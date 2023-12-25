#include "py/obj.h"
#include "py/runtime.h"

#include "shared-bindings/sticks/__init__.h"

#include "supervisor/port.h"

#define _TICKS_PERIOD 16777216 // 1 << 24

// ------------
// ticks
// ------------
mp_obj_t sticks_ticks(void) {
    return mp_obj_new_int(port_get_ticks());
}
MP_DEFINE_CONST_FUN_OBJ_0(sticks_ticks_obj, sticks_ticks);

// ------------
// ticks_to_us
// ------------
mp_obj_t sticks_ticks_to_us(mp_obj_t ticks_in) {
    uint32_t ticks = mp_obj_get_int(ticks_in);
    // us = ticks * 1_000_000 / 32768 = ticks * 15625 / 512
    return mp_obj_new_int((ticks * 15625) >> 9);
}
MP_DEFINE_CONST_FUN_OBJ_1(sticks_ticks_to_us_obj, sticks_ticks_to_us);

// ------------
// ticks_diff
// ------------
mp_obj_t sticks_ticks_diff(mp_obj_t end_in, mp_obj_t start_in) {
    uint32_t start = mp_obj_get_int(start_in);
    uint32_t end = mp_obj_get_int(end_in);
    // Optimized formula avoiding if conditions. We adjust difference "forward",
    // wrap it around and adjust back.
    return mp_obj_new_int(
        ((end - start + _TICKS_PERIOD / 2) & (_TICKS_PERIOD - 1)) - _TICKS_PERIOD / 2
    );
}
MP_DEFINE_CONST_FUN_OBJ_2(sticks_ticks_diff_obj, sticks_ticks_diff);

// ------------
// current_ticks_diff
// ------------
mp_obj_t sticks_current_ticks_diff(mp_obj_t start_in) {
    uint32_t end = port_get_ticks();
    uint32_t start = mp_obj_get_int(start_in);
    // Optimized formula avoiding if conditions. We adjust difference "forward",
    // wrap it around and adjust back.
    return mp_obj_new_int(
        ((end - start + _TICKS_PERIOD / 2) & (_TICKS_PERIOD - 1)) - _TICKS_PERIOD / 2
    );
}
MP_DEFINE_CONST_FUN_OBJ_1(sticks_current_ticks_diff_obj, sticks_current_ticks_diff);

// ------------
// write_current_ticks
// ------------
mp_obj_t sticks_write_current_ticks(mp_obj_t buffer_in, mp_obj_t start_in) {
    mp_buffer_info_t bufinfo;
    mp_get_buffer_raise(buffer_in, &bufinfo, MP_BUFFER_WRITE);

    uint32_t start = mp_obj_get_int(start_in);
    uint32_t ticks = port_get_ticks();

    uint8_t *buf = ((uint8_t *)bufinfo.buf);
    buf[start] = ticks & 0xff;
    buf[start+1] = (ticks >> 8) & 0xff;
    buf[start+2] = (ticks >> 16) & 0xff;

    return mp_const_none;

}
MP_DEFINE_CONST_FUN_OBJ_2(sticks_write_current_ticks_obj, sticks_write_current_ticks);

STATIC const mp_rom_map_elem_t sticks_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR_ticks),  MP_ROM_PTR(&sticks_ticks_obj) },
    { MP_ROM_QSTR(MP_QSTR_ticks_to_us),  MP_ROM_PTR(&sticks_ticks_to_us_obj) },
    { MP_ROM_QSTR(MP_QSTR_ticks_diff),  MP_ROM_PTR(&sticks_ticks_diff_obj) },
    { MP_ROM_QSTR(MP_QSTR_current_ticks_diff),  MP_ROM_PTR(&sticks_current_ticks_diff_obj) },
    { MP_ROM_QSTR(MP_QSTR_write_current_ticks),  MP_ROM_PTR(&sticks_write_current_ticks_obj) },
};
STATIC MP_DEFINE_CONST_DICT(sticks_module_globals, sticks_module_globals_table);

const mp_obj_module_t sticks_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&sticks_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_sticks, sticks_module);

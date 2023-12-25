#ifndef MICROPY_INCLUDED_SHARED_BINDINGS_STICKS___INIT___H
#define MICROPY_INCLUDED_SHARED_BINDINGS_STICKS___INIT___H

#include "py/obj.h"

extern mp_obj_t sticks_ticks(void);
extern mp_obj_t sticks_ticks_to_us(mp_obj_t ticks_in);
extern mp_obj_t sticks_ticks_diff(mp_obj_t end, mp_obj_t start);
extern mp_obj_t sticks_current_ticks_diff(mp_obj_t start);
extern mp_obj_t sticks_write_current_ticks(mp_obj_t buffer, mp_obj_t start);

#endif // MICROPY_INCLUDED_SHARED_BINDINGS_STICKS___INIT___H

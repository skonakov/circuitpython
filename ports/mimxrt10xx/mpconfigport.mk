LD_FILE = $(FLASH).ld $(CHIP_FAMILY).ld imxrt10xx.ld

INTERNAL_LIBM = 1

USB_HIGHSPEED = 1

# Number of USB endpoint pairs.
USB_NUM_ENDPOINT_PAIRS = 8
# Align buffers on the cache boundary so we don't inadvertently load them early.
CIRCUITPY_TUSB_MEM_ALIGN = 32

INTERNAL_FLASH_FILESYSTEM = 1

CIRCUITPY_AUDIOBUSIO = 1
CIRCUITPY_AUDIOBUSIO_PDMIN = 0
CIRCUITPY_AUDIOCORE = 1
CIRCUITPY_AUDIOIO = 0
CIRCUITPY_AUDIOMIXER = 1
CIRCUITPY_AUDIOMP3 = 1
CIRCUITPY_AUDIOPWMIO = 1
CIRCUITPY_BUSDEVICE = 1
CIRCUITPY_COUNTIO = 0
CIRCUITPY_FREQUENCYIO = 0
CIRCUITPY_I2CTARGET = 0
CIRCUITPY_NVM = 0
CIRCUITPY_PARALLELDISPLAY = 0
CIRCUITPY_PULSEIO = 0
CIRCUITPY_ROTARYIO = 0
CIRCUITPY_USB_MIDI = 1
LONGINT_IMPL = MPZ

CIRCUITPY_BUILD_EXTENSIONS ?= hex,uf2

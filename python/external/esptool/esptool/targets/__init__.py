from .esp32 import ESP32ROM

CHIP_DEFS = {
    "esp32": ESP32ROM,
}

CHIP_LIST = list(CHIP_DEFS.keys())
ROM_LIST = list(CHIP_DEFS.values())

# default SMING_HOME. Can be overriden.
SMING_HOME ?= /usr/local/esp8266/Sming/Sming

# ESP8266 sdk package home directory
ESP_HOME ?= /usr/local/esp8266/esp-open-sdk

# default COM port
COM_PORT ?= /dev/cuaU0

# base directory of the ESP8266 SDK package, absolute
SDK_BASE  ?= $(ESP_HOME)/sdk
SDK_TOOLS ?= $(SDK_BASE)/tools

# other tools mappings
ESPTOOL      ?= $(ESP_HOME)/esptool/esptool.py
KILL_TERM    ?= pkill -9 -f "$(COM_PORT) $(COM_SPEED_SERIAL)" || exit 0
GET_FILESIZE ?= stat -f "%-15z"
TERMINAL     ?= python -m serial.tools.miniterm $(COM_PORT) $(COM_SPEED_SERIAL)
MEMANALYZER  ?= $(OBJDUMP) -h -j .data -j .rodata -j .bss -j .text -j .irom0.text

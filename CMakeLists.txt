cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico_w)
set(PROJECT_NAME "main")

# Pull in SDK based on PICO_SDK_PATH
# note: this must happen before project()
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(${PROJECT_NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20) #17

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of project
add_executable(${PROJECT_NAME}
    main.cpp
)

# Add pico_stdlib library which aggregates commonly used features 
# pico_cyw43_arch_none is nessessary for accessing the CYW4343W WiFi chip and it's LED
target_link_libraries(${PROJECT_NAME} pico_stdlib pico_cyw43_arch_none hardware_i2c)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(${PROJECT_NAME})

# set output to UART
pico_enable_stdio_usb(${PROJECT_NAME} 0)
pico_enable_stdio_uart(${PROJECT_NAME} 1)
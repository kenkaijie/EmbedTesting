cmake_minimum_required(VERSION 3.15)

project(sampleProject)

include(cmake/utils.cmake)

enable_language(C ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)  # force gnu11
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
# set(STM32CUBEMX_GENERATED_FILES

#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.c
#         BSP/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c

#         BSP/Inc/main.h
#         BSP/Inc/stm32f4xx_hal_conf.h
#         BSP/Inc/stm32f4xx_it.h

#         BSP/Src/main.c
#         BSP/Src/stm32f4xx_hal_msp.c
#         BSP/Src/stm32f4xx_it.c
#         BSP/Src/system_stm32f4xx.c

#         BSP/startup_stm32f413xx.s)

add_executable(sampleProject)

target_include_directories(sampleProject PUBLIC inc)
target_sources(sampleProject PUBLIC 
./src/main.c 
./src/startup_stm32f429xx.s
./src/stm32f4xx_hal_msp.c 
./src/stm32f4xx_it.c 
./src/syscalls.c 
./src/system_stm32f4xx.c)

add_subdirectory(extern/cmocka)

target_link_libraries(sampleProject cmocka)
target_include_directories(cmocka PUBLIC inc)
target_compile_definitions(cmocka PUBLIC CMOCKA_PLATFORM_INCLUDE)

add_subdirectory(libs/stm32bsp)

target_link_libraries(sampleProject stm32bsp)
target_include_directories(stm32bsp PUBLIC inc)

#Print executable size
add_custom_command(TARGET sampleProject
        POST_BUILD
        COMMAND arm-none-eabi-size sampleProject)

# Create hex file
add_custom_command(TARGET sampleProject
        POST_BUILD
        COMMAND arm-none-eabi-objcopy -O ihex sampleProject ${PROJECT_NAME}.hex
        COMMAND arm-none-eabi-objcopy -O binary sampleProject ${PROJECT_NAME}.bin)


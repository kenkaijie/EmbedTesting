cmake_minimum_required(VERSION 3.15)

project(sampleProject)

include(cmake/utils.cmake)

enable_language(C ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)  # force gnu11
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

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


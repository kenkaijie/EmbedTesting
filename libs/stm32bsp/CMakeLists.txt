add_library(stm32bsp)

target_include_directories(stm32bsp PUBLIC 
BSP/STM32F4xx_Nucleo_144
CMSIS/Include
CMSIS/Device/ST/STM32F4xx/Include
STM32F4xx_HAL_Driver/Inc
STM32F4xx_HAL_Driver/Inc/Legacy)

target_sources(stm32bsp PUBLIC 
BSP/STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.c
STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c
STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c)

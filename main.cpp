#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hardware/i2c.h"
#include "pico/binary_info.h"
#include "LCDConstants.h"

int main()
{
    stdio_init_all();

    i2c_init(i2c_default, 100000);

    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));

    uint8_t command = set_mode + C_LAST_COMMAND + T_ROW_MODE + E_ALL_ON_STATUS + 0b01;
    uint8_t command2 = set_mode + C_LAST_COMMAND + T_MIXED_MODE + E_BLANK_STATUS + 0b01;

    uint8_t select[] = {device_select + C_COMMAND_FOLLOWING + 0b0000, command};
    uint8_t select1[] = {device_select + C_COMMAND_FOLLOWING + 0b0001, command};
    uint8_t select2[] = {device_select + C_COMMAND_FOLLOWING + 0b0010, command};

    uint8_t device0 = device_select + C_COMMAND_FOLLOWING + 0b0000;
    uint8_t device1 = device_select + C_COMMAND_FOLLOWING + 0b0001;
    uint8_t device2 = device_select + C_COMMAND_FOLLOWING + 0b0010;

    // 0x00 register address
    uint8_t pot_command[] = {0x00, 0x7F};     // Potentiometer max
    uint8_t pot_command_low[] = {0x00, 0x00}; // Potentiometer min

    i2c_write_blocking(i2c_default, 0b0111100, &command2, sizeof(uint8_t), false);

    i2c_write_blocking(i2c_default, 0b0111100, select, sizeof(select), false);

    i2c_write_blocking(i2c_default, 0b0111100, select1, sizeof(select1), false);

    i2c_write_blocking(i2c_default, 0b0111100, select2, sizeof(select2), false);

    i2c_write_blocking(i2c_default, 0b0111110, pot_command, sizeof(pot_command), false);

    // untested
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            uint8_t ramCommand[]{device0 + i, load_X_address + C_COMMAND_FOLLOWING, RAM_access + C_LAST_COMMAND + G_RAM_FULL_GRAPHIC_MODE + 0b00};
        }
    }
    // while (true)
    // {
    //     i2c_write_blocking(i2c_default, 0b0111110, pot_command, sizeof(pot_command), false);
    //     sleep_ms(3000);
    //     i2c_write_blocking(i2c_default, 0b0111110, pot_command_low, sizeof(pot_command_low), false);
    //     sleep_ms(3000);
    // }

    return 0;
}

#include "main.hpp"
// INCLUDE GPIO Component
#include <iostream>
#include <string.h>
#include "esp_vfs_dev.h"
#include "driver/uart.h"
#include <esp_log.h>
// DEFINE TAGS
#define TAG "BLINK"
#define PIN GPIO_NUM_4
esp_err_t General::Core::setup()
{
    ESP_LOGI(TAG, "SETUP");
    // https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/storage/vfs.html#standard-io-streams-stdin-stdout-stderr
    //  Initialize VFS (Virtual file system) & UART so we can use std::cout/cin
    setvbuf(stdin, NULL, _IONBF, 0);
    /* Install UART driver for interrupt-driven reads and writes */
    ESP_ERROR_CHECK(uart_driver_install((uart_port_t)CONFIG_ESP_CONSOLE_UART_NUM,
                                        256, 0, 0, NULL, 0));
    /* Tell VFS  to use UART driver */
    esp_vfs_dev_uart_use_driver(CONFIG_ESP_CONSOLE_UART_NUM);
    esp_vfs_dev_uart_port_set_rx_line_endings(CONFIG_ESP_CONSOLE_UART_NUM, ESP_LINE_ENDINGS_CR);
    /* Move the caret to the beginning of the next line on '\n' */
    esp_vfs_dev_uart_port_set_tx_line_endings(CONFIG_ESP_CONSOLE_UART_NUM, ESP_LINE_ENDINGS_CRLF);
    return ESP_OK;
}

void General::Core::run()
{
    ESP_LOGI(TAG, "LOOP");
    char c = 0;
    std::string s;
    std::cout << "ESP32# ";
    while (std::getline(std::cin, s))
    {
        std::cout << "Read: '" << s << "'\nESP32# ";
    }

    std::cout << "Bye bye!" << s;
}

extern "C" void app_main()
{
    General::Core core;
    core.setup();
    while (true)
    {
        core.run();
    }
}
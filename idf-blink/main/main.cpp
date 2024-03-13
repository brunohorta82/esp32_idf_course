#include "main.hpp"
// INCLUDE GPIO Component
#include "driver/gpio.h"
#include <esp_log.h>
// DEFINE TAGS
#define TAG "BLINK"
#define PIN GPIO_NUM_4
esp_err_t General::Core::setup()
{
    ESP_LOGI(TAG, "SETUP");
    gpio_set_direction(PIN, GPIO_MODE_INPUT_OUTPUT);
    return ESP_OK;
}

void General::Core::run()
{
    ESP_LOGI(TAG, "LOOP");
    gpio_set_level(PIN, !gpio_get_level(PIN));
    ESP_LOGI(TAG, "STATE %s", gpio_get_level(PIN) ? "ON" : "OFF");
    vTaskDelay(pdMS_TO_TICKS(1000));
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
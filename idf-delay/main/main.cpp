#include "main.hpp"
#include <esp_log.h>
#define TAG "DELAY"

// #include "freertos/FreeRTOS.h" required - check main.hpp

esp_err_t General::Core::setup()
{
    ESP_LOGI(TAG, "SETUP");
    return ESP_OK;
}

void General::Core::run()
{
    ESP_LOGI(TAG, "LOOP");
    // CONVERT MS TO TICKS - Inspect macro pdMS_TO_TICKS
    ESP_LOGI(TAG, "Message 1");
    vTaskDelay(pdMS_TO_TICKS(2000));
    // OTHER WAY TO CONVERT MS TO TICKS
    ESP_LOGI(TAG, "Message 2");
    vTaskDelay(2000 / portTICK_PERIOD_MS);
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
#include "main.hpp"
// INCLUDE LOG LIB
#include <esp_log.h>
// DEFINE TAGS
#define TAG "RANDOM"
#include "esp_random.h"
#include "math.h"

esp_err_t General::Core::setup()
{
    ESP_LOGI(TAG, "SETUP");
    return ESP_OK;
}

void General::Core::run()
{
    ESP_LOGI(TAG, "LOOP");
    int random = esp_random();
    ESP_LOGI(TAG, "RAMDOM NUMBER %d", random);
    int positiveNumber = abs(random);
    ESP_LOGI(TAG, "POSITIVE NUMBER %d", positiveNumber);
    int limitedNumber = (positiveNumber % 6) + 1;
    ESP_LOGI(TAG, "LIMITED NUMBER %d", limitedNumber);
    vTaskDelay(pdMS_TO_TICKS(5000));
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
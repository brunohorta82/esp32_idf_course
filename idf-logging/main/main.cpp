#include "main.hpp"
//INCLUDE LOG LIB
#include <esp_log.h>
//DEFINE TAGS
#define TAG "LOGGING"
#define OTHER_TAG "OTHER TAG"

esp_err_t General::Core::setup()
{
    /*
    Test with different levels and TAG's
    Change level output on menuconfig
    Analise the output
    LEVEL MILLIS TAG       MESSAGE
    E     (1302) LOGGING: This is an error
    E (1302) LOGGING: This is an error
    W (1302) LOGGING: This is a warning
    I (1312) LOGGING: This is an info
    D (1312) LOGGING: This is a Debug
    V (1312) LOGGING: This is Verbose
    */
    // esp_log_level_set(TAG, ESP_LOG_INFO);
    ESP_LOGE(TAG, "This is an error");
    ESP_LOGW(TAG, "This is a warning");
    ESP_LOGI(TAG, "This is an info");
    ESP_LOGD(TAG, "This is a Debug");
    ESP_LOGV(TAG, "This is Verbose");

    int number = 0;
    ESP_LOGE(OTHER_TAG, "This is an error %d", number++);
    ESP_LOGW(OTHER_TAG, "This is a warning %d", number++);
    ESP_LOGI(OTHER_TAG, "This is an info %d", number++);
    ESP_LOGD(OTHER_TAG, "This is a Debug %d", number++);
    ESP_LOGV(OTHER_TAG, "This is Verbose %d", number++);

    return ESP_OK;
}

void General::Core::run()
{
    ESP_LOGI(TAG, "LOOP");
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
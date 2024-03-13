#pragma once
#include "freertos/FreeRTOS.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "esp_mac.h"

namespace General
{

    class Core final
    {
    private:
        char deviceId[13];

    public:
        Core()
        {
            uint8_t mac_byte_buffer[6]{};
            const esp_err_t
                status{esp_efuse_mac_get_default(mac_byte_buffer)};
            if (ESP_OK == status)
            {

                snprintf(deviceId, sizeof(deviceId),
                         "%02X%02X%02X%02X%02X%02X",
                         mac_byte_buffer[0],
                         mac_byte_buffer[1],
                         mac_byte_buffer[2],
                         mac_byte_buffer[3],
                         mac_byte_buffer[4],
                         mac_byte_buffer[5]);
            };
        }
        constexpr const char *getDeviceId()
        {
            return deviceId;
        }
        esp_err_t setup();
        void run();
    };
};
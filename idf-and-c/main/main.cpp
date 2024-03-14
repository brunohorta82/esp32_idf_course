#include "main.hpp"
#include <esp_log.h>
#include <string.h>
#define TAG "ESP-AND-C"

typedef struct Car_struct
{
    char brand[20];
    char color[10];
    int horsepower;
} Car;

void createFerrari(Car *car)
{
    strcpy(car->brand, "Ferrari");
    strcpy(car->color, "Red");
    car->horsepower = 350;
}
void changeColorToBlack(char *color) // TEST with void changeColorToBlack(char color), void changeColorToBlack(char color[]);
{
    strcpy(color, "Black");
}

esp_err_t General::Core::setup()
{
    ESP_LOGI(TAG, "SETUP");
    Car car;
    createFerrari(&car); // TEST with createFerrari(car);
    ESP_LOGI(TAG, "Car: %s with %s color and %d horsepower", car.brand, car.color, car.horsepower);

    changeColorToBlack(car.color);
    ESP_LOGI(TAG, "Car: %s with %s color and %d horsepower", car.brand, car.color, car.horsepower);
    return ESP_OK;
}

void General::Core::run()
{
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
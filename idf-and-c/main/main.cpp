#include "main.hpp"
#include <esp_log.h>
#include <iostream> // Include necessary header for input/output stream
#include <string.h>
#define TAG "ESP-AND-C"

class Person
{ // Define a class named Person
private:
    std::string name;    // Private member to store the name of the person
    int age;             // Private member to store the age of the person
    std::string country; // Private member to store the country of the person

public:
    // Setter functions to set the private member variables
    void setName(const std::string &n)
    {             // Setter function for the name
        name = n; // Assign the provided name to the 'name' member variable
    }

    void setAge(int a)
    {            // Setter function for the age
        age = a; // Assign the provided age to the 'age' member variable
    }

    void setCountry(const std::string &c)
    {                // Setter function for the country
        country = c; // Assign the provided country to the 'country' member variable
    }

    // Getter functions to retrieve the private member variables
    std::string getName()
    {                // Getter function for retrieving the name
        return name; // Return the stored name
    }

    int getAge()
    {               // Getter function for retrieving the age
        return age; // Return the stored age
    }

    std::string getCountry()
    {                   // Getter function for retrieving the country
        return country; // Return the stored country
    }
};
typedef struct Car_struct
{
    char brand[20];
    char color[10];
    int horsepower;
    void (*doWork)(int param);
} Car;
void doWork(int param)
{
    ESP_LOGI(TAG, "Pointer function wiht param %d", param);
}
void createFerrari(Car *car)
{
    strcpy(car->brand, "Ferrari");
    strcpy(car->color, "Red");
    car->doWork = doWork;
    car->doWork(30);
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

    Person person;

    // Set the person's details using setter functions
    person.setName("Bruno Horta"); // Set the person's name
    person.setAge(41);             // Set the person's age
    person.setCountry("PT");       // Set the person's country

    // Get and display the person's details using getter functions
    std::cout << "Name: " << person.getName() << std::endl;       // Output the person's name
    std::cout << "Age: " << person.getAge() << std::endl;         // Output the person's age
    std::cout << "Country: " << person.getCountry() << std::endl; // Output the person's country
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
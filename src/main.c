#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define LED_pin 13

void app_main(void *pvParams) {
    esp_rom_gpio_pad_select_gpio(LED_pin);
    gpio_set_direction(LED_pin, GPIO_MODE_OUTPUT);

    while (1){
        gpio_set_level(LED_pin, 1);
        vTaskDelay(750 / portTICK_PERIOD_MS);

        gpio_set_level(LED_pin, 0);
        vTaskDelay(750 / portTICK_PERIOD_MS);
    }
    
}
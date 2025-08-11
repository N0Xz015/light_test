#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define LED_pin_1 13
#define LED_pin_2 12

void blink(void *pvParameter) {
    gpio_num_t LED_pin = (gpio_num_t)pvParameter;
    while (1){
        gpio_set_level(LED_pin, 1);
        vTaskDelay(750 / portTICK_PERIOD_MS);
        gpio_set_level(LED_pin, 0);
        vTaskDelay(750 / portTICK_PERIOD_MS);
    }
}

void app_main(void) {
    gpio_set_direction(LED_pin_1, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED_pin_2, GPIO_MODE_OUTPUT);

    xTaskCreate(blink, "blink_task_1", 2048, (void *)LED_pin_1, 5, NULL);
    xTaskCreate(blink, "blink_task_2", 2048, (void *)LED_pin_2, 5, NULL);
}
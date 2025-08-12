#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define LED_PIN_1 13
#define LED_PIN_2 12

void blink_1(void *pvParameter) {
    gpio_num_t LED_PIN = (gpio_num_t)pvParameter;
    while (1){
        gpio_set_level(LED_PIN, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(LED_PIN, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
void blink_2(void *pvParameter) {
    gpio_num_t LED_PIN = (gpio_num_t)pvParameter;
    while (1){
        gpio_set_level(LED_PIN, 1);
        vTaskDelay(250 / portTICK_PERIOD_MS);
        gpio_set_level(LED_PIN, 0);
        vTaskDelay(250 / portTICK_PERIOD_MS);
    }
}

void app_main(void) {
    gpio_set_direction(LED_PIN_1, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED_PIN_2, GPIO_MODE_OUTPUT);

    xTaskCreate(blink_1, "blink_task_1", 2048, (void *)LED_PIN_1, 5, NULL);
    xTaskCreate(blink_2, "blink_task_2", 2048, (void *)LED_PIN_2, 5, NULL);
}
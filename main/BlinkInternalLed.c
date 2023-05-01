#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

// internal blink
#define BLINK_LED 2

// flag to led (Low, High)
char status[2] = {'L', 'H'};

void app_main(void)
{
  gpio_pad_select_gpio(BLINK_LED);
  gpio_set_direction(BLINK_LED, GPIO_MODE_OUTPUT); // definition to output

  printf("Hello World ESP IDF\n"); // put information on monitor serial

  bool i = 0; // logic state flag

  for (;;) // loop
  {
    i = i ^ 1;                                             // Change value for flag
    gpio_set_level(BLINK_LED, i);                          // Set GPIO to value
    printf("Hello World - Led status : %c \n", status[i]); // Print on Serial
    vTaskDelay(1000 / portTICK_PERIOD_MS);                 // Await 1 second
    fflush(stdout);                                        // Unload output data buffer
  }
}

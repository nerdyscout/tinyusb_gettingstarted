#include <Arduino.h>
#include <tusb.h>
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <semphr.h>

TaskHandle_t taskBlinkHandle;

void TaskBlink(void *pvParameters)
{
  (void)pvParameters;

  pinMode(LED_BUILTIN, OUTPUT);

  for (;;)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(250 / portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay(250 / portTICK_PERIOD_MS);
  }
}

void setup(void)
{
  xTaskCreate(TaskBlink, // Task function
              "Blink",   // Task name
              128,       // Stack size
              NULL,
              0,                 // Priority
              &taskBlinkHandle); // Task handler
}

void loop(void)
{
  tud_task(); // device task
}

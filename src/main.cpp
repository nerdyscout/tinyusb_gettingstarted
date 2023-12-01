#include <Arduino.h>
#include <tusb.h>

void setup(void)
{
  tusb_init(); // initialize tinyusb stack
}

void loop(void)
{
  tud_task(); // device task
}
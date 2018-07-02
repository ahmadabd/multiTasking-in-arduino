#include <Arduino_FreeRTOS.h>

// define two tasks for Blink1 & Blink2
void taskBlink1( void *pvParameters );
void taskBlink2( void *pvParameters );

int pin1 = 4;   // For Blink1
int pin2 = 8;   // For Blink1


void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ;
  }


  xTaskCreate(
    taskBlink1
    , (const portCHAR *)"Blink2"   // A name just for humans
    , 128  // This stack size can be checked & adjusted by reading the Stack Highwater
    , NULL
    , 2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    , NULL);

  xTaskCreate(
    taskBlink2
    , (const portCHAR *)"Blink1"
    , 128  // Stack size
    , NULL
    , 1  // Priority
    , NULL);

}

void loop()

{
}

void taskBlink1(void *pvParameters)  // This is a task.
{

  (void) pvParameters;
  
  pinMode(pin1, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
    
    digitalWrite(pin1, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS); // wait for one second
    digitalWrite(pin1, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay(500 / portTICK_PERIOD_MS); // wait for one second

    Serial.println("Task1");
  }
}


void taskBlink2(void *pvParameters)  // This is a task.
{

  (void) pvParameters;

  pinMode(pin2, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
    
    digitalWrite(pin2, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS); // wait for one second
    digitalWrite(pin2, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay(500 / portTICK_PERIOD_MS); // wait for one second

    Serial.println("Task2");
  }
}

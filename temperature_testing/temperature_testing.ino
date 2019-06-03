//#include <OneWire.h>

//#include <Arduino.h>
#include "OneWire.h"
#include "DallasTemperature.h"
  
OneWire oneWire(3); // GPIO35
// GPIO39 physical pin 9
DallasTemperature tempSensor(&oneWire);
  
void setup(void)
{  
  Serial.begin(115200);
  tempSensor.begin();
  tempSensor.setResolution(12);
}
  
void loop(void)
{
  tempSensor.requestTemperaturesByIndex(0);
  tempSensor.requestTemperaturesByIndex(1);
  tempSensor.requestTemperaturesByIndex(2);
  tempSensor.requestTemperaturesByIndex(3);

  double a = tempSensor.getTempCByIndex(0);
  double b = tempSensor.getTempCByIndex(1);
  double delta = max(a, b) - min(a, b);
  Serial.printf("Delta: %.4f", delta);

  Serial.printf(" count %u \n", tempSensor.getDS18Count());
  Serial.print(". a ");
  Serial.print(a);
  Serial.println(" C");
  Serial.print(". b ");
  Serial.print(b);
  
  Serial.println(" C");
    Serial.print(". c ");
  Serial.print(tempSensor.getTempCByIndex(2));
  Serial.println(" C");
    Serial.print(". d ");
  Serial.print(tempSensor.getTempCByIndex(3));
  Serial.println(" C");
  Serial.println("------------------------------");
  delay(1000);
}

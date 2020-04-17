#include <Wire.h> // Arduino I2C library
#include <SparkFunMLX90614.h> // IR thermometer library
#include "rgb_lcd.h" // LCD display library

rgb_lcd lcd;
IRTherm tempIR;

void setup() 
{
    Serial.begin(9600);  

    // Setup temperature sensor
    tempIR.begin();
    tempIR.setUnit(TEMP_C); // Celsius

    // Setup diplay
    lcd.begin(16, 2);
    lcd.setRGB(255, 0, 0);

    // Print LCD header
    lcd.print("IR thermometer");

    delay(1000);
}

void displayLCD(String text)
{
    lcd.setCursor(0, 1);
    lcd.print(text);
}

void loop() 
{  
    // Read from temperature sensor
    if (tempIR.read()) 
    { 
        float objectT = tempIR.object();
        // Print temperature value on serial (debugging)
        Serial.println("Temp. Celsius: " + String(objectT));
  
        // Display temperature value on LCD
        displayLCD(String(objectT) + "\xDF" + "C");
    }
    else
    {
        // Print error message on serial (debugging)
        Serial.println("IR sensor error");
    }
    delay(100);
}

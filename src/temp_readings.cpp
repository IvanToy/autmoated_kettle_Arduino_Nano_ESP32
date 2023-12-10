#include <Arduino.h>
#include "temp_readings.h"

int adc_value; 
float R2, t_kelvin, t_celsius;
const float Beta = 3950.0;
const float room_temp = 298.15; 
const float thermistor_resistance = 10000.0;      
const float resistor = 10000.0;       

int temp_readings(int thermistor_pin){

    adc_value = analogRead(thermistor_pin);
    R2 = resistor * (4095.0 / (float)adc_value - 1.0);
    t_kelvin = (Beta * room_temp) /  (Beta + (room_temp * log(R2 / thermistor_resistance)));
    t_celsius = t_kelvin - 273.15;

    return t_celsius;
}
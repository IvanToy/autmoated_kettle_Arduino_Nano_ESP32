#include "leds_control.h"

void leds_control(int red_led, int green_led, int blue_led, int temp)
{

    if (temp >= 60 && temp <= 70)
    {
        analogWrite(blue_led, 255);
        analogWrite(green_led, 0);
        analogWrite(red_led, 255);
    }
    else if (temp >= 70 && temp <= 80)
    {
        analogWrite(blue_led, 0);
        analogWrite(green_led, 255);
        analogWrite(red_led, 255);
    }
    else if (temp >= 80 && temp <= 90)
    {
        analogWrite(blue_led, 255);
        analogWrite(green_led, 0);
        analogWrite(red_led, 0);
    }
    else if (temp >= 90 && temp <= 100)
    {
        analogWrite(blue_led, 0);
        analogWrite(green_led, 255);
        analogWrite(red_led, 0);
    }else if(temp > 100){
        analogWrite(blue_led, 255);
        analogWrite(green_led, 255);
        analogWrite(red_led, 0);
    }else{
        analogWrite(blue_led, 0);
        analogWrite(green_led, 255);
        analogWrite(red_led, 255);
    }
    
        
    
}
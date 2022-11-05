#include <Q2HX711.h>
#include <Average.h>
#include "HX710B.h"


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define pressureAir_1  A1
#define display_1  2
#define NUMPIXELS_1 8

Adafruit_NeoPixel pixels_1(NUMPIXELS_1, display_1, NEO_GRB + NEO_KHZ800);

const byte MPS_OUT_pin = 32; // OUT data pin
const byte MPS_SCK_pin = 33; // clock data pin
int avg_size = 10; // #pts to average over
float analog_temp;

//const byte MPS_OUT_pin2 = 10; // OUT data pin
//const byte MPS_SCK_pin2 = 9; // clock data pin
//int avg_size2 = 10; // #pts to average over
//float analog_temp2;

Q2HX711 MPS20N0040D_1(MPS_OUT_pin, MPS_SCK_pin); // start comm with the HX710B
Average<long> ave(avg_size);


void setup()
{
  pixels_1.begin();
  pixels_1.setBrightness(50);

//  pixels_2.begin();
//  pixels_2.setBrightness(50);

  Serial.begin(9600);
}

void loop()
{
//  ave.push(MPS20N0040D.read());
  Serial.print (ave.mean());
  analog_temp = ave.mean()/40960;
  int  analog_1 = int(analog_temp);
  Serial.print ("  ");
  Serial.println(analog_1);
  
 // int analog_1 = analogRead(pressureAir_1);
//  Serial.print (analog_1); Serial.print ("     ");
  analog_1 = map (analog_1, 0, 255, 0, 8);
 // Serial.println (analog_1);
  
  pixels_1.setPixelColor(analog_1, 255, 0, 0);
 // pixels_2.setPixelColor(analog_2, 0, 255, 0);
 // pixels_3.setPixelColor(analog_2, 0, 0, 255);
 // pixels_4.setPixelColor(analog_4, 35, 35, 35);

  pixels_1.show();
 // pixels_2.show();
 // pixels_3.show();
 // pixels_4.show();

  pixels_1.setPixelColor(analog_1, 0, 0, 0);
 // pixels_2.setPixelColor(analog_1, 0, 0, 0);
 // pixels_3.setPixelColor(analog_1, 0, 0, 0);
 // pixels_4.setPixelColor(analog_1, 0, 0, 0);

  delay(10);

  
}

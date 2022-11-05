#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> 
#endif

#define PIN1 25
#define PIN2 26
#define PIN3 27

#define NUMPIXELS 8

Adafruit_NeoPixel pixels1(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);// Neo1
Adafruit_NeoPixel pixels2(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);// Neo2
Adafruit_NeoPixel pixels3(NUMPIXELS, PIN3, NEO_GRB + NEO_KHZ800);// Neo3

#define DELAYVAL 10


//pressure sensor
#include "HX710B.h"

const int DOUT1 = 32;   //sensor1 data pin
const int SCLK1  = 33;   //sensor1 clock pin
const int DOUT2 = 18;   //sensor2 data pin
const int SCLK2  = 19;   //sensor2 clock pin
const int DOUT3 = 22;   //sensor3 data pin
const int SCLK3  = 23;   //sensor3 clock pin

HX710B pressure_sensor1; 
HX710B pressure_sensor2; 
HX710B pressure_sensor3; 


void setup() {

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
 

  pixels1.begin(); 
  pixels2.begin(); 
  pixels3.begin(); 

  //  pressure sensor
  Serial.begin(57600);
  pressure_sensor1.begin(DOUT1, SCLK1);
  pressure_sensor2.begin(DOUT2, SCLK2);
  pressure_sensor3.begin(DOUT3, SCLK3);
}

void loop() {
  pixels1.clear();
  pixels2.clear();
  pixels3.clear();
  
  if (!pressure_sensor1.is_ready()) {
    Serial.println("Pressure sensor not found.");
      //    Adafruit
     
        pixels1.setPixelColor(7, pixels1.Color(255, 0, 0));
        pixels1.setPixelColor(6, pixels1.Color(255, 0, 0));
        pixels1.setPixelColor(5, pixels1.Color(255, 0, 0));
        pixels1.setPixelColor(4, pixels1.Color(255, 0, 0));
        pixels1.setPixelColor(3, pixels1.Color(255, 0, 0));
        pixels1.setPixelColor(2, pixels1.Color(255, 0, 0));
        pixels1.setPixelColor(1, pixels1.Color(255, 0, 0));
        pixels1.setPixelColor(0, pixels1.Color(255, 0, 0));
        pixels1.show(); 
 
  }
   if (!pressure_sensor2.is_ready()) {
    Serial.println("Pressure sensor not found.");
      //    Adafruit
     
        pixels2.setPixelColor(7, pixels2.Color(255, 0, 0));
        pixels2.setPixelColor(6, pixels2.Color(255, 0, 0));
        pixels2.setPixelColor(5, pixels2.Color(255, 0, 0));
        pixels2.setPixelColor(4, pixels2.Color(255, 0, 0));
        pixels2.setPixelColor(3, pixels2.Color(255, 0, 0));
        pixels2.setPixelColor(2, pixels2.Color(255, 0, 0));
        pixels2.setPixelColor(1, pixels2.Color(255, 0, 0));
        pixels2.setPixelColor(0, pixels2.Color(255, 0, 0));
        pixels2.show(); 
 
    }
  if (!pressure_sensor3.is_ready()) {
      Serial.println("Pressure sensor not found.");
        //    Adafruit
       
          pixels3.setPixelColor(7, pixels3.Color(255, 0, 0));
          pixels3.setPixelColor(6, pixels3.Color(255, 0, 0));
          pixels3.setPixelColor(5, pixels3.Color(255, 0, 0));
          pixels3.setPixelColor(4, pixels3.Color(255, 0, 0));
          pixels3.setPixelColor(3, pixels3.Color(255, 0, 0));
          pixels3.setPixelColor(2, pixels3.Color(255, 0, 0));
          pixels3.setPixelColor(1, pixels3.Color(255, 0, 0));
          pixels3.setPixelColor(0, pixels3.Color(255, 0, 0));
          pixels3.show(); 
   
    }
  float Ps1 = pressure_sensor1.pascal();
  float Ps2 = pressure_sensor2.pascal();
  float Ps3 = pressure_sensor3.pascal();
  Serial.println();  

  Serial.print("PASCAL1: ");
  Serial.println(Ps1);
  Serial.println();  
  Serial.print("PASCAL2: ");
  Serial.println(Ps2);
  Serial.println();  
  Serial.print("PASCAL3: ");
  Serial.println(Ps3); 

  
  // map 0-8
  int Px1 = map(Ps1, 530, 930, 0, 7);
  int Px2 = map(Ps2, 580, 980, 0, 7);
  int Px3 = map(Ps3, 390, 790, 0, 7);
  //    Adafruit
  pixels1.setPixelColor(Px1, pixels1.Color(0, 150, 0));
  pixels1.show();  
  pixels2.setPixelColor(Px2, pixels2.Color(0, 150, 255));
  pixels2.show();
  pixels3.setPixelColor(Px3, pixels3.Color(250, 150, 0));
  pixels3.show();  


  delay(DELAYVAL);
}

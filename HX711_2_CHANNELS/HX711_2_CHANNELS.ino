#include "HX711.h"

// HX711.DOUT  - pin #A1
// HX711.PD_SCK - pin #A0

HX711 scale_1; // set the HX711 board 1
HX711 scale_2; // set the HX711 board 2

int u_1 = 0; // Variable of the extensometer 1
int u_2 = 0; // Variable of the extensometer 2

void setup()
{
  Serial.flush();
  
  Serial.begin(115200);
  
  scale_1.begin(A1,A0); // read data HX711 board 1
  scale_2.begin(A3,A2); // read data HX711 board 2
  
  scale_1.set_scale(7940.f); // this value is obtained by calibrating the scale with known weights;
  scale_2.set_scale(700.f); // this value is obtained by calibrating the scale with known weights;
 
  scale_1.tare(); // reset the scale_1 to 0
  scale_2.tare(); // reset the scale_2 to 0
 
  }

void loop()
{

  u_1 = ( scale_1.get_units() ); // reading the extensometer 1
  scale_1.power_down();

  u_2 = ( scale_2.get_units() ); // reading the extensometer 2
  scale_2.power_down();
  
  Serial.print(y_1);  // print a raw reading from the ADC channel A, HX711 board 1
  Serial.print(',');  // print a raw reading from the ADC channel A, HX711 board 1
  Serial.println(y_2);  // print a raw reading from the ADC channel A, HX711 board 1
  //Serial.print(',');  // print a raw reading from the ADC channel A, HX711 board 1

  scale_1.power_up();
  scale_2.power_up();
  
}




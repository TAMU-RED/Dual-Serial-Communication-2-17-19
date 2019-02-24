#include <Wire.h>

void setup() { 
  //Serial port baud rate
  Serial.begin(9600);
}

void loop() {
  //Tells Arduino that input data will be coming from A1 port. 
  int sensorVal=analogRead(A1);

  //Converts output of reading data into voltage.
  float voltage = (sensorVal*5.0)/1024.0;

  //Converts voltage into pressure in pascals.
  float pressure_pascal = (3.0*((float)voltage-0.47))*1000000.0;

  //Converts pressure in pascal to pressure in bars.
  float pressure_bar = pressure_pascal / 10e5;
 
  //Converts pressure in bars to string,
  String s = String(pressure_bar)+";";

  //This sends each pressure value in string list to serial  
  for(int i=0;i<s.length(); i++){
    Serial.write(s[i]);
  }
  
   delay(1300); // 4 seconds per reading for 16 samples per reading
}

#include <Wire.h>

//#include <BMA222.h>

//BMA222 mySensor;


//float data[3] = {2.4,1.2,0.6};
String data = "1,2,3?";


void setup() { 
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("Accelerometer to Mega test");

  //mySensor.begin();

}

void loop() {
  //int8_t xdata = mySensor.readXData();

  //int8_t ydata = mySensor.readYData();

  //int8_t zdata = mySensor.readZData();
  //String s = String(xdata)+","+String(ydata)+","+String(zdata)+";";
  String s = String(millis()) + ",2,3;";

  for(int i=0; i<s.length(); i++){
    Serial1.write(s[i]);
  }
  //Serial1.write(data); 
  //Serial.println("H");
  delay(50); // 4 seconds per reading for 16 samples per reading
  
  //Serial1.println("1,2,3;");


  //delay(10);
}

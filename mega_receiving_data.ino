#include <SoftwareSerial.h>

SoftwareSerial BTserial(10, 11); //RX, TX

char c;
char string[100][20];
boolean NL = true;
int i = 0;
int j = 0;
int bytesAvailable;

void setup() 
{
    Serial.begin(9600);
    BTserial.begin(9600);  
    Serial.println("AT ready");
}
 
void loop()
{
    // Read from the Bluetooth module and send to the Arduino Serial Monitor
//    int bytesAvailable = BTserial.available();
//    if (bytesAvailable > 0)
//    {
//        for (int j=0; i<bytesAvailable; i++)
//        {
//          c = BTserial.read();
//          if (c != "?")
//          {
//            string[i][j] = c;
//          }
//          else
//          {
//            Serial.println(string[i]);
//            i++;
//          }
//        }
//    }
      bytesAvailable = BTserial.available();
      if (bytesAvailable > 0)
      {
          c = BTserial.read();
          if (c != '?')
          {
            Serial.println(c);
            string[i][j] = c;
            j++;
          }
          else
          {
            Serial.print("Data: ");
            Serial.println(string[i]);
            i++;
            j = 0;
          }  
      }
 
    // Read from the Serial Monitor and send to the Bluetooth module
//    if (Serial.available())
//    {
//        c = Serial.read();
// 
//        // do not send line end characters to the HM-10
//        if (c!=10 & c!=13 ) 
//        {  
//             BTserial.write(c);
//        }
// 
//        // Echo the user input to the main window. 
//        // If there is a new line print the ">" character.
//        if (NL) { Serial.print("\r\n>");  NL = false; }
//        Serial.write(c);
//        if (c==10) { NL = true; }
//    }
}

#include <SoftwareSerial.h>

SoftwareSerial Port1(10, 11); //RX, TX
SoftwareSerial Port2(12, 13); //RX, TX

char c1;
char c2;
char string1[100][20];
char string2[100][20];
boolean NL = true;
int i1 = 0;
int i2 = 0;
int j1 = 0;
int j2 = 0;
int bytesAvailable1;
int bytesAvailable2;
bool port1Listen = true;

void setup() 
{
    Serial.begin(9600);
    Port1.begin(9600);
    Port2.begin(9600); 
    //Serial.println("AT ready");
}
 
void loop()
{
      while(port1Listen)
      {
        Port1.listen();
        bytesAvailable1 = Port1.available();
        //Serial.print(bytesAvailable1);
        if (bytesAvailable1 > 0)
        {
            c1 = Port1.read();
            if (c1 != ';')
            {
              string1[i1][j1] = c1;
              j1++;
            }
            else
            {
              //Serial.print("17:");
              //Serial.println(string1[i1]);
              String s = "17:"+String(string1[i1])+";";
          for(int i=0;i<s.length();i++){
            Serial.write(s[i]);
          }
              i1++;
              j1 = 0;
              port1Listen = false;
            }  
        }
      }
      
      while (!port1Listen)
      {
      Port2.listen();
      bytesAvailable2 = Port2.available();
      if (bytesAvailable2 > 0)
      {
        c2 = Port2.read();
        if (c2 != ';')
        {
          string2[i2][j2] = c2;
          j2++;
        }
        else
        {
          //Serial.print("18:");
          //Serial.println(string2[i2]);
          String s = "18:"+String(string2[i2])+";?";
          for(int i=0;i<s.length();i++){
            Serial.write(s[i]);
          }
          i2++;
          j2 = 0;
          port1Listen = true;
        }
      }
      }
      
}

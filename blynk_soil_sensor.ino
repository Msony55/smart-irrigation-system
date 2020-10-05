#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define soilpin A0
char auth[] ="1e91bb194fc34c9a9ec576e1cb42b5ae";
char ssid[] ="recharge krwa le";
char pass[] ="yaadnahihai";
int sensor=0;
int lastval=0;
int x=0;
int y=0;
void setup() 
  {
      Serial.begin(115200);
      Blynk.begin(auth, ssid, pass);
      pinMode(soilpin,INPUT);
      pinMode(D1,OUTPUT);
      digitalWrite(D1,HIGH); // pump is OFF because in my case relay is triggering at LOW data 
  }

void loop() 
  {
      Blynk.run();
      sensor=analogRead(soilpin);
      Serial.println(sensor);
      Blynk.virtualWrite(V2,sensor);
  
   
 if(sensor >= 350 && lastval == 0)
  {
      Serial.println("needs water, send notification");
      Blynk.notify("HEY!!Water your plants");
      lastval = 1;
      delay(1000);
//send notification
    
  } 
  else if (sensor >=350 && lastval == 1)
  {
    //do nothing, has not been watered yet
    Serial.println("Has not been Watered yet");
    delay(1000);
  }
  else 
  {   
    Serial.println("does not need water");
    lastval = 0;
    delay(1000);
  }
  if(sensor<=90 && x == 0)
  { Serial.println("Turning Off Pump Automatically,sending notification");
    Blynk.notify("HEY!! I am Turning Off The Pump,｡^‿^｡");
    x = 1;
    delay(1000);
  }
  else if(sensor<=90 && x == 1)
  {
    digitalWrite(D1,HIGH); //pump is Off at HIGH
    Serial.println("Pump Is OFF");
  delay(1000);
  }
  else
  {
    x=0;
  }
  if(sensor>=700 && y == 0)
  {
    Serial.println("Turning Off Pump Automatically");
    Blynk.notify("Huhh!! I am Turning On The Pump in 5 seconds,ಠ_ಠ");
    y=1;
    delay(5000);
  }
  else if(sensor>=700 && y == 1)
  {
    delay(500);
    digitalWrite(D1,LOW); //pump is On at LOW
    Serial.println("Pump Is ON");
    delay(1000);
  }
   else
  {
    y=0;
  }
  delay(1000);
}


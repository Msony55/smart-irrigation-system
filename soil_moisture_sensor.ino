#define sensorpin 8
#define relay 9
#define buzzer 10
#define green 11
#define red 12
int r =0;
void setup() 
{
  pinMode(sensorpin,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(relay,OUTPUT);
}

void loop() 
{
  r = digitalRead(sensorpin);  
  if(r==HIGH)
  {
      digitalWrite(red,LOW);
      digitalWrite(green,HIGH);
      digitalWrite(relay,LOW);
      digitalWrite(buzzer,HIGH); 
      delay(500);
      digitalWrite(buzzer,LOW);
      delay(500); 
  }
  else if(r==LOW)
  {
      digitalWrite(green,LOW);
      digitalWrite(red,HIGH);
      digitalWrite(relay,HIGH);
      digitalWrite(buzzer,LOW);
  }
}

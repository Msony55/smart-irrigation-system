void setup() {
  // initialize digital pin 13 as an output.
  pinMode(2, INPUT);
  pinMode(4, OUTPUT);
  pinMode(3, INPUT);
  pinMode(5, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if( digitalRead(2)==HIGH)
  {
  digitalWrite(4, HIGH);   
  }
else   if( digitalRead(3)==HIGH)
  {
  digitalWrite(5, HIGH);   
  } 
else
{
  digitalWrite(4, LOW);
digitalWrite(5, LOW);   
}              
}

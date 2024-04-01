
void setup()
{
    Serial.begin(9600);
    pinMode(10, OUTPUT);
}
 
void loop()
{
  delay(1000);
  tone(10, 1);
  delay(1000);
  tone(10, 2000);
  delay(1000);
  tone(10, 5000);
  delay(1000);
  tone(10, 10000);
  delay(1000);
}

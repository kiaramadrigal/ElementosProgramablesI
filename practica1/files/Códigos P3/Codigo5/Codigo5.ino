// Codigo Attiny85
//
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  digitalWrite(3, HIGH);
  delay(300);
  digitalWrite(3, LOW);
  delay(300);
  digitalWrite(4, HIGH);
  delay(300);
  digitalWrite(4, LOW);
  delay(300);
}
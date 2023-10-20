int brightness = 0;

void setup()
{
  pinMode(0, OUTPUT);
}

void loop()
{
  for (brightness = 0; brightness <= 255; brightness += 1) {
    analogWrite(0, brightness);
    delay(100); // Wait for 100 millisecond(s)
  }
  for (brightness = 255; brightness >= 0; brightness -= 1) {
    analogWrite(0, brightness);
    delay(100); // Wait for 100 millisecond(s)
  }
}
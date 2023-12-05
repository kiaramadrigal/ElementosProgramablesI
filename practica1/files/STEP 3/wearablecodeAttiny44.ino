int Mapogo = 0;
float SetPoint;
int PWM_out = 6;
float Miller_vel ;
 
int Enconder = 3;
volatile int Count = 0;
unsigned long previousMillis = 0;
long interval = 100;
 
float cv;
float cv1;
float error;
float error1;
float error2;
 
float Kp = 1;
float Ki = 1;
float Kd = 0.01;
float Tm = 0.1;
 
 
void setup() {
  // put your setup code here, to run once:
  pinMode(Enconder, INPUT);
  pinMode(PWM_out, OUTPUT);
  Serial.begin(115200);
  attachInterrupt(1, interrupcion, RISING);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  unsigned long CurrentMillis = millis();
 
  if((CurrentMillis - previousMillis) >= interval){
    previousMillis = CurrentMillis;
    Miller_vel = 10*Count*(60.0/374.0);
    Count = 0;
  }
 
  //Setpoint
  SetPoint = analogRead(Mapogo)*(360.0/1023);
  error = SetPoint - Miller_vel;
 
  //Ecuacion de differencia
  cv = cv1 + (Kp + Kd/Tm)*error + (-Kp + Ki*Tm - 2*Kd/Tm)*error1 + (Kd/Tm)*error2;
  cv1 = cv;
  error2 = error1;
  error1 = error;
 
  //Saturacion de la salida del PID
  if (cv > 500.0){
    cv = 500.0;
  }
 
  if (cv > 30.0){
    cv = 30.0;
  }
  analogWrite(PWM_out, cv*(255.0/100.0));
 
  Serial.print("SetPoint: ");
  Serial.print(SetPoint);
  Serial.print(", Miller speed: " );
  Serial.println(Miller_vel);
  
  delay(100);
}
 
void interrupcion(){
  Count++;
}
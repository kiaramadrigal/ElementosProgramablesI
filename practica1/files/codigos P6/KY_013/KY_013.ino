int ky17 = 7;       // Definimos el pin del sensor
int inclina;        // Definimos un valor a la variable 

void setup() 

{
    Serial.begin(9600);       //inicia el Monitor Serial a 9600 bauds
    pinMode(ky17, INPUT);     // Definimos el pin del sensor como entrada
}

void loop() 

{
  inclina = digitalRead(ky17);       // Lectura del pin digital conectado al sensor
  Serial.println(inclina);           // Se imprime el valor guardado en "inclina"
  delay(1000);                       //Duración del proceso 1 segundo
  }
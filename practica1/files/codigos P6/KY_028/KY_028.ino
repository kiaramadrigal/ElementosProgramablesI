int ledR = 10;       //Led Rojo del KY-029
int ledV = 9;        //Led Verde del KY-029
int ky013 = A0;     //Valores de entrada analógicos por el termistor
int valor;         //Variable que guardara los datos de entrada del KY-013

//Variables para realizar la ecuación Steinhart-Hart

float R1 = 10000;                                               // Valor de R1 de la PCB 10k
float logR2, R2, TK, TC;                                             //Elementos para realizar la ecuación
float A = 0.001129148, B= 0.000234125, C = 0.0000000876741; //Valores constantes considerando NTC de 10K y trabajando a una temperatura entre -55°C a +125°C

void setup() {
Serial.begin(9600);             //Inicialización del Puerto Serial
pinMode (ledR, OUTPUT) ;        //Declaración del Led Rojo del KY-029
pinMode (ledV, OUTPUT) ;        //Declaración del Led Verde del KY-029
}

void loop() {
valor = analogRead(ky013);                                //Se asigna los valores leídos a la variable valor
Serial.print("Valor Analógico:");                         //Se imprimirá los valores del sensor
Serial.println(valor);                                    // que va de 0-1023, esto para saber que que valores esta teniendo en reposo en termistor
                                                          
valor = map (valor, 0, 270, 0, 50);                       //para evitar la exponencial, usaremos la función map
                                                          //en donde 0-270, serán los valores de entrada analógico vs 0-50 el valor de temperatura
//Conversión de valores analógicos a grados Celsius
R2 = R1 * (1023.0 / (float)valor - 1.0);                   //Calculo de la resistencia del termistor
logR2 = log(R2);                                            //Calculo del logaritmo de la resistencia del termistor
TK = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2)); // Temperatura en Kelvin
TC = TK - 273.15;                                             //Conversión a Temperatura Celsius
TC=TC*(-1);
Serial.print("Temperatura es:"); 
Serial.println(TK);                                          //Impresión de temperatura en Celsius
delay(500);                                                  //Duración del proceso, medio minuto 

digitalWrite(ledR, LOW);                                    //Antes de cualquier función los LED estarán en nivel BAJO/0
digitalWrite(ledV, LOW);
if (T >= 22) {                                               //Si la temperatura es por arriba de 22° 
digitalWrite(ledR, HIGH);                                   //Se encenderá el LED ROJO del KY-029
}
else {                                                       //De lo contrario T<22°C
digitalWrite(ledV, HIGH);                                    //Se encenderá el LED VERDE del KY-029
}
}

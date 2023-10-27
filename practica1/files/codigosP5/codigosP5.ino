int laser = 13 ;    // Definimos el pin de salida digital al modulo KY-008 Laser 
int ky03 = 9;      // Definimos el pin de detección del campo magnético
int iman;            // Definimos la variable donde vamos a grabar los datos del
                        // sensor (0,1);0 sin campo magnético y 1 si detecta
void setup() {
Serial.begin(9600);       
pinMode ( ky03 , INPUT ) ;// Definimos al sensor ky-003 como entrada
pinMode ( laser, OUTPUT); // Definimos al laser como pin de salida

}

void loop()

{
iman= digitalRead ( ky03) ; // Leemos el estado del pin y guardamos el valor en la variable imán
Serial.println(iman);          //impresión en el Monitor Serial de la señal digital (0,1)
if ( iman== HIGH )            // Si el sensor tiene una señal Alta(1) entonces...
{
digitalWrite ( laser, LOW) ;      // el laser no se emitirá luz y el led L13 del Arduino NO prendera
}
else                                  //de lo contrario, si la señal de entrada digital es Baja (0)
{
  digitalWrite ( laser, HIGH) ; / / el laser emitirá luz y el led L13 del Arduino encenderá
}
}
#include <DHT.h>                 //Cargamos la librería DHT
#include <Adafruit_GFX.h>       //Liberia para gráficos
#include <Adafruit_SSD1306.h>  /*Liberia para Oleds monocromáticos basados ​​en controladores SSD1306
                                  Se declara el pin de reset, este es requerido por el constructor de la librería SSD1306
                                  para definir el tipo de OLED y la comunicación I2C en los (pines SDA, SCL)*/
#define OLED_RESET 13
#define DHTTYPE 11                //Definimos el modelo DHT11
#define DHTPIN    8              //Se define el pin para conectar el sensor
float h, t;

Adafruit_SSD1306 display(OLED_RESET);            /*Se define una condición para saber si en la librería esta definida la altura de 32 de lo contrario
                                                  no dejara compilar el código hasta que se cambie la altura correcta desde la librería*/
#if (SSD1306_LCDHEIGHT != 32)
#error("Altura incorrecta, cambie en la librería de Adafruit_SSD1306.h!");
#endif

DHT dht(DHTPIN, DHTTYPE);
void setup()
{
  Serial.begin(9600);   //Se inicia la comunicación serial
  dht.begin();          //Se inicia la libreria DHT
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Se inicia la comunicación I2C en la direcion 0x3C para la pantalla oled 128x32
}
void loop()
{
  h = dht.readHumidity();           //Se realiza la lectura de humedad
  t = dht.readTemperature();        //Se realiza la lectura de temperatura

  //Se imprimen las variables en el display y puerto serial 
  display.setCursor(0, 10);  //Establecer las coordenadas para mostrar la posición del texto
  Serial.println("Humedad");
  //Serial.setCursor(60, 10);
  Serial.println(h);
  //Serial.setCursor(0, 20);  //Establecer las coordenadas para mostrar la posición del texto
  Serial.println("Temperatura");
  //Serial.setCursor(80, 20);
  Serial.println(t);
  //Serial.setCursor(110, 20);
  Serial.println("C");
  //Serial.setCursor(0, 30);
  Serial.println("********************************************************************");
  //Serial.display(); //Muestra el texto
  Serial.println("Humedad: "); Serial.println(h);
  Serial.println("Temperatura: "); Serial.println(t);
  delay(2000);              //Se espera 2 segundos para seguir leyendo datos
}
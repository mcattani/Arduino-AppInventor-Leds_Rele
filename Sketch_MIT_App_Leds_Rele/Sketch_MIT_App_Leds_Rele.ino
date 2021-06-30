/* Este sketch es parte de un proyecto publicado en: https://thenerdyapprentice.blogspot.com/
 * El objetivo de este proyecto es el de crear una aplicación para celular utilizando la plataforma MIT APP INVENTOR
 * para controlar le encendido/apagado y brillo de un conjunto de LEDS y el encendido/apagado de un Relé. Todo a través 
 * de una interfaz bluetooth.
 * El envío de comandos puede hacerse tanto desde la aplicación como del puerto serie (útil para probar el sketch y hacer pruebas).
 * Hay leds conectados en los pines 5 y 4 con sus correspondientes resistencias de 220 ohms.
 * Un Led extra conectado en el pin 3 (PWM) para controlar el brillo del mismo.
 * Un módulo Relé conectado en el pin 10.
 * Un módulo bluetooth HC-06 conectados a los pines 8 y 9. Se utiliza la librería SoftwareSerial para proveer comunicación sobre esos 
 * puertos.
 * Más información puede ser encontrada en el blog citado al principio.
 * The Nerdy Apprentice. 
 */


// Incluimos la librería SoftwareSerial que vamos a utilizar para comunicarnos el módulo BT
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(8, 9); // RX, TX --> Recordar que las conexiones van cruzadas RX en el Arduino -> TX en el módulo BT

// Declaramos las constantes que vamos a utilizar
const byte LRojo = 5;
const byte LAzul = 4;
const byte Rele = 10;
const byte LBlanco = 3;
int Comando;

void setup() {

// Seteamos todos los pines 
pinMode(LRojo, OUTPUT);
pinMode(LAzul, OUTPUT);
pinMode(Rele, OUTPUT);
pinMode(LBlanco, OUTPUT);


// Inicializamos todos los pines apagados.
digitalWrite(LRojo, LOW);
digitalWrite(LAzul, LOW);
digitalWrite(Rele, LOW);
analogWrite(LBlanco, 0);

// Inicializamos los puertos serie
BTSerial.begin(9600);
Serial.begin(9600);
  
}

void loop() {

///////////////////////////////////////////////////////////////////////////////////////
// Configuración para función del puerto Serie.

if(Serial.available()) { // Si llega información al puerto Serie

Comando = Serial.read(); //Leemos lo recibidos y lo almacenamos en la variable 'Comando'

switch (Comando) { // Según el comando -> apagamos/encendemos los LEDS y controlamos el brillo del LED del pin 3
  case 'E':
    digitalWrite(Rele, !digitalRead(Rele));
    break;
  case 'A':
    digitalWrite(LAzul, !digitalRead(LAzul));
    break;
  case 'R':
    digitalWrite(LRojo, !digitalRead(LRojo));
    break;
  case '0':
    analogWrite(LBlanco, 0);
    break;
  case '1':
    analogWrite(LBlanco, 50);
    break;
  case '2':
    analogWrite(LBlanco, 100);
    break;
  case '3':
    analogWrite(LBlanco, 125);
    break;
  case '4':
    analogWrite(LBlanco, 150);
    break;
  case '5':
    analogWrite(LBlanco, 175);
    break;
  case '6':
    analogWrite(LBlanco, 200);
    break;  
  case '7':
    analogWrite(LBlanco, 225);
    break;  
  case '8':
    analogWrite(LBlanco, 250);
    break;
  case '9':
    analogWrite(LBlanco, 255);
    break;
  
   }

 }

///////////////////////////////////////////////////////////////////////////////////////
// Misma configuración que antes pero utilizando la conexión a través del módulo BT.

if(BTSerial.available()) { 

Comando = BTSerial.read();

switch (Comando) {
  case 'E':
    digitalWrite(Rele, !digitalRead(Rele));
    break;
  case 'A':
    digitalWrite(LAzul, !digitalRead(LAzul));
    break;
  case 'R':
    digitalWrite(LRojo, !digitalRead(LRojo));
    break;
  case '0':
    analogWrite(LBlanco, 0);
    break;
  case '1':
    analogWrite(LBlanco, 50);
    break;
  case '2':
    analogWrite(LBlanco, 100);
    break;
  case '3':
    analogWrite(LBlanco, 125);
    break;
  case '4':
    analogWrite(LBlanco, 150);
    break;
  case '5':
    analogWrite(LBlanco, 175);
    break;
  case '6':
    analogWrite(LBlanco, 200);
    break;  
  case '7':
    analogWrite(LBlanco, 225);
    break;  
  case '8':
    analogWrite(LBlanco, 250);
    break;
  case '9':
    analogWrite(LBlanco, 255);
    break;
  
   }
 }
}

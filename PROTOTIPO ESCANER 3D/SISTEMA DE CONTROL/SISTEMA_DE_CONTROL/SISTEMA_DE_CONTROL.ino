// Librerías utilizadas
#include <LiquidCrystal.h>  // Incluye la librería para el LCD estándar (no I2C)
#include <Wire.h>  // Incluye la librería para el I2C del LCD. SCL se conecta al pin A5, SDA se conecta al pin A4. Se necesita un jumper en el pin de retroiluminación LED en la placa I2C.
#include <Stepper.h>  // Incluye la librería para controlar motores paso a paso.
#include <Servo.h>  // Incluye la librería para controlar servos.

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);  // Inicializa el LCD 1602 usando los pines especificados.

const int SW_pin = 8; // Pin digital conectado a la salida del interruptor.
const int X_pin = A0; // Pin analógico conectado a la salida X del joystick.
const int Y_pin = A1; // Pin analógico conectado a la salida Y del joystick.

int MenuNr = 0;   // Número del menú.
int PhotoNr = 2;  // Cantidad de fotos que se deben tomar.
bool Flag1 = 0;   // Bandera activa durante un ciclo de programa para evitar incrementar/decrementar continuamente el número del menú.
bool Flag2 = 0;   // Bandera activa durante un ciclo de programa para evitar incrementar/decrementar continuamente el número de fotos.
bool Flag3 = 0;   // Bandera activa durante un ciclo de programa para evitar incrementar/decrementar continuamente las RPM.
bool Flag4 = 0;   // Bandera activa durante un ciclo de programa para evitar incrementar/decrementar continuamente el número de giros.
bool Flag5 = 0;   // Bandera activa durante un ciclo de programa para evitar incrementar/decrementar continuamente las RPM.
bool Flag6 = 0;   // Bandera activa durante un ciclo de programa para limpiar el LCD.
int SwMenu = 0;   // Menú del interruptor (submenús en los menús principales).
bool BtnFlag = 0; // Bandera activa durante un ciclo de programa para evitar incrementar continuamente SwMenu cuando se presiona el botón.

// Variables añadidas para modos de cambio rápido y cancelación
int FastChng = 0;  // Indica el modo de cambio rápido. 0 = apagado, 1 = modo de demora, 2 = modo de cambio rápido.
const unsigned long FastDelay = 1000;  // Tiempo de demora para el modo rápido (antes de que los valores cambien rápido).
const unsigned long ShortInt = 100;  // Intervalo corto de cambio rápido.
const unsigned long LongInt = 300;  // Intervalo largo de cambio rápido.
const unsigned long BtnDelay = 2000;  // Retardo para la cancelación de operaciones al presionar el botón. Nota: este es un retardo aproximado, ya que el motor paso a paso suspende toda la ejecución del programa hasta que finaliza su movimiento.
unsigned long SetTime = 0; // Valor de tiempo para modos de cambio rápido y cancelación con botón. Usado para calcular intervalos de tiempo.
bool BtnCancelFlag = 0; // Bandera usada para detectar cuando se presiona el botón para cancelar operaciones.
bool MaxSwMenu = 0;  // Bandera usada para detectar cuando se alcanza el máximo SwMenu.
bool CinCancelFlag = 0;  // Bandera usada para activar la cancelación cinematográfica. 1 = cancelar operación cinematográfica.
int StepPoll = 480;  // Número de pasos del motor para sondear la cancelación cinematográfica (a 15 rpm).
int Cntr = 0;  // Contador de pasos para la cancelación del motor cinematográfico.
// Fin de las variables añadidas.

const int stepsPerRevolution = 2000;  // Cambia esto para ajustar el número de pasos por revolución.
int FullRev = 14336;  // 1 revolución completa del engranaje grande -> La relación entre el engranaje pequeño y el grande es de 7:1.
int rolePerMinute = 15;  // Rango ajustable del motor paso a paso 28BYJ-48 es de 0~17 rpm.
int PhotoTaken = 0;  // Cantidad de fotos tomadas.
int StepPerPhoto;  // Cantidad de pasos por foto (calculado -> ver MenuNr 0/SwMenu 2).
int TurnNr = 1;  // Cantidad de giros.
int CurrentTurn = 0;  // Almacena el número de giro actual.
int Steps = 0;  // Cantidad de pasos individuales que el motor paso a paso tiene que girar.

Stepper myStepper(stepsPerRevolution, 9, 11, 10, 12);  // Inicializa el motor paso a paso usando los pines especificados.

Servo Servo1;  // Define Servo1 como un servo.


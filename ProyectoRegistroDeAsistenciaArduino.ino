
/* Proyecto Modular Codigo   Sistema de Registro de Asistencia
 *  Jorge Enrique Meza Gutierrez
 

*/
#include <Adafruit_GFX.h> // Libreia para hardware
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#include <Keypad.h>
#include<Wire.h>
#include <SoftwareSerial.h>
#include <virtuabotixRTC.h>
virtuabotixRTC myRTC(44, 45, 46);  //click , dat, rst
#include <Adafruit_Fingerprint.h>    // Libreria  para el Sensor de huella dactilar



SoftwareSerial BT(50,51); // 0 RX, 1 TX.

uint16_t xO = 100, yO = 110;

////////////////////////////////////////////////////////////////////////sensor de huella////////
#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
SoftwareSerial mySerial(18, 19);   // Crear Serial para Sensor  Rx, TX del Arduino
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
#else
#define mySerial Serial1
#endif
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
uint8_t id;
////////////////////////////////////////////////////////////////////////sensor de huella////////


int my_id = 0; //variable

//variables 
int opt;  
char optc;
int iddivision=0;

int idR=0;
 byte INDICETiempo = 0;
  byte ConteoEspacios=0;

char ingreid[2];     //variable tipo array de 2 espacios
String ingid;
int idcovert=0;
////////////////////////////////////////////////declaracion del teclado/////////////////////////////////////
const byte filas = 4;            
const byte columnas = 4;

byte pinsFilas[filas] = {22, 23, 24, 25};   //22 cafe, 23 rojo, 24 naranja, 25 amarillo
byte pinsColumnas[columnas] = {28,29, 30, 31};     //28 verde, 29 azul, 30 morado, 31 blanco
char teclas[filas][columnas] =  {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

Keypad teclado = Keypad(makeKeymap(teclas), pinsFilas, pinsColumnas, filas, columnas);
////////////////////////////////////////////////declaracion del teclado/////////////////////////////////////
 char TECLA;   //variable para teclas

char Clave[6];
char ClaveMaestra[6]= "12345";
byte IndiceClave = 0;
byte IndiceClaveM=0;

byte ModoCLAVE =0;
byte ModoCLAVEM=0;
byte ModoClaveMensaje=0;
byte ModoClaveMensajeM=0;
byte ConteoEspaciosclave=0;
byte ConteoEspaciosclaveM=0;
 
 ///////////////////varibleses contadoras
 byte ModoB=0;
 char EleccionModoB;
 byte ModoBMensaje=0;
char EleccionModoC;
 byte ModoCMensaje=0;
 byte ModoC=0;
 byte ModoA=0;
  byte ModoD=0;
  byte ModoCC=0;

  byte ModoCT=0;
 int x=0;
char Asis[50];
int d=0;

int segundahuella=0;
int segidhuella=0;

byte bmensaje=0;
byte cmensaje=0;
byte ccmensaje=0;

int v50=50;
int convert=0;
 //////////////////////Varaibles Cadenas//////////////
  String horas;
  String minutos;
  String segundos;
//////////////////////Varaibles Cadenas//////////////

 //////////////////////Colores de Letra //////    
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define BLACK   0x0000
 //////////////////////Colores de Letra //////    

////////////////////////////////////////////variables enteras//////////////////////


   ///////////////////////////////////////////variables enteras//////////////////////

////////////////////////////////////////////variables de tipo byte//////////////////////

  byte IndiceGTI=0; //revisar
////////////////////////////////////////////variables de tipo byte//////////////////////


void setup() {   ///////////////void setup ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
tft.reset();
         // segundos, minutos, horas, dia de la semana, dia del mes, mes, año
 //myRTC.setDS1302Time(00, 21, 8, 1, 28, 11, 2022); //configuracion del reloj

  Serial.begin(9600);

pinMode(A13, OUTPUT);   //huella
digitalWrite(A13, HIGH); //huella

////////////////////////////////////////////////Inicio de la pantalla tft/////////////////////////////////////
    tft.reset();
    uint16_t identifier = tft.readID();
    //Serial.print("ID = 0x");
    //Serial.println(identifier, HEX);
    if (identifier == 0xEFEF) identifier = 0x9486;
    tft.begin(identifier);
    //  tft.fillScreen(BLACK);
     tft.fillScreen(0x0000);
      tft.setRotation(1);
 ////////////////////////////////////////////////Inicio de la pantalla tft/////////////////////////////////////



 
 

        pinMode(A8, OUTPUT);   ///blue
     
   ////////////////////////////////////////////////Mensajes Entrada/////////////////////////////////////




     
////////////////////////////////////////////////Mensajes Entrada/////////////////////////////////////





  finger.begin(57600);  // inicializa comunicacion con sensor a 57600 Baudios
  delay(5);
  if (finger.verifyPassword()) { /////////funcion verifica sensor
    //Serial.println("Detectado un sensor de huella!");
Serial.println("Sensor listo");
 tft.setCursor(80, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Sistema");
       tft.setCursor(30, 90);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Registro De");
tft.setCursor(40, 130);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Asistencia"); 
       delay(3000);
       
  } else {
  

Serial.println("Sensor no listo");
 
 
 tft.setCursor(100, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Sensor");

 tft.setCursor(140, 100);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("No");

       tft.setCursor(110, 150);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Listo");


       
    //Serial.println("No hay comunicacion con el sensor de huella");
   // Serial.println("Revise las conexiones");
    while (1) { delay(1); }
  }


finger.getTemplateCount();// funcion sensor de huella iniciar




for(int i=0; i<50; i++) //ciclo for
{

   Asis[i]=0; 


}


 delay(2000);
    tft.fillScreen(0x0000);
}  ///////////////void setup ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




char DataBluetooth =' ';


void loop() {
  BT.begin(9600); 
  Serial.begin(9600);
  ProgramaR(1);  ////Funcion de programa////////////////
   
    
    // 
   
    //Serial.println("");
    //Serial.println("Iniciando Control ...");
    //pinMode(bluetooth_ensendido,OUTPUT);
    //digitalWrite(bluetooth_ensendido,LOW);
}
 


void ProgramaR(int a)  //////Inicio de la Funcion ProgramaR//////////////////
{


 if(ModoB==0 && ModoC==0 && ModoD==0 && ModoCC==0 )
 {
  ModoClaveMensaje=0;
 tft.setCursor(20, 10);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Menu de opciones");
tft.setCursor(20, 50);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK);
       tft.print("A: Registro"); 
tft.setCursor(20, 80);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK);
       tft.print("B: Nuevo Id"); 
tft.setCursor(20, 110);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK);
       tft.print("C: Borrar Id"); 

       tft.setCursor(20, 140);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK);
       tft.print("D: Registro Face");
         tft.setCursor(20, 170);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK);
       tft.print("#: Cambio CRS");
       

 myRTC.updateTime(); 
   if(myRTC.hours <10)
 {

  tft.setCursor(15, 210);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK);
       tft.print("0");
       
tft.setCursor(35, 210);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK);
       tft.print(myRTC.hours);
       
 }
 else{
  tft.setCursor(15, 210);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK);
       tft.print(myRTC.hours);
 }
       //
tft.setCursor(50, 203);
  tft.setTextSize(5);
     tft.setTextColor(BLUE,BLACK);
       tft.print(":");

       
 if(myRTC.minutes <10)
 {
tft.setCursor(75, 210);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK);
       tft.print("0");
 tft.setCursor(95, 210);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK);
       tft.print(myRTC.minutes);
       
 
 }
 else{
   tft.setCursor(75, 210);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK);
       tft.print(myRTC.minutes);
 }

       
 }


if(ModoA==1) //funcion principal evaluando
{
   tft.fillScreen(0x0000);
tft.setCursor(40, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Coloque el");
tft.setCursor(40, 60);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Dedo en el");   
       tft.setCursor(90, 110);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Sensor");  


while(ModoA==1) //ciclo while para repeticion
{ 

getFingerprintIDez(); //funcion del escaner
 
 
}

}
   







 if(ModoD==1) ///evaluaando entrada de datos
 {
opt=0;
   optc='0';

tft.setCursor(20, 130);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Verificando");

  
if (Serial.available() > 0){

    opt = Serial.read();
for(int i=0; i<50; i++){//////////////ciclo para aumentar el registro
if(Asis[i] == opt) //evaluando casos iguales
{
  i=50;

  d=2;
}
else{
d=1;
  optc=opt;
}
}//////////////ciclo para aumentar el registro





   
    if(d== 1){ ///evaluando datos
   tft.fillScreen(0x0000);
tft.setCursor(50, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Bienvenido");
tft.setCursor(95, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("NL."); 
tft.setCursor(180, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print(optc);

Serial.print("NL. ");
       Serial.print(optc);
       Serial.println();
       
       Asis[x++] = opt;
ModoD=0;
       delay(5000);
    }

 /*if(optc== '0'){
   tft.fillScreen(0x0000);
tft.setCursor(50, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Desconocido");
       //ModoD=0;
       delay(5000);
 }*/

if(d==2)////////////////////validacion de segundo registro
{
   tft.fillScreen(0x0000);
      tft.setRotation(1);
tft.setCursor(140, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Ya");
       
      tft.setCursor(70, 80);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Has sido"); 
       
tft.setCursor(45, 120);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Registrado"); 
   ModoD=0;
   delay(5000);
   tft.fillScreen(0x0000);
}////////////////////validacion de registro

 
    }
 }//////////////////////////////////modoD////////////////////////////
 
 
                                                                                            //|
 
 BT.begin(9600); 
BT.available();
 
TECLA = teclado.getKey();     ////Declaracion de tecla para el telcado////////

 DataBluetooth= BT.read();



if(DataBluetooth=='0' || DataBluetooth=='1'  || DataBluetooth=='2' || DataBluetooth=='3')
{
  TECLA=DataBluetooth;
}
if(DataBluetooth=='4' || DataBluetooth=='5'  || DataBluetooth=='6' || DataBluetooth=='7')
{
  TECLA=DataBluetooth;
}
if(DataBluetooth=='8' || DataBluetooth=='9' ||DataBluetooth=='#' )
{
  TECLA=DataBluetooth;
}

if(DataBluetooth=='A' || DataBluetooth=='B' || DataBluetooth=='C' || DataBluetooth=='D')
{
  TECLA=DataBluetooth;
}


  if (TECLA != NO_KEY)          /////if no es necesario oprimir tecla//////
  
    switch (TECLA) {         //////Inicio del menu switch//////////////////
      case 'A':             //////Inicio opcion A//////////////////
/*
tft.fillScreen(0x0000);
      tft.setCursor(75, 40);
  tft.setTextSize(3.5);
     tft.setTextColor(BLUE);
 tft.print("Modo A");
*/
ModoA=1;
     break;                   //////Fin opcion A//////////////////
        
      case 'B':          //////Inicio opcion B//////////////////
//ModoB=1;
if(ModoClaveMensaje==0)
{
ModoCLAVE=1;
ModoB=7;
ModoC=0;
ModoCC=0;
tft.fillScreen(0x0000);
 tft.setCursor(80, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Ingresa");
tft.setCursor(70, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("la clave");  

tft.setCursor(110, 100);
  tft.setTextSize(4);
     tft.setTextColor(CYAN,BLACK);
       tft.print("_");
       
bmensaje=1;
  
}

if(ModoClaveMensaje==1 && ModoCLAVE==0)
{
  ModoB=1;
}



if(ModoB==1 && ModoBMensaje==0){ //evaluando 2da funcion
ModoC=0;
ModoCMensaje=0;
reset1();

 tft.fillScreen(0x0000);
 tft.setCursor(30, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Registro De");
tft.setCursor(90, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Huella");  

 finger.getTemplateCount(); //funcion de registro de huella


tft.setCursor(20, 90);
  tft.setTextSize(2);
     tft.setTextColor(BLUE,BLACK);
       tft.print("El sensor contiene");

       iddivision= finger.templateCount / 2;
       tft.setCursor(250, 90);
  tft.setTextSize(2);
     tft.setTextColor(BLUE,BLACK); 
 tft.print(iddivision); 
 
   tft.setCursor(270, 90);
  tft.setTextSize(2);
     tft.setTextColor(BLUE,BLACK); 
 tft.print("Id"); 
 
  //Serial.println("Esperando por una huella valida...");
 // Serial.println("Listo");


tft.setCursor(10, 130);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK); 
 tft.print("Ingresa el nuevo"); 
tft.setCursor(10, 160);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK); 
 tft.print("Id:"); 
 
}

if(ModoB==1 && ModoBMensaje==1); ///evaluando condicion
{
  
    //char c = EleccionModoB;
    

 
   id= idcovert;

   
 
  if (id == 0) {// ID #0 not allowed, try again!
     return;
  }
  else{
     tft.fillScreen(0x0000);
tft.setCursor(40, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Coloque el");
tft.setCursor(40, 60);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Dedo en el");   
       tft.setCursor(90, 110);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Sensor");  

 tft.setCursor(40, 160);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Id:");  
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print(id); 
  }

  //Serial.print("Enrolando  ID #");
 // Serial.println(id);

  while (!  getFingerprintEnroll() ); //ciclo while en ejecucion
  
 ModoBMensaje=2;
idcovert=0;
}

if(ModoB==1 && ModoBMensaje==2); ///evaluando condicion
{
 tft.fillScreen(0x0000);
tft.setCursor(75, 60);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Registro");
tft.setCursor(85, 100);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Segunda");   
       tft.setCursor(95, 140);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Huella");
segidhuella=id;
if(id >=1 && id <= 10)
{
  segidhuella+= v50;

  /* tft.setCursor(90, 150);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
      // tft.print(segidhuella); */

       id =segidhuella;
}

if(id >=11 && id <= 20)
{
  segidhuella+= v50;

   tft.setCursor(90, 150);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
      // tft.print(segidhuella);

       id =segidhuella;
}

if(id >=21 && id <= 30)
{
  segidhuella+= v50;

   tft.setCursor(90, 150);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       //tft.print(segidhuella);

       id =segidhuella;
}

if(id >=31 && id <= 40)
{
  segidhuella+= v50;

   tft.setCursor(90, 150);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
      // tft.print(segidhuella);

       id =segidhuella;
}

if(id >=41 && id <= 50)
{
  segidhuella+= v50;

   tft.setCursor(90, 150);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
      // tft.print(segidhuella);

       id =segidhuella;
}


delay(4000);
if (id == 0) {// ID #0 not allowed, try again!
     return;
  }
  else{
     tft.fillScreen(0x0000);
tft.setCursor(40, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Coloque el");
tft.setCursor(40, 60);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Dedo en el");   
       tft.setCursor(90, 110);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Sensor");  
  }

 while (!  getFingerprintEnroll() ); //ciclo while en ejecucion
reset1();

 ModoBMensaje=0;
EleccionModoB=0;
id=0;
reset1();
ModoB=0;


ModoCMensaje=0;
   ModoBMensaje=0;
   ModoClaveMensaje =1;
   ModoClaveMensajeM =0;
   ModoCLAVEM=0;
   ModoCLAVE=0;
   bmensaje=0;
   cmensaje=0;
   ccmensaje=0;
   ModoCC=0;
    IndiceClaveM=0;            
 ConteoEspaciosclaveM=0;
   memset(&Clave,0,sizeof(Clave));//////Variables a 0//////////////////
   
  memset(&printPassClave,0,sizeof(printPassClave));
   memset(&printPassClaveM,0,sizeof(printPassClaveM)); 
 IndiceClaveM=0;            
 ConteoEspaciosclaveM=0;
  
 IndiceClave=0;            
 ConteoEspaciosclave=0;






}

  
      break;           //////Fin opcion B//////////////////
      
        case 'C':          //////Inicio opcion C//////////////////
//ModoC=1;

if(ModoClaveMensaje==0)
{
ModoCLAVE=1;
ModoC=7;
ModoB=0;
ModoCC=0;
cmensaje=1;
tft.fillScreen(0x0000);
 tft.setCursor(80, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Ingresa");
tft.setCursor(70, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("la clave");  

tft.setCursor(110, 100);
  tft.setTextSize(4);
     tft.setTextColor(CYAN,BLACK);
       tft.print("_");
       

  
}

if(ModoClaveMensaje==1 && ModoCLAVE==0)
{
  ModoC=1;
}



if(ModoCT==10 && ModoC==1)
  {
 
tft.fillScreen(0x0000);
   tft.setCursor(30, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Eliminacion");
       tft.setCursor(80, 90);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Total");
       //ModoCMensaje==5; 
delay(3000);


       tft.fillScreen(0x0000);
   tft.setCursor(30, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Eliminacion");
       tft.setCursor(140, 90);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("En");
       
tft.setCursor(70, 120);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Proceso"); 
finger.emptyDatabase();


delay(3000);
  tft.fillScreen(0x0000);
   tft.setCursor(35, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Eliminacion");
       tft.setCursor(80, 90);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Exitosa");
       delay(3000);
tft.fillScreen(0x0000);
reset1(); 
 ModoC=0;
 ModoCT= NULL;
  }



if(ModoC==1 && ModoCMensaje==0){ //evaluando 2da funcion
ModoB=0;
ModoCT++;
ModoBMensaje=0;
reset1(); 

memset(&ingreid,0,sizeof(ingreid));//////Variables a 0//////////////////
  memset(&printPassGT,0,sizeof(printPassGT));
  memset(&ingid,0,sizeof(ingid));


tft.fillScreen(0x0000);
tft.setCursor(70, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Eliminar");
tft.setCursor(90, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Huella"); 

 finger.getTemplateCount(); //3era funcion borrar huella


tft.setCursor(20, 90);
  tft.setTextSize(2);
     tft.setTextColor(BLUE,BLACK);
       tft.print("El sensor contiene");
        iddivision= finger.templateCount / 2;
       tft.setCursor(250, 90);
  tft.setTextSize(2);
     tft.setTextColor(BLUE,BLACK); 
 tft.print(iddivision); 
 
   tft.setCursor(270, 90);
  tft.setTextSize(2);
     tft.setTextColor(BLUE,BLACK); 
 tft.print("Id"); 
 
 // Serial.println("Esperando por una huella valida...");
 // Serial.println("Listo");


tft.setCursor(10, 130);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK); 
 tft.print("Ingresa el Id"); 
tft.setCursor(10, 160);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK); 
 tft.print("Para borrar:"); 

tft.setCursor(270, 200);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK); 
 tft.print(ModoCT); 

 
}

if(ModoC==1 && ModoCMensaje==1); ///evaluando condicion
{
 
   id= idcovert;

   
 
  if (id == 0) {// ID #0 not allowed, try again!
     return;
  }
else{
tft.fillScreen(0x0000);
   tft.setCursor(30, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Eliminacion");
       tft.setCursor(140, 90);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("En");
       
tft.setCursor(70, 120);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Proceso"); 
       
       tft.setCursor(40, 160);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Id:");  
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print(id); 
       
       delay(3000);
  deleteFingerprint(id);

}
ModoC=2;
ModoCMensaje=1;
}//////////////////////////////////////if(ModoC==1 && ModoCMensaje==1); ///evaluando condicion

if(ModoC==2 && ModoCMensaje==2); ///evaluando condicion
{
 
segidhuella=id;
if(id >=1 && id <= 10)
{
  segidhuella+= v50;
       id =segidhuella;  
}

if(id >=11 && id <= 20)
{
  segidhuella+= v50;

       id =segidhuella;
}

if(id >=21 && id <= 30)
{
  segidhuella+= v50;

       id =segidhuella;
}

if(id >=31 && id <= 40)
{
  segidhuella+= v50;

       id =segidhuella;
}

if(id >=41 && id <= 50)
{
  segidhuella+= v50;
       id =segidhuella;
}


delay(1000);
if (id == 0) {// ID #0 not allowed, try again!
     return;
  }
  else{

tft.fillScreen(0x0000);
   tft.setCursor(30, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Eliminacion");
       tft.setCursor(180, 90);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("2DA");
       
tft.setCursor(70, 120);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Huella"); 
       
       tft.setCursor(40, 160);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
      /* tft.print("Id:");  
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print(id); */
       
       delay(3000);
  deleteFingerprint(id);

  
  }

reset1();

 ModoCMensaje=0;
EleccionModoC=0;
id=0;
ModoC=0;
ModoB=0;
ModoCT=0;
reset1();



ModoCMensaje=0;
   ModoBMensaje=0;
   ModoClaveMensaje =1;
   ModoClaveMensajeM =0;
   ModoCLAVEM=0;
   ModoCLAVE=0;
   bmensaje=0;
   cmensaje=0;
   ccmensaje=0;
   ModoCC=0;
    IndiceClaveM=0;            
 ConteoEspaciosclaveM=0;
   memset(&Clave,0,sizeof(Clave));//////Variables a 0//////////////////
  memset(&printPassClave,0,sizeof(printPassClave));
   memset(&printPassClaveM,0,sizeof(printPassClaveM)); 
 IndiceClaveM=0;            
 ConteoEspaciosclaveM=0;
  
 IndiceClave=0;            
 ConteoEspaciosclave=0;


}


  
       
        break;              //////Fin opcion C//////////////////
     
      case 'D':            //////Inicio opcion D//////////////////////////////////////////////////////////////////////////
        ModoD=1;
       tft.fillScreen(0x0000);
      tft.setCursor(30, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Registro De");
tft.setCursor(30, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Asistencia");

tft.setCursor(50, 90);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Facial");
       
        break;                        

case '#':   

if(ModoClaveMensajeM==0)
{
ModoCLAVEM=1;
ModoCC=7;
ccmensaje=1;
tft.fillScreen(0x0000);
 tft.setCursor(80, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Ingresa");
tft.setCursor(70, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("la clave");  

tft.setCursor(110, 100);
  tft.setTextSize(4);
     tft.setTextColor(CYAN,BLACK);
       tft.print("_");
       

  
}

if(ModoClaveMensajeM==1 && ModoCLAVE==0)
{
  ModoCC=1;
}


if(ModoCC==1){
tft.fillScreen(0x0000);
 tft.setCursor(50, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Cambio de");
tft.setCursor(100, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Clave");  

tft.setCursor(110, 100);
  tft.setTextSize(4);
     tft.setTextColor(RED,BLACK);
       tft.print("_");

 
  ModoCLAVEM=2;
  ModoCLAVE==0;
  
}




break;





case '*':            //////Inicio opcion *//////////////////////////////////////////////////////////////////////////
   ModoA=0;
   ModoB=0;
   ModoC=0;
   ModoD=0;
   ModoCT=0;
   ModoCMensaje=0;
   ModoBMensaje=0;
   ModoClaveMensaje =1;
   ModoClaveMensajeM =0;
   ModoCLAVEM=0;
   ModoCLAVE=0;
   bmensaje=0;
   cmensaje=0;
   ccmensaje=0;
   ModoCC=0;
    IndiceClaveM=0;            
 ConteoEspaciosclaveM=0;
   memset(&Clave,0,sizeof(Clave));//////Variables a 0//////////////////
  memset(&printPassClave,0,sizeof(printPassClave));
   memset(&printPassClaveM,0,sizeof(printPassClaveM)); 
 IndiceClaveM=0;            
 ConteoEspaciosclaveM=0;
  
 IndiceClave=0;            
 ConteoEspaciosclave=0;
      reset1();
      tft.fillScreen(0x0000);
        break; 


      default:  
     //////Opcion default//////////////////

 if(ModoCLAVEM==2 && ModoCC==1)
     {
      
if(ConteoEspaciosclaveM <= 5)        //////If evaluando//////////////////
        { 
        ingresarClaveM();        //////ingresar a la funcion//////////////////
 IndiceClaveM++;             //////aumentar valor//////////////////
 ConteoEspaciosclaveM++;           //////aumentar valor//////////////////

        }

        if(IndiceClaveM==5)
        {         
          tft.fillScreen(0x0000);
 tft.setCursor(100, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Clave");
tft.setCursor(40, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Actualizada");  
    
tft.setCursor(20, 90);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Correctamente"); 

       delay(3000);
       tft.fillScreen(0x0000);
          ModoCLAVEM=0;
          ModoCC=0;
         memset(&Clave,0,sizeof(Clave));//////Variables a 0//////////////////
  memset(&printPassClaveM,0,sizeof(printPassClaveM));
  
 IndiceClaveM=0;            
 ConteoEspaciosclaveM=0;
  TECLA=NO_KEY;
   TECLA=NULL;   
        
        
        }  
     }/////////////////////////fin del modo claveM//////////////////////////////////////////////////











     


     if((ModoCLAVE=1 && ModoB==7) || (ModoCLAVE=1 && ModoC==7) || (ModoCLAVE=1 && ModoCC==7) )
     {
if(ConteoEspaciosclave <= 5)        //////If evaluando//////////////////
        { 
        ingresarClave();        //////ingresar a la funcion//////////////////
 IndiceClave++;             //////aumentar valor//////////////////
 ConteoEspaciosclave++;           //////aumentar valor//////////////////

        }

        if(IndiceClave==5)
        {
        if(!strcmp(Clave, ClaveMaestra))
        {

          
          tft.fillScreen(0x0000);
 tft.setCursor(110, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Clave");
tft.setCursor(70, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Correcta");  

  if(bmensaje==1)
  {
     tft.setCursor(75, 90);
  tft.setTextSize(3);
   tft.setTextColor(BLUE,BLACK);
       tft.print("Presione B");
  }
if(cmensaje==1)
  {
     tft.setCursor(75, 90);
  tft.setTextSize(3);
   tft.setTextColor(BLUE,BLACK);
       tft.print("Presione C");
  }

  if(ccmensaje==1)
  {
     tft.setCursor(75, 90);
  tft.setTextSize(3);
   tft.setTextColor(BLUE,BLACK);
       tft.print("Presione #");
  }
  
    
tft.setCursor(40, 130);
  tft.setTextSize(3);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Para Continuar"); 
       
        ModoClaveMensaje=1;
        ModoClaveMensajeM=1;
          ModoCLAVE=0;
memset(&Clave,0,sizeof(Clave));//////Variables a 0//////////////////
  memset(&printPassClave,0,sizeof(printPassClave));
  
 IndiceClave=0;            
 ConteoEspaciosclave=0;
  TECLA=NO_KEY;
   TECLA=NULL;
          
        }
        else
        {
          tft.fillScreen(0x0000);
 tft.setCursor(110, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Clave");
tft.setCursor(50, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Incorrecta"); 
       memset(&Clave,0,sizeof(Clave));//////Variables a 0//////////////////
  memset(&printPassClave,0,sizeof(printPassClave));
  
 IndiceClave=0;            
 ConteoEspaciosclave=0;
  TECLA=NO_KEY;
   TECLA=NULL; 
          
        }    
        }  
     }/////////////////////////fin del modo clave//////////////////////////////////////////////////


     if(ModoB==1) //evaluando condicion /////////////////////////////////////////////////////////////////7inicio modo b
     {
      ModoBMensaje=1;

if(ConteoEspacios <= 1)        //////If evaluando//////////////////
        { 
        ingresarT();        //////ingresar a la funcion//////////////////
 INDICETiempo++;             //////aumentar valor//////////////////
 ConteoEspacios++;           //////aumentar valor//////////////////
        }

if(INDICETiempo == 1)         //////If evaluando//////////////////
 {
/*tft.setCursor(170, 160);
  tft.setTextSize(3);
     tft.setTextColor(BLUE);
 tft.println(INDICETiempo);*/
  
  if(convert==0)
  {
  
   ingid += ingreid[0];
   
idcovert = ingid.toInt();
convert=1;
  }
   if(idcovert >=51 || idcovert ==0 )
   {
    /*tft.setCursor(70, 180);
      tft.setTextSize(3);
     tft.setTextColor(BLUE);
 tft.println(ingid);*/

        mensajeRes1();
        
   }
 }

      if(INDICETiempo ==2 )         //////If evaluando//////////////////
 {
  convert=0;
  memset(&ingid,0,sizeof(ingid));
  idcovert=0;
 /*tft.setCursor(170, 160);
  tft.setTextSize(3);
     tft.setTextColor(BLUE);
 tft.println(INDICETiempo);*/
  
  if(convert==0)
  {
    for(int i=0; i<=1; i++)   //////Ciclos For para llenar Strings//////////////////   
   { 
   ingid += ingreid[i];
   }
idcovert = ingid.toInt();
convert=1;
  }
  
   if(idcovert >=51 || idcovert ==0 )
   {
      /*tft.setTextSize(3);
     tft.setTextColor(BLUE);
 tft.println(ingid);*/
        mensajeRes1();
      
   }
   INDICETiempo =3;
 }
   
   

  
     }///////////////fin modo B
     

  if(ModoC==1)//////////////////////////////////////////////////////////////////////////////////////////inicio modo C
     {
      ModoCMensaje=1; 
if(ConteoEspacios <= 1)        //////If evaluando//////////////////
        { 
        ingresarT();        //////ingresar a la funcion//////////////////
 INDICETiempo++;             //////aumentar valor//////////////////
 ConteoEspacios++;           //////aumentar valor//////////////////
        }

if(INDICETiempo == 1)         //////If evaluando//////////////////
 {
/*tft.setCursor(270, 160);
  tft.setTextSize(3);
     tft.setTextColor(BLUE);
 tft.println(INDICETiempo);*/
  
  if(convert==0)
  {
  
   ingid += ingreid[0];
   
idcovert = ingid.toInt();
convert=1;
  }
   if(idcovert >=51 || idcovert ==0 )
   {
    /*tft.setCursor(70, 180);
      tft.setTextSize(3);
     tft.setTextColor(BLUE);
 tft.println(ingid);*/
 ModoCT=0;
        mensajeRes1();
        
   }
 }

      if(INDICETiempo ==2 )         //////If evaluando//////////////////
 {
  convert=0;
  memset(&ingid,0,sizeof(ingid));
  idcovert=0;
 /*tft.setCursor(270, 160);
  tft.setTextSize(3);
     tft.setTextColor(BLUE);
 tft.println(INDICETiempo);*/
  
  if(convert==0)
  {
    for(int i=0; i<=1; i++)   //////Ciclos For para llenar Strings//////////////////   
   { 
   ingid += ingreid[i];
   }
idcovert = ingid.toInt();
convert=1;
  }
  
   if(idcovert >=51 || idcovert ==0 )
   {
      /*tft.setTextSize(3);
     tft.setTextColor(BLUE);
 tft.println(ingid);*/
 ModoCT=0;
        mensajeRes1();
      
   }
   INDICETiempo =3;
 }




      


     } /////////////////////////////////////fin del modo c///////////////
break;
        
    }//////fin del switch
    
       
          
}///////////////////////////Fin de la Funcion ProgramaR//////////////////



void ingresarT()        //////Inicio de la funcio ingresarT//////////////////
{

       ingreid[INDICETiempo]= TECLA;          //////LLenar cadena//////////////////
        printPassGT(ingreid[INDICETiempo]);     //////Funcion imprimir//////////////////
        
 
     }//////Fin de la funcio ingresarT//////////////////

void ingresarClaveM()        //////Inicio de la funcio ingresarT//////////////////
{

       ClaveMaestra[IndiceClaveM]= TECLA;          //////LLenar cadena//////////////////
        printPassClaveM(ClaveMaestra[IndiceClaveM]);     //////Funcion imprimir//////////////////
        
 
     }//////Fin de la funcio ingresarT//////////////////


void ingresarClave()        //////Inicio de la funcio ingresarT//////////////////
{

       Clave[IndiceClave]= TECLA;          //////LLenar cadena//////////////////
        printPassClave(Clave[IndiceClave]);     //////Funcion imprimir//////////////////
        
 
     }//////Fin de la funcio ingresarT//////////////////

void printPassClave(char a) {   //////Inicio de la funcio printPass//////////////////


  if(ModoCLAVE==1){ 
 if(IndiceClave ==0){
tft.setCursor(110, 100);
  tft.setTextSize(4);
     tft.setTextColor(CYAN,BLACK);
      tft.print(a);   
tft.setCursor(135, 100);
  tft.setTextSize(4);
     tft.setTextColor(CYAN,BLACK);
       tft.print("_");       
     }

      if(IndiceClave ==1){
tft.setCursor(135, 100);
  tft.setTextSize(4);
     tft.setTextColor(CYAN,BLACK);
      tft.print(a);   
tft.setCursor(160, 100);
  tft.setTextSize(4);
     tft.setTextColor(CYAN,BLACK);
       tft.print("_");       
     }
if(IndiceClave ==2){
tft.setCursor(160, 100);
  tft.setTextSize(4);
     tft.setTextColor(CYAN,BLACK);
      tft.print(a);   
tft.setCursor(185, 100);
  tft.setTextSize(4);
     tft.setTextColor(CYAN,BLACK);
       tft.print("_");       
     }

if(IndiceClave ==3){
tft.setCursor(185, 100);
  tft.setTextSize(4);
     tft.setTextColor(CYAN,BLACK);
      tft.print(a);   
tft.setCursor(210, 100);
  tft.setTextSize(4);
     tft.setTextColor(CYAN,BLACK);
       tft.print("_");       
     }

if(IndiceClave ==4){
tft.setCursor(210, 100);
  tft.setTextSize(4);
     tft.setTextColor(CYAN,BLACK);
      tft.print(a);          
     }
    
     

}

 delay(100);
}
 
 
//////Fin de la funcio printPass//////////////////


void printPassClaveM(char a) {   //////Inicio de la funcio printPass//////////////////



if(ModoCLAVEM==2){ 
 if(IndiceClaveM ==0){
tft.setCursor(110, 100);
  tft.setTextSize(4);
     tft.setTextColor(RED,BLACK);
      tft.print(a);   
tft.setCursor(135, 100);
  tft.setTextSize(4);
     tft.setTextColor(RED,BLACK);
       tft.print("_");       
     }

      if(IndiceClaveM ==1){
tft.setCursor(135, 100);
  tft.setTextSize(4);
     tft.setTextColor(RED,BLACK);
      tft.print(a);   
tft.setCursor(160, 100);
  tft.setTextSize(4);
     tft.setTextColor(RED,BLACK);
       tft.print("_");       
     }
if(IndiceClaveM ==2){
tft.setCursor(160, 100);
  tft.setTextSize(4);
     tft.setTextColor(RED,BLACK);
      tft.print(a);   
tft.setCursor(185, 100);
  tft.setTextSize(4);
     tft.setTextColor(RED,BLACK);
       tft.print("_");       
     }

if(IndiceClaveM ==3){
tft.setCursor(185, 100);
  tft.setTextSize(4);
     tft.setTextColor(RED,BLACK);
      tft.print(a);   
tft.setCursor(210, 100);
  tft.setTextSize(4);
     tft.setTextColor(RED,BLACK);
       tft.print("_");       
     }

if(IndiceClaveM ==4){
tft.setCursor(210, 100);
  tft.setTextSize(4);
     tft.setTextColor(RED,BLACK);
      tft.print(a);          
     }
    
     

}
 delay(100);
}
 
 
//////Fin de la funcio printPass//////////////////




     


void printPassGT(char a) {   //////Inicio de la funcio printPass//////////////////

if(ModoB==1)
{
  if(a!='C' || a!= '*'){     
 if(INDICETiempo ==0){
 tft.setCursor(85, 160);
  tft.setTextSize(3);
     tft.setTextColor(CYAN,BLACK); 
      tft.print(a);   
tft.setCursor(105, 160);
  tft.setTextSize(3);
     tft.setTextColor(CYAN,BLACK);
       tft.print("_");       
     }

     if(INDICETiempo ==1){
tft.setCursor(105, 160);
  tft.setTextSize(3);
     tft.setTextColor(CYAN,BLACK);
         tft.print(a);      
     }
}
}
  

if(ModoC==1)
{
  if(a!='C' || a!= '*'){     
 if(INDICETiempo ==0){
tft.setCursor(230, 160);
  tft.setTextSize(3);
     tft.setTextColor(CYAN,BLACK); 
      tft.print(a);   
tft.setCursor(250, 160);
  tft.setTextSize(3);
     tft.setTextColor(CYAN,BLACK);
       tft.print("_");       
     }

     if(INDICETiempo ==1){
tft.setCursor(250, 160);
  tft.setTextSize(3);
     tft.setTextColor(CYAN,BLACK);
         tft.print(a);      
     }
}
}








     
  delay(100);



} 

//////Fin de la funcio printPass//////////////////





void reset1() //funcion de reset
{

  

idcovert=0;
 memset(&ingreid,0,sizeof(ingreid));//////Variables a 0//////////////////
  memset(&printPassGT,0,sizeof(printPassGT));
  memset(&ingid,0,sizeof(ingid));
  
  INDICETiempo = 0;
  ConteoEspacios=0;
  TECLA=NO_KEY;
convert=0;
 ModoBMensaje=0;
 ModoCMensaje=0;
}


//////////////////////////////////////////////////////////////////////////////Registro de Asistencia////////////////

int getFingerprintIDez() { //funcion del sensor
   TECLA = teclado.getKey(); 

if (TECLA != NO_KEY)      //////evaluar if//////////////////   
    switch (TECLA) {       //////menu de opcion//////////////////  
      
      case '*':      //////Inicio de opcion #//////////////////  
   ModoA=0;
    tft.fillScreen(0x0000);
    return 0; 
        break;   //////Fin de opcion #//////////////////  
}//////Fin de opcion #////////////////// 

    
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK) return -1;


  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  
{
  tft.fillScreen(0x0000);
       tft.setRotation(1);
    tft.setCursor(90, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Huella");
      
      tft.setRotation(1);
    tft.setCursor(135, 85);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("No");
       
tft.setCursor(15, 120);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Identificada");
       delay(3000);
 tft.fillScreen(0x0000);
tft.setCursor(40, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Coloque el");
tft.setCursor(40, 60);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Dedo en el");   
       tft.setCursor(90, 110);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Sensor");  
    return -1;
    
}
   
    
  
  // Si hay coincidencias de huella
/*  Serial.print("ID #"); Serial.print(finger.fingerID); 
  Serial.print(" coincidencia del "); Serial.println(finger.confidence);
   */
   
   if(finger.fingerID> 0 ){ // Si hay coincidencias de huella

idR=finger.fingerID;

if(idR >=51 && idR <= 60)
{
  finger.fingerID-= v50;

  /* tft.setCursor(90, 150);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
      // tft.print(segidhuella); */

       //id =segidhuella;
}

if(idR >=61 && idR <= 70)
{
  finger.fingerID-= v50;

   /*tft.setCursor(90, 150);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
      // tft.print(segidhuella);*/

       //id =segidhuella;
}

if(idR >=71 && id <= 80)
{
  finger.fingerID-= v50;

  /* tft.setCursor(90, 150);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       //tft.print(segidhuella);*/

      // id =segidhuella;
}

if(idR >=81 && idR <= 90)
{
  finger.fingerID-= v50;

  /* tft.setCursor(90, 150);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
      // tft.print(segidhuella);*/

       //id =segidhuella;
}

if(idR >=91 && idR <= 100)
{
  finger.fingerID-= v50;

  /* tft.setCursor(90, 150);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
      // tft.print(segidhuella); */

       //id =segidhuella;
}




//Asis[x]=finger.fingerID;

for(int i=0; i<50; i++){//////////////ciclo para aumentar el registro
if(Asis[i] == finger.fingerID) //evaluando casos iguales
{
  i=50;

  d=2;
}
else{
d=1;
  
}
}//////////////ciclo para aumentar el registro


if(d==1)  ////////////////////validacion de primer registro
{
  tft.fillScreen(0x0000);
      tft.setRotation(1);
      
  /*if(myRTC.hours == 8 &&  myRTC.minutes < 16 )
    if(myRTC.hours == 8 &&  myRTC.minutes < 35 )
    {

    }*/
    tft.fillScreen(0x0000);
tft.setCursor(50, 10);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Bienvenido");
tft.setCursor(95, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("NL."); 

       Serial.print("NL. ");
       Serial.print(finger.fingerID);
       Serial.println();

       tft.setCursor(180, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print(finger.fingerID);

tft.setCursor(50, 90);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Asistencia");
tft.setCursor(50, 135);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Registrada"); 




Asis[x++] = finger.fingerID;
    


ModoA=0;

  
}////////////////////validacion de primer registro


if(d==2)////////////////////validacion de segundo registro
{
   tft.fillScreen(0x0000);
      tft.setRotation(1);

tft.setCursor(140, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Ya");
       
      tft.setCursor(70, 80);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Has sido"); 
       
tft.setCursor(45, 120);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Registrado"); 
   ModoA=0;
}////////////////////validacion de registro


delay(3000);
   } 
tft.fillScreen(0x0000);
      tft.setRotation(1);
  return finger.fingerID; 
 
}

//////////////////////////////////////////////////////////////////////////////Registro de Asistencia////////////////












//////////////////////////////////////guardar huella///////////////////////////////////////////////////////
uint8_t getFingerprintEnroll() {

  int p = -1;
  //Serial.print("Esperando una huella valida para enrolar en #"); Serial.println(id);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
     // Serial.println("Imagen tomada");
      break;
    case FINGERPRINT_NOFINGER:
     // Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Error al recibir el paquete");
      break;
    case FINGERPRINT_IMAGEFAIL:
     //  Serial.println("Error al determinar la imagen");
      break;
    default:
     // Serial.print("Error Desconocido: ");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
      //Serial.println("Imagen Convertida");
      break;
    case FINGERPRINT_IMAGEMESS:
      //Serial.println("Image muy confusa");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Paquetes Errados");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      //Serial.println("No es posible detectar los rasgos caracteriticos");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
       //Serial.println("Imagen invalida");
      return p;
    default:
      //Serial.print("Error Desconocido: ");
      return p;
  }

tft.fillScreen(0x0000);
tft.setCursor(80, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Remover");
       tft.setCursor(135, 85);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("El");
tft.setCursor(110, 120);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Dedo");

  
  delay(3000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  //Serial.print("ID "); Serial.println(id);
  p = -1;
  //Serial.println("Por favor vuelva a poner nuevamente el Pulgar");
  
tft.fillScreen(0x0000);
tft.setCursor(40, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Colocar de");
       tft.setCursor(70, 85);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Nuevo el");
tft.setCursor(110, 120);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Dedo");

  
  
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
     // Serial.println("Imagen Tomada");
      break;
    case FINGERPRINT_NOFINGER:
     // Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Error al recibir el paquete");
      break;
    case FINGERPRINT_IMAGEFAIL:
     // Serial.println("Error al determinar la imagen");
      break;
    default:
     // Serial.print("Error Desconocido:");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
     //Serial.println("Imagen Convertida");
      break;
    case FINGERPRINT_IMAGEMESS:
     // Serial.println("Image muy confusa");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
     // Serial.println("Paquetes Errados");
      return p;
    case FINGERPRINT_FEATUREFAIL:
    // Serial.println("No es posible detectar los rasgos caracteriticos");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
     // Serial.println("Imagen invalida");
      return p;
    default:
     //Serial.print("Error Desconocido");
      return p;
  }

  // OK converted!
 // Serial.print("Emparejando huella #");  Serial.println(id);

  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
   // Serial.println("Muestras de Huellas Emparejadas!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
   // Serial.println("Error de comunicacion");
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
   // Serial.println("Muestras de Huellas NO Emparejadas!");
    return p;
  } else {
   // Serial.print("Error Desconocido");
    return p;
  }

 // Serial.print("ID "); Serial.println(id);
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
  //  Serial.println("EXITO - Huella Guardada!");
tft.fillScreen(0x0000);
tft.setCursor(90, 70);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Huella");
tft.setCursor(40, 100);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Almacenada");


delay(3000);
    tft.fillScreen(0x0000);
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
   // Serial.println("Error de comunicacion");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
   // Serial.println("No se puede ubicar en la ubicacion asignada");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
   // Serial.println("Error escribiendo en la flash");
    return p;
  } else {
   // Serial.print("Error Desconocido");
    return p;
  }

  return true;
}
//////////////////////////////////////guardar huella///////////////////////////////////////////////////////




////////////////////////////////////////borrar huella/////////////////
uint8_t deleteFingerprint(uint8_t id) {
  uint8_t p = -1;

  p = finger.deleteModel(id);

  if (p == FINGERPRINT_OK) {
   // Serial.println("Borrado");

  } 
  else if (p == FINGERPRINT_PACKETRECIEVEERR) {
  //  Serial.println("Error de comunicacion");

  } 
  else if (p == FINGERPRINT_BADLOCATION) {
   // Serial.println("No se puede ubicar en la ubicacion asignada");

  } 
  else if (p == FINGERPRINT_FLASHERR) {
   // Serial.println("Error escribiendo en la flash");
  } 
  else {
  //  Serial.print("Error Desconocido"); Serial.println(p, HEX);
 
  }
  tft.fillScreen(0x0000);
   tft.setCursor(35, 50);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Eliminacion");
       tft.setCursor(80, 90);
  tft.setTextSize(4);
     tft.setTextColor(BLUE,BLACK);
       tft.print("Exitosa");
       delay(3000);
 tft.fillScreen(0x0000);
  return p;
}
////////////////////////////////////////borrar huella/////////////////



void mensajeRes1()
{
 tft.fillScreen(0x0000);
 tft.setCursor(50, 70);
  tft.setTextSize(3);
     tft.setTextColor(BLUE);
 tft.println("No se permite");

 tft.setCursor(10, 100);
  tft.setTextSize(3);
     tft.setTextColor(BLUE);
 tft.println("Un Id mayor de 50");

 tft.setCursor(70, 130);
  tft.setTextSize(3);
     tft.setTextColor(BLUE);
 tft.println("O igual a 0");

      
     idcovert=0;
 memset(&ingreid,0,sizeof(ingreid));//////Variables a 0//////////////////
  memset(&printPassGT,0,sizeof(printPassGT));
  memset(&ingid,0,sizeof(ingid));
  
  INDICETiempo = 0;
  ConteoEspacios=0;
  TECLA=NO_KEY;
convert=0;
 ModoBMensaje=0;
 ModoCMensaje=0;


 
}

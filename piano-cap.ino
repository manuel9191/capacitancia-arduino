//SalvadorMarquez
//AntonyTrejo
//ManuelMartinez

#include <CapacitiveSensor.h> //libreria demo Sketch

//Crea una macro
#define c  3830
#define d 3400
#define e 3038
#define f 2864
#define g 2550
#define a 2272
#define b 2028
#define C 1912


#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


// declaramos arreglo para juntar varios todos en un solo pin
int notes1[]={NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5}; // C-Major scale
int notes2[]={NOTE_A4,NOTE_B4,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_A5}; // A-Minor scale
int notes3[]={NOTE_C4,NOTE_DS4,NOTE_F4,NOTE_FS4,NOTE_G4,NOTE_AS4,NOTE_C5,NOTE_DS5}; // C Blues scale
int notes4[]={NOTE_C7, NOTE_CS7,NOTE_D7, NOTE_DS7,NOTE_E7, NOTE_F7,NOTE_FS7, NOTE_G7,NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7,NOTE_C8,NOTE_CS8, NOTE_D8, NOTE_DS8};
int nota[]= {e,f,g};

 
//melodia para el tema de MARIO 
int melodia[] = {660,660,660,510,660,770,380,510,380,320,440,480,450,430,380,660,760,860,700,760,660,520,580,480,510,380,320,440,480,450,430,380,660,760,860,700,760,660,520,580,480,500,760,720,680,620,650,380,430,500,430,500,570,500,760,720,680,620,650,1020,1020,1020,380,500,760,720,680,620,650,380,430,500,430,500,570,585,550,500,380,500,500,500,500,760,720,680,620,650,380,430,500,430,500,570,500,760,720,680,620,650,1020,1020,1020,380,500,760,720,680,620,650,380,430,500,430,500,570,585,550,500,380,500,500,500,500,500,500,500,580,660,500,430,380,500,500,500,500,580,660,870,760,500,500,500,500,580,660,500,430,380,660,660,660,510,660,770,380};

 
//duracion de cada nota
int duracaodasnotas[] = {100,100,100,100,100,100,100,100,100,100,100,80,100,100,100,80,50,100,80,50,80,80,80,80,100,100,100,100,80,100,100,100,80,50,100,80,50,80,80,80,80,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,150,200,80,80,80,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,150,200,80,80,80,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,100,100,100,60,80,60,80,80,80,80,80,80,60,80,60,80,80,80,80,80,60,80,60,80,80,80,80,80,80,100,100,100,100,100,100,100};
  
//el sensor se conecta entre el pin 2 y 3 por defecto
//CapacitiveSensor sensor=CapacitiveSensor(4,2);

CapacitiveSensor   cs_3_2 = CapacitiveSensor(2,3); //2m de resistencia para la entrada y 10m para la salida
CapacitiveSensor   cs_4_2 = CapacitiveSensor(2,4); //pin 4, es el pin del resistor
CapacitiveSensor   cs_5_2 = CapacitiveSensor(2,5); //pin 5, es el pin del resistor
CapacitiveSensor   cs_6_2 = CapacitiveSensor(2,6); //pin 6, es el pin del reistor
CapacitiveSensor   cs_7_2 = CapacitiveSensor(2,7); // pin 7, es el pin del resitor


void setup(){
   cs_3_2.set_CS_AutocaL_Millis(0xFFFFFFFF); //desactivamos la calibracion automatica
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);  
   cs_5_2.set_CS_AutocaL_Millis(0xFFFFFFFF); 
   cs_6_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_7_2.set_CS_AutocaL_Millis(0xFFFFFFFF);  

//for para tocar las 156 notas del 0-156 ++incrementa
for (int nota = 0; nota < 156; nota++) {
 
 int duracaodanota = duracaodasnotas[nota];
 
tone(13, melodia[nota],duracaodanota); //enviamos la melodia a la bocina
//pausa despues de cada nota

int pausadepoisdasnotas[] ={150,300,300,100,300,550,575,450,400,500,300,330,150,300,200,200,150,300,150,350,300,150,150,500,450,400,500,300,330,150,300,200,200,150,300,150,350,300,150,150,500,300,100,150,150,300,300,150,150,300,150,100,220,300,100,150,150,300,300,300,150,300,300,300,100,150,150,300,300,150,150,300,150,100,420,450,420,360,300,300,150,300,300,100,150,150,300,300,150,150,300,150,100,220,300,100,150,150,300,300,300,150,300,300,300,100,150,150,300,300,150,150,300,150,100,420,450,420,360,300,300,150,300,150,300,350,150,350,150,300,150,600,150,300,350,150,150,550,325,600,150,300,350,150,350,150,300,150,600,150,300,300,100,300,550,575};
delay(pausadepoisdasnotas[nota]);}
noTone (13);

  Serial.begin(9600);
  pinMode(13,OUTPUT); //pin 13, salida a la bocina
}

void loop(){
  
  long total1=cs_3_2.capacitiveSensor(4); //sensibilidad de cada sensor
  long total2=cs_4_2.capacitiveSensor(4);
  long total3=cs_5_2.capacitiveSensor(4);
  long total4=cs_6_2.capacitiveSensor(4);
  long total5=cs_7_2.capacitiveSensor(3);
  
  Serial.print(total1); //imprimimos los valores de salida de cada sensor
  Serial.print("      "); //3 espacios entre cada columna de valores
  Serial.print('\r');    //envia los valores a una nueva columna
  Serial.print(total2);
  Serial.print("      ");
  Serial.print('\r');
  Serial.print(total3);
  Serial.print("      ");
  Serial.print('\r');
  Serial.print(total4);
  Serial.print("      ");
  Serial.print('\r'); 
  Serial.println(total5);
  Serial.print("      ");
  Serial.print('\r'); 
  
  
  
  if(total1>15){
  tone(13,notes1[13]); //reproduce la nota correspondiente a la tecla presionada
  delay(300); //duracion de la nota reproducida
  noTone(13); // detine la nota

  }

 
  if (total2>15){
    tone(13,nota[13]); // Plays the note corresponding to the key pressed
    delay(300);
    noTone(13);
  }


 if(total3>15){
  tone(13,a);
  delay(300);
  noTone(13);

 }
  
  
  if (total4>15){
  
  tone(13,b);
  delay(300);
  noTone(13);
  }

  if (total5>15){
  
  tone(13,g);
  delay(300);
  noTone(13);
  }
}// cierra el void loop()

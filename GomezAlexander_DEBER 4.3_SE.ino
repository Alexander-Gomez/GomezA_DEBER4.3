/*
* NOMBRE: GOMEZ ALEXANDER
* MATERIA: SISTEMAS EMBEBIDOS
* DEBER 4.3
*/
#include <MsTimer2.h>        //libreria Timer2
#include <LiquidCrystal.h>   //libreria LCD
LiquidCrystal lcd (13,12,11,10,9,8); //Objeto para la libreria de LCD
int segundos=0;               //variable de segundos
int minutos=0;                //variable de minutos
int horas=0;                  //variable de horas

void setup() {
  lcd.begin(20,4);     //inicia la LCD
  MsTimer2::set(100,reloj); //configura el timer 2 a 1 segundo
  MsTimer2::start();
}
void loop() {
}
void reloj(){
  if(segundos<60){          //condicion de segundos
    segundos++;             //incremento variable
  }
  else{
    segundos=0;
    if(minutos<60){         //condicion de minutos
      minutos++;            //incrementar la variable
    }
    else{
      minutos=0;            
      if(horas<24){        //condicion de horas
        horas++;           //incrementar variable
      }
      else{
        horas=0;           
      }
    }
  }
  lcd.clear(); //borrar el anterior mensaje
  lcd.setCursor(5,0);  //ubicacion de LCD
  lcd.print("BIENVENIDO");
  lcd.setCursor(2,1);  //ubicacion de LCD
  lcd.print("GOMEZ ALEXANDER");
  lcd.setCursor(7,2);  //ubicacion de LCD
  lcd.print(String(horas)+String(":")+String(minutos)+String(":")+String(segundos));
  lcd.setCursor(5,3);  //ubicacion de LCD
  lcd.print(String("Valor:100 "));
}
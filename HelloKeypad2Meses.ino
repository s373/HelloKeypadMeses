
/*
AS for Mauricio Martins, projecto audio meses, etc, etc



*/


boolean DEBUG = true;//false;


/* @file HelloKeypad.pde
 || @version 1.0
 || @author Alexander Brevig
 || @contact alexanderbrevig@gmail.com
 ||
 || @description
 || | Demonstrates the simplest use of the matrix Keypad library.
 || #
 */
#include <Keypad.h>

const byte ROWS = 6; //four rows
const byte COLS = 7; //three columns
char keys[ROWS][COLS] = {
  {
    '1','2','3','4','5','6','7'    }
  ,
  {
    '8','9','a','b','c','d','e'    }
  ,
  {
    'f','g','h','i','j','k','l'    }
  ,
  {
    'm','n','o','p','q','r','s'    }
  ,
  {
    't','u','v','x','y','z','A'    }
  ,
  {
    'B','C','D','E','F','G','H'    }
};

char * keysAudio[ROWS][COLS] = {
  {
    "A001","A002","A003","A004","A005","A006","A007"    }
  ,
  {
    "A008","A009","A010","A011","A012","A013","A014"    }
  ,
  {
    "A015","A016","A017","i","j","k","l"    }
  ,
  {
    "m","n","o","p","q","r","s"    }
  ,
  {
    "t","u","v","x","y","z","A"    }
  ,
  {
    "B","C","D","E","F","G","H"    }
};


byte colPins[COLS] = {
  15,14,12,11,10,9,8}; //connect to the column pinouts of the keypad
byte rowPins[ROWS] = { 
  7,6,5, 4, 3, 2}; //connect to the row pinouts of the keypad

// assim funciona
//byte colPins[COLS] = {15,14,12,11,10,9,8}; //connect to the column pinouts of the keypad
//byte rowPins[ROWS] = { 7,6,5, 4, 3, 2}; //connect to the row pinouts of the keypad



Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
}

void loop(){
  char key = keypad.getKey();

  if (key){
    if(DEBUG)
      Serial.print(key);
    
    int row  = -1;
    int col = -1;
    for(int i=0; i<ROWS; i++) {
      for(int j=0; j<COLS; j++) {
          
        if( key == keys[i][j] ){
           row = i;
           col = j; 
           break;
        }
        
      }
    }
    
  if(DEBUG) {
    Serial.print(" __ = __ ");
  }

    Serial.println("0xEF"); // send stop mp3 player
    delay(50);
    Serial.print(keysAudio[row][col]); // ´e isto q queres imprimir a partir dos botoes
    Serial.println();
    
  }



}



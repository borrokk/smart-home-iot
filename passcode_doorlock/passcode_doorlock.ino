/*

*/
#include <Keypad.h> #include <Servo.h>
#define codeLength 4 Servo myservo;

char Code[codeLength];
char PassW[codeLength]="123"; byte keycount=0;
const byte ROWS = 3; const byte COLS = 3;
char hexaKeys[ROWS][COLS] = { {'1', '2', '3'},
{'4', '5', '6'},
{'7', '8', '9'}
};
byte rowPins[ROWS] = {9, 8, 7};
byte colPins[COLS] = {5, 4, 3};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
void setup(){ Serial.begin(9600); myservo.attach(10);
}
void loop(){
char customKey = customKeypad.getKey(); if(customKey){
//Serial.println(customKey); Code[keycount]=customKey; Serial.print(Code[keycount]); keycount++;
} if(keycount==codeLength-1){
Serial.println(" ");
if(!strcmp(Code,PassW)){
Serial.println("Correct password - Access Granted"); myservo.write(80); //unlock
delay(4000);
}
else{
Serial.println("Incorrect password - Access Denied"); myservo.write(10); //lock
delay(1000);


 
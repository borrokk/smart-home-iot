/*

*/
#include <IRremote.h>
int RECV_PIN = 3; //This Pin should be PWM
IRrecv irrecv(RECV_PIN); decode_results results;
void setup() {
Serial.begin(9600); irrecv.enableIRIn(); // Start the receiver
pinMode(5, OUTPUT); pinMode(6, OUTPUT); pinMode(7, OUTPUT); pinMode(8,OUTPUT);
}
void loop() {
if (irrecv.decode(&results)) { switch(results.value)
{
case 16582903: Serial.println("1"); // Button 1
digitalWrite(5,HIGH); break;
case 16615543: Serial.println("2"); // Button 2 digitalWrite(5,LOW);
break;
case 16599223: Serial.println("3"); // Button 3 digitalWrite(6,HIGH);
break;
case 16591063: Serial.println("4"); // Button 4 digitalWrite(6,LOW);
break;
case 16623703: Serial.println("5"); // Button 5 digitalWrite(7,HIGH);
break;
case 16607383: Serial.println("6"); // Button 6 digitalWrite(7,LOW);
break;
default: Serial.println(results.value); }
irrecv.resume(); // Receive the next value }

}

#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int redPin = 5;
const int greenPin = 11;
const int yellowPin = 10;

void setup(){
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
}

void loop(){
    if (irrecv.decode(&results)){

        switch(results.value){
          case 0xFD08F7: //Keypad button "1"
          digitalWrite(redPin, HIGH);
          delay(2000);
          digitalWrite(redPin, LOW);
          }

        switch(results.value){
          case 0xFD8877: //Keypad button "2"
          digitalWrite(greenPin, HIGH);
          delay(2000);
          digitalWrite(greenPin, LOW);
          }
        switch(results.value){
          case 0xFD48B7: //Keypad button "3"
          digitalWrite(yellowPin, HIGH);
          delay(2000);
          digitalWrite(yellowPin, LOW);
          }

        irrecv.resume(); 
    }
}

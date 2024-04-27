/* NRF24L01 Remote Control
 * Install RF24 Library
 * Code by Superb Tech
 * www.youtube.com/superbtech
 */

#include <SPI.h>          // Include SPI Library
#include <nRF24L01.h>     // Include RF24 Library
#include <RF24.h>         // Include RF24 Library
#define pin1 3            // Define Output Pins
#define pin2 5
#define pin3 6
#define pin4 9
RF24 radio(8, 7);          // CE, CSN Pins
const byte address[6] = "00001";  // Address for communication
char joyData[32] = "";    // Data to be sent over radio
int xAxis, yAxis;         // Joystick data
int pwmSignal1 = 0;
int pwmSignal2 = 0;
int pwmSignal3 = 0;
int pwmSignal4 = 0;


void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
  
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  
  
}

void loop() {
  
  
  if (radio.available()) {
    radio.read(&joyData, sizeof(joyData));
    xAxis = atoi(&joyData[0]);
    delay(10);
    radio.read(&joyData, sizeof(joyData));
    yAxis = atoi(&joyData[0]);
    delay(10);
    Serial.print ("xaxis: ");
    Serial.print (xAxis);
    Serial.print ("yaxis: ");
    Serial.println (yAxis);
  }
  else {
    digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
    digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
  }

 
  
  if (xAxis > 700) {        // condition when joystick is UP
    pwmSignal1 = map(xAxis, 700, 1023, 0, 255);
    digitalWrite(pin1, HIGH);
    
     
  }
  else if (xAxis < 500) {   // condition when joystick is DOWN
    pwmSignal2 = map(xAxis, 500, 0, 0, 255);
    digitalWrite(pin2, HIGH);
  }
  else {
    pwmSignal1 = 0;
    pwmSignal2 = 0;
    digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  
  }
  if (yAxis > 700) {         // condition when joystick is RIGHT
    pwmSignal3 = map(yAxis, 700, 1023, 0, 255);
    digitalWrite(pin3, HIGH);
    
  }
  else if (yAxis < 500) {    // condition when joystick is LEFT
    pwmSignal4 = map(yAxis, 500, 0, 0, 255);
    digitalWrite(pin4, HIGH);
  }
  else {   // set signal to 0 to avoid noise
    pwmSignal3 = 0;
    pwmSignal4 = 0;
    
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
  }

  
   
}

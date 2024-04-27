/* NRF24L01 Remote Control
 * Install RF24 Library
 * Code by Superb Tech
 * www.youtube.com/superbtech
 */

#include <SPI.h>        // Include SPI Library
#include <nRF24L01.h>   // Include RF24 Library
#include <RF24.h>       // Include RF24 Library

RF24 radio(9,8); // CE, CSN Pins
const byte address[6] = "00001";   // Address for communication
char joyData[32] = "";    // Data to be sent over radio

String xAxis, yAxis;

void setup() {
  radio.begin();   // Initiate Radio
  radio.openWritingPipe(address); // Set address
  radio.setPALevel(RF24_PA_MIN);  // Set Power Amplification Level
  radio.stopListening();
}

void loop() {


  
  xAxis = analogRead(A0);  // Read Joystick Data
  yAxis = analogRead(A1);
  

  xAxis.toCharArray(joyData, 6);
  radio.write(&joyData, sizeof(joyData)); // send data over radio
 

  yAxis.toCharArray(joyData, 6);
  radio.write(&joyData, sizeof(joyData));
  delay(20);
  
}

/* 
Use L298N to drive 2 DC motors and control the motors speed and direction with potentiometer

You can attach the control pins to any digital or analog pins. 
But, for motor speed control - the motor "Enable" pins 
must be attached to a PWM enabled pin. 
In this sketch  the motor "Enable" pins connect to pin ~10 and pin ~5, 
both of which are PWM pins.

The circuit:
  - Motor A Enable connected to pin ~10
  - Motor B Enable connected to pin ~5
  - Motor A Input connected to pin ~9 and 8
  - Motor B Input connected to pin 7 and ~6
  - Potentiometer 1 connected to pin A0
  - Potentiometer 1 connected to pin A1

modified 25 November 2019
  by ShEF
This code is distributed under the GNU Public Licence
*/

// Motor Connections
// Change this if you wish to use another diagram
// We will use #define statement to assign pins with same names as on L298N
#define EnA 10  // Half bridge for Motor 1 Enable 
//#define EnB 5   // Half bridge for Motor 2 Enable 
#define In1 9   // Control pin for Motor 1
#define In2 8   // Control pin for Motor 1
/*#define In3 7   // Control pin for Motor 2
#define In4 6 */  // Control pin for Motor 2
#define Pot1 A0   // Pot on Analog Pin A0
//#define Pot2 A1   // Pot on Analog Pin A1

// Store readings from Potentiometers (0-1024)
int MotorSpeed1 = 0;     
int MotorSpeed2 = 0;     
// Store desiered speed values (0-255)
int M1Speed = 0;
int M2Speed = 0;


// the setup routine runs once when you press reset:
void setup()
{
  // All motor control pins are outputs
  pinMode(EnA, OUTPUT);
  //pinMode(EnB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  //pinMode(In3, OUTPUT);
  //pinMode(In4, OUTPUT);
}

//Stops motor
void brake ()
{
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);  
  //digitalWrite(In3, LOW);
  //digitalWrite(In4, LOW);
}

// the loop routine runs over and over again forever:
void loop()
{
// Reading potentiometer values
  MotorSpeed1 = analogRead(Pot1); 
 // MotorSpeed2 = analogRead(Pot2);
  //Motor 1 go forward 
  if (MotorSpeed1 > 600)
  {
    M1Speed = map(MotorSpeed1, 600, 1023, 0, 50);  //Mapping the values to 0-255 to move the motor
    digitalWrite(EnA, LOW);
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);
    digitalWrite(EnA, M1Speed); // Defines motor speed
  }
 
  //Motor 1 go backward
  else if (MotorSpeed1 < 400) 
  {
    M1Speed = map(MotorSpeed1, 400, 0, 0, 50);
    digitalWrite(EnA, LOW);
    digitalWrite(In1, LOW);
    digitalWrite(In2, HIGH);
    digitalWrite(EnA, M1Speed);
  }
 
  //Motor 2 go forward Motor
  /*if (MotorSpeed2 > 500)
  {
    M2Speed = map(MotorSpeed2, 500, 1023, 0, 255);  //Mapping the values to 0-255 to move the motor
    digitalWrite(EnB, LOW);
    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
    digitalWrite(EnB, M2Speed);
  }
 */
  //Motor 2 go backward
 
 /*else if (MotorSpeed2 < 450) 
  {
    M2Speed = map(MotorSpeed2, 450, 0, 0, 255);
    digitalWrite(EnB, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In4, HIGH);
    digitalWrite(EnB, M2Speed);
  }*/
 
  //Brake (Potentiometer shaft in the center position)
  else
  {
    brake();
  }
}

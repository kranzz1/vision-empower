//Vision Empower Glove Code - Version 1.0.1
//Code written by Vision Empower Team, and edited by Zachary Kranz

// This is an edited version of the initial Vision Empower Code to simplify the program to one output
// and implement PWM modulation for the vibration motor.

//Written and compiled for Arduino Nano
//			 -------------
//			=|16       15|=
//			=|17       14|=
//	Sensor Input	=|18       13|=
//			=|19       12|=
//			=|20       11|=
//			=|21       10|=
//			=|22   N    9|= Audiable Buzzer
//			=|23   A    8|=
//			=|24   N    7|=
//			=|2    O    6|= Motor Transistor 4 - Not Used
//			=|26        5|= Motor Transistor 3 - Not Used
//			=|27        4|= Motor Transistor 2 - Not Used
//			=|28        3|= Motor Transistor 1
//			=|29        2|= Input Button
//			=|30        1|=
//			 -------------

int motorPin1 = 3; //motor transistor is connected to pin 3
//int motorPin2 = 4; //motor transistor is connected to pin 4
//int motorPin3 = 5; //motor transistor is connected to pin 5
//int motorPin4 = 6; //motor transistor is connected to pin 6
int read1 = 0;
const int buzzer = 9; //buzzer to arduino pin 9
const int buttonPin = 7; //Button to arduino pin 2
int buttonState = 0;
int flag = 0;
int start_new= 0;
int dutyCycle = 0; //PWM Duty Cycle

int iteration = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(A4, INPUT);
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(buttonPin, INPUT);
  pinMode(motorPin1, OUTPUT);
  //pinMode(motorPin2, OUTPUT);
  //pinMode(motorPin3, OUTPUT);
  //pinMode(motorPin4, OUTPUT);
}

void Start_Motor()
{
// Read the value from the photosensor, determine duty cycle, and 
  delay(10);
  Serial.println(dutyCycle);
  analogWrite(motorPin1, dutyCycle);
}

void loop()
{

  
  buttonState = digitalRead(buttonPin); // button input
  if (buttonState == HIGH)
  {
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(1000);
    noTone(buzzer);
   start_new= start_new+1;
  }
  else 
  {
    start_new=start_new;
  } 
  noTone(buzzer);
  if(start_new==1)
  {
    dutyCycle = analogRead(A4);
    Start_Motor();}
    }

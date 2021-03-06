//Vision Empower Glove Code - Version 1.5.2
//Code written by Vision Empower Team, and edited by Zachary Kranz

// This is an edited version of the initial Vision Empower Code to simplify the program to one output
// and implement PWM modulation for the vibration motor.

//TO-DO: 
//	Clean up code and comment
//	Resolve orphaned variables - DONE 
//	Implement and test standby mode - DONE

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
//			=|2    O    6|= Motor Transistor 1
//			=|26        5|= Motor Transistor 3 - Not Used
//			=|27        4|= Motor Transistor 2 - Not Used
//			=|28        3|= Motor Transistor 4 - Not Used
//			=|29        2|= Input Button
//			=|30        1|=
//			 -------------
int motorPin1 = 3; //motor transistor is connected to pin 6
//int motorPin2 = 4; //motor transistor is connected to pin 4
//int motorPin3 = 5; //motor transistor is connected to pin 5
//int motorPin4 = 6; //motor transistor is connected to pin 6
const int buzzer = 9; 	//buzzer to arduino pin 9
const int buttonPin = 7; //Button to arduino pin 2
int buttonState = 0; 	//Variable for button input
int dutyCycle = 0; 	//PWM Duty Cycle
int cycle = 1;		//Variable to store cycle running status

//int iteration = 1;	//orphaned variable
//int flag = 0;		//unknown variable, potentially not used?
//int start_new= 0;	//orphaned variable
//int read1 = 0;	//orphaned variable


void setup()
{
  Serial.begin(9600); //commence yelling into the void
  pinMode(A4, INPUT); //input from photosensor 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(buttonPin, INPUT);
  pinMode(motorPin1, OUTPUT);
  //pinMode(motorPin2, OUTPUT);
  //pinMode(motorPin3, OUTPUT);
  //pinMode(motorPin4, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void Start_Motor()
{
// Read the value from the photosensor, determine duty cycle, and use analogWrite to implement PWM  
  delay(10);
  if(dutyCycle < 200)
  {
      Serial.println(0); //send duty cycle to serial out pin
      analogWrite(motorPin1, 0); //use analogWrite function to implement PWM
      analogWrite(LED_BUILTIN, 0);
  }   
  else if(200 < dutyCycle && dutyCycle < 500)
  {
      Serial.println(350);
      analogWrite(motorPin1, 350);
      analogWrite(LED_BUILTIN, 350);
  }
   else if(500 < dutyCycle && dutyCycle < 800)
   {
        Serial.println(750);
      analogWrite(motorPin1, 750);
      analogWrite(LED_BUILTIN, 750);
   }
   else if(dutyCycle > 800)
   {
      Serial.println(1024);
      analogWrite(motorPin1, 1024);
      analogWrite(LED_BUILTIN, 1024);
  }
  
} //end of Start_Motor

void loop()
{
  buttonState = digitalRead(buttonPin); // button input
  if (buttonState == HIGH && cycle == 0)
  {
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(1000);	//wait a second in order for finger to move off button
    noTone(buzzer);	// stop sending 1khz sound
    cycle = 1; 		//Set cycle variable to 1 to
	delay(1000);	//wait a second in order for finger to move off button

  } //end of if
  else if (buttonState == HIGH && cycle == 1)
  {
    cycle = 0;
	delay(1000); 	//wait a second in order for finger to move off button
  } // end of elif
  else
{
	cycle = cycle; 	//keep on keeping on
}//end of else
  noTone(buzzer);	//in case the buzzer is still making a noise, stop making a noise
  if(cycle==1)
  {
    dutyCycle = analogRead(A4);	//pull sigmal from photosensor
    Start_Motor();
}//end of if
    } //end of loop

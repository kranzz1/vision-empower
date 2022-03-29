//Vision Empower Glove Code - Version 1.0.0
//Code written by Vision Empower Team, and edited by Zachary Kranz
//Written and compiled for Arduino Nano
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

int iteration = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(A4, INPUT);
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(buttonPin, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void Start_Motor()
{
  delay(10);
  Serial.println(read1);
  if (read1 >= 750 && read1 <= 900) {

    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
  }
  else if (read1 >= 500 && read1 <= 749) {

    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
  }
  else if (read1 >= 350 && read1 <= 499) {
    
    digitalWrite(motorPin1, LOW); 
				a Kucha f machines in each department, or $N_{routes}=N_{d1}*N{Î
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
  }
  else if (read1 >= 150 && read1 <= 349) 
  {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  }
  else 
  {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
  }
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
    read1 = analogRead(A4);
    Start_Motor();}
    }

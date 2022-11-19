                                                  /*** Follower Line Robot ***/
#define WhiteBlackBorder 343
#define PUMP 13 // connect DO pin of sensor to this pin
#define LED 11 // connect led + buzzer to pin 11

int EN_A = 3;      //Enable (PWM) pin for first motor  
int IN1 = 5;        //control pin for first motor(Left motor)
int IN2 = 6;        //control pin for first motor (Left motor)
int IN3 = 7;        //control pin for second motor (Right motor)
int IN4 = 8;        //control pin for second motor (Right motor)
int EN_B = 9;      //Enable (PWM) pin for second motor  


void setup() {
  // Define All the setupes 
  pinMode(PUMP, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(EN_A, OUTPUT);
  pinMode(EN_B, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600); 
  
  // -------------------------------------------------------------------

  // Disable both motors
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  delay(2000);

  // Set the speed of both motors to 200 (But motors are disables at the moment !)
  analogWrite(EN_A, 120);  
  analogWrite(EN_B, 120);
  
}


void loop() {
       // enter the loop when there no fire 
       if(analogRead(A0)>80)// turn left
    {
    //Serial.println(analogRead(A0));
    digitalWrite(PUMP,LOW); // set the PUMP ON
    digitalWrite(LED,LOW);  // set the LED+BUZZER ON
    if(analogRead(A1)>WhiteBlackBorder&&analogRead(A1)<WhiteBlackBorder+150) // turn left
    {
      // Set motor A (Left) Disable
      digitalWrite(IN1, LOW);  
      digitalWrite(IN2, LOW);
      // Set motor B (Right) forward
      digitalWrite(IN3, HIGH); 
      digitalWrite(IN4, LOW);
    }
     if(analogRead(A1)<WhiteBlackBorder&&analogRead(A1)>280) // turn right
    {
      digitalWrite(IN1, HIGH);  // Set motor A (Left) forward
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW); // Set motor B (Right) Disable
      digitalWrite(IN4, LOW);
    }
    if(analogRead(A1)>WhiteBlackBorder+150)// turn left on spot
    {
      // Set motor A (Left) reverse
      digitalWrite(IN1, LOW); 
      digitalWrite(IN2, HIGH);
      // Set motor B (Right) forward
      digitalWrite(IN3, HIGH); 
      digitalWrite(IN4, LOW);
    }
    if(analogRead(A1)<280)// turn right on spot
    {
      // Set motor A (Left) forward
      digitalWrite(IN1, HIGH);  
      digitalWrite(IN2, LOW);
      // Set motor B (Right) Disable
      digitalWrite(IN3, LOW); 
      digitalWrite(IN4, HIGH);
    }
  }
  // enter the loop if there are a fire and stop the robot from moving 
  else{
      digitalWrite(PUMP,HIGH);  // set the PUMP ON
      digitalWrite(LED,HIGH); // set the LED+BUZZER ON
     
      // Set motor A (Left) forward
      digitalWrite(IN2, LOW);
      digitalWrite(IN1, LOW); 
      // Set motor B (Right) Disable
      digitalWrite(IN3, LOW); 
      digitalWrite(IN4, LOW);
      delay(2000);
  }
} 

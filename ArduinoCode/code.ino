#include<Servo.h> //Servo Library

//Servo Motor setups
Servo servo;
const int servoPin = 5

//Right Motor Pins
const int in1 = 8;
const int in2 = 9;

//Left Motor Pins
const int in3 = 10;
const int in4 = 11;

float rvel = 390.; //Angular velocity of the Car while rotating

//Sonar Sensor Pins
const int trig = 3;
const int echo = 4;
const int vcc = 2

float dis; //to store Distance from any object
float stdis = 30; //Minimum Distance to Stop the robot
float rdis; //Object Distance on the Right
float ldis; //Object Distance on the Left

void setup() {
  //Setting up Servo
  servo.attach(servoPin);
  servo.write(90);
  
  //Setting up Motor pins
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  //VCC pin of the Sensor
  pinMode(vcc, OUTPUT);
  digitalWrite(vcc, HIGH);
  
  //Setting up Sonar Sensor pins
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  //Moving the robot forward unless the nearest object comes closer than the minimum distance
  forward();
  dis = distance();
  while(dis > stdis){
    dis = distance();
  }
  stp();
  
  //Measuring the distance of the nearest object on right
  servo.write(0);
  delay(500);
  rdis = distance();
  delay(1000);
  
  //Measuring the distance of the nearest object on left
  servo.write(180);
  delay(500);
  ldis = distance();
  delay(1000);
  
  servo.write(90);
  delay(500);
  
  //Taking decision on which direction to turn
  if (ldis<50 && rdis<50){
      reverse();
    }else{
      if (ldis>rdis){
        left();
      }else{
        right();
    }
  }
   delay(500);
}

void forward(){ //For Moving Forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void right(){ //For Turning Right
  float t;
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  t = 90./rvel*1000;
  delay(t);
  stp();
}

void left(){ //For Turning Left
  float t;
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  t = 90./rvel*1000;
  delay(t);
  stp();
}

void reverse(){ //For Turning Backward
  float t;
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  t = 180./rvel*1000;
  delay(t);
  stp();
}

void stp(){ //For Stoping
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

float distance(){ //For measuring Distance using the Sonar Sensor
  float dis;
  float tm;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  tm = pulseIn(echo, HIGH);
  dis = tm*0.034/2.;
  return dis;
}

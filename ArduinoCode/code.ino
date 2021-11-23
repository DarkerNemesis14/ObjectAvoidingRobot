#include<Servo.h>

Servo servo;
const int in1 = 11; //Right Motor
const int in2 = 10;
const int in3 = 8; //Left MOtor
const int in4 = 9;
float rvel = 390.; //Angular velocity of the Car while rotating
const int trig = 3; //Sensor
const int echo = 4;
float dis; //Distance
float stdis = 30; //Minimum Distance to Stop
float rdis; //Object Distance on the Right
float ldis; //Object Distance on the Left

void setup() {
  servo.attach(5);
  servo.write(90);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(2, OUTPUT); //VCC pin of the Sensor
  digitalWrite(2, HIGH);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  forward();
  dis = distance();
  while(dis > stdis){
    dis = distance();
  }
  stp();
  servo.write(0);
  delay(500);
  rdis = distance();
  delay(1000);
  servo.write(180);
  delay(500);
  ldis = distance();
  delay(1000);
  servo.write(90);
  delay(500);
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

void forward(){ //Move Forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void right(){ //Turn Right
  float t;
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  t = 90./rvel*1000;
  delay(t);
  stp();
}

void left(){ //Turn Left
  float t;
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  t = 90./rvel*1000;
  delay(t);
  stp();
}

void reverse(){ //Turn Backward
  float t;
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  t = 180./rvel*1000;
  delay(t);
  stp();
}

void stp(){ //Stop
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

float distance(){ //Distance Measurement using the Sensor
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

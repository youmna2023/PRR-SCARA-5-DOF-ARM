#include <ros.h>
#include <std_msgs/Int8.h>

#include <Servo.h>

#define DC11 11
#define DC12 10
#define STEPPER2_STEP_PIN 400
#define STEPPER2_DIR_PIN 500

#define SERVO_PIN_1 3
#define SERVO_PIN_2 5
#define SERVO_PIN_3 6

Servo servo1;
Servo servo2;
Servo servo3;

int pos1 = 0;
int pos2 = 0;

int motion = 0;

ros::NodeHandle nh;

void moveServo1Left();
void moveServo1Right();
void moveServo2Left();
void moveServo2Right();

void androidCallback(const std_msgs::Int8& msg)
{
  nh.loginfo("Callback");
  motion = msg.data;
}

ros::Subscriber<std_msgs::Int8> android_sub("/android_topic", &androidCallback);

void setup() {
  nh.getHardware()->setBaud(9600);
  nh.initNode();
  nh.subscribe(android_sub);
  
  pinMode(DC11,OUTPUT); 
  pinMode(DC12,OUTPUT);
  pinMode(STEPPER2_STEP_PIN,OUTPUT); 
  pinMode(STEPPER2_DIR_PIN,OUTPUT);
  servo1.attach(SERVO_PIN_1);
  servo2.attach(SERVO_PIN_2);
  servo3.attach(SERVO_PIN_3);
}

void loop() {
  //nh.loginfo(motion);
  if(motion==3)
  {
    digitalWrite(STEPPER2_DIR_PIN,0);
    digitalWrite(STEPPER2_STEP_PIN,1); 
    delayMicroseconds(1000); 
    digitalWrite(STEPPER2_STEP_PIN,LOW); 
    delayMicroseconds(1000);
  }
  else if(motion==4)
  {
    digitalWrite(STEPPER2_DIR_PIN,1);
    digitalWrite(STEPPER2_STEP_PIN,1); 
    delayMicroseconds(1000); 
    digitalWrite(STEPPER2_STEP_PIN,LOW); 
    delayMicroseconds(1000);
  }
  else
  {
    digitalWrite(STEPPER2_DIR_PIN,0);
    digitalWrite(STEPPER2_STEP_PIN,0); 
    delayMicroseconds(1000); 
    digitalWrite(STEPPER2_STEP_PIN,LOW); 
    delayMicroseconds(1000);
    if(motion==1)
    {
      digitalWrite(DC11, HIGH);
      digitalWrite(DC12, LOW);
    }
    else if(motion==2)
    {
      digitalWrite(DC11, LOW);
      digitalWrite(DC12, HIGH);
    }
    else if(motion==5)
    {
      moveServo1Right();
    }
    else if(motion==6)
    {
      moveServo1Left();
    }
    else if(motion==7)
    {
      moveServo2Right();
    }
    else if(motion==8)
    {
      moveServo2Left();
    }
    else if(motion==9)
    {
      servo3.write(0);
    }
    else if(motion==10){
      servo3.write(90);
    }
    else
    {
      digitalWrite(DC11, LOW);
      digitalWrite(DC12, LOW);
      nh.loginfo("Waiting");
    }
  }
  nh.spinOnce();
  delay(10);
}

void moveServo1Left() {
  pos1 -= 1;
  if (pos1 < 0) {
    pos1 = 0;
  }
  char logMsg[50];
  sprintf(logMsg, "The value is: %d", pos1);
  nh.loginfo(logMsg);
  servo1.write(pos1);
}

void moveServo1Right() {
  pos1 += 1;
  if (pos1 > 180) {
    pos1 = 180;
  }
  char logMsg[50];
  sprintf(logMsg, "The value is: %d", pos1);
  nh.loginfo(logMsg);
  servo1.write(pos1);
}

void moveServo2Left() {
  pos2 -= 1;
  if (pos2 < 0) {
    pos2 = 0;
  }
  char logMsg[50];
  sprintf(logMsg, "The value is: %d", pos2);
  nh.loginfo(logMsg);
  servo2.write(pos2);
}

void moveServo2Right() {
  pos2 += 1;
  if (pos2 > 180) {
    pos2 = 180;
  }
  char logMsg[50];
  sprintf(logMsg, "The value is: %d", pos2);
  nh.loginfo(logMsg);
  servo2.write(pos2);
}

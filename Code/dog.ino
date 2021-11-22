// 4 LEGGED ROBOT (DOG)

#include<Servo.h>           //For servos
#include <NewPing.h>        //For ultrasonic sensor

#define trigPin 11             //Sensor initalisation
#define echoPin 12
NewPing sonar(trigPin, echoPin);
float duration, distance;

Servo a_up;                 //Motor initalisation 
Servo b_up;
Servo c_up;
Servo d_up;
Servo a_down;
Servo b_down;
Servo c_down;
Servo d_down;

// BASE POSITIONS OF LEGS                     
int a_u = 80;
int b_u = 100;
int c_u = 90;
int d_u = 90;
int a_d = 100;
int b_d = 110;
int c_d = 35;
int d_d = 140;

void setup() {
  a_up.attach(2);
  b_up.attach(4);
  c_up.attach(6);
  d_up.attach(8);
  a_down.attach(3);
  b_down.attach(5);
  c_down.attach(7);
  d_down.attach(10);
}

//THE DOG STANDS STILL WHEN THIS FUNCTION IS RUNNING
int stand() {
  int a_u = 60;
  int b_u = 100;
  int c_u = 90;
  int d_u = 90;
  int a_d = 100;
  int b_d = 110;
  int c_d = 35;
  int d_d = 140;
  a_up.write(a_u);
  b_up.write(b_u);
  c_up.write(c_u);
  d_up.write(d_u);
  a_down.write(a_d);
  b_down.write(b_d);
  c_down.write(c_d);
  d_down.write(d_d);
}

// THE DOG STARTS TO GO FRONT WHEN THIS FUNCTION IS RUNNING
int walk(int x) {
  int a_u = 80;
  int b_u = 100;
  int c_u = 90;
  int d_u = 90;
  int a_d = 100;
  int b_d = 110;
  int c_d = 35;
  int d_d = 140;
  int steps, i;
  a_up.write(a_u);
  b_up.write(b_u);
  c_up.write(c_u);
  d_up.write(d_u);
  a_down.write(a_d);
  b_down.write(b_d);
  c_down.write(c_d);
  d_down.write(d_d);

  for (steps = 1; steps <= x; steps++)
  {
    duration = sonar.ping();
    distance = (duration / 2) * 0.0343;
    if (distance > 10 )           // CONDITION CHECK 
    {
      //LEFT front
      for ( i = 0; i < 25; i++)
      {
        d_d = d_d - 1;
        b_d = b_d + 1;
        d_down.write(d_d);
        b_down.write(b_d);
        delay(10);
      }
      for (i = 0; i < 20; i++)
      {
        d_u = d_u + 1;
        b_u = b_u - 1;
        d_up.write(d_u);
        b_up.write(b_u);
        delay(10);
      }
      for (i = 0; i < 25; i++)
      {
        d_d = d_d + 1;
        b_d = b_d - 1;
        d_down.write(d_d);
        b_down.write(b_d);
        delay(10);
      }

      for (i = 0; i < 20; i++)
      {
        d_u = d_u - 1;
        b_u = b_u + 1;
        d_up.write(d_u);
        b_up.write(b_u);
        delay(10);
      }
      delay(100);

      // RIGHT front
      for ( i = 0; i < 25; i++)
      {

        a_d = a_d + 1;
        c_d = c_d - 1;
        a_down.write(a_d);
        c_down.write(c_d);
        delay(10);
      }

      for (i = 0; i < 20; i++)
      {
        a_u = a_u - 1;
        c_u = c_u + 1;
        a_up.write(a_u);
        c_up.write(c_u);
        delay(10);
      }

      for (i = 0; i < 25; i++)
      {
        a_d = a_d - 1;
        c_d = c_d + 1;
        a_down.write(a_d);
        c_down.write(c_d);
        delay(10);
      }

      for (i = 0; i < 20; i++)
      {
        a_u = a_u + 1;
        c_u = c_u - 1;
        a_up.write(a_u);
        c_up.write(c_u);
        delay(10);
      }
    }
    else
    {
      delay(5000);
    }
  }
}


void loop() {
  stand();
  delay(5000);
  walk(20);      // WALK  20 STEPS
}

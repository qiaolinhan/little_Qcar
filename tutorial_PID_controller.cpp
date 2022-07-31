/*******************************************************************************
*   Copyright (C) 2022 Concordia NAVlab. All rights reserved.
*
*   @Filename: tutorial_PID_controller.cpp
*
*   @Author: Linhan Qiao
*
*   @Email: q_linhan@live.concodia.ca
*
*   @Date: 2022-07-31
*
*   @Description: This is a record of PID controller using C++
*
*******************************************************************************/


#include "tutorial_PID_controller.hpp"
int main(int argc, char** argv) {
return 0;
}

/* position control */
#include <iostream>

using namespace std;

void PID_init();
float PID_realizer(float speed);

struct _pid{
float SetSpeed; // referece speed
float ActualSpeed; // meaurement speed
float error; // residual
float error_last; // last residual
float Kp, Ki, Kd; // p, i, d
float voltage; // represented the acutator
float integral; // define the integral vaue
} pid;

int main()
{
  cout << "======> System begin \n";
  PID_init();
  int cout = 0;
  while (cout < 1000)
  {
    float speed = PID_realize(200.0);
    cout << "The speed of" << count << "th time is:" << speed << endl;
    cout++;
  }
  return 0;
}

void PID_init()
{
cout << "PID_init begin \n";
pid.SetSpeed = speed;
pid.error = pid.SetSpeed - pid.AcutalSpeed;
pid.integral += pid.error;
pid.voltage = pid.Kp * pid.error + pid.integral + pid.Kd * (pid.error - pid.error_last);
pid.error_last = pid.error;
pid.ActualSpeed = pid.voltage * 1.0;
return pid.ActualSpeed;
}


/* Residual-based PID controller */
#include <iostream>

using namespace std;

void PID_init();
float PID_realize(float speed);

struct _pid{
float SetSpeed; 
float ActualSpeed;
float error;
float error_next;
float error_last;
float Kp, Ki, Kd;
float voltage;
float integral;
}pid;

bool index;

int main()
{
  cout<<" ======> System begin \n";
  PID_init();
  int_count = 0;
  while (count < 1000)
  {
    float speed = PID_realize(200.0);
    cout << "The speed of" << count "th time is:" << speed <<endl;
    count++;
  }
  return 0;
}

void PID_init()
{
  cout<<"PID_init begin \n;"
  pid.SetSpeed = 0.0;
  pid.ActualSpeed = 0.0;
  pid.error = 0.0;
  pid.error_last = 0.0;
  pid.voltage = 0.0;
  pid.intergral = 0.0;
  pid.Kp = 0.2;
  cout<<"PID_init end \n";
}

float PID_realize(float speed)
{
pid.SetSpeed = speed;
pid.error = pid.SetSpeed = pid.ActualSpeed;
if (abs(pid.rror) > 180)
  {
  index = 1;
  }
else
  {
  pid.integral += pid.error;
  }

pid.voltage = pid.Kp * pid.error + 
              index * pid.intergral + 
              pid.Kd * (pid.error - pid.error_last);

pid.error_last = pid.error;
pid.ActualSpeed = pid.voltage * 1.0;
return pid.ActualSpeed;
}

/* 抗积分饱和 */
/* aviod integrate out of control */
/* if u(k - 1) > umaxu(k - 1) > umax, only accumulate negative deviations;:
 * if u(k - 1) < umin, only accumulate positive deviations.
 * */
#include <ostream>

using namespace std;

void PID_init();
float PID_realize(float speed);

struct _pid{
float SetSpeed;
float ActualSpeed;
float error;
float error_last;
float Kp, Ki, Kd;
float valtage;
float integreal;
float umax;
flaot umin;
}pid;

int main()
{
  cout<<"System begin \n";
  PID_init();
  int count = 0;
  while(count < 1000)
  {
    float speed=PID_realize(200.0);
    cout<<"The speed of the" << count <<"th time is:" << speed <<endl;
    count++;
  }
  return 0;
}

void PID_init()
{
cout << "PID_init begin \n";
pid.SetSpeed = 0.0;
pid.ActualSpeed = 0.0;
pid.error = 0.0;
pid.error_last = 0.0;
pid.voltage = 0.0;
pid.intergral = 0.0;
pid.Kp = 0.2;
pid.Ki = 0.1;
pid.Kd = 0.2;
pid.umax = 400;
pid.umin = -200;
cout << "PID_init end \n"
}

float PID_realize(float speed)
  {
  pid.SetSpeed = speed;
  pid.error = pid.SetSpeed = pid.ActualSpeed;
  if (pid.ActualSpeed > pid.umax)
  {
    // 抗积分饱和
    if (abs(pid.error) > 200)
    //积分分离
    {
      index= 0；
    }
    else
    {
      index = 1;
      if (pid.error < 0)
      {
        pid.intergral += pid.error;
      }
    }
  }
  else if (pid.ActualSpeed<pid.umin)
  {
    if (abs(pid.error) > 200)
  // 积分分离
    {
      index = 0;
    }
    else
    {
      index = 1; 
      if (pid.error > 0)
      {
        pid.intergral += pid.error;
      }
      else
      {
        if (abs(pid.error) > 200)
        // 积分分离
        {
          index = 0；
        }
        else
        {
          index = 1;
          pid.integral += pid.error;
        }
      }
      pid.voltage = pid.Kp * pid.error + 
                    index * pid.Ki * pid.integral + 
                    pid.Kd * (pid.errpr - pid.error_last);
      pid.error_last = pid.error;
      pid.ActualSpeed = pid.voltage * 1.0;
    }
  }
}

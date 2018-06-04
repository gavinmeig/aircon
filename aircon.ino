#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int PowerAcPIN = D1;
int tempUpPIN = D2;
int tempDownPIN = D3;
int degrees;

void setup()
{

  pinMode(PowerAcPIN, OUTPUT);
  pinMode(tempUpPIN, OUTPUT);
  pinMode(tempDownPIN, OUTPUT);

  digitalWrite(PowerAcPIN, LOW);
  digitalWrite(tempUpPIN, LOW);
  digitalWrite(tempDownPIN, LOW);

  Particle.function("PowerAc", PowerAc);
  Particle.function("tempUp", tempUp);
  Particle.function("tempDown", tempDown);
}

void loop()
{
}

int PowerAc(String command)
{
  if (command == "power")
  {
    digitalWrite(PowerAcPIN, HIGH);
    digitalWrite(PowerAcPIN, LOW);

    return 1;
  }
  else
    return -1;
}

int tempUp(String command)
{
  degrees = atoi(command);

  if (isdigit(degrees))
  {

    for (int i = 0; i < degrees; ++i)
    {
      digitalWrite(tempUpPIN, HIGH);
      digitalWrite(tempUpPIN, LOW);
    }

    return 1;
  }
  else
    return -1;
}

int tempDown(String command)
{
  degrees = atoi(command);

  if (isdigit(degrees))
  {

    for (int i = 0; i < degrees; ++i)
    {
      digitalWrite(tempDownPIN, HIGH);
      digitalWrite(tempDownPIN, LOW);
    }

    return 1;
  }
  else
    return -1;
}

// Imports from C++ library to convert string to int and check if int
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Environment variables
int PowerAcPIN = D1;
int tempUpPIN = D2;
int tempDownPIN = D3;
int degrees;

void setup()
{

  // Setting up pins for use
  pinMode(PowerAcPIN, OUTPUT);
  pinMode(tempUpPIN, OUTPUT);
  pinMode(tempDownPIN, OUTPUT);

  // Setting pins to low
  digitalWrite(PowerAcPIN, LOW);
  digitalWrite(tempUpPIN, LOW);
  digitalWrite(tempDownPIN, LOW);

  // Particle IFTTT functions
  Particle.function("PowerAc", PowerAc);
  Particle.function("tempUp", tempUp);
  Particle.function("tempDown", tempDown);
}

void loop()
{
}

// Gets String of command and checks if it matches power, if it does it toggles the AC.
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

// Gets String of command from IFTTT, string will be # of degrees to increase.
int tempUp(String command)
{
  // Uses atoi to convert it to an int by assigning to the degrees variable that's an int
  degrees = atoi(command);

  // Uses ctype library to check if degrees is a number with the isdigit function
  if (isdigit(degrees))
  {

    // Loops through the requested number of times, might need a delay.
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

// Gets String of command from IFTTT, string will be # of degrees to decrease.
int tempDown(String command)
{
  // Uses atoi to convert it to an int by assigning to the degrees variable that's an int
  degrees = atoi(command);

  // Uses ctype library to check if degrees is a number with the isdigit function
  if (isdigit(degrees))
  {

    // Loops through the requested number of times, might need a delay.
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

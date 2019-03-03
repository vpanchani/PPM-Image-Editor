#include <iostream>
#include "ColorClass.h"
#include "ImageClass.h"

using namespace std;

//Construct and Destructor

ColorClass::ColorClass() 
{
  red = green = blue = 0;
}

ColorClass::ColorClass(int inRed, int inGreen, int inBlue) 
{
  red = inRed;
  green = inGreen;
  blue = inBlue;
}

ColorClass::~ColorClass() 
{
  
}

int ColorClass::getRed() 
{
  return red;
}

int ColorClass::getGreen() 
{
  return green;
}

int ColorClass::getBlue() 
{
  return blue;
}

bool ColorClass::compareColors(ColorClass anotherColor) 
{
  if(anotherColor.red == red && anotherColor.blue == blue && anotherColor.green == green) 
  {
    return true;
  }
  else 
  {
    return false;
  }
}


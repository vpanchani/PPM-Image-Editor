/* 
 * File:   RectangleClass.cpp
 * Author: Virat
 *
 * Created on February 20, 2014, 10:03 PM
 */
#include <iostream>
#include "RectangleClass.h"
#include "ImageClass.h"

using namespace std;
void RectangleClass::rectangleMethod(ImageClass &loadImage)
{
  int choice;
  int pass = 0;
  cout << "1. Specify upper left and lower right" 
       << " corners of rectangle" << endl;
  cout << "2. Specify upper left corner and dimensions" 
       << " of rectangle" << endl;
  cout << "3. Specify extent from center of rectangle" << endl;
  while (pass == 0) 
  {
    cout << "Enter int for rectangle specification method: " << endl;
    cin >> choice;
    pass = checkInput(choice);
    if (choice > 3 || choice < 1)
    {
      cout << "ERROR: No rectangle specification method" 
           << " for the given input!" << endl;
      pass = 0;
    }    
  }
  switch (choice)
  {
    case 1: methodOne(loadImage); break;
    case 2: methodTwo(loadImage); break;
    case 3: methodThree(loadImage); break;
  }  
}

void RectangleClass::createRectangle(int xPosition, int yPosition, int width,
                                           int height, ImageClass &loadImage)
{
  ColorClass myColor;
  int choice, colorFillOption;
  int maxValue = 255;
  int pass = 0;
  int columns = loadImage.getColumns();
  cout << "1. Red\n";
  cout << "2. Green\n";
  cout << "3. Blue\n";
  cout << "4. Black\n";
  cout << "5. White\n";
  while (pass == 0) 
  {
    cout << "Enter int for rectangle color: ";
    cin >> choice;
    pass = checkInput(choice);
    if (choice > 5 || choice < 1)
    {
      cout << "ERROR: No rectangle color found for" 
           <<" the given input!" << endl;
      pass = 0;
    }    
  }
  switch (choice)
  {
    case 1: myColor = ColorClass(maxValue,0,0); break;
    case 2: myColor = ColorClass(0,maxValue,0); break;
    case 3: myColor = ColorClass(0,0,maxValue); break;
    case 4: myColor = ColorClass(0,0,0); break;
    case 5: myColor = ColorClass(maxValue,maxValue,maxValue); break;
  }
  cout << "1. No\n";
  cout << "2. Yes\n";
  pass = 0;
  while (pass == 0) 
  {
    cout << "Enter int for rectangle fill option: ";
    cin >> colorFillOption;
    pass = checkInput(colorFillOption);
    if (colorFillOption > 2 || colorFillOption < 1)
    {
      cout << "ERROR: No rectangle fill option found for the"
           << " given input!" << endl;
      pass = 0;
    }    
  }
  if (colorFillOption == 1)
  {
    for (int n=xPosition; n<=(height+xPosition); n+=height)
    {
      for (int m=yPosition; m <(width+yPosition); m++)
      {      
        index = columns*(n) + m;      
        loadImage.getIndexNumberAt(index,myColor);
      }
    }    
  
    for (int y=yPosition; y <=(width+yPosition); y += width)
    {  
      for (int x=xPosition; x<=(height+xPosition); x++)
      { 
        index = columns*(x) + y;
        loadImage.getIndexNumberAt(index,myColor);
      }
    } 
  }
  else if(colorFillOption == 2)
  {
    for (int n=xPosition; n<(height+xPosition); n++)
    {      
      for (int m=yPosition; m <(width+yPosition-2); m++)
      {      
        index = columns*(n) + m;
        loadImage.getIndexNumberAt(index,myColor);
      }   
    }
  }  
}

void  RectangleClass::methodOne(ImageClass &loadImage)
{
  int upperLeftRow, upperLeftColumn, lowerRightRow, lowerRightColumn;
  cout << "Enter upper left corner row and column: ";
  cin >> upperLeftRow >> upperLeftColumn;
  cout << "Enter lower right corner row and column: ";
  cin >> lowerRightRow >> lowerRightColumn;
  xPosition = upperLeftRow;
  yPosition = upperLeftColumn;
  height = lowerRightRow - upperLeftRow;
  width = lowerRightColumn - upperLeftColumn;
  createRectangle(xPosition, yPosition, width, height, loadImage);
}

void  RectangleClass::methodTwo(ImageClass &loadImage)
{
  int upperLeftRow, upperLeftColumn;
  cout << "Enter upper left corner row and column: ";
  cin >> upperLeftRow >> upperLeftColumn;
  cout << "Enter int for number of rows: ";
  cin >> height;
  cout << "Enter int for number of columns: ";
  cin >> width;
  xPosition = upperLeftRow;
  yPosition = upperLeftColumn;
  createRectangle(xPosition, yPosition, width, height, loadImage);
}

void  RectangleClass::methodThree(ImageClass &loadImage)
{
  int centerRow, centerColumn, halfWidth, halfHeight;
  cout << "Enter rectangle center row and column: " ;
  cin >> centerRow >> centerColumn;
  cout << "Enter int for half number of rows: ";
  cin >> halfHeight;
  cout << "Enter int for half number of columns: ";  
  cin >> halfWidth;
  xPosition = centerRow - halfWidth;
  yPosition = centerColumn - halfHeight;
  width = 2*halfWidth;
  height = 2*halfHeight;
  createRectangle(xPosition, yPosition, width, height, loadImage);
}

bool RectangleClass::checkInput(int check)
{
  if (cin.fail())
  {
    cin.clear(); 
    cin.ignore(200, '\n');
    cout << endl << "ERROR: Expected integer value" << endl;
  }
  else
  {
    return true;      
  }
  return false;
}






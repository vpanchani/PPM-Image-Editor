/* 
 * File:   main.cpp
 * Author: Virat
 *
 * Created on February 17, 2014, 9:38 PM
 */

#include <iostream>
//#include "constants.h"
#include "ColorClass.h"
#include "ImageClass.h"
#include "PixelLocationClass.h"
#include "RectangleClass.h"
//#include "PerformOperation.h"
using namespace std;

// function deceleration
int operationChoice();

int main()
{
  ImageClass loadImage;
  ColorClass getColor;
  RectangleClass rectangle;
  loadImage.readImage();
//  loadImage.readImageToInsert();
//  loadImage.insertPattern();
//  loadImage.writeImage();
/*  
  PerformOperation startProgram(loadImage);
  startProgram.callFunction();*/
  
  int choice = operationChoice();
  while (choice != 5 )
  {
    switch (choice)
      {
        case 1: rectangle.rectangleMethod(loadImage); break;
        case 2: loadImage.insertPattern(); break;
        case 3: loadImage.readImageToInsert(); break;
        case 4: loadImage.writeImage(); break;
        case 5: break;
        default:
          cout << "Sorry that is an invalid menu choice - try again!" << endl; 
          break;
      }
	choice = operationChoice();
  }
  loadImage.deleteImage();
  return 0; 
}


int operationChoice()
{
  int choice;
  cout << "1. Annotate image with rectangle" << endl;
  cout << "2. Annotate image with pattern from file" <<  endl;
  cout << "3. Insert another image" << endl;
  cout << "4. Write out current image" << endl;
  cout << "5. Exit the program" <<  endl;
  cout << "Enter int for main menu choice: " <<  endl;
  cin >> choice;
  return choice;
}
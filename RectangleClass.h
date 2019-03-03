/* 
 * File:   RectangleClass.h
 * Author: Virat
 *
 * Created on February 20, 2014, 9:56 PM
 */

#ifndef RECTANGLECLASS_H
#define	RECTANGLECLASS_H
#include "ImageClass.h"
#include "ColorClass.h"

class RectangleClass
{
  private:
    int xPosition, yPosition, width, height;
    int index;
  public:      
    void createRectangle(int xPosition, int yPosition, int width, 
                              int height, ImageClass& loadImage);
    void methodOne(ImageClass &loadImage);
    void methodTwo(ImageClass &loadImage);
    void methodThree(ImageClass &loadImage);
    void rectangleMethod(ImageClass &loadImage);
    bool checkInput(int check);
};


#endif	/* RECTANGLECLASS_H */


/* 
 * File:   ColorClass.h
 * Author: Virat
 *
 * Created on February 17, 2014, 9:40 PM
 */

#ifndef COLORCLASS_H
#define	COLORCLASS_H

class ColorClass
{
  private:
    int red, green, blue;

  public:
    ColorClass();
    ColorClass(int inRed, int inBlue, int inGreen);
    ~ColorClass();
    bool compareColors(ColorClass anotherColor);
    int getRed();
    int getBlue();
    int getGreen();    
};



#endif	/* COLORCLASS_H */


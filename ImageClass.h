/* 
 * File:   ImageClass.h
 * Author: Virat
 *
 * Created on February 17, 2014, 10:34 PM
 */

#ifndef IMAGECLASS_H
#define	IMAGECLASS_H
#include <string>
#include "ColorClass.h"
class ImageClass
{
  public:
    void readImage();
    void writeImage();
    void readImageToInsert();
    void insertPattern();
    ImageClass();
    ImageClass(int getRows, int getColumns);
    ~ImageClass();
    int getRows();
    int getColumns();    
    void deleteImage();
  	void getIndexNumberAt(int index, ColorClass getColor);
  private:
    int rows;
    int columns;
    std::string format;
    ColorClass *matrix; 
};

#endif	/* IMAGECLASS_H */


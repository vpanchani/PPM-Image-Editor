
#include <iostream>
#include <fstream>
#include <string>
#include "ImageClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include <cstdlib>

using namespace std;
ImageClass::ImageClass()
{
  rows = columns = 0;
}

ImageClass::ImageClass(int getRows, int getColumns)
{
  rows = getRows;
  columns = getColumns;
}

ImageClass::~ImageClass()
{
}
void ImageClass::readImage()
{
  ifstream inFile;
  string fileName;
  int a;
  int pixelRed, pixelBlue, pixelGreen;
  cout << "Enter string for PPM image file name to load: ";
  cin >> fileName;
  inFile.open(fileName.c_str());
  
  getline(inFile,format);  
  inFile >> columns;
  inFile >> rows;
  inFile >> a;  
  cout << "columns:::" << columns << endl;
  matrix = new ColorClass[rows*columns];
  
  int curRow = 0;
  int curCol = 0;
  while(!inFile.eof())
  {
    if(curRow*columns + curCol == rows*columns) 
    {
      break;
    }
    inFile >> pixelRed;
    inFile >> pixelGreen;
    inFile >> pixelBlue;
    ColorClass fullPixel(pixelRed, pixelGreen, pixelBlue);
    matrix[curRow*columns+curCol] = fullPixel;
    curCol++;
    if(curCol == columns) 
    {
      curRow++;
      curCol = 0;
    }
	}
  inFile.close();  
}

void ImageClass::writeImage()
{
  int maxValue = 255;
  ofstream outFile;
  string writeFileName;
  cout << "Enter string for PPM file name to output: ";
  cin >> writeFileName;
  outFile.open(writeFileName.c_str());
  outFile << format << '\n';
  outFile << columns << " " << rows << '\n';
  outFile << maxValue << '\n';
  for (int n=0; n<rows; n++)
  {   
    for (int m=0; m < columns; m++)
    { 
      outFile << matrix[n*columns+m].getRed() << " ";
      outFile << matrix[n*columns+m].getGreen() << " ";
      outFile << matrix[n*columns+m].getBlue() << " ";       
    } 
    outFile << '\n';   
  }
  outFile.close();
}

void ImageClass::readImageToInsert()
{
  ifstream insert;
  ColorClass myColor;
  string fileName;
  int choice, pixel, xPosition, yPosition, height, width;
  int maxValue = 255;
  int pixelRed, pixelBlue, pixelGreen;
  cout << "Enter string for file name of PPM image to insert: ";
  cin >> fileName;
  cout << "Enter upper left corner to insert image row and column: ";
  cin >> xPosition >> yPosition;
  insert.open(fileName.c_str());
  getline(insert,format);  
  insert >> width;
  insert >> height;
  insert >> pixel;  
  int curRow = xPosition;
  int curCol = yPosition;
  cout << "1. Red\n";
  cout << "2. Green\n";
  cout << "3. Blue\n";
  cout << "4. Black\n";
  cout << "5. White\n";
  cout << "Enter int for transparecy color: ";
  cin >> choice;
  switch (choice)
  {
    case 1: myColor = ColorClass(maxValue,0,0); break;
    case 2: myColor = ColorClass(0,maxValue,0); break;
    case 3: myColor = ColorClass(0,0,maxValue); break;
    case 4: myColor = ColorClass(0,0,0); break;
    case 5: myColor = ColorClass(maxValue,maxValue,maxValue); break;
  }
  while(!insert.eof())
  {
    if(curRow >= height+xPosition) 
    {
      break;
    }
    insert >> pixelRed;
    insert >> pixelGreen;
    insert >> pixelBlue;
    ColorClass insertImagePixel(pixelRed, pixelGreen, pixelBlue);
    if ( myColor.compareColors(insertImagePixel))
    {    
    }
    else
    {
      matrix[curRow*columns+curCol] = insertImagePixel;
    }
    curCol++;
    if(curCol == width+yPosition) 
    {
      curRow++;
      curCol = yPosition;
    }
	}
  insert.close(); 
}

void ImageClass::deleteImage() 
{
  delete [] matrix;
}

void ImageClass::insertPattern()
{
  ifstream pattern;
  string fileName;
  ColorClass myColor;
  int choice, xPosition, yPosition, height, width, data;
  int maxValue = 255;
  cout << "Enter string for file name containing pattern: ";
  cin >> fileName;
  cout << "Enter upper left corner of pattern row and column: ";
  cin >> xPosition >> yPosition;
  pattern.open(fileName.c_str());
  pattern >> width;
  pattern >> height;
  cout << "1. Red\n";
  cout << "2. Green\n";
  cout << "3. Blue\n";
  cout << "4. Black\n";
  cout << "5. White\n";
  cout << "Enter int for rectangle color: ";
  cin >> choice;
  switch (choice)
  {
    case 1: myColor = ColorClass(maxValue,0,0); break;
    case 2: myColor = ColorClass(0,maxValue,0); break;
    case 3: myColor = ColorClass(0,0,maxValue); break;
    case 4: myColor = ColorClass(0,0,0); break;
    case 5: myColor = ColorClass(maxValue,maxValue,maxValue); break;
  }
  int curRow = xPosition;
  int curCol = yPosition;
  
  while(!pattern.eof())
  {
    if(curRow >= height+xPosition) 
    {
      break;
    }    
    pattern >> data;
    if (data == 1)
    {
      matrix[curRow*columns+curCol] = myColor;
    }
    curCol++;
    if(curCol == width+yPosition) 
    {
      curRow++;
      curCol = yPosition;
    }
	}
  pattern.close(); 
}

int ImageClass::getRows()
{
  return rows;
}

int ImageClass::getColumns()
{
  return columns;
}

void ImageClass::getIndexNumberAt(int index, ColorClass getColor)
{
  matrix[index] = getColor;
}







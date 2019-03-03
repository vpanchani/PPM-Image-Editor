main.exe:ColorClass.o ImageClass.o RectangleClass.o PixelLocationClass.o main.o
	g++ -g -Wall ColorClass.o ImageClass.o main.o RectangleClass.o -o PixelLocationClass.o -o main.exe

main.o:main.cpp
	g++ -c -g -Wall main.cpp -o main.o

ColorClass.o:ColorClass.cpp ColorClass.h
	g++ -c -g -Wall ColorClass.cpp -o ColorClass.o
	
RectangleClass.o:RectangleClass.cpp RectangleClass.h
	g++ -c -g -Wall RectangleClass.cpp -o RectangleClass.o

ImageClass.o:ImageClass.cpp ImageClass.h
	g++ -c -g -Wall ImageClass.cpp -o ImageClass.o
	
PixelLocationClass.o:PixelLocationClass.cpp PixelLocationClass.h
	g++ -c -g -Wall PixelLocationClass.cpp -o PixelLocationClass.o

clean:  
	rm -rf main.o ColorClass.o ImageClass.o main.exe

#include <iostream>
#include <string>
#include <fstream>
#include  <stdlib.h>
#include <cstring>
#include <ctype.h>
#include <cmath>
#include "bmplib.h"
#include "bmplib.cpp"
using namespace std ;
unsigned char image [SIZE][SIZE][RGB];
void loadRGB();
void saveRGB();
void display();
int main ()
{
   loadRGB();
   display();
   saveRGB();
}
void loadRGB()
{
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
}
void saveRGB()
{
    char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
  writeRGBBMP(imageFileName, image);
}
void display(){
    

     for( int row = 0; row < SIZE ; row++){
    for(int col =0 ; col < SIZE ; col++){
       for (int k =0 ; k < RGB;k++)
       {
            image[row][col][k] /= 2 ;
       }
    }
     }
}
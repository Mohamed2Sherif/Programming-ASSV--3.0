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
const int COUNT = 256 *256*3;
unsigned char image [SIZE][SIZE][RGB];
void loadRGB();
void saveRGB();
void darken();
void flip_h();
void Black_White_Filter();
void flip_v();
void detectE();
double Average();
void mirror();
int main ()
{
   loadRGB();
  detectE();
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
void darken(){
    

     for( int row = 0; row < SIZE ; row++){
    for(int col =0 ; col < SIZE ; col++){
       for (int k =0 ; k < RGB;k++)
       {
            image[row][col][k] /= 2 ;
       }
    }
     }
}
void flip_h()
{
    unsigned char temp;
    for( int row = 0; row < SIZE/2 ; row++){
    for(int col =0 ; col < SIZE ; col++){
            for ( int k =0 ; k < RGB;k++)
            {
                temp = image[255-row][col][k];
             image[255-row][col][k] = image[row][col][k] ;
             image[row][col][k] = temp;
            }



    }

}
}
void flip_v()
{
     unsigned char temp;
    for( int row = 0; row < SIZE ; row++){
    for(int col =0 ; col < SIZE/2 ; col++){
        for (int k =0; k<RGB;k++)
        {
               temp = image[row][255 - col][k];
             image[row][255 - col][k] = image[row][col][k] ;
             image[row][col][k] = temp;

        }
         


    }

}

}

void mirror()
{
    int option;
    cout << " for mirroring the left part press (1) for mirroring the right part press (2)"<<endl;
    cout << " for mirroring the upper part press (3)for mirroring the lower part press (4)"<<endl;
    cin >> option;

    if (option == 1)
      {
for( int row = 0; row < SIZE ; row++){
    for(int col =0 ; col < SIZE/2 ; col++){
        for (int k =0; k <RGB; k++){
            image[row][255-col][k] = image[row][col][k];
        }
            

    }


}
      }
      else if (option == 2)
      {
          for( int row = 0; row < SIZE ; row++){
    for(int col =0 ; col < SIZE/2 ; col++){
    for (int k =0; k <RGB; k++){
     image[row][col][k] = image[row][255-col][k];
}
           

    }


}
    }
      else if (option == 3)
      {
for( int row = 0; row < SIZE/2 ; row++){
    for(int col =0 ; col < SIZE ; col++){
    for (int k =0; k <RGB; k++){

            image[255-row][col][k] = image[row][col][k];
    }
    }


}
      }
      else if (option == 4)
      {
          for( int row = 0; row < SIZE/2 ; row++){
    for(int col =0 ; col < SIZE ; col++){
            for (int k =0; k <RGB; k++){

            image[row][col][k] = image[255-row][col][k];
            }
    }


}
      }
   
}
double Average()
{
    int sum = 0;
    for ( int row =0 ; row <SIZE; row++)
        {
            for (int col =0 ; col <SIZE; col++)
            {
                for (int k = 0; k <RGB; k++)
                {
                    sum += image[row][col][k];
                }
            }
        }
    double result = sum / COUNT ;
    return result ;
}
void Black_White_Filter()
{
   
int sum ;
    for ( int row =0 ; row <SIZE; row++)
    {
        for (int col =0 ; col <SIZE; col++)
        {
            sum =0;
          for (int k =0 ; k <RGB; k++)
          {
              sum += image[row][col][k];
          }
          double average = (sum/3 );
           if (average > 128 )
           {
               for (int k =0 ; k <RGB; k++){
               image[row][col][k] =255;
           }}
           else if (average < 128 )
           {
               for (int k =0 ; k <RGB; k++)
               {
               image[row][col][k] =0;
           }}
        }
    }
    
}
void detectE()

{
    Black_White_Filter();
    for( int row = 0; row < SIZE ; row++){
    for(int col =0 ; col < SIZE ; col+=1){
    
        for (int k = 0 ; k <RGB; k++)
        {
            if(image[row][col][k] == image[row][col+1][k])
        {
            image[row][col][k]= 255;
        }
        else {image[row][col][k] = 0;}
        }
    }
    }
}
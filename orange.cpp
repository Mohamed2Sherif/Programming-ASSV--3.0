#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.h"
#include "bmplib.cpp"
using namespace std ;
void display_menu();
void load();
void save();
const int COUNT = 256 *256;
double Average();
void Black_White_Filter();
unsigned char image[SIZE][SIZE];
int main ()
{
    load();
    display_menu();
    cout<<endl;
    
    

     

}


 void display_menu()
 {
     int option;
     {
     cout<<"choose a filter to apply  : "<<endl;
     cout<<"1- Black & White Filter"<<endl;
     cout<<"2- Invert Filter"<<endl;
     cout<<"3- Merge Filter" <<endl;
     cout<<"4- Flip Image" <<endl;
     cout<<"5- Darken and Lighten Image"<<endl;
     cout<<"6- Rotate Image"  <<endl;
     cout<<"7- Detect Image Edges"<<endl;
     cout<<"8- Enlarge Image"   <<endl;
     cout<<"9- Shrink Image"   <<endl;
     cout<<"a- Mirror 1/2 Image"  <<endl;   
     cout<<"b- Shuffle Image" <<endl;
     cout<<"c- Blur Image"  <<endl;
     cout<<"s- Save the image to a file"<<endl;
     cout<<"0- Exit" <<endl;
     cin >> option;
     }
     if (option == 1)
     {
            Black_White_Filter();
     }
    //  else if (option == 2)
    //  {}
    //  else if (option == 3)
    //  {}
    //  else if (option == 4)
    //  {}
    //  else if (option == 5)
    //  {}
    //  else if (option == 6)
    //  {}
    //  else if (option == 7)
    //  {}
    //  else if (option == 8)
    //  {}
    //  else if (option == 9)
    //  {}
    //  else if (option == 'a')
    //  {}
    //  else if (option == 'b')
    //  {}
    //  else if (option == 's')
    //  {}   
    //  else if (option == 0)
    //  {
    //  }
     }
 

 void load () {
char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
 }
 void save ()

 {
    char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
 }

double Average()
{
    int sum = 0;
    for ( int row =0 ; row <SIZE; row++)
        {
            for (int col =0 ; col <SIZE; col++)
            {
                sum += image[row][col];
            }
        }
    double result = sum / COUNT ;
    return result ;
}

void Black_White_Filter()
{

    for ( int row =0 ; row <SIZE; row++)
    {
        for (int col =0 ; col <SIZE; col++)
        {
           if (image[row][col] > Average())
           {
               image[row][col] =255;
           }
           else if (image[row][col] < Average())
           {
               image[row][col] =0;
           }
        }
    }
    save();
}
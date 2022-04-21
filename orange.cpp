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
// functions , arrays and constants used globally in the programe

void display_menu();
void load();
void load1();
void save();
const int COUNT = 256 *256;
double Average();
void Black_White_Filter();
void Invert_Image();
void Merge();
void Rotate_img();
void flip_h();
void flip_v();
void Rotate_img();
void Rotate_img1();
void Rotate_img2();
void darken();
void lighten ();
void mirror ();
void enlarge();
void Shuffle();
void Shrink();
void detectE();
unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];

// int main ()
// {
//     load();
//     while (1)
//     {
//     display_menu();
    
//     }
//     cout<<endl;

//  }


 void display_menu()
 {
     char option;
     int option1;

     {
     cout<<"choose a filter to apply or 0 to exit : "<<endl;
     cout<<"1- Black & White Filter"<<endl;
     cout<<"2- Invert Filter"<<endl;
     cout<<"3- Merge Filter" <<endl;
     cout<<"4- Flip Image" <<endl;
     cout<<"5- Rotate Image"  <<endl;
     cout<<"6- Darken and Lighten Image"<<endl;
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
     if (option == '1')
     {      
            Black_White_Filter();
     }
     else if (option == '2')
      {     
          Invert_Image();
      }
      else if (option == '3')
     {      
         load1();
         Merge();
     }
      else if (option == '4')
      {
          cout<<"for horizontal flip press (1) for vertical flip press (2)"<<endl;
          cin>>option1;
          if(option1 == 1){
            flip_h();
          }
          else if (option1 == 2){
            flip_v();
          }
      }
    else if (option == '5')
     {
         load1();
         cout << "for rotating 90 deg press (1) for 180 deg press (2) and for 270 deg press(3)"<<endl;
         cin >> option1 ;
         if(option1 == 1)
         {
             Rotate_img();
         }
         else if(option1 == 2)
         {
             Rotate_img2();
         }
         else if(option1 == 3)
         {
             Rotate_img1();
         }
         save();
     }
      else if (option == '6')
      {
          cout<<"for darken press (1) and for lighten press (2)"<<endl;
          cin >> option1;
           if(option1 == 1){
            darken();
          }
          else if (option1 == 2){
            lighten();
          }
      }
     else if (option == '7')
     {  
         Black_White_Filter();
         detectE();
         
     }
      else if (option == '8')
      {
           enlarge();
           
           
      }
     else if (option == '9')
     {
         Shrink();
        

     }
      else if (option == 'a')
     {
         mirror();
     }
    //  else if (option == 'b')
    //  {}
    //  else if (option == 'c')
    //  {}
     else if (option == 's')
     {
         save();
     }
     else if (option == '0')
     {
        exit(0);
     }
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

  void load1 () {
char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the second source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image1);
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
           if (image[row][col] > 128)
           {
               image[row][col] =255;
           }
           else if (image[row][col] < 128)
           {
               image[row][col] =0;
           }
        }
    }
    
}

void Invert_Image()
{

for( int row = 0; row < SIZE ; row++){
    for(int col =0 ; col < SIZE ; col++){
        image[row][col] = 255 - image[row][col];
    }

}
// save();

}
void Merge()
{
for( int row = 0; row < SIZE ; row++){
    for(int col =0 ; col < SIZE ; col++){
        image[row][col] = (image1[row][col]+image[row][col])/2;
    }

}
// save();
}

/*void Rotate_img()
{
    for( int row = 0; row < SIZE ; row++){
    for(int col =0 ; col < SIZE ; col++){
        if((row < 128) && (col < 128)){
            image = image
        }
    }

}
}*/

void flip_h()
{
    unsigned char temp;
    for( int row = 0; row < SIZE/2 ; row++){
    for(int col =0 ; col < SIZE ; col++){
            temp = image[255-row][col];
             image[255-row][col] = image[row][col] ;
             image[row][col] = temp;



    }

}
// save();
}

void flip_v()
{
     unsigned char temp;
    for( int row = 0; row < SIZE ; row++){
    for(int col =0 ; col < SIZE/2 ; col++){

            temp = image[row][255 - col];
             image[row][255 - col] = image[row][col] ;
             image[row][col] = temp;



    }

}
// save();
}

void darken()
{
     for( int row = 0; row < SIZE ; row++){
    for(int col =0 ; col < SIZE ; col++){

            image[row][col] /= 2;

    }


}
// save();
}

void lighten()
{
    double temp;
     for( int row = 0; row < SIZE ; row++){
    for(int col =0 ; col < SIZE ; col++){

            temp = image[row][col] ;

            temp *= 1.5;
            if (temp > 255){
             image[row][col] = 255;

            }
            else {
                image[row][col] = temp;
            }

    }


}
// save();
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

            image[row][255-col] = image[row][col];

    }


}
      }
      else if (option == 2)
      {
          for( int row = 0; row < SIZE ; row++){
    for(int col =0 ; col < SIZE/2 ; col++){

            image[row][col] = image[row][255-col];

    }


}
    }
      else if (option == 3)
      {
for( int row = 0; row < SIZE/2 ; row++){
    for(int col =0 ; col < SIZE ; col++){

            image[255-row][col] = image[row][col];

    }


}
      }
      else if (option == 4)
      {
          for( int row = 0; row < SIZE/2 ; row++){
    for(int col =0 ; col < SIZE ; col++){

            image[row][col] = image[255-row][col];

    }


}
      }
    //   save();
}

void enlarge()
{
    int part;
    load1();
    cout<<"which part you want to enlarge : "<<endl;
    cout<<" 1   2 "<<endl;
    cout<<" __|__ "<<endl;   
    cout<<" 3 | 4 "<<endl;
    unsigned char imageenlarged[SIZE][SIZE];
    cin >> part;
    if(part == 1)
    {

          for( int row = 0; row < SIZE/2 ; row+=1){
    for(int col =0 ; col < SIZE/2 ; col+=1){
    imageenlarged[row][col] = image1[row][col];
    
    }
    }
    for (int row =0 ; row < SIZE; row+=2){
    for (int col = 0; col < SIZE; col+=2)
    {
    image[row][col] = imageenlarged[row/2][col/2];
    image[(row+1)][col] = imageenlarged[row/2][col/2];
    image[(row+1)][(col+1)] = imageenlarged[row/2][col/2];
    image[row][(col+1)] = imageenlarged[row/2][col/2];
          }
    }
    
    }
     else if (part == 2)
     {
                   for( int row = 0; row < SIZE/2 ; row+=1){
    for(int col =0 ; col < SIZE/2 ; col+=1){
    imageenlarged[row][col] = image1[row][col+128];
    
    }
    }
          for (int row =0 ; row < SIZE; row+=2){
    for (int col = 0; col < SIZE; col+=2)
    {
    image[row][col] = imageenlarged[row/2][col/2];
    image[(row+1)][col] = imageenlarged[row/2][col/2];
    image[(row+1)][(col+1)] = imageenlarged[row/2][col/2];
    image[row][(col+1)] = imageenlarged[row/2][col/2];
          }
    }
     }
      else if (part == 3)
     {
                    for( int row = 0; row < SIZE/2 ; row+=1){
    for(int col =0 ; col < SIZE/2 ; col+=1){
    imageenlarged[row][col] = image1[row+128][col];
    
    }
    }
        
    for (int row =0 ; row < SIZE; row+=2){
    for (int col = 0; col < SIZE; col+=2)
    {
    image[row][col] = imageenlarged[row/2][col/2];
    image[(row+1)][col] = imageenlarged[row/2][col/2];
    image[(row+1)][(col+1)] = imageenlarged[row/2][col/2];
    image[row][(col+1)] = imageenlarged[row/2][col/2];
          }
    }
          
     } else if (part == 4)
     {
                   for( int row = 0; row < SIZE/2 ; row+=1){
    for(int col =0 ; col < SIZE/2 ; col+=1){
    imageenlarged[row][col] = image1[row+128][col+128];
    }
    }
     for (int row =0 ; row < SIZE; row+=2){
    for (int col = 0; col < SIZE; col+=2){
    image[row][col] = imageenlarged[row/2][col/2];
    image[(row+1)][col] = imageenlarged[row/2][col/2];
    image[(row+1)][(col+1)] = imageenlarged[row/2][col/2];
    image[row][(col+1)] = imageenlarged[row/2][col/2];
          }
    }
          }

}

void Shrink()
{   
    int option ;
    cout<<"1-shrink to 1/2"<<endl;
    cout<<"2-shrink to 1/3"<<endl;
    cout<<"3-shrink to 1/4"<<endl;
    cin>>option;
    unsigned char imageshrink[SIZE][SIZE];
    switch(option)
    {
        case 1 :
{
    for(int row = 0 ; row < SIZE; row+=1){
    for ( int col = 0 ; col < SIZE ; col +=1)
    {   
        imageshrink[row][col] = image[row][col];
    }}
    for(int row = 0 ; row < SIZE; row+=1){
    for ( int col = 0 ; col < SIZE ; col +=1)
    {   
        image[row][col] = 0;
    }}
    for(int row = 0 ; row < SIZE; row+=2){
    for ( int col = 0 ; col < SIZE ; col +=2)
    {   
        image[row/2][col/2] = (imageshrink[row][col]+imageshrink[(row)+1][col]+imageshrink[row+1][col+1]+imageshrink[row][col+1])/4 ;
    }
    }  
}
break;
case 2 :
for(int row = 0 ; row < SIZE; row+=1){
    for ( int col = 0 ; col < SIZE ; col +=1)
    {   
        imageshrink[row][col] = image[row][col];
    }}
    for(int row = 0 ; row < SIZE; row+=1){
    for ( int col = 0 ; col < SIZE ; col +=1)
    {   
        image[row][col] =0;
    }}
    for(int row = 0 ; row < SIZE; row+=3){
    for ( int col = 0 ; col < SIZE ; col +=3)
    {   
        image[row/3][col/3] = (imageshrink[row][col]+imageshrink[row][col+1]+imageshrink[row+1][col])/3;
    }}
    break;
case 3:
    for(int row = 0 ; row < SIZE; row+=1){
    for ( int col = 0 ; col < SIZE ; col +=1)
    {   
        imageshrink[row][col] = image[row][col];
    }}
    for(int row = 0 ; row < SIZE; row+=1){
    for ( int col = 0 ; col < SIZE ; col +=1)
    {   
        image[row][col] =0;
    }}
    for(int row = 0 ; row < SIZE; row+=4){
    for ( int col = 0 ; col < SIZE ; col +=4)
    {   
        image[row/4][col/4] = (imageshrink[row][col] + imageshrink[row-1][col-1] + imageshrink[row-1][col] + imageshrink[row-1][col+1] + imageshrink[row][col-1] + imageshrink[row][col+1] +imageshrink[row+1][col-1] + imageshrink[row+1][col] + imageshrink[row+1][col+1])/9;
    }}
    break;
    }
    
}
void detectE()

{
              for( int row = 0; row < SIZE ; row++){
    for(int col =0 ; col < SIZE ; col+=1){
    
        if(image[row][col] == image[row][col+1])
        {
            image[row][col]= 255;
        }
        else {image[row][col] = 0;}
    }
    }
}
void Rotate_img()
{
    for(int row =0 ; row < SIZE ;row ++){
        for(int col = 0 ; col < SIZE ; col++){
            image[row][col]=image1[255-col][row];
        }
    }

}

void Rotate_img1()
{
    for(int row =0 ; row < SIZE ;row ++){
        for(int col = 0 ; col < SIZE ; col++){
            image[row][col]=image1[col][255-row];
        }
    }

}

void Rotate_img2()
{
    for(int row =0 ; row < SIZE ;row ++){
        for(int col = 0 ; col < SIZE ; col++){
            image[row][col]=image1[255-row][255-col];
        }
    }
}

void Shuffle()
{   
    cout<<"Enter parts by the sequence you want : ";
    int sequ[4];
    int part;
    for (int range =0 ; range < 3; range++)
    {   
        cin>>part;
        cout<<"/";

    }
}
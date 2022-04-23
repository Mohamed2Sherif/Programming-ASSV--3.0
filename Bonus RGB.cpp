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
unsigned char image1 [SIZE][SIZE][RGB];
void loadRGB();
void load1();
void saveRGB();
void darken();
void Invert_Image();
void enlarge();
void flip_h();
void Black_White_Filter();
void flip_v();
void Rotate_img();
void Rotate_img1();
void Rotate_img2();
void detectE();
void display_menu();
double Average();
void mirror();
void Merge();
void lighten();
void Shrink();
void Shuffle();
void Blur();
int main ()
{
    
   loadRGB();
display_menu();
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
         saveRGB();
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
     else if (option == 'b')
     {
         Shuffle();
     }
     else if (option == 'c')
     {
         Blur();
     }
     else if (option == 's')
     {
         saveRGB();
     }
     else if (option == '0')
     {
        exit(0);
     }
     }



void load1()
{
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image1);
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

void Invert_Image()
{

for( int row = 0; row < SIZE ; row++){
    for(int col =0 ; col < SIZE ; col++){
       for (int k =0 ; k < RGB;k++){
            image[row][col][k] = 255 - image[row][col][k];

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

void Rotate_img()
{
    for(int row =0 ; row < SIZE ;row ++){
        for(int col = 0 ; col < SIZE ; col++){
              for (int k = 0 ; k <RGB; k++){
            image[row][col][k]=image1[255-col][row][k];
        }
        }
    }

}

void Rotate_img1()
{
    for(int row =0 ; row < SIZE ;row ++){
        for(int col = 0 ; col < SIZE ; col++){
                for (int k = 0 ; k <RGB; k++){
            image[row][col][k]=image1[col][255-row][k];
        }
        }
    }

}

void Rotate_img2()
{
    for(int row =0 ; row < SIZE ;row ++){
        for(int col = 0 ; col < SIZE ; col++){
                for (int k = 0 ; k <RGB; k++){
            image[row][col][k]=image1[255-row][255-col][k];
        }
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
void enlarge()
{
    int part;
    load1();
    cout<<"which part you want to enlarge : "<<endl;
    cout<<" 1   2 "<<endl;
    cout<<" __|__ "<<endl;
    cout<<" 3 | 4 "<<endl;
    unsigned char imageenlarged[SIZE][SIZE][RGB];
    cin >> part;
    if(part == 1)
    {

          for( int row = 0; row < SIZE/2 ; row+=1){
    for(int col =0 ; col < SIZE/2 ; col+=1){
            for (int k = 0 ; k <RGB; k++){
    imageenlarged[row][col][k] = image1[row][col][k];
            }
    }
    }
    for (int row =0 ; row < SIZE; row+=2){
    for (int col = 0; col < SIZE; col+=2)
    {
        for (int k = 0 ; k <RGB; k++){
    image[row][col][k] = imageenlarged[row/2][col/2][k];
    image[(row+1)][col][k] = imageenlarged[row/2][col/2][k];
    image[(row+1)][(col+1)][k] = imageenlarged[row/2][col/2][k];
    image[row][(col+1)][k] = imageenlarged[row/2][col/2][k];
          }
    }
    }

    }
     else if (part == 2)
     {
                   for( int row = 0; row < SIZE/2 ; row+=1){
    for(int col =0 ; col < SIZE/2 ; col+=1){
            for (int k = 0 ; k <RGB; k++){
    imageenlarged[row][col][k] = image1[row][col+128][k];
            }
    }
    }
          for (int row =0 ; row < SIZE; row+=2){
    for (int col = 0; col < SIZE; col+=2)
    {
        for (int k = 0 ; k <RGB; k++){
    image[row][col][k] = imageenlarged[row/2][col/2][k];
    image[(row+1)][col][k] = imageenlarged[row/2][col/2][k];
    image[(row+1)][(col+1)][k] = imageenlarged[row/2][col/2][k];
    image[row][(col+1)][k] = imageenlarged[row/2][col/2][k];
          }
    }
    }
     }
      else if (part == 3)
     {
                    for( int row = 0; row < SIZE/2 ; row+=1){
    for(int col =0 ; col < SIZE/2 ; col+=1){
            for (int k = 0 ; k <RGB; k++){
    imageenlarged[row][col][k] = image1[row+128][col][k];
            }
    }
    }

    for (int row =0 ; row < SIZE; row+=2){
    for (int col = 0; col < SIZE; col+=2)
    {
        for (int k = 0 ; k <RGB; k++){
    image[row][col][k] = imageenlarged[row/2][col/2][k];
    image[(row+1)][col][k] = imageenlarged[row/2][col/2][k];
    image[(row+1)][(col+1)][k] = imageenlarged[row/2][col/2][k];
    image[row][(col+1)][k] = imageenlarged[row/2][col/2][k];
          }
    }
    }

     } else if (part == 4)
     {
                   for( int row = 0; row < SIZE/2 ; row+=1){
    for(int col =0 ; col < SIZE/2 ; col+=1){
            for (int k = 0 ; k <RGB; k++){
    imageenlarged[row][col][k] = image1[row+128][col+128][k];
            }
    }
    }
     for (int row =0 ; row < SIZE; row+=2){
    for (int col = 0; col < SIZE; col+=2){
            for (int k = 0 ; k <RGB; k++){
    image[row][col][k] = imageenlarged[row/2][col/2][k];
    image[(row+1)][col][k] = imageenlarged[row/2][col/2][k];
    image[(row+1)][(col+1)][k] = imageenlarged[row/2][col/2][k];
    image[row][(col+1)][k] = imageenlarged[row/2][col/2][k];
          }
    }
    }
          }

}
void Merge()

{

     for (int i = 0 ; i < SIZE ; i ++)
   {
       for (int j = 0 ; j < SIZE ; j ++)
       {
           for (int m = 0 ; m < RGB ; m ++)
           {
               image1[i][j][m] = (image[i][j][m]+image1[i][j][m]) / 2 ; 
           }
           
       }
   }  
}
void lighten()
{

    double temp;
     for( int row = 0; row < SIZE ; row++){
    for(int col =0 ; col < SIZE ; col++){
        for (int k =0 ; k < RGB; k++)
        {
            temp = image[row][col][k] ;

            temp *= 1.5;
            if (temp > 255){
             image[row][col][k] = 255;

            }
            else {
                image[row][col][k] = temp;
            }

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
    unsigned char imageshrink[SIZE][SIZE][RGB];
    switch(option)
    {
        case 1 :
{
    for(int row = 0 ; row < SIZE; row+=1){
    for ( int col = 0 ; col < SIZE ; col +=1)
    {   for (int k = 0; k<RGB; k++){
        imageshrink[row][col][k] = image[row][col][k];
    }}}
    for(int row = 0 ; row < SIZE; row+=1){
    for ( int col = 0 ; col < SIZE ; col +=1)
    {   for (int k =0 ; k<RGB;k++){
        image[row][col][k] = 0;
    }}}
    for(int row = 0 ; row < SIZE; row+=2){
    for ( int col = 0 ; col < SIZE ; col +=2)
    {   for (int k =0 ; k<RGB;k++){
        image[row/2][col/2][k] = (imageshrink[row][col][k]+imageshrink[(row)+1][col][k]+imageshrink[row+1][col+1][k]+imageshrink[row][col+1][k])/4 ;
    }}
    }  
}
break;
case 2 :
for(int row = 0 ; row < SIZE; row+=1){
    for ( int col = 0 ; col < SIZE ; col +=1)
    {   
       for (int k =0 ; k<RGB;k++)
       {
            imageshrink[row][col][k] = image[row][col][k];
       }
    }}
    for(int row = 0 ; row < SIZE; row+=1){
    for ( int col = 0 ; col < SIZE ; col +=1)
    {   for (int k =0 ; k<RGB;k++){
        image[row][col][k] =0;
    }}}
    for(int row = 0 ; row < SIZE; row+=3){
    for ( int col = 0 ; col < SIZE ; col +=3)
    {   for (int k =0 ; k<RGB;k++){
        image[row/3][col/3][k] = (imageshrink[row][col][k]+imageshrink[row][col+1][k]+imageshrink[row+1][col][k])/3;
    }}
    break;}
case 3:
    for(int row = 0 ; row < SIZE; row+=1){
    for ( int col = 0 ; col < SIZE ; col +=1)
    {   for (int k = 0; k<RGB; k++){
        imageshrink[row][col][k] = image[row][col][k];
    }}}
    for(int row = 0 ; row < SIZE; row+=1){
    for ( int col = 0 ; col < SIZE ; col +=1)
    {   for (int k =0 ; k<RGB;k++){
        image[row][col][k] =0;
    }}}
    for(int row = 0 ; row < SIZE; row+=4){
    for ( int col = 0 ; col < SIZE ; col +=4)
    {   for (int k =0 ; k<RGB;k++){
        image[row/4][col/4][k] = (imageshrink[row][col][k] + imageshrink[row-1][col-1][k] + imageshrink[row-1][col][k] + imageshrink[row-1][col+1][k] + imageshrink[row][col-1][k] + imageshrink[row][col+1][k] +imageshrink[row+1][col-1][k] + imageshrink[row+1][col][k] + imageshrink[row+1][col+1][k])/9;
    }}}
    break;
    }
}
void Blur()
{
     for ( int row =0 ; row <SIZE; row++)
    {
        for (int col =0 ; col <SIZE; col++)
        {
            for(int k =0 ; k<RGB; k++)
            image[row][col][k] = (image[row][col][k] + image[row-1][col-1][k] + image[row-1][col][k] + image[row-1][col+1][k] + image[row][col-1][k] + image[row][col+1][k] +image[row+1][col-1][k] + image[row+1][col][k] + image[row+1][col+1][k])/9;

}
    }

}
void Shuffle()
{   
    for (int ro =0; ro < SIZE;ro++)
    {
        for(int co =0; co<SIZE; co++)
        {
            for(int k =0; k <RGB; k++)
            {
            image1[ro][co][k]=image[ro][co][k];
        }}
    }
for (int ro =0; ro < SIZE;ro++)
    {
        for(int co =0; co<SIZE; co++)
        {
            for(int k =0; k <RGB; k++)
            {
           image[ro][co][k]=0;
        }
    }}
     cout<<"Enter parts by the sequence you want : "<<endl;
    int sequ[4];
    int m=0,n=0,row=0,col=0 ;
    for (int range =0 ; range < 4; range++)
    {   
        cin>>sequ[range];
        
    }
        int parts[4] = {1,2,3,4};
        int rowbegin,colbegin;
    for (int range =0 ; range < 4; range++)
    {           
         if ( parts[range] <= 2   ){
            
                    rowbegin = 0;
            }
            else {rowbegin=128;}
            if (parts[range] %2 == 0)
            {
                        colbegin =128;
            }
            else {colbegin =0;}
                int rowsize,colsize;     
        if (rowbegin == 128 )
        {
                 rowsize=256;
        }
        else {rowsize =128;}
         if(colbegin == 128)
        {
                colsize = 256;
        }
        else {colsize=128;}
            m=0,n=0;
            if ( sequ[range] <= 2   )
            {
                    row = 0;
            }
            else {row=128;}
            if (sequ[range] %2 == 0)
            {
                        col =128;
            }
            else {col =0;}
            
    m =row;
    for (int i =rowbegin ; i <rowsize; i++,m++)
    {
            n = col;
            for(int j =colbegin; j <colsize; j++,n++)
            {
                for(int k =0; k <RGB; k++)
            {
                    image[i][j][k]=image1[m][n][k];
            }}
    }
    }
   
   
    
    
}
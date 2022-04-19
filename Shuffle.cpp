#include <iostream>
#include "bmplib.h"
#include "orange.cpp"
using namespace std;
int main ()
{   
    load1();
    // for(int row ; row < SIZE;row++){
    //     for(int col; col<SIZE; col++)
    //     {
    //             image1[row][col] = image[row][col];
    //     }
    // }
    //  for(int row ; row < SIZE;row++){
    //     for(int col; col<SIZE; col++)
    //     {
    //              image[row][col] = 0;
    //     }
    // }
    // save();
     cout<<"Enter parts by the sequence you want : "<<endl;
    int sequ[4];
    int part ;
    for (int range =0 ; range < 4; range++)
    {   
        cin>>part;
        
    }
    ///part 1 
    {
    if (sequ[0] == 1){
            for(int row = 0; row<SIZE/2;row++)
            {
                for (int col =0 ; col<SIZE/2;col++){
                        image[row][col] = image1[row][col];
                }
            }
    }
    else if (sequ[0] == 2){
            for(int row = 0; row<SIZE/2;row++)
            {
                for (int col =0 ; col<SIZE/2;col++){
                        image[row][col] = image1[row][col+=128];
                }
            }
    }
    else if (sequ[0] == 3){
            for(int row = 0; row<SIZE/2;row++)
            {
                for (int col =0 ; col<SIZE/2;col++){
                        image[row][col] = image1[row+=128][col];
                }
            }
    }
    else if (sequ[0] == 4){
            for(int row = 0; row<SIZE/2;row++)
            {
                for (int col =0 ; col<SIZE/2;col++){
                        image[row][col] = image1[row+=128][col+=128];
                }
            }
    }
    }
   //part2
    {
     if (sequ[1] == 1){
            for(int row = 0; row<SIZE/2;row++)
            {
                for (int col =0 ; col<SIZE/2;col++){
                        image[row][col+=128] = image1[row][col];
                }
            }
    }
    else if (sequ[1] == 2){
            for(int row = 0; row<SIZE/2;row++)
            {
                for (int col =0 ; col<SIZE/2;col++){
                        image[row][col+=128] = image1[row][col+=128];
                }
            }
    }
    else if (sequ[1] == 3){
            for(int row = 0; row<SIZE/2;row++)
            {
                for (int col =0 ; col<SIZE/2;col++){
                        image[row][col+=128] = image1[row+=128][col];
                }
            }
    }
    else if (sequ[1] == 4){
            for(int row = 0; row<SIZE/2;row++)
            {
                for (int col =0 ; col<SIZE/2;col++){
                        image[row][col+=128] = image1[row+=128][col+=128];
                }
            }
    }
    }
    //part3
    {
        if (sequ[2] == 1){
            for(int row = 0; row<SIZE/2;row++)
            {
                for (int col =0 ; col<SIZE/2;col++){
                        image[row+=128][col] = image1[row][col];
                }
            }
    }
     else if (sequ[2] == 2){
            for(int row = 0; row<SIZE/2;row++)
            {
                for (int col =0 ; col<SIZE/2;col++){
                        image[row+=128][col] = image1[row][col+=128];
                }
            }
    }
    else if (sequ[2] == 3){
            for(int row = 0; row<SIZE/2;row++)
            {
                for (int col =0 ; col<SIZE/2;col++){
                        image[row+=128][col] = image1[row+=128][col];
                }
            }
    }
    else if (sequ[2] == 4){
            for(int row = 0; row<SIZE/2;row++)
            {
                for (int col =0 ; col<SIZE/2;col++){
                        image[row+=128][col] = image1[row+=128][col+=128];
                }
            }
    }
    }
    //part4
    {
         if (sequ[3] == 1){
            for(int row = 0; row<SIZE/2;row++)
            {
                for (int col =0 ; col<SIZE/2;col++){
                        image[row+=128][col+=128] = image1[row][col];
                }
            }
            
    }
    else  if (sequ[3] == 2){
            for(int row = 0; row<SIZE/2;row++)
            {
                for (int col =0 ; col<SIZE/2;col++){
                        image[row+=128][col+=128] = image1[row][col+=128];
                }
            }
            
    }
     else if (sequ[3] == 3){
            for(int row = 0; row<SIZE/2;row++)
            {
                for (int col =0 ; col<SIZE/2;col++){
                        image[row+=128][col+=128] = image1[row+=128][col];
                }
            }
            
    }
    else  if (sequ[3] == 4){
            for(int row = 0; row<SIZE/2;row++)
            {
                for (int col =0 ; col<SIZE/2;col++){
                        image[row+=128][col+=128] = image1[row+=128][col+=128];
                }
            }
            
    }
    }
    save();
}
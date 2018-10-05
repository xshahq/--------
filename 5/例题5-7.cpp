#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int next(int *arr, int low, int high)
{
    int prod = arr[low] * arr[high];
     int prev = arr[high];
      while(low <= high){
          if(arr[low]*arr[high] <= prev)
              ++low;
          else{
              if(arr[low]*arr[high] < prod)
                  prod = arr[low]*arr[high];
              --high;
          }
      }
      return prod;
}
int main()
{
    int data[1500];
    data[0]=1;
    data[1]=2;
    data[2]=3;
    data[3]=4;
    data[4]=5;
    for(int i = 5; i < 1500; ++i)
        data[i] = next(data, 1, i - 1);
        for(int i = 0; i < 1500; ++i)
            if(i == 1499)
                printf ("The 1500'th ugly number is %d.\n" ,data[i] );
    printf ("\n" );
    return 0;
}

#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
using namespace std;
int numMirro[10] = {'1','S','E',-1,'Z',-1,-1,'8',-1};
int charMirro[26] = {'A',-1,-1,-1,'3',-1,-1,'H','I','L',-1,'J','M',-1,'O',-1,-1,-1,'2','T','U','V','W','X','Y','5'};
int main()
{
    char arr[21];
    while(scanf("%s",arr) == 1)
    {
        int j = 0,temp = strlen(arr) - 1,count1 = 0,count2 = 0;
        while(j <= temp)
        {
            if(arr[j] != arr[temp])
            {
                count1 = 1;
                break;
            }
            ++j;
            --temp;
        }
        int t = strlen(arr);
        temp = t - 1;
        j = 0;
        while(j < t)
        {
            int trans = isalpha(arr[j]) ? charMirro[arr[j] - 'A'] : numMirro[arr[j] - '1'];
            if(trans != arr[temp])
            {
                count2 = 1;
                break;
            }
            ++j;
            --temp;
        }
        for(int j = 0;j < t;++j)
            cout << arr[j];
        if(count1 && count2)
            cout << " -- is not a palindrome." << endl;
        else if(count1 && !count2)
            cout << " -- is a mirrored string." << endl;
        else if(!count1 && count2)
            cout << " -- is a regular palindrome." << endl;
        else
            cout << " -- is a mirrored palindrome." << endl;
        cout << endl;
    }
}


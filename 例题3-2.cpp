#include<iostream>
#include<stdio.h>
using namespace std;
char str[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
    char ch;
    while((ch = getchar()) != EOF)
    {
        int i;
        for(i = 0;str[i];++i)
            if(str[i] == ch)
                break;
        if(str[i])
            cout << str[i - 1];
        else
            cout << ch;
    }
}
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int count1 = 0;
    char ch;
    while((ch = getchar()) != EOF)
    {
        if(ch == '"')
        {
            if(!count1)
            {
                cout << "``";
                count1 = 1;
            }
            else
            {
                count1 = 0;
                cout << "''";
            }
        }
        else
            cout << ch;
    }
}

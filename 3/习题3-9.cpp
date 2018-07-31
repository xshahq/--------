#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<string>
using namespace std;
string str1,str2;
int main()
{
    while(cin >> str1 >> str2)
    {
        int i = 0,j = 0;
        while(i < str1.length() && j < str2.length())
        {
            if(str1[i] == str2[j])
                ++i;
            ++j;
        }
        i < str1.length() ? cout << "No" : cout << "Yes";
        cout << endl;
    }
}
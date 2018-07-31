#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
string str1,str2;
int main()
{
    while(cin >>str1 >>str2)
    {
        int arr1[26] = {0},arr2[26] = {0};
        for(int i = 0;i < str1.length();++i)
            arr1[str1[i] - 'A']++;
        for(int i = 0;i < str2.length();++i)
            arr2[str2[i] - 'A']++;
        sort(arr1,arr1 + 26);
        sort(arr2,arr2 + 26);
        int i = 0;
        for(;i < 26;++i)
            if(arr1[i] != arr2[i])
                break;
        i >= 26 ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}

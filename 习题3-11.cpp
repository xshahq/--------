#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<limits.h>
using namespace std;
string str1,str2;
int main()
{
    while(cin >> str1 >> str2)
    {
        if(str1.length() > str2.length())
            swap(str1,str2);
        int length = str2.length();
        for(int i = 0;i < str1.length();++i)
            str2.push_back('0');
        int ans = INT_MAX;
        for(int i = 0;i < str2.length();++i)
        {
            int t = i,j,temp = length;
            for(j = str1.length() - 1;j >= 0;--j)
            {
                if(t < 0 || str1[j] - '0' + str2[t] - '0' > 3)
                    break;
                --t;
            }
            if(t < 0)
            {
                temp = length + j + 1;
                j = -1;
            }
            if(j < 0)
            {
                if(i + 1> length)
                    temp = i + 1;
                ans = min(ans,temp);
            }
        }
        //if(ans == INT_MAX)
            //ans = str1.length() +str2.length();
        cout << ans << endl;
    }
    return 0;
}


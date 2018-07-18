#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<string>
using namespace std;
int t,d[26];
string str;
int main()
{
    cin >> t;
    while(t)
    {
        memset(d,0,sizeof(d));
        cin >> str;
        for(int i = 0;i < str.length();++i)
        {
            int j = i + 1,temp = 0;
            while(j < str.length() && isdigit(str[j]))
            {
                temp = temp * 10 + str[j] - '0';
                ++j;
            }
            d[str[i] - 'A'] = temp == 0 ? d[str[i] - 'A'] + 1 : d[str[i] - 'A'] + temp;
        }
        double ans = 12.01 * d['C' - 'A'] + 1.008 * d['H' - 'A'] + 16 * d['O' - 'A'] +14.01 * d['N' - 'A'];
        printf("%.3f\n",ans);
        --t;
    }
}
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<string>
using namespace std;
int n,m,d[10][10],down[100];
string arr[11],t[101];
int main()
{
    int time = 1;
    while(1)
    {
        memset(d,0,sizeof(d));
        memset(down,0,sizeof(down));
        cin >> n;
        if(!n)
            break;
        cin >> m;
        for(int i = 0;i < n;++i)
            cin >> arr[i];
        printf("puzzle #%d:\n",time++);
        cout << "Across" << endl;
        int count1 = 1;
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j)
                if(arr[i][j] != '*' && (!i || !j || arr[i - 1][j] == '*' || arr[i][j - 1] == '*'))
                    d[i][j] = count1++;
        int temp = 0;
        for(int i = 0;i < n;++i)
        {
            for(int j = 0;j < m;++j)
                if(arr[i][j] != '*')
                {
                    if(!temp)
                    {
                        if(d[i][j] < 10)
                            printf("  %d.",d[i][j]);
                        else
                            printf(" %d.",d[i][j]);
                        temp = 1;
                    }
                    putchar(arr[i][j]);
                }
                else
                {
                    if(temp)
                        cout << endl;
                    temp = 0;
                }
            if(temp)
                cout << endl;
            temp = 0;
        }
        cout << "Down" << endl;
        int count2 = 0;
        temp = 0;
        for(int i = 0;i < m;++i)
        {
            string str1;
            for(int j = 0;j < n;++j)
                if(arr[j][i] != '*')
                {
                    if(!temp)
                    {
                        down[count2] = d[j][i];
                        temp = 1;
                    }
                    str1.push_back(arr[j][i]);
                }
                else
                {
                    if(temp)
                        t[down[count2++]] = str1;
                    string str;
                    str1 = str;
                    temp = 0;
                }
             if(temp)
                t[down[count2++]] = str1;
            temp = 0;
        }
        sort(down,down + count2);
        for(int i = 0;i < count2;++i)
        {
            if(down[i] < 10)
                printf("  %d.",down[i]);
            else
                printf(" %d.",down[i]);
            cout << t[down[i]] << endl;
        }
        cout << endl;
    }
    return 0;
}


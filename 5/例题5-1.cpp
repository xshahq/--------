#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int m,n;
#define N 10000
int arr[N];
int main()
{
    int t = 1;
    while(cin >> n >> m && n)
    {
        for(int i = 1;i <= n;++i)
            cin >> arr[i];
        sort(arr + 1,arr + n + 1);
        printf("CASE# %d:\n",t++);
        while(m)
        {
            int temp;
            cin >> temp;
            int pos = lower_bound(arr + 1,arr + 1 + n ,temp) - arr;
            if(pos == n + 1 || arr[pos] > temp)
               printf("%d not found\n",temp);
            else
                printf("%d found at %d\n",temp,pos);
            --m;
        }
    }
    return 0;
}
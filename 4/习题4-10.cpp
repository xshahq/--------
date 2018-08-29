#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,arr[1000],Min[1000];
double water;
int main()
{
    int time = 1;
    while(cin >> m >> n && m)
    {
        memset(arr,0,sizeof(arr));
        memset(Min,0,sizeof(Min));
        for(int i = 1;i <= n * m;++i)
            cin >> arr[i];
        cin >> water;
        sort(arr + 1,arr + n * m + 1);
        for(int i = 1;i < m * n;++i)
            Min[i] = arr[i + 1] - arr[i];
        int t = 1,i = 1;
        water = water / 100;
        printf("Region %d\n",time++);
        while(i <= m * n)
        {
            double temp = water / t;
            //cout << temp << endl;
            if(temp <= Min[i])
            {
                printf("Water level is %.2f meters.\n",arr[i] + temp);
                break;
            }
            water -= t++ * Min[i++];
            //cout << water << endl;
        }
        if(i > m * n)
        {
            printf("Water level is %.2f meters.\n",arr[m * n] + water / (m * n));
            printf("100.00 percent of the region is under water.\n");
        }
        else
        {
            double ans = 1.0 * i / (n * m);
            printf("%.2f percent of the region is under water.\n",ans * 100);
        }
        cout <<endl;
    }
    return 0;
}

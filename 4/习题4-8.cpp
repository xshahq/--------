#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<cstring>
using namespace std;
int n,a[11],b[11],c[11],state[11],count1[11],num[11];
vector<vector<int> > arr[1024];
int check(int m)
{
    for(int j = 0;j < arr[m].size();++j)
    {
        int i = 0;
        for(;i < n;++i)
        {
            //cout << num[i + 1] << endl;
            if(arr[m][j][i] != num[i + 1])
                break;
        }
        if(i >= n)
            return 1;
    }
    return 0;
}
int last()
{
    int sum = 0;
    for(int i = 1;i <= n;++i)
        if(!state[i])
            sum++;
    int temp = n - sum;
    return sum > temp;
}
int main()
{
    count1[0] = 1;
    for(int i = 1;i < 11;++i)
        count1[i] = count1[i - 1] * 2;
    int tt = 1;
    while(1)
    {
        cin >> n;
        if(!n)
            break;
        for(int i = 0;i < 1024;++i)
            arr[i].clear();
        memset(state,0,sizeof(state));
        memset(num,0,sizeof(num));
        for(int i = 1;i <= n;++i)
            cin >> a[i] >> b[i] >> c[i];
        int temp1 = 0;
        vector<int> v;
        int sum = 0;
        for(int i = 1;i <= n;++i)
        {
            state[i] = c[i] <= a[i] ? 1 : 0;
            temp1 += count1[i - 1] * state[i];
            num[i] = state[i] ? a[i] - c[i] : a[i] + b[i] - c[i];
            if(state[i])
                sum++;
            v.push_back(num[i]);
        }
        printf("Case %d: ",tt++);
        if(sum == n)
        {
            cout << 1 << endl;
            continue;
        }
        arr[temp1].push_back(v);
        int t = 2;
        while(1)
        {
            temp1 = 0;
            vector<int> v1;
            sum = 0;
            int count2 = last();
            for(int i = 1;i <= n;++i)
            {
                //cout << num[i];
                if(!num[i])
                {
                    if(state[i] && !count2)
                        num[i] = state[i] ? a[i] : b[i];
                    else
                    {
                        num[i] = state[i] ? b[i] : a[i];
                        state[i] ? state[i] = 0 : state[i] = 1;
                    }
                }
                num[i]--;
                temp1 += count1[i - 1] * state[i];
                if(state[i])
                    sum++;
                v1.push_back(num[i]);
            }
            //cout << temp1 << endl;
            //cout << endl;
            if(sum == n)
            {
                cout << t << endl;
                break;
            }
            if(arr[temp1].size() && check(temp1))
            {
                cout << "-1" << endl;
                break;
            }
            arr[temp1].push_back(v1);
            ++t;
        }
    }
    return 0;
}
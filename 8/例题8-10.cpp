#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<memory>
#include<map>
#include<limits.h>
using namespace std;
int n,k,m;
int arr[501],ans[501];
int findSub(long long num)
{
    long long sum = 0,count1 = 0;
    for(int i = 0;i < m;++i)
    {
        if(count1 > k - 1)
            return 0;
        sum += arr[i];
        if(sum > num)
        {
            sum = arr[i];
            ++count1;
        }

    }
    if(count1 > k - 1)
        return 0;
    return 1;
}
void divid(long long num)
{
    long long sum = 0,count1 = 0;
    for(int i = m - 1;i >= 0;--i)
        if(sum + arr[i] > num)
        {
            ans[i + 1] = 1;
            sum = arr[i];
            count1++;
        }
        else
            sum += arr[i];
    int i = 1;
    while(i < m && count1 < k - 1)
    {
        if(!ans[i])
            ans[i] = count1++;
        ++i;
    }
}
int main()
{
    cin >> n;
    while(n)
    {
        memset(arr,0,sizeof(arr));
        memset(ans,0,sizeof(ans));
        long long sum = 0;
        int max1 = INT_MIN;
        cin >> m >> k;
        for(int i = 0;i < m;++i)
        {
            cin >> arr[i];
            sum += arr[i];
            max1 = max(max1,arr[i]);
        }
        long long i = max1,j = sum + 1,mid;
        while(i < j)
        {
            mid = (i + j) / 2;
            if(findSub(mid))
                j = mid;
            else
                i = mid + 1;
        }
        divid(i);
        for(int i = 0;i < m;++i)
        {
            if(ans[i])
                cout << '/' << ' ';
            cout << arr[i] << ' ';
        }
        cout << endl;
        --n;
    }
	return 0;
}
#include<iostream>
#include<stdio.h>
using namespace std;
int n,arr[100001];
int main()
{
    cin >> n;
    for(int i = 1;i <= 100000;++i)
    {
        int t = i,sum = i;
        while(t >= 10)
        {
            int temp = t % 10;
            sum += temp;
            t /= 10;
        }
        sum += t;
        arr[i] = sum;
    }
    int i;
    for(i = 0;i <= 100000;++i)
        if(arr[i] == n)
            break;
    i > 100000 ? cout << 0 : cout << i;
}
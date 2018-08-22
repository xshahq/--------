#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<list>
#include<vector>
using namespace std;
int arr[256][8],n,num[1001][4],mask[4][8],arr1[8] = {1,2,4,8,16,32,64,128},ip1[4][8];
string ip[1001];
void init()
{
    for(int i = 0;i < 256;++i)
    {
        int j = 7,temp = i;
        while(temp >= 2)
        {
            int temp2 = temp % 2;
            temp /= 2;
            arr[i][j--] = temp2;
        }
        arr[i][j] = temp;
    }
}
void ipaddress()
{
    for(int i = 0;i < 4;++i)
    {
        int sum = 0;
        for(int j = 0;j < 8;++j)
        {
            if(!mask[i][j])
                break;
            sum += arr1[7 - j] * ip1[i][j];
        }
        cout << sum;
        if(i != 3)
            cout << ".";
    }
    cout << endl;
}
int main()
{
    init();
    while(cin >> n)
    {
        memset(mask,0,sizeof(mask));
        memset(num,0,sizeof(num));
        for(int i = 0;i < n;++i)
           cin >> ip[i];
        for(int i = 0;i < n;++i)
            for(int j = 0,t = 0;j < ip[i].length();++j)
            {
                if(ip[i][j] == '.')
                    t++;
                else
                    num[i][t] = num[i][t] * 10 + ip[i][j] - '0';
            }
        for(int i = 0;i < 4;++i)
        {
            int t = 0;
            for(;t < 8;++t)
            {
                ip1[i][t] = arr[num[0][i]][t];
                int j = 1;
                for(;j < n;++j)
                    if(arr[num[j][i]][t] != ip1[i][t])
                        break;
                if(j < n)
                    break;
                mask[i][t] = 1;
            }
            if(t < 8)
                break;
        }
        ipaddress();
        for(int i = 0;i < 4;++i)
        {
            int sum = 0;
            for(int j = 0;j < 8;++j)
                sum += arr1[7 - j] * mask[i][j];
            cout << sum;
            if(i != 3)
                cout << ".";
        }
        cout << endl;
    }
    return 0;
}
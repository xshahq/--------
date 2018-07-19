#include<iostream>
using namespace std;
int t,n;
long long arr[11][10001];
int main()
{
    cin >> t;
    arr[1][1] = 1;
    for(int i = 2;i <= 10000;++i)
    {
        for(int j = 0;j <= 9;++j)
            arr[j][i] = arr[j][i - 1];
        int temp = i;
        while(temp >= 10)
        {
            int t = temp % 10;
            arr[t][i] += 1;
            temp /= 10;
        }
        arr[temp][i] += 1;
    }
    while(t)
    {
        cin >> n;
        for(int i = 0;i <= 9;++i)
            cout << arr[i][n] << " ";
        cout << endl;
        --t;
    }
}


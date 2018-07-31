#include<bits/stdc++.h>
using namespace std;
int n,arr[1001],arr1[1001];
int main()
{
    cin >> n;
    int t = 1;
    while(n)
    {
        int judge1[11] = {0};
        for(int i = 0;i < n;++i)
        {
            cin >> arr[i];
            judge1[arr[i]]++;
        }
        cout << "Game " << t << ":" << endl;
        while(1)
        {
            int judge[11];
            for(int i = 0;i < 10;++i)
                judge[i] = judge1[i];
            int count1 = 0,count2 = 0,count3 = 0;
            for(int i = 0;i < n;++i)
            {
                cin >> arr1[i];
                if(!arr1[i])
                    ++count1;
                if(arr1[i] == arr[i])
                {
                    count2++;
                    judge[arr1[i]]--;
                }
            }
            if(count1 == n)
                break;
            for(int i = 0;i < n;++i)
                if((arr[i] != arr1[i]) && judge[arr1[i]])
                {
                    count3++;
                    judge[arr1[i]]--;
                }
            cout << "    (" << count2 << "," << count3 << ")" << endl;
        }
        ++t;
        cin >> n;
    }
}
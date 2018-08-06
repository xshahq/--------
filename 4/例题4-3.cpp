#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<list>
using namespace std;
int n,k,m,arr[20];
int main()
{
    while(1)
    {
        cin >> n >> k >> m;
        if(!n)
            break;
        memset(arr,0,sizeof(arr));
        int t = n,a = 0,b = n + 1;
        while(1)
        {
            int temp1 = k,temp2 = m;
            while(temp1)
            {
                a == n ? a = 1 : ++a;
                if(!arr[a])
                   --temp1;
            }
            while(temp2)
            {
                b == 1 ? b = n : --b;
                if(!arr[b])
                    --temp2;
            }
            a >= 10 ? cout << " " : cout << "  ";
            cout << a;
            if(a != b)
            {
                b >= 10 ? cout << " " : cout << "  ";
                cout << b;
                --t;
            }
            arr[a] = arr[b] = 1;
            --t;
            if(!t)
                break;
            cout << ",";
        }
        cout << endl;
    }
    return 0;
}

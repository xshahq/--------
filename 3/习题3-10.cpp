#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int w,h,t;
pair<int,int> pallet[6];
int judge()
{
    sort(pallet,pallet + 6);
    for(int i = 0;i < 6;++i)
    {
        if(pallet[i].first != pallet[i + 1].first || pallet[i].second != pallet[i + 1].second)
            return 0;
        ++i;
    }

    if(pallet[0].first == pallet[2].first && pallet[0].second == pallet[5].first && pallet[3].second == pallet[5].second)
        return  1;
    return 0;
}
int main()
{
    while(cin >> w >> h)
    {
        int temp1 = min(w,h);
        int temp2 = max(w,h);
        pair<int,int> p(temp1,temp2);
        pallet[t++] = p;
        if(t == 6)
        {
            judge() ? cout << "POSSIBLE" : cout << "IMPOSSIBLE";
            cout << endl;
            t = 0;
        }
    }
    return 0;
}


#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<memory>
#include<map>
using namespace std;
int x[101],y[101],height[101],width[101],depth[101],m,len;
vector<int> sortedX;
int cover(int t,double num)
{
    for(int i = 0;i < m;++i)
        if(i != t && num >= x[i] && num <= x[i] + width[i] && y[i] < y[t] && height[i] >= height[t])
            return 0;
    return 1;
}
int judge(int num)
{
    for(int i = 0;i < len - 1;++i)
        if(sortedX[i] >= x[num] && sortedX[i] < x[num] + width[num])
        {
            //cout << i << endl;
            if(cover(num,(sortedX[i] + sortedX[i + 1]) / 2.0))
                return 1;
        }
        return 0;
}
int main()
{
    int time = 1;
    cin >> m;
    while(m)
    {
        sortedX.clear();
        int i1 = 0;
        while(i1 != m)
        {
            cin >> x[i1] >> y[i1] >> width[i1] >> depth[i1] >> height[i1];
            sortedX.push_back(x[i1]);
            sortedX.push_back(x[i1] + width[i1]);
            ++i1;
        }
        sort(sortedX.begin(),sortedX.end());
        auto pos = unique(sortedX.begin(),sortedX.end());
        len = pos - sortedX.begin();
        map<pair<int,int>,int> ans;
        for(int i = 0;i < m;++i)
            if(judge(i))
                ans.insert(make_pair(make_pair(x[i],y[i]),i));
        printf("For map #%d, the visible buildings are numbered as follows:\n",time++);
        for(auto pos1 = ans.begin();pos1 != ans.end();++pos1)
            cout << pos1 ->second + 1 << " ";
        cout << endl;
        cin >> m;
    }
    return 0;
}

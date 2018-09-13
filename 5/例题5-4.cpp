#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
vector<string> v;
map<string,pair<int,int> > m;
int main()
{
    string str;
    int time = 0;
    while(cin >> str && str != "#")
    {
        v.push_back(str);
        string temp1;
        for(int i = 0;i < str.length();++i)
        {
            int ch = tolower(str[i]);
            temp1.push_back(ch);
        }
        sort(temp1.begin(),temp1.end());
        if(m.find(temp1) != m.end())
            (m[temp1].first)++;
        else
        {
            pair<int,int> p(1,time);
            m[temp1] = p;
        }
        time++;
    }
    vector<string> ans;
    for(auto pos = m.begin();pos != m.end();++pos)
        if(pos ->second.first == 1)
            ans.push_back(v[pos ->second.second]);
    sort(ans.begin(),ans.end());
    for(int i = 0;i < ans.size();++i)
        cout << ans[i] << endl;
    return 0;
}
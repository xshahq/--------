#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
stack<int> st;
map<set<int>,int> m;
set<int> s;
vector<set<int> > v;
int n,time1,count1 = 1;
void id(set<int>& temp2)
{
    if(m.find(temp2) != m.end())
        st.push(m[temp2]);
    else
    {
        m[temp2] = count1;
        v.push_back(temp2);
        st.push(count1++);
    }
}
void unio()
{
    set<int> temp1 = v[st.top()];
    st.pop();
    set<int> temp2 = v[st.top()];
    st.pop();
    for(auto pos = temp1.begin();pos != temp1.end();++pos)
        temp2.insert(*pos);
    id(temp2);
}
void ins()
{
    set<int> temp1 = v[st.top()];
    st.pop();
    set<int> temp2 = v[st.top()];
    st.pop();
    set<int> temp3;
    for(auto pos = temp1.begin();pos != temp1.end();++pos)
        if(temp2.find(*pos) != temp2.end())
            temp3.insert(*pos);
    id(temp3);
}
void add()
{
    set<int> temp1 = v[st.top()];
    st.pop();
    set<int> temp2 = v[st.top()];
    st.pop();
    if(m.find(temp1) != m.end())
        temp2.insert(m[temp1]);
    else
    {
        m[temp1] = count1;
        v.push_back(temp1);
        temp2.insert(count1++);
    }
    id(temp2);
}
int main()
{
    cin >> n;
    while(n)
    {
        cin >> time1;
        string str;
        m.clear();
        v.clear();
        v.push_back(s);
        m[s] = 0;
        count1 = 1;
        while(st.size())
            st.pop();
        while(time1)
        {
            cin >> str;
            switch(str[0])
            {
                case 'P':st.push(0);break;
                case 'D':st.push(st.top());break;
                case 'U':unio();break;
                case 'I':ins();break;
                case 'A':add();break;
            }
            set<int> temp1 = v[st.top()];
            cout << temp1.size() << endl;
            --time1;
        }
        cout << "***" << endl;
        --n;
    }
    return 0;
}
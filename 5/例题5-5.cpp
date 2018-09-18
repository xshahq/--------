#include <bits/stdc++.h>
using namespace std;
typedef set<int> Set;
map<Set,int> id;
vector<Set> vs;
stack<int> st;
int ID(const Set &x)
{
    if(id.find(x)!=id.end())
        return id[x];
    vs.push_back(x);
    return id[x]=vs.size()-1;
}
int main ()
{
    ios::sync_with_stdio(false);
    int t,n;
    cin>>t;
    while(t--)
    {
        vs.clear();
        id.clear();
        while(!st.empty())
            st.pop();
        cin>>n;
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            if(s=="PUSH")
            {
                st.push(ID(Set()));
            }
            else
            {
                if(s=="DUP")
                {
                    st.push(st.top());
                }
                else
                {
                    Set s1=vs[st.top()];
                    st.pop();
                    Set s2=vs[st.top()];
                    st.pop();
                    Set tmp;
                    if(s=="UNION")
                    {
                        set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(tmp,tmp.begin()));
                    }
                    if(s=="INTERSECT")
                    {
                        set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(tmp,tmp.begin()));
                    }
                    if(s=="ADD")
                    {
                        tmp=s2;
                        tmp.insert(ID(s1));
                    }
                    st.push(ID(tmp));
                }
            }

            cout<<vs[st.top()].size()<<endl;
        }
        cout<<"***"<<endl;
 }
    return 0;
}
#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<algorithm>
#include<list>
#include<queue>
#include<stack>
#include<map>
#include<cstring>
using namespace std;
int n,m;
int dataBase[10001][11];
int main()
{
    while(cin >> n >> m)
    {
        memset(dataBase,0,sizeof(dataBase));
        string str;
        getchar();
        map<string,int> index;
        int count1 = 0;
        for(int i = 0;i < n;++i)
        {
            int j = 0;
            getline(cin,str);
            auto pos1 = str.begin();
            for(auto pos = str.begin();pos != str.end();++pos)
                if(*pos == ',')
                {
                    string temp(pos1,pos);
                    if(index.find(temp) != index.end())
                        dataBase[i][j++] = index[temp];
                    else
                    {
                        index.insert(make_pair(temp,count1));
                        dataBase[i][j++] = count1++;
                    }
                    pos1 = pos;
                    ++pos1;
                }
            string temp(pos1,str.end());
            if(index.find(temp) != index.end())
                dataBase[i][j++] = index[temp];
            else
            {
                index.insert(make_pair(temp,count1));
                dataBase[i][j++] = count1++;
            }
        }
        map<pair<pair<int,int>,pair<int,int> >,int> m1;
        int count2 = 0;
        for(int i = 0;i < n;++i)
        {
            for(int j = 0;j < m;++j)
            {
                for(int t = j + 1;t < m;++t)
                {
                    pair<pair<int,int>,pair<int,int> > p(make_pair(dataBase[i][j],j),make_pair(dataBase[i][t],t));
                    if(m1.find(p) == m1.end())
                        m1[p] = i;
                    else if(i != m1[p])
                    {
                        cout << "NO" << endl << m1[p] + 1 << " " << i + 1 << endl << j + 1 << " " << t + 1 << endl;
                        count2 = 1;
                        break;
                    }
                }
                if(count2)
                    break;
            }
            if(count2)
                break;
        }
        if(!count2)
            cout << "YES" << endl;
    }
    return 0;
}
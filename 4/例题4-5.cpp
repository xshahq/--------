#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<list>
#include<vector>
using namespace std;
int r,c,n,or1,oc1,m;
vector<int> oper;
vector<int> order;
void exchange(int& i,int& r1,int& c1)
{
    if(r1 == oper[i] && c1 == oper[i + 1])
    {
        r1 = oper[i + 2];
        c1 = oper[i + 3];
    }
    else if(r1 == oper[i + 2] && c1 == oper[i + 3])
    {
        r1 = oper[i];
        c1 = oper[i + 1];
    }
    i += 4;
}
int deler(int& i,int& r1,int& c1)
{
    int temp = oper[i++],temp1 = r1;
    for(int j = 0;j < temp;++j)
    {
        if(temp1 == oper[i])
            return 0;
        if(temp1 > oper[i])
            r1--;
        ++i;
    }
    return 1;
}
int delec(int& i,int& r1,int& c1)
{
    int temp = oper[i++],temp1 = c1;
    for(int j = 0;j < temp;++j)
    {

        if(temp1 == oper[i])
            return 0;
        if(temp1 > oper[i])
            c1--;
        ++i;
    }
    return 1;
}
void insertr(int& i,int& r1,int& c1)
{
    int temp = oper[i++],temp1 = r1;
    for(int j = 0;j < temp;++j)
    {
        if(temp1 >= oper[i])
            ++r1;
        ++i;
    }
}
void insertc(int& i,int& r1,int& c1)
{
    int temp = oper[i++],temp1 = c1;
    for(int j = 0;j < temp;++j)
    {
        if(temp1 >= oper[i])
            ++c1;
        ++i;
    }
}
void querry(int num)
{
    while(num)
    {
        int r1,c1;
        cin >> r1 >> c1;
        or1 = r1;
        oc1 = c1;
        int i = 0;
        for(int j = 0;i < order.size();++i)
        {
            int count1 = 1;
            switch(order[i])
            {
                case 0:exchange(j,r1,c1);break;
                case 1:count1 = deler(j,r1,c1);break;
                case 2:count1 = delec(j,r1,c1);break;
                case 3:insertc(j,r1,c1);break;
                default:insertr(j,r1,c1);
            }
            //cout << r1 << c1 <<  endl;
            if(!count1)
                break;
        }
        i == order.size() ? printf("Cell data in (%d,%d) moved to (%d,%d)\n",or1,oc1,r1,c1) : printf("Cell data in (%d,%d) GONE\n",or1,oc1);
        --num;
    }
}
int main()
{
    int time = 1;
    while(1)
    {
        cin >> r >> c;
        if(!r && !c)
            break;
        cin >> n;
        while(n)
        {
            string str;
            cin >> str;
            if(str[0] == 'E')
            {
                for(int i = 0;i < 4;++i)
                {
                    int temp;
                    cin >> temp;
                    oper.push_back(temp);
                }
                order.push_back(0);
            }
            else
            {
                int i = 1,temp;
                if(str == "DC")
                    i = 2;
                else if(str == "IC")
                    i = 3;
                else if(str == "IR")
                    i = 4;
                cin >> temp;
                oper.push_back(temp);
                for(int j = 0;j < temp;++j)
                {
                    int temp1;
                    cin >> temp1;
                    oper.push_back(temp1);
                }
                order.push_back(i);
            }
            --n;
        }
        printf("Spreadsheet #%d\n",time++);
        cin >> m;
        querry(m);
        oper.clear();
        order.clear();
        cout << endl;
    }
    return 0;
}
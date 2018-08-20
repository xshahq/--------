#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <set>
#include <stack>
#include <stdlib.h>
#include <time.h>

using namespace std;

char mp[10][10];
int f[2][10][10];
int dx[] = {-1,-1,-1, 1,1,1,0, 0};
int dy[] = {-1, 0, 1,-1,0,1,1,-1};

void is(int a, char b, int x, int y)
{
    for(int k=0;k<8;k++)
    {
        int tx = x+dx[k];
        int ty = y+dy[k];
        int num = 0;
        while(tx>=0 && ty>=0
              && tx<8 && ty<8
              && mp[tx][ty] == b)
        {
            tx += dx[k];
            ty += dy[k];
            ++num;
        }
        if(num>=1 && mp[tx][ty] == '-')
            f[a][tx][ty] |= 1<<k;
    }
}

void init()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(mp[i][j] == 'W')
                is(0, 'B', i, j);
            else if(mp[i][j] == 'B')
                is(1, 'W', i, j);
}

bool print(bool isprint, int p)
{
    bool flag = false;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(f[p][i][j])
            {
                if(flag && isprint)
                    cout<<" ";
                flag = true;
                if(isprint)
                    cout<<'('<<i+1<<','<<j+1<<")";
                else
                    return flag;
            }
    if(isprint)
    {
        if(flag)
            cout<<endl;
        else
            cout<<"No legal move."<<endl;
    }
    return flag;
}

void move(int x, int y, int p)
{
    char ch;
    if(p == 0)
        ch = 'W';
    else
        ch = 'B';
    mp[x][y] = ch;
    for(int i=0;i<8;i++)
    {
        if(f[p][x][y] & 1<<i)
        {
            int tx = x-dx[i];
            int ty = y-dy[i];
            while(tx>=0 && ty>=0
                  && tx<8 && ty<8
                  && mp[tx][ty] != ch)
            {
                mp[tx][ty] = ch;
                tx -= dx[i];
                ty -= dy[i];
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        memset(mp, 0, sizeof(mp));
        for(int i=0;i<8;i++)
            cin>>mp[i];
        char ch[5];int p;
        cin>>ch;
        if(ch[0] == 'W')
            p = 0;
        else
            p = 1;
        while(ch[0] != 'Q')
        {
            memset(f, 0, sizeof(f));
            init();
            cin>>ch;
            if(ch[0] == 'L')
                print(true, p);
            else if(ch[0] == 'M')
            {
                if(!print(false, p))
                    p ^= 1;
                move(ch[1]-'0'-1, ch[2]-'0'-1, p);
                p ^= 1;
                int wnum = 0;
                int bnum = 0;
                for(int i=0;i<8;i++)
                    for(int j=0;j<8;j++)
                    {
                        if(mp[i][j] == 'W')
                            ++wnum;
                        if(mp[i][j] == 'B')
                            ++bnum;
                    }
                printf("Black - %2d White - %2d\n", bnum, wnum);
            }
        }
        for(int i=0;i<8;i++)
            cout<<mp[i]<<endl;
        if(n != 0)
            cout<<endl;
    }
    return 0;
}
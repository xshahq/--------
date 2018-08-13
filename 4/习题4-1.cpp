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
//grhc

int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};
int tx[20];
int ty[20];
int f[20][20] = {};

bool ischeck(int x, int y, int n)
{
    for(int i=0;i<n;i++)
    {
        if(tx[i] == x && ty[i] == y)
            continue;
        if(f[tx[i]][ty[i]] == 'G' ||
           f[tx[i]][ty[i]] == 'R')
        {
            if(x == tx[i])
            {
                int num = 0;
                for(int j = min(y, ty[i])+1;j<max(y, ty[i]);j++)
                {
                    if(f[x][j] != 0)
                        ++num;
                }
                if(num == 0)
                    return true;
            }
            if(y == ty[i])
            {
                int num = 0;
                for(int j = min(x, tx[i])+1;j<max(x, tx[i]);j++)
                {
                    if(f[j][y] != 0)
                        ++num;
                }
                if(num == 0)
                    return true;
            }
        }
        if(f[tx[i]][ty[i]] == 'C')
        {
            if(x == tx[i])
            {
                int num = 0;
                for(int j = min(y, ty[i])+1;j<max(y, ty[i]);j++)
                {
                    if(f[x][j] != 0)
                        ++num;
                }
                if(num == 1)
                    return true;
            }
            if(y == ty[i])
            {
                int num = 0;
                for(int j = min(x, tx[i])+1;j<max(x, tx[i]);j++)
                {
                    if(f[j][y] != 0)
                        ++num;
                }
                if(num == 1)
                    return true;
            }
        }
        if(f[tx[i]][ty[i]] == 'H')
        {
            if(abs(tx[i]-x) == 2 && abs(ty[i]-y) == 1)
            {
                if(tx[i] > x && f[tx[i]-1][ty[i]] == 0)
                    return true;
                if(tx[i] < x && f[tx[i]+1][ty[i]] == 0)
                    return true;
            }
            if(abs(tx[i]-x) == 1 && abs(ty[i]-y) == 2)
            {
                if(ty[i] > y && f[tx[i]][ty[i]-1] == 0)
                    return true;
                if(ty[i] < y && f[tx[i]][ty[i]+1] == 0)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    int n,x,y;
    while(cin>>n>>x>>y)
    {
        if(!n && !x && !y)
            break;
        memset(f, 0, sizeof(f));
        int bx=0, by=0;
        for(int i=0;i<n;i++)
        {
            char ch;
            int a,b;
            cin>>ch>>a>>b;
            tx[i] = a;
            ty[i] = b;
            f[a][b] = ch;
            //cout<<"saa"<<f[a][b]<<endl;
            if(ch == 'G')
            {
                bx = a;
                by = b;
            }
        }
        bool ff = false;
        if(y == by)
        {
            ff = true;
            int l = min(bx, x) + 1;
            int r = max(bx, x);
            while(l < r)
            {
                if(f[l][y] != 0)
                {
                    ff = false;
                    break;
                }
                ++l;
            }
        }
        if(ff)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int i;
        for(i=0;i<4;i++)
        {
            if(x+dx[i]>=1 && x+dx[i]<=3
               && y+dy[i]>=4 && y+dy[i]<=6)
            {
                //cout<<x+dx[i]<<" "<<y+dy[i]<<endl;
                if(!ischeck(x+dx[i], y+dy[i], n))
                    break;
            }
        }
        if(i == 4)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
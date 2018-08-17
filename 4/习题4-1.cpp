#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<list>
#include<vector>
using namespace std;
int checkboard[20][20],bx,by,arr[21][20];
void general(int i1,int j)
{
    for(int i = bx;i <= i1;++i)
    {
        arr[i][j] = 1;
        if(checkboard[i][j])
            break;
    }
}
void chariot(int i1,int j)
{
        for(int i = i1 + 1;i <= 10;++i)
        {
            arr[i][j] = 1;
            if(checkboard[i][j])
                break;
        }
        for(int i = i1 - 1;i >= 0;--i)
        {
            arr[i][j] = 1;
            if(checkboard[i][j])
                break;
        }
        for(int i = j + 1;i <= 9;++i)
        {
            arr[i1][i] = 1;
            if(checkboard[i1][i])
                break;
        }
        for(int i = j - 1;i >= 0;--i)
        {
            arr[i1][i] = 1;
            if(checkboard[i1][i])
                break;
        }
}
void cannon(int i1,int j)
{
        for(int i = i1 + 1;i <= bx;++i)
            if(checkboard[i][j])
            {
                for(int t = i + 1;t <= 10;++t)
                {
                    arr[t][j] = 1;
                    if(checkboard[t][j])
                        break;
                }
                break;
            }
        for(int i = i1 -1;i >= bx;--i)
            if(checkboard[i][j])
            {
                for(int t = i - 1;t >= 1;--t)
                {
                    arr[t][j] = 1;
                    if(checkboard[t][j])
                        break;
                }
                break;
            }
        for(int i = j + 1;i <= by;++i)
            if(checkboard[i1][i])
            {
                for(int t = i + 1;t <= 9;++t)
                {
                    arr[i1][t] = 1;
                    if(checkboard[i1][t])
                        break;
                }
                break;
            }
        for(int i = j - 1;i >= by;--i)
            if(checkboard[i1][i])
            {
                for(int t = i - 1;t >= 1;--t)
                {
                    arr[i1][t] = 1;
                    if(checkboard[i1][t])
                        break;
                }
                break;
            }
}
void horse(int i,int j)
{
    if(j < 8 && !checkboard[i][j + 1])
    {
        if(i <= 9)
            arr[i + 1][j + 2] = 1;
        if(i >= 2)
            arr[i - 1][j + 2] = 1;
    }
    if(j >= 3 && !checkboard[i][j - 1])
    {
        if(i <= 9)
            arr[i + 1][j - 2] = 1;
        if(i >= 2)
            arr[i - 1][j - 2] = 1;
    }
    if(i <= 8 && !checkboard[i + 1][j])
    {
        if(j <= 8)
            arr[i + 2][j + 1] = 1;
        if(j >= 2)
            arr[i + 2][j - 1] = 1;
    }
    if(i >= 3 && !checkboard[i - 1][j])
    {
        if(j <= 8)
            arr[i - 2][j + 1] = 1;
        if(j >= 2)
            arr[i - 2][j - 1] = 1;
    }
}
void judge()
{
    int count1 = bx > 1 ? arr[bx - 1][by] : 1;
    int count2 = bx < 3 ? arr[bx + 1][by] : 1;
    int count3 = by < 6 ? arr[bx][by + 1] : 1;
    int count4 = by > 4 ? arr[bx][by - 1] : 1;
    //cout << count1 << count2 << count3 << count4;
    for(int i = bx;i <= 10;++i)
    {
        if(checkboard[i][by] == 'G')
        {
            printf("NO\n");
            return;
        }
        else if(checkboard[i][by])
            break;
    }
    if(!count1 || !count2 || !count3 || !count4)
        printf("NO\n");
    else
        printf("YES\n");
}
int main()
{
    int n;
    while(cin >> n >> bx >> by)
    {
        memset(arr,0,sizeof(arr));
        memset(checkboard,0,sizeof(checkboard));
        if(!n && !bx && !by)
            break;
        while(n)
        {
            char temp;
            int x,y;
            cin >> temp;
            scanf("%d %d",&x,&y);
            checkboard[x][y] = temp;
            --n;
        }
        for(int i = 1;i <= 10;++i)
            for(int j = 1;j <= 9;++j)
                if(checkboard[i][j])
                {
                    int temp = checkboard[i][j];
                    switch(temp)
                    {
                        case 'C':cannon(i,j);break;
                        case 'H':horse(i,j);break;
                        case 'G':case 'R':chariot(i,j);break;
                    }
                }
        judge();
    }
    return 0;
}
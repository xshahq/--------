#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<list>
#include<vector>
using namespace std;
int horizontal[10][10][10],edge[10],vertical[10][10][10],m,n;
int main()
{
    int t = 1;
    while(cin >> n >> m)
    {
        if(t != 1)
            cout << endl << "**********************************" << endl;
        cout << endl;
        int count1 = 0;
        memset(horizontal,0,sizeof(horizontal));
        memset(vertical,0,sizeof(vertical));
        memset(edge,0,sizeof(edge));
        while(m)
        {
            char ch;
            int temp1,temp2;
            cin >> ch >> temp1 >> temp2;
            ch == 'H' ? horizontal[temp1][temp2 + 1][1] = 1 : vertical[temp2 + 1][temp1][1] = 1;
            --m;
        }
        for(int i = 2;i <= n;++i)
            for(int j = 1;j <= n;++j)
                for(int t = 1;t <= n;++t)
                    if(horizontal[j][t - 1][i - 1] && horizontal[j][t][1])
                        horizontal[j][t][i] = 1;
        for(int i = 2;i <= n;++i)
            for(int j = 1;j <= n;++j)
                for(int t = 1;t <= n;++t)
                    if(vertical[j - 1][t][i - 1] && vertical[j][t][1])
                        vertical[j][t][i] = 1;
        /*for(int i = 1;i <= n;++i)
            for(int j = 1;j <= n;++j)
                cout << horizontal[i][j][1];
        cout << endl;*/
        printf("Problem #%d\n",t++);
        cout << endl;
        for(int i = 1;i<= n;++i)
        {
            int sum = 0;
            for(int j = 1;j <= n - i;++j)
                for(int t = 1;t <= n - i;++t)
                    if(vertical[j + i][t][i] && horizontal[j][t + i][i] && vertical[j + i][t + i][i] && horizontal[j + i][t + i][i])
                    {
                        //cout << i << j << endl;
                        sum++;
                    }
            if(sum)
            {
                count1 = 1;
                printf("%d square (s) of size %d\n",sum,i);
            }
        }
        if(!count1)
            cout << "No completed squares can be found."<< endl;
    }
    return 0;
}

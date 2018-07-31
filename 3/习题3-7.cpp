#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
int time1,m,n,dna[52][1002],ans[1002],d[26];
int main()
{
    cin >> time1;
    while(time1)
    {
        cin >> m >> n;
        memset(ans,0,sizeof(ans));
        for(int i = 0;i < m;++i)
        {
            int ch;
            while((ch = getchar()) == '\n');
            dna[i][0] = ch;
            for(int j = 1;j < n;++j)
                scanf("%c",&dna[i][j]);
        }
        for(int i = 0;i < n;++i)
        {

            memset(d,0,sizeof(d));
            for(int j = 0;j < m;++j)
                d[dna[j][i] - 'A']++;
            int max1 = d[0],count1 = 0;
            for(int t = 1;t < 26;++t)
                if(max1 < d[t])
                {
                    max1 = d[t];
                    count1 = t;
                }
            ans[i] = count1 + 'A';
        }
        for(int i = 0;i < n;++i)
            putchar(ans[i]);
        int temp = 0;
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j)
                if(dna[j][i] != ans[i])
                    temp++;
        cout << endl << temp << endl;
        --time1;
    }
}

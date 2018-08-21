#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<list>
#include<vector>
using namespace std;
int str1[7],str2[7],arr[6][4] = {{2,4,5,3},{6,4,1,3},{2,1,5,6,},{2,6,5,1},{1,4,6,3},{2,3,5,4}};
int judge(int num)
{
    if(str2[7 - num] != str1[6])
        return 0;
    int i;
    for(i = 0;i < 4;++i)
        if(str2[arr[num- 1][i]] == str1[2])
        {
            int j = 0,temp = i;
            for(;j < 4;++j)
            {
                if(str2[arr[num - 1][temp++]] != str1[arr[0][j]])
                    break;
                if(temp == 4)
                    temp = 0;
            }
            if(j >= 4)
                return 1;
        }
    return 0;
}
int main()
{
    char ch;
    while(cin >> ch)
    {
        str1[1] = ch;
        for(int i = 2;i <= 6;++i)
        {
            cin >> ch;
            str1[i] = ch;
        }
        for(int i = 1;i <= 6;++i)
        {
            cin >> ch;
            str2[i] = ch;
        }

        int i = 1;
        for(;i <= 6;++i)
            if(str1[1] == str2[i] && judge(i))
                break;
        i > 6 ? cout << "FALSE" : cout << "TRUE";
        cout << endl;
    }
    return 0;
}
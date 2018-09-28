#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int t;
int arr[1000000],pos[1000000];
int main()
{
    int time1 = 1;
    while(cin >> t && t)
    {
        memset(pos,-1,sizeof(pos));
        memset(arr,0,sizeof(arr));
        vector<int> v[1001];
        queue<int> q[1001];
        int count1 = 0,temp1,head = 0,tail = 0;
        while(t)
        {
            cin >> temp1;
            for(int i = 0;i < temp1;++i)
            {
                int temp2;
                cin >> temp2;
                arr[temp2] = count1;
                v[count1].push_back(temp2);
            }
            count1++;
            --t;
        }
        printf("Scenario #%d\n",time1++);
        string str;
        while(cin >> str && str[0] != 'S')
            if(str[0] == 'E')
            {
                int ele;
                cin >> ele;
                int i;
                for(i = 0;i < v[arr[ele]].size();++i)
                    if(pos[v[arr[ele]][i]] != -1)
                    {
                        q[pos[v[arr[ele]][i]]].push(ele);
                        pos[ele] = pos[v[arr[ele]][i]];
                        break;
                    }
                if(i == v[arr[ele]].size())
                {
                    pos[ele] = tail++;
                    q[pos[ele]].push(ele);
                }
            }
            else
            {
                int num = q[head].front();
                cout << num << endl;
                pos[num] = -1;
                q[head].pop();
                if(!q[head].size())
                    head++;
            }
        cout << endl;
    }
    cout << endl;
    return 0;
}
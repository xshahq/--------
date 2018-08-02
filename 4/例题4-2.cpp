#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
int m,arr[26],c[26];
string str1,str2;
void judge()
{
    int temp = 0;
    for(int i = 0;i < str1.length();++i)
        if(!arr[str1[i] - 'a'])
        {
            temp++;
            arr[str1[i] - 'a'] = 1;
        }
    int count1 = 0,i;
    for(i = 0;i < str2.length();++i)
    {
        int t = str2[i] - 'a';
        if(arr[t] == 1 && !c[t])
            --temp;
        else if(!arr[t] && !c[t])
                ++count1;
        c[t] = 1;
        if(!temp)
        {
            cout << "You win." << endl;
            break;
        }
        if(count1 > 6)
        {
            cout << "You lose." << endl;
            break;
        }
    }
    if(i >= str2.length())
        cout << "You chickened out." << endl;
}
int main()
{
    while(1)
    {
        cin >> m;
        if(m == -1)
            break;
        memset(arr,0,sizeof(arr));
        memset(c,0,sizeof(c));
        cin >> str1 >> str2;
        printf("Round %d\n",m);
        judge();
    }
    return 0;
}
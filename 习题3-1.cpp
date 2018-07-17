#include<iostream>
#include<string>
using namespace std;
int t;
string str;
int main()
{
    cin >> t;
    while(t)
    {
        cin >> str;
        int count1 = 0,sum = 0;
        for(int i = 0;i < str.length();++i)
            str[i] == 'O' ? sum += ++count1 : count1 = 0;
        cout << sum << endl;
        --t;
    }
}
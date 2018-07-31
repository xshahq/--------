#include<iostream>
#include<string>
using namespace std;
int n;
string str;
int main()
{
    cin >> n;
    while(n)
    {
        cin >> str;
        int count1 = 0;
        int j = 0;
        for(int i = 1;i < str.length();++i)
        {
            if(str[i] == str[j])
            {
                if(count1 && count1 == j)
                    j = 0;
                else if(!count1)
                    count1 = i;
                ++j;
            }
            else
            {
                if(count1)
                    --i;
                j = count1 = 0;
            }
        }
        if(count1 && count1 == j) cout << count1 << endl;
        else cout << str.length() << endl;
        cout << endl;
        --n;
    }
}


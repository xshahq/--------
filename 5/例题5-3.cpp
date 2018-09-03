#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
vector<string> arr,arr2;
int main()
{
    string str;
    while(cin >> str)
        arr.push_back(str);
    for(auto i = arr.begin();i != arr.end();++i)
    {
        string temp = *i,str2;
        int count1 = 0;
        for(int j = 0;j < temp.length();++j)
        {
            if(isalpha(temp[j]))
                str2.push_back(tolower(temp[j]));
            if(!isalpha(temp[j]) || !count1)
                ++count1;
            if(count1 == 2)
            {
                count1 = 0;
                if(str2.length())
                    arr2.push_back(str2);
                str2.clear();
            }
        }
        if(str2.length())
            arr2.push_back(str2);
    }
    sort(arr2.begin(),arr2.end());
    auto pos = unique(arr2.begin(),arr2.end());
    for(auto i = arr2.begin();i != pos;++i)
        cout << *i << endl;
    return 0;
}
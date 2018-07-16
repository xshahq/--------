#include<iostream>
#include<string>
using namespace std;
int t;
string str;
vector<int> arr[4];
int main()
{
    cin >> t;
    while(t)
    {
        cin >> str;
        for(int i = 0;i < str.size();++i)
            switch(str[i])
            {
                case 'A':arr[0].push_back(i);break;
                case 'C':arr[1].push_back(i);break;
                case 'G':arr[2].push_back(i);break;
                default:arr[3].push_back(i);
            }
        int i = 0;
        while(!arr[i].size())
            ++i;
        int ans = 0;
        for(int h = 1;h < arr[i].size();++h)
            for(int j = 0,t1 = arr[i][h],t2 = arr[i][ans];j < str.length();++j)
            {
                if(str[t1] > str[t2])
                    break;
                if(str[t1] < str[t2])
                {
                    ans = h;
                    break;
                }
                t1 == str.length() - 1 ? t1 = 0 : ++t1;
                t2 == str.length() - 1 ? t2 = 0 : ++t2;
            }
        for(int t = 0,j = arr[i][ans];t < str.length();++t)
        {
            cout << str[j];
            j == str.length() - 1 ? j = 0 : ++j;
        }
        cout << endl;
        --t;
    }
}
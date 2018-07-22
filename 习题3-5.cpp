#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int x,y;
int arr[5][5];
int a()
{
    if(!y)
        return 0;
    swap(arr[y - 1][x],arr[y][x]);
    y = y - 1;
    return 1;
}
int r()
{
    if(x == 4)
        return 0;
    swap(arr[y][x],arr[y][x + 1]);
    x = x + 1;
    return 1;
}
int l()
{
    if(!x)
        return 0;
    swap(arr[y][x],arr[y][x - 1]);
    x = x - 1;
    return 1;
}
int b()
{
    if(y == 4)
        return 0;
    swap(arr[y][x],arr[y + 1][x]);
    y = y + 1;
    return 1;
}
int main()
{
    int time = 1;
    while(1)
    {
        while((arr[0][0] = getchar()) == '\n');
        if(arr[0][0] == 'Z')
            break;
        int j = 1,temp;
        if(arr[0][0] == ' ')
        {
            x = 0;
            y = 0;
        }
        for(int i = 0;i < 5;++i)
        {
            while(j != 5)
            {
                while((temp = getchar()) == '\n');
                arr[i][j] = temp;
                if(arr[i][j] == ' ')
                {
                    x = j;
                    y = i;
                }
                ++j;
            }
            j = 0;
        }
        int ch,count1 = 1;;
        while((ch = getchar()) != '0')
        {
            if(ch == '\n')
                continue;
            switch(ch)
            {
                case 'A':if(!a())
                            count1 = 0;
                break;
                case 'B':if(!b())
                            count1 = 0;
                break;
                case 'R':if(!r())
                            count1 = 0;
                break;
                case 'L':if(!l())
                            count1 = 0;
                break;
                default:count1 = 0;break;
            }
        }
        printf("Puzzle #%d:\n",time++);
        if(count1)
            for(int i = 0;i < 5;++i)
            {
                for(int j = 0;j < 5;++j)
                {
                    putchar(arr[i][j]);
                    cout << " ";
                }
                cout << endl;
            }
        else
            cout << "This puzzle has no final configuration." << endl;
        cout << endl;
    }
}
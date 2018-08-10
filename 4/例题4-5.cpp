#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
 
const int MAX = 10000;
int r,c,n;
struct cmd
{
    string s;
    int A,a[20];
    int r1,c1,r2,c2;
}cmds[MAX];
 
void save(string str, int i)
{
    int A;
    if(str!="EX"){
        cin>>A;
        cmds[i].s = str; cmds[i].A = A;
        for(int j=0;j<A;j++) cin>>cmds[i].a[j];
    }
    else if(str=="EX"){
        cmds[i].s = str;
        cin>>cmds[i].r1>>cmds[i].c1>>cmds[i].r2>>cmds[i].c2;
    }
}
 
bool solve(int& x, int& y)
{
    int xx,yy;
    for(int i=0;i<n;i++)
    {
        if(cmds[i].s=="DR"){
            xx = x; yy = y;
            for(int j=0;j<cmds[i].A;j++){
                if(cmds[i].a[j]<xx) { x--; }
                else if(cmds[i].a[j]==xx) { return false;}
            }
        }
        else if(cmds[i].s=="DC"){
            xx = x; yy = y;
            for(int j=0;j<cmds[i].A;j++){
                if(cmds[i].a[j]<yy)  {  y--;}
                else if(cmds[i].a[j]==yy) { return false;}
            }
        }
        else if(cmds[i].s=="IC"){
            xx = x; yy = y;
            for(int j=0;j<cmds[i].A;j++){
                if(cmds[i].a[j]<=yy) y++;
            }
        }
        else if(cmds[i].s=="IR"){
            xx = x; yy = y;
            for(int j=0;j<cmds[i].A;j++){
                if(cmds[i].a[j]<=xx)  x++;
            }
        }
        else if(cmds[i].s=="EX"){
            if(x==cmds[i].r1&&y==cmds[i].c1) { x = cmds[i].r2; y =cmds[i].c2;}
            else if(x==cmds[i].r2&&y==cmds[i].c2) { x = cmds[i].r1; y =cmds[i].c1;}
        }
    }
    return true;
}
 
int main()
{
    int icase = 0;
    while(cin>>r>>c)
    {
        if(r==0&&c==0) break;
        cin>>n;
        if(icase>0) cout<<endl;
        for(int i=0;i<n;i++)
        {
            string str; cin>>str;
            save(str,i);
        }
        cout<<"Spreadsheet #"<<++icase<<endl;
        int q; cin>>q;
        while(q--)
        {
            int x,y,xx,yy;
            cin>>x>>y; xx = x; yy = y;
            if(solve(x,y)) printf("Cell data in (%d,%d) moved to (%d,%d)\n",xx,yy,x,y);
            else printf("Cell data in (%d,%d) GONE\n",xx,yy);
        }
    }
    return 0;
}
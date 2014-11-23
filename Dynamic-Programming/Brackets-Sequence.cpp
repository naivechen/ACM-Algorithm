// http://poj.org/problem?id=1141


#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <cassert>
#include <set>
using namespace std;
#define LL long long
#define L(u) (u<<1)
#define R(u) (u<<1|1)
#define pii pair<int,int>
#define mpair make_pair
const int N=300;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
int d[N][N];
int pos[N][N];
char s[N];  //接受初始数据
void Match(int len)
{
    int i,j,k;
    for(i=0;i<len;i++)
        d[i][i]=1;
    for(k=1;k<len;k++)   //表示i和j之间的间隔
        for(i=0;i<len-k;i++)
        {
            char right=s[i+k];
            char left=s[i];
            d[i][i+k]=inf;  //此条语句不能少，假如下面的if不执行，则for中判断就会出错d[i][i+k]未赋值
            if(left=='('&&right==')'||left=='['&&right==']')
            {
                d[i][i+k]=d[i+1][i+k-1];
                pos[i][i+k]=-1;
            }
            for(j=i;j<i+k;j++) //靠左分界
                if(d[i][i+k]>d[i][j]+d[j+1][i+k])
                {
                    pos[i][i+k]=j;
                    d[i][i+k]=d[i][j]+d[j+1][i+k];
                }
        }
}
void show(int i,int j)
{
    if(i>j)  return;
    if(i==j)
    {
        if(s[i]=='('||s[i]==')') cout<<"()";
        else      cout<<"[]";
    }
    else
    {
        if(pos[i][j]==-1)
        {
            cout<<s[i];
            show(i+1,j-1);
            cout<<s[j];
        }
        else
        {
            show(i,pos[i][j]);
            show(pos[i][j]+1,j);
        }
    }
}
int main()
{
    cin>>s;
    int len=strlen(s);
    Match(len);
    show(0,len-1);
    cout<<endl;
    return 0;
}

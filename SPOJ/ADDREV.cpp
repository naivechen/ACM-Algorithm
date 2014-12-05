// http://www.spoj.com/problems/ADDREV/


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
const int maxn=210;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
string add(string s1,string s2)
{
    string ret="";
    int flag=0;
    int len1=s1.length(),len2=s2.length();
    int i=0,j=0;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    while(i<len1 && j<len2)
    {
        flag+=(s1[i]-'0')+(s2[j]-'0');
        ret+=char(flag%10+'0');
        flag/=10;
        i++;j++;
    }
    while(i<len1)
    {
        flag+=(s1[i]-'0');
        ret+=char(flag%10+'0');
        flag/=10;
        i++;
    }
    while(j<len2)
    {
        flag+=(s2[j]-'0');
        ret+=char(flag%10+'0');
        flag/=10;
        j++;
    }
    if(flag) ret+=char(flag+'0');
    reverse(ret.begin(),ret.end());
    return ret;
}
string domul(string s1, char s2)
{
    int b=s2-'0';
    string ret="";
    reverse(s1.begin(),s1.end());
    int len1=s1.length(),flag=0;
    for(int i=0;i<len1;i++)
    {
        int a=s1[i]-'0';
        flag+=a*b;
        ret+=char(flag%10+'0');
        flag/=10;
    }
    if(flag) ret+=char(flag+'0');
    reverse(ret.begin(),ret.end());
    return ret;
}
string mul(string s1, string s2)
{
    if(s1=="0" || s2=="0") return "0";
    if(s1.length()<s2.length())
    {
        string tmp=s1;
        s1=s2;
        s2=tmp;
    }
    reverse(s2.begin(),s2.end());
    string ans="";
    for(int i=0;i<s2.length();i++)
    {
        string ss=domul(s1,s2[i]);
        for(int j=0;j<i;j++)
            ss+=char('0');
        ans=add(ans,ss);
    }
    return ans;
}
bool cmp(string s1,string s2)
{
    // s1 < s2 , return true
    if(s1.length()<s2.length()) return true;
    if(s1.length()>s2.length()) return false;
    int len=s1.length();
    for(int i=0;i<len;i++)
    {
        if(s1[i]<s2[i]) return true;
        if(s1[i]>s2[i]) return false;
    }
}
string dosub(string s1,char s2,int pos)
{
    string ans=s1;
    reverse(ans.begin(),ans.end());
    {
        int val=ans[pos]-'0';
        if(ans[pos]<s2)
        {
            for(int j=pos+1;j<ans.length();j++)
            {
                if(ans[j]!='0')
                {
                    ans[j]=ans[j]-1;
                    for(int k=j-1;k>pos;k--)
                    {
                       ans[k]='9';
                    }
                    break;
                }
            }
            val+=10;
        }
        val=val-(s2-'0');
        ans[pos]=char(val+'0');
    }
    reverse(ans.begin(),ans.end());
    int i=0;
    while(ans[i]=='0') i++;
    ans=ans.substr(i);
    return ans;
}
string sub(string s1,string s2)
{
    if(s1==s2) return 0;
    bool flag=cmp(s1,s2);
    if(flag)
    {
        string tmp=s1;
        s1=s2;
        s2=tmp;
    }
    reverse(s2.begin(),s2.end());
    string ans=s1;
    for(int i=0;i<s2.length();i++)
        ans=dosub(ans,s2[i],i);
    if(flag) ans=char('-')+ans;
    return ans;
}
int main()
{
    string s1,s2;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        string ans=add(s1,s2);
        reverse(ans.begin(),ans.end());
        int i=0;
        while(ans[i]=='0') i++;
        ans=ans.substr(i);
        cout<<ans<<endl;
    }
}

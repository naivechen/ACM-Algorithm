// http://codeforces.com/contest/483/problem/D

#pragma comment(liner, "/STACK:1024000000,1024000000")
#include <cstdlib>
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
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define LL long long int
#define L(u) (u<<1)
#define R(u) (u<<1|1)
#define pii pair<int,int>
#define mpair make_pair
const int maxn=200110;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------
struct Tree
{
    int left,right;
    int lazy;
    int sum;
}tree[maxn<<2];
int le[maxn],ri[maxn],val[maxn];
int n,m;
void build(int u,int left,int right)
{
    tree[u].left=left;
    tree[u].right=right;
    tree[u].lazy=tree[u].sum=0;
    if(left==right) return ;
    int mid=(left+right)>>1;
    build(L(u),left,mid);
    build(R(u),mid+1,right);
}
void pushdown(int u,int left,int right)
{
    if(!tree[u].lazy) return ;
    tree[L(u)].lazy |= tree[u].lazy;
    tree[R(u)].lazy |= tree[u].lazy;
    tree[L(u)].sum |= tree[u].lazy;
    tree[R(u)].sum |= tree[u].lazy;
    tree[u].lazy=0;
}
void pushup(int u)
{
    tree[u].sum = tree[L(u)].sum & tree[R(u)].sum;
}
void update(int u,int ql,int qr,int val)
{
    if(ql<=tree[u].left && tree[u].right<=qr)
    {
        tree[u].sum |= val;
        tree[u].lazy |= val;
        return;
    }
    pushdown(u,tree[u].left,tree[u].right);  // make the two son get the value from father
    int mid=(tree[u].left+tree[u].right)>>1;
    if(ql>mid) update(R(u),ql,qr,val);
    else if(qr<=mid) update(L(u),ql,qr,val);
    else update(L(u),ql,mid,val),update(R(u),mid+1,qr,val);
    pushup(u);
}
int query(int u,int ql,int qr)
{
    if(ql<=tree[u].left && tree[u].right<=qr)
        return tree[u].sum;
    int mid=(tree[u].left+tree[u].right)>>1;
    if(ql>mid) return query(R(u),ql,qr);
    else if(qr<=mid) return query(L(u),ql,qr);
    else return query(L(u),ql,mid) & query(R(u),mid+1,qr);
}
int num=0;
void print(int u,int left,int right)
{
    if(left==right)
    {
        if(num==1) cout<<" ";
        else num=1;
        cout<<tree[u].sum;
        return ;
    }
    pushdown(u,tree[u].left,tree[u].right);
    int mid=(left+right)>>1;
    print(L(u),left,mid);
    print(R(u),mid+1,right);
}
int main()
{
    cin>>n>>m;
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        cin>>le[i]>>ri[i]>>val[i];
        update(1,le[i],ri[i],val[i]);
    }
    int flag=1;
    for(int i=1;i<=m;i++)
    {
        if(query(1,le[i],ri[i])!=val[i])
        {
            flag=0;
            break;
        }
    }
    if(flag)
    {
        cout<<"YES"<<endl;
        print(1,1,n);
        cout<<endl;
    }
    else cout<<"NO"<<endl;
}

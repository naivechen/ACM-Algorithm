// http://poj.org/problem?id=2796


#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<iomanip>
using namespace std;
const int maxn=100001;
int lleft[maxn],rright[maxn];
long long int sum[maxn];
long long int a[maxn];
int n;
int main()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        memset(rright,0,sizeof(rright));
        memset(lleft,0,sizeof(lleft));
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            sum[i]=sum[i-1]+a[i];
            lleft[i]=rright[i]=i;
        }
        for(int i=2;i<=n;i++)
            while(lleft[i]>1 && a[lleft[i]-1]>=a[i])
                lleft[i]=lleft[lleft[i]-1];
        for(int i=n-1;i>=1;i--)
            while(rright[i]<n && a[rright[i]+1]>=a[i])
                rright[i]=rright[rright[i]+1];
        long long int ans=-1,ssum=0;
        int p1,p2;
        for(int i=1;i<=n;i++)
        {
            ssum=(sum[rright[i]]-sum[lleft[i]-1])*a[i];
            if(ssum>ans)
            {
                ans=ssum;
                p1=lleft[i];
                p2=rright[i];
            }
        }
        printf("%lld\n",ans);
        printf("%d %d\n",p1,p2);
    }
}




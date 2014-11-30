// http://acm.hdu.edu.cn/showproblem.php?pid=1026


#include<stdio.h>
#include<queue>
#define maxn 101
using namespace std;
int m,n;
int dir[4][2]={1,0,-1,0,0,-1,0,1};
struct node
{
    int x,y,time;
    friend int operator<(node a,node b)
    {
        return a.time>b.time;
    }
};
struct cmap
{
    char c;
    int nx,ny;
}map[maxn][maxn];
int fight[maxn][maxn],vis[maxn][maxn];
priority_queue<node>q;
int bfs()
{
    node now,next;
    int i;
    char s;
    while(!q.empty())q.pop();
    now.x=n-1;now.y=m-1;
    s=map[now.x][now.y].c;
    if(s>='1'&&s<='9')
    {
        now.time=map[now.x][now.y].c-'0';
        fight[now.x][now.y]=map[now.x][now.y].c-'0';
    }
    else now.time=0;
    q.push(now);
    while(!q.empty())
    {
        now=q.top();q.pop();
        if(now.x==0&&now.y==0)return now.time;
        for(i=0;i<4;i++)
        {
            next.x=now.x+dir[i][0];
            next.y=now.y+dir[i][1];
            if(next.x>=0&&next.x<n&&next.y>=0&&next.y<m&&map[next.x][next.y].c!='X'&&!vis[next.x][next.y])
            {
                 vis[next.x][next.y]=1;
                 s=map[next.x][next.y].c;
                 if(s>='1'&&s<='9')
                 {
                     fight[next.x][next.y]=s-'0';
                     next.time=now.time+s-'0'+1;
                 }
                 else next.time=now.time+1;
                 map[next.x][next.y].nx=now.x;
                 map[next.x][next.y].ny=now.y;
                 q.push(next);
            }
        }
    }
    return -1;
}
int main()
{
    int i,j;
    //freopen("int.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        getchar();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%c",&map[i][j].c);
            }
            getchar();
        }
        memset(vis,0,sizeof(vis));
        memset(fight,0,sizeof(fight));
        int ans=bfs();
        if(ans==-1)printf("God please help our poor hero.\n");
        else
        {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);
            int cnt=1,x=0,y=0;
            while(cnt<=ans)
            {
                int fx=map[x][y].nx,fy=map[x][y].ny;
                printf("%ds:(%d,%d)->(%d,%d)\n",cnt++,x,y,fx,fy);
                for(int j=1;j<=fight[fx][fy];j++)
                printf("%ds:FIGHT AT (%d,%d)\n",cnt++,fx,fy);
                x=fx;y=fy;
            }
        }
        printf("FINISH\n");
    }
    return 0;
}

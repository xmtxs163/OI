#include<bits/stdc++.h>
#define POW(x) ((x)*(x))
using namespace std;
const int N=1e3+5;
const double INF=1e15;
int n,Ans[N],st,Ans2[N],vis[N],a[N],bj[N];
double ans,maxy,ans2;
struct Point
{
	double x,y;	
}po[N];
vector<int>jl[N];
double js(double x1,double y1,double x2,double y2)
{
	return sqrt(POW(x1-x2)+POW(y1-y2));
}
void dfs(int x)
{
	if(x>n)
	{
		double tmp=0;
		for(int i=1;i<n;++i)
			tmp=tmp+js(po[a[i]].x,po[a[i]].y,po[a[i+1]].x,po[a[i+1]].y);
		if(tmp<ans)
		{
			ans=tmp;
			for(int i=1;i<=n;++i)
				Ans[i]=a[i];
		}
		return ;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i])
			vis[i]=1,a[x]=i,dfs(x+1),vis[i]=0;
}
void slove1()
{
	a[1]=st,vis[st]=1,ans=INF;
	dfs(2);
	for(int i=1;i<=n;++i)
		printf("%d ",Ans[i]);
}
int main()
{
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	maxy=-INF;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lf%lf",&po[i].x,&po[i].y);
		if(po[i].y>maxy)	st=i,maxy=po[i].y;
	}
	if(n<=9)
		slove1();
	else
	{
		ans=0;
		for(int i=1;i<n;++i)
			ans=ans+js(po[i].x,po[i].y,po[i+1].x,po[i+1].y);
		int nxt=0,lst=0;
		for(int ll=1;ll<=n;++ll)
		{
			Ans2[ll]=st,bj[st]=1;
			if(ll==n)
				break;
			double mindis=INF,dis;
			for(int i=1;i<=n;++i)
			{
				dis=js(po[st].x,po[st].y,po[i].x,po[i].y);
				if(st!=i&&i!=lst&&bj[i]==0&&dis<mindis)
				{
					mindis=dis;
					nxt=i;
				}
			}
			lst=st,st=nxt,ans2+=mindis;
		}
		if(ans2<ans)
			for(int i=1;i<=n;++i)
				printf("%d ",Ans2[i]);
		else
			for(int i=1;i<=n;++i)
				printf("%d ",i);
	}
	return 0;
}

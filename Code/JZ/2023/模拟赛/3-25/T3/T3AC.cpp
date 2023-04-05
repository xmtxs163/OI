#include<bits/stdc++.h>
#define Pow(x)	x*x
using namespace std;
const int N=1e3+5;
const double INF=1e9+5;
int n,g[N][N][2],ansl,ansr,ansid,st,lid[N],rid[N];
double f[N][N][2];
struct Point
{
	double x,y;	
}a[N];
double dis(int x,int y)
{
	return	sqrt(Pow((a[x].x-a[y].x))+Pow((a[x].y-a[y].y)));
}
void Print(int l,int r,int id)
{
	if(id==-1||g[l][r][id]==-1)
	{
		printf("%d ",st);
		return ;
	}
	if(id==1)	Print(l-1,r,g[l][r][id]),printf("%d ",lid[l]);
	else Print(l,r-1,g[l][r][id]),printf("%d ",rid[r]);
}
int main()
{
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	st=0,a[0].y=-INF;
	for(int i=1;i<=n;++i)
		if(a[i].y>a[st].y)
			st=i;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			f[i][j][0]=f[i][j][1]=INF,g[i][j][0]=g[i][j][1]=-1;
	f[0][0][1]=f[0][0][0]=0;
	for(int i=st+1,j=1;j<=n-1;++j,++i)
	{
		if(i>n)	i=1;
		lid[j]=i;
	}
	for(int i=st-1,j=1;j<=n-1;++j,i--)
	{
		if(i==0)	i=n;
		rid[j]=i;
	}
	lid[0]=rid[0]=st;
	for(int len=1;len<n;++len)
	{
		for(int l=0,r;l<=len;++l)
		{
			r=len-l;
			double tmp;
			if(l!=0)
			{
				tmp=f[l-1][r][1]+dis(lid[l],lid[l-1]);
				if(f[l][r][1]>tmp)
					f[l][r][1]=tmp,g[l][r][1]=1;
				tmp=f[l-1][r][0]+dis(lid[l],rid[r]);
				if(f[l][r][1]>tmp)
					f[l][r][1]=tmp,g[l][r][1]=0;
			}
			if(r!=0)
			{
				tmp=f[l][r-1][0]+dis(rid[r],rid[r-1]);
				if(f[l][r][0]>tmp)
					f[l][r][0]=tmp,g[l][r][0]=0;
				tmp=f[l][r-1][1]+dis(rid[r],lid[l]);
				if(f[l][r][0]>tmp)
					f[l][r][0]=tmp,g[l][r][0]=1;	
			}
		}
	}
	ansl=ansr=n+1,ansid=1,f[n+1][n+1][1]=INF;
	for(int l=0,r;l<n;++l)
	{
		r=n-l-1;
		if(f[l][r][0]<f[ansl][ansr][ansid])
			ansl=l,ansr=r,ansid=0;
		if(f[l][r][1]<f[ansl][ansr][ansid])
			ansl=l,ansr=r,ansid=1;
	}
	Print(ansl,ansr,ansid);
	return 0;
}

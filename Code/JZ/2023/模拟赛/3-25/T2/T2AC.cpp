#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const double INF=1e18+5;
LL n,K,f[200],g[200],Ans;
LL Pow(LL x,LL y)
{
	LL tmp=1;
	double cnt=1;
	for(int i=1;i<=y;++i)
	{
		if(cnt*x>=INF)
			return -1;
		cnt=cnt*x,tmp=tmp*x;
	}
	return tmp;
}
LL FIND(LL x,LL y)
{
	LL l=1,r=x,mid,tmp,ans=0;
	while(l<=r)
	{
		mid=(l+r)/2,tmp=Pow(mid,y);
		if(tmp==x)
			return tmp;
		else if(tmp>x||tmp==-1)
			r=mid-1;
		else	ans=mid,l=mid+1;
	}
	return ans;
}
int main()
{
//	freopen("power.in","r",stdin);
//	freopen("power.out","w",stdout);
	scanf("%lld%lld",&n,&K);
	for(int i=1;i<=64;++i)
		g[i]=FIND(n,i)-1;
	for(int i=64;i>=1;i--)
	{
		f[i]=g[i];
		for(int j=2;i*j<=64;++j)
			f[i]-=f[i*j];
	}
//	for(int i=1;i<=64;++i)
//		printf("%d %d\n",i,f[i]);
	for(int i=K;i<=64;++i)
		Ans+=f[i];
	printf("%lld",Ans+1);
	return 0;	
} 

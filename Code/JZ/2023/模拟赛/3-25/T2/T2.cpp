#include<bits/stdc++.h>
#define LL long long 
using namespace std;
LL n,K,Ans,jtmp;
LL ksm(LL x,LL y)
{
	jtmp=1;
	while(y!=0)
	{
		if(y%2)	jtmp=jtmp*x;
		x*=x,y/=2;
	}
	return jtmp;
}
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	scanf("%lld%lld",&n,&K);
	for(LL i=1,j,tmp,l,r,rr,mid,ans,val;i<=n;++i)
	{
		j=1,tmp=1ll*(1<<j),rr=sqrt(i)+1,ans=1;
		while(tmp<=i)
		{
			l=1,r=rr;
			while(l<=r)
			{
				mid=(l+r)/2,val=ksm(mid,j);
				if(val==i)
				{
					ans=j;
					break;
				}
				else if(val<i)
					l=mid+1;
				else	r=mid-1;
			}
			tmp=1ll*(1<<++j);
		}
		if(ans<K)
			Ans++;
	}
	if(K!=1)
		printf("%lld",n-Ans+1);
	else
		printf("%lld",n-Ans);
	return 0;
}

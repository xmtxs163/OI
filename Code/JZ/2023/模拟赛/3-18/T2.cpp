#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int N=16+5;
LL a,b,tmp[N],s,ansa,ansb,f[N][200][3],sans,jl[N];
LL slove1(LL x)
{
	int n=0;
	LL ans=0;
	memset(f,0,sizeof(f));
	while(x!=0)
		tmp[++n]=x%10,x/=10;
	for(int j=1;j<=n/2;++j)
		swap(tmp[j],tmp[n-j+1]);
	for(int j=0;j<tmp[1];++j)
		f[1][j][1]=1;
	f[1][tmp[1]][0]=1;
	for(int i=1,sum=0;i<n;++i)
	{
		sum+=tmp[i];
		for(int j=0;j<=s;++j)
		{
			if(j==sum)
			{
				for(int k=0;k<tmp[i+1];++k)
					f[i+1][j+k][1]+=f[i][j][0];
				f[i+1][j+tmp[i+1]][0]+=f[i][j][0];	
			}
			for(int k=0;k<=9;++k)
				f[i+1][j+k][1]+=f[i][j][1];
		}
	}
	ans=ans+f[n][s][0]+f[n][s][1];
	return ans;
}
LL slove2()
{
	LL tmp=a;
	int sum=0,tot=0,ssum;
	while(tmp!=0)	sum+=(jl[++tot]=tmp%10),tmp/=10;
	ssum=sum=s-sum;
	for(int i=1;i<=tot;++i)
	{
		if(sum>9-jl[i])	sum-=(9-jl[i]),jl[i]=9;
		else
		{
			jl[i]=jl[i]+sum,sum=0;
			break;
		}
	}
	while(sum>0)
	{
		sum=ssum;
		for(int i=1;i<=tot;++i)	jl[i]=0;
		jl[++tot]=1;
		for(int i=1;i<=tot;++i)
		{
			if(sum>9-jl[i])	sum-=(9-jl[i]),jl[i]=9;
			else
			{
				jl[i]=jl[i]+sum,sum=0;
				break;
			}
		}
	}
	for(int i=tot;i>=1;i--)
		printf("%d",jl[i]);
}
int main()
{
	scanf("%lld%lld%lld",&a,&b,&s);
	ansa=slove1(a-1),ansb=slove1(b);
	printf("%lld\n",ansb-ansa),slove2();
	return 0;
}

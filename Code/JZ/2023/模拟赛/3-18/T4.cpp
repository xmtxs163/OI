#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int N=2*1e5+5,M=1e4+5,INF=1e9;
namespace segtr
{
	struct Tree
	{
		LL mx,mn;
		int num;	
	}tr[M*4];
	void Init(int x,int l,int r)
	{
		if(l>r)	return ;
		tr[x].mx=-INF,tr[x].mn=INF,tr[x].num=0;
		if(l==r) return ;
		int mid=(l+r)/2;
		Init(x*2,l,mid),Init(x*2+1,mid+1,r);
	}
	void updata(int x,int l,int r,int ql,int qr,LL val)
	{
		if(l>r||l>qr||r<ql)	return ;
		if(ql<=l&&r<=qr)
		{
			if(tr[x].mx==-INF)
				tr[x].mx=tr[x].mn=val;
			tr[x].num++;
			return ;
		}
		int mid=(l+r)/2;
		if(ql<=mid)	updata(x*2,l,mid,ql,qr,val);
		if(mid<qr)	updata(x*2+1,mid+1,r,ql,qr,val);
		tr[x].mx=max(tr[x*2].mx,tr[x*2+1].mx),tr[x].mn=min(tr[x*2].mn,tr[x*2+1].mn);
		if(tr[x].mx==tr[x*2].mx)	tr[x].num=tr[x*2].num;
		else	tr[x].num=tr[x*2+1].num;
	}
	void del(int x,int l,int r,int ql,int qr)
	{
		if(l>r||l>qr||r<ql)	return ;
		if(ql<=l&&r<=qr)
		{
			tr[x].num--;
			return ;
		}
		int mid=(l+r)/2;
		if(ql<=mid)	del(x*2,l,mid,ql,qr);
		if(mid<qr)	del(x*2+1,mid+1,r,ql,qr);
		if(tr[x].mx==tr[x*2].mx)
		{
			if(tr[x*2].num==0)	tr[x]=tr[x*2+1];
			else	tr[x]=tr[x*2];
		}
		else
		{
			if(tr[x*2+1].num==0)	tr[x]=tr[x*2];
			else	tr[x]=tr[x*2+1];
		}
	}
	void qry(int x,int l,int r,int ql,int qr,LL& nans)
	{
		if(l>r||l>qr||r<ql)	return ;
		if(ql<=l&&r<=qr)
		{
			if(tr[x].num!=0)
				nans=max(nans,tr[x].mx);
			return ;
		}
		int mid=(l+r)/2;
		if(ql<=mid)	qry(x*2,l,mid,ql,qr,nans);
		if(mid<qr)	qry(x*2+1,mid+1,r,ql,qr,nans);
	}
}
struct Data
{
	LL out,in,b;
	bool operator < (const Data& xx)const
	{
		return b>xx.b;	
	}
}da[N];
int n;
LL ans,m;
int main()
{
	freopen("doll.in","r",stdin);
	freopen("doll.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld%lld%lld",&da[i].out,&da[i].in,&da[i].b),ans=ans+da[i].in*da[i].b,m=max(m,da[i].out);
	segtr::Init(1,1,m);
	for(int i=1;i<=n;++i)
		segtr::updata(1,1,m,da[i].out,da[i].out,da[i].out);
	sort(da+1,da+n+1);
	LL pre;
	for(int i=1;i<=n;++i)
	{
		pre=-INF,segtr::qry(1,1,m,1,da[i].in-1,pre);
		if(pre!=-INF)
			ans=ans-da[i].b*pre,segtr::del(1,1,m,pre,pre);
	}
	printf("%lld",ans);
	return 0;
}

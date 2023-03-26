#include<bits/stdc++.h>
#define Yes printf("Yes\n")
using namespace std;
const int N=3*1e4+5,INF=1e9;
int n,dfn[N],son[N],dep[N],top[N],fa[N],hd[N],siz[N],to[N*2],nxt[N*2],val[N],rnk[N],tot,nwdfn,ansmax,anssum,Q;
char ch[10];
void add(int u,int v)
{
	to[++tot]=v,nxt[tot]=hd[u],hd[u]=tot;
}
void dfs1(int x,int fath)
{
	fa[x]=fath,siz[x]=1,dep[x]=dep[fath]+1;
	for(int i=hd[x];i;i=nxt[i])
	{
		if(to[i]!=fath)
		{
			dfs1(to[i],x);
			if(siz[to[i]]>siz[son[x]])
				son[x]=to[i];
			siz[x]+=siz[to[i]];
		}
	}
}
void dfs2(int x,int Top)
{
	top[x]=Top,dfn[x]=++nwdfn;
	if(son[x]!=0)
		dfs2(son[x],Top);
	for(int i=hd[x];i;i=nxt[i])
		if(to[i]!=fa[x]&&to[i]!=son[x])
			dfs2(to[i],to[i]);
}
namespace sgtr
{
	struct Point
	{
		int maxn,sum;
	}tr[N*4];
	void pushup(int& x)
	{
		tr[x].maxn=max(tr[x*2].maxn,tr[x*2+1].maxn),tr[x].sum=tr[x*2].sum+tr[x*2+1].sum;
	}
	void INIT(int x,int l,int r)
	{
		if(l>r)	return ;
		if(l==r)
		{
			tr[x].maxn=tr[x].sum=val[rnk[l]];
			return ;
		}
		int mid=(l+r)/2;
		INIT(x*2,l,mid),INIT(x*2+1,mid+1,r);
		pushup(x);
	}
	void updata(int x,int l,int r,int& qq,int val)
	{
		if(l>r||l>qq||r<qq)	return ;
		if(l==qq&&r==qq)
		{
			tr[x].maxn=tr[x].sum=val;
			return ;
		}
		int mid=(l+r)/2;
		if(qq<=mid)	updata(x*2,l,mid,qq,val);
		if(mid<qq)	updata(x*2+1,mid+1,r,qq,val);
		pushup(x);
	}
	void qrymax(int x,int l,int r,int& ql,int& qr,int& ans)
	{
		if(l>r||l>qr||r<ql)	return ;
		if(ql<=l&&r<=qr)
		{
			ans=max(ans,tr[x].maxn);
			return ;
		}
		int mid=(l+r)/2;
		if(ql<=mid)	qrymax(x*2,l,mid,ql,qr,ans);
		if(mid<qr)	qrymax(x*2+1,mid+1,r,ql,qr,ans);
	}
	void qrysum(int x,int l,int r,int& ql,int& qr,int& ans)
	{
		if(l>r||l>qr||r<ql)	return ;
		if(ql<=l&&r<=qr)
		{
			ans+=tr[x].sum;
			return ;
		}
		int mid=(l+r)/2;
		if(ql<=mid)	qrysum(x*2,l,mid,ql,qr,ans);
		if(mid<qr)	qrysum(x*2+1,mid+1,r,ql,qr,ans);
	}
}
void change(int u,int val)
{
	sgtr::updata(1,1,n,dfn[u],val);
}
int qmax(int u,int v)
{
	ansmax=-INF;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]>dep[top[v]])
			sgtr::qrymax(1,1,n,dfn[top[u]],dfn[u],ansmax),u=fa[top[u]];
		else
			sgtr::qrymax(1,1,n,dfn[top[v]],dfn[v],ansmax),v=fa[top[v]];
	}
	if(dep[u]<dep[v])	sgtr::qrymax(1,1,n,dfn[u],dfn[v],ansmax);
	else	sgtr::qrymax(1,1,n,dfn[v],dfn[u],ansmax);
	return ansmax;
}
int qsum(int u,int v)
{
	anssum=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]>dep[top[v]])
			sgtr::qrysum(1,1,n,dfn[top[u]],dfn[u],anssum),u=fa[top[u]];
		else
			sgtr::qrysum(1,1,n,dfn[top[v]],dfn[v],anssum),v=fa[top[v]];
	}
	if(dep[u]<dep[v])	sgtr::qrysum(1,1,n,dfn[u],dfn[v],anssum);
	else	sgtr::qrysum(1,1,n,dfn[v],dfn[u],anssum);
	return anssum;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),add(u,v),add(v,u);
	for(int i=1;i<=n;++i)
		scanf("%d",&val[i]);
	dfs1(1,0),dfs2(1,1);
	for(int i=1;i<=n;++i)
		rnk[dfn[i]]=i/*,printf("%d %d\n",i,dfn[i])*/;
	sgtr::INIT(1,1,n);
	int l,r;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%s%d%d",ch+1,&l,&r);
		if(ch[1]=='C')
			change(l,r);
		else if(ch[1]=='Q'&&ch[2]=='M')
			printf("%d\n",qmax(l,r));
		else if(ch[1]=='Q'&&ch[2]=='S')
			printf("%d\n",qsum(l,r));
	}
	return 0;	
}
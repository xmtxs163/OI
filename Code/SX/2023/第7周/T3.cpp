#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],st[N],ed[N],tot,len[N],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	st[1]=tot=1,a[n+1]=a[n],len[1]=1;
	for(int i=2;i<=n+1;++i)
	{
		if(a[i]!=a[i-1])	len[tot]++;
		else	ed[tot]=i-1,st[++tot]=i,len[tot]=1;
	}
	len[tot]=0,tot--;
	for(int i=1;i<=tot;++i)
		ans=max(ans,len[i]);
	for(int i=1;i<=tot;++i)
		ans=max(ans,len[i]+len[i-1]+len[i+1])/*,printf("%d %d %d\n",st[i],ed[i],len[i])*/;
	printf("%d",ans);
}

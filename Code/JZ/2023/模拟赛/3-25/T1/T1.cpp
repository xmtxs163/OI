#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,q,n,m;
struct DATA
{
	int id,col;	
}vis1[N],vis2[N];
void Init()
{
	for(int i=1;i<=n;++i)
		vis1[i].id=vis1[i].col=0;
	for(int i=1;i<=m;++i)
		vis2[i].id=vis2[i].col=0;
}
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		Init();
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1,op,xx,col;i<=q;++i)
		{
			scanf("%d%d%d",&op,&xx,&col);
			if(op==1)
				vis2[xx].id=i,vis2[xx].col=col;
			else
				vis1[xx].id=i,vis1[xx].col=col;
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(vis1[i].id>vis2[j].id)	printf("%d ",vis1[i].col);
				else	printf("%d ",vis2[j].col);
			}
			printf("\n");
		}
	}
	return 0;
}

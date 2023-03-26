#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,q,T;
vector<int>ve[N];
int main()
{
	freopen("paint.in","r",stdin);
	freopen("ans.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=n;++i)
			ve[i].clear();
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;++i)
			for(int j=0;j<=m;++j)
				ve[i].push_back(0);
		for(int i=1,op,xx,col;i<=q;++i)
		{
			scanf("%d%d%d",&op,&xx,&col);
			if(op==0)
				for(int j=1;j<=m;++j)
					ve[xx][j]=col;
			else
				for(int j=1;j<=n;++j)
					ve[j][xx]=col;
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
				printf("%d ",ve[i][j]);
			printf("\n");	
		}	
	}
	return 0;
}

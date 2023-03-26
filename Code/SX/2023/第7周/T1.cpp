#include<bits/stdc++.h>
using namespace std;
const int N=41;
int n,ans[N][N];
int main()
{
	scanf("%d",&n);
	int x=1,y=n/2+1;
	ans[x][y]=1;
	for(int i=2;i<=n*n;++i)
	{
		if(x==1&&y!=n)	x=n,y+=1;
		else if(x!=1&&y==n)	x-=1,y=1;
		else if(x==1&&y==n)	x+=1;
		else
		{
			if(ans[x-1][y+1]==0)	x-=1,y+=1;
			else	x+=1;	
		}
		ans[x][y]=i;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}

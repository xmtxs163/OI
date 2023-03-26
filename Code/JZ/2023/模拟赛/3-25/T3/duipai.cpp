#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N],b[N],tot,pop,n;
int main()
{
	freopen("tree.out","r",stdin);
	while(scanf("%d",&n)!=EOF)
		a[++tot]=n;
	freopen("tree6.ans","r",stdin);
	while(scanf("%d",&n)!=EOF)
		b[++pop]=n;
	for(int i=1;i<=tot;++i)
		if(a[i]!=b[i])
		{
			printf("WA %d %d %d",i,a[i],b[i]);
			return 0;
		}
	printf("AC");
	return 0;
}

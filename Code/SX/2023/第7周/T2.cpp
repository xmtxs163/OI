#include<bits/stdc++.h>
using namespace std;
const int N=100000+5,LEN=20;
int n,m;
struct Data
{
	int fx;
	char s[LEN];
}a[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d%s",&a[i].fx,a[i].s+1);
	int nwfx,num,nw=1;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&nwfx,&num);
		if(a[nw].fx==0)
		{
			if(nwfx==0)	nw=(nw-num+n)%n;
			else	nw=(nw+num)%n;
		}
		else
		{
			if(nwfx==0)	nw=(nw+num)%n;
			else	nw=(nw-num+n)%n;
		}
		if(nw==0)	nw=n;
	}
	printf("%s",a[nw].s+1);
	return 0;
}

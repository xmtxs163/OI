#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const int N=1e7;
int n,tot,a[N],b[N],pop,AC;
int main()
{
	while(1)
	{
		system("DATA.exe");
		system("baoli.exe");
		system("T1.exe");
		tot=pop=0,AC=1;
		freopen("paint.out","r",stdin);
		while((scanf("%d",&n))!=EOF)
			a[++tot]=n;
		freopen("ans.out","r",stdin);
		while((scanf("%d",&n))!=EOF)
			b[++pop]=n;
		for(int i=1;i<=tot;++i)
			if(a[i]!=b[i])
			{
				printf("WA\n");
				AC=0;	
			}
		if(AC)
			printf("AC\n");
		else
			return 0;
	}
}

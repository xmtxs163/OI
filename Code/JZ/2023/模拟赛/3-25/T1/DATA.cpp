#include<bits/stdc++.h>
using namespace std;
void data()
{
	freopen("paint.in","w",stdout);
	printf("10\n");
	for(int pp=1;pp<=10;++pp)
	{
		if(pp%2)
		{
			printf("1000 1000 100000\n");
			for(int i=1,op,xx,col;i<=100000;++i)
			{
				op=rand()%2;
				xx=rand()%1000;
				if(xx==0)	xx=1000;
				col=rand()%5000;
				printf("%d %d %d\n",op,xx,col);
			}
		}
		else
		{
			printf("10000 100 100000\n");
			for(int i=1,op,xx,col;i<=100000;++i)
			{
				op=rand()%2;
				if(op==0)
				{
					xx=rand()%10000;
					if(xx==0)	xx=10000;
				}
				else
				{
					xx=rand()%100;
					if(xx==0)	xx=100;
				}
				col=rand()%5000;
				printf("%d %d %d\n",op,xx,col);
			}
		}
	}
}
int main()
{
	srand(int(time(0)));
	data();
	return 0;
}

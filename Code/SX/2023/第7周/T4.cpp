#include<bits/stdc++.h>
using namespace std;
const int L=100+5;
int T,ans,loc,len[3],tr[3],vis[200],st,ed,trti,tilen,TIME,ANS,top,gxpd[L],pop,lol,lol2,lol3;
char ti[10],id,cct,num[3][10],sta[L];
void Init()
{
	st=ed=trti=tr[1]=tr[2]=len[1]=len[2]=ANS=top=pop=ans=TIME=lol=lol2=lol3=0;
	memset(vis,0,sizeof(vis)),memset(gxpd,0,sizeof(gxpd)),memset(sta,0,sizeof(sta));
}
void Scan()
{
	Init();
	scanf("%d",&loc),scanf("%s",ti+1);
	tilen=strlen(ti+1);
	for(int nwl=1;nwl<=loc;++nwl)
	{
		scanf("%s",&id);
		if(id=='F')
		{
			st++,scanf("%s",&cct);
			scanf("%s%s",num[1]+1,num[2]+1);
			len[1]=strlen(num[1]+1),len[2]=strlen(num[2]+1);
			tr[1]=tr[2]=0;
			if(vis[cct])	ans=2;
			vis[cct]++,sta[++top]=cct;
			if(lol)
			{
				lol2++;
				continue;
			}
			gxpd[++pop]=0;
			for(int i=1;i<=2;++i)
			{
				for(int j=1;j<=len[i];++j)
				{
					if(num[i][j]=='n')	tr[i]=101;
					else	tr[i]=tr[i]*10+num[i][j]-'0';
				}
			}
			if(tr[1]<=tr[2])
			{
				if(tr[1]!=101&&tr[2]==101)
					trti++,gxpd[pop]=1;	
			}
			else
				lol=st,gxpd[pop--]=0,lol2=1;
		}
		else
		{
			ed++;
			if(lol)
			{
				lol3++,vis[sta[top--]]--;
				if(lol2==lol3&&ed<=st)
					lol=lol2=lol3=0;
			}
			else
			{
				if(ed<=st)
					ANS=max(ANS,trti),trti-=gxpd[pop--],vis[sta[top--]]--;	
			}	
		}
	}
	if(st!=ed||ans==2)	ans=2;
	else
	{
		for(int i=1;i<=tilen;++i)
		{
			if(ti[i]=='n')
			{
				for(int j=i+2;j<=tilen;++j)
				{
					if(ti[j]<'0'||ti[j]>'9')	break;
					TIME=TIME*10+ti[j]-'0';
				}
				break;
			}
		}
		if(ANS==TIME)	ans=1;
		else	ans=0;
	}
}
void Print()
{
	if(ans==2)	printf("ERR\n");
	else if(ans==1)	printf("Yes\n");
	else printf("No\n");
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		Scan();
		Print();
	}
	return 0;
}
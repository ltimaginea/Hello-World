#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
struct bign
{
	int d[40000];
	int len;
	bign()
	{
		memset(d,0,sizeof(d));
		len=0;
	}
};
bign change(char str[])
{
	bign c;
	c.len=strlen(str);
	for(int i=c.len-1;i>=0;i--)
	{
		c.d[c.len-1-i]=str[i]-'0';
	}
	return c;
}
bign add(bign a,bign b)
{
	bign c;
	int carry=0,temp;
	for(int i=0;i<a.len ||i<b.len;i++)
	{
		temp=a.d[i]+b.d[i]+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	}
	if(carry!=0) c.d[c.len++]=carry;
	while(c.len>1&&c.d[c.len-1]==0)
	{
		c.len--;
	}
	return c;
}

int cmp(bign a,bign b)
{
	if(a.len>b.len) return 1;
	else if(a.len<b.len) return -1;
	else {
		for(int i=a.len-1;i>=0;i--)
		{
			if(a.d[i]>b.d[i]) return 1;
			else if(a.d[i]<b.d[i]) return-1;
		}
		return 0;
	}
}
bign sub(bign a,bign b)
{
	bign c,tem;
	int s=cmp(a,b);
	if(s==0)
	{
		c.len=1;
		return c;
	}
	else if(s==-1)
	{
		printf("-");
		tem=a;
		a=b;
		b=tem;
	}
	for(int i=0;i<a.len||i<b.len;i++)
	{
		if(a.d[i]<b.d[i]){
			a.d[i+1]--;
			a.d[i]+=10;
		}
		c.d[c.len++]=a.d[i]-b.d[i];
	}
	for(;c.len>1&&c.d[c.len-1]==0;)
	{
		c.len--;
	}
	return c;
}



bign multi(bign a,bign b)
{
	bign t,c;
	int carry=0,temp=0,len=0;
	for(int m=0;m<a.len;m++)
	{
		len=m;carry=0;temp=0;
		memset(t.d,0,sizeof(t.d));
		for(int n=0;n<b.len;n++)
		{
			temp=a.d[m]*b.d[n]+carry;
			t.d[len++]=temp%10;
			carry=temp/10;
		}
		if(carry!=0) t.d[len++]=carry;
		t.len=len;
		c=add(t,c);
	}
	return c;
}
bign divide(bign a,bign b)
{
	bign c;
	c.len=1;
	if(a.len<b.len) return c;
	else if(a.len>b.len)
	{
		bign ss;
		int t=a.len-b.len+1,ra;
		int tt=a.len;int rra=b.len;
		    for(memset(ss.d,0,sizeof(ss.d)),ss.len=tt,ra=tt,rra=b.len;rra>0;ra--,rra--)
			ss.d[ra-1]=b.d[rra-1];
		if(cmp(a,ss)==-1)
		{
			tt--;
			for(memset(ss.d,0,sizeof(ss.d)),ss.len=tt,ra=tt,rra=b.len;rra>0;ra--,rra--)
			ss.d[ra-1]=b.d[rra-1];
	    }
		if(tt==a.len) c.len=t;
		else {c.len=t-1;t=t-1;}	
			
		for(;t>=1;)
		{
		    for(memset(ss.d,0,sizeof(ss.d)),ss.len=tt,ra=tt,rra=b.len;rra>0;ra--,rra--)
			ss.d[ra-1]=b.d[rra-1];
		if(cmp(a,ss)==-1)
		{
			tt--;t--;
			for(memset(ss.d,0,sizeof(ss.d)),ss.len=tt,ra=tt,rra=b.len;rra>0;ra--,rra--)
			ss.d[ra-1]=b.d[rra-1];
		}
		for(int s=cmp(a,ss);s==1||s==0;)
		{
			a=sub(a,ss);
		    c.d[t-1]++;
		    s=cmp(a,ss);
		    if(s==-1) break;
		}
		tt--;t--;
		}
		return c;
    }
	/*  
	//下面的算法只采用减法会超时 
	{
		c.len=1;int i=0;
		for(int s=1;s==1||s==0;s=cmp(a,b))
		{
			i=0;
			if(c.d[i]<9) ++c.d[i];
			else {
				c.d[i]=0;
				for(i++;;i++)
				{
					if((1+c.d[i])<=9) 
					{
						c.d[i]++;
						break;
					}
					else c.d[i]=0;
				}
			}
			if(c.len==i) c.len++;
			a=sub(a,b);
		}
		return c;
		 
	}*/ 
	else {
		int s=cmp(a,b);
		if(s==0) {
			c.d[0]=1;
			c.len=1;
			return c;
		}
		else if(s==-1) return c;
		else
		{
			c.len=1;
			for(;s==1||s==0;s=cmp(a,b))
			{
				c.d[0]++;
				a=sub(a,b);
			}
			return c;
		}
	}
}

void print(bign c)
{
	for(int i=c.len-1;i>=0;i--)
	{
		printf("%d",c.d[i]);
	}
	return;
}


int main()
{
	char str1[40000],str2[40000],o;
	bign a,b,c;
	scanf("%s\n",str1);
	scanf("%c",&o);
	scanf("%s",str2);
	a=change(str1);
	b=change(str2);
	switch(o)
	{
		case '+' :c=add(a,b);break;
		case '-' :c=sub(a,b);break;
		case '*' :c=multi(a,b);break;
		case '/' :c=divide(a,b);
	}
	print(c);
	printf("\n");
	return 0;
}

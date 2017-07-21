#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct data{
	int num;
	int time;
} Data;
const int MAX=100001;
Data array[MAX];
//char tmp[8];//保存临时字符串
int intoint(const char *s)//Accept
{
	int i=0,j;
	char a;
	char tmp[8];//保存临时字符串
	for(j=0;j<strlen(s);j++)
	{
		if (s[j]=='-')
			continue;
		a=s[j];
		switch(a)
		{
			case 'A':
			case 'B':
			case 'C':tmp[i++]='2';break;//映射ABC为2 
			case 'D':
			case 'E':
			case 'F':tmp[i++]='3';break;//映射DEF为3
			case 'G':
			case 'H':
			case 'I':tmp[i++]='4';break;//映射GHD为4
			case 'J':
			case 'K':
			case 'L':tmp[i++]='5';break;
			case 'M':
			case 'N':
			case 'O':tmp[i++]='6';break;
			case 'P':
			case 'R':
			case 'S':tmp[i++]='7';break;
			case 'T':
			case 'U':
			case 'V':tmp[i++]='8';break;
			case 'W':
			case 'X':
			case 'Y':tmp[i++]='9';break;
			default:tmp[i++]=a;break;
		}
	}
	return atoi(tmp);
}
//系统快速排序子函数 使用字典顺序  返回1，升序 -1，降序 
int cmp(const void *a,const void *b)
{
	Data *d1=(Data *)a;
	Data *d2=(Data *)b;
	return d1->num>d2->num?1:-1;
}
void inttochar(int a)//把数字转化为字符格式形式输出 10--->000-0010  1234567
{
	int index=0;
	int k=1000000;
	while(k)
	{
		printf("%d",a/k);
		a%=k;
		k/=10;
		index++;
		if (index==3)
		printf("-");
	}
}
int main()
{
	bool flag,have=true;
	char ss[10];
	int i,j,k,s;
	scanf("%d",&s);
	for (i=0;i<s;i++)
	{
		array[i].time=1;//初始化为首次 
		array[i].num=-1; 
	}
	i=0;
	while(s--)
	{
		//printf("%d\n",intoint(ss));
		scanf("%s",ss);
		k=intoint(ss);
		flag=false;
		for (j=0;j<=i;j++)
		{
			if (array[j].num==k)
				{
					array[j].time++;
					flag=true;//有重复 
				}
		}
		if (!flag)//没有重复的 
			array[i++].num=k;
	}
	qsort(array,i,sizeof(array[0]),cmp);
	for(int b=0;b<i;b++)
		{
			if (array[b].time>1)
			{
				//printf("%d %d\n",array[b].num,array[b].time);//需要把10转化为000-0010 
				inttochar(array[b].num);
				printf(" %d\n",array[b].time);
				have=false;
			}
		}
	if(have)
		printf("No duplicates.\n");
	return 0;
}

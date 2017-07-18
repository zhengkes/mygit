#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 130
char input[10];
int data[N];
void test(int a,int b,int c)//a:底数 b:幂 c:小数位数 
{
	int i,j,jingwei;
	int tmp,point;
	memset(data,0,sizeof(data));
	data[0]=1;
	for (i=0;i<b;i++)
	{
		jingwei=0;
		for (j=0;j<N;j++){
			tmp=data[j]*a+jingwei;
			data[j]=tmp%10;//每个int保存一位数字，方便添加小数点
			jingwei=tmp/10; 
		}
	}
	for(i=N-1;i>=0;i--)
		if(data[i])
		break;//反向查找第一个不是0的数组单位
	point=b*c;//小数点位数 
	if (point<i+1)
	{
		for (j=i;j>=point;j--)
			printf("%d",data[j]);
		printf(".");
		for(j=point-1;j>=0;j--)
			printf("%d",data[j]);
	}
	if (point==i+1)
	{
		printf(".");
		for(j=i;j>=0;j--)
			printf("%d",data[j]);
	}
	if (point>i+1)
	{
		printf(".");
		for(j=0;j<(point-i-1);j++)
		{
			printf("0");
		}
		for(j=i;j>=0;j--)
			printf("%d",data[j]);
	}
	#if 1
	printf("\n"); 
	#endif
}
int main()
{
	int a,b,k,c,num,f1;//a:底数 b:幂次 c:小数位 
	double f,tmp,m;
	while(scanf("%f%d",&f,&b)!=EOF)
	{
		num=0;
		f1=(int)f;
		tmp=f-(int)f;//差值小数 
		while(tmp*10000>=1)
		{
			k=((int)tmp)*10;//小数的化整后 
			m=tmp*10;
			tmp=m-k;
			num++;
		} 
		c=num;
		while(num--)
			f1*=10;
		a=f1+k;
		printf("a=%d  b=%d  c=%d\n",a,b,c);
		#if 0
		strncpy(in1,input,6);
		in1[6]='\0';
		f=atof(in1);
		tmp=atoi(in1);
		while(f-(int)f>=0.001)
		{
			 c++;//小数位加1
		 	 f*=10; 
		} 
		a=(int)f;
		printf("a=%d\tb=%d\tc=%d\n",a,b,c);
		//test(a,b,c);
		c=0;
		//printf("底数:%d 小数位:%d\n",a,c);
		#endif
	}
	return 0;
}

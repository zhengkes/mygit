#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 130
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
	
	//TODO
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
int* inputdeal(const char *s)//输入处理 
{
	int *out;
	int d=0;
	char in1[7];
	char in2[3];
	strncpy(in1,s,6);
	in1[6]='\0';
	strncpy(in2,s+7,2);
	in2[2]='\0';
	out[0]=atoi(in2); //获取幂次
	double f=atof(in1);
	int tmp=atoi(in1);
	while(f-(int)f>=0.00001)
	{
		 d++;//小数位加1
		 f*=10; 
	} 
	out[1]=d;//获得小数位 
	out[2]=(int)f;//获得整数 
	//printf("%s\n%d",in1,atoi(in2));
	return out;
}
int main()
{
	int *a,*b,*c;
	char ee[10];
	int *kk;
	while(scanf("%s",ee)!=EOF)
	{
		kk=inputdeal(ee);
		printf("%d%d%d",kk[0],kk[1],kk[2]);
	}
	/*while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		test(a,b,c);
	}*/
	//inputdeal("512.55 12");
	return 0;
}

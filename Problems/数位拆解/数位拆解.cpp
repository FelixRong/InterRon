#include<iostream>
using namespace std;
int main()
{
	int a;
	int buf[100];
	int i=0;
	scanf("%d",&a);
	while(a!=0)
	{
		buf[i++]=a%10; // 取最低位 
		a/=10; // 去掉最低位的值 
	}
	for(int j=0;j<i;j++)
	{
		cout<<buf[j]<<" ";
	}
	return 0;
}
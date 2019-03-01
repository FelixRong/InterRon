/*
	找出数组中重复的数字
	该数组为：长度为n的数组里的所有数字都在0-(n-1)中 
*/
#include<cstdio>
#include<cstring>
const int maxn=101;
int cnt[maxn];
int main()
{
	int N,x;
	while(scanf("%d",&N)==1 && N)// 数组的个数N 
	{
		memset(cnt,0,sizeof(cnt));// 数组赋值为0 
		
		for(int i=0;i<N;i++)
		{
			scanf("%d",&x);// 输入数组中的元素 但x不大于N的值
			cnt[x]++;// 该元素的个数+1 
		}
		for(int i=0;i<N;i++)
		{
			if(cnt[i])// 如果该元素存在 
			{
				if(cnt[i]>=2)// 如果该元素的个数重复 
				{
					printf("%d ",i);// 输出该元素 
				}
			}
		}
		printf("\n");
	}
	return 0;
}
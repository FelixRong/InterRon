#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
int main()
{
	vector<long long> num;
	long long count;
	int n;
	cin>>n;
	int a=n;
	int nn=0;
	while(n--){
		cin>>count;
		if(count<=0){
			nn++;
		}
		num.push_back(count);
	}

	sort(num.begin(),num.end(),cmp); // 排序 sort(a,a+20);

	long long max;
	long long min;
	max=num[0]*num[1]*num[2];
	min=num[a-1]*num[a-2]*num[0];
	
	if(max>min){
		cout<<max<<endl;
	}else{
		cout<<min<<endl;
	}
	if(nn==n){
		cout<<0<<endl;
	}
	return 0;
}
#include<iostream>
using namespace std;
int main(){
	long long N;
	
	while (scanf("%lld", &N) != EOF){
		int f1=0;
		int f2=1;
		int c=0;
		cout<<f1<<" "<<f2<<" ";
		for(int i=3;i<=N;i++){
			c=f1+f2;
			cout<<c<<" ";
			f1=f2;7
			f2=c;
		}
		cout<<endl;
	}
	return 0;
}
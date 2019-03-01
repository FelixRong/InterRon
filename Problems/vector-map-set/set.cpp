#include<iostream>
#include<set>
#include <algorithm>
using namespace std;

int main()
{
	set<int> set1;
	int x;
	do{
		cin>>x;
		set1.insert(x);
	}while(cin.get()!='\n');
	
	for(set<int>::iterator it=set1.begin();it!=set1.end();it++){
		cout<<*it<<endl;
	}
	int in;
	cin>>in;
	cout<<*set1.find(in)<<endl;
	cout<<set1.size()<<endl;
	return 0;
}
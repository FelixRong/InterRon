#include<iostream>
#include<map>
#include <algorithm>
using namespace std;

int main()
{
	map<char,int> mymap;
	char c;
	int i;
	do{
		cin>>c>>i;
		mymap.insert(pair<char,int>(c,i));
	}while(cin.get()!='\n');

	for(map<char,int>::iterator iter=mymap.begin();iter!=mymap.end();iter++){
		cout<<iter->first<<' '<<iter->second<<endl;
	}
	char ch;
	cin>>ch;
	cout<<mymap[ch]<<endl; // 使用下标访问 
	
	cout<<mymap.size()<<endl; // 输出向量大小 
	
	char chch;
	cin>>chch; 
	mymap.erase(chch); // 删除键为chch的值 
	for(map<char,int>::iterator iter=mymap.begin();iter!=mymap.end();iter++){
		cout<<iter->first<<' '<<iter->second<<endl;
	}
	return 0;
}
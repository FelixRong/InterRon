#include<iostream>
#include<cstdlib>
#include<iomanip>
void getAvg(int arr[],int l);
using namespace std;

template <class T>
int getLength(T& array)
{
	return (sizeof(array) / sizeof(array[0]));
}

void getAvg(int arr[],int l){
	int sum=0;
	for(int i=0;i<l;i++){
		sum+=arr[i];
	}
	cout<<sum<<setw(6)<<sum/l<<endl;
}
int main(){
	int arr[4]={1,2,3,4};
	int l=getLength(arr);
	getAvg(arr,l);
	return 0;
}
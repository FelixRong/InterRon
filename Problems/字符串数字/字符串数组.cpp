#include<iostream>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int maxV=0;
	if(str.length()==1)
	{
		maxV=str[0]-48;
	}
	else if(str.length()==2)
	{
		maxV=(str[0]-48)*10+(str[1]-48);
	}
	else if(str.length()>=3)
	{
		maxV=(str[0]-48)*100+(str[1]-48)*10+(str[2]-48);
		for(int i=1;i<str.length()-2;i++)
		{			
			if(maxV<(str[i]-48)*100+(str[i+1]-48)*10+(str[i+2]-48)) 
			{
				maxV=(str[i]-48)*100+(str[i+1]-48)*10+(str[i+2]-48);
			}
		}
	}
	cout<<maxV<<endl;
	return maxV;
 } 
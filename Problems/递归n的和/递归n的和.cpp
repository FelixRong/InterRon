#include<iostream>
using namespace std;
int sum(int n);
int main()
{
	int n;
	cin >> n;
	cout << sum(n);
}
int sum(int n)
{
	int ans = n;
	ans && (ans += sum(n - 1));
	return ans;
}
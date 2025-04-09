#include <iostream>
using namespace std;

#define ll long long

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, x = 0;
		cin >> n;
		x = n/3;
		if(n==1)
			cout << 2 << '\n';
		else if(n<5 && n%2==0)
			cout << n/2 << '\n';
		else if(n%3==0)
			cout << n/3 << '\n';
		else if(n-x==2)
			cout << n/3+1 << '\n';
		else
			cout << n/3+1 << '\n';
		if(t==0)
			break;
	}
	return 0;
}

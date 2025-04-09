#include <bits/stdc++.h>
#define ll long long

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	ll n;
	std::cin >> n;
	std::cout << n;
	while(n!=1){
		if(n%2==0)
			n/=2;
		else
			n=n*3+1;
		std::cout << ' ' << n;
	}
	return 0;
}

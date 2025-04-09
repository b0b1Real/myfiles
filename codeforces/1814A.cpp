#include <iostream>
#define ll long long

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		ll k, n;
		std::cin >> n >> k;
		bool can = 0;
		if(n%2==0)
			can = 1;
		else if((n-k)%2==0 && n-k>0)
			can = 1;
		else if((n-k-k)%2==0 && n-k-k>0)
			can = 1;
		else if(n%k==0)
			can = 1;
		else if((n-2)%k==0)
			can = 1;
		if(can)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
	return 0;
}

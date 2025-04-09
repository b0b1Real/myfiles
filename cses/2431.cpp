#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ll long long
#define all(x) x.begin(), x.end()
#define hashmap unordered_map

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 10001;

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int q;
	std::cin >> q;
	while(q--){
		ll n;
		std::cin>>n;
		if(n<10)
			std::cout << n << '\n';
		else if(n<100){
			if(n%2==0)
				std::cout << ((n-9)/2+9)%10 << '\n';
			else
				std::cout << (((n-9)/2+9)/10%10) << '\n';
		}
	}
	return 0;
}


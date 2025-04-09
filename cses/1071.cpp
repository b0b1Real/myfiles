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
	int t;
	std::cin >> t;
	while(t--){
		ll y, x;
		std::cin >> y >> x;
		ll ans;
		if(y>x){
			ans = (y-1) * (y-1);
			if(y%2==0)
				ans += 2*y-x;
			else
				ans+=x;
		}else{
			ans = (x-1) * (x-1);
			if(x%2!=0)
				ans += 2*x-y;
			else
				ans+=y;
		}
		std::cout << ans << '\n';
	}
	return 0;
}


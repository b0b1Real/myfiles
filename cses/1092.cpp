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
	int n;
	std::cin >> n;
	ll sum = 0;
	for(int i = 1;i<=n;i++)
		sum+=i;
	if(sum%2!=0)
		std::cout << "NO\n";
	else{
		sum/=2;
		std::vector<int> a, b;
		a.pb(n);
		ll suma = n;
		for(int i = n-1;i>0;i--){
			//std::cout << "suma+i = " << suma+i << "\tsum=" << sum << '\n';
			if(suma+i > sum){
				b.pb(i);
				continue;
			}
			a.pb(i);
			suma += i;
		}
		if(suma!=sum){
			std::cout << "NO\n";
			return 0;
		}
		std::cout << "YES\n";
		std::cout << sz(a) << '\n';
		for(auto& it : a)
			std::cout << it << ' ';
		std::cout << '\n' << sz(b) << '\n';
		for(auto& it : b)
			std::cout << it << ' ';
		std::cout << '\n';
	}
	return 0;
}


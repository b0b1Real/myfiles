#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ll long long
#define all(x) x.begin(), x.end()
#define hashmap unordered_map
#define forn(i, n) for(int i = 0;i<int(n);i++)

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 10001;

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		int ans = 0;
		int a[n];
		ll sum = 0;
		bool one = 0;
		forn(i, n){
			std::cin >> a[i];
			sum+=a[i];
			if(a[i]%3==1)
				one=1;
		}
		if(sum%3==2)
			ans=1;
		else if(sum%3==1){
			if(one)
				ans = 1;
			else
				ans = 2;
		}
		std::cout << ans << '\n';
	}
	return 0;
}


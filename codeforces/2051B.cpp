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
		int n, a, b, c;
		std::cin >> n >> a >> b >> c;
		ll d = a+b+c;
		int ans = (n/d)*3;
		d = n%d;
		if(d!=0){
			d-=a;
			ans++;
		}
		if(d>0){
			d-=b;
			ans++;
		}
		if(d>0){
			d-=c;
			ans++;
		}
		std::cout << ans << '\n';
	}
	return 0;
}


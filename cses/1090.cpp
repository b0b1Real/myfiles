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
	int n, x;
	std::cin >> n >> x;
	std::vector<int> p;
	forn(i, n){
		int pi;
		std::cin >> pi;
		p.pb(pi);
	}
	std::sort(all(p));
	int ans = 0;
	int j = 0;
	for(int i = n-1;i>=j;i--){
		ans++;
		if(i == j)
			break;
		if(p[i] + p[j] <= x)
			j++;
	}
	std::cout << ans;
	return 0;
}


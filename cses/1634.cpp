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
	int n, x;
	std::cin >> n >> x;
	ll dp[x], c[n];
	dp[0] = 0;
	for(int i = 1;i<x;i++)
		dp[i] = INF;
	for(int i = 0;i<n;i++){
		std::cin >> c[i];
		if(c[i] < x)
			dp[c[i]] = 1;
	 }
	std::sort(c, c+n);
	for(int i = 1;i<x;i++){
		for(auto& it : c){
			if(i-it < 0)
				break;
			dp[i] = std::min(dp[i], dp[i-it]+1);
		}
	}
	std::cout << dp[x-1];
	return 0;
}


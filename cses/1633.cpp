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
	const int dice[6] = {1, 2, 3, 4, 5, 6};
	std::cin >> n;
	ll dp[n] = { };
	if(n>6)
		for(int i = 0;i<6;i++)
			dp[i]=1;
	else
		for(int i = 0;i<n;i++)
			dp[i]=1;
	for(int i = 1;i<n;i++){
		for(auto& it : dice){
			if(i-it < 0)
				break;
			dp[i] = (dp[i] + dp[i-it]) % MOD;
		}
	}
	std::cout << dp[n-1];
	return 0;
}


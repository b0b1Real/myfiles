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
	int n, ans = 0;
	std::cin >> n;
	for(int i = 0;i<n;i++){
		std::string s;
		std::cin >> s;
		if(s[1]=='+')
			ans++;
		else
			ans--;
	}
	std::cout << ans;
	return 0;
}


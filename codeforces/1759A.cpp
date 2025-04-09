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
		std::string s;
		std::cin >> s;
		bool can = 1;
		if(s[0] != 'Y' && s[0] != 'e' && s[0] != 's')
			can = 0;
		for(int i = 1;i<sz(s);i++){
			if(s[i] != 'Y' && s[i] != 'e' && s[i] != 's')
				can = 0;
			if(s[i-1] == 'Y' && s[i] != 'e')
				can = 0;
			if(s[i-1] == 'e' && s[i] != 's')
				can = 0;
			if(s[i-1] == 's' && s[i] != 'Y')
				can = 0;
			if(!can)
				break;
		}
		if(can)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
	return 0;
}


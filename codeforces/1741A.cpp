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
		std::string a, b;
		std::cin >> a >> b;
		if(a==b)
			std::cout << "=\n";
		else{
			if(a.back() != b.back()){
				if(a.back() == 'L')
					std::cout << ">\n";
				else if(b.back() == 'L')
					std::cout << "<\n";
				else if(a.back() == 'M')
					std::cout << ">\n";
				else if(b.back() == 'M')
					std::cout << "<\n";
			}else{
				if(a.back() == 'S'){
					std::string ans = (sz(a) < sz(b)) ? ">" : "<";
					std::cout << ans << '\n';
				}
				else{
					std::string ans = (sz(a) > sz(b)) ? ">" : "<";
					std::cout << ans << '\n';
				}
			}
		}
	}
	return 0;
}


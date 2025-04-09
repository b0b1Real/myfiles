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
		int n, d;
		std::cin >> n >> d;
		std::string s;
		std::cin >> s;
		std::string sa = s;
		std::string sb = s;
		bool did = 0;
		for(int i = 0;i<n;i++){
			if(s[i]-'0' < d){
				did = 1;
				sa.erase(i, sz(s)-i);
				sb.erase(0, i);
//				std::cout << i << " "<< sa << " " << d << " " << sb << '\n';
				std::cout << sa << d << sb << '\n';
				break;
			}
		}
		if(!did)
			std::cout << s << d << '\n';
	}
	return 0;
}


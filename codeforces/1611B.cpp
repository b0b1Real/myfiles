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
		int a, b;
		std::cin >> a >> b;
		if(a<b)
			std::swap(a, b);
		if(a==b)
			std::cout << a/2 << '\n';
		else{
			if(b*3<=a)
				std::cout << b << '\n';
			else{
				int ans = 1;
				for(int i = 3;i<a;i+=3){
					if(i/3>b)
						break;
					ans++;
				}
				std::cout << ans << '\n';
			}
		}
	}
	return 0;
}


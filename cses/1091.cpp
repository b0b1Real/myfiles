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
	int n, m;
	std::cin >> n >> m;
	ll h[n], t[m];
	std::vector<int> ans(m, -1);
	forn(i, n)
		std::cin >> h[i];
	forn(i, m)
		std::cin >> t[i];
	std::sort(h, h+n);
	std::reverse(h, h+n);
	int last = 1;
	forn(i, m){
		if(t[i] < h[n-last])
			continue;
		forn(j, n){
//			std::cout << "t[" << i << "] = " << t[i] << "\th[" << j << "] = " << h[j] << '\n';
			if(t[i] >= h[j]){
				ans[i] = h[j];
				h[j] = INF;
				if(j==n-last)
					last++;
				break;
			}
		}
		std::cout << ans[i] << '\n';
	}
	return 0;
}


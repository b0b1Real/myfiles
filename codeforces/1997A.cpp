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
		std::string c = " ";
		bool did = 0;
		c[0] = s[0];
		forn(i, sz(s)){
			if(i==0)
				continue;
			if(did){
				c += s[i];
				continue;
			}
			if(s[i-1] == s[i]){
				if(s[i]!='y')
					c += 'y';
				else
					c += 'w';
				c += s[i];
				did = 1;
				i++;
			}else
				c += s[i];
		}
		if(!did && c[sz(s)-1] != 'y')
			c += 'y';
		else if(!did)
			c += 'x';
		if(s==c)
			c+='y';
		std::cout << c << '\n';
	}
	return 0;
}


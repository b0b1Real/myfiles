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
	std::string s;
	std::cin >> s;
	char c[sz(s)];
	for(int i = 0;i<sz(s);i++)
		c[i] = s[i];
	std::sort(c, c+sz(s));
	int i = 0;
	do {
		i++;
	}while(std::next_permutation(c, c+sz(s)));
	std::cout << i << '\n';
	std::sort(c, c+sz(s));
	do {
		for(int i = 0;i<sz(s);i++)
			std::cout<<c[i];
		std::cout << '\n';
	}while(std::next_permutation(c, c+sz(s)));
	return 0;
}


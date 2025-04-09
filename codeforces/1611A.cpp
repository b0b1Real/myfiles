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

bool isEven(char c){
	bool can = (c-'0')%2==0;
	return can;
}

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::string s = std::to_string(n);
		int x = sz(s);
		if(isEven(s[x-1]))
			std::cout << "0\n";
		else if(isEven(s[0]))
			std::cout << "1\n";
		else{
			bool can = 0;
			for(int i = 0;i<x;i++){
				if(isEven(s[i])){
					can = 1;
					break;
				}
			}
			if(can)
				std::cout << "2\n";
			else
				std::cout << "-1\n";
		}
	}
	return 0;
}


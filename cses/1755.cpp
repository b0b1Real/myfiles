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

bool cmp(std::pair<char, int>& a, std::pair<char, int>& b){
	return a.second > b.second;
}

std::vector<std::pair<char, int>> sort(std::map<char, int>& m){
	std::vector<std::pair<char, int>> a;
	for(auto& it : m)
		a.pb(it);
	sort(all(a), cmp);
	return a;
}

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::string s;
	std::cin >> s;
	char ans[sz(s)];
	bool can = 1, middle = 0;
	std::map<char, int> a;
	for(int i = 0;i<sz(s);i++){
		if(a.find(s[i]) != a.end())
			a[s[i]]++;
		else
			a[s[i]]=1;
	}
	int p = 0;
	std::vector<std::pair<char, int>> m = sort(a);
	for(int i = 0;i<sz(m);i++){
		if(m[i].second >= 2){
			if(m[i].second % 2 == 0){
				int z = m[i].second / 2;
				for(int j = p;j<p+z;j++){
					ans[j] = m[i].first;
					ans[sz(s)-1-j] = ans[j];
				}
				p+=z;
			}else if(middle)
				can = 0;
			else{
				int z = m[i].second / 2;
				for(int j = p;j<p+z;j++){
					ans[j] = m[i].first;
					ans[sz(s)-1-j] = ans[j];
				}
				p+=z;
				ans[sz(s)/2] = m[i].first;
				middle = 1;
	 		}
		}else{
			if(middle)
				can = 0;
			else{
				ans[sz(s)/2] = m[i].first;
				middle = 1;
			}
		}
		if(!can)
			break;
	}
	if(can)
		for(int i = 0;i<sz(s);i++)
			std::cout << ans[i];
	else
		std::cout << "NO SOLUTION";
	return 0;
}


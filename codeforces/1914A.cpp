#include <iostream>
#include <unordered_map>
#define hashmap unordered_map

int main(){
	int t;
	std::cin >> t;
	while(t--){
		int n, ans = 0;
		std::cin >> n;
		char s[n];
		std::cin >> s;
		std::hashmap<int, int> p;
		for(int i = 0;i<n;i++){
			int x = s[i] - 64;
			if(p.find(x) == p.end())
				p[x] = 1;
			else
				p[x]+=1;
		}
		for(auto i : p){
			if(i.second >= i.first)
				ans++;
	//		std::cout << i.first << '\t' << i.second << '\n';
		}
		std::cout << ans << '\n';
	}
	return 0;
}

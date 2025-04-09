#include <bits/stdc++.h>
#define ll long long

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::string s;
	std::cin >> s;
	ll longest = 1, current = 1;
	for(int i = 1;i<s.size();i++){
		if(s[i-1]==s[i])
			current++;
		else
			current = 1;
		if(current > longest)
			longest = current;
	}
	std::cout << longest;
	return 0;
}

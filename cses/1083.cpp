#include <bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	int a[n] = { };
	for(int i = 0;i<n-1;i++){
		int tmp;
		std::cin >> tmp;
		a[tmp-1] = tmp;
	}
	for(int i = 0;i<n;i++){
		if(a[i] == 0){
			std::cout << i+1;
			break;
		}
	}
	return 0;
}

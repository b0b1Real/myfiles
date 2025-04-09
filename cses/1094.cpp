#include <bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	long long ans = 0;
	std::cin >> n;
	int a[n];
	std::cin >> a[0];
	for(int i = 1;i<n;i++){
		std::cin >> a[i];
		if(a[i-1] > a[i]){
			ans+=a[i-1]-a[i];
			a[i] = a[i-1];
		}
	}
	std::cout << ans;
	return 0;
}

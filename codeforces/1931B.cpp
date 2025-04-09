#include <iostream>

#define ll long long

int main(){
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		ll arr[n], sum=0; 
		for(int i = 0;i<n;i++){
			std::cin >> arr[i];
			sum+=arr[i];
		}
		int amm = sum/n;
		bool can = true;
		for(int i = 0;i<n-1;i++){
			if(arr[i]<amm){
				can = false;
				break;
			}
			arr[i+1] += arr[i]-amm;
			arr[i] = amm;
		}
		if(can && arr[n-1]!=amm)
			std::cout << "NO\n";
		else if(can)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
	return 0;
}

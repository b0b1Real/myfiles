#include <iostream>

#define ll long long

int main(){
	int t;
	std::cin >> t;
	while(t--){
		ll p;
		std::cin >> p;
		ll j = p-1, i = 2;
		while(p%i!=p%j){
			i++;
			j--;
		}
		std::cout << i << " " << j << '\n';
	}
	return 0;
}

#include <bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	if(n<4 && n!=1)
		std::cout << "NO SOLUTION";
	else if(n==1)
		std::cout << "1";
	else if(n==4)
		std::cout << "2 4 1 3";
	else{
		int a[n] = { };
		a[2] = n;
		a[n-2] = 1;
		int j = 1, i = 1, count = 0;
		while(count<n){
			if(a[count] != 0){
				std::cout << a[count] << ' ';
				count++;
				continue;
			}
			if(j==i){
				a[count] = n-j;
				j++;
				//std::cout << "j: " << j << " i: " << i << "\n";
			}else{
				a[count] = i+1;
				i++;
				//std::cout << "j: " << j << " i: " << i << "\n";
			}
			std::cout << a[count] << ' ';
			count++;
		}
	}
	return 0;
}

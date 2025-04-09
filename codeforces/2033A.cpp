#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, x = 0;
		cin >> n;
		bool sakurako = true;
		int i = 1;
		while(abs(x)<=abs(n)){
			if(sakurako)
				x-=2*i-1;
			else
				x+=2*i-1;
			sakurako = !sakurako;
			i++;
		}
		if(sakurako)
			cout << "Kosuke\n";
		else
			cout << "Sakurako\n";
	}
	return 0;
}

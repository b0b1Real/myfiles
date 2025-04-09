#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int ans[n/k][n/k] = { };
		int ki = 0, kj = 0;
		for(int i = 0;i<n;i++){
			string tmp;
			cin >> tmp;
			int tmpa[n];
			//cout << "A\n";
			for(int z = 0;z<n;z++){
				tmpa[z] = tmp[z] - '0';
				//cout << "B\n";
			}
			if((i+1)%k==0){
				for(int j = 0;j<n;j+=k){
					ans[ki][kj] = tmpa[j];
					kj++;
					//cout << "C\n";
				}
				ki++;
			}
			kj=0;
		}
		for(int i = 0;i<n/k;i++){
			for(int j = 0;j<n/k;j++){
				cout << ans[i][j];
			}
			cout << "\n";
		}
		if(t==0)
			break;
	}
	return 0;
}

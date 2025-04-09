#include <iostream>
#include <string>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int ans = 0;
		int n = s.size();
		if(n>2){
			int k = 101, z = 101;
			for(int i = n-1;i>=0;i--){
				if(s[i] == '1'){
					z = i;
					break;
				}
			}
			for(int i = 0;i<n;i++){
				if(s[i] == '1'){
					k = i;
					break;
				}
			}
			if(k!=z && k!=101){
				for(int i = k;i<z;i++){
					if(s[i] == '0')
						ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

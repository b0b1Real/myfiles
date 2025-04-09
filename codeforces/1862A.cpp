#include <iostream>
#include <string>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		char s[n][m];
		int phase = 0;
		for(int i = 0;i<n;i++){
			string z;
			cin >> z;
			for(int j = 0;j<m;j++){
				s[i][j] = z[j];
			}
		}
		for(int i = 0;i<m;i++){
			for(int j = 0;j<n;j++){
	//			cout << "pos:[" << i << "][" << j << "]\tphase: " << phase << '\n';
				if(phase == 0){
					if(s[j][i] == 'v'){
						phase++;
						break;
					}
				}else if(phase == 1){
					if(s[j][i] == 'i'){
						phase++;
						break;
					}
				}else if(phase == 2){
					if(s[j][i] == 'k'){
						phase++;
						break;
					}
				}else if(phase == 3){
					if(s[j][i] == 'a'){
						phase++;
						break;
					}
				}
			}
			if(phase == 4)
				break;
		}
		if(phase==4)
			cout<<"YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}

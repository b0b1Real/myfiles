#include <iostream>
#include <string>
#include <vector>

#define pb push_back

int main(){
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::string s;
		std::cin >> n >> s;
		std::vector<std::string> mel;
		for(int i = 0;i<n-1;i++){
			std::string a;
			a+=s[i];
			a+=s[i+1];
			bool broke = false;
			for(int j = 0;j<mel.size();j++){
				if(a==mel[j]){
					broke = true;
					break;
				}
			}
			if(!broke)
				mel.pb(a);
		}
		std::cout << mel.size() << '\n';
	}
	return 0;
}

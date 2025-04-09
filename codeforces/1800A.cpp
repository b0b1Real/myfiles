#include <iostream>
#include <string>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n >> s;
		int phase = 0;
		if((char)tolower(s[0]) != 'm')
			cout << "NO\n";
		else if(n<4)
			cout << "NO\n";
		else{
			bool meow = true;
			for(int i = 0;i<n;i++){
				s[i] = (char)tolower(s[i]);
				if(phase == 0){
					if(s[i] == 'e')
						phase++;
					else if(s[i] != 'm')
						meow = false;
				}else if(phase == 1){
					if(s[i] == 'o')
						phase++;
					else if(s[i] != 'e')
						meow = false;
				}else if(phase == 2){
					if(s[i] == 'w')
						phase++;
					else if(s[i] != 'o')
						meow = false;
				}else{
					if(s[i] != 'w')
						meow = false;
				}
				if(!meow){
					//cout << i;
					break;
				}
			}
			if(s[n-1]!='w')
				meow = false;
			if(meow)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		if(t==0)
			break;
	}
	return 0;
}

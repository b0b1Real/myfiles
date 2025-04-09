#include <iostream>
#include <string>
using namespace std;

int main(){
	int n, count = 0;
	string t;
	char s[10];
	cin >> n >> t;
	for(int i = 1;i<=n;i+=count+1){
		s[count] = t[i-1];
		count++;
	}
	for(int i = 0;i<count;i++){
		cout << s[i];
	}
	return 0;
}

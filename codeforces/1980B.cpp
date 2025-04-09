#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, f, k;
		cin >> n >> f >> k;
		int a[n];
		for(int i = 0;i<n;i++){
			cin >> a[i];
		}
		int tmp = f-1;
		f = a[tmp];
		sort(a, a+n, greater<int>());
		bool can = false;
		bool maybe = false;
		for(int i = 0;i<n;i++){
			if(a[i] < f)
				break;
			if(i<k && a[i] == f){
				maybe = true;
			}else if(i>=k && a[i] == f){
				can = true;
				break;
			}
		}
		if(can && maybe)
			cout << "MAYBE\n";
		else if(can)
			cout << "NO\n";
		else if(!can)
			cout << "YES\n";
	}
	return 0;
}

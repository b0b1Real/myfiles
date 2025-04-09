#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define pb push_back

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		int m = 0;
		vector<int> a;
		for(int i = 0;i<k;i++){
			int tmp;
			cin >> tmp;
			a.pb(tmp);
		}
		sort(a.begin(), a.end());
		for(int i = 0;i<k-1;i++){
			m+=a[i]*2-1;
		}
		cout << m << '\n';
	}
	return 0;
}

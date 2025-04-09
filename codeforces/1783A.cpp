#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0;i<n;i++){
			int tmp;
			cin >> tmp;
			arr[i] = tmp;
		}
		sort(arr, arr+n, greater<int>());
		int m = arr[0];
		bool b = true;
		if(arr[1] == m){
			for(int i = 0;i<n;i++){
				if(arr[i] != m){
					cout << "YES\n";
					int tmp = arr[i];
					arr[i] = m;
					arr[1] = tmp;
					for(int i : arr){
						cout << i << " ";
					}
					cout << "\n";
					b = false;
					break;
				}
			}
		}else{
			cout << "YES\n";
			for(int i : arr){
				cout << i << " ";
			}
			cout << "\n";
			b = false;
		}
		if(b)
			cout << "NO\n";
	}
	return 0;
}

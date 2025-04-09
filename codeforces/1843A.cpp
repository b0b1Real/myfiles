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
		int m = 0;
		for(int i = 0;i<n;i++){
			cin >> arr[i];
		}
		sort(arr, arr+n);
		int j = n-1;
		for(int i = 0;i<n/2;i++){
			m+=arr[j]-arr[i];
			j--;
		}
		cout << m << '\n';
	}
	return 0;
}

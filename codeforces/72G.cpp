#include <iostream>
#include <unordered_map>
using namespace std;

#define hashmap unordered_map

hashmap<int, int> memo;

int fib(int n){
	if(n < 2){
		return 1;
		memo[n] = 1;
	}
	if(memo.find(n) != memo.end())
		return memo[n];
	memo[n] = fib(n-1) + fib(n-2);
	cout << n << " : " << memo[n] << '\n';
	return memo[n];
}

int main(){
	int n;
	cin >> n;
	cout << fib(n);
}

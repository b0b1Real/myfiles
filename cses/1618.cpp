#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ll long long
#define all(x) x.begin(), x.end()
#define hashmap unordered_map

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 10001;

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	ll n;
	std::cin >> n;
	ll ans = n/5;
	ans+=n/25;
	ans+=n/125;
	ans+=n/625;
	ans+=n/3125;
	ans+=n/15625;
	ans+=n/78125;
	ans+=n/390625;
	ans+=n/1.95312e+06;
	ans+=n/9.76562e+06;
	ans+=n/4.88281e+07;
	ans+=n/2.44141e+08;
	ans+=n/1.2207e+09;
	ans+=n/6.10352e+09;
	ans+=n/3.05176e+10;
	ans+=n/1.52588e+11;
	ans+=n/7.62939e+11;
	ans+=n/3.8147e+12;
	ans+=n/1.90735e+13;
	ans+=n/9.53674e+13;
	ans+=n/4.76837e+14;
	ans+=n/2.38419e+15;
	ans+=n/1.19209e+16;
	ans+=n/5.96046e+16;
	ans+=n/2.98023e+17;
	ans+=n/1.49012e+18;
	ans+=n/7.45058e+18;
	ans+=n/3.72529e+19;
	ans+=n/1.86265e+20;
	ans+=n/9.31323e+20;
	ans+=n/4.65661e+21;
	ans+=n/2.32831e+22;
	ans+=n/1.16415e+23;
	ans+=n/5.82077e+23;
	ans+=n/2.91038e+24;
	ans+=n/1.45519e+25;
	ans+=n/7.27596e+25;
	ans+=n/3.63798e+26;
	ans+=n/1.81899e+27;
	ans+=n/9.09495e+27;
	ans+=n/4.54747e+28;
	ans+=n/2.27374e+29;
	ans+=n/1.13687e+30;
	ans+=n/5.68434e+30;
	ans+=n/2.84217e+31;
	ans+=n/1.42109e+32;
	ans+=n/7.10543e+32;
	ans+=n/3.55271e+33;
	ans+=n/1.77636e+34;
	std::cout<<ans;
	return 0;
}


#include <iostream>

int main(){
	int n;
	std::cin >> n;
	char s[n], a[n];
	std::cin >> s >> a;
	int ans = 0;
	for(int i = 0;i<n;i++){
		int x=s[i] - '0', y=a[i] - '0';
		if(x>y){
			if((x-y)>=5)
				ans+=y+10-x;
			else
				ans+=x-y;
		}else if(x<y){
			if((y-x)>=5)
				ans+=x+10-y;
			else
				ans+=y-x;
		}
	}
	std::cout << ans;
	return 0;
}

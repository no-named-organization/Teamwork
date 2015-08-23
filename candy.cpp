#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

#define FOR(i,a,b) for (i = a; i <= b; i++)

int rat[100005], can[100005];

int main(int argc, char const *argv[])
{
	int n, i, j;
	std::cin>>n;
	FOR(i,1,n){
		std::cin>>rat[i];
		can[i] = 0;
	}
	rat[0] = rat[1];
	rat[n+1] = rat[n];
	FOR(i,1,n){
		if(rat[i] <= rat[i+1] && rat[i] <= rat[i-1]){
			can[i] = 1;
			for(j=i-1;j>=1 && rat[j] > rat[j+1];j--){
				can[j] = can[j+1]+1;
			}
			for(j=i+1;j<=n && rat[j] > rat[j-1];j++){
				can[j] = can[j-1]+1;
			}
		}
	}
	int ans = 0;
	FOR(i,1,n){
		if(rat[i]>rat[i-1] && rat[i] > rat[i+1]){
			can[i] = can[i-1]>can[i+1]?can[i-1]+1:can[i+1]+1;
		}
		ans += can[i]; 
	}
	std::cout<<ans<<"\n";
	return 0;
}
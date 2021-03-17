#include <stdio.h>


int main() {
	int n, M[30001];
	int dp[30001] = {0,};
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) scanf("%d", &M[i]);
	
	int ans=0;
	
	dp[1] = M[1];
	dp[2] = M[1]+M[2];
	ans = dp[2];
	
	for(int i = 3; i<=n; i++){
		dp[i] = dp[i-2] + M[i];
		if(dp[i] < dp[i-1]) dp[i] = dp[i-1];
		if(dp[i] < (M[i-1] + M[i] + dp[i-3]))
			dp[i] = M[i-1] + M[i] + dp[i-3];
	}
	printf("%d\n",dp[n]);
	return 0;
}


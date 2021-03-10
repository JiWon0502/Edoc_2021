#include <stdio.h>
int dp[10] = {0,};

int chk(int l, int r){
	if(l==0) return 1;
	else if(l==r){
		if (dp[r] != 0) return dp[r];
		else {
			dp[r] = chk(l-1, r);
			return dp[r];
		}
	}
	else if((r-l) == 1){
		if (dp[r] != 0) return dp[r];
		else {
			dp[r] = chk(l-1, r) + chk(l, r-1);
			return dp[r];
		}
	}
	return chk(l-1, r) + chk(l, r-1);
}

int main() {
	int input;
	scanf("%d",&input);
	dp[1] = 1;
	dp[2] = 2;
	chk(input, input);
	printf("%d", dp[input]);
	return 0;
}

// 스택 사용XX인 코드
#include<stdio.h>
long long F[1000005] = {0,};


int main(){
    int N;
    long long A[1000005] = {0, }, ans[1000005] = {0,}, max;
    scanf("%d", &N);
    for (int i = 0; i<N; i++){
        scanf("%lld", &A[i]);
        F[A[i]]++;
    }
    ans[N-1] = -1;
    max = F[A[N-1]];
    for(int j = N-2; j>=0; j--){
    label:
        if(j<0) break;
        for(int k = j; k<N;k++){
            if(max<F[A[j]]) {
                ans[j] = -1;
                max = F[A[j--]];
                goto label;
            }
            else if(F[A[j]] < F[A[k]]){
                ans[j--] = A[k];
                goto label;
            }
            else ans[j] = -1;
        }
    }
    for(int i = 0; i<N;i++) printf("%lld ", ans[i]);
    return 0;
}

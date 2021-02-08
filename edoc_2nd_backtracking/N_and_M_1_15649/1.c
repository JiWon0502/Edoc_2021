#include<stdio.h>
int isused[8] = {0,} , num[8] = {0,};

void numbering(int N, int M){
    if(M==0){
        for(int i=8;i>0;i--){
            if (num[i] != 0){
                printf("%d ",num[i]);
            }
        }
        printf("\n");
        return;
    }
    else {
        for(int i=1; i<=N; i++){
            if(isused[i]==1) continue;
            else {
                isused[i]=1;
                num[M]=i;
                numbering(N, M-1);
                isused[i] = 0;
            }
        }
    }
}


int main(){
    int N,M;
    scanf("%d %d", &N, &M);
    numbering(N,M);
    return 0;
}

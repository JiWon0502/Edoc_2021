#include<stdio.h>


int main(){
    int N, M, i,j,a,b,sign = 0;
    char A[51][51], B[51][51];
    scanf("%d %d", &N, &M);

    for(i=0;i<N;i++)
        scanf("%s", A[i]);
    
    for(i=0;i<N;i++)
        scanf("%s", B[i]);
    
    for(i=0;i<N-2;i++){
        for(j=0;j<M-2;j++){
            if(A[i][j]!=B[i][j]){
                sign++;
                for(a=0;a<3;a++){
                    for(b=0;b<3;b++){
                        if(A[i+a][j+b]=='0'){
                            A[i+a][j+b] = '1';
                        } 
                        else{
                            A[i+a][j+b] = '0';
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(A[i][j]!=B[i][j]){
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d", sign);
    return 0;
}

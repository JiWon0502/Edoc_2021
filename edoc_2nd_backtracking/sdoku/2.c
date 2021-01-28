#include <stdio.h>
int N[9][9];
int used_int [10] = {0,};

void check(int i, int j){
    for(int q=0;q<10;q++){
        used_int[q+1] = 0;
    }
    for(int k =1; k<10; k++){
        if(N[i][k]!=0) used_int[N[i][k]]=1;
        else if(N[k][j]!=0) used_int[N[i][k]]=1;
    }
    i = i - i%3;
    j = j - j%3;
    for(int w=0; w<3; w++){
        for(int p=0; p<3; p++){
            if(N[i+p][j+w]!=0) used_int[N[i+p][j+w]]=1;
        }
    }
    return;
}

void check_if(){
    for(int i=0; i<9; i++){
        for (int j =0; j<9; j++){
            if(N[i][j]==0){
                check(i,j);
                for(int r=1; r<10; r++){
                    if(used_int[r]==0){
                        N[i][j] = r;
                        used_int[r] = 1;
                        check_if();
                        N[i][j]=0;
                        used_int[r] = 0;
                        continue;
                    }
                }
            }
            else if(i==9 && j==9) return;
        }
    }
    return;
}

int main(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            scanf("%d", &N[i][j]);
        }
    }
    check_if();
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("%d ", N[i][j]);
        }
        printf("\n");
    }
}

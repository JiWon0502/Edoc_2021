#include<stdio.h>
int main(){
    int N, lvl[100], x=0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &lvl[i]);
    for(int i = N-1; i > 0; i--){
        if(lvl[i]<=lvl[i-1]){
            int tmp = lvl[i-1] - lvl[i] + 1;
            lvl[i-1] = lvl[i] -1;
            x += tmp;
        }
    }
    printf("%d", x);
    return 0;
}

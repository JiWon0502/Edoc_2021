#include<stdio.h>

int main(){
    int i = 1;
    int L,P,V,max;
    while(1){
        scanf("%d %d %d", &L, &P, &V);
        if(L==0 && P==0 && V==0){
            break;
        }
        else {
            max = V/P*L;
            if((V%P)>L)
                max+=L;
            else max+=V%P;
            printf("Case %d: %d\n",i++, max);
        }
    }
    return 0;
}

#include<stdio.h>

int main(){
    int N, arr[30000]={0,}, i, j, temp, max = 0;
    scanf("%d", &N);
    for(j = 0; j<N; j++) scanf("%d", &arr[j]);
    for(i = 0; i<N; i++){
        temp = 0;
        for(j = i+1; j < N; j++){
            if(arr[i]>arr[j])
                temp++;
            else {
                i = j;
                break;
            }
        }
        if(max<temp) max = temp;
    }
    printf("%d\n", max);
}

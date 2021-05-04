#include <stdio.h>
#include <stdlib.h>
long arr[1000000] = {0,};

int compare(const void* a, const void* b){
    if(*(long*)a > *(long*)b)
        return 1;
    else if (*(long*)a < *(long*)b)
        return -1;
    else return 0;
}

int main(){
    long N;
    scanf("%ld", &N);
    for(int i = 0; i<N; i++)
        scanf("%ld", &arr[i]);
    qsort(arr, N, sizeof(long int), compare);
    for(int j = N-1; j>=0; j--)
        printf("%ld\n", arr[j]);
    return 0;
}


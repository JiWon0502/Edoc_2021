#include<stdio.h>
#include<stdlib.h> //qsort, abs

int compare_sort(const void* a, const void* b){
    if(abs(*(int*)a)>abs(*(int*)b))
        return 1;
    else if (abs(*(int*)a)<abs(*(int*)b))
        return -1;
    else return 0;
}

int main(){
    int arr[100001]={0,};
    int arr_size, min_indx, min_cal;
    scanf("%d", &arr_size);
    for(int i=0;i<arr_size;i++){
        scanf("%d", &arr[i]);
    }
    //sort the array by its abs value
    qsort(arr, arr_size, sizeof(int), compare_sort);
    /*check if sorted
    for(int i = 0; i< arr_size; i++){
        printf("%d\n", arr[i]);
    }
    */        
    
    //initailize
    min_cal = abs(arr[0] + arr[1]);//abs!!!!!!!
    min_indx = 0;
    
    for (int j = 0; j < (arr_size -1); j++){
        if(min_cal == 0){
            break;
        }
        else if(abs(arr[j]+arr[j+1]) < min_cal){ //do not forget abs!!!!!
            min_cal = abs(arr[j] + arr[j+1]);
            min_indx = j;
        }
    }
    
    if(arr[min_indx]<arr[min_indx+1])
        printf("%d %d\n", arr[min_indx], arr[min_indx+1]);
    else printf("%d %d\n", arr[min_indx+1], arr[min_indx]);
    
    return 0;
}

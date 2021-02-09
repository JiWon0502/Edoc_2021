#include <stdio.h>
#define MAX_SIZE 10000005
int stack[1000005];
int top = -1;

void stack_full(){
    printf("Stack is Full\n");
}

int stack_empty(void) {
    printf("Stack is empty\n");
    return -1;
}

void push(int x) {
    if (top >= MAX_SIZE-1) {
        stack_full();
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1)
        return stack_empty();
    return stack[top--];
}

int main(){
    int N;
    int F[1000005] = {0,};
    int A[1000005] = {0, }, ans[1000005] = {0,}, max;
    scanf("%d", &N);
    for (int i = 0; i<N; i++){
        scanf("%d", &A[i]);
        F[A[i]]++;
    }
    
    for(int j = N-1; j>=0; j--){
        int a;
        while(stack_empty() != -1){
            a = pop();
            if(F[a]>F[A[j]]) break;
        }
        if(stack_empty() == -1)
            ans[A[j]] = -1;
        else ans[A[j]] = a;
        push(A[j]);
    }
    
    for (int i = 0; i<N; i++){
        scanf("%d", &ans[i]);
    }
}

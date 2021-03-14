#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int s[1000];
int e[1000];
//프로그래머스에서는 main함수 및 입출력문이 필요하지 않습니다. 대신 solution함수만 작성하면 됩니다.
int compare_s(const void* a, const void* b){
	if(s[*(int*)a] > s[*(int*)b]) return 1;
	else if(s[*(int*)a] < s[*(int*)b]) return -1;
	else return 0;
}
int compare_e(const void* a, const void* b){
	if(e[*(int*)a] > e[*(int*)b]) return 1;
	else if(e[*(int*)a] < e[*(int*)b]) return -1;
	else return 0;
}

int solution(int s[], int e[], int N){
	int answer = 0, i = N;
	int l_fnl = 0, r_fnl = 0;	
	int* indx = malloc(sizeof(int)*N);
	while(i-->=0) indx[i] = i;
	printf("%d %d %d %d %d\n", indx[0], indx[1], indx[2], indx[3], indx[4]);
	
	if(N==1 || N==2) return N;
	
	for(int i = 0; i < N; i++) *indx = i;
	qsort(indx, N, sizeof(int), compare_s);
	qsort(indx, N, sizeof(int), compare_e);
	
	
	l_fnl = e[indx[i++]];
	r_fnl = e[indx[i++]];
	answer += 2;
	
	while(i<N){
		if(s[indx[i]] >= l_fnl){
			answer++;
			l_fnl = s[indx[i++]];
		}
		else if(s[indx[i]] >= r_fnl){
			answer++;
			l_fnl = s[indx[i++]];
		}
		else i++;
	}
	
	return answer;
}

int main() {

	int N = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &s[i]);
	for(int i = 0; i < N; i++)
		scanf("%d", &e[i]);
	
	printf("%d", solution(s, e, N));
	return 0;
}


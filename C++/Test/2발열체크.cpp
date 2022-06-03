#include<cstdio>
#include<iostream>
#include<time.h>

using namespace std;


/**
 * 걸린시간의 최소값을 구하는 함수
 * @param N     발열 측정을 기다리는 사람 수 
 * @param m     발열 측정기 개수
 * @param times    각 발열 측정기의 검사시간 배열
 * 
 * @return 걸린시간의 최소값
 */
int getFastestTime(int N, int m, int times[]){
    int count = 0;
    int seconds;

    // 1초부터 매 초마다 
    // 각 발열측정기가 측정을 끝냈는지(초를 나누어 떨어지는지) 판별
    // 나누어떨어지는 경우 측정완료된 사람 count에 +1을 하여
    // 그 숫자가 측정해야하는 사람 수 인 N보다 크거나 같은 경우에 for문을 멈추고
    // 그때의 seconds를 return 한다.
    for(seconds = 1; count < N; seconds++){ 
        for(int i = 0; i < m; i++){
            if(seconds % times[i] == 0){
                count++;
            }
        }
    };

    // for문으로 +1 되어있으므로 다시 1을 빼준다.
    return seconds - 1;
}

/**
 * @param N     발열 측정을 기다리는 사람 수
 * @param m     발열 측정기 개수
 * @param times 각 발열 측정기가 한 명을 검사할 때 걸리는 시간
 * 
 * @return int 
 */
int main() {
    clock_t start = clock();

    // 입력값 스캔
    // N, m, times[]
    int N, m;
    scanf("%d %d", &N, &m);

    int* times = new int[m];
    for(int i = 0; i < m; i++){
        scanf("%d", &times[i]);
    }


    // 걸린시간의 최솟값 구하기 및 출력
    int answer = getFastestTime(N,m,times);
    printf("%d\n", answer);

    delete[] times;

    // 실행시간 출력
    clock_t end = clock();
    printf("실행시간: %lf초\n", (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
#include <iostream>
#include <vector>
#include <sstream>
#include<time.h>

using namespace std;

/**
 * 최대공약수를 구하는 함수 (유클리드 호제법 사용)
 * @param W
 * @param H
 * 
 * @return 최대공약수
 */
int getGcd(int a, int b){
    int c;
    while (b > 0){
        c = a % b; // 두 수를 나눈 나머지 c
        a = b; // a 에 b를
        b = c; // b 에 c를 저장한다.
    }
    return a;
}

/**
 * 사용할 수 있는 정사각형의 개수를 구하는 함수
 * @param W     width
 * @param H     heigth
 * 
 * @return 걸린시간의 최소값
 */
int getNumberOfSquaares(int W, int H){
    // W-최대공약수의 너비, H-최대공약수의 높이의 정사각형에서 계속 같은 패턴이 반복되는 것을 확인.
    // 패턴내의 대각선이 지나쳐가는 정사각형의 수는 w+h-1 로 동일.
    // 전체 (W*H) 정사각형에 대입하면 W+H-최대공약수 가 대각선에 지나가는 것임을 알 수 있다.

    int gcd = getGcd(W, H); // 높이와 너비의 최대공약수
    int total = W*H; // 전체 정사각형 조각 수

    // 전체 - 대각선에 잘려나간 정사각형의 수
    int answer = (W*H) - (W+H-gcd);

    return answer;
}

int main(){  
    clock_t start = clock();

    // 입력값 스캔
    // W, H
    int W, H;
    scanf("%d %d", &W, &H);


    // 정사각형 개수 구하는 함수
    int answer = getNumberOfSquaares(W, H);
    printf("%d\n", answer);


    // 실행시간 출력
    clock_t end = clock();
    printf("실행시간: %lf초\n", (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
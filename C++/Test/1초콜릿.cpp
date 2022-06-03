#include<cstdio>
#include<iostream>
#include<time.h>

using namespace std;


/**
 * 팩토리얼을 구하는 함수
 * @param n     인자
 * @return      팩토리얼 결과
 */
unsigned long long factorial (int n){
    // 결과값 담을 변수
    unsigned long long result = 1;
    // 팩토리얼 구하는 반복문
    for (int i = 0; i < n; i++)
        result *= (i+1);

    return result;

    // 재귀함수 사용시 값이 커질수록 부하가 커진다고 함
    // if(n <= 1) 
    //     return 1;
    // else
    //     return (n * factorial(n-1));
}

/**
 * 분자의 수가 너무 커서 표현할 수 없음. (e.g. 24!)
 * 미리 분모 팩토리얼 중 하나로 약분하여 크기를 줄이기로 함
 * @param num       인자
 * @param fact      분모 팩토리얼 중 하나
 */
unsigned long long reducedFactorial (int num, int fact){
    // 결과값 담을 변수
    unsigned long long result = 1;
    // (fact + 1)부터 num까지의 곱을 구하는 반복문
    for (int i = fact; i < num; i++)
        result *= (i+1);

    return result;
}

/**
 * 초콜릿을 나누어 줄 수 있는 경우의 수를 반환하는 함수
 * @param N     초콜릿 받을 사람 수
 * @param m     인당 받을 최소 초콜릿 수
 * @param K     초콜릿 총 개수
 * @return      N명에게 K-mn 개를 나눠주는 경우의 수
 */
unsigned long long getNumberOfCases(int N, int m, int K){
    
    int r = K-(N * m); // 최소 수만큼 나눠주고 남은 초콜릿 수

    // 중복조합을 사용하기로 함
    // 공식 : (N - 1 + r) / ((n - 1)! * r!))

    // 20!까지 담을 수 있는 자료형 선택 후 변수 선언
    unsigned long long numerator = 0; // 분자
    unsigned long long denominator = 0; // 분모
    // 더 큰 분모로 약분하기 위한 if문
    if(N-1 >= r){
        // 분자를 (N-1)! 로 약분한 경우
        numerator = reducedFactorial(N + r - 1, N-1);
        denominator = factorial(r);
    } else {
        // 분자를 r! 로 약분한 경우
        numerator = reducedFactorial(N + r - 1, r);
        denominator = factorial(N-1);
    } 

    // 분자와 분모를 나눠 원하던 중복조합 값을 구한다
    unsigned long long  result = numerator / denominator;

    return result;
}
/**
 * 초콜릿은 총 Nm개 이상
 * 실행시간 0.2초 이하
 * @param N     초콜릿 받을 사람 수
 * @param m     인당 받을 최소 초콜릿 수
 * @param K     초콜릿 총 개수
 * 
 * 목표 : 초콜릿을 나누어 줄 수 있는 경우의 수 구하기
 * 
 * 입력 : N m k 
 * 출력 : 경우의 수, 실행시간
 */
int main() {
    clock_t start = clock();

    // 입력값 스캔
    int N, m, K;
    scanf("%d %d %d", &N, &m, &K);

    // 계산 함수
    unsigned long long  answer = getNumberOfCases(N, m, K);

    // 답 출력
    printf("%llu\n", answer);
    
    // 실행시간 출력
    clock_t end = clock();
    printf("실행시간: %lf초\n", (double)(end-start)/CLOCKS_PER_SEC);
    
    return 0;
}
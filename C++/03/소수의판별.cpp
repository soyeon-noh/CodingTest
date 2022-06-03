#include<cstdio>
#include<iostream>
using namespace std;

/**
 * 주어진 숫자가 소수인지 판별하는 함수
 * 
 * @param N
 * @return true     소수인 경우
 * @return false    소수가 아닌 경우
 */
bool isPrime(int N){
    // 1은 소수가 아니다
    if(N == 1) return false;

    // 소수라는 것을 default로 bool 변수 선언
    bool isPrime = true;

    // 가지치기 사용.
    // 약분은 짝으로 이루어지므로 
    // 루트 N보다 큰 값은 이전에 나온 약수쌍이므로 검사할 필요 x
    // i를 2부터 루트 N까지 반복하면 된다.
    for(int i = 2; i*i < N; i++){
        // 만약 2부터 N-1 사이 값으로 약분된다면
        if (N%i == 0) {
            // 소수가 아니다
            isPrime = false; 
            break;
        } 
    }
    return isPrime;
}

// 예시코드
// i * i 를 for문의 조건에 사용함으로 가지치기를 할 수 있다.

// bool isPrime(int N){
//     if(N==1) return false;
//     int cnt=0;
//     for(int i = 2; i*i <=N; i++){
//         if(N%i == 0) return false;
//     }
//     return true;
// }

void testcase(int caseIndex){
    int n; // 변수 n 선언
    scanf("%d", &n); // 변수 n에 정수하나를 입력받는다.

    bool result = isPrime(n); // n이 소수인지 판별하는 함수를 실행. 결과를 변수에 대입.

    printf("Case $%d\n", caseIndex); // 케이스 index를 출력
    if(result){ // n이 소수이면
        printf("YES\n");
    } else{ // n이 소수가 아니면
        printf("NO\n");
    }
}

int main(){
    int caseSize; // caseSize 변수 선언
    scanf("%d", &caseSize); // caseSize 정수를 입력받는다
    for(int caseIndex = 1; caseIndex <= caseSize; caseIndex++){ // caseSize 만큼 반복
        testcase(caseIndex); // caseIndex를 매개별수로 testcase함수 실행
    }

    return 0;
}
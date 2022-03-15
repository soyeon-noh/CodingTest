#include <stdio.h>
#include <iostream>

using namespace std;

/**
 * 1부터 N까지의 자연수의 합을 계산하는 함수
 * @param i
 * @return 
 */

// 1이상 i이하의 모든 자연수의 합을 계산하는 함수
int getRangeSumFromOne(int i){
    int answer = 0; // 합을 담을 변수 선언
    for(int j = 1; j <= i; j++){ // 1부터 i까지 반복
        answer += j; // 더한다
    }
    return answer;
}

// 1부터 1까지, ... 1부터 N까지의 모든 자연수의 합을 구하고 그것들의 합을 계산하는 함수
long long getAnswer(int N)
{
    long answer = 0;
    for(int i = 0; i < N; i++){ // N번 반복
        int rangesum = getRangeSumFromOne(i+1); // 파라미터: 1부터 N까지 
        answer += rangesum; // getRangeSumFroOne의 결과를 전부 더한다.
    }
    return answer;
}

int main()
{
    int n;
    scanf("%d", &n);
    long long answer = getAnswer(n);

    printf("%11d", answer);
    return 0;
}

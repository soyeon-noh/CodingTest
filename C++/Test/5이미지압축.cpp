#include <iostream>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

// 이 문제를 이해하지 못하겠습니다.

/**
 * 최소 변환 비용을 갖도록 이미지를 binary 코드로 변환하는 함수
 * @param numbers 
 */
void process (int W, const vector<int>& numbers) {

    // 입력된 수열을... level에 따라.. 변환? 한 벡터가 필요할 것 같다.
    vector<int> level;
    
    // binary 코드로 변환
    string code = "000000000";
 
    // 에러 구하기
    int error;

    
    // 변환 비용 계산
    // 전체 에러 + W * (변환 코드의 길이)
    int cost = 952;


    int codeSize = code.size();
    // int cost = error + W * codeSize;


    // 최소 변환 비용 출력
    printf("%d", cost);
    // 최소 변환 비용을 갖는 변환 코드 출력
    printf("%s", code);
}

int main(){
    clock_t start = clock();

    // 입력값 스캔
    // 이미지 수열의 길이 N
    // 가중치 W
    int N;
    int W;
    scanf("%d %d", &N, &W);

    // 수열을 담을 vector 변수
    vector<int> numbers;

    // 벡터변수에 수열 입력받기
    for(int i = 0; i < N; i++){
        int num;
        scanf("%d", &num);
        numbers.push_back(num);
    }

    // 수열이 담긴 벡터변수를 매개변수로 넘겨 process 함수 실행
    process(W, numbers);

    // 실행시간 출력
    clock_t end = clock();
    printf("실행시간: %lf초\n", (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
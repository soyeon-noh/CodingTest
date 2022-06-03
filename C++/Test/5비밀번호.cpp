#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

// 1. 중복이 있는 경우
// 2. 인접하지 않은 경우
/**
 * 입력받은 패턴이 가능한지 불가능한지 판별하여 결과를 출력하는 함수 
 * @param numbers 패턴이 순서대로 담긴 벡터변수
 */
bool process(const vector<int>& numbers){
    // 패턴 길이만큼 반복
    for(int i = 0; i < numbers.size(); i++){
        // 중복 검사. 
        // 중복이 존재하면 return false
        if(find(numbers.begin(), numbers.end(), numbers[i]) == numbers.end()){
            return false;
        }

        // 현재 입력 번호
        int n = numbers[i];
        // 다음 입력 번호
        int next = numbers[i+1];

        // 가능한 패턴인지 확인
        // 불가능하면 return false

        // 1인경우 3,7,9
        // 2인경우 8
        // 3인경우 1,7,9
        // 4인경우 6
        // 5인경우 
        // 6인경우 4
        // 7인경우 1,3,9
        // 8인경우 2
        // 9인경우 1,3,7
        if(n == 1){
            if(next == 3 || next == 7 || next == 9 ){
                return false;
            }   
        } else if(n == 2){
            if(next == 8 ){
                return false;
            }   
        }else if(n == 3){
            if(next == 1 || next == 7 || next == 9){
                return false;
            }   
        }else if(n == 4){
            if(next == 6 ){
                return false;
            }   
        }else if(n == 6){
            if(next == 4 ){
                return false;
            }   
        }else if(n == 7){
            if(next == 1 || next == 3 || next == 9 ){
                return false;
            }   
        }else if(n == 8){
            if(next == 2){
                return false;
            }   
        }else if(n == 9){
            if(next == 1 || next == 3 || next == 7){
                return false;
            }   
        }
    }
    // 아무 제약도 안 걸렸으면 true 반환
    return true;
}

int main(){  
    clock_t start = clock();

    // 입력값 스캔
    // 패턴의 길이 L
    int L;
    scanf("%d", &L);

    // 패턴을 순서대로 담을 벡터변수 선언
    vector<int> numbers;

    // 벡터변수에 패턴 입력받기
    for(int i = 0; i < L; i++){
        int num;
        scanf("%d", &num);
        numbers.push_back(num);
    }

    // 패턴이 담긴 벡터변수를 매개변수로 넘겨 process 함수 실행
    bool result = process(numbers);
    // 결과가 true면 YES, false면 NO 출력
    result? printf("YES\n") : printf("NO\n");

    // 실행시간 출력
    clock_t end = clock();
    printf("실행시간: %lf초\n", (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
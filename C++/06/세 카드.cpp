#include <stdio.h>
#include <vector> // push_back, size // 원소를 편하게 추가하기 위함
#include <algorithm> // sort, binary_search

using namespace std;

/**
 * 중복을 포함해 두 카드의 합으로 만들 수 있는 당첨번호의 수를 계산하는 함수
 * @param n     카드의 수
 * @param m     검사하려는 당첨번호의 수
 * @param cards     각 카드에 적힌 숫자들
 * @param target    검사하려는 각 당첨번호 리스트
 * @return
 */
vector<int> getPossibleTargets(int n, int m, int * cards, int* targets){
    vector<int> possibleTargets; // 만들 수 있는 당첨 번호들

    // 모든 카드를 오름차순으로 정렬한다. -- 바이너리 서치를 하기위한 조건
    // sort(시작위치, 끝 위치) -- n개 크기
    sort(cards, cards + n);

    // 당첨번호 수만큼 for문 돌리기
    // k가 당첨 가능한 수인지 확인해보자.
    for(int i = 0; i < m; ++i){
        int k = targets[i]; // 모든 당첨번호 타켓 k에 대하여
        bool possible = false; // 당첨번호가 존재하는지, 가능한지 여부

        // n번 반복
        for(int j = 0; j < n; ++j){
            int x = cards[j];   // 모든 카드 중 하나인 x에 대하여

            // 숫자조합의 중복을 없애기 위해 j까지만 반복
            for(int p = 0; p <= j; p += 1){ // 숫자조합의 중복 없애기
                int y = cards[p];   // 카드 중 하나 y를 선택한다
                int z = k - (x + y);    // k = (x+y) + z 가 되는 z를 계산한다
                
                // z가 cards[]에 존재하는지 binary_search 로 검색
                // 존재한다면
                if(binary_search(cards, cards + n, z) == true){// 시작위치, 끝위치, 찾을 값
                    // k = x + y + z 가 가능한 <x, y, z> 가 존재한다.
                    possible = true;
                    break;
                }
            }
            if(possible){ // 이미 찾았다면 탈출한다.
                break;
            }
        }
        if(possible){ // 세 카드의 합으로 k를 만들 수 있다면, 추가한다.
            possibleTargets.push_back(k);
        }
    }
    // 값이 정렬이 안되어 있을 가능성이 있다.
    // 오름차순으로 출력해야하므로 한번 더 sort해준다.
    sort(possibleTargets.begin(), possibleTargets.end());
    
    return possibleTargets;
}

int main(){
    int n; // 카드의 수 
    int m; // 검사 할 후보 당첨번호의 수
    scanf("%d %d", &n, &n);

    int* cards = new int[n]; // 카드번호를 담을 n개 크기의 배열 선언
    int* targets = new int[m]; // 당첨번호를 담을 m개 크기의 배열 선언

    // 각 카드 정보를 입력받는다
    for(int i = 0; i < n; i++){
        scanf("%d", &cards[i]);
    }

    // 각 후보 당첨번호를 입력받는다
    for(int i = 0; i < m; i++){
        scanf("%d", &targets[i]);
    }

    // 3개 숫자의 합으로 표현될 수 있는 당첨 번호 결과값
    vector<int> answers = getPossibleTargets(n, m, cards, targets);

    // answers에 담긴 데이터가 없다.
    if(answers.size() == 0){
        // 가능한 당첨번호가 없다면 NO를 출력한다.
        printf("NO");
    }
    // answers에 담긴 데이터가 있다.
    else{
        // 가능한 당첨번호가 존재한다면 그 목록을 출력한다.
        for(int i = 0; i < answers.size(); i++){
            // 공백 추가
            if(i > 0){
                printf(" ");
            }
            printf("%d", answers[i]);
        }
    }

    delete[] cards;
    delete[] targets;

    return 0;
}
#include <iostream>
#include <vector>
#include <time.h>
#include <queue>
#include <stack>


using namespace std;

/**
 * 카드를 뒤집은 횟수를 출력하는 함수
 * 불가능하면 return -1
 * 
 * @param cards 
 * @return int 
 */
int process(int K, vector<int>& cards){

    // 우선순위 큐를 오름차순으로 생성
    priority_queue< int, vector<int>, greater<int> > sorted;
    
    // 우선순위 큐에 card값들을 복사
    for(int i = 0; i < cards.size(); i++){
        sorted.push(cards.at(i));
    }

    // 카드 순서를 뒤집은 횟수 counting 변수
    int count = 0;
    stack<int> st;

    // 카드 수 만큼 반복
    for(int i = 0; i < cards.size(); i++){
    
        if(sorted.top() == cards.at(i) && i >= K){
            
            int num1 = i;
            // queue에 뒤집을 카드를 집어넣는다. 
            // for(int j = i; j > i-K; j--){
            for(int j = 0; j < K; j++){
                st.push(cards.at(num1));
                num1--;
            }

            int num2 = i;
            vector<int>::iterator it = cards.begin();
            cards.erase(it + num2 -1, it + num2 -1 - K);
          
            
            for(int j = 0; j < K; j++){
                cards.insert(it + num2 -1 - K, st.top());
                st.pop();
            }

            count++;

            if ( num2 - K < K ){
                return -1;
            }
        }
    }
    // 아무 제약도 안 걸렸으면 true 반환
    return -1;
}

/**
 * 카드의 개수 N
 * 한번에 뒤집어지는 카드의 수 K
 * 
 * 1부터 N까지의 정수로 이루어진 N개의 카드
 * 
 * 카드를 최소한으로 뒤집어서 오름차순으로 만들고
 * 최소한 뒤집은 횟수를 구하기
 * 
 * 카드 뒤집기는 스택을 사용해보자.
 * 
 * @return int 
 */
int main(){  
    clock_t start = clock();

    // 입력값 스캔
    // 카드 개수 N, 한번에 뒤집어지는 카드 수 K
    int N, K;
    scanf("%d %d", &N, &K);

    // 카드를 순서대로 담을 벡터변수 선언
    vector<int> cards;

    // cards 벡터변수에 카드 값 입력받기
    for(int i = 0; i < N; i++){
        int card;
        scanf("%d", &card);
        cards.push_back(card);
    }

    // process 함수에 cards 벡터변수를 매개변수로 넘겨 실행
    int result = process(K, cards);

    // 함수 return 값(최소한의 카드 뒤집는 횟수) 출력
    printf("%d\n", result);

    // 실행시간 출력
    clock_t end = clock();
    printf("실행시간: %lf초\n", (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
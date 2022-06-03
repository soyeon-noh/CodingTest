#include <iostream>
#include <set>

using namespace std;

int main() {
    // 입력받을 정수의 개수 입력받기
    int N;
    scanf("%d", &N);

     // set := 이전까지 등장한 모든 정수를 저장한 집합
     // 중복을 확인하기 위해 set 변수 선언
    set<int> set;

    // N번 반복
    for(int i = 0; i < N; i++){
        // 차례대로 입력받은 정수를 X에 할당
        int X;
        scanf("%d", &X);

        // set.find := 찾는 수가 있다면 해당 iterator, 없다면 end()의 iterator 반환
        // 때문에 count를 사용.
        
        // set에 있으면 중복이므로 "DUPLICATED"
        if(set.count(X) > 0){
            printf("DUPLICATED\n");
        // set에 없으먼 해당정수를 set에 담고 "OK"를 출력한다.
        } else {
            set.insert(X);
            printf("OK\n");
        }
    }

    return 0;
}
#include <stdio.h>
#include <map>

using namespace std;

// 입력 한도가 20만이기 때문에 2중 for문을 사용할 시 시간이 오래걸린다.
// map을 사용하여 1중 for문으로 해결 가능

int main() {

    // 입력변수 수 N을 입력받는다.
    int N;
    scanf("%d", &N);

    // 각 <정수, 빈도수> 형태로 key-value 를 저장할 Map 자료구조
    // frequencyMap := 이전에 입력된 정수들의 빈도수를 저장하고 있다.
    map<int, int> frequencyMap;

    // N만큼 반복하여 각 입력 숫자를 판별
    for(int i = 0; i < N; i++){
        // 판별할 수 X를 입력받는다
        // map에는 key값으로 들어간다
        int X;
        scanf("%d", &X);

        // frequencyMap[key] 는 value값이다
        // map의 value는 각 숫자가 등장한 횟수
        // 등장 횟수를 + 1 해주는 것
        frequencyMap[X]++; 

        // 1. map에는 중복된 key가 존재하지 않으므로 size()로 입력된 값의 종류 수를 알 수 있다.
        // 2. 그리고 map의 value이 입력 정수의 빈도수이므로 같이 출력하면 된다.
        printf("%lu %d\n", frequencyMap.size(), frequencyMap[X]);
    }    

    return 0;

}
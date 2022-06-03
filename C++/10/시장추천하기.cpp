#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // 후보수 입력받기
    int N;
    scanf("%d", &N);

    // 각 후보의 이름과 득표 수를 저장하는 key-value Map
    map<string, int> frequencyMap;

    // 가장 많은 득표수 
    int maxFrequency = 0; 

    // 각 이름이 하나 추가될 때마다 현재까지의 최다 득표 값 갱신,
    // 최다 득표 후보 리스트를 갱신한다.
    for(int i = 0; i < N; i++){

        // 후보 이름 입력받기
        string st;
        cin >> st;

        // st 후보의 득표값 +1
        frequencyMap[st]++;

        // 만약 st 후보의 득표값이 가장 높다면
        int k = frequencyMap[st];
        if(k > maxFrequency){
            // maxfrequency 변수의 값을 교체해준다.
            maxFrequency = k;
        }
    }

    // 최대 득표 후보 수를 출력한다.
    printf("%d\n", maxFrequency);

    
    // 최대 득표를 한 동점 후보들 이름을 사전순으로 출력해보자.
    map<string, int>::iterator it;

    // key값에 저장된 후보자 이르을 사전순으로 정렬
    // begin(), end() 사용
    for(it = frequencyMap.begin(); it != frequencyMap.end(); it++){
        // 맵 value값에 접근하는 것 second
        if (it -> second == maxFrequency){
            // iterator의 first를 통해
            // 후보 이름 값에 접근할 수 있다.
            printf("%s ", it->first.c_str());
        }
    }
}
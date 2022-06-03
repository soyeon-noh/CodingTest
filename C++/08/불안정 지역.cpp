#include <iostream>
#include <queue> // 우선순위 큐를 사용하기 위함
#include <vector>

using namespace std;

// 클래스 선언
class City {
    public:
    int index; // 도시의 인덱스
    int income; // 해당 도시의 소득

    City(int index, int income){
        this -> index = index;
        this -> income = income;
    }

    bool operator < (const City& o) const {
        return this -> income < o.income;
    }
    bool operator > (const City& o) const {
        return this -> income > o.income;
    }
};

int getMaximumRangeDifference (int n, int k, const vector<City>& cities){
    // 가장 큰 소득차를 담을 변수
    // 최종 반환 값
    int answer = 0;

    // 소득이 가장 적은 도시부터 pop 되는 우선순위 큐
    // 우선순위 큐 <데이터 타입, 컨테이너, 비교>
    // greater : 탑에서 봤을 때 오름차순으로 정렬
    //          탑이 제일 작은 것! 
    //          pop()을 사용하면 min이 삭제됨
    priority_queue<City, vector<City>, greater<City> > rangeMinimum;

    // 소득이 가장 높은 도시부터 pop 되는 우선순위 큐
    priority_queue<City> rangeMaximum;
    // 원래 아래처럼 써야하는데 뒤에 인자들을 삭제한 것임
    // priority_queue<City, vector<City>, less<City> > rangeMaximum;
 
    // 첫번째 두번째 값을 넣음
    for(int i = 0; i < k - 1; i++){
        // 탑이 가장 크도록 삽입 (내림차순)
        rangeMaximum.push(cities[i]);
        // 탑이 가장 작도록 삽입 (오름차순)
        rangeMinimum.push(cities[i]); 
    }
    // 그 다음 값을 넣음
    for(int i = k - 1; i < n; i ++){
        rangeMaximum.push(cities[i]);
        rangeMinimum.push(cities[i]); 
        // 현재 최대, 최소가 각각 top에 있고 범위만큼의 원소를 가진 우선순위 큐 2개가 있다.
        
        // 아래 반복문 다시 한번 보기
        // index : 위치정보
        // 범위에 존재하지 않은 값들을 삭제하는 과정
        while (rangeMaximum.top().index < i - k + 1) rangeMaximum.pop(); // 탑부분을 삭제
        while (rangeMinimum.top().index < i - k + 1) rangeMinimum.pop();
        // 현재 범위에서 구한 max와 min의 차를 구하고 
        // 더 큰 answer를 비교해 찾은후 
        answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);
    }

    // 반환
    return answer;
}

void process(){
    // 도시의 수, 연속된 도시의 수 입력받음
    int n, k;
    cin >> n >> k;
    // vector를 배열처럼 사용하기 위해 선언
    vector<City> cities;

    for(int i = 0; i < n; i++){
        int income;
        cin >> income;
        // 인덱스와 소득정보를 입력
        cities.push_back(City(i, income));
    }

    // 가장 큰 도시 소득차를 구하는 함수를 실행 후 answer에 저장
    int answer = getMaximumRangeDifference(n, k, cities);

    // print
    cout << answer << endl;

}

int main() {
    // 테스트 케이스 입력받기
    int caseSize;
    cin >> caseSize;

    // 테스트 케이스 수만큼 반복
    for(int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1){
        process();
    }
}
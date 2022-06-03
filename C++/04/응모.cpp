#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SERIAL_NUMBER = 100000;

/**
 * data[0] ~ data[n-1]에 등장한 시리얼 번호들에 대한 빈도수 테이블을 채우는 함수
 * @param data
 * @param n
 * @param table     table[x] := data배열에서 x가 등장한 횟수
 */
void fillFrequencyTable(const vector<int> & data, int n, vector<int> &table){
    // 백터 멤버함수로 클리어
    table.clear();
    // 백터 멤버함수로 크기 변경, 초기화
    table.resize(MAX_SERIAL_NUMBER + 1, 0);

    // 히스토그램 구하기
    for (int i = 0; i < n; ++i){
        int serial = data[i];
        table[serial] += 1;
    }
} 

/**
 * data[0] ~ data[n-1]에서 중복이 존재하지 않는 원소를 반환한다.
 * 단, 각 원소들은 오름차순으로 정렬되어 있어야 한다.
 * @param data  data[0] ~ data[n-1]에는 10만 이하의 자연수다.
 * @param n
 * @return
 */
vector<int> getUniqueElements(const vector<int>& data, int n){

    // 유일한 원소들 배열, 비어있는 벡터 생성, 배열과 달리 고정사이즈가 아님
    vector<int> ret; 

    // data에 대한 빈도수 테이블을 계산한다
    vector<int> table;
    fillFrequencyTable(data, n, table);

    // 존재할 수 있는 모든 시리얼 넘버에 대해 차례로 조회한다.
    for(int number = 1; number <= MAX_SERIAL_NUMBER; number += 1){

        // 히스토그램값이 1인 것
        // 전체 데이터에서 한 번만 등장한 number를 차례로 정답 리스트에 추가한다.
        if(table[number] == 1){
            ret.push_back(number);
        }
    }
    
    /* sorting을 생략할 수 있다!! 중요!! */
    // 오름차순 순서로 추가했기 때문에 ret에 대한 정렬은 불필요하다.
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<int> data = vector<int>(n);
    /**
     * 백터 컨테이너
     * - 자동으로 메모리가 할당되는 배열
     * 
     * <vector> 헤더파일 추가
     * using namespace std; -> 표준 네임스페이스를 사용하여...std::vector
     * vector의 선언
     * - vector<data type> 변수명
     * 
     * vector의 선언 예시
     * vector<int> v;   ->  비어있는 배열 선언
     * vector<int> v(5);    ->  0으로 초기화된 5개의 원소를 갖는 배열 생성
     * vector<int> v(5,2);  ->  5개의 원소를 갖는 배열, 모든 값을 2로 초기화.
     * 
     * vector는 여러가지 멤버함수를 가짐
     *  tttps://blockdmask.tistory.com/70
     * v.size();    ->  원소의 개수 리턴
     * v.clear();   ->  모든 원소 제거, 원소만 제거하고 메모리는 그대로 남아있음.
     * v.resize(n,3);   ->  크기를 n으로 변경하고, 인자의 값을 3으로 초기화
     * v.push_back(7);  ->  마지막 원소 뒤에 원소 7을 삽입
     * 
     * 원소 추가, 삭제, 크기변경이 어려운 배열의 단점을 극복가능
     * 
     */

    // 응모번호를 n개 입력받는다
    for(int i = 0; i < n; ++i){
        scanf("%d", &data[i]);
    }

    // 중복을 없애고, 오름차순으로 만드는 함수
    const vector<int> answer = getUniqueElements(data, n);

    // 각 원소들을 출력한다.
    for (int i = 0; i < answer.size(); ++i){
        if(i>0){// 첫 번재 원소가 아니라면 앞에 공백을 하나 추가한다
            printf(" ");
        }
        printf("%d", answer[i]);
    }

    return 0;
}
#include <cstdio>

using namespace std;

const int MAX_TABLE_LENGTH = 10000;

/**
 * data[0] ~ data[n-1] 에 등장한 번호드에 대한 빈도수 테이블을 채우는 함수
 * @param data
 * @param n
 * @param table     table[x] := data배열에서 x가 등장한 횟수
 */
void fillFrequencyTable(int data[], int n, int table[]){
    // 빈도수 변수 선언
    int frequent_number = 0;
    // table 배열의 모든 원소를 0으로 초기화
    // 기본 빈도수를 0으로 설정
    for (int i = 0; i < MAX_TABLE_LENGTH; i++){
        table[i] = 0;
    }

    // 입력받은 전화번호 수만큼 반복
    for (int i = 0; i < n; i++){
        // 입력받은 전화번호 를 하나씩 변수에 할당하고
        frequent_number = data[i];
        // 해당 변수번째 배열 원소에 1을 추가하여 빈도수를 +1한다.
        table[frequent_number] += 1;
    }
}

/**
 * cnt 배열이 해당 의미를 만족하도록 각 값을 채워보자 (초기값에 주의)
 * data[0] ~ data[n-1]사이에서 가장 많이 등장한 번호를 반환하는 함수
 * @param data
 * @param n
 * @return  가장 많이 등장한 번호. 여러개인 경우 사전순으로 가장 빠른 번호.
 */
int getFrequentNumber(int data[], int n){
    // 0000 ~ 9999 중에서 가장 많이 등장한 번호를 구해보자
    int frequent_number = 0;

    int table[MAX_TABLE_LENGTH]; // 0~ 9999 까지 숫자의 횟수를 카운트하는 히스토그램
    // 빈도수 테이블을 채우는 함수
    fillFrequencyTable(data, n, table);

    // 0~9999까지 반복
    for(int i = 0; i < MAX_TABLE_LENGTH; i++){
        // 가장 큰 빈도수를 가진 frequent_number를 찾아낸다.
        if(table[i] > table[frequent_number]) // 횟수가 같은 번호가 2개인 경우
            frequent_number = i;
    }

    return frequent_number;
}

int main() {
    // 전화번호 개수 입력받기
    int n;

    scanf("%d", &n);
    int* data = new int[n];

    // 전화번호 n개 입력받기
    for(int i = 0; i < n; i++){
        scanf("%d", &data[i]);
    }

    // 가장 빈번한 전화번호 return 
    int answer = getFrequentNumber(data, n);

    // 네 자리로 출력
    printf("%04d", answer);

    delete[] data;

    return 0;
}
#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

/**
 * 평균과의 차가 가장 작은 데이터의 번호를 반환하는 함수
 * 여려 가지라면 가장 빠른 번호를 반환한다.
 * 
 * @param data
 * @param n
 * @return int 가장 평균과 가까운 데이터의 번호 (1번부터 시작)
 */
int findIndex(int data[], int n){
    int sum = 0; // 총합 변수 선언
    int x = 0; // target data의 입력받은 순서를 담을 변수 선언
    for(int i = 0; i < n; i++) // 배열에 담긴 원소 수 만큼 반복
        sum += data[i]; // 배열의 모든 원소 총합을 sum에 대입
    
    for(int i = 1; i < n; i++){ // x가 0이므로 i는 1부터 시작
        /**
         * <cmatch>의 abs 함수
         * 인자로 들어온 int 타입의 num의 절대값을 반환하는 함수
         */
        // data에서 평균을 뺄 필요 없이 'data의 n배 - 총합' 을 사용
        int dx = abs(n * data[x] - sum); // x번째 원소의 평균에서의 거리 절대값
        int di = abs(n * data[i] - sum); // i번째 원소의 평균에서의 거리 절대값
        if(dx > di) //  i번째 원소가 더 평균에 가깝다면 x에 i를 대입
            x = i;
    }
    return x + 1;
}

int main()
{
    int n;
    int* data;
    scanf("%d", &n);
    data = new int[n];

    for (int i = 0; i < n; i++){
        scanf("%d", &data[i]);
    }

    int answer = findIndex(data, n);
    // index와 해당 index의 원소갑 출력
    printf("%d %d\n", answer, data[answer-1]); 
    
    delete[] data;
    return 0;
}

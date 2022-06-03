#include<cstdio>
#include<iostream>

using namespace std;

/**
 * 버블정렬
 * 오른쪽부터 왼쪽으로 최대값을 구해나가는 정렬방법
 * 선택정렬보다 빠르다고 한다.
 * @param data  배열 
 * @param n     배열 원소 수
 * @return      버블정렬된 배열
 */
void bubbleSort(int data[], int n){
    for(int i = 0; i < n; i++){

        int negativeCnt = 0;
        // 처음엔 n-1번 반복
        // 이후부터 배열의 마지막 배열에 하나씩 가장 큰 값이 정렬되므로
        // 정렬되지 않은 n-1-i 까지만 비교하면 된다.
        for(int j = 0; j < n-1-i; j++){
            // 오름차순을 부정하는 쌍이 나오면 2개 값의 자리를 교환
            if(data[j] > data[j+1]){
                // temp를 이용한 값 교환
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;

                negativeCnt++;
            }
        }

        // 오름차순을 부정하는 쌍이 하나도 없으면 이미 정렬된 것
        // for문을 멈출 필요가 있다.
        if(negativeCnt == 0) break;
    }
}

int main(){
    int n;
    int* data;

    // 배열 원소 수 입력받기
    scanf("%d", &n);
    // 배열 원소 수만큼 메모리 할당
    data = new int[n];

    // 배열에 저장
    for(int i = 0; i < n; i++){
        scanf("%d", &data[i]);
    }

    // 버블정렬 함수
    bubbleSort(data, n);

    // 공백과 함께 배열을 순서대로 출력
    for(int i = 0; i < n; i++){
        if(i > 0){
            printf(" ");
        }
        printf("%d", data[i]);
    }

    delete[] data;
    return 0;
}
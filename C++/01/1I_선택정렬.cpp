#include <stdio.h>
#include <iostream>

using namespace std;

/**
 * 주어진 범위의 최소값의 위치를 반환하는 함수
 * @param data  데이터 배열  
 * @param n     배열의 크기
 * @param begin 탐색할 가장 첫(왼쪽) 인덱스
 * @param end   탐색할 가장 마지막(오른쪽) 인덱스
 * @return int  data[begin] ~ data[end] 중 가장 작은 원소의 인덱스
 */

// @param (입력받은 배열, 배열의 크기, 비교를 시작할 index, 배열의 가장 마지막 index)
int getMinIndexInRange(int data[], int n, int begin, int end)
{
    int index = begin; // 가장 작은 원소의 index를 담을 변수 선언

    for(int i = begin; i <= end; i++){ // 시작점부터 끝점까지 포함한 반복문
        if(data[index] > data[i]) // 지금까지 가장 작은 원소보다 i번째 원소가 더 작은 경우
            index = i; // 가장 작은 원소 index를 i로 지정
    }
    // 모든 for문을 돌린 후
    return index; // 가장 작은 원소의 index가 담긴 변수를 return
}

int selectionSort(int data[], int n)
{
    // 가장 작은 원소가 담긴 i-1 번째 원소를 제외하고 for문을 돌린다.
    for(int i = 0; i < n; i++){
        //주어진 범위에서 가장 작은 원소의 위치를 찾는다.
        int minIndex = getMinIndexInRange(data, n, i, n-1);

        // 2개 숫자를 변경
        // 가장 작은 원소와 i번째 원소의 배열 위치를 교환
        int temp = data[minIndex]; 
        data[minIndex] = data[i];
        data[i] = temp;
    }
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

    selectionSort(data, n);

    for(int i = 0; i < n; i++){
        if(i > 0){
            printf(" ");
        }
        printf("%d\n", data[i]);
    }

    delete[] data;
    return 0;
}

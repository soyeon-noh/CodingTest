#include<cstdio>
#include<iostream>

using namespace std;

/**
 * 중복을 제외한 숫자의 종류의 수를 계산하는 함수
 * @param data  원본 배열
 * @param n     원본 배열의 크기
 * @return      숫자의 종류의 수
 */
int getElementTypeCount(int data[], int n){
    int countType = 1; // 최소 다양성 수는 1이므로 defalut는 1로 지정.

    for(int i=0; i<n-1; i++){ // n-1번 반복
        // 중복검사
        // 오름차순이므로 붙어있는 수만 비교해주면 된다.
        if(data[i] != data[i+1]) // i번째 원소와 i+1번째 원소가 다르다면 
            countType++; //다양성 카운트 + 1
    }

    return countType; // 다양성 수를 return
}
int main() {
    int n;
    int* data;

    scanf("%d", &n);
    data = new int[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &data[i]);
    }

    int answer = getElementTypeCount(data, n);

    printf("%d\n", answer);
    
    delete[] data;
    return 0;
}
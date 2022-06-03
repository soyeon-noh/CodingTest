#include<cstdio>
#include<iostream>

using namespace std;



/**
 * 주어진 배열이 오름차순인지 검사하는 함수
 * @param data
 * @param n     데이터의 수
 * @return      data[0] ~ data[n-1]이 오름차순이라면 true, else false
 */
bool isOrdered(int data[], int n){
    // 오름차순이 아닌경우 F
    bool isOrdered = true; // 오름차순인 것을 defalut 로 지정

    for(int i = 0; i<n-1; i++){ // n-1번 반복
        if(data[i]>data[i+1]){ // i번째 원소와 i+1번째 원소를 비교 하여
            isOrdered = false; // i번째 원소가 더 클 때 isOrdered를 false로 변경
            break; // 이후는 의미 없으므로 중단
        }
    }
    // printf(isOrdered ? "T":"F"); // 확인 
    return isOrdered;
}


int main(){
    int n;
    int* data;

    scanf("%d", &n);
    data = new int[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &data[i]);
    }

    bool result = isOrdered(data, n);

    if(result){
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    delete[] data;
    return 0;
}

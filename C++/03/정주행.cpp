#include<cstdio>
#include<iostream>
using namespace std;

// 아이디어를 떠올리는데 오랜시간이 걸림
// 다시 풀어보기.

/**
 * 배열의 N개의 원소가 연속적인 정수 수열로 표현될 수 있는지 판단하는 함수
 * @param data
 * @param n
 * @return
 */
bool isConsecutive(int data[], int n){
    // 첫번째 원소로 최대값, 최소값 초기화
    int max_data = data[0];
    int min_data = data[0];

    // max - min = n-1 의 여부만 판단하면 된다.
    for(int i = 0; i < n; i++){
        // max와 min은 별개이므로 각각 if문 사용
        if(max_data < data[i])
            max_data = data[i];
        if(min_data > data[i])
            min_data = data[i];
    }

    if(max_data - min_data == n-1)
        return true;
    else
        return false;
}

int main(){
    int n;
    int* data;
    
    // 숫자 개수 n 입력받기
    scanf("%d", &n);

    // 에피소드 번호 배열  입력받기
    data = new int[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &data[i]);
    }

    // 연속적인지 아닌지 판별하는 함수
    bool result = isConsecutive(data, n);

    // 연속적이면
    if(result){
        printf("YES");
    // 연속적이지 않으면
    } else {
        printf("NO");
    }

    delete[] data;
    return 0;
}
#include<cstdio>
#include<iostream>

using namespace std;

/**
 * 생일이 m월ㄹ인 가장 큰 키의 도토리를 찾는 함수
 * @param height    각 도토리의 키
 * @param month     각 도토리의 출생 월
 * @param n 도토리의 수
 * @param m 찾고자 하는 달
 * @return      month[k] == m 인 가장 큰 height[k]
 */

int getMaximumHeight(int height[], int month[], int n, int m){
    int maxHeight = -1; // 생일이 m월인 도토리가 없으면 -1을 출력)

    // (도토리의 수 - 1) 이 0이 될때까지 i--
    // 배열의 index에 맞추기위해 n-1을 사용. 
    // 또한 배열이 오름차순이므로 배열의 마지막부터 진행 (가지치기)
    for(int i=n-1; i>=0; i--){ 
        if(month[i] == m){ // i번째 도토리의 출생 월이 찾고자 하는 달과 같은가
            maxHeight=height[i]; // 같다면 가장큰 키로 i번째 배열 원소값을 대입
            break; // 이후는 불필요하므로 break 
        }
    }

    return maxHeight;
}

int main() {
    int n, m;
    int* height;
    int* month;

    scanf("%d", &n);
    height = new int[n];
    month = new int[n];

    for (int i=0; i<n; i++){
        scanf("%d", &height[i]);
    }

    for (int i = 0; i <n; i++){
        scanf("%d", &month[i]);
    }

    scanf("%d", &m);

    int answer = getMaximumHeight(height, month, n, m);

    printf("%d\n", answer);

    delete[] height;
    delete[] month;
    return 0;
}
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

/**
 * 배열에서 소속이 "AJOU"인 첫 원소와 마지막 원소를 출력하는 함수
 * @param school    각 사람들의 소속학교 정보 배열
 * @param n         사람들의 수
 * @return int 
 */
void printIndexes(string school[], int n){
    int first = -1; // 존재하지 않으면 -1
    int last = -1;  // 존재하지 않으면 -1

    for(int i = 0; i < n; i++){ // 사람의 수 만큼 반복
        if(school[i] == "AJOU"){ // i번째 원소가 "AJOU" 인가?
            if(first == -1) // 아직 한번도 "AJOU" 원소가 없었다면
                first = i + 1; // first 변수에 배열 index + 1 을 대입
            // 이미 "AJOU" 원소가 있었다면 
            last = i + 1; //last 변수에 배열 index + 1 을 대입
            
        }
    }

    printf("%d %d\n", first, last);
}

int main()
{
    int n;
    char buff[11];
    string* school;

    scanf("%d", &n);
    school = new string[n];

    for (int i = 0; i < n; i++){
        scanf("%s", buff);
        school[i] = buff;
    }

    printIndexes(school, n);
    delete[] school;
    return 0;
}

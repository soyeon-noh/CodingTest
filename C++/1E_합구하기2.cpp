#include <stdio.h>
#include <iostream>

using namespace std;

/**
 * 동아리 멤버들의 탑승 가능 여부를 출력하는 함수
 * 
 * @param data  각 멤버들의 몸무게 data[0] ~ data[n-1]
 * @param n     멤버들의 수
 * @param p     놀이기구 탑승 가능 체중 제한
 * @param q     놀이기구 최대 하중
 */
void solve(int data[], int n, int p, int q){
    int count = 0; // 탈 수 있는 인원수 
    int weight_sum = 0; // 탈 수 있는 인원의 체중 합

    for(int i = 0; i < n; i++){ // n명의 멤버들을 한명씩 검사
        if(data[i]<= p){ // 탐승 가능 체중 제한에 걸리는지 확인
            count++; // 탐승인 수 +1
            weight_sum += data[i]; // 탐승인 체중 합에 무게 추가
        }
    }

    printf("%d %d\n", count, weight_sum); // 탑승인 수, 탑승인 무게 합 print
    if(weight_sum <= q) // 탑승인 무게 합과 놀이기구 최대 하중을 비교해
        printf("YES\n"); // 탑승인 무게 합이 더 작으면 모두가 탈 수 있으므로 YES
    else 
        printf("NO\n"); // 아니면 NO를 출력한다.
}

int main()
{
    int n, p, q;
    int *data;

    scanf("%d %d %d", &n, &p, &q);
    data = new int[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &data[i]);
    }

    solve(data, n, p, q);

    delete[] data;
    return 0;
}

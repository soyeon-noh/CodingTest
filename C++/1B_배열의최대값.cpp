#include <stdio.h>
#include <iostream>

using namespace std;

/**
 * 배열의 최대값을 계산하는 함수
 * 
 * @param data
 * @param n
 * @return data[0] ~ data[n-1]중 최대값.
 */

int getMax(int data[], int n)
{
    int answer = data[0];
    for(int i=1; i < n; i++)
        if(data[i]>answer)
            answer=data[i];
            
    return answer;
}

int main()
{
    int n; // 입력받을 숫자의 수 
    int *data;

    scanf("%d", &n);
    data = new int[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &data[i]);
    }

    int answer = getMax(data, n);

    printf("5d\n", answer);
    delete[] data; // 메모리해제
    return 0;
}

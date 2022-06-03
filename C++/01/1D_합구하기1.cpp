#include <stdio.h>
#include <iostream>

using namespace std;

/**
 * @param data
 * @param n
 * @return data[0] ~ data[n-1]의 합
 */

int getSum(int data[], int n){
    int answer = 0;
    for(int i=0; i<n; i++)
        answer+= data[i]; // answer= answer + data[i]

    return answer;
}

int main()
{
    int n;
    int *data;
    
    scanf("%d", &n);
    data = new int[n];
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &data[i]);
    }

    int answer = getSum(data, n);
    
    printf("%d\n", answer);
    delete[] data;
    return 0;
}

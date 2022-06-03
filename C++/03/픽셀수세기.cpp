#include<cstdio>
#include<iostream>

using namespace std;

// 풀이 방법을 생각해내기 어려움. 
// 이해필요. 다시 한번 풀어보기.

/**
 * 원의 부등식 (x^2 + y^2 < r^2) 을 만족하면 
 * 좌표가 원의 내부에 있는 것이다.
 * 이것이 이번 문제해결의 핵심.
 */

/**
 * 왼쪽 아래 좌표가 (x,y)인 픽셀이 반지름 R인 원에 포함되는가?
 * @param   x
 * @param   y
 * @param   R
 * @return  포함된다면 true, else false
 */
bool isInside(long long x, long long y, long long R){
    // x^2 + y^2 < R^2 부등호를 만족하면 원 내부. (등호는 필요 없나?)
    long long sqd = x*x  + y*y;
    if(sqd < R*R) 
        // 부등호를 만족하면 포함이므로 true
        return true;
    // 부등호를 만족하지 않으면 포함하지 않으므로 false
    return false;
}
void testcase(int caseIndex){
    // 반지름 10만 이하이므로 int로 선언
    int R;
    scanf("%d", &R);

    long long sum = 0; // 1사분면에 존재하는 총 픽셀의 수
    long long y = R; // y값을 R로 초기화

    // 원을 중심으로부터 4등분하여 사분면을 만든 뒤 1사분면의 픽셀수를 구하는 방식
    // x값을 지정하고 그 x값에서의 가장 높은 픽셀을 구한 후 그보다 낮은 높이의 픽셀을 포함시킨다.

    // x값을 0부터 반지름(R)까지 반복
    for(long x = 0; x <= R; x++){
        long long height = 0;

        // 반지름부터 1씩 줄여가며 위에서 부터 내려오다가
        for (; y >= 0; y--){
            // 가장 최초로 원 안에 포함된 픽셀 (x, y) 을 구해낸다.
            // 이 그룹의 높이는 (y+1)이 된다.
            if(isInside(x, y, R)){ 
                // height 값이 그 x값의 픽셀 수가 된다. (1사분면 기준)
                height = (y + 1);
                break;
            }
        }
        
        // 너비는 1이므로
        // 구한 높이를 모두 더하면 1사분면의 픽셀수다.
        sum += height;
        
    }

    // 픽셀 계산이 끝나면 caseIndex, 픽셀 수 출력
    printf("#%d\n", caseIndex);
    printf("%lld\n", sum * 4); // 모든 사분면의 픽셀 수
}


int main(){
    // test case 수를 입력받는다.
    int caseSize;
    scanf("%d", &caseSize);

    // test case 수 만큼 반복
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1){
        testcase(caseIndex);
    }

    return 0;
}
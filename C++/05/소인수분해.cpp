#include <cstdio>
#include <vector>

using namespace std;

/**
 * 자연수 N을 구성하는 모든 소인수를 반환하는 함수
 * 
 * @param N
 * @return 
 */
vector<int> factorize(int n){ // 1억이하니까 int써도된다

    // 여기 이 함수내부를 통째로 이해하고 외워놓자 (중요)

    vector<int> factors;    
    // sqrt(N)이하의 자연수 div에 대하여 (1 제외)
    for(int div = 2; div * div <= n; div += 1){ 
        // div가 N의 약수라면
        while (n % div == 0){
            // 이 때, div보다 작은 약수는 모두 처리되었으므로 div는 소인수임이 보장된다.

            // 소인수 목록에 div를 추가한다.
            factors.push_back(div);

            // N에서 div를 소거해준다.
            // 그러므로 이후에는 div를 제외한 소인수를 찾게 된다.
            // (이부분 잊지말기!!)
            n /= div;
        }
    }
    if(n > 1){
        // 소인수를 찾지 못하고 남아있는 N이 존재한다면, 소수일 수 밖에 없다.
        // 이를 소인수에 추가한다.
        factors.push_back(n);
    }
    
    return factors;
}

void process(int caseIndex){
    // 숫자 n을 입력받는다.
    int n;
    scanf("%d", &n);

    // factorize 함수에 N을 전달한 후 결과값을 factors 변수에 저장
    vector<int> factors = factorize(n);

    printf("#%d:\n", caseIndex);
    // factors 변수에 담긴 값을 하나씩 전부 출력
    for (int i = 0; i < factors.size(); ++i){
        if(i > 0){
            printf(" ");
        }
        printf("%d", factors[i]);
    }
    printf("\n");
}

int main() {
    // 테스트 케이스 수를 입력받는다.
    int caseSize;
    scanf("%d", &caseSize);

    // 테스트 케이스 수만큼 반복
    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex){
        process(caseIndex);
    }

    return 0;
}
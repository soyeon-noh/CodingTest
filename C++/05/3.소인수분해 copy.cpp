#include <cstdio>
#include <vector>

using namespace std;

/**
 * 자연수 N을 구성하는 모든 소인수를 반환하는 함수
 * 
 * @param N
 * @return 
 */
vector<long long> factorize(long n){

}

void process(int caseIndex){
    long long n;
    scanf("%lld", &n);

    vector<long long> factors = factorize(n);

    printf("#%d:\n", caseIndex);
    for (int i = 0; i < factors.size(); ++i){
        if(i > 0){
            printf(" ");
        }
        printf("%lld", factors[i]);
    }
    printf("\n");
}

int main() {
    int caseSize;
    scanf("%d", &caseSize);

    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex){
        process(caseIndex);
    }
}
#include <cstdio>
#include <vector>

using namespace std;

// 소인수 분해를 빠르게
class Sieve {
    public:
    int maximumValue;       // 에라토스테네스의 체에서 다룰 
    vector<bool> isPrime; // 각 숫자별 소수 여부
    Sieve(int maximumValue){
        this -> maximumValue = maximumValue;
        this -> isPrime.assign(maximumValue + 1, false);
        this -> fillSieve();
    }

    /**
     * @param num
     * @return 'num'이 소수라면 true, 그렇지 않으면 false
     */
    bool isPrimeNumber(int num) const {
        return this -> isPrime[num];
    }

    /**
     * isPrime 배열의 값을 채우는 함수
     */
    void fillSieve(){

    }
};

vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve){
    vector<int> primes;

    for(int num = from; num <= to; num += 1){
        if(sieve.isPrimeNumber(num)){
            primes.push_back(num);
        }
    }

    return primes;
}

void process(int caseIndex, const Sieve& sieve){
    int L, R;
    scanf("%d%d", &L, &R);

    vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve);

    printf("Case $%d:\n", caseIndex);
    printf("%d\n", (int)allPrimeNumbers.size());
}

int main() {
    const int MAX_VALUE = 1000000;
    Sieve sieve = Sieve(MAX_VALUE);

    int caseSize;
    scanf("%d", &caseSize);

    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex){
        process(caseIndex, sieve);
    }
}
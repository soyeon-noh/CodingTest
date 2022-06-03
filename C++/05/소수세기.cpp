#include <cstdio>
#include <vector>

using namespace std;

// 소인수 분해를 빠르게
class Sieve {
    public:
    int maximumValue;       // 에라토스테네스의 체에서 다룰 
    vector<bool> isPrime; // 각 숫자별 소수 여부
    Sieve(int maximumValue){ // 매개변수에 100만이 대입된다.
        this -> maximumValue = maximumValue;
        // vector는 index가 0부터 시작하므로 maximumValue + 1로 지정
        // 두번째 인자는 소수가 아니다라는 것을 디폴트로 지정
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
        // 전처리하는 전체 과정을 한번더 살펴보자.
        // 이 함수는 아직 완전히 이해x
        isPrime.assign(this -> maximumValue, true); // 처음에는 모두 소수라고 저장한다.
        isPrime[0] = isPrime[1] = false; // 0과 1은 소수가 아니므로 미리 false로 처리

        for(int num = 2; num <= maximumValue; num += 1){
            // [2, N] 사이의 모든 자연수 num에 대해
            // 이미 소수가 아니라고 체크되어있다면 건너 뛴다.
            if(isPrime[num] == false){
                continue;
            }

            // 이 때 num은 소수다.
            // 그러므로 num의 모든 배수를 소수가 아니라고 체크한다.
            // num보다 작은 k에 대해 mul = num * num 으로 표현되는 모든 자연수는 이미 처리됐다.
            // 그러므로 mul = num * num 부터만 처리하면 된다.
            // 최대 100만의 제곱까지 -> longlong 타입

            // 제곱부터 맥시멈까지
            for(long long mul = (long long) num * num; mul <= maximumValue; mul += num){
                // [!!] 이 때 mul에 대해서, mul을 나누는 '최초의 소인수 num'이 등장한다.
                // 이 정보를 저장해두면 소인수 분해를 할 때 유용하다.
                int index = (int) mul;
                // 업데이트
                isPrime[index] = false;
            }
        }

    }
};

vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve){
    // 벡터 변수 선언
    vector<int> primes;

    // from부터 to까지 반복하며
    for(int num = from; num <= to; num += 1){
        // 만약 그것이 소수이면
        if(sieve.isPrimeNumber(num)){ // 이미 전처리해놔서 물어보기만 하면된다.
            // 소수를 primes에 push
            primes.push_back(num);
        }
    }

    return primes;
}

void process(int caseIndex, const Sieve& sieve){
    // 범위를 입력받음
    int L, R;
    scanf("%d%d", &L, &R);

    // 모든 소수를 저장한 vector 변수
    vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve);

    // 출력형식에 맞게 출력
    printf("Case $%d:\n", caseIndex);
    printf("%d\n", (int)allPrimeNumbers.size());
}

int main() {
    // 100만이라는 값 전처리
    const int MAX_VALUE = 1000000;
    // 1부터 maxmumvalue까지 범위에 어떤값이 소수이고 아닌지 미리 데이터화해서 저장하고 있는 전처리
    // Sieve = 채
    // 구조체 선언, MAX_VALUE 인자값을 넘긴다.
    Sieve sieve = Sieve(MAX_VALUE); 

    // 케이스 사이즈 입력받는다.
    int caseSize;
    scanf("%d", &caseSize);

    // 케이스 사이즈만큼 프로세스 반복
    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex){
        process(caseIndex, sieve);
    }
}
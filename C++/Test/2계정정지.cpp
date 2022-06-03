#include<cstdio>
#include<iostream>
#include<time.h>
#include<string>
#include<cstring>

using namespace std;

/**
 * 두 문자열 비교 ( * 의 경우 제외하고 비교 )
 * 
 * 문자열 비교시 함수와 자료형에 대한 이해 부족으로 계속 오류 발생.
 *      compare 식에 클래스 형식이 있어야 하는데 "char" 형식이 있음
 *      string으로 형변환 했으나 그대로. 
 * 결국 해결 못하고 제출합니다.
 * 
 * @return ture 일치
 * @return false 불일치
 */
bool compareString(string& id, string& k){
    // strcmp 함수 사용
    // - 일치하는 문자열이 있는지 확인
    // 일치할 경우 : 0 반환
    // 일치하지 않을 경우 : 음수 혹은 양수 반환
    const char* str1 = id;

    for(int i = 0; i < id.length(); i++){
        // 클래스
        string strId(id);
        string strK(k);

       strncmp(id.at(i), k.at(i));

        // 제재 아이디 문자에 * 가 들어 있는 경우 다음 문자 비교
        if( strK.at(i).compare("*") == 0) continue;

        // 비교
        if (strId.at(i).compare(k.at(i)) != 0) {
            return false;
        }
    }
    return true;
}


/**
 * 각 제재 대상자의 경우의 수 구하는 함수
 * @return 
 */
int getCount(int N, string id[], int m, string k){

    int count = 0;

    // 전체 유저를 돌아가면서 일치하는 게 있는지 비교
    for(int i = 0; i < N; i++){
        // 비교해서 일치하는 경우 count + 1
        if( compareString(id[i], k)) count++ ;
    }
    
    // 제재 대상자 아이디와 일치할 가능성이 있는 id의 수를 반환
    return count;
}

/**
 * 모든 제재 대상자의 경우의 수 구하는 함수
 * 
 * @param N 
 * @param id 
 * @param m 
 * @param k 
 * @return int 
 */
int getNumberOfCases(int N, string id[], int m, string k[]){

    int num = 1;
    int* cases = new int[m];
    
    // 경우의 수를 구한다.
    for(int i = 0; i < m; i++){
        int num = num * getCount(N, id, m, k[i]);
    }

    return num;
}


/**
 * 계정이 정지되어야 할 계정 정지 대상자 목록은 
 * 몇 가지 경우의 수를 가지는 지 구하라.
 * 
 * @param N     게임을 이용하는 이용자 수 (1~8)
 * @param id     이용자 ID 배열
 * @param m     제재 대상자 수
 * @param k     제재 대상자 아이디 배열
 * 
 * @return int 
 */
int main() {
    clock_t start = clock();

    // 사용자 아이디 입력값 스캔
    int N;
    scanf("%d", &N);

    string* id = new string[N];
    for(int i = 0; i < N; i++){
        cin >> id[i];
    }

    // 제재 대상자 아이디 입력값 스캔
    int m;
    scanf("%d", &m);

    string* k = new string[m];
    for(int i = 0; i < m; i++){
       cin >> k[i];
    }
    cout << "k : " << k << '\n';


    // 경우의 수 출력
    int answer = getNumberOfCases(N, id, m, k);
    printf("%d", answer);

    delete[] id;
    delete[] k;

    // 실행시간 출력
    clock_t end = clock();
    printf("실행시간: %lf초\n", (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
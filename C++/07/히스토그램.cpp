#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

// 이해를 다 하지 못함. 다시보기.
// 데이터 오름차순 정렬 후 삭제.
// 그때마다 면적을 구해서 면적의 최대값을 구하는 방식.
// 출력에 제대로 나오지 않음.

class Histogram {
public:
    int height;     // 히스토그램의 높이
    int leftX;      // 인덱스 혹은 히스토그램의 왼쪽 변의 x 좌표
    int rightX;     // 히스토그램의 오른쪽 변의 x 좌표
    
    Histogram() {}

    // index와 heigth를 설정하는 함수
    Histogram(int index, int height){
        this->leftX = index;
        this->rightX = this->leftX + 1; // 각 히스토그램은 너비가 1이므로
        this->height = height;
    }
};

/**
 * 가장 큰 직사각형 면적을 구하는 함수
 * 
 * @param histograms    히스토그램이 차례로 저장된 배열
 * @return 
 */
long long getLargestRectangleArea(const vector<Histogram>& histograms){
    long long answer = 0; // 최대 직사각형의 넓이
    
    // 현재 우측으로 확장 가능성이 있는 히스토그램들
    stack<Histogram> stk;

    // 구현상 편의를 위해 가장 왼쪽에 높이 0까지 가상의 히스토그램 추가
    stk.push(Histogram(-1, 0));
    for(int i = 0; i < histograms.size() + 1; i++){
        // 왼쪽부터 오른쪽 히스토그램까지 차례로
        Histogram h;
        if(i < histograms.size()){
            h = histograms[i];
        } else {
            // if(i == n)
            // 구현상 편의를 위해 가장 오른쪽에 높이 0까지 가상의 히스토그램 추가
            h = Histogram(histograms.size(), 0);
        }

        // 이전에 확장중이던 히스토그램들 중, h보다 높이가 높은 히스토그램들은
        // 더이상 확장될 수 없다 => 최대 넓이가 결정된다.
        while(stk.size() 
            > 1 && stk.top().height > h.height){
            // 확장중이던 히스토그램
            Histogram lh = stk.top(); // 삭제하기 전의 top을 나중에 사용하기 위함
            stk.pop();

            // 그 이전의 히스토그램 (왼쪽 확장의 끝)
            Histogram bh = stk.top();

            // 현재 추가된 h의 바로 왼쪽까지 확장중이었다.
            // 너비, 높이, 면적을 구한다
            long long width = abs(h.leftX = bh.rightX);
            long long height = lh.height;
            long long area = width * height;

            // 최대 값 갱신
            answer = max(answer, area);    
        }
        // h를 새로이 추가한다
        stk.push(h);
    }
    return answer;
}

/**
 * 각 직사각형의 높이를 입력받고 Histogram 벡터에 셋팅하는 함수.
 * getLargestRectangleArea 를 호출한 후 그 결과를 출력하는 함수.
 */
void process(){
    int n;
    cin >> n;

    // Histogram 클래스 타입으로 벡터변수 선언
    vector<Histogram> histograms;
    for(int i = 0; i < n; i ++){
        int height;
        histograms.push_back(Histogram(i, height));
    }

    // 20억보다 클 수 있으므로 long long으로 선언
    // 가장 큰 넓이를 반환받는 getLargestRectangleArea 함수 호출
    long long answer = getLargestRectangleArea(histograms);
    cout << answer << endl;
}

// 메인함수
int main() {
    // 케이스 사이즈 입력받음
    int caseSize;
    cin >> caseSize;

    // 케이스 사이즈 만큼 반복
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++){
        process();
    }
}
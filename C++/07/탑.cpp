#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 클래스 선언
class Tower {
    public:
    int index; // 타워의 인덱스
    int height; // 타워의 높이
    int targetTowerIndex; // 이 타워의 레이저를 수신하는 대상 타워

    Tower(int index, int height){
        // 각각 입력받은 인자로 셋팅
        this -> index = index;
        this -> height = height;
        this -> targetTowerIndex = 0; // 0으로 초기화
    }

    // 셋팅 함수
    void setTargetTowerIndex(int targetTowerIndex){
        this -> targetTowerIndex = targetTowerIndex;
    }

    // 반환 함수
    int getTargetTowerIndex() {
        return this -> targetTowerIndex;
    }
};

/**
 * 파라미터로 주어지는 각 타워들에 대해 타겟 타워를 계산하는 함수
 * 
 * @param n     타워의 수
 * @param towers 왼쪽~오른쪽 순서로 저장된 타워 배열
 */
void findTargetTowers(vector<Tower>& towers){
    // 현재 다른 타워의 신호를 수신할 가능성이 있는 타워들
    // 스택 변수 선언
    stack<Tower> stk;

    // 시간복잡도 O(N)
    // 입력받은 타워의 개수만큼 반복
    for(int i = 0; i < towers.size(); i++){
        Tower& t = towers[i];   // 각 타워 t에 대해 0번째 원소부터 차례로 고려
        int targetTowerIndex = 0;   // 타워 t의 신호를 수신할 후보 개수 (초기값 null)

        // 먼저 저장된 stack이 없거나 지금까지 가장 높은 타워인 경우
        while(stk.empty() == false
            && stk.top().height < t.height){
                // t보다 높이가 낮은 타워들은 이후에도 수신 가능성이 없으므로 제거
                stk.pop();
        }

        // t 이상의 높이를 가진 타워가 남아있다면
        if(stk.size() > 0){
            // t는 해당 타워를 타겟으로 정하게 된다.
            targetTowerIndex = stk.top().index;
        }
        // 계산한 타겟 정보를 저장한다.
        t.setTargetTowerIndex(targetTowerIndex);

        // t는 마지막에 등장했으므로 다른 타워의 신호를 수신할 수 있다. 등록.
        stk.push(t);
    }
}

int main() {
    // 탑의 개수 입력받기
    int n;
    cin >> n;

    // 탑 백터 변수 선언
    vector<Tower> towers;
    // 탑의 개수만큼 반복
    for(int i = 0; i < n; i++){
        // 탑 높이 입력받기
        int hi;
        cin >> hi;
        // 인덱스 1부터 저장
        // 타워 높이 저장
        towers.push_back(Tower(i + 1, hi)); 
    }

    // 각 타워가 송신하는 레이저에 대해 타겟을 모두 계산한다.
    findTargetTowers(towers);

    // 탑의 수만큼 반복
    for(int i = 0; i < n; i++){
        if(i > 0){
            cout << " ";
        }
        // 각 탑에서 발사한 레이저 신호를 수신한 탑들의 번호를 출력
        Tower t = towers[i];
        int targetIndex = t.getTargetTowerIndex();
        cout << targetIndex;
    }
}
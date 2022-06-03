#include <iostream>
#include <vector>
#include <queue> // 큐 변수를 사용하기 위한 헤더파일

using namespace std; // 표준 namespace

class Player{
    public:
    int index; // 멤버변수

    Player(int index = 0){
        this -> index = index; // 인덱스값 설정하는 멤버함수
    }
};

/**
 * 조세퍼스 게임을 수행하여 각 플레이어가 제거된 순서를 리스트로 반환하는 함수
 * @param n     플레이어의 수
 * @param m     매 턴마다 건너 뛸 사람의 수
 * @param players   좌석에 앉아 있는 순서대로 주어지는 플레이어 정보
 * @return vector<Player> 
 */
vector<Player> getDeadPlayersList(int n, int m, const vector<Player>& players){
    // 현재 게임에서 제외된 플레이어들의 리스트
    // 최종 반환값
    vector<Player> deadPlayers;

    // 아직 게임에서 제외되지 않는 플레이어들의 리스트
    queue<Player> playerQueue;

    // 사람들의 번호를 큐에 입력
    for(int i = 0; i < n; i+= 1){
        playerQueue.push(players[i]); // 1 2 3 4 5 6 7 
    }

    // 사람 수만큼 반복
    for(int i = 0; i < n; i++){
        // (m-1)명의 사람을 건너뛴다. 다시 1을 + 해줌
        // m의 배수의 숫자를 제외.
        int jump = 1 + (m-1) % playerQueue.size();
        for(int j = 0; j < jump - 1; j+= 1){
            // 맨 앞의 사람을 임시보관
            Player p = playerQueue.front();
            // 맨 앞의 사람을 삭제
            playerQueue.pop();
            // 없앴던 사람 p를 다시 뒤에 push
            playerQueue.push(p); 
            // 2 3 4 5 6 7 1 -> 3 4 5 6 7 1 2 
        }

        // m번째 사람은 게임에서 제외한다.
        Player dead = playerQueue.front();
        playerQueue.pop();

        // 위에서 찾은 사람을 제외 리스트에 추가한다.
        deadPlayers.push_back(dead);
    }

    return deadPlayers;
}

void process(int caseIndex){
    int n, m;
    scanf("%d %d", &n, &m);

     vector<Player> players;
    for(int i = 0; i < n; i++){
        // 숫자가 1부터 시작이므로 i + 1
        // 뒤에 삽입
        players.push_back(Player(i+1));
    }

    // 제외된 숫자를 담을 리스트 deadPlayers
    vector<Player> deadPlayers = getDeadPlayersList(n, m, players);

    // 나온 결과를 순서대로 출력
    for(int i = 0; i < n; i++){
        if (i > 0){
            printf(" ");
        }
        
        Player p = deadPlayers[i];
        printf("%d", p.index);
    }
    printf("\n");
}

int main() {
    // 테스트 케이스 입력받음
    int caseSize;
    cin >> caseSize;

    // 테스트 케이스만큼 반복
    for(int caseIndex = 1; caseIndex <= caseSize; caseIndex++){
        process(caseIndex);
    }
}
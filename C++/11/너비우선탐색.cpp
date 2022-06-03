#include<iostream>
#include<queue>

using namespace std;

// 그래프를 인접행렬로 표현한 map변수 선언 및 0으로 초기화
int map[10][10] = {0};
// 방문할 예정인 노드를 visit 배열로 선언 및 0으로 초기화
int visit[10] = {0};
// 너비우선탐색은 queue로 구현할 수 있다. 
queue<int> q;
// 정점의 개수 num
// 간선의 개수 edge_num 선언
int num, edge_num;

// 너비우선탐색 함수
void bfs(int v){
    // 방문한 정점 v를 출력 (여기서는 v=1로 고정)
    cout << v << "\n";
    // 큐변수 q에 방문한 정점 데이터를 push한다.
    q.push(v);
    // 비어있지 않으므로 돌아가는 while 반복문
    while(!q.empty()){
        // front 정보를 node 변수에 저장
        int node = q.front();
        // pop() 함수를 통해 없앤다.
        // 그럼 q에 아무것도 남지않는다.
        q.pop();

        // 정점의 수만큼 반복
        // node와 연결되어있는 모든 경로를 탐색할때까지 반복되는 반복문
        for(int i = 0; i < num; i++){

            // node와 연결되어있는, 존재하는 간선인가 (map[node][i] == 1)
            // 방문한 적이 없는가 (visit[i] == 0)
            // 두가지를 만족해야 if문이 돌아간다.
            if(map[node][i] == 1 && visit[i] == 0){
                // 이제 방문했으므로 visit을 1로 업데이트
                visit[node] = 1;
                // 방문한 노드 i를 출력 (여기서 순서대로 출력되는 정점들이 경로이다.)
                cout << i << "\n";
                // 다시 q에 i를 push해준다.
                q.push(i);
            }
        }
    }
}

int main(){
    // 정점의 개수 num
    // 간선의 개수 edge_num 을 입력받음
    cin >> num >> edge_num;

    // 간선의 수만큼 반복
    for(int i = 0; i <<edge_num; i++){
        // 그래프의 간선 정보를 입력받음
        int v1,v2;
        cin >> v1 >> v2;
        // 무방향 그래프이므로 [v1][v2]와 [v2][v1]을 동일하게 여기며 1을 할당
        map[v1][v2] = map[v2][v1] = 1;
    }
    // 너비우선탐색 함수. 1정점에서 시작하므로 매개변수로 넣어준다.
    bfs(1);
    return 0;
}
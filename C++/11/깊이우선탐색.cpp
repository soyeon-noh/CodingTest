#include<iostream>

using namespace std;

// 그래프를 인접행렬로 표현
// 원래 정점이 8개여서 [8][8]이어도 되지만 크기를 넉넉하게 잡음
int maps[10][10];
// 정점 방문 순서와 방문여부를 저장하기 위한 배열
int visited[10]={0};
int num;

// maps 의 모든 값을 0으로 초기화
void init() {
    for (int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            maps[i][j] = 0;
        }
    }
}


void dfs(int v){
    // 먼저 매개변수로 들어온 시작정점을 출력한다.
    // 여기서 순서대로 출력되는 정점들이 깊이우선탐색의 경로인 것이다.
    cout<<v<<endl;
    // 이미 방문(계산)한 정점을 제외시키기 위해 1 -> 0 으로 값 변경
    visited[v] = 0;
    // 간선 수만큼 반복
    for(int i = 0; i <= num; i++){
        // 인접행렬 값인 maps가 1고, 
        // 방문을해야하는 곳이라는 visited[i]가 1일때 
        // 조건문 실행
        if(maps[v][i] && visited[i]){
            // v에서 -> i로 이동 하여 
            // 다시 또 스스로인 dfs(i)를 수행한다. (재귀)
            dfs(i);
        }
    }
}


int main(void){

    // 간선 정보 입력받는 변수
    int v1, v2;
    // maps[][] 값을 0으로 초기화하는 함수
    init();
    // 간선의 갯수를 num 변수에 입력받음
    cin>>num;
    // 간선의 개수 만큼 반복하여 인접행렬을 완성시킨다.
    for(int i = 0; i < num; i++){
        // 간선 정보를 입력받음
        cin >> v1 >> v2;
        // 간선 정보를 map[][] 변수에 입력받는다.
        // 무방향 그래프이므로
        // 정점 v1과 v2를 잇는 간선은 map[v1][v2], map[v2][v1] 이 된다.
        maps[v1][v2] = maps[v2][v1] = 1;
        // 각 정점 v1, v2를 방문할 예정임을 int 1 (true)로 표현하여 배열에 값을 저장한다.
        visited[v1] = visited[v2] = 1;
    }
    // 1이라는 정점에서 시작한다는 뜻으로 dfs함수의 매개변수로 넘겨 실행시킨다.
    dfs(1);

    return 0;
}
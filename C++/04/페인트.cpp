#include <cstdio>
#include <vector>

using namespace std;

const int MAX_SEAT_NUMBER = 1000;
const int MAX_COLOR_NUMBER = 100;

// 좌석들을 한 번 색칠하는 이벤트에 대한 정보
class Painting{
    public:
    int left;
    int right;
    int color;

    Painting() {}

    Painting(int left, int right, int color){
        this->left = left;
        this->right = right;
        this->color = color;
    }
};

/**
 * data[0] ~ data[n-1] 에 등장한 번호들에 대한 빈도수 테이블을 채우는 함수
 * @param data
 * @param n
 * @param table     table[x] := data배열에서 x가 등장한 횟수
 */
void fillFrequencyTable(int data[], int n, int table[]){
    // 모든 색갈의 빈도수를 0으로 초기화
    for(int i = 0; i < MAX_COLOR_NUMBER; i++){
        table[i] = 0;
    }
    // 좌석에 있는 색을 하나씩 반복해가며 빈도수를 1씩 추가한다.
    for(int i = 0; i < n; i++){
        int color = data[i];
        table[color] += 1;
    }
}

/**
 * @param n     좌석의 수. 좌석은 0 ~ (n-1)번의 번호를 가진다
 * @param m     좌석을 칠한 횟수
 * @param paintings     좌석들을 색칠한 이벤트들의 정보
 */
void solve(int n, int m, const Painting* paintings){
    // 좌석들의 색을 담을 배열 선언
    int* seats = new int[n];

    // 처음 좌석은 전부 0번 색으로 칠해져 있으므로 
    // 전부 0으로 초기화
    for (int i = 0; i < n; i++){
        seats[i] = 0;
    }

    // 색칠 정보들이 주어진 순서대로 각 좌석을 색칠( 색상 대입) 한다.
    for (int i = 0; i < m; i++){

        // 모든 색칠 정보 p에 대하여 차례로
        const Painting &p = paintings[i];

        // 각 페인팅 정보마다 좌석의 색을 업데이트 해준다.
        for (int j = p.left; j <= p.right; j++){
            seats[j] = p.color;
        }
    }

    // 모든 색칠을 완료한 이후의 색상 정보를 사용하여
    // 모든 색상에 대한 빈도수 테이블을 계산한다.
    int *table = new int[MAX_COLOR_NUMBER];
    fillFrequencyTable(seats, n, table);

    int minColor = seats[0]; // 가장 적게 등장한 색상
    int maxColor = seats[0]; // 가장 많이 등장한 색상


    // 전체 color 수만큼 반복해서 빈도수를 추출하고
    // 가장 적은 색과 가장 많은 색도 찾아낸다.
    for (int color = 0; color < MAX_COLOR_NUMBER; color += 1){
        if(table[color] == 0){ // 한번도 등장하지 않은 색
            continue;
        }

        // 한 번 이상 등장한 모든 색갈 color에 대하여

        // 가장 적게 등장한 색이 아직 없거나, color가 더 적게 등장한 경우
        if (table[minColor] > table[color]){ 
            minColor = color;
        }
        // 가장 많이 등장한 색이 아직 없거나, color가 더 많이 등장한 경우
        if(table[maxColor] <  table[color]){
            maxColor = color;
        }
    }


    printf("%d\n", maxColor);
    printf("%d\n", minColor);

    delete[] seats;
}


/**
 * @param n     좌석의 수. 좌석은 0 ~ (n-1)번의 번호를 가진다
 * @param m     좌석을 칠한 횟수
 */
int main() {
    // 좌석의 수와 좌석을 칠한 횟수를 입력받는다.
    int n, m;
    scanf("%d %d", &n, &m);

    // paintings[i] := 1번째에 일어난 색칠 이벤트의 정보
    Painting* paintings = new Painting[n];

    // 좌석을 칠한 횟수만큼
    // 가장 왼쪽, 가장 오른쪽, 색정보를 배열에 저장한다.
    for (int i = 0; i < m; ++i){
        scanf("%d", &paintings[i].left);
        scanf("%d", &paintings[i].right);
        scanf("%d", &paintings[i].color);

        /** 이부분을 놓치기 쉬움. 다시 확인하기 */
        // 좌석의 번호는 1번부터 시작하므로, 0 ~ (n-1) 범위로 맞추기 위하여 1씩 빼준다
        paintings[i].left -= 1;
        paintings[i].right -= 1;
    }

    // 문제의 정답을 구하는 함수
    solve(n, m, paintings);

    return 0;
}
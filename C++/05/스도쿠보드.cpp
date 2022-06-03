#include <cstdio>

using namespace std;

const int MAX_ROW = 9;
const int MAX_COL = 9;

// 클래스 선언
class SudokuBoard{
    public:
    // 칸의 번호로 행의 번호를 계산하는 메소드
    int getRowByIndex(int index){
        // 칸의 번호에 대해 마디를 가지고 증가하므로 몫으로 계산할 수 있다.
        // ex) 13 -> 4
        // index를 0부터 시작하게 만들어놓는 편이 규칙을 계산하기 편하므로 -1을 해준다.
        // ex) 1행의 경우: 1은 1/9 = 0인 반면에 9는 9/9 = 1이 나와버린다.
        return (index - 1) / 9 + 1;
    }

    // 칸의 번호로 열의 번호를 계산하는 메소드
    int getColByIndex(int index){
        // 칸의 번호에 대해 규칙적으로 순환하므로 나머지로 계산할 수 있다.
        // 열 또한 index - 1로 같은 열은 같은 값이 나오도록 조정
        return (index - 1) % 9 + 1;
    }

    // 칸의 번호로 그룹 번호를 계산하는 메소드
    int getGroupByIndex(int index){
        int r = getRowByIndex(index);
        int c = getColByIndex(index);
        return getGroupByPosition(r, c);
    }

    // 칸의 위치 (행, 열)로 그룹 번호를 계산하는 메소드
    int getGroupByPosition(int row, int column){
        // 행의 번호를 통해, 해당 행에 존재하는 그룹들 중 가장 왼쪽 그룹의 번호를 알 수 있다.
        // (row-1)/3 : 왼쪽 그룹중 몇번째인가 (0~2)
        // (row-1)/3 * 3 : 전체 그룹중 가장 왼쪽의 그룹의 번호가 무엇인가 (0, 3, 6)
        // (row-1)/3 * 3 + 1 : 전체 그룹중 가장 왼쪽의 그룹의 번호가 무엇인가 (1, 4, 7)
        int left = ((row - 1)/ 3) * 3 + 1;
        // 열의 번호를 통해, 해당 행에 존재하는 그룹들 중 몇 번째 그룹에 속하는지 알 수 있다.
        int offset = ((column - 1)/3);
        return left + offset;
    }

    // 보너스로 한번 찾아보자
    // 칸의 위치 (행, 열)로 칸의 번호를 계산하는 메소드
    int getIndexByPosition(int row, int column){
        // 행과 열 번호를 알면 반대로 인덱스도 쉽게 계산할 수 있다!
        // ex) 14인 경우  1*9 + 4%9 + 1 = 14
        return (row - 1) * 9 + (column - 1) % 9 + 1;
    }
};

void process(int caseIndex){
    // index 변수 선언
    int index;
    // index 변수에 값을 입력받음
    scanf("%d", &index);

    // 클래스 객체 생성
    SudokuBoard board = SudokuBoard();

    // 칸의 번호로 행, 열, 그룹 번호를 계산한다.
    int row = board.getRowByIndex(index);
    int col = board.getColByIndex(index);
    int group = board.getGroupByIndex(index);

    // 테스트케이스 순서 출력
    printf("Case #%d:\n", caseIndex);
    // 행, 열, 그룹 출력
    printf("%d %d %d\n", row, col, group);
}

int main(){
    // 테스트케이스 수를 입력받는다.
    int caseSize;
    scanf("%d", &caseSize);

    // 테스트케이스 1부터 입력받은 수까지 caseSize만큼 반복
    for(int caseIndex = 1; caseIndex <= caseSize; ++caseIndex){
        process(caseIndex);
    }
}
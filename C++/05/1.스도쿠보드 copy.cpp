#include <cstdio>

using namespace std;

const int MAX_ROW = 9;
const int MAX_COL = 9;

class SudokuBoard{
    public:
    // 칸의 번호로 행의 번호를 계산하는 메소드
    int getRowByIndex(int index){

    }

    // 칸의 번호로 열의 번호를 계산하는 메소드
    int getColByIndex(int index){

    }

    // 칸의 번호로 그룹 번호를 계산하는 메소드
    int getGroupByIndex(int index){
        int r = getRowByIndex(index);
        int c = getColByIndex(index);
        return getGroupByPosition(r, c);
    }

    // 칸의 위치 (행, 열)로 그룹 번호를 계산하는 메소드
    int getGroupByPosition(int row, int column){

    }

    // 칸의 위치 (행, 열)로 칸의 번호를 계산하는 메소드
    int getIndexByPosition(int row, int column){

    }
};

void process(int caseIndex){
    int index;
    scanf("%d", &index);

    SudokuBoard board = SudokuBoard();

    // 칸의 번호로 행, 열, 그룹 번호를 계산한다.
    int row = board.getRowByIndex(index);
    int col = board.getColByIndex(index);
    int group = board.getGroupByIndex(index);

    printf("Case #%d:\n", caseIndex);
    printf("%d %d %d\n", row, col, group);
}

int main(){
    int caseSize;
    scanf("%d", &caseSize);

    for(int caseIndex = 1; caseIndex <= caseSize; ++caseIndex){
        process(caseIndex);
    }
}
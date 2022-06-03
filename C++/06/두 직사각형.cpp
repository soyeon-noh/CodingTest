#include <iostream>
#include <cstdio>

using namespace std;
/**
 *  두 직사각형의 left, right, top, bottom 좌표를 입력받아 면적을 출력하는 함수
 */ 
int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb){
    
    int l, r, t, b;
    l = max(la, lb); // 더 오른족에 있는 left 좌표
    r = min(ra, rb); // 더 왼쪽에 있는 right 좌표
    t = min(ta, tb); // 더 밑에 있는 top 좌표
    b = max(ba, bb); // 더 위에 있는 bottom 좌표

    // 면적이 존재하지 않는 경우를 고려해야함.
    if(l<=r && b<=t)
        // 면적을 구한 걸 return
        return ((r-l) * (t-b));
    // 존재하지 않은 경우 바로 
    return 0;
}

void test_case(){
    // a 직사각형 좌표
    int ax, ay, bx, by;
    // b 직사각형 좌표
    int px, py, qx, qy;
    // 좌표 입력받기
    scanf("%d %d %d %d", &ax, &ay, &bx, &by);
    scanf("%d %d %d %d", &px, &py, &qx, &qy);

    int la, ra, ba, ta; // 직사각형 a
    la = min(ax, bx); // left 좌표
    ra = max(ax, bx); // right 좌표
    ta = max(ay, by); // top 좌표
    ba = min(ay, by); // bottom 좌표

    int lb, rb, bb, tb; // 직사각형 b
    lb = min(px, qx);
    rb = max(px, qx);
    tb = max(py, qy);
    bb = min(py, qy);

    // 두 직사각형의 좌표를 통해 면적 산출
    int answer = get_area(la, ra, ta, ba,
                            lb, rb, tb, bb);

    printf("%d\n", answer);
}

int main() {

    // 테스트케이스 수 입력
    int t;
    scanf("%d", &t);

    // t가지의 테스트 케이스 입력 및 출력 함수
    for(int i = 0; i < t; i++){
        test_case();
    }

    return 0;
}
#include<cstdio>
#include<cmath>
#include<climits>
#include<iostream>

using namespace std;

// 구조체 선언
class Point2D {

// 좌표 변수 자체는 private
private:
  int x;
  int y;      

// x, y 좌표를 외부에서 입력받는 함수는 pulbic
public:
    Point2D(int x = 0, int y = 0){
        this -> x = x;
        this -> y = y;
    }


    /**
     * 구조체 내부 함수1
     * 2차원 평면 상에서 점 this부터 점 target까지 거리의 제곱을 계산하는 함수
     * @param   target
     * @return
     */
    int getSquaredDistanceTo(const Point2D &target) const {
        // 거리기때문에 절대값 연산 abs() 함수 사용
        // this 좌표와 target 좌표의 x, y값을 각각 빼준다.
        int dx = abs(this -> x - target.x);
        int dy = abs(this -> y - target.y);
        // dx의 제곱 + dy의 제곱 return
        return dx*dx + dy*dy;

    }

    /**
     * 구조체 내부 함수2
     * getSquaredDistanceTo의 결과에 루트를 씌워 거리를 계산하는 함수
     * @param target 
     * @return double 
     */
    double getDistanceTo(const Point2D &target) const {
        double sqd = (double) this->getSquaredDistanceTo(target);
        return sqrt(sqd);
    }
};


int main(){
    int n;
    Point2D *points;

    // 천체의 수 N을 입력받는다
    scanf("%d", &n);
    // N개의 구조체 배열을 선언
    points = new Point2D[n];

    // N개의 (x,y) 좌표쌍을 입력받는다
    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);

        // 좌표쌍을 porints 구조체 배열에 할당
        points[i] = Point2D(x, y);
    }

    // INT_MAX는 20억정도의 int의 최대값
    // 이후 갱신할 값이다.
    int min_sqd = INT_MAX;
    // 가장 작은 거리만큼 떨어진 천체 쌍의 수. default
    int min_cnt = 0;

    // n번 반복
    for(int i = 0; i < n; i++){
        // 이미 중복된 비교를 피하기 위해 0부터 i까지 반복
        for(int j = 0; j < i; j++){
            // i번째 천체의 좌표 points[i]와 j번째 천체의 좌표 points[j] 사이의 거리의 제곱을 구한다
            int sqd = points[i].getSquaredDistanceTo(points[j]);
            // 현재까지 가장 적은 거리값보다 작으면
            if (sqd < min_sqd){
                // 최소거리를 갱신
                min_sqd = sqd;
                // 카운트도 1로 갱신
                min_cnt = 1;
            // 현재까지 가장 적은 거리값과 같으면
            } else if(sqd == min_sqd){
                // 카운트를 1씩 증가시킨다
                min_cnt++;
            }
        }
    }

    // 최소거리를 구해 출력
    double distance = sqrt(min_sqd);
    // 소수 첫째자리까지 출력해야하므로 포멧을 .1f 로 작성
    printf("%.1f\n", distance);
    // 최소거리인 천체 수 카운트를 출력
    printf("%d\n", min_cnt);

    delete[] points;
    return 0;
}
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

// 다시 풀어보기. 이해 안 된 부분 많음.


class Point2D {
    public: 
    int x;
    int y;
    int index;

    // index, x, y를 매개변수로 받아서 값 설정
    Point2D(int index, int x, int y){
        this -> index = index;
        this -> x = x;
        this -> y = y;
    }

    // index가 없으면 1로 초기화
    Point2D(int x, int y){
        this -> index = 1;
        this -> x = x;
        this -> y = y;
    }

    long long getSquaredDistanceTo(Point2D target){
        // 두 좌표간의 제곱거리를 계산
        // 두 좌표를 잇는 정사각형의 면적
        long long dx = abs(this -> x - target.x);
        long long dy = abs(this -> y - target.y);
        return dx * dx + dy * dy;
    }
    
    double getDistanceTo(Point2D target){
        // 두 좌표간의 실수 거리를 계산
        long long sqd = this -> getSquaredDistanceTo(target);
        return sqrt(sqd);
    }

    // class 타입의 set을 사용하기 위해 대소관계를 지정해줘야한다.
    bool operator < (const Point2D& other)const {
        // 각 좌표의 우선순위를 비교하기 위한 비교 연산자

        // x좌표가 다르다면 x좌표를 기준으로 비교한다.
        if(this -> x != other.x){
            return this -> x < other.x;
        }

        // x좌표가 같다면 y좌표를 기준으로 비교한다.
        return this -> y < other.y;
    }
};

long long getMaximumSquareArea(int n, const vector<Point2D>& points){
    long long answer = 0;

    // 모든 점을 Set에 저장한다
    // default: less(오름차순), datatype이 class이므로 대소관계 정의 필요
    // 대소관계를 operator를 따로 작성해서 지정해줘야함
    set<Point2D> pSet; 
    for(int i = 0; i < n; i++){
        pSet.insert(points[i]);
    }
    // 임의의 a와 b, 두 점을 잡는다.
    for(int i = 0; i < n; i++){
        Point2D pa = points[i];
        for(int j = 0; j < n; j++){
            Point2D pb = points[j];

            // 둘이 같은 점인 경우 제외 (거리 0)
            if(i==j) continue; 

            // 두 기준점 pa와 pb를 지정한다.
            // 선분 pa-pb가 정사각형의 한 변이라고 하자.

            // 두 점의 거리(선분의 길이)의 제곱은 정사각형의 넓이가 된다.
            long long area = pa.getSquaredDistanceTo(pb);

            // 이미 구한 사각형보다 넓이가 작을 수 밖에 없다면 건너뛴다.
            if(area < answer) continue;

            // pa -> pb 방향의 x, y 좌표에 대한 거리를 구한다.
            int dx = pb.x = pa.x;
            int dy = pb.y = pa.y;

            // 벡터 <dx, dy>를 90도로 회전시키면 <-dy, dx>가 된다.
            // pa와 pb에 벡터 <-dy, dx>를 각각 더해 정사각형을 구성하는 두 점
            // pd, pc 를 계산할 수 있다.
            Point2D pd(pa.x - dy, pa.y + dx);
            Point2D pc(pb.x - dy, pb.y + dx);

            // pd, pc 와 결정적이므로 이 점이 pSet에 존재하는 점인지 검사하면 된다.
            if(pSet.count(pc)> 0 && pSet.count(pd) > 0){
                // find를 사용하려면 아래와 같이 작성
                // if(pSet.find(pc) != pSet.end() && pSet.find(pd) != pSet.end()){
                answer = max(answer, area);
            }
        }
    }

    return answer;
}   

// 이 함수 다시보기
void process(){
    // 좌표의 개수 입력받기
    int n;
    scanf("%d", &n);

    // pint2D (index, x, y)를 매개변수로 가지는 class
    // vector 로 변수 선언
    vector<Point2D> points;

    // 좌표의 개수만큼 반복
    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);
        // 벡터 변수에 Point2D 클래스를 뒤에서부터 삽입해나간다.
        // n개의 클래스가 삽입될 것.
        points.push_back(Point2D(i, x, y));
    }

    // 실제로 면적을 구하는 함수를 호출, 반환값 구하기
    double answer = getMaximumSquareArea(n, points);

    cout << fixed <<setprecision(2) << answer << endl;

}

int main(){
    // 테스트케이스 수를 입력받기
    int caseSize;
    scanf("%d", &caseSize);

    // 테스트케이스 수 만큼 process 반복
    for(int caseIndex = 1; caseIndex <= caseSize; caseIndex++){
        process();
    }
}

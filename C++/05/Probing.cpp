#include <cstdio>
#include <vector>

using namespace std;


// 클래스 구조체 선언
class TicketTable {
    public:
    // 변수 선언
    vector<bool> used;
    int length;

    TicketTable(int length){
        this -> length = length;
        // 초기값을 사용안한 경우인 false로 설정
        this -> used.assign(length, false);
    }

    /**
     * 사용자의 회원 번호로 지급받게 될 행운권 번호를 계산하는 메소드
     */
    int findEmptyIndexByUsrId(int userId){
        int index = userId % length; // 가장 초기에 시도할 티켓 번호
        
        // 사용된 티켓 번호라면 다음 번호를 조사해나간다.
        while (this -> isEmpty(index) == true){ 
            /** 방금 찾던 번호에 + 1을 한 다음 
             * 혹시 이전 index가 (length-1)이여서 
             * index = length이 되면 vector변수의 자리값을 벗어나므로
             * %length 를 해준 값을 반환 */ 
            index = (index + 1) % length; 
        }
        return index; // 사용되지 않은 인덱스를 찾아서 반환한다.

    }

    /**
     * 해당 행운권 번호가 이미 사용 중인지 여부를 반환하는 메소드
     */
    bool isEmpty(int ticketIndex){
        // 이미사용중이라면 true가 반환된다.
        return this->used[ticketIndex]; // 사용여부 <==> used[ticketIndex]
    }

    /**
     * 티켓 사용 여부를 갱신하기 위한 메소드
     */
    void setUsed(int index, bool status){
        this->used[index] = status; 
    }
};

// 전체 티켓의 수, 요청 고객의 수, 
vector<int> getTicketNumbers(int n, int m, const vector<int>& ids){
    vector<int> tickets;
    TicketTable table = TicketTable(n);

    for(int i = 0; i < m; i++){
        // 인덱스 값을 넘겨주기
        int userId = ids[i];
        // 행운권 번호를 계산하는 메소드 호출
        int ticketIndex = table.findEmptyIndexByUsrId(userId);
        // tickets 벡터변수에 해당 행운권 번호를 push
        tickets.push_back(ticketIndex);
        // 해당 행운권 번호가 사용됐음을 알 수 있도록 used[index]에 ture 값 저장
        table.setUsed(ticketIndex, true);
    }

    // 행운권 번호들을 return 
    return tickets;
}

int main(){
    // n: 전체 티켓의 수 (1이상 5000이하 자연수)
    // m: 요청 고객의 수 (1이상 1000이하의 자연수)
    // m <= n
    int n, m;
    // n과 m 입력받기
    scanf("%d%d", &n, &m);

    // ids라는 벡터변수 사용
    // 멤버함수를 사용하기 위해 vector 변수로 선언 (ex. push)
    vector<int> ids(m);
    for (int i = 0; i < m; ++i){
        scanf("%d", &ids[i]);
    }
    // 티켓번호를 반환하는 함수의 결과값을 저장
    vector<int> tickets = getTicketNumbers(n, m, ids);
    printf("%lu\n", tickets.size());
    for(int i = 0; i < tickets.size(); ++i){
        printf("%d\n", tickets[i]);
    }
    return 0;
}
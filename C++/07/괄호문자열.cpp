#include <iostream> // 입출력
#include <string> // 문자열
#include <stack> 
#include <vector>

using namespace std;

class Parenthesis {
    public:
    bool type;  // 열린 괄호면 true, 닫힌 괄호면 false
    int index; // 해당 괄호의 인덱스

    Parenthesis(int index, bool type){
        this-> index = index;
        this-> type = type;
    }

    // '(' 의 경우 type = true 를
    // 그 외(')')의 경우 false 를 저장하는 내장함수
    Parenthesis(int index, char c){
        this -> index = index;
        if(c == '('){
            this -> type = true;
        } else {
            this->type = false;
        }
    }
};

/**
 * 괄호들의 정보가 차례로 배열로 주어질 때, 올바른 괄호 문자열인지 판단하는 함수 
 *
 * @param n     괄호 문자열의 길이
 * @param parentheses   괄호 문자열에 대한 배열
 * @return bool VPS 여부
 */
bool isValidParentheses(const vector<Parenthesis>& parentheses){
    // 현재 짝을 찾지 못한 열린 괄호들만 저장
    // 닫힌 괄호가 나오면 탑에 저장된 열린 괄호를 삭제해 나감
    // 탑 원소 삭제만 이루어짐 -> 스택 변수로 선언
    stack<Parenthesis> st;

    for(int i = 0; i < parentheses.size(); i++){
        // 왼쪽부터 오른쪽의 괄호를 차례로 조회한다.
        // 벡터 변수이므로 모든 원소 접근 가능
        Parenthesis p = parentheses[i];

        if(p.type == true){
            // 열린 괄호라면 짝을 찾을 때 까지 스택에 보관한다.
            st.push(p);
        } else if (p.type == false){
            // 닫힌 괄호 p에 대하여

            if(st.size() > 0){
                // 가장 마지막에 추가된 열린 괄호와 짝을 맞출 수 있으므로 제거한다.
                st.pop();
            } else {
                // 짝을 맞출 수 있는 열린 괄호가 없다면 올바르지 않은 과롷 문자열이다.
                return false;
            }
        }
    }
    
    // 만약 st.empty() == 0
    if(st.size() > 0){
        // 아직 스택에 짝을 찾지 못한 열리 노갈호가 남아 있다.
        return false;
    }
    return true;
}

/**
 * 테스트케이스를 입력받고 문자하나씩 vector에 push 하는 함수
 * isValidParentheses 함수를 호출한 결과를 출력하는 함수
 * 
 */
void process(){
    string str;
    cin >> str;

    // 미리 정의한 parentheses 클래스를 이용해 vector 선언
    vector<Parenthesis> parentheses;
    // 벡터는 (front~back) 모든 위치의 원소 접근 가능 (동적 배열로 사용)
    // 스택은 탑 위치의 원소만 접근 가능
    for (int i = 0; i < str.length(); ++i){
        // 스택의 back에 데이터를 추가하는 push_back 함수 사용.
        // 인텍스와 스택내부 원소를 추가
        parentheses.push_back(Parenthesis(i, str[i]));
    }

    // 입력받은 문자열이 VPS인지 판별하는 함수 호출.
    bool isValid = isValidParentheses(parentheses);

    if(isValid){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

// 메인 함수
int main() {
    // 케이스사이즈 입력뱓기
    int caseSize;
    cin >> caseSize;

    // 케이스 수만큼 반복
    for (int caseIndex = 0; caseIndex < caseSize; caseIndex++){
        // 각 케이스가 VPS인지 판별하고 출력하는 함수 호출
        process();
    }
}
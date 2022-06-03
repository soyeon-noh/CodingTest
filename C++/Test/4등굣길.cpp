#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {  //공백을 기준으로 슬라이싱하여 string 벡터에 차례대로 넣어주는 함수

    vector<string> result; //슬라이싱된 string들을 저장할 string 벡터 선언
    stringstream ss(input); //stringstream 객체 ss를 선언하고  input 문자열 (공백이 포함되어있는 문자열)로 초기화                
    string temp;

    while (getline(ss, temp, delimiter)) { //입력스트림 객체인 ss에서 delimiter를 만날때까지의 string을 뽑아내temp에 저장
        result.push_back(temp); 
    }
    return result;
};
int main(){  
   //이외의 내용은 직접 구현
    string timetable;  //시간 하나를 담을 변수
    vector<string> timetables;  //시간들을 담을 벡터변수  
    cin.ignore();  //버퍼에 앤터가 남아있으면 getline에서 이미 입력을 받은 것으로 처리하기 때문에 getline전에 버퍼를 비워줌
    getline(cin, timetable);  //엔터가 들어오기 전까지 공백을 포함하여 문자열 입력받기
    timetables = split(timetable, ' ');  //split 함수를 이용해서 입력받는 문자열을 공백을 기준으로 슬라이싱 (c++은 spilt 함수를 지원하지 않기때문에 직접 구현)
   //이외의 내용은 직접 구현
};
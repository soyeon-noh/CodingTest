#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int MAX_LENGTH = 100000;

class MyString{
private:
        char *characters;
        int length;

public:
    MyString(const char * str){
        this->length = strnlen(str, MAX_LENGTH);
        this->characters = new char[this->length];
        for(int i = 0; i < this->length; i+= 1){
            this-> characters[i] = str[i];
        }
    }

    MyString(const string & original){
        this->length = original.length();
        this->characters = new char[this->length];
        for(int i = 0; i< this->length; i+=1){
            this->characters[i] = original[i];
        }
    }

    ~MyString(){
        delete[] characters;
    }
        
    /**
     * @param o         비교할 문자열 (오른쪽 항)
     * @return true     this가 o보다 시전순으로 앞선다면 true
     * @return false    else
     */
    bool operator < (const MyString &o) const{
        // 더 짧은 길이의 단어수를 n으로 지정
        int n = min(this->length, o.length);

        for (int i = 0; i < n; i++){ // n번 반복
            if(this->characters[i] < o.characters[i]){ // this와 o의 문자 비교
                return true; // this가 앞선다면 true
            } else if(this->characters[i] > o.characters[i]){
                return false; // 아니라면 false
            }
        }
        // 여기까지 했는데 return 하지 않았다면 어떤경우인가?
        // algorithm algo 와 같이 짧은 단어의 글자수까지 동일하다면
        // 더 글자수가 적은 쪽이 사전에 먼저나온다.
        // 이 경우 문자열의 길이를 비교하여 짧은 쪽을 찾아낸다.
        if(this->length < o.length){
            return true; 
        } else {
            return false;
        }
    }
        
    /**
     * @param o         비교할 문자열 (오른쪽 항)
     * @return true     o가 this보다 시전순으로 앞선다면 true
     * @return false    else
     */

    // 위와 동일한 방법으로 작성
    bool operator > (const MyString &o) const {
        int n = min(this->length, o.length);
        for (int i = 0; i < n; i++){
            if(this->characters[i] < o.characters[i]){
                return true;
            } else if(this->characters[i] > o.characters[i]){
                return false;
            }
        }
        // algorithm algo
        if(this->length > o.length){
            return true;
        } else {
            return false;
        }
    }

        
    /**
     * @param o         비교할 문자열 (오른쪽 항)
     * @return true     두 문자열이 같다면
     * @return false    두 문자열이 다르다면
     */
    bool operator == (const MyString &o) const {
        // 글자수가 같지 않으면 다른 단어이므로 false
        if(this->length != o.length)
            return false;
        
        for(int i = 0; i < this->length; i++){ // this의 길이만큼 반복
            if(this->characters[i] != o.characters[i]){ 
                return false; // 글자 중 하나라도 다르다면 false
            }
        }
        return true;
    }

};


int main() {

    string s1;
    string s2;
    cin >> s1 >> s2;

    MyString mys1(s1);
    MyString mys2(s2);

    if(mys1 < mys2){
        printf("-1\n");
    }
    else if(mys1 > mys2){
        printf("1\n");
    }
    else {
        printf("0\n");
    }

    return 0;

}
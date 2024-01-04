#include <iostream>

using namespace std;

int main() {
    // C++에서 문자열을 다루는 방법 중 하나인 string

    /*
    String의 특징
    - C스타일로 String 객체를 초기화할 수 있다.
    - cin을 사용하여 String 객체에 키보드 입력을 저장할 수 있다.
    - cout을 사용하여 string 객체를 디스플레이할 수 있다.
    - 배열 표기를 사용하여 string 객체에 저장되어 있는 개별적인 문자들에 접근할 수 있다.
    */

   /*
   배열의 한계
   - 배열을 다른 배열에 통째로 대입할 수 없다.
   >> 하지만 String에서는 이것이 가능하다.
   */

  char char1[20];
  char char2[20] = "apple";
  string str1;
  string str2 = "kobe";
  // char1 = char2; // 대입 불가
  str1 = str2; // 대입 가능
  cout << str1 << endl;
    return 0;
};
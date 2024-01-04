#include <iostream>
#include <cstring> // strlen() 함수를 사용하기 위해서

using namespace std;

int main() {
    const int Size = 15;
    char name1[Size]; // 비어있는 배열
    char name2[Size] = "C++programing"; // 문자열 상수로 초기화된 배열

    cout << "안녕하세요! 저는 " << name2;
    cout << "입니다! 성함이 어떻게 되시나요?\n";
    // cin >> name1; // cin -> 사용자의 입력을 받아 데이터의 흐름 방향에 따라 저장. 현재 >> 방향이므로 name1에 저장됨.
                  // 그러나 cin은 공백을 만나면 그 공백을 마지막이라고 생각하고 공백 뒤에 문자는 무시함.
                  // 따라서 kang kobe와 같은 문자열을 만나면 kang만 출력됨.
                  // 이러한 상황을 방지하기위해 cin.getline을 사용할 수 있음
    // cin.get(name1, Size);
    cin.getline(name1, Size);  // cin.get 과 cin.getline은 동일한 방식으로 동작합니다.             
    cout << "음, " << name1 << "씨, 당신의 이름은 ";
    cout << strlen(name1) << " 자입니다만\n"; // strlen() -> 문자열의 길이를 반환하는 함수.
    cout << sizeof(name1) << " 바이트 크기의 배열에 저장되었습니다.\n"; // sizeof() -> 변수의 바이트의 크기를 반환하는 함수.
    cout << "이름이" << name1[0] << "자로 시작하는군요.\n";
    name2[3] = '\0'; // set to null character
    cout << "제 이름의 처음 세 문자는 다음과 같습니다: ";
    cout << name2 << endl;

    return 0;
}
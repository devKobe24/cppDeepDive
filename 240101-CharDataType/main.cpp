#include <iostream>

using namespace std;

int main() {
    // char: 작은 문자형
    // C++에서 문자를 사용시 ASCII Code를 사용함.
    // ASCII Code를 보면 문자에 대응되는 숫자를 볼 수 있음.
    // 즉, 컴퓨터는 숫자를 받아들이는 것.

    // 예시
    int a = 77;
    char b = a;
    cout << b << endl; // M 출력 -> ASCII code 에서 숫자 77이 대문자 M과 대응되기 때문에 M이 출력됨.

    char c = 'd';
    cout << c << endl;

    // C++ 에서 큰 따옴표("")는 char형에서 사용할 수 없다, 오직 작은 따옴표('')만 사용할 수 있다.
    // C++ 에서 작은 따옴표('') 에는 명시적으로 null 문자가 포함되어 있지 않다.
    // C++ 에서 큰 따옴표("") 에는 명시적으로 null 문자가 포함되어 있다. => String

    char arr[] = { 'a', 'b', 'c', '\0'};
    cout << arr << endl;

    return 0;
}
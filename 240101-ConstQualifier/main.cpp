#include <iostream>

using namespace std;

// 원의 넓이를 구하는 프로그램
int main() {
    // 상수
    // 변수와 다르게 바뀔 필요가 없는 것
    // 변수와 다르게 바뀌어서는 안되는 것
    // => 상수로 관리.
    // C에서 상수를 정의하는 스타일 => #define PIE 3.1415926535
    // C++ 에서는 const라는 제한자를 활용하여 정의할 수 있음.
    // const 타입명 상수명 = 초기값;
    // 반드시 초기화해줘야 함.

    const float PIE = 3.1415926535;

    int radius = 3;
    float area = radius * radius * PIE;

    

    cout << "원의 넓이 : " << area << endl;

    return 0;
}
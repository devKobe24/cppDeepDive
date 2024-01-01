#include <iostream>

using namespace std;

int main() {

    // auto - C++ 만의 특별한 데이터형.
    // C++는 초기화하는 값을 보고 변수형을 추론할 수 있습니다.
    // 변수를 선언하고 값을 대입하는 것이 아닌 선언후 대입하는 "초기화"의 방식을 이용시에 "데이터형"을 "auto"로 명시하게 되면
    // C++가 "자동으로 데이터형을 결정하게 됩니다."

    auto n = 100; // n은 int로 추론
    auto x = 1.5; // x는 float으로 추론
    auto y = 1.3e12; // y는 long long으로 추론

    return 0;
}
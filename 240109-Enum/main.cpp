#include <iostream>

using namespace std;

int main() {
    // 열거체(enum)
    // 기호 상수를 만드는 것에 대한 또 다른 방법.
    // 아래 예시 코드를 통해 알아봅시다.

    // enum 구문은 두 가지의 역할을 수행하게 됩니다.
    /*
    1. Spectrum 이라는 이름의 새로운 데이터형을 생성합니다.
    2. red, orange, yellow ... ultraviolet 까지 각각 0~7 까지의 정수 값을 각각 나타내는 기호 상수로 만듭니다.
    즉, 0~7 이라는 int형 정수 대신 red, orange, yellow ... ultraviolet을 사용할 수 있습니다.
    c.f) 내부에 정의된 red, orange,,,들을 "열거자" 라고 부릅니다.
    */ 
    enum Spectrum {
        red,
        orange,
        yellow,
        green,
        blue,
        violet,
        indigo,
        ultraviolet
    };

    // 열거체의 선언
    // a라고 선언된 열거체는 열거자들의 값만 대입할 수 있습니다.
    // 아래의 코드를 보고 이해해봅시다.
    Spectrum a = orange;
    cout << "Orange == " << a << endl;

    // 열거체의 특징이 사용된 열거자들을 상수, 즉 기호 상수로서 관리하므로 산술 연산을 적용할 수 없습니다.
    // 예를 들어 orange(1) + yellow(2)를 하면 3인 green이 결과값으로 나올 것 같지만 그렇지 않습니다, 계산 자체가 불가능합니다.
    // 하지만 이 열거자들을 정수형에 대입할 경우에는 int형으로 변환될 수 있습니다.
    // 아래 예시 코드를 봐봅시다.
    int b;
    b = blue;

    // 위 코드에서 볼 수 있다시피 b 라는 int형에 blue라는 열거자를 대입할 수 있습니다.

    // 그리고 아래 코드에서 볼 수 있다시피 산술 연산을 사용이 가능합니다.
    // blue가 열거체 내에서 4의 의미를 가지고 있으므로 b에는 7이 저장되게 됩니다.
    b = blue + 3;
    cout << "blue(4) + 3 = " << b << endl;

    // 열거자는 아무런 옵션을 지정해주지 않을 경우 기본적으로 0부터 시작해서 1씩 더해지는 정수가 자동으로 저장됩니다.
    // 열거자에 명시적으로 대입 연산자(=)를 사용해서 그 값을 지정해 줄 수 있습니다.
    // 초기화시 값은 반드시 정수여야만 하며, 지정해주지 않은 열거자에는 이전 열거자 값에 +1인 값이 지정됩니다.
    // 아래 코드를 봐봅시다.

    enum Numbers {
        zero = 0,
        one = 1,
        two = 2,
        four = 4,
        six = 6,
        seven,
        eight,
        nine,
        ten
    };

    cout << "0 == " << zero << endl;
    cout << "1 == "<< one << endl;
    cout << "2 == "<< two << endl;
    cout << "4 == "<< four << endl;
    cout << "6 == " << six << endl;
    cout << "7 == " << seven << endl;
    cout << "8 == " << eight << endl;
    cout << "9 == " << nine << endl;
    cout << "10 == " << ten << endl;

    return 0;
}
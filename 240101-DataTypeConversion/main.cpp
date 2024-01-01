#include <iostream>

using namespace std;

int main() {
    // 데이터형 변환
    // C++은 데이터형이 풍부해 사용자가 필요한 데이터를 골라 사용할 수 있는 선택의 폭이 넓습니다.
    // 하지만 이로 인해서 컴퓨터의 처리는 복잡해질 수 있습니다.

    // 따라서 C++는 아래와 같은 상황에서 자동으로 데이터형을 바꾸어주는 데이터형 변환을 실시하게 됩니다.
    /*
    1. 특정 데이터형의 변수에 다른 데이터형의 값을 대입했을 때
    2. 수식에 데이터형을 혼합하여 사용했을 때
    3. 함수에 매개변수를 전달할 때
    */


    // 1. 특정 데이터형의 변수에 다른 데이터형의 값을 대입했을 때 - 예시
    int a = 3.141592;
    cout << a << endl; // 3 출력. -> int 형에 float 형 값을 대입.

    // 강제적으로 데이터 형 변환 방법.
    // 1. 타입명(변수명)
    // 2. (타입명)변수명

    char charType = 'M';
    cout << "타입명(변수명) 변환 방법 사용 => " << int(charType) << endl;
    cout << "(타입명)변수명 변환 방법 사용 => " << (int)charType << endl;

    // C++ 에서는 조금 더 제한적인 데이터형 변환 연산자가 있습니다.
    // static_cast<타입명>(변수명)

    char secondCharType = 'M';
    cout << "static_cast<int>secondCharType 으로 데이터 형 변환 => " << static_cast<int>(secondCharType) << endl;

    return 0;
}
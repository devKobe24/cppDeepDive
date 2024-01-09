#include <iostream>

using namespace std;

int main() {
    // 공용체(union)
    // 서로 다른 데이터 형을 한 번에 한 가지만 보관할 수 있는 데이터형
    // 아래 코드를 봐봅시다.

    union MyUnion {
        int intVal;
        long longVal;
        float floatVal;
    };

    // 위와 같이 union 변수는 int, long, float 형을 보관할 수 있지만 어느 시점에 한 가지만 보관이 가능합니다.
    // 아래의 코드를 봐보며 이해해 봅시다.

    // 먼저 test라는 이름으로 union 변수를 선언 한 합니다.
    // 멤버 연산자(.)를 통해 각 union의 멤버에 대해 접근할 수 있습니다.

    // 이렇게만 보면 구조체와 다를바게 없어보입니다. 출력을 통해 무엇이 다른지 알아봅시다.
    MyUnion test;
    test.intVal = 3;
    cout << test.intVal << endl;

    test.longVal = 33;
    cout << test.intVal << endl;
    cout << test.longVal << endl;

    test.floatVal = 3.3;
    cout << test.intVal << endl;
    cout << test.longVal << endl;
    cout << test.floatVal << endl;
    
    // 이 출력된 것을 보면 알 수 있다시피 이 union은 한 번에 한가지만 보관할 수 있기 때문에 int형 데이터를 보관할 때는 int형 데이터를 보관하고,
    // 그 이후로 다른 데이터형 값을 보관할 때마다 이전에 보관하였던 데이터 값이 소실되게 됩니다.
    // 그래서 union은 구조체처럼 배열과 달리 여러가지 데이터형을 사용할 수 있지만 이들을 동시에 사용할 수는 없습니다.
    // 이로 인한 장점은 있습니다. 
    // 바로 메모리를 절약 할 수 있다는 점 입니다.
    // 사실 공용체(union)은 일반적인 프로그램에서 많이 사용하기 보다는 운영체제나 하드웨어 데이터 구조에 자주 사용되는 데이터형이므로 프로그래밍시 구조체만큼 자주 사용할 일은 없을것 입니다.

    return 0;
}
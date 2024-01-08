#include <iostream>

using namespace std;

int main() {
    // 구조체 - 복합 데이터형
    // cf) 배열이란, 같은 데이터 형의 집합이기는 하지만 배열을 이루는 원소는
    // 모두 같은 데이터 형이여야 합니다.(제약)

    // 구조체는 다른 데이터 형이 허용되는 데이터의 집합.
    // 배열처럼 여러개의 원소를 하나의 구조체 안에 담을 수 있으나 그 원소들이 다른 데이터 형이여도 됩니다.
    // 구조체 내부의 요소들은 "멤버"라고 불립니다.

    // 구조체를 정의한 이후에는 변수에 데이터를 사용하듯이 구조체를 변수의 데이터 형으로 사용할 수 있습니다.

    struct FootballPlayer {
        string name;
        string position;
        float height;
        float weight;
        int backNumber;
    };

    FootballPlayer A; // A라는 이름의 FootballPlayer형 변수를 선언한 코드.
                      // A는 name, position, height, weight, backNumber에 관한 정보를 담고 있습니다.(아직 지정을 해주지는 않았습니다.)

    // 아래와 같은 방법으로 구조체의 멤버에 접근하여 원하는 값을 정의해줄 수 있습니다.
    // * (.) 은 멤버연산자입니다.
    A.name = "Son";
    A.position = "Striker";
    A.height = 183.1;
    A.weight = 75.3;
    A.backNumber = 7;

    // *구조체란 결국, 사용자가 정의한 새로운 데이터 형을 만드는 것 입니다.
    // *즉, 변수로 사용할 데이터 형을 새롭게 만드는 것 입니다.
        // * 그러므로 구조체 역시 선언과 동시에 값을 대입하는 초기화가 가능합니다.

    /*구조체의 초기화*/ 
    FootballPlayer B = {
        "Lee",
        "Striker",
        178,
        73.2,
        9
    };

    cout << "name: " << A.name << ", position: " << A.position << ", height: " << A.height << ", weight: " << A.weight << ", back number: " << A.backNumber << endl;
    cout << "name: " << B.name << ", position: " << B.position << ", height: " << B.height << ", weight: " << B.weight << ", back number: " << B.backNumber << endl;

    // 구조체 Tip and Trick
    // 구조체의 블록의 끝 중괄호에 구조체의 변수로 사용할 변수명을 입력해 줄 경우, 새로운 구조체를 선언하지 않아도 입력한 변수명으로 자동으로 구조체가 생성이 됩니다.
    // 아래의 예시 코드를 보고 이해해 봅시다.
    struct FomulelaOneDriverInfo {
        string name;
        float height;
        float weight;
        string team;
        int carNumber;
        bool carTest;
    } Kang;

    Kang.name = "Kobe Kang";
    Kang.height = 179.8;
    Kang.weight = 76.8;
    Kang.team = "Red Bull";
    Kang.carNumber = 1;
    Kang.carTest = true;

    cout << "Driver name: " << Kang.name << ", Driver height: " << Kang.height << ", Driver weight: " << Kang.weight << ", Raceing team: " << Kang.team << ", Car number: " << Kang.carNumber << ", is Car Test Passed?: " << Kang.carTest << endl;

    struct Man {
        string name;
        float height;
        float weight;
        int age;
    } Kobe;

    // 구조체 역시 배열처럼 값을 기입할 때 구조체에 멤버에 해당되는 모든 값을 기입하지 않아도 됩니다.
    // 아래와 같이 빈 중괄호로 선언시 빈 값들은 각각 0에 해당되어 저장됩니다.

    Kobe = {

    };

    cout << "What your name ? "<< Kobe.name << endl;
    cout << "How old are you ? " << Kobe.age << endl;
    
    struct BasketBallPlayer {
        string name;
        string position;
        int backNumber;
        float height;
        float weight;
    };

    // 구조체 역시 배열로 선언이 가능합니다.
    // 아래의 코드를 보고 이해해 봅시다.

    // 대괄호로 배열의 크기를 지정해주면 됩니다.
    // 이 배열은 아래와 같이 초기화가 가능합니다.
    // 먼저, 일반적인 구조체를 초기화 하듯 중괄호를 열어 줍니다.
    // 이후, 그 블록 내부에 중괄호를 다시 열어 배열의 첫 번째 인덱스에 해당되는 원소의 값을 집어 넣어줍니다.
    // 그리고 배열과 동일하게 (,)로 구분해줍니다.
    // 두 번째 인덱스에 해당되는 정보를 (,)이후에 중괄호를 열어 넣어줍니다.
    BasketBallPlayer C[2] = {
        {"Park", "Center", 0, 195.4, 118.5},
        {"Seo", "Guard", 7, 188.5, 82.5}
    };

    // 배열에 관련되어서 각각의 원소들의 멤버에 대해서 접근하는 방법은 `구조체명[접근할인덱스].원소` 이렇게 하면 됩니다.
    // 아래의 코드를 보고 이해해 봅시다.
    cout << "What is your position ? " << "My position is " << C[0].position << endl;
    cout << "How is the most valuable player you think ? " << "I think " << C[1].name << " is the MVP in this game." << endl;

    return 0;
}
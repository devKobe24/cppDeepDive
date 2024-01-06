#include <iostream>

using namespace std;

int main() {
    double rightOperand, leftOperand, result;
    char operation;

    // 사용자로부터 값 받아오기.
    cout << "Enter first operand number: ";
    cin >> rightOperand;

    cout << "Select operation (+ , -, *, /): ";
    cin >> operation;

    cout << "Enter second operand number: ";
    cin >> leftOperand;

    // 요청된 작업을 switch문을 통해 수행.
    switch (operation) {
    case '+':
        result = rightOperand + leftOperand;
        break;
    case '-':
        result = rightOperand - leftOperand;
        break;
    case '*':
        result = rightOperand * leftOperand;
        break;
    case '/':
        // 0으로 나눈 경우 확인.
        if (leftOperand != 0) {
            result = rightOperand / leftOperand;
        } else {
            cout << "Error: 0으로 나누는 것은 정의되지 않습니다." << endl;
            return 1; // 오류 코드와 함께 프로그램 종료
        }
        break;
    default:
        cout << "Error: 잘못된 작업입니다." << endl;
        return 1; // 오류 코드와 함께 프로그램 종료
    }

    // 결과 보여주기.
    cout << "Result: " << result << endl;

    return 0;
}
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// 사용자의 선택을 얻는 함수
char getUserChoice() {  
    char choice;

    cout << "Enter your choice (R for Rock, P for Paper, S for Scissors)";
    cin >> choice;
    return toupper(choice); // 대소문자를 구분하지 않으려면 대문자로 변환.
}

// 컴퓨터의 선택을 생성하는 함수
char getComputerChoice() {
    // 0과2 사이의 숫자를 무작위로 생성
    int randomNumer = rand() % 3;

    // 무작위로 생성한 숫자를 R, P 또는 S에 매핑
    switch (randomNumer) {
    case 0:
        return 'R';
    case 1:
        return 'P';
    case 2:
        return 'S';
    default:
        cout << "무작위 난수 생성에 오류가 있습니다.";
        return ' ';
    }
}

// 승자 결정 함수
void determineWinner(char userChoice, char computerChoice) {
    cout << "Computer's choice: " << computerChoice << endl;
    if (userChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if (
        (userChoice == 'R' && computerChoice == 'S') ||
        (userChoice == 'P' && computerChoice == 'R') ||
        (userChoice == 'S' && computerChoice == 'P')
    ) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }
}

int main() {
    // 난수 생성기에 현재 시간을 넣습니다
    srand(time(0));

    char userChoice = getUserChoice();
    char computerChoice = getComputerChoice();

    determineWinner(userChoice, computerChoice);

    return 0;
}
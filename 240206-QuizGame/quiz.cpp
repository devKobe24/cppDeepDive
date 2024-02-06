#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Question
{
public:
	string questionText;
	vector<string> options;
	int correctOption;

	Question(const string &text, const vector<string> &opts, int correct)
			: questionText(text), options(opts), correctOption(correct) {}
};

class Quiz
{
public:
	vector<Question> questions;
	int score;

	Quiz() : score(0) {}

	void addQuestion(const string &text, const vector<string> &opts, int correct)
	{
		questions.emplace_back(text, opts, correct);
	}

	void displayQuestion(int index) const
	{
		const Question &q = questions[index];
		cout << "Question " << index + 1 << ": " << q.questionText << "\n";

		for (size_t i = 0; i < q.options.size(); i++)
		{
			cout << "     " << i + 1 << ". " << q.options[i] << "\n";
		}
	}
	void startQuiz()
	{
		score = 0;
		for (size_t i = 0; i < questions.size(); ++i)
		{
			displayQuestion(i);
			int userChoice = getUserChoice();
			if (userChoice == questions[i].correctOption)
			{
				cout << "오! 정답!\n";
				score++;
			}
			else
			{
				cout << "Beep!! 아쉽게도 틀렸어요 :( 정답은: " << questions[i].correctOption << "\n";
			}
		}
		cout << "퀴즈가 모두 끝났습니다!! 당신의 점수는: " << score << "/" << questions.size() << "\n";
	}

	int getUserChoice() const
	{
		int choice;
		cout << "답을 입력해 주세요 (1~" << questions[0].options.size() << "): ";
		cin >> choice;
		// Validate user input
		while (choice < 1 || choice > static_cast<int>(questions[0].options.size()))
		{
			cout << "엥? 그 선택지는 없어용! 다른 선택지를 골라주세요: ";
			cin >> choice;
		}

		return choice;
	}
};

int main() {
	// Seed for randomization
	srand(time(0));

	// Create a quiz
	Quiz quiz;

	// Add questions
	quiz.addQuestion("이 프로그램을 만든 사람은?", {"1) 브라이언", "2) 팀 쿡", "3) 코비", "4) 스티브 워즈니악", "5) 빌 게이츠"}, 3);
	// START QUIZ
	quiz.startQuiz();
	return 0;
}
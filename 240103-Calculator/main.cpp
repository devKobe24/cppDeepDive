#include <string>
#include <iostream>

using namespace std;

class Calculator {
    string expr;
    int tcnt = 0;
    public: Calculator(string expr) {
        this -> expr = expr;
        tcnt = 0;
    }

    void Run() {
        cout << expr << "계산합니다." << endl;
        if (Lexical()) {
            if (Syntax()) {
                Parsing();
                PostOrderView();
                cout << expr << "=" << Calculate() << endl;
            } else {
                cout << "수식에 사용한 표현이 문법에 맞지 않습니다." << endl;
            }
        } else {
            cout << "사용할 수 없는 기호가 있습니다." << endl;
        }
        cout << endl;
    }

    private: bool Lexical() {
        int i = 0;
        while (expr[i]) {
            if (IsOperator(expr[i])) {
                i = MakeOperator(i);
            } else {
                if (IsDigit(expr[i])) {
                    i = MakeOperand(i);   
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    bool IsOperator(char ch) {
        return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/');
    }

    bool IsDigit(char ch) {
        return (ch >= '0') && (ch <= '9');
    }

    struct Token {
        int priority;
        virtual void View() = 0;
        bool MoreThanPriority(Token * token) {
            return priority >= token -> priority;
        }
    };

    struct Operator: public Token {
        char ch;
        Operator(char ch) {
            this -> ch = ch;
            if ((ch == '+') || (ch == '-')) {
                priority = 1;
            } else {
                priority = 2;
            }
        }

        void View() {
            cout << ch << " ";
        }
    };

    Token *tokens[100];

    int MakeOperator(int index) {
        tokens[tcnt] = new Operator(expr[index]);
        tcnt++;
        return index + 1;
    }

    struct Operand: public Token {
        int value; 
        Operand(int value) {
            this -> value = value;
            priority = 3;
        }

        void View() {
            cout << value << " ";
        }
    };

    int MakeOperand(int index) {
        int value = 0;
        while (IsDigit(expr[index])) {
            value = value * 10 + expr[index] - '0';
            index++;
        }
        tokens[tcnt] = new Operand(value);
        tcnt++;
        return index;
    }


    bool Syntax() {
        if (tcnt % 2 == 0) {
            return false;
        }

        if (tokens[0] -> priority != 3) {
            return false;
        }

        for (int i = 1; i < tcnt; i += 2) {
            if (tokens[i] -> priority == 3) {
                return false;
            }

            if (tokens[i + 1] -> priority != 3) {
                return false;
            }
        }
        return true;
    }

    struct ParserTree {
        struct Node {
            Token* token;
            Node* Ic;
            Node* rc;
            Node(Token* token) {
                this -> token = token;
                Ic = rc = 0;
            }
        };

        Node* root;
        ParserTree(Token* token)  {
            root = new Node(token);
        }

        void Add(Token* token) {
            Node* now = new Node(token);
            Token* st = root -> token;
            if(st -> MoreThanPriority(token)) {
                now -> Ic = root;
                root = now;
            } else {
                if (token -> priority != 3) {
                    now -> Ic = root -> rc;
                    root -> rc = now;
                } else {
                    Node* pa = root;
                    while (pa -> rc) {
                        pa = pa -> rc;
                    }
                    pa -> rc = now;
                }
            }
        }

        void View() {
            PostOrder(root);
            cout << endl;
        }

        void PostOrder(Node* sr) {
            if (sr) {
                PostOrder(sr -> Ic);
                PostOrder(sr -> rc);
                sr -> token -> View();
            }
        }

        int Calculate() {
            return PostOrderCalculate(root);
        }

        int PostOrderCalculate(Node* sr) {
            if (sr -> Ic) {
                int lvalue = PostOrderCalculate(sr -> Ic);
                int rvalue = PostOrderCalculate(sr -> rc);
                Operator* op = dynamic_cast<Operator*>(sr -> token);

                switch (op -> ch)
                {
                case '+': return lvalue + rvalue;
                case '-': return lvalue - rvalue;
                case '*': return lvalue * rvalue;
                case '/':
                    if (rvalue)
                    {
                        return lvalue / rvalue;
                    }
                    
                    cout << "divide zero error" << endl;
                    
                    return 0;

                    default:
                        throw "정의하지 않은 연산자입니다.";
                }
            }
            Operand* oprd = dynamic_cast<Operand*>(sr -> token);
            return oprd -> value;
        }
    };


    ParserTree* ps;
    void Parsing() {
        ps = new ParserTree(tokens[0]);
        for (int i = 1; i < tcnt; i++) {
            ps -> Add(tokens[i]);
        }
    }

    void PostOrderView() {
        ps -> View();
    }

    int Calculate() {
        return ps -> Calculate();
    }
};

int main() {

    string tc_exprs[6] = {
        "2+3=5*5+6/2",
        "23*5/2+4*6",
        "2+4*5#6",
        "2+3*5+",
        "3+36+-7",
        "45+3*5-25/2*7",
    };

    for(int i = 0; i < 6; i++) {
        Calculator * cal = new Calculator(tc_exprs[i]);
        cal -> Run();
        delete cal;
    }

    return 0;
}
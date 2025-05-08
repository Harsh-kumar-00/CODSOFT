#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char op;
    char choice;

    
        cout << "==============================" << endl;
        cout << "     SIMPLE CALCULATOR    " << endl;
        cout << "==============================" << endl;
        do {
        // Input numbers and operator
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << "==============================" << endl;
        cout << "Choose an operation:" << endl;
        cout << " Addition (+)" << endl;
        cout << " Subtraction (-)" << endl;
        cout << " Multiplication (*)" << endl;
        cout << " Division (/)" << endl;
        cout << "==============================" << endl;
        cout << "Enter operation: ";
        cin >> op;
        cout << "==============================" << endl;

        // Perform operation
        switch (op) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/':
                if (num2 != 0)
                    result = num1 / num2;
                else {
                    cout << "Error: Division by zero.\n";
                    continue; // Skip rest and ask again
                }
                break;
            default:
                cout << "Invalid operation.\n";
                continue;
        }

        
        cout << "Result: " << result << endl;
        cout << "==============================" << endl;
        // Ask user to continue
        cout << "Do you want to perform another operation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for using the calculator. Goodbye!" << endl;
    return 0;
}

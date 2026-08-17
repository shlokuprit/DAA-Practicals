// Practical 4 : Factorial of a number using Iterative and Recursive methods

#include <iostream>
using namespace std;

// Iterative method
long long factorialIterative(int n) {
    long long fact = 1;

    for (int i = 2; i <= n; i++)
        fact = fact * i;

    return fact;
}

// Recursive method
long long factorialRecursive(int n) {
    if (n == 0 || n == 1)
        return 1;

    return n * factorialRecursive(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "Factorial using iterative method : "
             << factorialIterative(n) << endl;
        cout << "Factorial using recursive method : "
             << factorialRecursive(n) << endl;
    }

    cout << "\n----------------------------------------\n";
    cout << "Name           : Shlok Uprit\n";
    cout << "Enrollment No. : 92460118211\n";

    return 0;
}

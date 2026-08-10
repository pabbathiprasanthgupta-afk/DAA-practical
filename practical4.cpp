#include <iostream>
using namespace std;

// Iterative method
long long factorialIterative(int n)
{
    long long fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

// Recursive method
long long factorialRecursive(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorialRecursive(n - 1);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Factorial is not defined for negative numbers.";
        return 0;
    }

    cout << "Factorial using Iterative Method: "
         << factorialIterative(n) << endl;

    cout << "Factorial using Recursive Method: "
         << factorialRecursive(n) << endl;

    return 0;
}

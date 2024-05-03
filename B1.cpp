#include <iostream>
#include <cmath>

using namespace std;

int sumOfDivisors(int n)
{
    int sum = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            sum += i;
            if (i != n / i)
                sum += n / i;
        }
    }
    return sum;
}

int main()
{
    int T;
    cout << " Enter the number of test cases: ";
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int n;
        cout << "Enter your munber : ";
        cin >> n;
        cout << "total number of divisors of n : " << sumOfDivisors(n) << endl;
    }

    return 0;
}
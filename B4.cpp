#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isPrime(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool isSuperPrime(int num) {
    if (!isPrime(num))
        return false;
    while (num > 0) {
        if (!isPrime(num))
            return false;
        num /= 10;
    }
    return true;
}

std::vector<int> getSuperPrimes(int n) {
    std::vector<int> superPrimes;
    std::queue<int> q;
    for (int i = 2; i <= n; i++) {
        if (isSuperPrime(i)) {
            superPrimes.push_back(i);
            q.push(i);
        }
    }
    return superPrimes;
}

void printSuperPrimes(int n) {
    std::vector<int> superPrimes = getSuperPrimes(n);
    cout << "Super prime numbers less than or equal to " << n << ": ";
    for (int num : superPrimes) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printSuperPrimes(n);
    return 0;
}
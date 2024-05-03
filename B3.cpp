#include <iostream>
#include <stack>
#include <string>

using namespace std;

string encodeString(const string &input)
{
    stack<char> charStack;
    stack<int> countStack;
    string output;

    for (char c : input)
    {
        if (charStack.empty() || c != charStack.top())
        {
            if (!charStack.empty())
            {
                output += charStack.top() + to_string(countStack.top());
                countStack.pop();
            }
            charStack.push(c);
            countStack.push(1);
        }
        else
        {
            countStack.top()++;
        }
    }

    if (!charStack.empty())
    {
        output += charStack.top() + to_string(countStack.top());
    }

    return output;
}

int main()
{
    string input;
    cout << "Nhap chuoi: ";
    getline(cin, input);

    string encoded = encodeString(input);
    cout << "Chuoi ma hoa: " << encoded << endl;

    return 0;
}
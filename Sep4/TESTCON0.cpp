#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
    string str;
    int num;
    cin >> str;
    string::iterator iter = str.begin();
    for (int i = 0; i < 8; i++)
    {
        num = 0;
        for (int j = 3; j >= 0; j--)
        {
            if (*iter == '1')
                num += pow(2, j);
            iter++;
        }
        if (num == 15)
            cout << "F";
        else if (num == 14)
            cout << "E";
        else if (num == 13)
            cout << "D";
        else if (num == 12)
            cout << "C";
        else if (num == 11)
            cout << "B";
        else if (num == 10)
            cout << "A";
        else
            cout << num;
    }
    cout << endl;
    return 0;
}

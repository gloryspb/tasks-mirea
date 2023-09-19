#include <iostream>
#include <typeinfo>
#include <string>
#include <math.h>

using namespace std;

void Task1(string name)
{
    cout << name << endl;
}

string Task2(double num1, double num2)
{
    string str = to_string(num1 + num2) + " " + to_string(num1 - num2) + " " + to_string(num1 * num2);
    if (num2 != 0)
        str += " " + to_string(num1 / num2);
    return str;
}

string Task3(double b, double c)
{
    if (c == 0 && b == 0)
    {
        return "endless solutions";
    }
    else if (c == 0)
    {
        return "0";
    }
    else if (b == 0)
    {
        return "no solution";
    }
    else
    {
        return to_string(-c / b);
    }
    // return b != 0 ? to_string(-c / b) : "no solution";
}

string Task4(double a, double b, double c)
{
    if (a == 0)
        return Task3(b, c);

    double d = b * b - 4 * a * c;

    if (d < 0) return "no solution";

    double x1, x2;
    x1 = (-b + sqrt(d)) / (2 * a);
    x2 = (-b - sqrt(d)) / (2 * a);

    if (d == 0)
    {
        return to_string(x1);
    }

    return to_string(x1) + " " + to_string(x2);
}

bool Task5(bool isDay, bool isCurtainsOpened, bool isLampOn)
{
    return isDay && isCurtainsOpened || isLampOn;
}

int main()
{
    Task1("Dima");
    Task1("Kirill");
    // ввод с клавиатуры
    double num1, num2;
    cin >> num1;
    cin >> num2;
    cout << Task2(num1, num2) << endl;

    double a, b, c;
    cin >> b;
    cin >> c;
    cout << Task3(b, c) << endl;

    cin >> a;
    cin >> b;
    cin >> c;
    cout << Task4(a, b, c) << endl;

    if (Task5(true, false, true))
    {
        cout << "svetlo" << endl;
    }
    else
    {
        cout << "temno" << endl;
    }
    // cout << Task5(true, false, true) ? "svetlo" : "temno" << endl;

    return 0;
}
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

double CalculateMonthlyPayment(double numS, double numN, double numP)
{
    if (numS <= 0 || numN <= 0 || (numP < 0 && numP > 100))
    {
        return (-1);
    }

    return (numS * (numP / 100) * pow((1 + (numP / 100)), numN)) / (12 * (pow((1 + (numP / 100)), numN) - 1));
}

double Task1(double numS, double numN, double numP)
{
    if (numS <= 0 || numN <= 0 || (numP < 0 && numP > 100))
    {
        return (-1);
    }

    double numR = numP / 100;
    return CalculateMonthlyPayment(numS, numN, numP);
}

double Task2(double numS, double numN, double numM)
{
    double min = 0.1, max = 100.0;
    
    double numP = 0.0;

    while (true)
    {
        if (max - min < 0.01) {
            numP = (min + max) / 2;
            break;
        } else if (abs(numM - CalculateMonthlyPayment(numS, numN, min)) > abs(numM - CalculateMonthlyPayment(numS, numN, max))) {
            min += (max - min) / 2;
        } else if (abs(numM - CalculateMonthlyPayment(numS, numN, min)) <= abs(numM - CalculateMonthlyPayment(numS, numN, max))) {
            max -= (max - min) / 2;
        }
    }

    return numP;
}

//double Task2Recursive(double numS, double numN, double numM, double min, double max)
//{
//    if (max - min < 0.01)
//    {
//        return (min + max) / 2;
//    }
//    else if (abs(numM - CalculateMonthlyPayment(numS, numN, min)) > abs(numM - CalculateMonthlyPayment(numS, numN, max))) 
//    {
//        Task2Recursive(numS, numN, numM, (max - min) / 2, max);
//    }
//    else if (abs(numM - CalculateMonthlyPayment(numS, numN, min)) <= abs(numM - CalculateMonthlyPayment(numS, numN, max))) 
//    {
//        Task2Recursive(numS, numN, numM, min, (max - min) / 2);
//    }
//}

string Task3()
{
    string line, str;
    
    ifstream in("C:\\Users\\Kirill\\Desktop\\unik\\.edu2\\files\\text.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            str += line + "\n";
        }
    }
    
    in.close();
    return str.erase(0,3);
}

string Task4()
{
    string  str = Task3(), strNum;
    for (int i = 0; i < str.size(); ++i) 
    {
        if ((str[i] <= '9') && (str[i] >= '1'))
        {
            strNum += str[i];
        }
    }
    return strNum;
}

string Sort(string _str)
{
    string  newStr;
    for(int i = 0; i < _str.size() - 1; i++)
    {
        for(int r = (_str.size() - 1); r > i; r--)
        {
            if(_str[r - 1] > _str[r])
            {
                int temp = _str[r - 1];
                _str[r - 1] = _str[r];
                _str[r] = temp;
            }
        }
    }
    
    return _str;
}

string Task5()
{
    string  str = Task3();

    return Sort(str);
}

int main() {
    
    double numS, numN, numP, numM, result;
    cout << "enter the loan amount, years and percentage" << endl;
    cin >> numS >> numN >> numP;
    result = Task1(numS, numN, numP);
    result == -1 ? cout << "error" << endl : cout << result << endl;

    cout << "enter the loan amount, years and payment amount" << endl;
    cin >> numS >> numN >> numM;
    result = Task2(numS, numN, numM);
//    result = Task2Recursive(numS, numN, numM, 0.1, 100.0);
    result == -1 ? cout << "error" << endl : cout << result << endl;

    cout << Task3() << endl;
    cout << Task4() << endl;
    cout << Task5() << endl;
    return 0;
}
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>
#include <sstream>
#include <math.h>
#include <iomanip>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

struct Figure
{
    virtual double GetArea()
    { };
};

struct Circle:Figure
{
    double radius;

    Circle(double _radius)
    {
        this->radius = _radius;
    }

    double GetArea() override
    {
        return 3.14 * radius * radius;
    }
};

struct Rectangle:Figure
{
    double width;
    double height;
    
    Rectangle(double _width, double _height)
    {
        this->width = _width;
        this->height = _height;
    }

    double GetArea() override
    {
        return width * height;
    }
};

struct Triangle:Figure
{
    double sideA, sideB, sideC;
    
    Triangle(double _sideA, double _sideB, double _sideC)
    {
        this->sideA = _sideA;
        this->sideB = _sideB;
        this->sideC = _sideC;
    }

    double GetArea() override
    {
        double p = (sideA + sideB + sideC) / 2;
        return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
    }
};



void Task1()
{
    if (fopen("..\\files\\ex.txt", "r") == NULL) {
        std::ofstream oFile("..\\files\\ex.txt");
        oFile.close();
    }
    
    string  str, line;
    
    cout << "enter numbers" << endl;
    
    getline(cin, line);
    cout << line << endl;

    ofstream out;
    out.open("..\\files\\ex.txt");
    if (out.is_open())
    {
        out << line;
    }
    
    out.close();

    double temp;
    double summ = 0;
    ifstream flow("..\\files\\ex.txt");
    if (flow) {
        while (flow >> temp) {
            summ += temp;
        }
    }

    cout << summ << endl;
}

int DetermineNumberSign(double  num)
{
    if (num > 0)
    {
        return 1;
    }
    if (num < 0)
    {
        return -1;
    }
    return 0;
}

void Task2()
{
    double _num;
    cout << "enter a number to determine the sign" << endl;
    cin >> _num;
    int _sign = DetermineNumberSign(_num);
    switch (_sign)
    {
        case 1:
            cout << "+" << endl;
            break;
        case -1:
            cout << "-" << endl;
            break;
        case 0:
            cout << "0" << endl;
            break;
    }
}

void CreateRectangle()
{
    cout << "enter width and height: " << endl;
    double _width, _height;
    cin >> _width >> _height;
    Rectangle _rectangle(_width, _height);
    cout << _rectangle.GetArea() << endl;
}

void CreateTriangle()
{
    cout << "enter a b c: " << endl;
    double _sideA, _sideB, _sideC;
    cin >> _sideA >> _sideB >> _sideC;
    Triangle _triangle(_sideA, _sideB, _sideC);
    cout << _triangle.GetArea() << endl;
}

void CreateCircle()
{
    cout << "enter radius: " << endl;
    double _radius;
    cin >> _radius;
    Circle _circle(_radius);
    cout << _circle.GetArea() << endl;
}

void Task3()
{
    cout << "select a figure (1 - rectangle, 2 - triangle, 3 - circle): " <<  endl;
    int _figure;
    cin >> _figure;
    switch (_figure) 
    {
        case 1:
            CreateRectangle();
            break;
        case 2:
            CreateTriangle();
            break;
        case 3:
            CreateCircle();
            break;
    }
}

void Task4()
{
    for (int i = 0; i < 6; ++i) 
    {
        for (int i = 0; i < 8; ++i)
        {
            cout << "* ";
        }
        for (int i = 0; i < 22; ++i)
        {
            cout << "__";
        }
        cout << endl;
    }
    for (int i = 0; i < 7; ++i) 
    {
        for (int i = 0; i < 30; ++i)
        {
            cout << "__";
        }
        cout << endl;
    }
}

void Task5()
{
    double y, x;
    char sym;
    for (int i = 0; i < 37; ++i) 
    {
        for (int j = 0; j < 37; ++j) 
        {
            x = j - 18;
            y = sin(x);

            if (round(y*2) == i - 18) 
                sym = '*';
            else if (i == 18 || j == 18) 
                sym = '*';
            else sym = ' ';
            cout << setw(3) <<  sym;
            if (j == 36) cout << endl; 
        }
    }
}



enum class RomanNums { I, V, X, L, C, D, M };

string  RomanNumsStr = "IVXLCDM";

list<int> romanNumsList;

bool CheckRomanNumIsCorrect(string romanNumStr)
{
    for (char _char : romanNumStr) 
    {
        if (RomanNumsStr.find(_char) == string::npos)
            return false;
    }
    if (romanNumStr.find("IIII") != string::npos)
        return false;
    if (romanNumStr.find("VX") != string::npos)
        return false;
    if (romanNumStr.find("VL") != string::npos)
        return false;
    if (romanNumStr.find("VC") != string::npos)
        return false;
    if (romanNumStr.find("VD") != string::npos)
        return false;
    if (romanNumStr.find("VM") != string::npos)
        return false;
    if (romanNumStr.find("VV") != string::npos)
        return false;
    
    return true;
}

int GetArabicNum(RomanNums romanNum)
{
    switch (romanNum) 
    {
        case RomanNums::I:
            return 1;
        case RomanNums::V:
            return 5;
        case RomanNums::X:
            return 10;
        case RomanNums::L:
            return 50;
        case RomanNums::C:
            return 100;
        case RomanNums::D:
            return 500;
        case RomanNums::M:
            return 1000;
    }
}

void ConvertToArabic(string romanNumStr)
{
    for (auto _char : romanNumStr) 
    {
        if (_char == 'I')
            romanNumsList.push_back(GetArabicNum(RomanNums::I));
        else if (_char == 'V')
            romanNumsList.push_back(GetArabicNum(RomanNums::V));
        else if (_char == 'X')
            romanNumsList.push_back(GetArabicNum(RomanNums::X));
        else if (_char == 'L')
            romanNumsList.push_back(GetArabicNum(RomanNums::L));
        else if (_char == 'C')
            romanNumsList.push_back(GetArabicNum(RomanNums::C));
        else if (_char == 'D')
            romanNumsList.push_back(GetArabicNum(RomanNums::D));
        else if (_char == 'M')
            romanNumsList.push_back(GetArabicNum(RomanNums::M));
    }
}

int GetArabicNum()
{
    int prev = 0, result = 0, temp = 0;
    
    for (int num : romanNumsList)
    {
        if (num >= prev && num > 5)
        {
            result += num - temp;
            temp = 0;
        }
        else if (num == prev && num <5)
        {
            temp += num;
        }
        else if (num < prev)
        {
            temp += num;
        }
        prev = num;
    }

    if (temp != 0) 
        result += temp;
    
    return result;
}

void Task6()
{
    cout << "Enter roman number: " << endl;
    string romanNum;
    cin >> romanNum;
    if (CheckRomanNumIsCorrect(romanNum))
    {
        ConvertToArabic(romanNum);
        cout << GetArabicNum() << endl;
    }
    else
    {
        cout << "incorrect number!!1";
    }
}

list<int> numsList;

void PseudoRandom(int count, int option)
{
    int temp = 0;
    numsList.push_back(temp);
    if (option == 0)
    {
        for (int i = 0; i < count - 1; ++i) 
        {
            temp = (37 * temp + i + 3) % 64;
            numsList.push_back(temp);
        }
    }
    else if (option == 1)
    {
        for (int i = 0; i < count - 1; ++i)
        {
            temp = (25173 * temp + i + 13849) % 65537;
            numsList.push_back(temp);
        }
    }
}

void Task7()
{
    int count, option;
    cout << "enter count of random numbers and randomization option (0 or 1)" << endl;
    cin >> count >> option;
    PseudoRandom(count, option);
    
    for (int num : numsList) 
    {
        cout << num << endl;
    }
}

void Task8()
{
    double matrix1[3][4]
            {
                {5, 2, 0, 10},
                {3, 5, 2, 5},
                {20, 0, 0, 0}
            },
    matrix2[4][2]
            {
                {1.20, 0.50},
                {2.80, 0.40},
                {5.00, 1.00},
                {2.00, 1.50}
            },
    matrix3[3][2],
    result = 0,
    maxIncome = 0,
    minIncome = 100000000,
    totalIncome = 0,
    maxComission = 0,
    minComission = 100000000,
    totalComission = 0,
    totalMoney = 0;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 4; ++k) 
            {
                result += matrix1[i][k] * matrix2[k][j];
            }
            matrix3[i][j] = result;
            if (j == 0)
            {
                if (result > maxIncome)
                {
                    maxIncome = result;
                }
                if (result < minIncome)
                {
                    minIncome = result;
                }
                totalIncome += result;
            }
            if (j == 1)
            {
                if (result > maxComission)
                {
                    maxComission = result;
                }
                if (result < minComission)
                {
                    minComission = result;
                }
                totalComission += result;
            }
            totalMoney += result;
            result = 0;
            cout << setw(5) << matrix3[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "max income: " << maxIncome << endl;
    cout << "min income: " << minIncome << endl;
    cout << "max comission: " << maxComission << endl;
    cout << "min comission: " << minComission << endl;
    cout << "total income: " << totalIncome << endl;
    cout << "total comission: " << totalComission << endl;
    cout << "total money: " << totalMoney << endl;
}

list<int> numsSys;
string nums = "1234567890ABCDEF";

template <typename T>
string ToString(T val)
{
    ostringstream oss;
    oss<< val;
    return oss.str();
}
        
void parseString(string _str)
{
    for (auto _char : _str) 
    {
        if (nums.find(_char) == string::npos)
        {
            cout << "uncorrect number!!1" << endl;
            return;
        }
        switch (_char)
        {
            case '0':
                numsSys.push_front(0);
                break;
            case '1':
                numsSys.push_front(1);
                break;
            case '2':
                numsSys.push_front(2);
                break;
            case '3':
                numsSys.push_front(3);
                break;
            case '4':
                numsSys.push_front(4);
                break;
            case '5':
                numsSys.push_front(5);
                break;
            case '6':
                numsSys.push_front(6);
                break;
            case '7':
                numsSys.push_front(7);
                break;
            case '8':
                numsSys.push_front(8);
                break;
            case '9':
                numsSys.push_front(9);
                break;
            case 'A':
                numsSys.push_front(10);
                break;
            case 'B':
                numsSys.push_front(11);
                break;
            case 'C':
                numsSys.push_front(12);
                break;
            case 'D':
                numsSys.push_front(13);
                break;
            case 'E':
                numsSys.push_front(14);
                break;
            case 'F':
                numsSys.push_front(15);
                break;
        }
    }
}

int ConvertToDecimal(string num, int currNumSys)
{
    int result = 0, _pow = 0;
    parseString(ToString(num));
    for (int num : numsSys)
    {
        result += num * pow(currNumSys, _pow);
        _pow++;
    }
    return result;
}

string ConvertToOther(int num, int requiredSys)
{
    string result = "";
    do
    {
        switch (num % requiredSys)
        {
            case 0:
                result.insert(0, "0");
                break;
            case 1:
                result.insert(0, "1");
                break;
            case 2:
                result.insert(0, "2");
                break;
            case 3:
                result.insert(0, "3");
                break;
            case 4:
                result.insert(0, "4");
                break;
            case 5:
                result.insert(0, "5");
                break;
            case 6:
                result.insert(0, "6");
                break;
            case 7:
                result.insert(0, "7");
                break;
            case 8:
                result.insert(0, "8");
                break;
            case 9:
                result.insert(0, "9");
                break;
            case 10:
                result.insert(0, "A");
                break;
            case 11:
                result.insert(0, "B");
                break;
            case 12:
                result.insert(0, "C");
                break;
            case 13:
                result.insert(0, "D");
                break;
            case 14:
                result.insert(0, "E");
                break;
            case 15:
                result.insert(0, "F");
                break;
        }
        num = num / requiredSys;
    }
    while (num / requiredSys != 0);
    if (num % requiredSys != 0)
    {
        switch (num % requiredSys)
        {
            case 0:
                result.insert(0, "0");
                break;
            case 1:
                result.insert(0, "1");
                break;
            case 2:
                result.insert(0, "2");
                break;
            case 3:
                result.insert(0, "3");
                break;
            case 4:
                result.insert(0, "4");
                break;
            case 5:
                result.insert(0, "5");
                break;
            case 6:
                result.insert(0, "6");
                break;
            case 7:
                result.insert(0, "7");
                break;
            case 8:
                result.insert(0, "8");
                break;
            case 9:
                result.insert(0, "9");
                break;
            case 10:
                result.insert(0, "A");
                break;
            case 11:
                result.insert(0, "B");
                break;
            case 12:
                result.insert(0, "C");
                break;
            case 13:
                result.insert(0, "D");
                break;
            case 14:
                result.insert(0, "E");
                break;
            case 15:
                result.insert(0, "F");
                break;
        }
    }
    return result;
}

void Task9()
{
    cout << "enter number, input num sys and required num sys" << endl;
    int inp, req;
    string  num;
    
    cin >> num >> inp >> req;

    bool isNegative = false;
    if (num[0] == '-')
    {
        num.erase(0, 1);
        isNegative = true;
    }
    string minus = "";
    if (isNegative)
    {
        minus = "-";
    }
    
    cout << minus + ConvertToOther(ConvertToDecimal(num, inp), req) << endl;
}

int main() 
{
    Task1();
    Task2();
    Task3();
    Task4();
    Task5();
    Task6();
    Task7();
    Task8();
    Task9();
    return 0;
}
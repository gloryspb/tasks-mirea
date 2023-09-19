#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Cone
{
private:
	double height,
		   radiusBase,
		   radiusVertex;

public:
	Cone(double height, double radiusBase, double radiusVertex);

	double GetVolume();
	double GetArea();
};


Cone::Cone(double _height, double _radiusBase, double _radiusVertex)
{
	height = _height;
	radiusBase = _radiusBase;
	radiusVertex = _radiusVertex;
}

double Cone::GetVolume()
{
	return 1.0/3 * 3.14 * height * (radiusBase * radiusBase + radiusVertex * radiusBase + radiusVertex * radiusVertex);
}

double Cone::GetArea()
{
	return 3.14 * (radiusBase * radiusBase + (radiusVertex * radiusBase)
		* (sqrt(radiusBase * radiusBase + height * height))
		+ radiusVertex * radiusVertex);
}


void Task1()
{
	cout << "Enter the height, base radius and top radius:" << endl;
	double _height, 
		   _radiusBase, 
		   _radiusVertex;
	cin >> _height >> _radiusBase >> _radiusVertex;

	//Cone _cone = new Cone(_height, _radiusBase, _radiusVertex);

	Cone _cone(_height, _radiusBase, _radiusVertex);

	cout << _cone.GetArea() << endl;
	cout << _cone.GetVolume() << endl;
}

double Task2(double numA, double numX)
{
	if (abs(numX) < 1)
	{
		return numA * log(abs(numX));
	}
	else
	{
		double num = numA - numX * numX;

		return num >= 0 ? sqrt(num) : NULL;
	}
}

double Task3(double b,  double x, double y)
{
	if (b - x < 0 || b - y < 0)
	{
		cout << "error!" << endl;
		return 0;
	}

	return log(b - y) * sqrt(b - x);
}

void Task4(int num)
{
	for (int i = 0; i < 10; i++)
	{
		cout << num << endl;
		num++;
	}
}

void Task5()
{
	for (double x = -4; x <= 4; x += 0.5)
	{
		cout << "x = " + to_string(x) + ", y = " + to_string((x * x - 2 * x + 2) / (x - 1));
	}
}

int main()
{
	// задание 1

	Task1();
	
	// задание 2

	double numA, numX;
	cout << "Enter 2 nums" << endl;
	cin >> numA >> numX;
	cout << Task2(numA, numX) << endl;

	// задание 3
	double b, x, y;

	cout << "Enter function parameters (b, x, y):" << endl;

	cin >> b >> x >> y;

	cout << Task3(b, x, y) << endl;


	// задание 4
	double num;

	cout << "Enter the number:" << endl;
	cin >> num;
	Task4(num);

	// задание 5

	cout << "Tabulation:" << endl;
	Task5();

	return 0;
}
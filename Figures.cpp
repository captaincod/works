#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
using namespace std;

double pi = atan(1) * 4;

class Figure {
public:
	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
	virtual void print() = 0;
};

class Rectangle : public Figure {
public:
	double height, width;
	Rectangle(double _height, double _width) {
		height = _height;
		width = _width;
	}
	double getPerimeter() {
		return 2 * height + 2 * width;
	}
	double getArea() {
		return width * height;
	}
	void print() {
		cout << "Rectangle height: " << height << " width: " << width << endl;
		cout << "Perimeter = " << getPerimeter() << endl;
		cout << "Area = " << getArea() << endl;
	}

};

class Triangle : public Figure {
public:
	double a, b, c;

	Triangle(double storona) {
		a = storona;
		b = storona;
		c = storona;
	}
	Triangle(double storona1, double storona2) {
		a = storona1;
		b = storona2;
		c = storona2;
	}
	Triangle(double storona1, double storona2, double storona3) {
		a = storona1;
		b = storona2;
		c = storona3;
	}
	double getPerimeter() {
		return a + b + c;
	}
	double getArea() {
		return sqrt((getPerimeter() / 2) * ((getPerimeter() / 2) - a) * ((getPerimeter() / 2) - b) * ((getPerimeter() / 2) - c));
	}
	void print() {
		cout << "Triangle a = " << a << " b = " << b << " c = " << c << endl;
		cout << "Perimeter = " << getPerimeter() << endl;
		cout << "Area = " << getArea() << endl;
	}
};

class Circle : public Figure {
public:
	double radius;
	Circle(double _radius) {
		radius = _radius;
	}
	double getPerimeter() {
		return 2*pi*radius;
	}
	double getArea() {
		return pi* radius* radius;
	}
	void print() {
		cout << "Circle radius = " << radius << endl;
		cout << "Perimeter = " << getPerimeter() << endl;
		cout << "Area = " << getArea() << endl;
	}

};

class Polygon : public Figure {
public:
	int how_many_tops;
	vector<pair<int, int>> tops;

	Polygon() {
		cout << "Enter how many tops in Polygon ";
		cin >> how_many_tops;
		if (how_many_tops > 0){
			cout << "Enter the tops:" << endl;
			for (int i = 0; i < how_many_tops; i++) {
				int x, y;
				cin >> x >> y;
				pair <int, int> top(x,y);
				tops.push_back(top);
			}
		}
	}

	double getPerimeter() {
		/*vector <double> distances;
		for (int i = 1; i < how_many_tops; i++) {
			double distance = sqrt( pow((tops[i].first - tops[i-1].first),2) + pow((tops[i].second - tops[i - 1].second), 2) );
			distances.push_back(distance);
		}
		double perimeter = 0;
		for (int i = 0; i < distances.size; i++) {
			perimeter += distances[i];
		}
		return perimeter;*/
		return 1;
	}
	double getArea() {
		return 1;
	}
	void print() {
		cout << "Polygon has " << how_many_tops << "tops" << endl;
		cout << "Tops: ";
		for (int i = 0; i < how_many_tops; i++) {
			cout << "( " << tops[i].first << ";" << tops[i].second << " ), " ;
		}
		cout << "Perimeter = " << getPerimeter() << endl;
	}

};

int main() {
	Triangle t(2,3,4);
	t.print();
	Circle c(15);
	c.print();
	Rectangle r(13, 12);
	r.print();
};

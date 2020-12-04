#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
using namespace std;

double pi = atan(1) * 4;

class Point {
public:
	int x;
	int y;

	Point(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

class Figure {
public:
	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
	virtual void print() = 0;
	
	double vector(const Point& A, const Point& B) const {
		return  A.x * B.y - B.x * A.y;
	}
	Point get_vector(const Point& A, const Point& B) const {
		return { B.x - A.x, B.y - A.y };
	}
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
	int points_amount;
	vector<Point> points;
	Polygon(int amount) {
		points_amount = amount;
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
		double area = 0;

		for (int i = 1; i < points_amount - 1; i++)
			area += vector(get_vector(points[0], points[i]), get_vector(points[0], points[i + 1]));

		return abs(area / 2.0);
	}
	void print() {
		cout << "Polygon has " << points_amount << "tops" << endl;
		cout << "Tops: ";
		for (int i = 0; i < points_amount; i++) {
			cout << "( " << points[i].first << ";" << points[i].second << " ), " ;
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

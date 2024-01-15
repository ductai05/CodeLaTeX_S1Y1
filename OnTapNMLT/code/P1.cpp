#include <iostream>
#include <cmath>
using namespace std;

typedef struct {
	double x; double y;
} Point;

double LineSegmentLength(Point A, Point B){
	double xA = A.x, xB = B.x;
	double yA = A.y, yB = B.y;
	return sqrt((xA - xB)*(xA - xB) + (yA - yB)*(yA - yB));
}

bool IsAligned(Point A, Point B, Point C){
	double d1, d2;
	d1 = (B.y - A.y) / (B.x - A.x);
	d2 = (B.y - C.y) / (B.x - C.x);
	if(d1 == d2){
		return true;
	} else {
		return false;
	}
}

double TriangleArea(Point A, Point B, Point C){
	if(IsAligned(A, B, C)){
		return 0;
	}
	double a = LineSegmentLength(A, B);
	double b = LineSegmentLength(B, C);
	double c = LineSegmentLength(C, A);
	double s = (a + b + c)/2;
	return sqrt(s*(s - a)*(s - b)*(s - c));
}

int main() {
	Point A; Point B; Point C;
	A.x = 1; A.y = 1;
	B.x = 2; B.y = 2;
	C.x = 3; C.y = 4;
	cin >> A.x >> A.y;
	cin >> B.x >> B.y;
	cin >> C.x >> C.y;
	cout << LineSegmentLength(A, B) << "\n";
	if(IsAligned(A, B, C)){
		cout << "Aligned\n";
	} else {
		cout << "NonAligned\n";
	}
	cout << TriangleArea(A, B, C) << "\n";
    return 0;
}
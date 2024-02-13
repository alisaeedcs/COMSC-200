//Ali Saeed
// Calculates dimensions of shapes
//COMSC-200
//2/4/24
//Done

#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

//function prototypes
vector<string> parseString(string);
void square(float);
void rectangle(float, float);
void circle(float);
void triangle(float);
void cube(float);
void box(float, float, float);
void cylinder(float, float);
void prism(float, float);
void invalid(string);

int main() {
	string line;
	ifstream fin;
	//access input file
	fin.open("Shapes.input.txt");
	//while getting input from txt file
	while (getline(fin, line)) {
		vector<string> tokens;
		//parse 
		tokens = parseString(line);
		//if input had a string
		if (tokens.size() != 0) {
			string shape = tokens[0];
			float first = 0, second = 0, third = 0;
			if (tokens.size() > 1) {
				first = stof(tokens[1]);
			}
			if (tokens.size() > 2) {
				second = stof(tokens[2]);
			}
			if (tokens.size() > 3) {
				third = stof(tokens[3]);
			}
			if (shape == "SQUARE") {
				if (tokens.size() < 2)
					first = 0;
				square(first);
			}
			else if (shape == "RECTANGLE") {
				if (tokens.size() < 2)
					first = 0;
				if (tokens.size() < 3)
					second = 0;
				rectangle(first, second);
			}
			else if (shape == "CIRCLE") {
				if (tokens.size() < 2)
					first = 0;
				circle(first);
			}
			else if (shape == "TRIANGLE") {
				if (tokens.size() < 2)
					first = 0;
				triangle(first);
			}
			else if (shape == "CUBE") {
				if (tokens.size() < 2)
					first = 0;
				cube(first);
			}
			else if (shape == "BOX") {
				if (tokens.size() < 2)
					first = 0;
				if (tokens.size() < 3)
					second = 0;
				if (tokens.size() < 4)
					third = 0;
				box(first, second, third);
			}
			else if (shape == "CYLINDER") {
				if (tokens.size() < 2)
					first = 0;
				if (tokens.size() < 3)
					second = 0;
				cylinder(first, second);
			}
			else if (shape == "PRISM") {
				if (tokens.size() < 2)
					first = 0;
				if (tokens.size() < 3)
					second = 0;
				prism(first, second);
			}
			else if (shape == "EOF") {
				cout << "";
			}
			else
				//if shape was not one of the included
				invalid(shape);
		}
		//skip if no input on line
		else
			cout << "";
	}
	//close input file
	fin.close();
}

//text parsing
vector<string> parseString(string str)
{
	stringstream s(str);
	istream_iterator<string> begin(s), end;
	return vector<string>(begin, end);
}

//2d square
void square(float x) {
	ofstream fout;
	float area, perimeter;
	area = x * x;
	perimeter = 4 * x;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "SQUARE side=" << x << " area=" << area << " perimeter=" << perimeter << endl;
	fout.open("Shapes.output.txt", ofstream::app);
	fout << "SQUARE side=" << x << " area=" << area << " perimeter=" << perimeter << endl;
	fout.close();
}

//2d rectangle
void rectangle(float length, float width) {
	ofstream fout;
	float area, perimeter;
	area = length * width;
	perimeter = (2 * width) + (2 * length);
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "RECTANGLE length=" << length << " width=" << width << " area=" << area << " perimeter=" << perimeter << endl;
	fout.open("Shapes.output.txt", ofstream::app);
	fout << "RECTANGLE length=" << length << " width=" << width << " area=" << area << " perimeter=" << perimeter << endl;
	fout.close();
}

//2d circle
void circle(float radius) {
	ofstream fout;
	float area, perimeter;
	area = 3.14159265358979323846 * (radius * radius);
	perimeter = 2 * 3.14159265358979323846 * radius;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "CIRCLE radius=" << radius << " area=" << area << " perimeter=" << perimeter << endl;
	fout.open("Shapes.output.txt", ofstream::app);
	fout << "CIRCLE radius=" << radius << " area=" << area << " perimeter=" << perimeter << endl;
	fout.close();
}

//2d equilateral triangle
void triangle(float side) {
	ofstream fout;
	float area, perimeter;
	area = (sqrt(3) / 4) * (side * side);
	perimeter = 3 * side;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "TRIANGLE side=" << side << " area=" << area << " perimeter=" << perimeter << endl;
	fout.open("Shapes.output.txt", ofstream::app);
	fout << "TRIANGLE side=" << side << " area=" << area << " perimeter=" << perimeter << endl;
	fout.close();
}

//3d cube
void cube(float side) {
	ofstream fout;
	float surface_area, volume;
	surface_area = 6 * (side * side);
	volume = side * side * side;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "CUBE side=" << side << " surface area=" << surface_area << " volume=" << volume << endl;
	fout.open("Shapes.output.txt", ofstream::app);
	fout << "CUBE side=" << side << " surface area=" << surface_area << " volume=" << volume << endl;
	fout.close();
}

//box 2d rectangle with third dimension
void box(float length, float width, float height) {
	ofstream fout;
	float surface_area, volume;
	surface_area = (2 * length * width) + (2 * length * height) + (2 * height * width);
	volume = length * width * height;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "BOX length=" << length << " width=" << width << " height=" << height << " surface area=" << surface_area << " volume=" << volume << endl;
	fout.open("Shapes.output.txt", ofstream::app);
	fout << "BOX length=" << length << " width=" << width << " height=" << height << " surface area=" << surface_area << " volume=" << volume << endl;
	fout.close();
}

//cylinder 2d circle with a 3rd dimension
void cylinder(float radius, float height) {
	ofstream fout;
	float surface_area, volume;
	surface_area = 2 * 3.14159265358979323846 * radius * height + 2 * 3.14159265358979323846 * (radius * radius);
	volume = 3.14159265358979323846 * (radius * radius) * height;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "CYLINDER radius=" << radius << " height=" << height << " surface area=" << surface_area << " volume=" << volume << endl;
	fout.open("Shapes.output.txt", ofstream::app);
	fout << "CYLINDER radius=" << radius << " height=" << height << " surface area=" << surface_area << " volume=" << volume << endl;
	fout.close();
}

//prism 2d equilateral triangle with a third dimension
void prism(float side, float height) {
	ofstream fout;
	float surface_area, volume;
	surface_area = (2 * ((sqrt(3) / 4) * (side * side))) + (3 * side * height);
	volume = ((sqrt(3) / 4) * (side * side)) * height;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "PRISM side=" << side << " height=" << height << " surface area = " << surface_area << " volume = " << volume << endl;
	fout.open("Shapes.output.txt", ofstream::app);
	fout << "PRISM side=" << side << " height=" << height << " surface area = " << surface_area << " volume = " << volume << endl;
	fout.close();
}

//invalid object
void invalid(string input) {
	ofstream fout;
	fout.open("Shapes.output.txt", ofstream::app);
	cout << input << " Invalid object" << endl;
	fout << input << " Invalid object" << endl;
}

//Ali Saeed
//Calculates dimensions of shapes
//COMSC-200
//2/7/24
//Done

struct Square {
    double side;
};
struct Rectangle {
    double length, width;
};

struct Circle {
    double radius;
};

struct Triangle {
    double side;
};

struct Cube {
    double side;
};

struct Box {
    double length, width, height;
};

struct Cylinder {
    double radius, height;
};

struct Prism {
    double side, height;
};

#include <iostream>
#include <ostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

//function prototypes
vector<string> parseString(string);
void outputSquare(ostream&, const Square&);
void outputRectangle(ostream&, const Rectangle&);
void outputCircle(ostream&, const Circle&);
void outputTriangle(ostream&, const Triangle&);
void outputCube(ostream&, const Cube&);
void outputBox(ostream&, const Box&);
void outputCylinder(ostream&, const Cylinder&);
void outputPrism(ostream&, const Prism&);
void outputInvalid(ostream&, string);

int main() {
    string line;
    ifstream fin;
    ofstream fout;
    //access input file
    fin.open("Shapes.input.txt");
    fout.open("Shapes.output.txt");
    //while getting input from txt file
    vector<void*> myBag; // empty bag
    vector<int> myBagType; //companion array
    for (unsigned int i = 0; getline(fin, line); i++) {
        vector<string> tokens = parseString(line);
        if (tokens.size() != 0) {
            string shape = tokens[0];
            double first, second, third;
            if (tokens.size() > 1) {
                first = atof(tokens[1].c_str());
            }
            if (tokens.size() > 2) {
                second = atof(tokens[2].c_str());
            }
            if (tokens.size() > 3) {
                third = atof(tokens[3].c_str());
            }
            if (shape == "SQUARE") {
                if (tokens.size() < 2)
                    first = 0;
                Square* s = new Square;
                s->side = first;
                myBag.push_back(s);
                myBagType.push_back(1);
            }
            else if (shape == "RECTANGLE") {
                if (tokens.size() < 2)
                    first = 0;
                if (tokens.size() < 3)
                    second = 0;
                Rectangle* r = new Rectangle;
                r->length = first;
                r->width = second;
                myBag.push_back(r);
                myBagType.push_back(2);
            }
            else if (shape == "CIRCLE") {
                if (tokens.size() < 2)
                    first = 0;
                Circle* circ = new Circle;
                circ->radius = first;
                myBag.push_back(circ);
                myBagType.push_back(3);
            }
            else if (shape == "TRIANGLE") {
                if (tokens.size() < 2)
                    first = 0;
                Triangle* t = new Triangle;
                t->side = first;
                myBag.push_back(t);
                myBagType.push_back(4);
            }
            else if (shape == "CUBE") {
                if (tokens.size() < 2)
                    first = 0;
                Cube* cuber = new Cube;
                cuber->side = first;
                myBag.push_back(cuber);
                myBagType.push_back(5);
            }
            else if (shape == "BOX") {
                if (tokens.size() < 2)
                    first = 0;
                if (tokens.size() < 3)
                    second = 0;
                if (tokens.size() < 4)
                    third = 0;
                Box* b = new Box;
                b->length = first;
                b->width = second;
                b->height = third;
                myBag.push_back(b);
                myBagType.push_back(6);
            }
            else if (shape == "CYLINDER") {
                if (tokens.size() < 2)
                    first = 0;
                if (tokens.size() < 3)
                    second = 0;
                Cylinder* cyl = new Cylinder;
                cyl->radius = first;
                cyl->height = second;
                myBag.push_back(cyl);
                myBagType.push_back(7);
            }
            else if (shape == "PRISM") {
                if (tokens.size() < 2)
                    first = 0;
                if (tokens.size() < 3)
                    second = 0;
                Prism* p = new Prism;
                p->side = first;
                p->height = second;
                myBag.push_back(p);
                myBagType.push_back(8);
            }
            else if (shape == "EOF") {
                break;
            }
            else {
                //if shape was not one of the included
                outputInvalid(cout, shape);
                outputInvalid(fout, shape);
            }

        }
        else {
            cout << "";
        }
    }
    //cout loop for console output
    for (unsigned int i = 0; i < myBag.size(); i++) {
        if (myBagType[i] == 1) {
            Square* pSquare = reinterpret_cast<Square*>(myBag[i]); //restore
            Square& rSquare = *pSquare; //dereference pointer to match parameter type
            outputSquare(cout, rSquare);
        }
        else if (myBagType[i] == 2) {
            Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]); //restore
            Rectangle& rRectangle = *pRectangle; //dereference pointer to match parameter type
            outputRectangle(cout, rRectangle);
        }
        else if (myBagType[i] == 3) {
            Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]); //restore
            Circle& rCircle = *pCircle; //dereference pointer to match parameter type
            outputCircle(cout, rCircle);
        }
        else if (myBagType[i] == 4) {
            Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]); //restore
            Triangle& rTriangle = *pTriangle; //dereference pointer to match parameter type
            outputTriangle(cout, rTriangle);
        }
        else if (myBagType[i] == 5) {
            Cube* pCube = reinterpret_cast<Cube*>(myBag[i]); //restore
            Cube& rCube = *pCube; //dereference pointer to match parameter type
            outputCube(cout, rCube);
        }
        else if (myBagType[i] == 6) {
            Box* pBox = reinterpret_cast<Box*>(myBag[i]); //restore
            Box& rBox = *pBox; //dereference pointer to match parameter type
            outputBox(cout, rBox);
        }
        else if (myBagType[i] == 7) {
            Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]); //restore
            Cylinder& rCylinder = *pCylinder; //dereference pointer to match parameter type
            outputCylinder(cout, rCylinder);
        }
        else if (myBagType[i] == 8) {
            Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]); //restore
            Prism& rPrism = *pPrism; //dereference pointer to match parameter type
            outputPrism(cout, rPrism);
        }
    }
    //fout loop for file output
    for (unsigned int i = 0; i < myBag.size(); i++) {
        if (myBagType[i] == 1) {
            Square* pSquare = reinterpret_cast<Square*>(myBag[i]); //restore
            Square& rSquare = *pSquare; //dereference pointer to match parameter type
            outputSquare(fout, rSquare);
        }
        else if (myBagType[i] == 2) {
            Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]); //restore
            Rectangle& rRectangle = *pRectangle; //dereference pointer to match parameter type
            outputRectangle(fout, rRectangle);
        }
        else if (myBagType[i] == 3) {
            Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]); //restore
            Circle& rCircle = *pCircle; //dereference pointer to match parameter type
            outputCircle(fout, rCircle);
        }
        else if (myBagType[i] == 4) {
            Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]); //restore
            Triangle& rTriangle = *pTriangle; //dereference pointer to match parameter type
            outputTriangle(fout, rTriangle);
        }
        else if (myBagType[i] == 5) {
            Cube* pCube = reinterpret_cast<Cube*>(myBag[i]); //restore
            Cube& rCube = *pCube; //dereference pointer to match parameter type
            outputCube(fout, rCube);
        }
        else if (myBagType[i] == 6) {
            Box* pBox = reinterpret_cast<Box*>(myBag[i]); //restore
            Box& rBox = *pBox; //dereference pointer to match parameter type
            outputBox(fout, rBox);
        }
        else if (myBagType[i] == 7) {
            Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]); //restore
            Cylinder& rCylinder = *pCylinder; //dereference pointer to match parameter type
            outputCylinder(fout, rCylinder);
        }
        else if (myBagType[i] == 8) {
            Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]); //restore
            Prism& rPrism = *pPrism; //dereference pointer to match parameter type
            outputPrism(fout, rPrism);
        }
    }
    //deallocation loop
    for (unsigned int i = 0; i < myBag.size(); i++) {
        if (myBagType[i] == 1) {
            Square* pSquare = reinterpret_cast<Square*>(myBag[i]); //restore
            delete pSquare;
        }
        else if (myBagType[i] == 2) {
            Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]); //restore
            delete pRectangle;
        }
        else if (myBagType[i] == 3) {
            Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]); //restore
            delete pCircle;
        }
        else if (myBagType[i] == 4) {
            Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]); //restore
            delete pTriangle;
        }
        else if (myBagType[i] == 5) {
            Cube* pCube = reinterpret_cast<Cube*>(myBag[i]); //restore
            delete pCube;
        }
        else if (myBagType[i] == 6) {
            Box* pBox = reinterpret_cast<Box*>(myBag[i]); //restore
            delete pBox;
        }
        else if (myBagType[i] == 7) {
            Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]); //restore
            delete pCylinder;
        }
        else if (myBagType[i] == 8) {
            Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]); //restore
            delete pPrism;
        }
    }
    //close input file
    fin.close();
    //close output file
    fout.close();
}

//text parsing
vector<string> parseString(string str)
{
    stringstream s(str);
    istream_iterator<string> begin(s), end;
    return vector<string>(begin, end);
}

//2d square
void outputSquare(ostream& x, const Square& shape) {
    double area = shape.side * shape.side;
    double perimeter = shape.side * 4;
    x << "SQUARE side=" << shape.side;
    x.setf(ios::fixed);
    x.precision(2);
    x << " area=" << area << " perimeter=" << perimeter << endl;
    x.unsetf(ios::fixed);
    x.precision(6);
}

//2d rectangle
void outputRectangle(ostream& x, const Rectangle& shape) {
    double area = shape.length * shape.width;
    double perimeter = (shape.length * 2) + (shape.width * 2);
    x << "RECTANGLE length=" << shape.length << " width=" << shape.width;
    x.setf(ios::fixed);
    x.precision(2);
    x << " area=" << area << " perimeter=" << perimeter << endl;
    x.unsetf(ios::fixed);
    x.precision(6);
}

//2d circle
void outputCircle(ostream& x, const Circle& shape) {
    double area = 3.14159265358979323846 * (shape.radius * shape.radius);
    double perimeter = 2 * 3.14159265358979323846 * shape.radius;
    x << "CIRCLE radius=" << shape.radius;
    x.setf(ios::fixed);
    x.precision(2);
    x << " area=" << area << " perimeter=" << perimeter << endl;
    x.unsetf(ios::fixed);
    x.precision(6);
}

//2d equilateral triangle
void outputTriangle(ostream& x, const Triangle& shape) {
    double area = (sqrt(3) / 4) * (shape.side * shape.side);
    double perimeter = 3 * shape.side;
    x << "TRIANGLE side=" << shape.side;
    x.setf(ios::fixed);
    x.precision(2);
    x << " area=" << area << " perimeter=" << perimeter << endl;
    x.unsetf(ios::fixed);
    x.precision(6);
}


//3d cube
void outputCube(ostream& x, const Cube& shape) {
    double surface_area = 6 * (shape.side * shape.side);
    double volume = shape.side * shape.side * shape.side;
    x << "CUBE side=" << shape.side;
    x.setf(ios::fixed);
    x.precision(2);
    x << " surface area=" << surface_area << " volume=" << volume << endl;
    x.unsetf(ios::fixed);
    x.precision(6);
}

//box 2d rectangle with third dimension
void outputBox(ostream& x, const Box& shape) {
    double surface_area = (2 * shape.length * shape.width) + (2 * shape.length * shape.height) + (2 * shape.height * shape.width);
    double volume = shape.length * shape.width * shape.height;
    x << "BOX length=" << shape.length << " width=" << shape.width << " height=" << shape.height;
    x.setf(ios::fixed);
    x.precision(2);
    x << " surface area=" << surface_area << " volume=" << volume << endl;
    x.unsetf(ios::fixed);
    x.precision(6);
}


//cylinder 2d circle with a 3rd dimension
void outputCylinder(ostream& x, const Cylinder& shape) {
    double surface_area = 2 * 3.14159265358979323846 * shape.radius * shape.height + 2 * 3.14159265358979323846 * (shape.radius * shape.radius);
    double volume = 3.14159265358979323846 * (shape.radius * shape.radius) * shape.height;
    x << "CYLINDER radius=" << shape.radius << " height=" << shape.height;
    x.setf(ios::fixed);
    x.precision(2);
    x << " surface area=" << surface_area << " volume=" << volume << endl;
    x.unsetf(ios::fixed);
    x.precision(6);
}

//prism 2d equilateral triangle with a third dimension
void outputPrism(ostream& x, const Prism& shape) {
    double surface_area = (2 * ((sqrt(3) / 4) * (shape.side * shape.side))) + (3 * shape.side * shape.height);
    double volume = ((sqrt(3) / 4) * (shape.side * shape.side)) * shape.height;
    x << "PRISM side=" << shape.side << " height=" << shape.height;
    x.setf(ios::fixed);
    x.precision(2);
    x << " surface area = " << surface_area << " volume = " << volume << endl;
    x.unsetf(ios::fixed);
    x.precision(6);
}

//invalid object
void outputInvalid(ostream& x, string input) {
    x << input << " Invalid object" << endl;
}

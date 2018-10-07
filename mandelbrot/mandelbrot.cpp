#include <iostream>
#include <cmath>

using namespace std;

class Complex {
    public:
        double real;
        double imaginary;

        Complex(double r = 0, double i = 0) {
            real = r;
            imaginary = i;
        }

        void add(Complex* z) {
            real += z->real;
            imaginary += z->imaginary;
        }

        void multiply(double r, double i) {
            double rr = real;
            real = real * r - imaginary * i;
            imaginary = rr * i + imaginary * r;
        }

        void square() {
            this->multiply(real, imaginary);
        }

        double modulus() {
            return sqrt(pow(real,2)+pow(imaginary,2));
        }
};

// (z_n+1) ← (z_n)^2 + c
bool mandelbrot(Complex* computed, Complex* start, int r) {
    if (r == 0) {
        return computed->modulus() <= 2;
    }
    r--;
    computed->square();
    computed->add(start);
    return mandelbrot(computed, start, r);
}

int main() {

    float x, y; // z = x + yi
    int r, i = 0; // maximum iterations
    while(scanf("%f %f %i" , &x, &y, &r) != EOF) {
        cout << "CASE " << ++i << ": " << (mandelbrot(new Complex(0,0), new Complex(x,y), r) ? "IN" : "OUT" ) << endl;
    }
}

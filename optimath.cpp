#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>

namespace Optimath {
    class Shape {
    public:
        virtual double area() const = 0;
        virtual ~Shape() {}
    };

    class Rectangle : public Shape {
    private:
        double width, height;

    public:
        Rectangle(double w, double h) : width(w), height(h) {}

        double area() const override {
            return width * height;
        }
    };


    template <typename T>
    T max(T a, T b) {
        return (a > b) ? a : b;
    }

    class Complex {
    public:
        double real, imag;

        Complex(double r, double i) : real(r), imag(i) {}

        Complex operator+(const Complex& anotherComplex) {
            return Complex(real + anotherComplex.real, imag + anotherComplex.imag);
        }
    };
}

int main() {
    namespace opti = Optimath;
    using namespace opti;

    std::vector<int> numbers = {5, 2, 8, 1, 3};

    std::cout << "Vector elements: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Smart pointers
    auto rectanglePtr = std::make_unique<Rectangle>(4.0, 5.0);
    std::cout << "Rectangle area: " << rectanglePtr->area() << std::endl;

    int maxInt = max(42, 56);
    double maxDouble = max(3.14, 2.71);
    std::cout << "Max Int: " << maxInt << ", Max Double: " << maxDouble << std::endl;


    Complex c1(1.0, 2.0), c2(2.5, 3.5);
    Complex c3 = c1 + c2;
    std::cout << "Complex Sum: " << c3.real << " + " << c3.imag << "i" << std::endl;

    return 0;
}

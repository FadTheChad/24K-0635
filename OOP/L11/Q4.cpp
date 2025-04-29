#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <cmath>        // For std::sqrt
#include <type_traits> // For std::is_arithmetic (alternative to specialization)

using namespace std;

class NegativeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "NegativeNumberException - Cannot compute square root of negative values!";
    }
};

class InvalidTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "InvalidTypeException - Provided value is not a numeric type!";
    }
};

template<typename T>
double sqrt_custom(T num) {
    throw InvalidTypeException();
}

// Specialization for double
template<>
double sqrt_custom<double>(double num) {
    if (num < 0.0) {
        throw NegativeNumberException();
    }
    return sqrt(num);
}

// Specialization for float
template<>
double sqrt_custom<float>(float num) {
    if (num < 0.0f) {
        throw NegativeNumberException();
    }
    return sqrt(static_cast<double>(num)); 
}

// Specialization for int
template<>
double sqrt_custom<int>(int num) {
    if (num < 0) {
        throw NegativeNumberException();
    }
    return sqrt(static_cast<double>(num));
}

// Specialization for long
template<>
double sqrt_custom<long>(long num) {
    if (num < 0L) {
        throw NegativeNumberException();
    }
    return sqrt(static_cast<double>(num));
}

int main() {
    cout << "sqrt_custom(12.0): ";
    try {
        cout << sqrt_custom(12.0) << endl;
    } catch(const exception& e) {
        cerr << e.what() << endl;
    }

    cout << "sqrt_custom(18): ";
    try {
        cout << sqrt_custom(18) << endl;
    } catch(const exception& e) {
        cerr << e.what() << endl;
    }

    cout << "sqrt_custom(-4.0): ";
    try {
        cout << sqrt_custom(-4.0) << endl;
    } catch (const NegativeNumberException& e) {
        cout << e.what() << endl; 
    } catch (const exception& e) {
        cerr << "Unexpected: " << e.what() << endl;
    }

    cout << "sqrt_custom(-2): ";
    try {
        cout << sqrt_custom(-2) << endl;
    } catch (const NegativeNumberException& e) {
        cout << e.what() << endl; 
    } catch (const exception& e) {
        cerr << "Unexpected: " << e.what() << endl;
    }

    cout << "sqrt_custom(\"hello\"): ";
    try {
        cout << sqrt_custom<string>("hello") << endl;
    } catch (const InvalidTypeException& e) {
        cout << e.what() << endl; 
    } catch (const exception& e) {
        cerr << "Unexpected: " << e.what() << endl;
    }

    return 0;
}

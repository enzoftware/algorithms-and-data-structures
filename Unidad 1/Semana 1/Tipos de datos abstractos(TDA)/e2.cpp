//  2. suma de números imaginarios
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Imaginario {
    float real;
    float img;
public:
    Imaginario(float real = 0, float img = 0) : real(real), img(img) {}

    Imaginario operator +(Imaginario otro) {
        return Imaginario(this->real + otro.real, this->img + otro.img);
    }
    string toStr()  {
        stringstream ss;
        ss << this->real << " + " << this->img << "i";
        return ss.str();
    }
};

int main() {
    Imaginario a(1, 2);
    Imaginario b(2, 3);

    Imaginario c = a + b;
    cout << c.toStr();
    return 0;
}


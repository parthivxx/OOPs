#include <bits/stdc++.h>
using namespace std;

class Complex
{
    int real, img;

public:
    Complex() {}
    Complex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }
    void display()
    {
        cout << real << "+i" << img << '\n';
    }
    Complex operator+(Complex &c)
    {
        Complex t;
        t.real = real + c.real;
        t.img = img + c.img;
        return t;
    }
    friend ostream &operator<<(ostream &obj, const Complex &c);
    friend istream &operator>>(istream &obj, Complex &c);
};

istream &operator>>(istream &obj, Complex &c)
{
    obj >> c.real >> c.img;
    return obj;
}
ostream &operator<<(ostream &obj, const Complex &c)
{
    obj << c.real << "+" << c.img << "i\n";
    return obj;
}

int main()
{
    Complex c1,c2;
    cin>>c1;
    cin>>c2;
    Complex c3 = c1 + c2;
    cout << c1;
    cout << c2;
    cout << c3;
    return 0;
}
#include <iostream>
using namespace std;
class complex
{
public:
    int real;
    int imaginary;
    complex()
    {
        real = 0;
        imaginary = 0;
        cout << real << "+" << imaginary << "i" << endl;
    }
    complex operator+(complex b)
    {
        complex c;
        c.real = real + b.real;
        c.imaginary = imaginary + b.imaginary;
        cout << "Additionis:" << c.real << " +" << c.imaginary << "i";
        return c;
    }
    complex operator*(complex b)
    {
        complex d;
        d.real = (real * b.real) -
                 (imaginary * b.imaginary);
        d.imaginary = (real * b.imaginary) + (imaginary *
                                              b.real);
        cout << "Multiplicationis:" << d.real << "+" << d.imaginary << "i";
        return d;
    }
    friend ostream &operator<<(ostream &output, complex &m);
    friend istream &operator>>(istream &input, complex &m);
};
ostream &operator<<(ostream &output, complex &m)
{
    output << "\nComplexnumberis: " << m.real << " +" << m.imaginary << "i" << endl;
    return output;
}
istream &operator>>(istream &input, complex &m)
{
    input >> m.real >> m.imaginary;
    return input;
}
int main()
{
    complex a;
    cout << "Enterfirstcomplexno.:";
    cin >> a;
    cout << "Entersecondcomplexno.:";
    complex b;
    cin >> b;
    cout << a;
    cout << b;
    complex c = a + b;
    complex d = a * b;
    return 0;
}
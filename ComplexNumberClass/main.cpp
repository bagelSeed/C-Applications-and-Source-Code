#include <iostream>

using namespace std;

class cplxNum
{
    public:
        cplxNum();
        cplxNum(cplxNum &num);
        cplxNum(double real, double imag);
        double getReal();
        double getImag();
        void setReal(double real);
        void setImag(double imag);
        void addToComplex(cplxNum num);
        void subtractFromComplex(cplxNum num);
        void multiplyByComplex(cplxNum num);
        void divideByComplex(cplxNum num);
        friend ostream &operator<<(ostream &stream, cplxNum &num);
    private:
        double mReal;//m = data member
        double mImag;
};

ostream &operator<<(ostream &stream, cplxNum &num)
{
    stream <<"("<<num.getReal()<<" + "<<num.getImag()<<" i)";
    return stream;
}

int main()
{
    cplxNum z1(3,5);
    cplxNum z1(z1);
    cplxNum z1(-15, 2);
    cplxNum z1(2,-4);
    cout <<z1<<" * "<<z2<<" = ";
    z1.multiplyByComplex(z2);
    cout <<z1<<endl;

    cout <<z2<<" - "<<z3<<" = ";
    z3.subtractFromComplex(z2);
    cout <<z3<<endl;

    cout <<z4<<" + "<<z1<<" = ";
    z4.addToComplex(z1);
    cout <<z4<<endl;

    cout <<z4<<" / "<<z2<<" = ";
    z4.divideByComplex(z2);
    cout <<z4<<endl;
    return 0;
}

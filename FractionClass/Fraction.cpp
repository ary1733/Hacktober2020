#include <iostream>
using namespace std;
/************ PROJECT Headers ********************************/
#include "Fraction.hpp"

    //constructor
    Fraction :: Fraction(int m, int n):p(m),q(n){normalize(p,q);};

    //explicit fraction typecast definition
    Fraction :: Fraction(double d)
    {
        int m = (int)d*prec;
        int n = prec;

        normalize(m,n);
        p=m;
        q=n;
    }

    //deep copy constructor
    Fraction :: Fraction(const Fraction &fp):p(fp.p),q(fp.q){normalize(p,q);}

    //print p for whole number and p/q for q!=1
    ostream& operator<<(ostream& os, const Fraction& f)
    {
        if(f.q == 1)
        {
            os<<f.p;
        }
        else if(f.p == 0)
        {
            os << f.p ;
        }
        else
        {
            os<< f.p<<'/'<<f.q;
        }
        return os;
    }

    //read pair of int as p/q
    istream& operator>>(istream& os, Fraction& f)
    {
        int m,n;
        os>>m>>n;
        f = Fraction(m,n);
        return os;
    }

    //copy assignment
    Fraction& Fraction::operator=(const Fraction& cpy)
    {
        if(this != &cpy)
        {
            int m,n;
            m = cpy.p;
            n = cpy.q;
            normalize(m,n);
            p= m;
            q=n;
        }
        return *this;
    }


    Fraction Fraction :: operator+()
    {
        return *this;
    }

    //changes sign of p
    Fraction Fraction :: operator-()
    {
        Fraction temp(*this);
        temp.p *=-1;
        return temp;
    }

    //returns reference after updating
    Fraction& Fraction :: operator++()
    {
        this->p +=this->q;
        normalize(p,q);
        return *this;
    }

    //returns a copy and updates the original number
    Fraction Fraction :: operator++(int)
    {
        Fraction temp(*this);
        this->p += this->q;
        normalize(p,q);
        return temp;
    }

    //update the fraction and the returns reference
    Fraction& Fraction :: operator--()
    {
        this->p -=this->q;
        normalize(p,q);
        return *this;
    }

    //returns a copy and updates the original number
    Fraction Fraction :: operator--(int)
    {
        Fraction temp(*this);
        this->p -= this->q;
        normalize(p,q);
        return temp;
    }


    //perform rational addition
    Fraction operator+(const Fraction &a, const Fraction &b)
    {
        int m, n;
        m = a.p * b.q + a.q * b.p;
        n = a.q * b.q;
        Fraction add(m,n);
        return add;
    }

    //perform rational subtraction
    Fraction operator-(const Fraction &a, const Fraction &b)
    {
        int m, n;
        m = a.p * b.q - a.q * b.p;
        n = a.q * b.q;
        Fraction sub(m,n);
        return sub;
    }

    //perform rational multiplication
    Fraction operator*(const Fraction &a, const Fraction &b)
    {
        int m, n;
        m = a.p * b.p;
        n = a.q * b.q;
        Fraction mul(m,n);
        return mul;
    }

    //perform rational division
    Fraction operator/(const Fraction &a, const Fraction &b)
    {
        int m, n;
        if(b.p == 0)
        {
            cout<<"throwing exception\n";
            throw runtime_error("CAN'T DIVIDE BY ZERO __ CUSTOM EXCEPTION\n");
            return {1,1};
        }
        m = a.p * b.q;
        n = a.q * b.p;
        Fraction div(m,n);
        return div;
    }

    //returns remainder [0, abs(b)) such that a = quo*b + remainder
    Fraction operator%(const Fraction &a, const Fraction &b)
    {
        if(b.p == 0)
        {
            cout<<"throwing exception\n";
            throw runtime_error("CAN'T DIVIDE BY ZERO __ CUSTOM EXCEPTION\n");
            return {1,1};
        }
        Fraction div = a/b;
        // 15%7 = 7*2 + {1}
        // -15%7 = 7*-3 +{-6}
        // remainder remains [0 , D)
        Fraction remainder = a - ((int)(div.p / div. q))*b ;

        if(remainder.p < 0)
        {
            if( b.p < 0 )
            {
                remainder = remainder - b;
            }
            else
            {
                remainder = remainder + b;
            }
        }
        //int x =(div.p % div.q +div.q)%div.q;
        return remainder;
    }

    //logical == operator
    bool Fraction :: operator== (const Fraction &b) const
    {
        const Fraction &a = *this;
        if(a.p == b.p && a.q == b.q)    return true;
        else return false;
    }

    //logical !=
    bool  Fraction :: operator!= (const Fraction &b) const
    {
        const Fraction &a = *this;
        if(a.p * b.q != b.p * a.q)    return true;
        else return false;
    }
    //logical <=
    bool Fraction :: operator<= (const Fraction &b) const
    {
        const Fraction &a = *this;
        if(a.p * b.q <= b.p * a.q)    return true;
        else return false;
    }

    //logical >=
    bool Fraction :: operator>= (const Fraction &b) const
    {
        const Fraction &a = *this;
        if(a.p * b.q >= b.p * a.q)    return true;
        else return false;
    }

    //logical <
    bool Fraction :: operator< (const Fraction &b) const
    {
        const Fraction &a = *this;
        if(a.p * b.q < b.p * a.q)    return true;
        else return false;
    }

    //logical >
    bool Fraction :: operator> (const Fraction &b) const
    {
        const Fraction &a = *this;
        if(a.p * b.q > b.p * a.q)    return true;
        else return false;
    }

    //calculate inverse
    Fraction Fraction :: operator!() const
    {
        Fraction inv(this->q,this->p);
        return inv;
    }

    //returns precision
    int Fraction :: precision()
    {
        return prec;
    }

    //compute gcd
    int Fraction:: gcd(int a, int b)
    {
        a=abs(a);
        b=abs(b);
        if(a==0 && b == 0)
        {
            cerr<<"gcd(0,0) not defined"<<endl;
            exit(2);
        }
        if(a>b)
        {
            return utilgcd(a,b);
        }
        else
        {
            return utilgcd(b,a);
        }

    }

    int Fraction:: utilgcd(int a, int b)
    {
        if(b==0)
        {
            return a;
        }
        else
        {
            return utilgcd(b,a%b);
        }
    }


    void Fraction ::normalize(int &m, int &n)
    {
        if(n==0)
        {
            cerr<<"Denominator cannot be 0\n";
            //cout<<"Denominator cannot be 0\n";
            exit(1);
        }
        if(m==0)
        {
            m=0;
            n=1;
        }
        else
        {
            int _gcd = gcd(m,n);
            m = m /_gcd;
            n = n/_gcd;

            if(n<0)
            {
                m*=-1;
                n*=-1;
            }
        }
        return ;
    }

    //computes lcm
    int Fraction :: lcm (int a, int b)
    {
        int prod = a*b;
        int _gcd = gcd(a,b);

        prod = abs(prod);
        return prod / _gcd;
    }

    //static variable initialization
    const Fraction Fraction :: sc_fUnity = Fraction();
    const Fraction Fraction :: sc_fZero = Fraction(0);



    //only inbuilt datatypes as member ,hence no need to define destructor
    Fraction::~Fraction()
    {

    }

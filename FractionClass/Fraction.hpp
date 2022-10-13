
class Fraction
{
private:
    //taking both p,q as int because p can be signed and q can temprorarily store -ve values
    int p,q;
    //prec for double to fraction conversion, must remain constant
    const int prec = 1000;

public:

    //Class constant
    static const Fraction sc_fUnity;
    //Class constant
    static const Fraction sc_fZero;

    //Default constructor with parameter overloading
    Fraction(int m = 1, int n = 1);

    //Explicit double to fraction constructor
    explicit Fraction(double d);

    //copy constructor
    Fraction(const Fraction &fp);

    //Output stream operator overloading
    friend ostream& operator<<(ostream& os, const Fraction& f);


    //input stream operator overloading
    friend istream& operator>>(istream& os, Fraction& f);

    //copy assignment, input must remain constant
    Fraction& operator=(const Fraction& cpy);

    //unary operator+
    Fraction operator+();

    //unary operator-
    Fraction operator-();

    //prefix increment
    Fraction& operator++();

    //postfix increment, dummy int
    Fraction operator++(int);

    //prefix decrement
    Fraction& operator--();

    //postfix decrement, dummy int
    Fraction operator--(int);

    //friend function binary function, inputs must remain constant
    friend Fraction operator+(const Fraction &a, const Fraction &b);
    friend Fraction operator-(const Fraction &a, const Fraction &b);
    friend Fraction operator*(const Fraction &a, const Fraction &b);
    friend Fraction operator/(const Fraction &a, const Fraction &b);
    friend Fraction operator%(const Fraction &a, const Fraction &b);

    //logical operation , constant function for keeping this constant, and constant arguement
    bool operator== (const Fraction &b) const;
    bool operator!= (const Fraction &b) const;
    bool operator<= (const Fraction &b) const;
    bool operator>= (const Fraction &b) const;
    bool operator< (const Fraction &b) const;
    bool operator> (const Fraction &b) const;

    //user defined inverse function
    Fraction operator!() const;


    //returns the constant precision
    int precision();

    //gcd function
    int gcd( int  a, int b);

    //a gcd utility fuction
    int utilgcd(int a,int b);


    int lcm(int a, int b);

    //normalizes a and b , checks for b==0
    void normalize(int &a, int &b);


    ~Fraction();


};

//Fraction - описываем простую дробь
#include<iostream>
using namespace std;

class Fraction
{
	int integer;        //Целая часть
	int numerator;      //Числитель
	int denominator;    //Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//          Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		//Single-argument-constructor - конструктор с одним параметром
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstructor" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor\t" << this << endl;
	}
	
	//           Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//          Compound Assignments
	Fraction& operator+=(const Fraction& other)
	{
		this->integer += other.integer;
		this->numerator += other.numerator;
		this->denominator += other.denominator;
		return *this;
	}

	Fraction& operator-=(const Fraction& other)
	{
		this->integer -= other.integer;
		this->numerator -= other.numerator;
		this->denominator -= other.denominator;
		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		this->integer *= other.integer;
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		return *this;
	}

	Fraction& operator/=(const Fraction& other)
	{
		this->integer /= other.integer;
		this->numerator /= other.numerator;
		this->denominator /= other.denominator;
		return *this;
	}

	//           Increment/Decrement
	Fraction& operator++()    //Prefix increment
	{
		this->integer++;
		this->numerator++;
		this->denominator++;
		return *this;
	}

	Fraction& operator++(int)  //Postfix increment
	{
		Fraction old = *this;
		this->integer++;
		this->numerator++;
		this->denominator++;
		return old;
	}

	Fraction& operator--()     //Prefix decrement
	{
		this->integer--;
		this->numerator--;
		this->denominator--;
		return *this;
	}

	Fraction& operator--(int)  //Postfix decrement
	{
		Fraction old = *this;
		this->integer--;
		this->numerator--;
		this->denominator--;
		return old;
	}

	//                       Compaison Operators
	bool operator==(const Fraction& other)
	{
		return this->integer == other.integer && this->numerator == other.numerator && this->denominator == other.denominator;
	}
	
	bool operator!=(const Fraction& other)
	{
		return !(this->integer == other.integer && this->numerator == other.numerator && this->denominator == other.denominator);
	}

	bool operator>(const Fraction& other)
	{
		return this->integer > other.integer && this->numerator > other.numerator && this->denominator > other.denominator;
	}

	bool operator<(const Fraction& other)
	{
		return this->integer < other.integer && this->numerator < other.numerator && this->denominator < other.denominator;
	}

	bool operator>=(const Fraction& other)
	{
		return this->integer >= other.integer && this->numerator >= other.numerator && this->denominator >= other.denominator;
	}

	bool operator<=(const Fraction& other)
	{
		return this->integer <= other.integer && this->numerator <= other.numerator && this->denominator <= other.denominator;
	}


	//           Methods:
	void to_proper()
	{
		//Переводит дробь в правильную - выделяет целую часть:
		integer += numerator / denominator;
		numerator %= denominator;
	}
	void to_improper()
	{
		//Переводит дробь в неправильную - интегрирует целую часть в числитель:
		numerator += integer * denominator;
		integer = 0;
	}
	void reduce()
	{
		//Сокращает дробь:
		
	}
	void print()
	{
		if (integer)cout << integer;    //Если есть целая часть, выводим её на экран
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;    //Если есть дробная часть, числитель делим на знаменатель
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
}; 

//                      cin/cout
ostream& operator<<(ostream& os, const Fraction& obj)
{
	os << obj.get_integer() << "\t" << obj.get_numerator() << "\t" << obj.get_denominator();
	return os;
}

istream& operator>>(istream& is, Fraction& obj)
{
	int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;
}

//                 Arithmetical operators
Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction buffer;
	buffer.set_integer(left.get_integer() + right.get_integer());
	buffer.set_numerator(left.get_numerator() + right.get_numerator());
	buffer.set_denominator(left.get_denominator() + right.get_denominator());
	return buffer;
}

Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction buffer;
	buffer.set_integer(left.get_integer() - right.get_integer());
	buffer.set_numerator(left.get_numerator() - right.get_numerator());
	buffer.set_denominator(left.get_denominator() - right.get_denominator());
	return buffer;
}

Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction buffer;
	buffer.set_integer(left.get_integer() * right.get_integer());
	buffer.set_numerator(left.get_numerator() * right.get_numerator());
	buffer.set_denominator(left.get_denominator() * right.get_denominator());
	return buffer;
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction buffer;
	buffer.set_integer(left.get_integer() / right.get_integer());
	buffer.set_numerator(left.get_numerator() / right.get_numerator());
	buffer.set_denominator(left.get_denominator() / right.get_denominator());
	return buffer;
}

//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;     //Default constructor
	A.print();
	Fraction B = 5; //Single-argument constructor
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRUCTORS_CHECK

	Fraction A(3, 4, 8);
	A.to_proper();
	A.print();
	A.to_improper();
	A.print();
	A.reduce();
	A.print();
	cout << A << endl;
	/*cout << "Введите целую часть, числитель и знаменатель дроби: "; cin >> A;
	cout << A << endl;
	Fraction B(3, 5, 1);
	cout << B << endl;
	Fraction C = A + B;
	Fraction D = A >= B;
	if (D == 1)cout << "True" << endl;
	else cout << "False" << endl;
	cout << D << endl;*/
}
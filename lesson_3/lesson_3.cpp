#include <iostream>

// TASK 1

class Figure
{
public:
  Figure() {}
  virtual float area() = 0;
  virtual ~Figure(){}
};

class Circle : public Figure
{
private:
  int m_radius;
  static const float PI;
public:
  Circle(int radius): m_radius(radius)
  {
    // body of constr
  }
  float area() override
  {
    return PI * (m_radius * m_radius);
  }
};

const float Circle::PI = 3.14;

class Parallelogram : public Figure
{
protected:
  int m_a, m_b, m_h;
public:
  Parallelogram(int a, int b, int h): m_a(a), m_b(b), m_h(h)
  {
    // body of constr
  }
  float area() override
  {
    return m_a * m_h;
  }
};

class Rectangle : public Parallelogram
{
public:
  Rectangle(int a, int b): Parallelogram(a, b, 0)
  {
    // constr
  }
  float area() override
  {
    return m_a * m_b;
  }
};

class Square : public Parallelogram
{
public:
  Square(int a): Parallelogram(a, 0, 0)
  {
    // constr
  }
  float area() override
  {
    return m_a * m_a;
  }
};

class Rhombus : public Parallelogram
{
public:
  Rhombus(int a, int b, int h): Parallelogram(a, b, h)
  {
    // constr
  }
};

void printArea(Figure* f)
{
  std::cout << f->area() << std::endl;
}

// TASK 2

class Car
{
protected:
  const char* m_company;
  const char* m_model;
public:
  Car(const char* company, const char* model):
    m_company(company), m_model(model)
  {
    std::cout << "Car" << std::endl \
	      << "Company: " << m_company << std::endl \
	      << "Model: " << m_model << std::endl;
  }

};

class PassengerCar: virtual public Car
{
public:
  PassengerCar(const char* company, const char* model):
    Car(company, model)
  {
    std::cout << "PassengerCar" << std::endl		       \
	      << "Company: " << m_company << std::endl \
	      << "Model: " << m_model << std::endl;
  }
};

class Bus: virtual public Car
{
public:
  Bus(const char* company, const char* model):
    Car(company, model)
  {
    std::cout << "Bus" << std::endl	       \
	      << "Company: " << m_company << std::endl	\
	      << "Model: " << m_model << std::endl;
  }
};

class Minivan: public Bus, public PassengerCar
{
public:
  Minivan(const char* company, const char* model):
    Bus(company, model), PassengerCar(company, model), Car(company, model)
  {
    std::cout << "Minivan" << std::endl			\
	      << "Company: " << m_company << std::endl	\
	      << "Model: " << m_model << std::endl;
  }
};

// TASK 3

class Fraction
{
private:
  int m_numerator;
  int m_denominator;
public:
  Fraction(int numerator, int denominator):
    m_numerator(numerator),
    m_denominator((denominator == 0) ? 1 : denominator)
  {
    // constr
  }
  int getNumerator() const
  {
    return m_numerator;
  }
  int getDenominator() const
  {
    return m_denominator;
  }
  void changeFraction(int numerator, int denominator)
  {
    m_numerator = numerator;
    m_denominator = (denominator == 0) ? 1 : denominator;
  }
  float getDecimalFraction()
  {
    return static_cast<float>(m_numerator)/m_denominator;
  }
  void printFraction() const
  {
    std::cout << m_numerator << "/" << m_denominator << std::endl;
  }
  void shortenFraction(unsigned int commonDivisor = 0)
  {
    if (commonDivisor == 0)
      {
	commonDivisor = (m_numerator > m_denominator) ? m_numerator : m_denominator;
      }
    for (int i = commonDivisor; i > 0; i--)
      {
	if ((m_numerator % commonDivisor == 0) && (m_denominator % commonDivisor == 0))
	  {
	    m_numerator /= commonDivisor;
	    m_denominator /= commonDivisor;
	  }
      }
  }
  Fraction operator-() const
  {
    return Fraction(-m_numerator, m_denominator);
  }
  Fraction operator+(Fraction &fraction)
  {
    int numerator, denominator;
    if (m_denominator == fraction.getDenominator())
      {
	numerator = m_numerator + fraction.getNumerator();
	denominator = m_denominator;
      }
    else
      {
	numerator = m_numerator * fraction.getDenominator() + \
	  fraction.getNumerator() * m_denominator;
	denominator = m_denominator * fraction.getDenominator();
      }
    return Fraction(numerator, denominator);
    }
  Fraction operator-(Fraction &fraction)
  {
    int numerator, denominator;
    if (m_denominator == fraction.getDenominator())
      {
	numerator = m_numerator - fraction.getNumerator();
	denominator = m_denominator;
      }
    else
      {
	numerator = m_numerator * fraction.getDenominator() -\
	  fraction.getNumerator() * m_denominator;
	denominator = m_denominator * fraction.getDenominator();
      }
    return Fraction(numerator, denominator);
  }
  Fraction operator*(Fraction &fraction)
  {
    int numerator, denominator;
    numerator = m_numerator * fraction.getNumerator();
    denominator = m_denominator * fraction.getDenominator();
    return Fraction(numerator, denominator);
  }
  Fraction operator/(Fraction &fraction)
  {
    int numerator, denominator;
    numerator = m_numerator * fraction.getDenominator();
    denominator = m_denominator * fraction.getNumerator();
    return Fraction(numerator, denominator);
  }
  bool operator>(Fraction &fraction)
  {
    if (this->getDecimalFraction() > fraction.getDecimalFraction())
      {
	return true;
      }
    else
      {
	return false;
      }
  }
  bool operator<=(Fraction &fraction)
  {
    if (operator>(fraction))
      {
	return false;
      }
    else
      {
	return true;
      }
  }
  bool operator<(Fraction &fraction)
  {
    if (this->getDecimalFraction() < fraction.getDecimalFraction())
      {
	return true;
      }
    else
      {
	return false;
      }
  }
  bool operator>=(Fraction &fraction)
  {
    if (operator<(fraction))
      {
	return false;
      }
    else
      {
	return true;
      }
  }
  bool operator==(Fraction &fraction)
  {
    if (this->getDecimalFraction() == fraction.getDecimalFraction())
      {
	return true;
      }
    else
      {
	return false;
      }
  }
  bool operator!=(Fraction &fraction)
  {
    if (operator==(fraction))
      {
	return false;
      }
    else
      {
	return true;
      }
  }
};

int main()
{
  std::cout << "TASK 1" << std::endl;
  Circle c1(5);
  Parallelogram p1(4, 2, 1);
  Rectangle rec1(5, 6);
  Square sq1(9);
  Rhombus r(1,2,3);
  printArea(&sq1);

  std::cout << "TASK 2" << std::endl;
  std::cout << "NEW OBJECT Car" << std::endl;
  Car car("Lada", "Priora");
  std::cout << std::endl;
  std::cout << "NEW OBJECT PassengerCar" << std::endl;
  PassengerCar passCar("BMW", "x6");
  std::cout << std::endl;
  std::cout << "NEW OBJECT Bus" << std::endl;
  Bus bus("VAZ", "Bus");
  std::cout << std::endl;
  std::cout << "NEW OBJECT Minivan" << std::endl;
  Minivan minivan("Crysler", "Caravan");
  
  std::cout << "TASK 3" << std::endl;
  Fraction fr1(1, 2);
  Fraction fr2(2, 3);
  Fraction fr4(10, 12);
  Fraction fr5(15, 3);
  Fraction fr3 = fr1 + fr2;
  std::cout << "Fractions:" << std::endl;
  fr1.printFraction();
  fr2.printFraction();
  fr3.printFraction();
  fr4.printFraction();
  fr5.printFraction();
  std::cout << "Comparison operators:" << std::endl;
  std::cout << std::boolalpha;
  std::cout << "1/2 <= 2/3 \t" << (fr1 <= fr2) << std::endl	\
	    << "1/2 == 2/3 \t" << (fr1 == fr2) << std::endl		\
	    << "1/2 != 15/3 \t" << (fr1 != fr5) << std::endl		\
	    << "10/12 < 1/2 \t" << (fr4 < fr1) << std::endl			\
	    << "7/6 > 2/3 \t" << (fr3 > fr2) << std::endl			\
	    << "15/3 >= 15/3 \t" << (fr5 >= fr5) << std::endl		\
	    << "7/6 < 10/12 \t" << (fr3 < fr4) << std::endl;
  std::cout << "Arithmetic operators:" << std::endl;
  std::cout << "15/3 + 1/2 = "; (fr5 + fr1).printFraction();
  std::cout << "1/2 - 10/12 = "; (fr1 - fr4).printFraction();
  std::cout << "7/6 - 7/6 = "; (fr3 - fr3).printFraction();
  std::cout << "1/2 * 1/2 = "; (fr1 * fr1).printFraction();
  std::cout << "2/3 / 2/3 = "; (fr2 / fr2).printFraction();
  std::cout << "15/3 / 2/3 = "; (fr5 / fr2).printFraction();
  std::cout << "-2/3 * 7/6 = "; ((-fr2) * fr3).printFraction();
  //  (-(*a1)).printFraction(); // ok
  //  (-a1)->printFraction(); // not ok: wrong type argument
                              // to unary minus
  return 0;
}

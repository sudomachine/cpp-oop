// for main func
#include <iostream>

// for RGBA class
#include <cstdint>


class Power
{
private:
  // expNum ^ degreeNum
  float exponentialNumber;
  float degreeOfNumber;
public:
  // constr (default) without parametrs
  Power()
  {
    exponentialNumber = 0;
    degreeOfNumber = 0;
  }
  // constr with parametrs 
  Power(float expNum, float degreeNum):
    exponentialNumber(expNum),
    degreeOfNumber(degreeNum)
  {
    // body of constructr
  }
  // destructr
  ~Power()
  {
    // body of destructr
  }

public:
  void setExponentialNumber(float exponentialNumber)
  {
   this->exponentialNumber = exponentialNumber;
  }
  void setDegreeOfNumber(float degreeOfNumber)
  {
   this->degreeOfNumber = degreeOfNumber;
  }
  float calculate()
  {
    // raising a number to a power is not necessary
    if (degreeOfNumber == 0)
      {
	return 1.0f;
      }
   // 'calculatedNumber' multiply by 'exponentialNumber' for 'degreeOfNumber' times
   float calculatedNumber = this->exponentialNumber;
   for (int i = 0; i < this->degreeOfNumber; i++)
     {
       calculatedNumber *= this->exponentialNumber;
     }
   return calculatedNumber;
  }
};

class RGBA
{
private:
  // not used uint8_t because the compiler perceives this as like char type
  std::uint16_t m_red;
  std::uint16_t m_green;
  std::uint16_t m_blue;
  std::uint16_t m_alpha;

public:
  // constr default
  RGBA()
  {
    m_red = 0;
    m_green = 0;
    m_blue = 0;
    m_alpha = 255;
  }
  // constr with parametrs
  RGBA(std::uint16_t red, std::uint16_t green, std::uint16_t blue, std::uint16_t alpha):
    m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
  {
    // body of constr
  }
  // deconstr
  ~RGBA()
  {
    // body of deconstr
  }
  void print() const
  {
    std::cout << "Red\t = " << m_red << std::endl \
	      << "Green\t = " << m_green << std::endl \
	      << "Blue\t = " << m_blue << std::endl \
	      << "Alpha\t = " << m_alpha << std::endl;
  }
};

class Stack
{
private:
  int* stack;
  unsigned short stackSize;
  static const unsigned short maxStackSize = 10;
public:
  // default constr
  Stack()
  {
    stackSize = 0;
    stack = new int[maxStackSize];
  }
  // deconstr
  ~Stack()
  {
    delete[] stack;
  }
  void reset()
  {
    stackSize = 0;
  }
  bool push(const int NUMBER_TO_STACK)
  {
    // stack can't be crowded
    if (stackSize == 10)
      {
	return false;
      }
    // else number will be added to stack end
    stack[stackSize++] = NUMBER_TO_STACK;
    return true;
  }
  int pop()
  {
    if (stackSize == 0)
      {
	std::cout << "Stack hasn't any elements!" << std::endl;
	return 0;
      }
    else
      {
	// (stackSize-1) is index of newest element of stack,
	// func deletes and returns this element
	// and decrease stack size by 1
        return stack[--stackSize];
      }
  }
  void print() const
  {
    if (stackSize == 0)
      {
	std::cout << "( )" << std::endl;
      }
    else
      {
	std::cout << "( ";
	for (int i = 0; i < stackSize; i++)
	  {
	    std::cout << stack[i] << " ";
	  }
	std::cout << ")" << std::endl;
      }
  }
};

int main()
{
  // TASK 1
  std::cout << "##### TASK 1" << std::endl;
  
  // initialization
  Power pwrObj1;
  std::cout << pwrObj1.calculate() << std::endl;
  // default initialization
  Power pwrObj2(5.3f, 1.2f);
  std::cout << pwrObj2.calculate() << std::endl;
  // declaring and assignment
  Power pwrObj3;
  pwrObj3.setExponentialNumber(1.1f);
  pwrObj3.setDegreeOfNumber(2.5f);
  std::cout << pwrObj3.calculate() << std::endl;

  // TASK 2
  std::cout << "##### TASK 2" << std::endl;
  
  RGBA rgba1;
  rgba1.print();
  RGBA rgba2(25, 10, 14, 200);
  rgba2.print();

  // TASK 3
  std::cout << "##### TASK 3" << std::endl;

  Stack s;
  s.reset();
  s.print();

  s.push(3);
  s.push(7);
  s.push(5);
  s.print();
  
  s.pop();
  s.print();
  s.pop();
  s.pop();
  s.print();
  s.pop();
  return 0;
}

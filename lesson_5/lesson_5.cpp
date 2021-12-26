
#include <iostream>
#include <string>

// TASK 1
template <class T>
class Pair1
{
private:
  T m_var1;
  T m_var2;
public:
  Pair1(T var1, T var2): m_var1(var1), m_var2(var2)
  {
    // constr
  }
  ~Pair1()
  {
    // destr
  }
  // getter 1
  T first() const
  {
    return m_var1;
  }
  // getter 2
  T second() const
  {
    return m_var2;
  }
};

// TASK 2
template <class T1, class T2>
class Pair2
{
private:
  T1 m_var1;
  T2 m_var2;
public:
  Pair2(T1 var1, T2 var2): m_var1(var1), m_var2(var2)
  {
    // constr
  }
  ~Pair2()
  {
    // destr
  }
  // getter 1
  T1 first() const
  {
    return m_var1;
  }
  // getter 2
  T2 second() const
  {
    return m_var2;
  }
};
/*
// TASK 3
template <const char* name, class T>
class StringValuePair
{
private:
  T m_age;
public:
  StringValuePair(T age): m_age(age)
  {
    std::cout << "template <class T2>\nclass StringValuePair" << std::endl;
    }
};

template <const char* name>
class StringValuePair <name, int> {};
*/
int main()
{
  // TASK 1
  std::cout << "TASK 1" << std::endl;
  Pair1<double> biceps(12.5, 12.9);
  std::cout << "My left biceps: " << biceps.first() << std::endl;
  std::cout << "My right biceps: " << biceps.second() << std::endl;

  Pair1<const char*> parents("Olga", "Aleksey");
  std::cout << "My mother is " << parents.first() << std::endl;
  std::cout << "My father is " << parents.second() << std::endl;

  // TASK 2
  std::cout << "TASK 2" << std::endl;
  Pair2<const char*, float> CPU("Intel Core 2 Duo", 1.30);
  std::cout << "CPU: " << CPU.first() << std::endl \
	    << "CPU Frequency: " << CPU.second() << " GHz" << std::endl;
  Pair2<const char*, const char*> car("BMW", "X6");
  std::cout << "Car Brand: " << car.first() << std::endl \
	    << "Car Model: " << car.second() << std::endl;
/*
  // TASK 3
  std::cout << "TASK 3" << std::endl;
  std::string s = "Hello";
  
  //StringValuePair<25, const char*> p("Sudakov");
  //std::cout << p.first() << " and " << p.second() << std::endl;
  //Pair<100, int> p(10);
  //std::cout << p.first() << " and " << p.second() << std::endl;
  //StringValuePair<const char*> p("Sudakov");
  StringValuePair<int, int> p;
*/
  return 0;
}

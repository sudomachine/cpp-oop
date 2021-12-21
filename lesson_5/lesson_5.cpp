
#include <iostream>

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
  return 0;
}

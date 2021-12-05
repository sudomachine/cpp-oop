
// for main func
#include <iostream>
// for Student class
//#include <ctime>

// TASK 1

class Person
{
private:
  const char* name;
  unsigned short age;
  bool sex;
  float weight;

public:
  // constructr default
  Person()
  {
    name = "Andrey";
    age = 25;
    sex = true;
    weight = 73.50f;
  }
  // constructr
  Person(const char* cName, unsigned short nAge, bool bSex, float fWeight):
    name(cName), age(nAge), sex(bSex), weight(fWeight)
  {
    // body of constructr
  }
  // destructr
  ~Person()
  {
    // body of destructr
  }

  // setters
  void setName(const char* name)
  {
    this->name = name;
  }
  void setAge(unsigned short age)
  {
    this->age = age;
  }
  void setWeight(float weight)
  {
    this->weight = weight;
  }
  // print class members
  void print() const
  {
    std::cout << "Name: " << name << std::endl	\
	      << "Age: " << age << std::endl	\
	      << "Weight: " << weight << std::endl	\
	      << "Sex: " << ((sex == 0) ? "Female" : "Male") << std::endl;
  }
};

class Student : public Person
{
private:
  int studyYear;
  static unsigned int studentsCounter;
public:
  Student()
  {
    studyYear = 2021;
    studentsCounter++;
  }
  Student(const char* cName, unsigned short nAge,
	  bool bSex, float fWeight, int nStudyYear) :
    Person(cName, nAge, bSex, fWeight),
    studyYear(nStudyYear)
  {
    studentsCounter++;
  }
  ~Student ()
  {
    // body of destructr
    studentsCounter--;
  }
  void setStudyYear(int studyYear)
  {
    this->studyYear = studyYear;
  }
  static unsigned int getStudentsCount()
  {
    return studentsCounter;
  }
};

// for Student class
unsigned int Student::studentsCounter = 0;

// TASK 2

class Fruit
{
protected:
  const char* name;
  const char* color;
public:
  Fruit()
  {
    name = "Banana";
    color = "Yellow";
  }
  Fruit(const char* cName, const char* cColor):
    name(cName), color(cColor)
  {
    // body of constructr
  }
  Fruit(const char* cColor):
    color(cColor)
  {
    // body of constructr
  }
  ~Fruit()
  {
    // body of destructr
  }
  // setters
  void setName(const char* name)
  {
    this->name = name;
  }
  void setColor(const char* color)
  {
    this->color = color;
  }
  // getters
  const char* getName() const
  {
    return name;
  }
  const char* getColor() const
  {
    return color;
  }
};

class Banana: public Fruit
{
public:
  Banana(const char* cColor = "Yellow"):
    Fruit(cColor)
  {
    name = "Banana";
  }
  ~Banana()
  {
    //body of destructr
  }
};

class Apple: public Fruit
{
public:
  Apple(const char* cColor = "Red"):
    Fruit(cColor)
  {
    name = "Apple";
  }
  ~Apple()
  {
    // body of destructr
  }
};

class GrannySmith: public Apple
{
public:
  GrannySmith()
  {
    name = "Granny Smith apple";
    color = "Green";
  }
  GrannySmith(const char* cColor):
    Apple(cColor)
  {
    // body of cinstructr
  }
  ~GrannySmith()
  {
    // body of destructr
  }
};

int main()
{
  Apple a("Red");
  Banana b;
  GrannySmith gs;
  std::cout << "My " << a.getName() << " is " << a.getColor() << std::endl \
	    << "My " << b.getName() << " is " << b.getColor() << std::endl \
	    << "My " << gs.getName() << " is " << gs.getColor() << std::endl;
  return 0;
}

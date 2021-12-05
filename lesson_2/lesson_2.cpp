
// for main func
#include <iostream>
// for Student class
//#include <ctime>

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

unsigned int Student::studentsCounter = 0;

int main()
{
  Student s1("Anna", 18, 0, 45.4, 2022);
  s1.print();
  Student s2;
  Student s3;
  std::cout << s1.getStudentsCount() << std::endl;
  std::cout << Student::getStudentsCount() << std::endl;
  return 0;
}

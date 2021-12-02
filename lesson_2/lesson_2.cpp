
class Person
{
private:
  char name[32];
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
  Person(char cName[32], unsigned short nAge, bool bSex, float fWeight):
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
  void setName(char name[32])
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
};

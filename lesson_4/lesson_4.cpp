
#include <iostream>
#include <cassert>
#include <vector>

// TASK 1

class Container
{
private:
  int *m_container;
  unsigned int m_size;
public:
  Container(): m_size(0), m_container(nullptr)
  {
    // constr
  }
  Container(const unsigned int SIZE): m_size(SIZE)
  {
    m_container = new int[SIZE];
  }
  void clear()
  {
    if (m_size > 0)
      {
	delete[] m_container;
	m_container = nullptr;
	m_size = 0;
      }
  }
  ~Container()
  {
    this->clear();
  }
  unsigned int getSize() const
  {
    return m_size;
  }
  void resize(const unsigned int SIZE)
  {
    if (SIZE == m_size)
      {
	return; //void
      }
    else if (SIZE <= 0)
      {
	this->clear();
	return; //void
      }
    else
      {
	unsigned int elementsToCopy = (SIZE < m_size) ? SIZE : m_size;
	int *newContainer = new int[SIZE];
	for (int i = 0; i < elementsToCopy; i++)
	  {
	    newContainer[i] = m_container[i];
	  }
	delete[] m_container;
	m_container = newContainer;
	m_size = SIZE;
      }
    
  }
  void pushBack(const int ELEMENT)
  {
    int *newContainer = new int[++m_size];
    for (int i = 0; i < m_size-1; i++)
      {
	newContainer[i] = m_container[i];
      }
    newContainer[m_size-1] = ELEMENT;
    delete[] m_container;
    m_container = newContainer;
  }
  void pushFront(const int ELEMENT)
  {
    int *newContainer = new int[++m_size];
    for (int i = m_size-1; i > 0; i--)
      {
	newContainer[i] = m_container[i-1];
      }
    newContainer[0] = ELEMENT;
    delete[] m_container;
    m_container = newContainer;
  }
  void popBack()
  {
    if (m_size == 1)
      {
	this->clear();
      }
    else if (m_size >= 2)
      {
	int *newContainer = new int[--m_size];
	for (int i = 0; i < m_size; i++)
	  {
	    newContainer[i] = m_container[i];
	  }
	delete[] m_container;
	m_container = newContainer;
      }
  }
  void popFront()
  {
    if (m_size == 1)
      {
	this->clear();
      }
    else if (m_size >= 2)
      {
	int *newContainer = new int[--m_size];
	for (int i = 0; i < m_size; i++)
	  {
	    newContainer[i] = m_container[i+1];
	  }
	delete[] m_container;
	m_container = newContainer;
      }
  }
  void sort()
  {
    if (m_size > 1)
      {
	for (unsigned int i = 0; i < (m_size-1); i++)
	  {
	    unsigned int indexMinElement = i;
	    int minElement = m_container[indexMinElement];
	    for (unsigned int j = (i+1); j < m_size; j++)
	      {
		if (m_container[j] < minElement)
		  {
		    indexMinElement = j;
		    minElement = m_container[indexMinElement];
		  }
	      }
	    if (m_container[i] != m_container[indexMinElement])
	      {
		m_container[indexMinElement] = m_container[i];
		m_container[i] = minElement;
	      }
	  }
      }
  }
  void print()
  {
    if (m_size == 0)
      {
	std::cout << "Container is empty." << std::endl;
      }
    else
      {
	std::cout << "Container's elements:" << std::endl;
	for (unsigned int i = 0; i < m_size; i++)
	  {
	    std::cout << i+1 << ": " << m_container[i] << std::endl;
	  }
      }
  }
  int &operator[](unsigned int index)
  {
    assert(index < m_size);
    return m_container[index];
  }
};

// TASK 2

int countUniqueElements(std::vector<int> *vect)
{
  std::vector<int> filteredVect;
  bool uniqueValue = true;
  //1 empty vect
  if (vect->size() == 0)
    {
      return 0;
    }
  //2 empty filtered vect
  filteredVect.push_back((*vect)[0]);
  //3 check other elements of vect
  for (int i = 1; i < vect->size(); i++)
    {
      for (int j = 0; j < filteredVect.size(); j++)
	{
	  if ((*vect)[i] == filteredVect[j])
	    {
	      uniqueValue = false;
	      break;
	    }
	}
      if (uniqueValue)
	{
	  filteredVect.push_back((*vect)[i]);
	}
      else
	{
	  uniqueValue = true;
	}
    }
  return filteredVect.size();
}

int main()
{
  srand(time(0));
  
  std::cout << "TASK 1" << std::endl;
  Container cnt;
  cnt.pushFront(100);
  cnt.pushFront(1);
  cnt.pushBack(5);
  cnt.pushBack(12);
  cnt.print();
  cnt.sort();
  cnt.print();
  cnt.pushBack(1);
  cnt.pushBack(-1);
  cnt.pushBack(0);
  cnt.print();
  cnt.sort();
  cnt.print();
  cnt.resize(4);
  cnt.print();
  cnt.resize(4);
  cnt.print();

  std::cout << "TASK 2" << std::endl;
  std::vector<int> v;
  std::vector<int> *p = &v;
  std::cout << "VECT:" << std::endl;
  for (int i = 0; i < 10; i++)
    {
      p->push_back(rand()%10);
      std::cout << (*p)[i] << " ";
    }
  std::cout << std::endl;
  std::cout << "VECT SIZE: " << p->size() << std::endl;
  std::cout << "FILTERED VECT SIZE: " << countUniqueElements(p) << std::endl;
  return 0;
}


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
  Container()
  {
    m_size = 0;
    m_container = new int[m_size];
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
  void resize(const int unsigned SIZE, int INDEX_OF_NEW_ELEMENT = -1)
  {
    if (SIZE == m_size)
      {
	return; //void
      }
    else if (SIZE <= 0)
      {
	this->clear();
      }
    else
      {
	int *newContainer = new int[SIZE];
	// detect: push front or back of container
	// [startIndex=0, SIZE-1) OR [startIndex=1, SIZE)
	unsigned int startIndex;
	unsigned int endIndex;
	if (INDEX_OF_NEW_ELEMENT == -1)
	  {
	    startIndex = 0;
	    endIndex = (SIZE < m_size) ? SIZE : m_size;
	  }
	else
	  {
	    startIndex = (INDEX_OF_NEW_ELEMENT == 0) ? 1 : 0;
	    endIndex = (startIndex == 0) ? (SIZE-1) : SIZE;
	  }
	for (int i = startIndex; i < endIndex; i++)
	  {
	    newContainer[i] = m_container[i-startIndex];
	  }
	delete[] m_container;
	m_container = newContainer;
	m_size = SIZE;
      }
  }
  void pushBack(const int ELEMENT)
  {
    const unsigned int INDEX_OF_NEW_ELEMENT = m_size; // last
    this->resize(m_size + 1, INDEX_OF_NEW_ELEMENT);
    m_container[INDEX_OF_NEW_ELEMENT] = ELEMENT;
  }
  void pushFront(const int ELEMENT)
  {
    const unsigned int INDEX_OF_NEW_ELEMENT = 0; // first
    this->resize(m_size + 1, INDEX_OF_NEW_ELEMENT);
    m_container[INDEX_OF_NEW_ELEMENT] = ELEMENT;
  }
  void popBack()
  {
    this->resize(m_size - 1);
  }
  /*
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
      }*/
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
  cnt.pushFront(100);  cnt.print();
  cnt.pushFront(1);  cnt.print();
  cnt.pushBack(5);  cnt.print();
  cnt.pushBack(12);
  cnt.print();
  cnt.sort();
  cnt.print();
  cnt.pushBack(1);
  cnt.pushBack(-1);
  cnt.pushBack(0);
  cnt.print();
  cnt.popBack();
  cnt.popBack();
  cnt.popBack();
  cnt.popBack();
  cnt.popBack();
  cnt.popBack();
  cnt.popBack();
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


#include <iostream>
#include <cassert>

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
  ~Container()
  {
    this->clear();
  }
  unsigned int getSize() const
  {
    return m_size;
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
  //  void resize(const unsigned int SIZE){}
  void pushBack(const int ELEMENT)
  {
    if (m_size == 0)
      {
	m_container = new int[m_size];
      }
    m_container[m_size++] = ELEMENT;
  }
  void pushFront(const int ELEMENT)
  {
    if (m_size == 0)
      {
	m_container = new int[m_size];
	m_container[m_size++] = ELEMENT;
      }
    else
      {
	
      }
  }
  //  void popBack(){}
  //  void popFront(){}
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

int main()
{
  Container cnt;
  cnt.print();
  cnt.pushBack(5);
  cnt.print();
  cnt.clear();
  cnt.clear();
  cnt.print();
  cnt.pushBack(10);
  cnt.pushBack(1);
  cnt.pushBack(5);
  cnt.print();
  return 0;
}

#include <iostream>
#include <vector>

enum Suit {CLUBS = 1,
	   DIAMONDS,
	   HEARTS,
	   SPADES};
enum Dignity {TWO = 2,
	      THREE,
	      FOUR,
	      FIVE,
	      SIX,
	      SEVEN,
	      EIGHT,
	      NINE,
	      TEN,						
	      JACK = 10,
	      QUEEN = 10,
	      KING = 10,
	      ACE = 11};

class Card
{
private:
  Suit m_suit;
  Dignity m_dignity;
  // true-visible, false-unvisible
  bool m_visibillity;
public:
  Card(Suit suit, Dignity dignity, bool visibillity):
    m_suit(suit), m_dignity(dignity), m_visibillity(visibillity)
  {
    // constr
  }
  ~Card()
  {
    // destr
  }
  void Flip()
  {
    m_visibillity = (m_visibillity) ? false : true;
  }
  int getDignity() const
  {
    return this->m_dignity;
  }
  void print()
  {
    std::cout << "CARD" << std::endl;
    std::cout << "m_suit: " << m_suit << std::endl;
    std::cout << "m_dignity: " << m_dignity << std::endl;
    std::cout << "m_visibillity: " << ((m_visibillity) ? "Visible":"Unvisible") << std::endl;
  }
};

class Hand
{
private:
  std::vector<Card> *m_hand;
public:
  Hand()
  {
    m_hand = new std::vector<Card>;
  }
  Hand(std::vector<Card> *hand): m_hand(hand)
  {
    // constr
  }
  ~Hand()
  {
    delete[] m_hand;
  }
  void add(Card *card)
  {
    m_hand->push_back(*card);
  }
  void clear()
  {
    m_hand->clear();
  }
  int getValue()
  {
    Card *card;
    int score = 0;
    // Ace quantity is necessary to recalculate score count if score is > 21,
    // then Ace dignity is 1
    int qAce = 0;
    const short ALT_ACE = 1;
    // hand is empty then score is 0
    if (m_hand->size() > 0)
      {
	// count score for each card in the hand
        for (int i = 0; i < m_hand->size(); i++)
	  {
	    score += (m_hand->begin()+i)->getDignity();
	  }
      }
    // check score count
    if (score > 21)
      {
	// count ace quantity
	for (int i = 0; i < m_hand->size(); i++)
	  {
	    if ((m_hand->begin()+i)->getDignity() == ACE)
	      {
		qAce++;
	      }
	  }
      }
    return score - qAce*ACE + qAce*ALT_ACE;
  }
};

int main()
{   
  Hand *hand = new Hand();
  std::cout << hand->getValue() << std::endl;
  hand->add(new Card(DIAMONDS, ACE, true));
  hand->add(new Card(DIAMONDS, THREE, true));
  hand->add(new Card(DIAMONDS, FIVE, true));
  hand->add(new Card(DIAMONDS, TWO, true));
  std::cout << hand->getValue() << std::endl;
  return 0;
}


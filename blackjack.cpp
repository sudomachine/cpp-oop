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
  // true-visible, false-invisible
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
    //m_visibillity = (m_visibillity) ? false : true; // my variant
    m_visibillity = !(m_visibillity); // teacher variant
  }
  int getDignity() const
  {
    // dignity of invisible card get zero points
    if (m_visibillity)
      {
	return m_dignity;
      }
    else
      {
	return 0;
      }
  }
  void print()
  {
    std::cout << "CARD" << std::endl;
    std::cout << "m_suit: " << m_suit << std::endl;
    std::cout << "m_dignity: " << m_dignity << std::endl;
    std::cout << "m_visibillity: " << ((m_visibillity) ? "Visible":"Invisible") << std::endl;
  }
};

class Hand
{
private:
  std::vector<Card*> m_hand;
public:
  Hand()
  {
    m_hand.reserve(0);
  }
  ~Hand()
  {
    this->clear();
  }
  void add(Card *card)
  {
    m_hand.push_back(card);
  }
  void clear()
  {
    // delete all cards in the hand by pointers
    for (int i = 0; i < m_hand.size(); i++)
      {
	delete m_hand[i];
      }
    // delete card collection (hand)
    m_hand.clear();
  }
  int getValue()
  { 
    int score = 0;
    // presence of an ace is necessary to recalculate score count if score is > 21,
    // then Ace dignity is 1
    int aceInHand = false;
    const short ALT_ACE = 1;
    // if there are no cards in the hand then nothing to count 
    if (m_hand.size() > 0)
      {
	// count score for each card in the hand
        for (int i = 0; i < m_hand.size(); i++)
	  {
	    score += m_hand[i]->getDignity();
	  }
      }
    // check score count to recalculate the ace dignity
    if (score > 21)
      {
	// swap ace dignity (only of one card) from 11 to 1
	for (int i = 0; i < m_hand.size(); i++)
	  {
	    if (m_hand[i]->getDignity() == ACE)
	      {
		aceInHand = true;
	      }
	  }
      }
    return score - aceInHand*ACE + aceInHand*ALT_ACE;
  }
};

int main()
{   
  Hand hand;
  std::cout << hand.getValue() << std::endl;
  hand.add(new Card(DIAMONDS, ACE, false));
  hand.add(new Card(DIAMONDS, THREE, false));
  hand.add(new Card(DIAMONDS, FIVE, false));
  hand.add(new Card(DIAMONDS, TWO, false));
  hand.add(new Card(DIAMONDS, ACE, false));
  std::cout << hand.getValue() << std::endl;
  return 0;
}


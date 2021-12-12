
enum Suit {CLUBS = 1, DIAMONDS, HEARTS, SPADES};
enum Dignity {1 = 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

class Card
{
private:
  Suit m_suit;
  Dignity m_dignity;
  bool m_visibillity;
public:
  Card(int suit, int dignity, bool visibillity):
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
  int getDignity(Card *card) const
  {
    return card->m_dignity;
  }
};

int main()
{
  return 0;
}


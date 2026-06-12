#ifndef DECK_H_
#define DECK_H_

#include <vector>

#include "Card.h"
#include "Player.h"

// Класс колоды: создаёт, перемешивает и раздаёт карты.
class Deck {
 public:
  Deck();

  void Create();
  void Shuffle();
  void Deal(Player* player1, Player* player2) const;

 private:
  std::vector<Card> cards_;
};

#endif  // DECK_H_

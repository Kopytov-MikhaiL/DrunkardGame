#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>

#include "Card.h"

// Класс игрока: хранит карты и операции с ними.
class Player {
 public:
  Player();

  void ClearCards();
  void AddCard(const Card& card);
  Card TakeTopCard();
  bool HasCards() const;
  int GetCardCount() const;

 private:
  std::vector<Card> cards_;
};

#endif  // PLAYER_H_

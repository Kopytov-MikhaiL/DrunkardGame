#ifndef CARD_H_
#define CARD_H_

#include <string>

// Класс хранит одну карту и переводит её значение в строку.
class Card {
 public:
  Card();
  explicit Card(int rank);

  int GetRank() const;
  std::string ToString() const;

 private:
  int rank_;
};

#endif  // CARD_H_

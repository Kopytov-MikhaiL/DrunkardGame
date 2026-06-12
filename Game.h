#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Player.h"

// Класс игры "Пьяница": запускает раунды, спор и лог игры.
class Game {
 public:
  Game();

  void Start();

 private:
  Deck deck_;
  Player player1_;
  Player player2_;
  std::vector<std::string> log_;

  int CompareCards(const Card& card1, const Card& card2) const;
  void AddLog(int round, const Card& card1, const Card& card2, int winner);
  void PrintWinner() const;
  void PrintLog() const;
  void ProcessRound(int round);
  void ProcessAfterGameMenu() const;
};

#endif  // GAME_H_

#include "Deck.h"

#include <algorithm>
#include <ctime>
#include <cstdlib>

Deck::Deck() {}

void Deck::Create() {
  cards_.clear();

  for (int rank = 6; rank <= 14; ++rank) {
    for (int suit = 0; suit < 4; ++suit) {
      cards_.push_back(Card(rank));
    }
  }
}

void Deck::Shuffle() {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  for (int i = 0; i < static_cast<int>(cards_.size()); ++i) {
    int random_index = std::rand() % cards_.size();
    std::swap(cards_[i], cards_[random_index]);
  }
}

void Deck::Deal(Player* player1, Player* player2) const {
  player1->ClearCards();
  player2->ClearCards();

  for (int i = 0; i < static_cast<int>(cards_.size()); ++i) {
    if (i % 2 == 0) {
      player1->AddCard(cards_[i]);
    } else {
      player2->AddCard(cards_[i]);
    }
  }
}

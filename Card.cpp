#include "Card.h"

Card::Card() : rank_(6) {}

Card::Card(int rank) : rank_(rank) {}

int Card::GetRank() const {
  return rank_;
}

std::string Card::ToString() const {
  if (rank_ <= 10) {
    return std::to_string(rank_);
  }
  if (rank_ == 11) {
    return "J";
  }
  if (rank_ == 12) {
    return "Q";
  }
  if (rank_ == 13) {
    return "K";
  }
  return "A";
}

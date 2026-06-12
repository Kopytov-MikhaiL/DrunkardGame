#include "Player.h"

Player::Player() {}

void Player::ClearCards() {
  cards_.clear();
}

void Player::AddCard(const Card& card) {
  cards_.push_back(card);
}

Card Player::TakeTopCard() {
  Card top_card = cards_.front();
  cards_.erase(cards_.begin());
  return top_card;
}

bool Player::HasCards() const {
  return !cards_.empty();
}

int Player::GetCardCount() const {
  return static_cast<int>(cards_.size());
}

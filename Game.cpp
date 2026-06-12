#include "Game.h"

#include <iostream>
#include <limits>
#include <vector>

Game::Game() {}

void Game::Start() {
  log_.clear();
  deck_.Create();
  deck_.Shuffle();
  deck_.Deal(&player1_, &player2_);

  std::cout << "\nИГРА НАЧАЛАСЬ\n";
  std::cout << "Нажмите Enter, чтобы продолжить.";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  int round = 1;
  while (player1_.HasCards() && player2_.HasCards() && round <= 1000000) {
    ProcessRound(round);
    ++round;
  }

  if (round > 1000000){
    std::cout << "\n===== botva =====\n";
    ProcessAfterGameMenu();
  }

  std::cout << "\n===== ИГРА ОКОНЧЕНА =====\n";
  PrintWinner();
  ProcessAfterGameMenu();
}

int Game::CompareCards(const Card& card1, const Card& card2) const {
  if (card1.GetRank() > card2.GetRank()) {
    return 1;
  }
  if (card2.GetRank() > card1.GetRank()) {
    return 2;
  }
  return 0;
}

void Game::AddLog(int round, const Card& card1, const Card& card2, int winner) {
  std::string entry = "Раунд " + std::to_string(round) + ": " +
                      card1.ToString() + " vs " + card2.ToString();

  if (winner == 1) {
    entry += " -> Победил Игрок 1";
  } else if (winner == 2) {
    entry += " -> Победил Игрок 2";
  } else {
    entry += " -> Ничья";
  }

  log_.push_back(entry);
}

void Game::PrintWinner() const {
  if (player1_.GetCardCount() > player2_.GetCardCount()) {
    std::cout << "ПОБЕДИЛ ИГРОК 1\n";
  } else if (player2_.GetCardCount() > player1_.GetCardCount()) {
    std::cout << "ПОБЕДИЛ ИГРОК 2\n";
  } else {
    std::cout << "НИЧЬЯ\n";
  }
}

void Game::PrintLog() const {
  std::cout << "\nЛОГ ХОДОВ:\n";
  for (const std::string& line : log_) {
    std::cout << line << '\n';
  }
}

void Game::ProcessRound(int round) {
  std::vector<Card> table;

  std::cout << "\n--------------------------------\n";
  std::cout << "Раунд " << round << '\n';
  std::cout << "Карты у Игрока 1: [" << player1_.GetCardCount() << "]\n";
  std::cout << "Карты у Игрока 2: [" << player2_.GetCardCount() << "]\n";
  std::cout << "Нажмите Enter, чтобы открыть карты.";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  Card card1 = player1_.TakeTopCard();
  Card card2 = player2_.TakeTopCard();
  table.push_back(card1);
  table.push_back(card2);

  std::cout << "Игрок 1 открыл: " << card1.ToString() << '\n';
  std::cout << "Игрок 2 открыл: " << card2.ToString() << '\n';

  while (card1.GetRank() == card2.GetRank() && player1_.HasCards() &&
         player2_.HasCards()) {
    std::cout << "СПОР! Карты равны.\n";
    std::cout << "Каждый кладет карту рубашкой вниз.\n";

    table.push_back(player1_.TakeTopCard());
    table.push_back(player2_.TakeTopCard());

    if (!player1_.HasCards() || !player2_.HasCards()) {
      if (!player1_.HasCards()) {
        std::cout << "У первого игрока закончились карты во время спора.\n";
      } else {
        std::cout << "У второго игрока закончились карты во время спора.\n";
      }
      break;
    }

    std::cout << "Нажмите Enter, чтобы открыть дополнительные карты.";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    card1 = player1_.TakeTopCard();
    card2 = player2_.TakeTopCard();
    table.push_back(card1);
    table.push_back(card2);

    std::cout << "Дополнительно:\n";
    std::cout << "Игрок 1: " << card1.ToString() << '\n';
    std::cout << "Игрок 2: " << card2.ToString() << '\n';
  }

  int winner = CompareCards(card1, card2);
  if (winner == 1) {
    std::cout << "Победил Игрок 1 в этом раунде!\n";
    for (const Card& card : table) {
      player1_.AddCard(card);
    }
  } else if (winner == 2) {
    std::cout << "Победил Игрок 2 в этом раунде!\n";
    for (const Card& card : table) {
      player2_.AddCard(card);
    }
  }

  AddLog(round, card1, card2, winner);
}

void Game::ProcessAfterGameMenu() const {
  while (true) {
    std::cout << "\nЧто хотите сделать дальше?\n";
    std::cout << "1 - Вернуться в меню\n";
    std::cout << "2 - Показать лог боев\n";
    std::cout << "Выберите 1 или 2: ";

    int choice;
    if (!(std::cin >> choice)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Неверный ввод. Введите число 1 или 2.\n";
      continue;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 1) {
      break;
    }
    if (choice == 2) {
      PrintLog();
      std::cout << "\nНажмите Enter.";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }

    std::cout << "Неверный ввод. Введите 1 или 2.\n";
  }
}

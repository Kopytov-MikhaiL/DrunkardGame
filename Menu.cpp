#include "Menu.h"

#include <iostream>
#include <limits>

Menu::Menu() {}

void Menu::ShowMainMenu() const {
  std::cout << "\nСИМУЛЯТОР КАРТОЧНОЙ ИГРЫ \"ПЬЯНИЦА\"\n";
  std::cout << "\n1. Начать игру\n";
  std::cout << "2. Правила\n";
  std::cout << "3. Выход\n";
  std::cout << "Выбор: ";
}

int Menu::GetMenuChoice() const {
  int choice;

  while (!(std::cin >> choice) || choice < 1 || choice > 3) {
    std::cout << "Ошибка. Введите 1-3: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return choice;
}

void Menu::ShowRules() const {
  std::cout << "\nПРАВИЛА ИГРЫ \"ПЬЯНИЦА\"\n\n";
  std::cout << "1. Играют два игрока.\n";
  std::cout << "2. Используется колода из 36 карт.\n";
  std::cout << "3. Каждый раунд игроки открывают верхнюю карту.\n";
  std::cout << "4. Старшая карта забирает все карты раунда.\n";
  std::cout << "5. При равенстве начинается спор.\n";
  std::cout << "6. Игра идет до победы одного игрока или до 1000000 раундов.\n";
  std::cout << "7. В конце можно посмотреть лог ходов.\n\n";
  std::cout << "Нажмите Enter для возврата в меню.";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

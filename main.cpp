#include <iostream>

#ifdef _WIN64
#include <windows.h>
#endif

#include "Game.h"
#include "Menu.h"

int main() {
#ifdef _WIN64
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
#endif

  Menu menu;

  while (true) {
    menu.ShowMainMenu();
    int choice = menu.GetMenuChoice();

    if (choice == 1) {
      Game game;
      game.Start();
    } else if (choice == 2) {
      menu.ShowRules();
    } else {
      std::cout << "Программа завершена.\n";
      break;
    }
  }

  return 0;
}

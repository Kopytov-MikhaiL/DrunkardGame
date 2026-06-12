#ifndef MENU_H_
#define MENU_H_

// Класс меню: выводит пункты и проверяет ввод пользователя.
class Menu {
 public:
  Menu();

  void ShowMainMenu() const;
  void ShowRules() const;
  int GetMenuChoice() const;
};

#endif  // MENU_H_

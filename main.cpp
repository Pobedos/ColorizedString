#include <iostream>
#include <string>
#include "colorized-string.hpp"

int main()
{
  std::string a;
  using namespace Colorized;
  ColorizedString string("new string", ColorizedString::Foreground::DEFAULT,
    ColorizedString::Background::DEFAULT, ColorizedString::Emphasis::ITALIC);
  std::cout << string.format() << '\n';
  string.set(ColorizedString::Foreground::BLUE, ColorizedString::Background::BLACK, ColorizedString::Emphasis::FAINT);
  std::cout << string.format() << '\n';
  string.set(ColorizedString::Foreground::BLUE, ColorizedString::Background::BLACK, ColorizedString::Emphasis::BOLD);
  std::cout << string.format() << '\n';
  string.set(ColorizedString::Foreground::BLUE, ColorizedString::Background::BLACK, ColorizedString::Emphasis::REGULAR);
  std::cout << string.format() << '\n';
  string.set(ColorizedString::Foreground::BLUE, ColorizedString::Background::BLACK, ColorizedString::Emphasis::SLOW_BLINK);
  std::cout << string.format() << '\n';
  string.set(ColorizedString::Foreground::BLUE, ColorizedString::Background::BLACK, ColorizedString::Emphasis::RAPID_BLINK);
  std::cout << string.format() << '\n';
  return 0;
}

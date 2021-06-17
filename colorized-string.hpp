#ifndef UNTITLED1_COLORIZED_STRING_HPP
#define UNTITLED1_COLORIZED_STRING_HPP

#include <string>

namespace Colorized {
  class ColorizedString {
  public:
    enum class Foreground {
      BLACK = 30,
      RED,
      GREEN,
      YELLOW,
      BLUE,
      MAGENTA,
      CYAN,
      WHITE,
      DEFAULT
    };
    enum class Background {
      BLACK = 40,
      RED,
      GREEN,
      YELLOW,
      BLUE,
      MAGENTA,
      CYAN,
      WHITE,
      DEFAULT
    };
    enum class Emphasis {
      REGULAR,
      BOLD,
      FAINT,
      ITALIC,
      UNDERLINE,
      SLOW_BLINK,
      RAPID_BLINK
    };

    ColorizedString(const std::string &rawString, Foreground foreground = Foreground::DEFAULT,
      Background background = Background::DEFAULT, Emphasis emphasis = Emphasis::REGULAR);
    ColorizedString(std::string &&rawString, Foreground foreground = Foreground::DEFAULT,
      Background background = Background::DEFAULT, Emphasis emphasis = Emphasis::REGULAR);

    std::string format();
    void set(Foreground foreground);
    void set(Background background);
    void set(Emphasis emphasis);

    void set(Foreground foreground, Background background, Emphasis emphasis);
    void setStr(const std::string &str);
    void setStr(std::string &&str);
  private:
    std::string rawString_;
    Foreground foreground_;
    Background background_;
    Emphasis emphasis_;
    const std::string PREFIX = "\033[";
    const std::string POSTFIX = "\033[0m";
  };
}

#endif

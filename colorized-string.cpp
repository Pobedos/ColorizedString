#include "colorized-string.hpp"

Colorized::ColorizedString::ColorizedString(const std::string &rawString, Foreground foreground, Background background,
  Emphasis emphasis):
  rawString_(rawString),
  foreground_(foreground),
  background_(background),
  emphasis_(emphasis)
{}

Colorized::ColorizedString::ColorizedString(std::string &&rawString, Foreground foreground, Background background,
  Emphasis emphasis):
  rawString_(std::move(rawString)),
  foreground_(foreground),
  background_(background),
  emphasis_(emphasis)
{}

std::string Colorized::ColorizedString::format()
{
  return PREFIX + std::to_string(static_cast<int>(emphasis_)) + ';' + std::to_string(static_cast<int>(background_))
         + ';' + std::to_string(static_cast<int>(foreground_)) + 'm' + rawString_ + POSTFIX;
}

void Colorized::ColorizedString::set(ColorizedString::Foreground foreground)
{
  foreground_ = foreground;
}

void Colorized::ColorizedString::set(Colorized::ColorizedString::Background background)
{
  background_ = background;
}

void Colorized::ColorizedString::set(Colorized::ColorizedString::Emphasis emphasis)
{
  emphasis_ = emphasis;
}

void Colorized::ColorizedString::set(Colorized::ColorizedString::Foreground foreground,
  Colorized::ColorizedString::Background background, Colorized::ColorizedString::Emphasis emphasis)
{
  foreground_ = foreground;
  background_ = background;
  emphasis_ = emphasis;
}

void Colorized::ColorizedString::setStr(const std::string &str)
{
  rawString_ = str;
}

void Colorized::ColorizedString::setStr(std::string &&str)
{
  rawString_ = std::move(str);
}

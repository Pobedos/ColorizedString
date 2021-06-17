#define BOOST_TEST_MODULE colorized

#include <boost/test/included/unit_test.hpp>
#include "colorized-string.hpp"

BOOST_AUTO_TEST_CASE(nothing)
{
  Colorized::ColorizedString("new");
  BOOST_CHECK_EQUAL(1, 1);
}
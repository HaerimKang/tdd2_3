#include "pch.h"
#include "../TDD2_3/baseball.cpp"

#include <string>
using namespace std;

class BaseballFixture : public testing::Test
{
public:
	Baseball game;
	void assertIllegalArgument(string guessNumber)
	{
		try
		{
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception  e)
		{
			//PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
}
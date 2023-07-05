#include "pch.h"
#include "../TDD2_3/baseball.cpp"

#include <string>
using namespace std;

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmached) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}
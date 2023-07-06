#include <string>
#include <stdexcept>

using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	explicit Baseball(const string& question)
		:question(question)
	{
		
	}
	bool isDuplicatedNumber(const string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3)
		{
			throw length_error("Must be three letters.");
		}

		for(char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9')
				continue;
			throw length_error("Must be number.");
		}
		if(isDuplicatedNumber(guessNumber))
		{
			throw length_error("Must not have the same number.");
		}
	}

	int checkStrike(const string& guessNumber)
	{
		int result = 0;
		const int QUESTION_LENGTH = 3;
		for(int i=0; i<QUESTION_LENGTH; ++i)
		{
			if (guessNumber[i] == question[i])
				++result;
		}
		return result;
	}

	GuessResult guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
		if(guessNumber == question)
		{
			return { true, 3, 0 };
		}

		GuessResult result{ false, 0,0 };
		result.strikes = checkStrike(guessNumber);
		return result;
	}

private:
	string question;
};

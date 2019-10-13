#include <iostream>
#include <random>
#include <ctime>

char* generate_3_digit()
{
	std::random_device rand;
	bool exist;
	int number[3] = { -1, -1, -1 };
	int temp;
	for (int i = 0; i < 3;)
	{
		exist = false;
		temp = rand() % 10;
		for (int j = 0; j <= i; ++j)
		{
			if (number[j] == temp)
				exist = true;
		}

		if (!exist)
		{
			number[i] = temp;
			i++;
		}
	}
	char* answer = new char[3];
	for (int i = 0; i < 3; ++i)
		answer[i] = number[i] + '0';

	return answer;
}

int main()
{
	char guess[3];
	int trials = 0;

	char* answer = generate_3_digit();
	
	for (int i = 0; i < 3; ++i)
		std::cout << answer[i] << " ";

	int strike = 0, ball = 0, out = 0;
	while(strike != 3)
	{
		trials++;

		strike = 0;
		ball = 0;
		out = 0;

		std::cout << "Guess three number: (ex. 1 2 3)" << std::endl;
		std::cin >> guess[0] >> guess[1] >> guess[2];
		
		for (int i = 0; i < 3; ++i)
		{
			if (guess[i] == answer[i])
				strike++;
			else
			{
				bool exist = false;
				for (int j = 0; j < 3; ++j)
				{
					if (guess[i] == answer[j])
					{
						exist = true;
						break;
					}
				}
				if (exist)
					ball++;
				else
					out++;
			}
		}

	
		std::cout << "S:" << strike << " B:" << ball << " O:"<< out << std::endl;
	}
	
	std::cout << "You have found the right number with " << trials << " trials" << std::endl;

	delete[] answer;
	return 0;
}
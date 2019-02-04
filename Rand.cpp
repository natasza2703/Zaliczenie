#include "Rand.h"
void Rand()
{
	ofstream save("save.txt");
	int randx, randy, result, i, j = 0;
	while (j < 11)
	{
		i = 0;
		while (i < 3)
		{
			randx = (rand() % 10) + 0;
			randy = (rand() % 10) + 0;
			result = randx + randy;
			if (result >= 0 && result < 10)
			{
				save << randx << " + " << randy << " = " << result << endl;
				i++;
			}
		}
		i = 0;
		while (i < 3)
		{
			randx = (rand() % 10) + 0;
			randy = (rand() % 10) + 0;
			result = randx - randy;
			if (result >= 0 && result < 10)
			{
				save << randx << " - " << randy << " = " << result << endl;
				i++;
			}
		}
		i = 0;
		while (i < 3)
		{
			randx = (rand() % 10) + 0;
			randy = (rand() % 10) + 0;
			result = randx * randy;
			if (result >= 0 && result < 10)
			{
				save << randx << " * " << randy << " = " << result << endl;
				i++;
			}
		}
		j++;
	}
	randx = (rand() % 10) + 0;
	randy = (rand() % 10) + 0;
	result = randx * randy;
	if (result >= 0 && result < 10)
	{
		save << randx << " * " << randy << " = " << result;
		i++;
	}
}
#include <iostream>
#include <vector>

int main()
{
	int t;
	std::cin >> t;
	while (t--)
	{
		std::vector<std::vector<int>> vect(3, std::vector<int>(3));
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				std::cin >> vect[i][j];
			}
		}
		std::vector<std::vector<int>> compV(3, std::vector<int>(3));
		for (int i = 0; i < 3; i++)
		{
			compV[0][i] = vect[0][i] - vect[1][i];
			compV[1][i] = vect[0][i] - vect[2][i];
			compV[2][i] = vect[1][i] - vect[2][i];
		}
		bool isCorr = true;
		
		for (int i = 0; i < 3; i++)
		{
			int pC(0), nC(0), zC(0);
			for (int j = 0; j < 3; j++)
			{
				if (compV[i][j] < 0)
					nC++;
				if (compV[i][j] > 0)
					pC++;
				if (compV[i][j] == 0)
					zC++;
			}
			if ( (pC > 0 && nC > 0) || zC == 3)
			{
				isCorr = false;
				break;
			}
		}
		if (isCorr)
			std::cout << "yes" << std::endl;
		else
			std::cout << "no" << std::endl;
	}
	return 0;
}
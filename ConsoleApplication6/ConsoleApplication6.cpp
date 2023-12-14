#include <iostream>
#include <algorithm>
using namespace std;
bool eleminatedCheck[4] = { false,false,false,false };
int eliminateCandidates(int list[4][5]) {
	int sumlist[5];

	for (int i = 0; i < 4; i++)
	{
		if (!eleminatedCheck[i]) {
			int sum = 0;
			for (int j = 0; j < 5; j++)
			{
				sum += list[i][j];

			}
			sumlist[i] = sum;
		}
		else {
			sumlist[i] = -1;
		}


	}
	int eliminatedIndex = -1;
	int eliminatedScore = -1;

	for (int x = 0; x < 4; x++)
	{
		if (!eleminatedCheck[x]) {
			eliminatedIndex = x;
			eliminatedScore = sumlist[x];
			break;
		}


	}
	for (int i = 0; i < 4; i++) {
		if (!eleminatedCheck[i] && (eliminatedScore == -1 || sumlist[i] < eliminatedScore)) {
			eliminatedIndex = i;
			eliminatedScore = sumlist[i];
		}
	}
	eleminatedCheck[eliminatedIndex] = true;

	cout << "candidate " << (eliminatedIndex + 1) << " is eliminated" << endl;
	return eliminatedIndex;
}

int main() {
	int list[4][5];


	for (int i = 0; i < 4; i++) {
		std::cout << "Enter scores for candidates " << i + 1 << " (5 scores): ";
		for (int j = 0; j < 5; j++) {
			std::cin >> list[i][j];
		}
	}

	int c1 = eliminateCandidates(list);
	int c2 = eliminateCandidates(list);
	int c3 = eliminateCandidates(list);

	return 0;
}
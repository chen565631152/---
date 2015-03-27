#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	int m = 0, n = 0;
	char answer;
	cout << "需要玩游戏吗？（Y/N）";      //ask the user
	cin >> answer;
	while (answer == 'Y')          //when the user wants to play   
	{
		int key[3], i;
		srand(time(NULL));
		do
		{
			for (i = 0; i<3; ++i)                      //create three random numbers
			{
				key[i] = rand() % 10;
			}
		} while (!(key[0] != key[1] && key[1] != key[2] && key[0] != key[2]));      //assure that three numbers produced are different 
		int y = 0, j, k, a = 0, b = 0;
		while (y<7)
		{
			int guess[3];                      //collect the numbers that the user puts in 
			cout << "请输入你猜测的数字：" << endl;
			cin >> guess[0] >> guess[1] >> guess[2];
			for (j = 0; j<3; ++j)
			{
				for (k = 0; k<3; ++k)
				{
					if (guess[j] == key[k] && j == k) ++a;    //if both the numbers and the locations are the same
					if (guess[j] == key[k] && j != k) ++b;     //if only the numbers are right but the locations are different
				}
			}
			if (a == 3)
			{
				++m;
				cout << "恭喜，你猜对了" << endl;         //get the right answer and begin a new round
				break;
			}
			cout << a << "A" << b << "B" << endl;   //put out the clue
			++y;
			a = 0, b = 0;
		}
		if (y == 7) cout << "很遗憾，你没有在规定次数内猜对。答案是" << key[0] << key[1] << key[2] << endl;  //the user loses in this round
		++n;
		cout << "需要玩游戏吗？（Y/N）";
		cin >> answer;
	}
	cout << "你一共玩了" << n << "局，赢了" << m << "局，输了" << n - m << "局。";    //put out the total amount of the rounds the uesr plays
	return 0;
}
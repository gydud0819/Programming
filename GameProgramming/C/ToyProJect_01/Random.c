#include "Random.h"

// 1 ~ 100까지 숫자 랜덤 반환
int ReturnRandomValue()
{
	srand((unsigned int) time(NULL) * 1000 + clock());	// 시간

	// reversePercent

	//int randomValue = (rand() % 100) + 1;	// return에 대입해서 반환한 거랑 같다.
	return (rand() % 100) + 1;
}

bool CheckRandomFunc(int Percent)
{
	int randValue = ReturnRandomValue();		// 1 ~ 100 랜덤으로 반환

	int SuccessPercent = Percent;				// 성공확률

	if (randValue <= Percent)
	{
		printf("성공하였습니다! %d\n", randValue);		
		return true;		 
	}						 
	else					 
	{						 
		printf("실패하였습니다ㅠㅠ %d\n", randValue);
		return false;
	}

}

//int ReturnRandomInRange(int min, int max)
//{
//	srand((unsigned int) (time(NULL) * 1000 + clock()));
//
//	return (rand() % (max - min + 1)) + min;		
//}

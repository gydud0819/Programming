#include "Random.h"

void CreateRandomSeed()
{
	srand(time(NULL) * 1000 + clock());		// 지금 시작한 시간을 더해주는 코드
}

int ReturnPosX()
{
	 
	// 0 ~ 40 
	// 랜덤값 + 짝수를 반환해야 한다.
	
	// 1. 랜덤한 숫자를 뽑는다. - rand 함수를 사용해서 A ~ B 범위
	// 2. 1 ~20 *2 (짝수)
	// 둘다 사용해도 되고 둘 중 구현하기 쉬운 걸로 구현한다.
	// 두 코드중에 더 효율적인 코드를 사용한다. (보기에 좋거나, 메모리 최적화에 좋은 것)

	int randValue = rand() % 36 + 1;	// 1~40까지 출력한다.
	return randValue % 2 == 0 ? randValue : randValue + 1;
}

int ReturnPosY()
{
	int randvalue = rand() % 18 + 1;
	return randvalue;
}

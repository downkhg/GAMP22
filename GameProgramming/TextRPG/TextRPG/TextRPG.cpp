#include "GameManager.h"

void main()
{
	GameManager cGameManager;
	cGameManager.Init();

	while (cGameManager.GetPlace() != GameManager::E_PLACE::EXIT)
	{
		cGameManager.Updata();
	}
}

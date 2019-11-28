#include "pch.h"

using namespace sf;

int main()
{
	GameManager::GetInstance()->Init();

	GameManager::GetInstance()->StartLoop();

	delete GameManager::GetInstance();
}
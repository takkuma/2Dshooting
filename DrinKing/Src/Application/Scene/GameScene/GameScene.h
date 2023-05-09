#pragma once
#include "../BaseScene.h"

class GameScene:public BaseScene
{
public:
	GameScene(){};
	~GameScene(){};

	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;
private:
	static const int Tea_Num = 3;
	static const int Beer_Num = 2;

	int m_life;
};
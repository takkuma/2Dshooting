#pragma once
#include"../../BaseBullet.h"

class Player_Bullet:public BaseBullet
{
public:
	Player_Bullet(){};
	~Player_Bullet() { Release(); };

	void Update()override;
	void Init()override;
	void Release()override;
private:
};
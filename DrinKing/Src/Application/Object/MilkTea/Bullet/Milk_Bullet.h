#pragma once
#include "../../BaseBullet.h"

class Milk_Bullet : public BaseBullet
{
public:
	Milk_Bullet() {};
	~Milk_Bullet() { Release(); };

	void Update()override;
	void Init()override;
	void Release()override;
private:
	static const int BulletNum = 5;
};
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

	void Shot(Math::Vector3 a_pos)override;
	float GetAngleDeg(Math::Vector3 a_pos, Math::Vector3 a_Ppos);
private:
	static const int BulletNum = 5;
};
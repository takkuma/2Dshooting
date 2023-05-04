#pragma once
#include "../../BaseBullet.h"

class Water_Bullet : public BaseBullet
{
public:
	Water_Bullet() {};
	~Water_Bullet() { Release(); };

	void Update()override;
	void Init()override;
	void Release()override;

private:
};
#pragma once
#include "../../BaseBullet.h"

class Cola_Bullet :public BaseBullet
{
public:
	Cola_Bullet() {}
	~Cola_Bullet() { Release(); }

	void Update()override;
	void Init()override;
	void Release()override;
private:
};
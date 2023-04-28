#pragma once
#include "../../BaseBullet.h"

class Sport_Bullet :public BaseBullet
{
public:
	Sport_Bullet() {}
	~Sport_Bullet() { Release(); }

	void Update()override;
	void Init()override;
	void Release()override;
private:

};

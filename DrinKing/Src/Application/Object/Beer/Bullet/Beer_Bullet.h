#pragma once
#include"../../BaseBullet.h"

class Beer_Bullet :public BaseBullet
{
public:
	Beer_Bullet() {};
	~Beer_Bullet() { Release(); };

	void Update()override;
	void Init()override;
	void Release()override;
private:
};
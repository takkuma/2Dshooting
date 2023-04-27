#pragma once
#include"../../BaseBullet.h"

class Tea_Bullet :public BaseBullet
{
public:
	Tea_Bullet() {};
	~Tea_Bullet() { Release(); };

	void Update()override;
	void Init()override;
	void Release()override;
private:
};
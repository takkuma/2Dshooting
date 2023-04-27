#pragma once
#include "../BasePlayer.h"

class Water_Bullet;

class Water :public BasePlayer
{
public:
	Water() {};
	~Water() { Release(); }

	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;
private:
	static const int BulletNum = 10;
	std::vector<std::shared_ptr<Water_Bullet>> m_objList;
};
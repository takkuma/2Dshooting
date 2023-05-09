#pragma once
#include "../BasePlayer.h"

class Cola_Bullet;

class Cola :public BasePlayer
{
public:
	Cola() {};
	~Cola() { Release(); }

	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;

private:
	static const int CoolTime = 90;
	static const int BulletNum = 10;
	std::vector<std::shared_ptr<Cola_Bullet>> m_objList;
};

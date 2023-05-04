#pragma once
#include "../BasePlayer.h"

class Sport_Bullet;

class Sport :public BasePlayer
{
public:
	Sport() {};
	~Sport() { Release(); }

	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;
private:
	
	std::vector<std::shared_ptr<Sport_Bullet>> m_objList;
	static const int BulletNum = 30;
};
#pragma once
#include"../BaseObject.h"

class Beer_Bullet;
class Player;

class Beer:public BaseObject
{
public:
	Beer(){};
	~Beer() { Release(); };

	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;
	void Pop()override;
	void OnHit()override;
	void OnHitBullet()override;
private:
	float m_deg;

	//•Ûç«E‰Â“Ç«E”Ä—p«
	std::vector<std::shared_ptr<Beer_Bullet>>m_objList;

	static const int BulletNum = 10;
	static const int MaxCoolTime = 90;
};
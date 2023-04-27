#pragma once
#include"../BaseObject.h"

class Beer_Bullet;

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

private:
	float m_deg;

	//•Ûç«E‰Â“Ç«E”Ä—p«
	std::vector<std::shared_ptr<Beer_Bullet>>m_objList;
};
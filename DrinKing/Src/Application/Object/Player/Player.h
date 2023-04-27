#pragma once
#include"../BaseObject.h"
//�q�N���X

class Player_Bullet;
class KeyBord;

enum Drink
{
	water,
	cola,
	sport
};

class Player:public BaseObject
{
public:
	Player(){};
	~Player() { Release(); };
	//���W���[�֐�
	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;
private:
	//�ړ���
	static const int Move_val = 5;
	Math::Rectangle rc = { 0,0,64,64 };
	//���[�h�`�F���W�֌W
	KdTexture colaTex;
	KdTexture sportTex;
	Drink drink;
	
	static const int BulletNum = 10;
	std::vector<std::shared_ptr<Player_Bullet>>m_objList;
};
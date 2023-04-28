#pragma once
#include"../BaseObject.h"
//子クラス

class BasePlayer;


enum Drink
{
	m_water,
	m_cola,
	m_sport
};

class Player:public BaseObject
{
public:
	Player(){};
	~Player() { Release(); };
	//メジャー関数
	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;
private:
	Math::Rectangle rc = { 0,0,64,64 };
	//モードチェンジ関係
	Drink drink;

	std::vector<std::shared_ptr<BasePlayer>>m_objList;
};
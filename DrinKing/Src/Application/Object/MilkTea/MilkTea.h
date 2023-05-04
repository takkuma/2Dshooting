#pragma once
#include"../BaseObject.h"

class Milk_Bullet;

class Milk :public BaseObject
{
public:
	//コンストラクタ…インスタンス化したときに最初に１度だけ実行される関数
	Milk() {};
	//デストラクタ…
	~Milk() { Release(); };
	//メジャー関数
	//オーバーライド…親クラスの関数を上書き
	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;
	void Pop()override;
	void OnHit()override;
	void OnHitBullet()override;
private:
	//保守性・可読性・汎用性
	std::vector<std::shared_ptr<Milk_Bullet>>m_objList;

	static const int BulletNum = 5;

	static const int MaxCoolTime = 120;
};
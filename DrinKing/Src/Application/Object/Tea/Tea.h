#pragma once
//絶対に書く
//多重読み込み抑制コマンド
#include"../BaseObject.h"

class Tea_Bullet;

class Tea:public BaseObject
{
public:
	//コンストラクタ…インスタンス化したときに最初に１度だけ実行される関数
	Tea(){};
	//デストラクタ…
	~Tea() { Release(); };
	//メジャー関数
	//オーバーライド…親クラスの関数を上書き
	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;
	void Pop()override;

private:
	//保守性・可読性・汎用性
	std::vector<std::shared_ptr<Tea_Bullet>>m_objList;
};
#pragma once
//親クラス(基底クラス)

class BasePlayer
{
public:
	BasePlayer() {};
	~BasePlayer() {};

	//仮想関数
	virtual void Update() = 0;
	virtual void Draw();
	virtual void Init() = 0;
	virtual void Release();

protected:
	//移動量
	static const int Move_val = 5;

	//プレイヤー関係========================
	//命名規則にキャメル型を採用
	KdTexture m_tex;
	Math::Vector3 m_pos;
	Math::Matrix m_mat;
	float m_cooltime;
	bool m_flg;
	float m_ang;
	float m_rad;

	Math::Rectangle rc = { 0,0,64,64 };
};

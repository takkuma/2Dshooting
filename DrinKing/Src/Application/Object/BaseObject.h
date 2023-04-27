#pragma once
//親クラス(基底クラス)

class BaseObject
{
public:
	BaseObject(){};
	~BaseObject() { Release(); };

	//仮想関数
	virtual void Update() = 0;
	virtual void Draw();
	virtual void Init() = 0;
	virtual void Release();
	//出現
	virtual void Pop();

protected:
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
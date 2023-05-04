#pragma once

class GameScene;

class BaseBullet
{
public:
	BaseBullet(){};
	~BaseBullet() { Release(); }

	//仮想関数
	virtual void Update() = 0;
	virtual void Draw();
	virtual void Init() = 0;
	virtual void Release();
	//発射
	virtual void Shot(Math::Vector3 a_pos);
	virtual bool GetFlg() { return m_flg; }

	virtual void SetPos(Math::Vector3 a_pos) { m_pos = a_pos; }
	virtual Math::Vector3 GetPos() { return m_pos; }

	void Setgamescene(GameScene* a_gamescene) { m_gamescene = a_gamescene; }
protected:
	GameScene* m_gamescene;
	//プレイヤー関係========================
	//命名規則にキャメル型を採用
	KdTexture m_tex;
	Math::Vector3 m_pos;
	Math::Matrix m_mat;
	bool m_flg;
	float m_ang;
	float m_deg;
	float m_scale = 1;
};

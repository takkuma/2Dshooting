#pragma once
#include "BaseObject.h"
//�e�N���X(���N���X)

class BaseObject;
class GameScene;
class Player;

class BasePlayer
{
public:
	BasePlayer() {};
	~BasePlayer() {};

	//���z�֐�
	virtual void Update() = 0;
	virtual void Draw();
	virtual void Init() = 0;
	virtual void Release();
	virtual void UpdateMat(Math::Matrix a_mat);
	virtual Math::Matrix GetMat() { return m_mat; }

	virtual Math::Vector3 GetPos() { return m_pos; }
	virtual void SetPos(Math::Vector3 a_pos) { m_pos = a_pos; }

	void SetgameScene(GameScene* a_gamescene) { m_gamescene = a_gamescene; }
protected:
	GameScene* m_gamescene;
	//�ړ���
	static const int Move_val = 5;

	//�v���C���[�֌W========================
	//�����K���ɃL�������^���̗p
	KdTexture m_tex;
	Math::Vector3 m_pos;
	Math::Matrix m_mat;
	float m_cooltime;
	bool m_flg;
	float m_ang;
	float m_rad;

	Math::Rectangle rc = { 0,0,64,64 };
};

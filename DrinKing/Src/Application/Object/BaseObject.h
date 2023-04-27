#pragma once
//�e�N���X(���N���X)

class BaseObject
{
public:
	BaseObject(){};
	~BaseObject() { Release(); };

	//���z�֐�
	virtual void Update() = 0;
	virtual void Draw();
	virtual void Init() = 0;
	virtual void Release();
	//�o��
	virtual void Pop();

protected:
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
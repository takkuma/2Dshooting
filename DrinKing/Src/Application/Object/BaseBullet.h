#pragma once
class BaseBullet
{
public:
	BaseBullet(){};
	~BaseBullet() { Release(); };

	//���z�֐�
	virtual void Update() = 0;
	virtual void Draw();
	virtual void Init() = 0;
	virtual void Release();
	//����
	virtual void Shot(Math::Vector3 a_pos);

protected:
	//�v���C���[�֌W========================
	//�����K���ɃL�������^���̗p
	KdTexture m_tex;
	Math::Vector3 m_pos;
	Math::Matrix m_mat;
	bool m_flg;
	float m_ang;
	float m_deg;
};

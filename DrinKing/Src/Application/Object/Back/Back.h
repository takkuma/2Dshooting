#pragma once

class Back
{
public:
	Back(){};
	~Back() { Release(); };

	void Update();
	void Draw();
	void Init();
	void Release();
private:
	//�摜
	KdTexture m_tex;
	//�ړ��p
	Math::Vector3 m_pos;
	//�s��
	Math::Matrix m_mat;
};

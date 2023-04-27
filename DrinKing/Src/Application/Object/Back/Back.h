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
	//‰æ‘œ
	KdTexture m_tex;
	//ˆÚ“®—p
	Math::Vector3 m_pos;
	//s—ñ
	Math::Matrix m_mat;
};

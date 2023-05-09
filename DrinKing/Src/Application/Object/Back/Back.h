#pragma once
#include"../BaseObject.h"

class Back :public BaseObject
{
public:
	Back() {};
	~Back() { Release(); };
	//ƒƒWƒƒ[ŠÖ”
	void Update()override;
	void Draw()override;
	void Init(int a);
	void Release()override;
private:
	KdTexture m_BordTex;
	Math::Vector3 m_BordPos;
	Math::Matrix m_BordMat;
};

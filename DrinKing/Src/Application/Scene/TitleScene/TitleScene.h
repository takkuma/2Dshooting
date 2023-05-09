#pragma once

#include "../BaseScene.h"

class TitleScene :public BaseScene
{
public:
	TitleScene() {}
	~TitleScene() { Release(); }

	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;

private:
	KdTexture m_NameTex;
	Math::Vector3 m_NamePos;
	Math::Matrix m_NameMat;

	KdTexture m_PushTex;
	Math::Vector3 m_PushPos;
	Math::Matrix m_PushMat;

	float m_scale;
};
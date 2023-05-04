#include "Back.h"

void Back::Update()
{
	m_pos.x -= 4;
	if (m_pos.x < -1280)
	{
		m_pos.x = 1276;
	}

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void Back::Draw()
{
	rc = { 0,0,1280,720 };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0, &rc);
}

void Back::Init(int a)
{
	m_tex.Load("Asset/Textures/Back.png");
	m_pos = {float(1280 * a),0,0};
	m_mat = Math::Matrix::Identity;
}

void Back::Release()
{
}

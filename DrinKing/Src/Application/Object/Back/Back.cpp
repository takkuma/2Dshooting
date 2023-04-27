#include "Back.h"

void Back::Update()
{
	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void Back::Draw()
{
	Math::Rectangle rc = { 0,0,1280,720 };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, m_pos.x, m_pos.y, &rc);
}

void Back::Init()
{
	m_tex.Load("Asset/Textures/Back.png");
	m_pos = {};
	m_mat = Math::Matrix::Identity;
}

void Back::Release()
{
}

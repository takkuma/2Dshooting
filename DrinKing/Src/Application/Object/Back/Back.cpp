#include "Back.h"
#include "../../Scene/GameScene/GameScene.h"

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
	
	m_BordMat = Math::Matrix::CreateTranslation(m_BordPos);
}

void Back::Draw()
{
	rc = { 0,0,1280,720 };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0, &rc);

	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_BordMat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_BordTex, 0, 0);
}

void Back::Init(int a)
{
	m_tex.Load("Asset/Textures/Back.png");
	m_pos = {float(1280 * a),0,0};
	m_mat = Math::Matrix::Identity;
	m_objType = ObjectType::Back;


	m_BordTex.Load("Asset/Textures/ScoreBord.png");
	m_BordPos = { 0,360 - 64,0 };
	m_BordMat = Math::Matrix::Identity;
}

void Back::Release()
{
}

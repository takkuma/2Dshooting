#include "Life.h"
#include "../../Scene/GameScene/GameScene.h"

void Life::Update()
{
	for (auto& obj : m_owner->GetObjectList())
	{
		obj->GetObjType() == ObjectType::Player;
		m_life = obj->GetLife();
	}

	for (int i = 0; i < m_life; i++)
	{
		Math::Matrix transMat;
		transMat = Math::Matrix::CreateTranslation(m_pos[i]);
		m_mat[i] = transMat;
	}
}

void Life::Draw()
{
	for (int i = 0; i < m_life; i++)
	{
		KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat[i]);
		KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0);
	}
}

void Life::Init()
{
	for (auto& obj : m_owner->GetObjectList())
	{
		obj->GetObjType() == ObjectType::Player;
		m_life = obj->GetLife();
	}
	

	m_tex.Load("Asset/Textures/UI/Life.png");
	for (int i = 0; i < m_life; i++)
	{		
		m_pos[i] = {float(-585 + (64 * i)),360 - 55,0};
		m_mat[i] = Math::Matrix::Identity;
	}
	

	m_objType = ObjectType::UI;
}

void Life::Release()
{
}

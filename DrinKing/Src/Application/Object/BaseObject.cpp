#include "BaseObject.h"

void BaseObject::Update()
{

}

void BaseObject::Draw()
{
	//•`‰æ
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0);
}

void BaseObject::Init()
{
	m_pos = {};
	m_mat = Math::Matrix::Identity;
}

void BaseObject::Release()
{

}

void BaseObject::Pop()
{

}

void BaseObject::OnHit()
{

}

void BaseObject::OnHitBullet()
{
}

void BaseObject::RankUp()
{
}

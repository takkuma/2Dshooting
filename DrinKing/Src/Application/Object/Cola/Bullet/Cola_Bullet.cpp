#include "Cola_Bullet.h"

void Cola_Bullet::Update()
{
	if (!m_flg)return;
	m_pos.x += 5;
	if (m_pos.x > 640 + 8)
	{
		m_flg = false;
	}

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void Cola_Bullet::Init()
{
	m_pos = {};
	m_flg = false;
	m_tex.Load("Asset/Textures/bullet_cola.png");
	m_mat = Math::Matrix::Identity;
}

void Cola_Bullet::Release()
{
	
}

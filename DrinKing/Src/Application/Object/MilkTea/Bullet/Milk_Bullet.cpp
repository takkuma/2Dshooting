#include "Milk_Bullet.h"

void Milk_Bullet::Update()
{
	if (!m_flg)return;
	m_pos.x -= 3;

	if (m_pos.x < -320 - 8)
	{
		m_flg = false;
	}

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void Milk_Bullet::Init()
{
	m_pos = {};
	m_flg = false;
	m_tex.Load("Asset/Textures/bullet_milktea.png");
	m_mat = Math::Matrix::Identity;
}

void Milk_Bullet::Release()
{
}

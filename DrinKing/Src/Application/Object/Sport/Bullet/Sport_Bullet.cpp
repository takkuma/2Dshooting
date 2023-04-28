#include "Sport_Bullet.h"

void Sport_Bullet::Update()
{
	if (!m_flg)return;
	m_pos.x += 10;
	if (m_pos.x > 640 + 8)
	{
		m_flg = false;
	}

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void Sport_Bullet::Init()
{
	m_pos = {};
	m_flg = false;
	m_tex.Load("Asset/Textures/bullet_sport.png");
	m_mat = Math::Matrix::Identity;
}

void Sport_Bullet::Release()
{
}

#include "Sport.h"

void Sport::Update()
{
}

void Sport::Draw()
{
}

void Sport::Init()
{
	//�v���C���[�̏�����
	m_tex.Load("Asset/Textures/player_sport.png");
	m_pos = { -250,0,0 };
	m_mat = Math::Matrix::Identity;
	m_cooltime = 30;
}

void Sport::Release()
{
}

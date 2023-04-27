#include "Cola.h"

void Cola::Update()
{
}

void Cola::Draw()
{
}

void Cola::Init()
{
	//ƒvƒŒƒCƒ„[‚Ì‰Šú‰»
	m_tex.Load("Asset/Textures/player_cola.png");
	m_pos = { -250,0,0 };
	m_mat = Math::Matrix::Identity;
	m_cooltime = 30;
}

void Cola::Release()
{
}

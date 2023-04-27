#include "Player.h"
#include "../Water/Water.h"

void Player::Update()
{
	if (GetAsyncKeyState('C') & 0x8000)
	{
		drink = m_water;
	}
	if (GetAsyncKeyState('V') & 0x8000)
	{
		drink = m_cola;
	}
	if (GetAsyncKeyState('B') & 0x8000)
	{
		drink = m_sport;
	}

	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Update();
	}
}

void Player::Draw()
{
	if (!m_flg)return;
	
	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Draw();
	}
}

void Player::Init()
{
	std::shared_ptr<Water> water;
	water = std::make_shared<Water>();
	water->Init();
	m_objList.push_back(water);

	m_flg = true;
	drink = m_water;
}

void Player::Release()
{
}

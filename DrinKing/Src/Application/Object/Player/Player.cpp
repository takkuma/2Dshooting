#include "Player.h"
#include "../../Scene/GameScene/GameScene.h"
#include "../Water/Water.h"
#include "../Cola/Cola.h"
#include "../Sport/Sport.h"

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

	m_objList[drink]->Update();

	for (int i = 0; i < m_objList.size(); i++)
	{
		m_pos = m_objList[drink]->GetPos();
		m_objList[i]->SetPos(m_pos);
		
		Math::Matrix transMat;
		transMat = Math::Matrix::CreateTranslation(m_pos);
		m_mat = transMat;
		m_objList[i]->UpdateMat(m_mat);
	}
}

void Player::Draw()
{
	if (!m_flg)return;
	
	m_objList[drink]->Draw();
}

void Player::Init()
{
	std::shared_ptr<Water> water;
	water = std::make_shared<Water>();
	water->Init();
	m_objList.push_back(water);

	std::shared_ptr<Cola> cola;
	cola = std::make_shared<Cola>();
	cola->Init();
	m_objList.push_back(cola);

	std::shared_ptr<Sport> sport;
	sport = std::make_shared<Sport>();
	sport->Init();
	m_objList.push_back(sport);

	m_flg = true;
	drink = m_water;
}

void Player::Release()
{
}

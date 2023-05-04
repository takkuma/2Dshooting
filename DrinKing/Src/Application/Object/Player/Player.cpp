#include "Player.h"
#include "../../Scene/GameScene/GameScene.h"
#include "../Water/Water.h"
#include "../Cola/Cola.h"
#include "../Sport/Sport.h"

void Player::Update()
{
	//モードチェンジ
	m_cooltime--;
	if (m_cooltime < 0)
	{
		if (GetAsyncKeyState('Z') & 0x8000)
		{
			if (drink == m_water)
			{
				m_cooltime = 0;
			}
			else
			{
				drink = m_water;
				m_cooltime = 180;
			}
		}
		if (GetAsyncKeyState('X') & 0x8000)
		{
			if (m_rank < 36)
			{
				if (drink == m_cola)
				{
					m_cooltime = 0;
				}
				else
				{
					drink = m_cola;
					m_cooltime = 180;
				}
			}	
		}
		if (GetAsyncKeyState('C') & 0x8000)
		{
			if (m_rank < 21)
			{
				if (drink == m_sport)
				{
					m_cooltime = 0;
				}
				else
				{
					drink = m_sport;
					m_cooltime = 180;
				}
			}
		}
	}
	

	m_objList[drink]->Update();

	for (int i = 0; i < m_objList.size(); i++)
	{
		//行列の共有・行列の更新
		m_pos = m_objList[drink]->GetPos();
		m_objList[i]->SetPos(m_pos);
		Math::Matrix transMat;
		transMat = Math::Matrix::CreateTranslation(m_pos);
		m_mat = transMat;
		m_objList[i]->UpdateMat(m_mat);
	}

	//当たり判定
	for (auto& obj : m_owner->GetObjectList())
	{
		if (obj->GetObjType() == ObjectType::Enemy)
		{
			//playerとenemy
			Math::Vector3 v = obj->GetPos() - m_pos;
			if (v.Length() < 64)
			{
				obj->OnHit();
			}
		}
	}
}

void Player::Draw()
{
	if (!m_flg)return;
	
	m_objList[drink]->Draw();
}

void Player::Init()
{
	m_rank = StartRnnk;

	std::shared_ptr<Water> water;
	water = std::make_shared<Water>();
	water->SetgameScene(m_owner);
	water->Init();
	m_objList.push_back(water);

	std::shared_ptr<Cola> cola;
	cola = std::make_shared<Cola>();
	cola->SetgameScene(m_owner);
	cola->Init();
	m_objList.push_back(cola);

	std::shared_ptr<Sport> sport;
	sport = std::make_shared<Sport>();
	sport->SetgameScene(m_owner);
	sport->Init();
	m_objList.push_back(sport);

	m_flg = true;
	m_cooltime = 0;
	drink = m_water;

	m_objType = ObjectType::Player;
}

void Player::Release()
{

}

void Player::RankUp()
{
	m_rank -= 1;
}

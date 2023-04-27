#include "Player.h"
#include "Bullet/Player_Bullet.h"
#include "Keyboard.h"

void Player::Update()
{
	m_cooltime++;
	if (m_cooltime > 30)
	{
 		m_cooltime = 30;
	}

	if (GetAsyncKeyState('C') & 0x8000)
	{
		drink = water;
	}
	if (GetAsyncKeyState('V') & 0x8000)
	{
		drink = cola;
	}
	if (GetAsyncKeyState('B') & 0x8000)
	{
		drink = sport;
	}


	//自機の操作==============================
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_pos.y += Move_val;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_pos.y -= Move_val;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_pos.x -= Move_val;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_pos.x += Move_val;
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000 && m_cooltime == 30)
	{
		
		for (int i = 0; i < m_objList.size(); i++)
		{
			m_objList[i]->Shot(m_pos);
		}
		m_cooltime = 0;
	}

	//画面外に行かないようにする
	if (m_pos.x > -160 - 16)
	{
		m_pos.x = -160 - 16;
	}
	if (m_pos.x < -320 + 16)
	{
		m_pos.x = -320 + 16;
	}
	if (m_pos.y > 180 - 16)
	{
		m_pos.y = 180 - 16;
	}
	if (m_pos.y < -180 + 16)
	{
		m_pos.y = -180 + 16;
	}
	
	
		for (int i = 0; i < m_objList.size(); i++)
		{
			m_objList[i]->Update();
		}

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void Player::Draw()
{
	if (!m_flg)return;
	
		for (int i = 0; i < m_objList.size(); i++)
		{
			m_objList[i]->Draw();
		}

	//自機の描画
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat);
	if (drink == water)
	{
		KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, m_pos.x, m_pos.y, &rc);
	}
	else if (drink == cola)
	{
		KdShaderManager::Instance().m_spriteShader.DrawTex(&colaTex, m_pos.x, m_pos.y, &rc);
	}
	else
	{
		KdShaderManager::Instance().m_spriteShader.DrawTex(&sportTex, m_pos.x, m_pos.y, &rc);
	}
}

void Player::Init()
{
	//弾の初期化
	std::shared_ptr<Player_Bullet>playerbullet[BulletNum];
	for (int i = 0; i < BulletNum; i++)
	{
		playerbullet[i] = std::make_shared<Player_Bullet>();
		playerbullet[i]->Init();
		m_objList.push_back(playerbullet[i]);
	}
	

	//プレイヤーの初期化
	m_tex.Load("Asset/Textures/player.png");
	colaTex.Load("Asset/Textures/player_cola.png");
	sportTex.Load("Asset/Textures/player_sport.png");
	m_pos = { -250,0,0 };
	m_mat = Math::Matrix::Identity;
	m_flg = true;
	drink = water;
	m_cooltime = 30;
}

void Player::Release()
{
}

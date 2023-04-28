#include "Cola.h"
#include "Bullet/Cola_Bullet.h"

void Cola::Update()
{
	m_cooltime++;
	if (m_cooltime > 30)
	{
		m_cooltime = 30;
	}

	//三方向発射
	if (GetAsyncKeyState(VK_SPACE) & 0x8000 && m_cooltime == 30)
	{
		for (int i = 0; i < m_objList.size(); i++)
		{
			if (m_objList[i]->GetFlg())continue;
			
				m_objList[i]->Shot(m_pos);
			break;
		}
		m_cooltime = 0;
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


	//画面外に行かないようにする
	if (m_pos.x > -160 - 32)
	{
		m_pos.x = -160 - 32;
	}
	if (m_pos.x < -640 + 32)
	{
		m_pos.x = -640 + 32;
	}
	if (m_pos.y > 360 - 32)
	{
		m_pos.y = 360 - 32;
	}
	if (m_pos.y < -360 + 32)
	{
		m_pos.y = -360 + 32;
	}


	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Update();
	}
}

void Cola::Draw()
{
	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Draw();
	}

	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0, &rc);
}

void Cola::Init()
{
	//プレイヤーの初期化
	m_tex.Load("Asset/Textures/player_cola.png");
	m_pos = { -500,0,0 };
	m_mat = Math::Matrix::Identity;
	m_cooltime = 30;

	//弾の初期化
	std::shared_ptr<Cola_Bullet>colabullet;
	for (int i = 0; i < BulletNum; i++)
	{
		colabullet = std::make_shared<Cola_Bullet>();
		colabullet->Init();
		m_objList.push_back(colabullet);
	}
}

void Cola::Release()
{
}

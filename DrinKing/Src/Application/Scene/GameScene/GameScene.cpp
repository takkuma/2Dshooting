#include "GameScene.h"
#include "../../Object/Player/Player.h"
#include "../../Object/Tea/Tea.h"
#include "../../Object/Beer/Beer.h"
#include "../../Object/MilkTea/MilkTea.h"

void GameScene::Update()
{
	//ポリモーフィズム
	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Update();
	}
}

void GameScene::Draw()
{
	// ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
	// 2Dの描画はこの間で行う
	KdShaderManager::Instance().m_spriteShader.Begin();
	{
		for (int i = 0; i < m_objList.size(); i++)
		{
			m_objList[i]->Draw();
		}
	}
	KdShaderManager::Instance().m_spriteShader.End();
}

void GameScene::Init()
{
	//自機の初期化
	std::shared_ptr<Player>player;
	player = std::make_shared<Player>();
	player->Init();

	//お茶敵の初期化
	std::shared_ptr<Tea>tea[Tea_Num];
	for (int i = 0; i < Tea_Num; i++)
	{
		tea[i] = std::make_shared<Tea>();
		tea[i]->Init();
		m_objList.push_back(tea[i]);
	}
	

	//ビールの初期化
	std::shared_ptr<Beer>beer[Beer_Num];
	for (int i = 0; i < Beer_Num; i++)
	{
		beer[i] = std::make_shared<Beer>();
		beer[i]->Init();
		m_objList.push_back(beer[i]);
	}

	std::shared_ptr<Milk>milk;
	
	milk = std::make_shared<Milk>();
	milk->Init();
	m_objList.push_back(milk);
	

	//描画を後にするものを後ろにする
	m_objList.push_back(player);
}

void GameScene::Release()
{
}

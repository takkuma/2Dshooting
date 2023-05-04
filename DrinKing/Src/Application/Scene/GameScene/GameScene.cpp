#include "GameScene.h"
#include "../../Object/Player/Player.h"
#include "../../Object/Tea/Tea.h"
#include "../../Object/Beer/Beer.h"
#include "../../Object/MilkTea/MilkTea.h"
#include "../../Object/Back/Back.h"

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
	player->SetOwner(this);
	player->Init();

	//背景の初期化
	std::shared_ptr<Back>back;
	for (int i = 0; i < 2; i++)
	{
		back = std::make_shared<Back>();
		back->Init(i);
		m_objList.push_back(back);
	}

	//お茶敵の初期化
	std::shared_ptr<Tea>tea;
	for (int i = 0; i < Tea_Num; i++)
	{
		tea = std::make_shared<Tea>();
		tea->SetOwner(this);
		tea->Init();
		m_objList.push_back(tea);
	}

	//ビールの初期化
	std::shared_ptr<Beer>beer;
	for (int i = 0; i < Beer_Num; i++)
	{
		beer = std::make_shared<Beer>();
		beer->SetOwner(this);
		beer->Init();
		m_objList.push_back(beer);
	}

	std::shared_ptr<Milk>milk;
	for (int i = 0; i < 2; i++)
	{
		milk = std::make_shared<Milk>();
		milk->SetOwner(this);
		milk->Init();
		m_objList.push_back(milk);
	}
	//描画を後にするものを後ろにする
	m_objList.push_back(player);
}

void GameScene::Release()
{
}
#pragma once

class BaseObject;

class GameScene
{
public:
	GameScene(){};
	~GameScene(){};

	void Update();
	void Draw();
	void Init();
	void Release();
	
private:
	//‰Â•Ï’·”z—ñ
	std::vector<std::shared_ptr<BaseObject>>m_objList;

	static const int Tea_Num = 3;
	static const int Beer_Num = 2;
};
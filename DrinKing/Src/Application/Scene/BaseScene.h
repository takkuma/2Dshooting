#pragma once

class BaseObject;

class BaseScene
{
public:
	BaseScene(){}
	~BaseScene(){}

	virtual void Update();
	virtual void Draw();
	virtual void Init();
	virtual void Release();

	std::vector<std::shared_ptr<BaseObject>> GetObjectList() { return m_objList; }
protected:
	std::vector<std::shared_ptr<BaseObject>>m_objList;
};
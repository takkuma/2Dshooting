#pragma once
#include"../BaseObject.h"

class Back :public BaseObject
{
public:
	Back() {};
	~Back() { Release(); };
	//メジャー関数
	void Update()override;
	void Draw()override;
	void Init(int a);
	void Release()override;
private:
};

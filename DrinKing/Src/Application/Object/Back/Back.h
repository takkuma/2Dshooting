#pragma once
#include"../BaseObject.h"

class Back :public BaseObject
{
public:
	Back() {};
	~Back() { Release(); };
	//���W���[�֐�
	void Update()override;
	void Draw()override;
	void Init(int a);
	void Release()override;
private:
};

#pragma once

#include "../BaseScene.h"

class TitleScene :public BaseScene
{
public:
	TitleScene() {}
	~TitleScene() { Release(); }

	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;

private:
};
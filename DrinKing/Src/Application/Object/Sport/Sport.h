#pragma once
#include "../BasePlayer.h"

class Sport :public BasePlayer
{
public:
	Sport() {};
	~Sport() { Release(); }

	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;
private:
};
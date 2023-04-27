#pragma once
#include "../BasePlayer.h"

class Cola :public BasePlayer
{
public:
	Cola() {};
	~Cola() { Release(); }

	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;
private:
};

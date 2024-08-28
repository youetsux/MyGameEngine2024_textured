#pragma once
#include "Quad.h"
#include "Transform.h"

class Dice :
	public Quad
{
public:
	Dice():Quad(){}//親のコンストラクタだけ読んでおく
	~Dice();
	void InitVertexData() override;
	void InitIndexData() override;
};
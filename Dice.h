#pragma once
#include "Quad.h"
#include "Transform.h"

class Dice :
	public Quad
{
public:
	Dice():Quad(){}//�e�̃R���X�g���N�^�����ǂ�ł���
	~Dice();
	void InitVertexData() override;
	void InitIndexData() override;
};
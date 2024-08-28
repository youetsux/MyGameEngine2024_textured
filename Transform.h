#pragma once
#include <DirectXMath.h>

using namespace DirectX;

//�ʒu�A�����A�g�嗦�Ȃǂ��Ǘ�����N���X
class Transform
{
	XMMATRIX matTranslate_;	//�ړ��s��
	XMMATRIX matRotate_;	//��]�s��	
	XMMATRIX matScale_;	//�g��s��
	//���[���h�}�g���N�X�́A����3�����������́@SRT

public:
	XMFLOAT3 position_;	//�ʒu�@���@���s�ړ�
	XMFLOAT3 rotate_;	//��]�@���@��]
	XMFLOAT3 scale_;	//�g��E�k�����@���@�X�P�[�����O

	//�R���X�g���N�^
	Transform();

	//�f�X�g���N�^
	~Transform();

	//�e�s��̌v�Z
	void Calculation();

	//���[���h�s����擾
	XMMATRIX GetWorldMatrix();
	XMMATRIX GetNormalMatrix();
};
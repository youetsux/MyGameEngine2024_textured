#pragma once
#include "Direct3D.h"
#include <DirectXMath.h>
#include "Texture.h"
#include <vector>
#include "Transform.h"

using std::vector;
using namespace DirectX;



class Sprite
{
	//�R���X�^���g�o�b�t�@�[:�@�A�v��������A�V�F�[�_�[�ɖ��t���[���n���������
	struct CONSTANT_BUFFER
	{
		XMMATRIX	matW;
	};

	//XMFLOAT3�ł��悢�B
	//���_���
	struct VERTEX
	{
		XMVECTOR position;
		XMVECTOR uv;
	};

	uint64_t vertexNum_;			//���_��
	vector<VERTEX> vertices_;		//���_���
	uint64_t indexNum_;				//�C���f�b�N�X��
	vector<int> indices_;			//�C���f�b�N�X���

	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;    //�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@

	Texture* pTexture_; //�e�N�X�`���ւ̃|�C���^
public:
	Sprite();//�R���X�g���N�^
	~Sprite();//�f�X�g���N�^
	HRESULT Load(std::string fileName);//�������p�i�R���X�g���N�^�łł��Ȃ��z�͂������ŏ������j
	void Draw(Transform& transform);//�`��֐�
	void Release();//�������
private:
	//---------Initialize����Ă΂��֐�---------
	void InitVertexData();			//���_���̏���
	HRESULT CreateVertexBuffer();	//���_�o�b�t�@���쐬

	void InitIndexData();			//�C���f�b�N�X��������
	HRESULT CreateIndexBuffer();	//�C���f�b�N�X�o�b�t�@���쐬

	HRESULT CreateConstantBuffer();	//�R���X�^���g�o�b�t�@�쐬

	HRESULT LoadTexture(std::string fileName);			//�e�N�X�`�������[�h
	//---------Draw�֐�����Ă΂��֐�---------
	void PassDataToCB(DirectX::XMMATRIX worldMatrix);	//�R���X�^���g�o�b�t�@�Ɋe�����n��
	void SetBufferToPipeline();							//�e�o�b�t�@���p�C�v���C���ɃZ�b�g
};


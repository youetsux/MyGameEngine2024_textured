#include "Dice.h"
#include "Camera.h"


Dice::~Dice()
{

}

void Dice::InitVertexData()
{
	
	// ���_���
	vertices_ =
	{
		{{ -1.0f,  1.0f, -1.0f, 0.0f },  XMVectorSet(0.0, 0.0, 0.0, 0.0) , XMVectorSet(0.0, 0.0, -1.0, 0.0)},
		{{  1.0f,  1.0f, -1.0f, 0.0f },  XMVectorSet(0.25, 0.0, 0.0, 0.0), XMVectorSet(0.0, 0.0, -1.0, 0.0)},
		{{ -1.0f, -1.0f, -1.0f, 0.0f },  XMVectorSet(0.0, 0.5, 0.0, 0.0) , XMVectorSet(0.0, 0.0, -1.0, 0.0)},
		{{  1.0f, -1.0f, -1.0f, 0.0f },  XMVectorSet(0.25, 0.5, 0.0, 0.0), XMVectorSet(0.0, 0.0, -1.0, 0.0)},

		{{ -1.0f,  1.0f, 1.0f, 0.0f },  XMVectorSet(0.25, 0.5, 0.0, 0.0) ,XMVectorSet(0.0, 0.0, 1.0, 0.0)},
		{{ -1.0f, -1.0f, 1.0f, 0.0f },  XMVectorSet(0.25, 1.0, 0.0, 0.0) ,XMVectorSet(0.0, 0.0, 1.0, 0.0)},
		{{  1.0f,  1.0f, 1.0f, 0.0f },  XMVectorSet(0.5, 0.5, 0.0, 0.0) ,XMVectorSet(0.0, 0.0, 1.0, 0.0)},
		{{  1.0f, -1.0f, 1.0f, 0.0f },  XMVectorSet(0.5, 1.0, 0.0, 0.0) ,XMVectorSet(0.0, 0.0, 1.0, 0.0)},

		{{ -1.0f,  1.0f,  1.0f, 0.0f },  XMVectorSet(0.25, 0.0, 0.0, 0.0) ,XMVectorSet(-1.0, 0.0, 0.0, 0.0)},
		{{ -1.0f,  1.0f, -1.0f, 0.0f },  XMVectorSet(0.5, 0.0, 0.0, 0.0) ,XMVectorSet(-1.0, 0.0, 0.0, 0.0)},
		{{ -1.0f, -1.0f,  1.0f, 0.0f },  XMVectorSet(0.25, 0.5, 0.0, 0.0) ,XMVectorSet(-1.0, 0.0, 0.0, 0.0)},
		{{ -1.0f, -1.0f, -1.0f, 0.0f },  XMVectorSet(0.5, 0.5, 0.0, 0.0) ,XMVectorSet(-1.0, 0.0, 0.0, 0.0)},

		{{  1.0f,  1.0f,  1.0f, 0.0f },  XMVectorSet(0.0, 0.5, 0.0, 0.0) ,XMVectorSet(1.0, 0.0, 0.0, 0.0)},
		{{  1.0f, -1.0f,  1.0f, 0.0f },  XMVectorSet(0.25, 0.5, 0.0, 0.0) ,XMVectorSet(1.0, 0.0, 0.0, 0.0)},
		{{  1.0f,  1.0f, -1.0f, 0.0f },  XMVectorSet(0.0, 1.0, 0.0, 0.0) ,XMVectorSet(1.0, 0.0, 0.0, 0.0)},
		{{  1.0f, -1.0f, -1.0f, 0.0f },  XMVectorSet(0.25, 1.0, 0.0, 0.0) ,XMVectorSet(1.0, 0.0, 0.0, 0.0)},

		{{ -1.0f,  1.0f,  1.0f, 0.0f },  XMVectorSet(0.5, 0.0, 0.0, 0.0) ,XMVectorSet(0.0, 1.0, 0.0, 0.0)},
		{{ -1.0f,  1.0f, -1.0f, 0.0f },  XMVectorSet(0.5, 0.5, 0.0, 0.0) ,XMVectorSet(0.0, 1.0, 0.0, 0.0)},
		{{  1.0f,  1.0f,  1.0f, 0.0f },  XMVectorSet(0.75, 0.0, 0.0, 0.0) ,XMVectorSet(0.0, 1.0, 0.0, 0.0)},
		{{  1.0f,  1.0f, -1.0f, 0.0f },  XMVectorSet(0.75, 0.5, 0.0, 0.0) ,XMVectorSet(0.0, 1.0, 0.0, 0.0)},

		{{ -1.0f, -1.0f,  1.0f, 0.0f }, XMVectorSet(0.75, 0.0, 0.0, 0.0) ,XMVectorSet(0.0, -1.0, 0.0, 0.0)},
		{{ -1.0f, -1.0f, -1.0f, 0.0f }, XMVectorSet(0.75, 0.5, 0.0, 0.0) ,XMVectorSet(0.0, -1.0, 0.0, 0.0)},
		{{  1.0f, -1.0f,  1.0f, 0.0f }, XMVectorSet(1.0, 0.0, 0.0, 0.0) ,XMVectorSet(0.0, -1.0, 0.0, 0.0)},
		{{  1.0f, -1.0f, -1.0f, 0.0f }, XMVectorSet(1.0, 0.5, 0.0, 0.0) ,XMVectorSet(0.0, -1.0, 0.0, 0.0)}
	};
	vertexNum_ = vertices_.size();
}

void Dice::InitIndexData()
{
	//�C���f�b�N�X���
	index_ = {
	 0,  1,  2,     3,  2,  1,
	 4,  5,  6,     7,  6,  5,
	 8,  9, 10,    11, 10,  9,
	12, 13, 14,    15, 14, 13,
	16, 18, 17,    19, 17, 18,
	20, 21, 22,    23, 22, 21, };
	indexNum_ = index_.size();
}

//HRESULT Dice::Initialize()
//{
//
//	
//	
//
//
//
//	// ���_�f�[�^�p�o�b�t�@�̐ݒ�
//	D3D11_BUFFER_DESC bd_vertex;
//	bd_vertex.ByteWidth = sizeof(vertices);
//	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
//	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
//	bd_vertex.CPUAccessFlags = 0;
//	bd_vertex.MiscFlags = 0;
//	bd_vertex.StructureByteStride = 0;
//	D3D11_SUBRESOURCE_DATA data_vertex;
//	data_vertex.pSysMem = vertices;
//	hr = Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_);
//	//hr = E_FAIL;
//	if (FAILED(hr))
//	{
//		//int MessageBox(
//		//	[in, optional] HWND    hWnd,
//		//	[in, optional] LPCTSTR lpText,
//		//	[in, optional] LPCTSTR lpCaption,
//		//	[in]           UINT    uType
//		//);
//		MessageBox(NULL, L"���_�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
//		return hr;
//	}
//
//	// �C���f�b�N�X�o�b�t�@�𐶐�����
//	D3D11_BUFFER_DESC   bd;
//	bd.Usage = D3D11_USAGE_DEFAULT;
//	bd.ByteWidth = sizeof(index);
//	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
//	bd.CPUAccessFlags = 0;
//	bd.MiscFlags = 0;
//
//	D3D11_SUBRESOURCE_DATA InitData;
//	InitData.pSysMem = index;
//	InitData.SysMemPitch = 0;
//	InitData.SysMemSlicePitch = 0;
//	hr = Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_);
//	if (FAILED(hr))
//	{
//		MessageBox(NULL, L"�C���f�b�N�X�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
//		return hr;
//	}
//
//	//�R���X�^���g�o�b�t�@�쐬
//	D3D11_BUFFER_DESC cb;
//	cb.ByteWidth = sizeof(CONSTANT_BUFFER);
//	cb.Usage = D3D11_USAGE_DYNAMIC;
//	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
//	cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
//	cb.MiscFlags = 0;
//	cb.StructureByteStride = 0;
//
//	// �R���X�^���g�o�b�t�@�̍쐬
//	hr = Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_);
//	if (FAILED(hr))
//	{
//		MessageBox(NULL, L"�R���X�^���g�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
//		return hr;
//	}
//
//	pTexture_ = new Texture;
//	pTexture_->Load("Assets\\dice.png");
//
//	return S_OK;
//}
//
//void Dice::Draw(Transform& transform)
//{
//	Direct3D::SetShader(SHADER_TYPE::SHADER_3D);
//
//	transform.Calculation();
//	CONSTANT_BUFFER cb;
//	cb.matWVP = XMMatrixTranspose(transform.GetWorldMatrix() * Camera::GetViewMatrix() * Camera::GetProjectionMatrix()); //view*proj���J��������Ƃ��Ă���
//	cb.matW = XMMatrixTranspose(transform.GetWorldMatrix());
//
//	D3D11_MAPPED_SUBRESOURCE pdata;
//	Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPU����̃f�[�^�A�N�Z�X���~�߂�
//	memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));	// �f�[�^��l�𑗂�
//	Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//�ĊJ
//
//	//���_�o�b�t�@
//	UINT stride = sizeof(VERTEX);
//	UINT offset = 0;
//	Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);
//
//	// �C���f�b�N�X�o�b�t�@�[���Z�b�g
//	stride = sizeof(int);
//	offset = 0;
//	Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);
//
//	//�R���X�^���g�o�b�t�@
//	Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//���_�V�F�[�_�[�p	
//	Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//�s�N�Z���V�F�[�_�[�p
//
//	//�T���v���[�ƃV�F�[�_�[���\�[�X�r���[���V�F�[�_�ɃZ�b�g
//	ID3D11SamplerState* 
//  = pTexture_->GetSampler();
//	Direct3D::pContext->PSSetSamplers(0, 1, &pSampler);
//
//	ID3D11ShaderResourceView* pSRV = pTexture_->GetSRV();
//	Direct3D::pContext->PSSetShaderResources(0, 1, &pSRV);
//
//	Direct3D::pContext->DrawIndexed(36, 0, 0);
//}

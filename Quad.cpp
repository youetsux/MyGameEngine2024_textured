#include "Quad.h"
#include "Camera.h"

Quad::Quad()
	:pTexture_(nullptr),pVertexBuffer_(nullptr),pIndexBuffer_(nullptr),
	pConstantBuffer_(nullptr),vertexNum_(0),indexNum_(0)
{
}

Quad::~Quad()
{
	Release();
}

HRESULT Quad::Initialize()
{
	InitVertexData();
	if (FAILED(CreateVertexBuffer()))
	{
		return E_FAIL;
	}


	InitIndexData();
	if (FAILED(CreateIndexBuffer()))
	{
		return E_FAIL;
	}

	if (FAILED(CreateConstantBuffer()))
	{
		return E_FAIL;
	}

	//�e�N�X�`���̃��[�h
	if (FAILED(LoadTexture()))
	{
		return E_FAIL;
	}

	return S_OK;
}

//void Quad::Draw()
//{
//	/*
//	////�R���X�^���g�o�b�t�@�ɓn�����
//	//xmvector position = { 0, 3, -10, 0 };	//�J�����̈ʒu
//	//xmvector target = { 0, 0, 0, 0 };	//�J�����̏œ_
//	//xmmatrix view = xmmatrixlookatlh(position, target, xmvectorset(0, 1, 0, 0));	//�r���[�s��
//	//xmmatrix proj = xmmatrixperspectivefovlh(xm_pidiv4, 800.0f / 600.0f, 0.1f, 100.0f);//�ˉe�s��
//	//
//
//	//constant_buffer cb;
//	//cb.matwvp = xmmatrixtranspose(camera::getviewmatrix() * camera::getprojectionmatrix()); //view*proj���J��������Ƃ��Ă���
//
//	//d3d11_mapped_subresource pdata;
//	//direct3d::pcontext->map(pconstantbuffer_, 0, d3d11_map_write_discard, 0, &pdata);	// gpu����̃f�[�^�A�N�Z�X���~�߂�
//	//memcpy_s(pdata.pdata, pdata.rowpitch, (void*)(&cb), sizeof(cb));	// �f�[�^��l�𑗂�
//	//direct3d::pcontext->unmap(pconstantbuffer_, 0);	//�ĊJ
//
//	////���_�o�b�t�@
//	//uint stride = sizeof(vertex);
//	//uint offset = 0;
//	//direct3d::pcontext->iasetvertexbuffers(0, 1, &pvertexbuffer_, &stride, &offset);
//
//	//// �C���f�b�N�X�o�b�t�@�[���Z�b�g
//	//stride = sizeof(int);
//	//offset = 0;
//	//direct3d::pcontext->iasetindexbuffer(pindexbuffer_, dxgi_format_r32_uint, 0);
//
//	////�R���X�^���g�o�b�t�@
//	//direct3d::pcontext->vssetconstantbuffers(0, 1, &pconstantbuffer_);	//���_�V�F�[�_�[�p	
//	//direct3d::pcontext->pssetconstantbuffers(0, 1, &pconstantbuffer_);	//�s�N�Z���V�F�[�_�[�p
//
//	//direct3d::pcontext->drawindexed(6, 0, 0);
//	*/
//}

void Quad::Draw(Transform& transform)
{
	Direct3D::SetShader(SHADER_3D);
	transform.Calculation();//�g�����X�t�H�[�����v�Z
	//�R���X�^���g�o�b�t�@�ɏ���n��
	PassDataToCB(transform);

	//���_�o�b�t�@�A�C���f�b�N�X�o�b�t�@�A�R���X�^���g�o�b�t�@���p�C�v���C���ɃZ�b�g
	SetBufferToPipeline();

	//�`��
	Direct3D::pContext->DrawIndexed(index_.size(), 0, 0);

}

void Quad::Release()
{
	SAFE_RELEASE(pConstantBuffer_);
	SAFE_RELEASE(pIndexBuffer_);
	SAFE_RELEASE(pVertexBuffer_);
}

void Quad::InitVertexData()
{
	// ���_���
	vertices_ =
	{
		{XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(0.0f,  0.0f, 0.0f, 0.0f), XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f)},// �l�p�`�̒��_�i����j
		{XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(1.0f,  0.0f, 0.0f, 0.0f), XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f)},// �l�p�`�̒��_�i�E��j
		{XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f)},// �l�p�`�̒��_�i�E���j
		{XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f)}	// �l�p�`�̒��_�i�����j	};
	};
	vertexNum_ = vertices_.size();

}

HRESULT Quad::CreateVertexBuffer()
{
	HRESULT hr;
	// ���_�f�[�^�p�o�b�t�@�̐ݒ�
	D3D11_BUFFER_DESC bd_vertex;
	bd_vertex.ByteWidth = sizeof(VERTEX) * vertexNum_;
	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd_vertex.CPUAccessFlags = 0;
	bd_vertex.MiscFlags = 0;
	bd_vertex.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA data_vertex;
	data_vertex.pSysMem = vertices_.data();
	hr = Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_);
	//hr = E_FAIL;
	if (FAILED(hr))
	{
		//int MessageBox(
		//	[in, optional] HWND    hWnd,
		//	[in, optional] LPCTSTR lpText,
		//	[in, optional] LPCTSTR lpCaption,
		//	[in]           UINT    uType
		//);
		MessageBox(NULL, L"���_�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
		return hr;
	}
	return S_OK;
}

void Quad::InitIndexData()
{
	//�C���f�b�N�X���
	index_ = { 0,2,3, 0,1,2 };
	indexNum_ = index_.size();
}

HRESULT Quad::CreateIndexBuffer()
{
	HRESULT hr;
	// �C���f�b�N�X�o�b�t�@�𐶐�����
	D3D11_BUFFER_DESC   bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(int) * indexNum_;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = index_.data();
	InitData.SysMemPitch = 0;
	InitData.SysMemSlicePitch = 0;
	hr = Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"�C���f�b�N�X�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
		return hr;
	}
	return S_OK;
}

HRESULT Quad::CreateConstantBuffer()
{
	HRESULT hr;
	//�R���X�^���g�o�b�t�@�쐬
	D3D11_BUFFER_DESC cb;
	cb.ByteWidth = sizeof(CONSTANT_BUFFER);
	cb.Usage = D3D11_USAGE_DYNAMIC;
	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	cb.MiscFlags = 0;
	cb.StructureByteStride = 0;

	// �R���X�^���g�o�b�t�@�̍쐬
	hr = Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"�R���X�^���g�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
		return hr;
	}
	return S_OK;
}

HRESULT Quad::LoadTexture()
{
	pTexture_ = new Texture;
	HRESULT hr;
	if (FAILED(hr = pTexture_->Load("Assets\\dice.png")))
	{
		MessageBox(NULL, L"�e�N�X�`���̍쐬�Ɏ��s���܂���", L"�G���[", MB_OK);
		return hr;
	}
	return S_OK;
}

void Quad::PassDataToCB(Transform& transform)
{
	CONSTANT_BUFFER cb;
	cb.matWVP = XMMatrixTranspose(transform.GetWorldMatrix() * Camera::GetViewMatrix() * Camera::GetProjectionMatrix()); //view*proj���J��������Ƃ��Ă���
	cb.matW = XMMatrixTranspose(transform.GetNormalMatrix()); //MATRIX�̊|���Z�̂�����DirectX�ƈႤ�̂œ]�u���Ƃ�i�Ȃ񂻂�j

	D3D11_MAPPED_SUBRESOURCE pdata;
	Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPU����̃f�[�^�A�N�Z�X���~�߂�
	memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));	// �f�[�^��l�𑗂�
	Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//�ĊJ

}

void Quad::SetBufferToPipeline()
{
	//���_�o�b�t�@
	UINT stride = sizeof(VERTEX);
	UINT offset = 0;
	Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);

	// �C���f�b�N�X�o�b�t�@�[���Z�b�g
	stride = sizeof(int);
	offset = 0;
	Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);

	//�R���X�^���g�o�b�t�@
	Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//���_�V�F�[�_�[�p	
	Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//�s�N�Z���V�F�[�_�[�p


	//�T���v���[�ƃV�F�[�_�[���\�[�X�r���[���V�F�[�_�ɃZ�b�g
	ID3D11SamplerState* pSampler = pTexture_->GetSampler();
	Direct3D::pContext->PSSetSamplers(0, 1, &pSampler);

	ID3D11ShaderResourceView* pSRV = pTexture_->GetSRV();
	Direct3D::pContext->PSSetShaderResources(0, 1, &pSRV);

	//Direct3D::pContext->DrawIndexed(indexNum_, 0, 0);
}

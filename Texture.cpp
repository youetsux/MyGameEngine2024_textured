#include "Texture.h"
#include "Direct3D.h"
#include <DirectXTex.h>


using namespace DirectX;


Texture::Texture()
	:pSampler_(nullptr), pSRV_(nullptr)
{
}

HRESULT Texture::Load(string fileName)
{

	TexMetadata metadata; //�摜�̕t�����
	ScratchImage image;   //�摜�{��

	HRESULT hr = S_OK;

	//���ۂɓǂ�ł䂭���@�@�@�@�@ 
	std::wstring wstr(fileName.begin(), fileName.end()); //string => wchar_t* �̕ϊ��@LPCWSTR == cont wchar_t*
	hr = LoadFromWICFile(wstr.c_str(), WIC_FLAGS::WIC_FLAGS_NONE, &metadata, image);

	if (FAILED(hr))
	{
		return S_FALSE;
	}

	//�T���v���[�̐ݒ�����Ă䂭��
	D3D11_SAMPLER_DESC  SamDesc;
	ZeroMemory(&SamDesc, sizeof(D3D11_SAMPLER_DESC));
	SamDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	SamDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
	SamDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
	SamDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
	Direct3D::pDevice->CreateSamplerState(&SamDesc, &pSampler_);
	if (FAILED(hr))
	{
		return S_FALSE;
	}


	//�V�F�[�_�[���\�[�X�r���[�̐ݒ�Ɛ���
	D3D11_SHADER_RESOURCE_VIEW_DESC srv = {};
	srv.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	srv.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srv.Texture2D.MipLevels = 1;
	hr = CreateShaderResourceView(Direct3D::pDevice,
		image.GetImages(), image.GetImageCount(), metadata, &pSRV_);
	if (FAILED(hr))
	{
		return S_FALSE;
	}

    return hr;
}

void Texture::Release()
{
	SAFE_RELEASE(pSampler_);
	SAFE_RELEASE(pSRV_);
}

#include "Transform.h"

Transform::Transform()
    :position_({ 0,0,0 }),
     rotate_({ 0,0,0 }),
     scale_({ 1,1,1 }),
    matTranslate_(XMMatrixIdentity()),
    matRotate_(XMMatrixIdentity()),
    matScale_(XMMatrixIdentity())
{
    //float x = XMVectorGetX(position_);
    //float y = XMVectorGetY(position_);
    //float z = XMVectorGetZ(position_);
    //float w = XMVectorGetW(position_);
}

Transform::~Transform()
{
}

void Transform::Calculation()
{
    //SRT�̏��ԂŊ|����ƁA���[���h�ϊ��ɂȂ��
    matTranslate_ = XMMatrixTranslation(position_.x, position_.y, position_.z);

    //R=Z*X*Y�̏��Ԃōs����|�����DirectX�̉�]�ɂȂ��
    //digree->radians XMConvertToRadians()
    XMMATRIX rx = XMMatrixRotationX(XMConvertToRadians( rotate_.x ));
    XMMATRIX ry = XMMatrixRotationY(XMConvertToRadians( rotate_.y ));
    XMMATRIX rz = XMMatrixRotationZ(XMConvertToRadians( rotate_.z ));
    matRotate_ = rz * rx * ry; //R = z * x * y

    matScale_ = XMMatrixScaling(scale_.x, scale_.y, scale_.z);
}

XMMATRIX Transform::GetWorldMatrix()
{
    return matScale_* matRotate_ * matTranslate_; //SRT�����߂�
}

XMMATRIX Transform::GetNormalMatrix()
{
    //���s�ړ��͖����A��]�͊|����A�X�P�[���͌��ɖ߂�
    return(matRotate_ * XMMatrixInverse(nullptr, matScale_));
}

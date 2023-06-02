#include "Core/Engine/Game/Material.h"
#include "Core/Engine/Asset/AssetManager.h"
#include "Core/Engine/Renderer/MaterialResourceProxy.h"

namespace Panda
{
	UMaterial::UMaterial(const FString& InVertexShaderPath, const FString& InFragShaderPath, UObject* Parent)
		: UObject(Parent)
        , VertexShaderPath(InVertexShaderPath)
		, FragShaderPath(InFragShaderPath)
	{
	}

	void UMaterial::AddScalarParameter(const FString &ParameterName, float DefaultValue)
    {
        ScalarParameters[ParameterName] = DefaultValue;
        AllParameterNames.push_back(ParameterName);
    }

    void UMaterial::AddVector4Parameter(const FString &ParameterName, FVector4 DefaultValue)
    {
        Vector4Parameters[ParameterName] = DefaultValue;
        AllParameterNames.push_back(ParameterName);
    }

    void UMaterial::AddTextureParameter(const FString &ParameterName, UTexture *DefaultTexture)
    {
        TextureParameters[ParameterName] = DefaultTexture;
        AllParameterNames.push_back(ParameterName);
    }

    void UMaterial::AddMatrix4x4Parameter(const FString &ParameterName, FMatrix DefaultMat)
    {
        Mat4Parameters[ParameterName] = DefaultMat;
        AllParameterNames.push_back(ParameterName);
    }

    void UMaterial::SetScalarParameterValue(const FString &ParameterName, float NewValue)
    {
        check(ScalarParameters.find(ParameterName) != ScalarParameters.end())
        ScalarParameters[ParameterName] = NewValue;
        AllParameterNames.push_back(ParameterName);
    }

    bool UMaterial::LoadAsset()
    {
	    VertexShaderSource = UAssetManager::Get()->LoadFileText(VertexShaderPath);
	    FragShaderSource = UAssetManager::Get()->LoadFileText(FragShaderPath);
        return (!VertexShaderSource.IsEmpty()) && (!FragShaderSource.IsEmpty());
    }

    FMaterialResourceProxy* UMaterial::CreateProxy()
    {
        MaterialProxy = new FMaterialResourceProxy(this);
        return MaterialProxy;
    }

    void UMaterial::SetTextureParameterValue(const FString &ParameterName, UTexture *Texture)
    {
        check(TextureParameters.find(ParameterName) != TextureParameters.end())
        TextureParameters[ParameterName] = Texture;
    }

    TArray<FString> UMaterial::GetAllParameterNames() const
    {
        return AllParameterNames;
    }
}
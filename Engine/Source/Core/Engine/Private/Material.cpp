#include "Core/Engine/Material.h"
#include "Core/Engine/Asset/AssetManager.h"
#include "Core/Engine/MaterialResourceProxy.h"

namespace Panda
{
	UMaterial::UMaterial(const FString& InVertexShaderPath, const FString& InFragShaderPath)
		: VertexShaderPath(InVertexShaderPath)
		, FragShaderPath(InFragShaderPath)
	{
	}

	void UMaterial::AddScalarParameter(const FString &ParameterName, float DefaultValue)
    {
        ScalarParameters[ParameterName] = DefaultValue;
    }

    void UMaterial::AddVector4Parameter(const FString &ParameterName, FVector4 DefaultValue)
    {
        Vector4Parameters[ParameterName] = DefaultValue;
    }

    void UMaterial::SetScalarParameterValue(const FString &ParameterName, float NewValue)
    {
        check(ScalarParameters.find(ParameterName) != ScalarParameters.end())
        ScalarParameters[ParameterName] = NewValue;
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
}
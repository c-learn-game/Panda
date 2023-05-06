#include "Core/Engine/Material.h"

namespace Panda
{
	UMaterial::UMaterial(const FString& InVertexShaderSource, const FString& InFragShaderSource)
		: VertexShaderSource(InVertexShaderSource)
		, FragShaderSource(InFragShaderSource)
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
}
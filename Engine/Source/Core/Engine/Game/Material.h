#ifndef PANDA_MATERIAL_H
#define PANDA_MATERIAL_H

#include "Basic/Basic.h"
#include "Core/Math/Vector4.h"

namespace Panda
{
	class UMaterial
	{
	public:
		explicit UMaterial(const FString& InVertexShaderPath, const FString& InFragShaderPath);
		
		virtual ~UMaterial() = default;

		void AddScalarParameter(const FString& ParameterName, float DefaultValue = 0.0f);

		void AddVector4Parameter(const FString& ParameterName, FVector4 DefaultValue);

		void SetScalarParameterValue(const FString& ParameterName, float NewValue);

        class FMaterialResourceProxy* CreateProxy();

        bool LoadAsset();

    public:
	    class FMaterialResourceProxy* MaterialProxy = nullptr;

    protected:
	    friend class FMaterialResourceProxy;
        FString VertexShaderSource, FragShaderSource;
        THash<FString, float> ScalarParameters;
        THash<FString, FVector4> Vector4Parameters;

	private:
	    FString VertexShaderPath, FragShaderPath;
	};
}


#endif
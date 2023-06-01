#ifndef PANDA_MATERIAL_H
#define PANDA_MATERIAL_H

#include "Basic/Basic.h"
#include "Core/Math/MathCore.h"
#include "Core/Engine/GameObject.h"

namespace Panda
{
    class UTexture;

    class UMaterial : public UObject
	{
	public:
		explicit UMaterial(const FString& InVertexShaderPath, const FString& InFragShaderPath);
		
		virtual ~UMaterial() = default;

		void AddScalarParameter(const FString& ParameterName, float DefaultValue = 0.0f);

		void AddVector4Parameter(const FString& ParameterName, FVector4 DefaultValue = FVector4(0));

        void AddTextureParameter(const FString& ParameterName, UTexture* DefaultTexture = nullptr);

        void AddMatrix4x4Parameter(const FString& ParameterName, FMatrix DefaultMat = FMatrix());

		void SetScalarParameterValue(const FString& ParameterName, float NewValue);

        void SetTextureParameterValue(const FString& ParameterName, UTexture* Texture);

        class FMaterialResourceProxy* CreateProxy();

        bool LoadAsset();

        TArray<FString> GetAllParameterNames() const;

    public:
	    class FMaterialResourceProxy* MaterialProxy = nullptr;

    protected:
	    friend class FMaterialResourceProxy;
        FString VertexShaderSource, FragShaderSource;
        THash<FString, float> ScalarParameters;
        THash<FString, FVector4> Vector4Parameters;
        THash<FString, UTexture*> TextureParameters;
        THash<FString, FMatrix> Mat4Parameters;
        TArray<FString> AllParameterNames;

	private:
	    FString VertexShaderPath, FragShaderPath;
	};
}


#endif
#ifndef PANDA_MATERIAL_H
#define PANDA_MATERIAL_H

#include "Basic/Basic.h"
#include "Core/Math/Vector4.h"

namespace Panda
{
	class UMaterial
	{
	public:
		explicit UMaterial(const FString& InVertexShaderSource, const FString& InFragShaderSource);
		
		virtual ~UMaterial() = default;

		void AddScalarParameter(const FString& ParameterName, float DefaultValue = 0.0f);

		void AddVector4Parameter(const FString& ParameterName, FVector4 DefaultValue);

		void SetScalarParameterValue(const FString& ParameterName, float NewValue);

        FString GetVertexShaderSource() const { return VertexShaderSource; }

        FString GetFragShaderSource() const { return FragShaderSource; }

        static SharedPtr<UMaterial> LoadMaterial(const FString& VertPath, const FString& FragPath);

	private:
		FString VertexShaderSource, FragShaderSource;
		THash<FString, float> ScalarParameters;
		THash<FString, FVector4> Vector4Parameters;
		//THash<FString, int> Texture2DParameters;
	};
}


#endif
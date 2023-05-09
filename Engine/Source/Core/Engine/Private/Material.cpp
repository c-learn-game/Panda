#include "Core/Engine/Material.h"
#include "Core/Path/File.h"
#include "Core/Path/Path.h"

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

    SharedPtr<UMaterial> UMaterial::LoadMaterial(const FString &VertPath, const FString &FragPath)
    {
        LogInfo("create material")
        LogInfo("   vertex source file: {}", VertPath)
        LogInfo("   fragment source file: {}", FragPath)
	    FFile VertSourceFile(VertPath);
	    FFile FragSourceFile(FragPath);

	    if (VertSourceFile.Open() && FragSourceFile.Open())
        {
	        FString VertSource = VertSourceFile.ReadAll();
	        FString FragSource = FragSourceFile.ReadAll();
	        VertSourceFile.Close();
	        FragSourceFile.Close();
            return MakeShared<UMaterial>(VertSource, FragSource);
        }
        LogWarn("open shader file failed!")
        VertSourceFile.Close();
        FragSourceFile.Close();
        return nullptr;
    }

    FString UMaterial::EngineShaderSourcePath(const FString &FilePath)
    {
        FString SourcePath = Path::EngineShaderPath;
        if (FilePath.empty() || !(FilePath[0]=='/'))
            SourcePath.append("/");
        return SourcePath.append(FilePath);
    }
}
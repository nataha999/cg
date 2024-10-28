#include "pch.h"
#include "ShaderLoader.h"
#include "Shader.h"
#include <sstream>
#include <fstream>

namespace
{
GLuint LoadShader(GLenum shaderType, std::istream& stream, GLuint shaderId)
{
	std::stringstream strStream;
	strStream << stream.rdbuf();

	std::string shaderSource = strStream.str();

	CShader shader(shaderId);
	if (!shader)
	{
		shader.Create(shaderType);
	}
	shader.SetSource(shaderSource.c_str());
	return shader.Detach();
}
}

GLuint ShaderLoader::LoadShader(GLenum shaderType, const wchar_t* fileName, GLuint shaderId)
{
	std::ifstream stream;
	stream.open(fileName);

	if (!stream.is_open())
	{
		throw std::runtime_error("Can't open shader file");
	}
	return ::LoadShader(shaderType, stream, shaderId);
}
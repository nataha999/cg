#pragma once

class ShaderLoader
{
public:
	static GLuint LoadShader(GLenum shaderType, const wchar_t* fileName, GLuint shaderId = 0);
};

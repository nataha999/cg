#pragma once

class ShaderCompiler
{
public:
	ShaderCompiler() = default;
	~ShaderCompiler() = default;
	void CompileShader(GLuint shader);
	void CheckStatus();

private:
	std::vector<GLuint> m_shaders;
};

#pragma once

class ProgramLinker
{
public:
	ProgramLinker() = default;
	~ProgramLinker() = default;

	void LinkProgram(GLuint program);
	void CheckStatus();

private:
	std::vector<GLuint> m_programs;
};

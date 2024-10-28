#include "pch.h"
#include "ProgramLinker.h"
#include "Shader.h"

void ProgramLinker::LinkProgram(GLuint program)
{
	CProgramHandle prog(program);
	prog.Link();
	m_programs.push_back(program);
}

void ProgramLinker::CheckStatus()
{
	std::stringstream strm;

	bool hasErrors = false;

	for (size_t i = 0; i < m_programs.size(); ++i)
	{
		CProgramHandle program(m_programs[i]);
		if (program.GetParameter(GL_LINK_STATUS) != GL_TRUE)
		{
			hasErrors = true;
			strm << "Program " << program << " linkage failed: " << program.GetInfoLog() << std::endl;
		}
	}

	m_programs.clear();

	if (hasErrors)
	{
		throw std::runtime_error(strm.str());
	}
}

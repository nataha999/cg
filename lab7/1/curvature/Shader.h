#pragma once
#include "pch.h"

class CShaderBase
{
protected:
	CShaderBase(GLuint shader = 0)
		: m_shader(shader)
	{
	}

	~CShaderBase() = default;

public:
	void SetSource(GLsizei count, const GLchar** strings, const GLint* lengths)
	{
		assert(m_shader != 0);

		glShaderSource(m_shader, count, strings, lengths);
	}

	void SetSource(const GLchar* source, GLint length)
	{
		const GLchar** ppSource = &source;
		SetSource(1, ppSource, &length);
	}

	void SetSource(const GLchar* source)
	{
		const GLchar** ppSource = &source;
		SetSource(1, ppSource, NULL);
	}

	void GetParameter(GLenum pname, GLint* param) const
	{
		assert(m_shader != 0);
		glGetShaderiv(m_shader, pname, param);
	}

	GLint GetParameter(GLenum pname) const
	{
		GLint value;
		GetParameter(pname, &value);
		return value;
	}

	void GetInfoLog(GLsizei bufSize, GLsizei* length, GLchar* infoLog) const
	{
		assert(m_shader != 0);
		glGetShaderInfoLog(m_shader, bufSize, length, infoLog);
	}

	std::string GetInfoLog() const
	{
		GLint length = GetParameter(GL_INFO_LOG_LENGTH);
		if (length > 0)
		{
			std::vector<char> buffer(length);
			GetInfoLog(length, &length, &buffer[0]);
			std::string log(&buffer[0]);
			return log;
		}
		else
		{
			return std::string();
		}
	}

	operator GLuint() const
	{
		return m_shader;
	}

	GLuint Get() const
	{
		return m_shader;
	}

	void Compile()
	{
		assert(m_shader != 0);
		glCompileShader(m_shader);
	}

	GLuint Attach(GLuint shader)
	{
		GLuint tmp = m_shader;
		m_shader = shader;
		return tmp;
	}

	GLuint Detach()
	{
		return Attach(0);
	}

	void Delete()
	{
		assert(m_shader != 0);
		if (m_shader != 0)
		{
			glDeleteShader(Detach());
			m_shader = 0;
		}
	}

private:
	CShaderBase(CShaderBase const&);
	CShaderBase& operator=(CShaderBase const&);

	GLuint m_shader;
};

template <bool t_managed>
class CShaderImpl : public CShaderBase
{
public:
	CShaderImpl(GLuint shader = 0)
		: CShaderBase(shader)
	{
	}

	CShaderImpl& operator=(GLuint shader)
	{
		if (t_managed && (Get() != 0) && (Get() != shader))
		{
			Delete();
		}
		Attach(shader);
		return *this;
	}

	GLuint Create(GLenum type)
	{
		if ((Get() != 0) && t_managed)
		{
			Delete();
		}
		GLuint shader = glCreateShader(type);
		Attach(shader);
		return shader;
	}

	~CShaderImpl(void)
	{
		if (t_managed && (Get() != 0))
		{
			Delete();
		}
	}
};

typedef CShaderImpl<true> CShader;
typedef CShaderImpl<false> CShaderHandle;

class CProgramBase
{
protected:
	CProgramBase(GLuint program = 0)
		: m_program(program)
	{
	}

public:
	operator GLuint() const
	{
		return m_program;
	}

	GLuint Get() const
	{
		return m_program;
	}

	void Delete()
	{
		if (m_program != 0)
		{
			glDeleteProgram(m_program);
			m_program = 0;
		}
	}

	GLuint Attach(GLuint program)
	{
		GLuint tmp = m_program;
		m_program = program;
		return tmp;
	}

	void AttachShader(GLuint shader)
	{
		assert(m_program != 0);
		glAttachShader(m_program, shader);
	}

	void DetachShader(GLuint shader)
	{
		assert(m_program != 0);
		glDetachShader(m_program, shader);
	}

	void Link() const
	{
		assert(m_program);
		glLinkProgram(m_program);
	}

	void Validate() const
	{
		assert(m_program);
		glValidateProgram(m_program);
	}

	void GetInfoLog(GLsizei bufSize, GLsizei* length, GLchar* infoLog) const
	{
		assert(m_program != 0);
		glGetProgramInfoLog(m_program, bufSize, length, infoLog);
	}

	std::string GetInfoLog() const
	{
		GLint length = GetParameter(GL_INFO_LOG_LENGTH);
		if (length > 0)
		{
			std::vector<char> buffer(length);
			GetInfoLog(length, &length, &buffer[0]);
			std::string log(&buffer[0], length - 1);
			return log;
		}
		else
		{
			return std::string();
		}
	}

	void GetParameter(GLenum pname, GLint* param) const
	{
		assert(m_program != 0);
		glGetProgramiv(m_program, pname, param);
	}

	GLint GetUniformLocation(const GLchar* name) const
	{
		assert(m_program);
		return glGetUniformLocation(m_program, name);
	}

	GLint GetAttribLocation(const GLchar* name) const
	{
		assert(m_program);
		return glGetAttribLocation(m_program, name);
	}

	GLuint GetActiveUniforms() const
	{
		return GetParameter(GL_ACTIVE_UNIFORMS);
	}

	GLuint GetActiveAttributes() const
	{
		return GetParameter(GL_ACTIVE_ATTRIBUTES);
	}

	GLuint GetActiveUniformMaxLength() const
	{
		return GetParameter(GL_ACTIVE_UNIFORM_MAX_LENGTH);
	}

	void GetActiveUniform(
		GLuint index, GLsizei maxLength,
		GLsizei* length, GLint* size,
		GLenum* type, GLchar* name) const
	{
		assert(m_program);
		assert(index < GetActiveUniforms());
		glGetActiveUniform(m_program, index, maxLength, length, size, type, name);
	}

	std::string GetActiveUniform(GLuint index, GLint* size, GLenum* type) const
	{
		GLuint bufferLength = GetActiveUniformMaxLength();
		if (!bufferLength)
		{
			return std::string();
		}
		std::vector<char> buffer(bufferLength);
		GLsizei nameLength = 0;

		GetActiveUniform(
			index, bufferLength,
			&nameLength, size,
			type, &buffer[0]);

		return std::string(&buffer[0], &buffer[nameLength]);
	}

	GLuint GetActiveAttributeMaxLength() const
	{
		return GetParameter(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH);
	}

	void GetActiveAttrib(GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLchar* name) const
	{
		assert(m_program);
		assert(index < GetActiveAttributes());
		glGetActiveAttrib(m_program, index, maxLength, length, size, type, name);
	}

	std::string GetActiveAttrib(GLuint index, GLint* size, GLenum* type) const
	{
		GLuint bufferLength = GetActiveAttributeMaxLength();
		if (!bufferLength)
		{
			return std::string();
		}
		std::vector<char> buffer(bufferLength);
		GLsizei nameLength = 0;

		GetActiveAttrib(index, bufferLength, &nameLength, size, type, &buffer[0]);

		return std::string(&buffer[0], &buffer[nameLength]);
	}

	GLint GetParameter(GLenum pname) const
	{
		GLint value = 0;
		GetParameter(pname, &value);
		return value;
	}

	void SetParameter(GLenum pname, GLint value)
	{
		assert(m_program);
		glProgramParameteri(m_program, pname, value);
	}

private:
	CProgramBase(CProgramBase const&);
	CProgramBase& operator=(CProgramBase const&);
	GLuint m_program;
};

template <bool t_managed>
class CProgramImpl : public CProgramBase
{
public:
	CProgramImpl(GLuint program = 0)
		: CProgramBase(program)
	{
	}

	GLuint Create()
	{
		if (t_managed && (Get() != 0))
		{
			Delete();
		}
		GLuint program = glCreateProgram();
		Attach(program);
		return program;
	}

	CProgramImpl& operator=(GLuint program)
	{
		if (t_managed && (Get() != 0) && (Get() != program))
		{
			Delete();
		}

		Attach(program);

		return *this;
	}

	~CProgramImpl()
	{
		if (t_managed && Get() != 0)
		{
			Delete();
		}
	}
};

typedef CProgramImpl<true> CProgram;
typedef CProgramImpl<false> CProgramHandle;

#include "shaderprogram.h"

#include <fstream>


ShaderProgram::ShaderProgram()
{
	program = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
	for (std::vector<GLuint>::iterator it = _shaders.begin(); it != _shaders.end(); ++it)
	{
		glDetachShader(program, *it);
		glDeleteShader(*it);
	}
	glDeleteProgram(program);
}

void ShaderProgram::addShader(GLenum type, std::string file)
{
	GLuint shaderID = loadShader(type, file);
	glAttachShader(program, shaderID);
	_shaders.push_back(shaderID);
}

void ShaderProgram::bindAttribute(int channel, std::string name)
{
	glBindAttribLocation(program, channel, name.c_str());
}

void ShaderProgram::linkProgram()
{
	glLinkProgram(program);
}

void ShaderProgram::programOn()
{
	glUseProgram(program);
}

void ShaderProgram::programOff()
{
	glUseProgram(0);
}


void ShaderProgram::setUniform(std::string uniform, glm::vec2 data)
{
	GLint loc = getUniformLocation(uniform);
	glUniform2fv(loc, 1, &data[0]);
}

void ShaderProgram::setUniform(std::string uniform, glm::vec3 data)
{
	GLint loc = getUniformLocation(uniform);
	glUniform3fv(loc, 1, &data[0]);
}

void ShaderProgram::setUniform(std::string uniform, glm::vec4 data)
{
	GLint loc = getUniformLocation(uniform);
	glUniform4fv(loc, 1, &data[0]);
}

void ShaderProgram::setUniform(std::string uniform, glm::mat4 data)
{
	GLint loc = getUniformLocation(uniform);
	glUniformMatrix4fv(loc, 1, GL_FALSE, &(data[0][0]));
}

void ShaderProgram::setUniform(std::string uniform, int data)
{
	GLint loc = getUniformLocation(uniform);
	glUniform1i(loc, data);
}

void ShaderProgram::setUniform(std::string uniform, float data)
{
	GLint loc = getUniformLocation(uniform);
	glUniform1f(loc, data);
}

GLuint ShaderProgram::getUniformLocation(std::string uniform)
{
	if (_uniforms.count(uniform) == 0)
	{
		_uniforms[uniform] = glGetUniformLocation(program, uniform.c_str());
	}
	return _uniforms[uniform];
}

GLuint ShaderProgram::loadShader(GLenum type, std::string file)
{
	GLuint loadedShader = glCreateShader(type);
	
	std::string shaderCode = "";
	std::ifstream shaderStream(file.c_str());

	std::string line = "";
	while ( std::getline(shaderStream, line) )
	{
		shaderCode += line + "\n";
	}

	shaderStream.close();

	const char* sourcePointer = shaderCode.c_str();
	glShaderSource( loadedShader, 1, &sourcePointer, NULL );

	glCompileShader( loadedShader );

	return loadedShader;
}

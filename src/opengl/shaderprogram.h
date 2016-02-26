#include "GL/glew.h"
#include "glm/glm.hpp"

#include <map>
#include <vector>
#include <string>

class ShaderProgram
{
	public:
		ShaderProgram();
		~ShaderProgram();

		void addShader(GLenum, std::string);
		void bindAttribute(int, std::string);
		void linkProgram();
		void programOn();
		void programOff();

		void setUniform(std::string, glm::vec2);
		void setUniform(std::string, glm::vec3);
		void setUniform(std::string, glm::vec4);
		void setUniform(std::string, glm::mat4);
		void setUniform(std::string, int);
		void setUniform(std::string, float);

	private:
		std::map<std::string, GLuint> _uniforms;
		std::vector<GLuint> _shaders;
		GLuint program;

		GLuint getUniformLocation(std::string);
		GLuint loadShader(GLenum, std::string);
};

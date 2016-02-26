#include "drawable.h"

Drawable::Drawable()
{

}

Drawable::~Drawable()
{
	for(std::map<int, GLuint>::iterator it = _vbo.begin(); it != _vbo.end(); ++it)
	{
		glDeleteBuffers(1, &(it->second));
	}
	glDeleteVertexArrays(1, &_vao);
}

void Drawable::setAttribute(int channel, int amount)
{
	_attrib[channel] = amount;
}

void Drawable::addData(int channel, std::vector<float> data)
{
	_data[channel].insert(_data[channel].end(), data.begin(), data.end());
}

void Drawable::init()
{
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	for (std::map<int, int>::iterator it = _attrib.begin(); it != _attrib.end(); ++it)
	{
		GLuint vbo_id = 0;

		glGenBuffers(1, &vbo_id);
		glBindBuffer(GL_ARRAY_BUFFER, vbo_id);

		glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT)*_data[it->first].size(), &(_data[it->first][0]), GL_STATIC_DRAW);
		glVertexAttribPointer(it->first, it->second, GL_FLOAT, GL_FALSE, it->second * sizeof(GL_FLOAT),	0);

		glEnableVertexAttribArray(it->first);

		_vbo[it->first] = vbo_id;
	}

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Drawable::draw(GLenum mode, int first, int count)
{
	glBindVertexArray(_vao);
	glDrawArrays(mode, first, count);
	glBindVertexArray(0);
}

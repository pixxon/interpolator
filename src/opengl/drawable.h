#include "GL/glew.h"

#include <map>
#include <vector>

class Drawable
{
public:
	Drawable();
	~Drawable();

	void setAttribute(int, int);
	void addData(int, std::vector<float>);
	void init();
	void draw(GLenum, int, int);

private:
	GLuint _vao;
	std::map<int, GLuint> _vbo;
	std::map<int, std::vector<float>> _data;
	std::map<int, int> _attrib;
};
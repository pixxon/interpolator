#include "glm/glm.hpp"

class Camera
{
	public:
		Camera();
		Camera(glm::mat4, glm::mat4, glm::mat4);
		~Camera();

		void setProj(glm::mat4);
		void setView(glm::mat4);
		void setWorld(glm::mat4);

		glm::mat4 getProj();
		glm::mat4 getView();
		glm::mat4 getWorld();
		glm::mat4 getWorldIT();
		glm::mat4 getMVP();
		
	private:
		glm::mat4 _proj;
		glm::mat4 _view;
		glm::mat4 _world;
};
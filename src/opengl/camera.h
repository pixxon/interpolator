#include <QMatrix4x4>
#include <QVector3D>

class Camera
{
	public:
		Camera();
        Camera(QMatrix4x4, QMatrix4x4, QMatrix4x4);
        ~Camera();

        void setProj(QMatrix4x4);
        void setView(QMatrix4x4);
        void setWorld(QMatrix4x4);

        QMatrix4x4 getProj();
        QMatrix4x4 getView();
        QMatrix4x4 getWorld();
        QMatrix4x4 getWorldIT();
        QMatrix4x4 getMVP();

        static QMatrix4x4 lookAt(QVector3D, QVector3D, QVector3D);
        static QMatrix4x4 perspective(float, float, float, float);
		
	private:
        QMatrix4x4 _proj;
        QMatrix4x4 _view;
        QMatrix4x4 _world;
};

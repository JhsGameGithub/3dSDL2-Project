#include <SDL.h>
#include <SDL_main.h>
#include <SDL_opengl.h>
#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <iostream>


//glViewport() == 사물이 그려지는 영역을 설정.
//SDL_GL_CreateContext() == OpenGL과 연결하는 함수. GL기능을 런타임에 로드.
//SDL_GL_SwapWindow() == GL을 이용하여 화면 업데이트를 수행.
//glPushMatrix() == 현재 위치(변환) 정보를 담고 있는 행렬을 스택에 저장.
//glPopMatrix() == 스택에 저장된 행렬 정보를
//↑씬그래프 구조 생각하면 편함.



#define WIDTH 640
#define HEIGHT 540

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1, 0, 0);

	glPushMatrix();
		glTranslated(0.0, 1.2, -6);
		glutSolidSphere(1, 50, 50);
	glPopMatrix();

	glFlush();
}

void changeSize(int w, int h)
{
	if (h == 0)
		h = 1;
	float ratio = 1.0 * w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, -1.0, 0.0f, 1.0f, 0.0f);
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("GLUT Tutorial");
	glutDisplayFunc(renderScene);

	glutReshapeFunc(changeSize);
	glutMainLoop();

	return 0;
}
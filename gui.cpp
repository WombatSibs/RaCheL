#include "gui.h"

int createWindow(void) {
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(1000, 200);
	glutCreateWindow("RaCheL");

	return EXIT_SUCCESS;
}

int destroyWindow() {
	return EXIT_SUCCESS;
}

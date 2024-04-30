
#include "menu.h"


void Menu::Setup()
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	//Menu::hower = (GLubyte*)Texture::getColor(Texture::TextureName::MENU_HOWER);
	//Menu::unhower = (GLubyte*)Texture::getColor(Texture::TextureName::MENU_UNHOWER);

	//Menu::colorPlay = Menu::unhower;
	//Menu::colorLevel = Menu::unhower;
	//Menu::colorQuit = Menu::unhower;
}


void Menu::RenderMenu()
{
	glClear(GL_COLOR_BUFFER_BIT);

	int block_size = Settings::getBlockSize();
	//int width = glutGet(GLUT_WINDOW_WIDTH);
	//int height = glutGet(GLUT_WINDOW_HEIGHT);

	glBegin(GL_QUADS);
	glColor3ub(165, 85, 40);

	//glColor3ubv(Menu::colorPlay);
	glVertex2i(3 * block_size, 7 * block_size);
	glVertex2i(3 * block_size, 9 * block_size);
	glVertex2i(7 * block_size, 9 * block_size);
	glVertex2i(7 * block_size, 7 * block_size);

	//glColor3ubv(Menu::colorPlay);
	glVertex2i(3 * block_size, 4 * block_size);
	glVertex2i(3 * block_size, 6 * block_size);
	glVertex2i(7 * block_size, 6 * block_size);
	glVertex2i(7 * block_size, 4 * block_size);

	//glColor3ubv(Menu::colorPlay);
	glVertex2i(3 * block_size, 1 * block_size);
	glVertex2i(3 * block_size, 3 * block_size);
	glVertex2i(7 * block_size, 3 * block_size);
	glVertex2i(7 * block_size, 1 * block_size);
	glEnd();

	glutSwapBuffers();
}


void Menu::ProcessMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if (x >= 216 && x <= 504)
		{
			if (y >= 135 && y <= 265)
			{
				std::cout << "PLAY" << '\n';
			}

			if (y >= 330 && y <= 460)
			{
				std::cout << "LEVEL" << '\n';
			}

			if (y >= 525 && y <= 655)
			{
				exit(0);
			}

		}
	}

	/*std::cout << "button= " << button << '\n';
	std::cout << "state= " << state << '\n';
	std::cout << "x= " << x << '\n';
	std::cout << "y= " << y << '\n';*/
}


//void Menu::ProcessMotion(int x, int y)
//{
//	if (x >= 216 && x <= 504)
//	{
//		if (y >= 135 && y <= 265)
//		{
//			Menu::colorPlay = Menu::hower;
//		}
//		else
//		{
//			Menu::colorPlay = Menu::unhower;
//		}
//
//		if (y >= 330 && y <= 460)
//		{
//			Menu::colorLevel = Menu::hower;
//		}
//		else
//		{
//			Menu::colorLevel = Menu::unhower;
//		}
//
//		if (y >= 525 && y <= 655)
//		{
//			Menu::colorQuit = Menu::hower;
//		}
//		else
//		{
//			Menu::colorQuit = Menu::unhower;
//		}
//	}
//}
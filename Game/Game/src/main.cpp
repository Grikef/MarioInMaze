
#include <iostream>
#include <gl/freeglut.h>
#include <list>
#include <filesystem>
#include "player.h"
#include "direction.h"
#include "level.h"
#include "txt_file.h"
#include "textures.h"
#include "arbiter.h"


std::list<std::string> levels{};
std::list<std::string> ::iterator currentLevel;

Player* mainActor = new Player();
Level* loadedLevel = new Level();
Matrix map{};
MoveArbiter* mvArbiter = MoveArbiter::getInstance();
int currentScreen = 1;


void RenderGame();
void RenderMenu();
void RenderLevels();
void Setup();
void RerenderingGame(int value);
void RerenderingMenu(int value);
void RerenderingLevels(int value);
void ProcessNormalKeys(unsigned char key, int x, int y);
void ProcessMouseMenu(int button, int state, int x, int y);
void ProcessMouseLevels(int button, int state, int x, int y);
void LoadLevel(bool next, int levelNumber = 0);
void ChangeWindowSize(int width, int height);


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(Settings::getWindowXSize(), Settings::getWindowYSize());
	glutInitWindowPosition(300, 100);
	int game = glutCreateWindow("MarioInMaze");
	glutReshapeFunc(ChangeWindowSize);
	//glutKeyboardFunc(ProcessNormalKeys);
	glutMouseFunc(ProcessMouseMenu);
	glutDisplayFunc(RenderMenu);
	glutTimerFunc(16, RerenderingGame, 0);
	glutTimerFunc(16, RerenderingMenu, 0);
	glutTimerFunc(16, RerenderingLevels, 0);
	Setup();
	glutMainLoop();
	return 0;
}


void RenderGame()
{
	// Окно очищается текущим цветом очистки 
	glClear(GL_COLOR_BUFFER_BIT);

	loadedLevel->display();
	mainActor->display(loadedLevel->getSize());

	// Смена экранов двойной буферизации
	glutSwapBuffers();
}


void RenderMenu()
{
	glClear(GL_COLOR_BUFFER_BIT);

	int block_size = Settings::getBlockSize();
	int mapSize = loadedLevel->getSize();
	double unit = block_size * mapSize / 10.0f;

	/*GLubyte* color = (GLubyte*)Texture::getColor(Texture::TextureName::MENU_START);
	glColor3ubv( color );
	delete color;*/

	glBindTexture(GL_TEXTURE_2D, Texture::TextureName::MENU_START + 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(3.0f * unit, 7.0f * unit);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(3.0f * unit, 9.0f * unit);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(7.0f * unit, 9.0f * unit);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(7.0f * unit, 7.0f * unit);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Texture::TextureName::MENU_LEVEL + 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2i(3 * unit, 4 * unit);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2i(3 * unit, 6 * unit);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2i(7 * unit, 6 * unit);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2i(7 * unit, 4 * unit);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Texture::TextureName::MENU_EXIT + 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2i(3 * unit, 1 * unit);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2i(3 * unit, 3 * unit);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2i(7 * unit, 3 * unit);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2i(7 * unit, 1 * unit);
	glEnd();

	glutSwapBuffers();
}


void RenderLevels()
{
	glClear(GL_COLOR_BUFFER_BIT);

	int block_size = Settings::getBlockSize();
	int mapSize = loadedLevel->getSize();
	double unit = block_size * mapSize / 10.0f;

	glBindTexture(GL_TEXTURE_2D, Texture::TextureName::LEVEL1 + 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(1.0f * unit, 7.0f * unit);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(1.0f * unit, 9.0f * unit);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(3.0f * unit, 9.0f * unit);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(3.0f * unit, 7.0f * unit);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Texture::TextureName::LEVEL2 + 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(4.0f * unit, 7.0f * unit);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(4.0f * unit, 9.0f * unit);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(6.0f * unit, 9.0f * unit);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(6.0f * unit, 7.0f * unit);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Texture::TextureName::LEVEL3 + 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(7.0f * unit, 7.0f * unit);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(7.0f * unit, 9.0f * unit);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(9.0f * unit, 9.0f * unit);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(9.0f * unit, 7.0f * unit);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Texture::TextureName::LEVEL4 + 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(1.0f * unit, 4.0f * unit);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(1.0f * unit, 6.0f * unit);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(3.0f * unit, 6.0f * unit);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(3.0f * unit, 4.0f * unit);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Texture::TextureName::LEVEL5 + 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(4.0f * unit, 4.0f * unit);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(4.0f * unit, 6.0f * unit);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(6.0f * unit, 6.0f * unit);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(6.0f * unit, 4.0f * unit);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Texture::TextureName::LEVEL6 + 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(7.0f * unit, 4.0f * unit);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(7.0f * unit, 6.0f * unit);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(9.0f * unit, 6.0f * unit);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(9.0f * unit, 4.0f * unit);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Texture::TextureName::LEVEL7 + 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(1.0f * unit, 1.0f * unit);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(1.0f * unit, 3.0f * unit);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(3.0f * unit, 3.0f * unit);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(3.0f * unit, 1.0f * unit);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Texture::TextureName::LEVEL8 + 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(4.0f * unit, 1.0f * unit);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(4.0f * unit, 3.0f * unit);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(6.0f * unit, 3.0f * unit);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(6.0f * unit, 1.0f * unit);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Texture::TextureName::LEVEL9 + 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(7.0f * unit, 1.0f * unit);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(7.0f * unit, 3.0f * unit);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(9.0f * unit, 3.0f * unit);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(9.0f * unit, 1.0f * unit);
	glEnd();

	glutSwapBuffers();
}


void Setup()
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	namespace fs = std::filesystem;

	const std::string prefix = fs::current_path().string() + "\\data\\";
	const int levelCount = 9;
	std::string _levels[levelCount]{ prefix + "1.txt", 
									 prefix + "2.txt",
									 prefix + "3.txt",
									 prefix + "4.txt",
									 prefix + "5.txt",
									 prefix + "6.txt",
									 prefix + "7.txt",
									 prefix + "8.txt",
									 prefix + "9.txt"};

	for (int i{ 0 }; i < levelCount; i++)
	{
		if (fs::exists(_levels[i]))
			levels.push_back(_levels[i]);
	}

	Texture::initTextures();

	currentLevel = levels.begin();
	getMatrix(*currentLevel, map);
	loadedLevel->SetMap(map);
	mainActor->setPosition(1, 1);
	mvArbiter->setPlayer(mainActor);
	mvArbiter->setLevel(loadedLevel);
}


void RerenderingGame(int value)
{
	if (currentScreen == 0)
	{
		RenderGame();
	}

	glutTimerFunc(16, RerenderingGame, 0);
}


void RerenderingMenu(int value)
{
	if (currentScreen == 1)
	{
		RenderMenu();
	}

	glutTimerFunc(100, RerenderingMenu, 0);
}


void RerenderingLevels(int value)
{
	if (currentScreen == 2)
	{
		RenderLevels();
	}

	glutTimerFunc(100, RerenderingMenu, 0);
}


void ProcessNormalKeys(unsigned char key, int x, int y) 
{
	switch (key)
	{
		case 27: // esc
		{
			glutDisplayFunc(RenderMenu);
			glutKeyboardFunc(NULL);
			glutMouseFunc(ProcessMouseMenu);
			currentScreen = 1;
			break;
		}

		case 82: // R
		case 114: // r
		case 234: // к
		{
			loadedLevel->Reset();
			mainActor->setPosition(1, 1);
			mainActor->clearBackpack();
			break;
		}

		case 87: // W
		case 119: // w
		case 246: // ц
		{
			mvArbiter->goTo(Direction::UP);
			break;
		}

		case 65: // A
		case 97: // a
		case 244: // ф
		{
			mvArbiter->goTo(Direction::LEFT);
			break;
		}

		case 83: // S
		case 115: // s
		case 251: // ы
		{
			mvArbiter->goTo(Direction::DOWN);
			break;
		}

		case 68: // D
		case 100: // d
		case 226: // в
		{
			mvArbiter->goTo(Direction::RIGHT);
			break;
		}

		default:
		{
			//std::cout << (char)key << "=" << (int)key << '\n';
		}
	}

}


void ProcessMouseMenu(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		int ySize = Settings::getWindowYSize();
		int xUnit = Settings::getWindowXSize() / 10;
		int yUnit = Settings::getWindowYSize() / 11;

		if (x >= 3 * xUnit && x <= 7 * xUnit)
		{
			if (y >= (ySize - 9 * yUnit) && y <= (ySize - 7 * yUnit))
			{
				glutDisplayFunc(RenderGame);
				glutKeyboardFunc(ProcessNormalKeys);
				glutMouseFunc(NULL);
				currentScreen = 0;
			}

			if (y >= (ySize - 6 * yUnit) && y <= (ySize - 4 * yUnit))
			{
				glutDisplayFunc(RenderLevels);
				glutKeyboardFunc(NULL);
				glutMouseFunc(ProcessMouseLevels);
				currentScreen = 2;
			}

			if (y >= (ySize - 3 * yUnit) && y <= (ySize - 1 * yUnit))
			{
				exit(0);
			}

		}
	}
}


void ProcessMouseLevels(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		int ySize = Settings::getWindowYSize();

		int xUnit = Settings::getWindowXSize() / 10;
		int yUnit = Settings::getWindowYSize() / 11;

		if (x >= 1 * xUnit && x <= 3 * xUnit)
		{
			if (y >= (ySize - 3 * yUnit) && y <= (ySize - 1 * yUnit))
			{
				LoadLevel(false, 7);
			}

			if (y >= (ySize - 6 * yUnit) && y <= (ySize - 4 * yUnit))
			{
				LoadLevel(false, 4);
			}

			if (y >= (ySize - 9 * yUnit) && y <= (ySize - 7 * yUnit))
			{
				LoadLevel(false, 1);
			}
		}

		if (x >= 4 * xUnit && x <= 6 * xUnit)
		{
			if (y >= (ySize - 3 * yUnit) && y <= (ySize - 1 * yUnit))
			{
				LoadLevel(false, 8);
			}

			if (y >= (ySize - 6 * yUnit) && y <= (ySize - 4 * yUnit))
			{
				LoadLevel(false, 5);
			}

			if (y >= (ySize - 9 * yUnit) && y <= (ySize - 7 * yUnit))
			{
				LoadLevel(false, 2);
			}
		}

		if (x >= 7 * xUnit && x <= 9 * xUnit)
		{
			if (y >= (ySize - 3 * yUnit) && y <= (ySize - 1 * yUnit))
			{
				glutDisplayFunc(RenderMenu);
				glutMouseFunc(ProcessMouseMenu);
				currentScreen = 1;
			}

			if (y >= (ySize - 6 * yUnit) && y <= (ySize - 4 * yUnit))
			{
				LoadLevel(false, 6);
			}

			if (y >= (ySize - 9 * yUnit) && y <= (ySize - 7 * yUnit))
			{
				LoadLevel(false, 3);
			}
		}

	}
}


void LoadLevel(bool next, int levelNumber)
{
	if (next)
	{
		currentLevel++;
	}
	else
	{
		currentLevel = levels.begin();
		int i = 0;

		while (i < levelNumber - 1 && currentLevel != levels.end())
		{
			currentLevel++;
			i++;
		}
	}

	if (currentLevel == levels.end())
	{
		currentScreen = 1;
		currentLevel = levels.begin();
		glutKeyboardFunc(NULL);
		glutMouseFunc(ProcessMouseMenu);
	}

	getMatrix(*currentLevel, map);
	loadedLevel->SetMap(map);
	mainActor->setPosition(1, 1);
	mainActor->clearBackpack();
	mvArbiter->setLevel(loadedLevel);
	ChangeWindowSize(Settings::getWindowXSize(), Settings::getWindowYSize());

	glutDisplayFunc(RenderGame);
	glutKeyboardFunc(ProcessNormalKeys);
	glutMouseFunc(NULL);
	currentScreen = 0;
}


void ChangeWindowSize(int width, int height)
{
	GLfloat map_size = Settings::getBlockSize() * loadedLevel->getSize();

	// Предотвращает деление на нуль 
	if (height == 0)
	{
		height = 1;
	}

	// Устанавливаем размеры поля просмотра равными размерам окна
	glViewport(0, 0, width, height);

	// Устанавливаем перспективную систему координат 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Устанавливает объем отсечения с помощью отсекающих
	if (width <= height)
	{
		glOrtho(0,														// Left
				map_size,												// Right
				0,														// Bottom
				map_size * height / width + Settings::getBlockSize(),	// Top
				0,														// Near
				map_size												// Far
		);						
	}
	else
	{
		glOrtho(0,														// Left
				map_size * width / height,								// Right
				0,														// Bottom
				map_size + Settings::getBlockSize(),					// Top
				0,														// Near
				map_size												// Far
		);						
	}

	// Обновляется стек матриц проекции модели 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
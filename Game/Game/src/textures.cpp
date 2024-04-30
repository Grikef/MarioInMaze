
#include "textures.h"


// Local files placement
std::string Texture::prefix = std::filesystem::current_path().string() + "\\data\\";


void Texture::initTextures()
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_DECAL);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GLuint* textures = new GLuint[TextureName::ENUM_COUNT];
	glGenTextures(TextureName::ENUM_COUNT, textures);

	std::string file_names[TextureName::ENUM_COUNT];

	file_names[TextureName::FLOOR] = prefix + "floor.jpg";
	file_names[TextureName::WALL] = prefix + "wall.jpg";
	file_names[TextureName::FINISH] = prefix + "finish.png";
	file_names[TextureName::YELLOW_KEY] = prefix + "yellow_key.png";
	file_names[TextureName::GREEN_KEY] = prefix + "green_key.png";
	file_names[TextureName::PLAYER] = prefix + "player.png";
	file_names[TextureName::TELEPORT] = prefix + "teleport.png";
	file_names[TextureName::YELLOW_DOOR] = prefix + "yellow_door.png";
	file_names[TextureName::GREEN_DOOR] = prefix + "green_door.png";
	file_names[TextureName::YELLOW_KEY_IN_BACKPACK] = prefix + "yellow_key_in_backpack.png";
	file_names[TextureName::GREEN_KEY_IN_BACKPACK] = prefix + "green_key_in_backpack.png";
	file_names[TextureName::MENU_START] = prefix + "play.png";
	file_names[TextureName::MENU_LEVEL] = prefix + "level.png";
	file_names[TextureName::MENU_EXIT] = prefix + "quit.png";
	file_names[TextureName::LEVEL1] = prefix + "1.png";
	file_names[TextureName::LEVEL2] = prefix + "2.png";
	file_names[TextureName::LEVEL3] = prefix + "3.png";
	file_names[TextureName::LEVEL4] = prefix + "4.png";
	file_names[TextureName::LEVEL5] = prefix + "5.png";
	file_names[TextureName::LEVEL6] = prefix + "6.png";
	file_names[TextureName::LEVEL7] = prefix + "7.png";
	file_names[TextureName::LEVEL8] = prefix + "8.png";
	file_names[TextureName::LEVEL9] = prefix + "9.png";

	int width{}, height{};
	unsigned char* image{};

	for (int i{ 0 }; i < TextureName::ENUM_COUNT; i++)
	{
		// Bind to next texture object
		glBindTexture(GL_TEXTURE_2D, textures[i]);
		// Set parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		// Load texture
		image = SOIL_load_image(file_names[i].c_str(), &width, &height, 0, SOIL_LOAD_RGBA);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		// Free memory
		SOIL_free_image_data(image);
	}
}


char* Texture::getColor(int id)
{
	char* color {};

	switch (id)
	{
		case TextureName::FLOOR:
		{
			color = new char[3] { (char)128, (char)128, (char)128 };
			break;
		}

		case TextureName::WALL:
		{
			color = new char[3] { (char)60, (char)60, (char)60 };
			break;
		}

		case TextureName::FINISH:
		{
			color = new char[3] { (char)40, (char)165, (char)240 };
			break;
		}

		case TextureName::YELLOW_DOOR:
		{
			color = new char[3] { (char)64, (char)64, (char)16 };
			break;
		}

		case TextureName::GREEN_DOOR:
		{
			color = new char[3] { (char)20, (char)145, (char)80 };
			break;
		}

		case TextureName::YELLOW_KEY:
		{
			color = new char[3] { (char)255, (char)240, (char)0 };
			break;
		}

		case TextureName::GREEN_KEY:
		{
			color = new char[3] { (char)128, (char)0, (char)128 };
			break;
		}

		case TextureName::TELEPORT:
		{
			color = new char[3] { (char)255, (char)255, (char)255 };
			break;
		}

		case TextureName::MENU_START:
		case TextureName::MENU_LEVEL:
		case TextureName::MENU_EXIT:
		case TextureName::LEVEL1:
		case TextureName::LEVEL2:
		case TextureName::LEVEL3:
		case TextureName::LEVEL4:
		case TextureName::LEVEL5:
		case TextureName::LEVEL6:
		case TextureName::LEVEL7:
		case TextureName::LEVEL8:
		case TextureName::LEVEL9:
		{
			color = new char[3] { (char)210, (char)120, (char)55 };
			break;
		}

		default:
		{
			color = new char[3] { (char)255, (char)0, (char)0 };
			break;
		}
	}

	return color;
}
#include "GlutInitializer.h"
#include "Ejik.h"

void Draw()
{
	auto character = Ejik();
	character.Draw(-100, 0);
	character.Draw(100, 0);
	character.Draw(300, 0);
}

int main(int argc, char** argv)
{
	GlutInitializer glutInit = GlutInitializer(argc, argv, Draw);
	return 0;
}
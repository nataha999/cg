#pragma once
class GlutInitializer
{
public:
	GlutInitializer(int argc, char** argv, void (*func)(void));

	~GlutInitializer() = default;
};

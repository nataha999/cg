#pragma once
#include "Smesharik.h"

class Ejik : public Smesharik
{
public:
	Ejik();
	void Draw(float x, float y) const override;
	~Ejik() = default;
};

#pragma once

class Smesharik
{
public:
	virtual void Draw(float x, float y) const = 0;
	virtual ~Smesharik() = default;
};
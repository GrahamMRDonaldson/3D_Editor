#pragma once
struct Color
{
	int r = 100;
	int g = 100;
	int b = 100;
	int a = 255;

	void Normalize()
	{
		if (r > 255)
			r = 255;
		if (g > 255)
			g = 255;
		if (b > 255)
			b = 255;
		if (a > 255)
			a = 255;
		if (r < 0)
			r = 0;
		if (g < 0)
			g = 0;
		if (b < 0)
			b = 0;
		if (a < 0)
			a = 0;
	}

	ImColor GetImColor()
	{
		return ImColor(r / 255.f, g / 255.f, b / 255.f, a / 255.f);
	}

	void operator=(float a[4]) {
		this->r = a[0] * 255;
		this->g = a[1]* 255;
		this->b = a[2]* 255;
		this->a = a[3]* 255;
	}

	void GetFltColr(float* a)
	{
		a[0] = this->r / 255;
		a[1] = this->g / 255;
		a[2] = this->b / 255;
		a[3] = this->a / 255;
	}
};

class Plane
{
private:
	Color led[35]; //5x7
public:
	// ROW COL
	Color& get(int col, int height);
};

class CustomData
{
private:
	Plane planes[5]; // 5 * 5x7
public:
	Color& get(int row, int col, int height);
};

class CustomGui
{
	int CurLayer = 0;
	float CurColor[4];
	int CurPlace[3] = { 0, 0, 0 };


	CustomData data;
public:
	void Main();
	void DrawLayer();
};


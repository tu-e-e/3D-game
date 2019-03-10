#include <stdlib.h>
#include <string.h>
#include "fstream"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include "iostream"
#include "C:\Users\Igel\documents\visual studio 2015\Projects\3d-2\3d-2\void.h"
#define pi 3.14159265359
#define pi2 6.28318530718

void generate_land1(int pox[3],int groﬂe2,int steigung) {
	float x, y;
	int g = 0,h = 5;
	int drin = 0,ein = 0,drin2 = 0;
	//craet cegel
	for (size_t j = 0; j < groﬂe2; j++)
	{
		//g++;
		for (size_t k = 0; k < steigung; k++)
		{
		h--;
		for (float i = 0; i < pi2; i = i + 0.01)
		{
			x = sin(i);
			y = cos(i);
			World[(int)(pox[0] + (x * j))][(pox[1] + h)][(int)((pox[2] + y * j))] = 2;		
		}
			
		}
	}
	//fill cegel
	for (size_t y = (groﬂe2 - pox[1]); y < (groﬂe2 + pox[1]); y++)
	{
		for (size_t k = 0; k < steigung; k++)
		{
			for (size_t x = (pox[0] - groﬂe2); x < (groﬂe2 + pox[2]); x++)
			{
				drin = 0;
				ein = 0;
				for (size_t z = (pox[2] - groﬂe2); z < (groﬂe2 + pox[0]); z++)
				{
					std::cout << "d = " << drin << "\n";

					if (drin == 1)
					{
						if (World[x][y][z] > 0)drin = 0;
						else World[x][y][z] = 1;
					}
					if ((World[x][y][z] > 0) && (ein == 0)) { drin = 1; ein = 1; }
				}
				if (drin == 1)
					for (size_t i = (pox[2] - groﬂe2); i < (groﬂe2 + pox[0]); i++)
					{
						if (drin2 == 1)World[x][y][i] = 0;
						if (World[x][y][i] > 0)drin2 = 1;
					}
				drin2 = 0;
			}
		}
	}
}

void generate_land()
{
	int pox_berg[5][3] = { {20,10,10},{64,10,20},{40,10,13} };
	
	
	for (size_t y = 0; y < 32; y++)
	{
		for (size_t x = 0; x < 264; x++)
		{
			for (size_t z = 0; z < 264; z++)
			{
				World[x][y][z] = 1;
			}
		}
	}
	for (size_t y = 32; y < 34; y++)
	{
		for (size_t x = 0; x < 264; x++)
		{
			for (size_t z = 0; z < 264; z++)
			{
				World[x][y][z] = 2;
			}
		}
	}


	for (size_t i = 0; i < 3; i++)
	{
		generate_land1(pox_berg[i], (i*10), i);
	}
}
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

static GLubyte ImageGras1[5][5][4]; /*= { { { 000,072,000,255 },{ 000,057,000,255 },{ 044,072,000,255 },{ 000,057,000,255 },{ 000,072,000,255 },{ 000,057,000,255 },{ 044,072,000,255 },{ 000,057,000,255 } },{ { 000,057,000,255 },{ 000000,072,000,255 },{ 000,057,000,255 },{ 044,072,000,255 },{ 000,057,000,255 },{ 000,072,000,255 },{ 000,057,000,255 },{ 000000,072,000,255 } },{ { 000000,072,000,255 },{ 000,057,000,255 },{ 000,072,000,255 },{ 000,057,000,255 },{ 000,057,000,255 },{ 000,046,000,255 },{ 000,046,000,255 },{ 000,046,000,255 } },{ { 000,057,000,255 },{ 044,072,000,255 },{ 000,046,000,255 },{ 000,046,000,255 },{ 000,072,000,255 },{ 000,072,000,255 },{ 000,057,000,255 },{ 000,072,000,255 } },{ { 000,057,000,255 },{ 000,046,000,255 },{ 000,057,000,255 },{ 000,057,000,255 },{ 000,072,000,255 },{ 000,057,000,255 },{ 000,072,000,255 },{ 000,057,000,255 } },{ { 000,046,000,255 },{ 000,072,000,255 },{ 000,057,000,255 },{ 044,072,000,255 },{ 000,057,000,255 },{ 000,046,000,255 },{ 000,057,000,255 },{ 000,072,000,255 } },{ { 000,072,000,255 },{ 000,057,000,255 },{ 000,072,000,255 },{ 000,057,000,255 },{ 000,046,000,255 },{ 000,057,000,255 },{ 000,057,000,255 },{ 000,046,000,255 } },{ { 000,057,000,255 },{ 000,072,000,255 },{ 000,057,000,255 },{ 000,072,000,255 },{ 000,057,000,255 },{ 000,072,000,255 },{ 000,072,000,255 },{ 000,057,000,255 } } };*/
static GLuint texGras1;
static GLuint texGrasf1;

static GLubyte ImageGras2[5][5][4]; /*= { { { 030,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 036,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 } },{ { 022,007,000,255 },{ 022,007,000,255 },{ 036,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 036,014,000,255 } },{ { 022,007,000,255 },{ 030,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 030,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 } },{ { 032,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 036,014,000,255 },{ 022,007,000,255 } },{ { 022,007,000,255 },{ 014,044,000,255 },{ 036,014,000,255 },{ 030,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 014,044,000,255 } },{ { 036,014,000,255 },{ 014,034,000,255 },{ 022,007,000,255 },{ 0,044,000,255 },{ 022,007,000,255 },{ 014,034,000,255 },{ 014,044,000,255 },{ 032,014,000,255 } },{ { 014,034,000,255 },{ 014,034,000,255 },{ 00,044,000,255 },{ 014,034,000,255 },{ 014,034,000,255 },{ 014,034,000,255 },{ 000,044,000,255 },{ 014,034,000,255 } },{ { 014,034,000,255 },{ 014,044,000,255 },{ 014,034,000,255 },{ 014,034,000,255 },{ 014,044,000,255 },{ 014,034,000,255 },{ 014,034,000,255 },{ 014,034,000,255 } } };*/
static GLuint texGras2;
static GLubyte ImageGras3[5][5][4]; /*= { { { 036,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 036,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 } },{ { 022,007,000,255 },{ 022,007,000,255 },{ 036,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 036,014,000,255 } },{ { 022,007,000,255 },{ 030,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 030,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 } },{ { 032,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 036,014,000,255 },{ 022,007,000,255 } },{ { 022,007,000,255 },{ 022,007,000,255 },{ 036,014,000,255 },{ 030,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 } },{ { 036,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 036,014,000,255 },{ 022,007,000,255 },{ 032,014,000,255 } },{ { 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 036,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 022,007,000,255 } },{ { 022,007,000,255 },{ 022,007,000,255 },{ 036,014,000,255 },{ 022,007,000,255 },{ 022,007,000,255 },{ 030,014,000,255 },{ 036,014,000,255 },{ 022,007,000,255 } } };*/
static GLuint texGras3;

static GLubyte ImageStone1[8][8][4] = { { { 034,034,034,255 },{ 044,044,044,255 },{ 024,024,024,255 },{ 044,044,044,255 },{ 034,034,034,255 },{ 034,034,034,255 },{ 044,044,044,255 },{ 034,034,034,255 } },{ { 036,036,036,255 },{ 034,034,034,255 },{ 034,034,034,255 },{ 034,034,034,255 },{ 036,036,036,255 },{ 036,036,036,255 },{ 034,034,034,255 },{ 024,024,024,255 } },{ { 034,034,034,255 },{ 036,036,036,255 },{ 044,044,044,255 },{ 034,034,034,255 },{ 044,044,044,255 },{ 036,036,036,255 },{ 044,044,044,255 },{ 044,044,044,255 } },{ { 044,044,044,255 },{ 034,034,034,255 },{ 036,036,036,255 },{ 024,024,024,255 },{ 034,034,034,255 },{ 036,036,036,255 },{ 034,034,034,255 },{ 024,024,024,255 } },{ { 034,034,034,255 },{ 017,017,017,255 },{ 034,034,034,255 },{ 034,034,034,255 },{ 044,044,044,255 },{ 034,034,034,255 },{ 017,017,017,255 },{ 034,034,034,255 } },{ { 044,044,044,255 },{ 034,034,034,255 },{ 044,044,044,255 },{ 036,036,036,255 },{ 034,034,034,255 },{ 044,044,044,255 },{ 044,044,044,255 },{ 034,034,034,255 } },{ { 044,044,044,255 },{ 034,034,034,255 },{ 044,044,044,255 },{ 034,034,034,255 },{ 024,024,024,255 },{ 044,044,044,255 },{ 034,034,034,255 },{ 017,017,017,255 } },{ { 034,034,034,255 },{ 024,024,024,255 },{ 044,044,044,255 },{ 017,017,017,255 },{ 034,034,034,255 },{ 034,034,034,255 },{ 024,024,024,255 },{ 034,034,034,255 } } };
static GLuint texStone1;

static GLubyte Imageofen1[8][8][4] = { { { 016,016,016,255 },{ 016,016,016,255 },{ 016,016,016,255 },{ 016,016,016,255 },{ 016,016,016,255 },{ 016,016,016,255 },{ 016,016,016,255 },{ 016,016,016,255 } },{ { 016,016,016,255 },{ 012,012,012,255 },{ 007,007,007,255 },{ 007,007,007,255 },{ 007,007,007,255 },{ 007,007,007,255 },{ 012,012,012,255 },{ 016,016,016,255 } },{ { 016,016,016,255 },{ 007,007,007,255 },{ 072,042,000,255 },{ 072,042,000,255 },{ 072,042,000,255 },{ 072,042,000,255 },{ 007,007,007,255 },{ 016,016,016,255 } },{ { 016,016,016,255 },{ 007,007,007,255 },{ 072,042,000,255 },{ 072,042,000,255 },{ 126,042,000,255 },{ 072,042,000,255 },{ 007,007,007,255 },{ 016,016,016,255 } },{ { 016,016,016,255 },{ 007,007,007,255 },{ 126,042,000,255 },{ 046,007,000,255 },{ 126,042,000,255 },{ 126,042,000,255 },{ 007,007,007,255 },{ 016,016,016,255 } },{ { 016,016,016,255 },{ 007,007,007,255 },{ 046,007,000,255 },{ 046,007,000,255 },{ 046,007,000,255 },{ 046,007,000,255 },{ 007,007,007,255 },{ 016,016,016,255 } },{ { 016,016,016,255 },{ 012,012,012,255 },{ 007,007,007,255 },{ 007,007,007,255 },{ 007,007,007,255 },{ 007,007,007,255 },{ 012,012,012,255 },{ 016,016,016,255 } },{ { 016,016,016,255 },{ 016,016,016,255 },{ 016,016,016,255 },{ 016,016,016,255 },{ 016,016,016,255 },{ 016,016,016,255 },{ 016,016,016,255 },{ 016,016,016,255 } } };
static GLuint texofen1;

static GLubyte Imagezenti1[8][8][4] = { { { 016,016,016,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 016,016,016,255 } },{ { 027,027,027,255 },{ 027,027,027,255 },{ 016,016,016,255 },{ 016,016,016,255 },{ 016,016,016,255 },{ 016,016,016,255 },{ 027,027,027,255 },{ 027,027,027,255 } },{ { 027,027,027,255 },{ 016,016,016,255 },{ 000,046,060,255 },{ 000,046,060,255 },{ 000,046,060,255 },{ 000,046,060,255 },{ 016,016,016,255 },{ 027,027,027,255 } },{ { 027,027,027,255 },{ 016,016,016,255 },{ 000,040,060,255 },{ 000,046,060,255 },{ 000,040,060,255 },{ 000,040,060,255 },{ 016,016,016,255 },{ 027,027,027,255 } },{ { 027,027,027,255 },{ 016,016,016,255 },{ 000,027,060,255 },{ 000,040,060,255 },{ 000,027,060,255 },{ 000,027,060,255 },{ 016,016,016,255 },{ 027,027,027,255 } },{ { 027,027,027,255 },{ 016,016,016,255 },{ 000,027,060,255 },{ 000,027,060,255 },{ 000,027,060,255 },{ 000,027,060,255 },{ 016,016,016,255 },{ 027,027,027,255 } },{ { 027,027,027,255 },{ 027,027,027,255 },{ 016,016,016,255 },{ 016,016,016,255 },{ 016,016,016,255 },{ 016,016,016,255 },{ 027,027,027,255 },{ 027,027,027,255 } },{ { 016,016,016,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 016,016,016,255 } } };
static GLuint texzenti1;
static GLubyte Imagezenti2[8][8][4] = { { { 016,016,016,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 016,016,016,255 } },{ { 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 } },{ { 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 } },{ { 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 } },{ { 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 } },{ { 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 } },{ { 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 } },{ { 016,016,016,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 027,027,027,255 },{ 016,016,016,255 } } };
static GLuint texzenti2;

static GLuint texdefult1;
static GLuint texdefult2;
static GLuint texdefult3;
static GLuint texdefult4;
static GLuint texdefult5;
static GLuint texdefult6;

static GLuint centrifuge1;
static GLuint centrifuge2;
static GLuint centrifuge3;
static GLuint centrifuge4;
static GLuint centrifuge5;
static GLuint centrifuge6;


static GLuint oven1;
static GLuint oven2;
static GLuint oven3;
static GLuint oven4;
static GLuint oven5;
static GLuint oven6;

//////////////////////////////////////////////////////////////////////////////////////////////

int p_h_r[10], p_w_r[10];
int p_h, p_w;

int wert_RGB[99999];
int d = 1;
int bild_data[10][10][3];




/*int lode_bild2(char *file_name)
{
	long int za[10] = { 0,0,0,0,0,0,0,0,0,0 };

	int wert_RGB_r[3];

	using namespace std;
	ifstream Quelldatei;                          // neuen Lese-Stream erzeugen
	Quelldatei.open(file_name, ios_base::in);      // Datei_1.txt öffnen
	long int i = 0;
	if (!Quelldatei)                              // Fehler beim Öffnen?
		std::cout << "Feler";
	
	else {                                      // falls es funktioniert hat 
		char c;
		char file_data[20000];   // maximale Länge der Datei angeben
		

		while (Quelldatei.get(c))
		{
			file_data[i] = c;
			i++;
		}

		for (int file_zeiger = 0; file_zeiger < i; file_zeiger++)
		{
			if (file_data[file_zeiger] == '\n') {
				file_zeiger++;
				
						std::cout << "a" << "\n";
						for (file_zeiger; file_zeiger < i; file_zeiger++)
						{
							if (file_data[file_zeiger] == ' ')
							{
								p_h_r[5] = za[1];
								za[2] = 1;
								za[1] = 0;
							}
							else
							{
								if (za[2] == 0)
								{
									//std::cout << "b" << "\n";
									p_h_r[za[1]] = (file_data[file_zeiger] - 48);
									za[1]++;
								}
								else
								{
									//std::cout << "c" << "\n";
									p_w_r[za[1]] = (file_data[file_zeiger] - 48);
									za[1]++;
								}

								if (file_data[file_zeiger] == '\n') {
									file_zeiger++;
									za[1]--;
									p_w_r[5] = za[1];

									//std::cout << "d" << "\n";

									for (file_zeiger; file_zeiger < i; file_zeiger++)
									{
										if (file_data[file_zeiger] == '\n')
										{
											//std::cout << "e" << "\n";
											za[8]++;
											switch (za[5])
											{
											case 1:
												wert_RGB[za[7]] = wert_RGB_r[0];
												break;
											case 2:
												wert_RGB[za[7]] = ((wert_RGB_r[0] * 10) + wert_RGB_r[1]);
												break;
											case 3:
												wert_RGB[za[7]] = (((wert_RGB_r[0] * 100) + (wert_RGB_r[1] * 10)) + wert_RGB_r[2]);
												break;
											}
											za[7]++;
											za[5] = 0;
										}


										else
										{
											wert_RGB_r[za[5]] = (file_data[file_zeiger] - 48);
											za[5]++;
										}
									}
								}
							}
						}
					}
				}
			}
		

	switch (p_w_r[5])
	{
	case 1:
		p_w = p_w_r[0];
		break;
	case 2:
		p_w = ((p_w_r[0] * 10) + p_w_r[1]);
		break;
	case 3:
		p_w = (((p_w_r[0] * 100) + (p_w_r[1] * 10)) + p_w_r[2]);
		break;
	}

	switch (p_h_r[5])
	{
	case 1:
		p_h = p_h_r[0];
		break;
	case 2:
		p_h = ((p_h_r[0] * 10) + p_h_r[1]);
		break;
	case 3:
		p_h = (((p_h_r[0] * 100) + (p_h_r[1] * 10)) + p_h_r[2]);
		break;
	}
	//std::cout << za[8];
	//std::cout << "::"<< i;
	return za[8];
}
int Image_bild_qad1(char *file_namea)
{
	static GLubyte Imagedefult[16][16][4];
	static GLuint texdefult;
	
	if (lode_bild(file_namea) == ((p_h * p_w) * 3))
	{
		for (int x = 0; x < p_w; x++)
		{
			for (int y = 0; y < p_h; y++)
			{
				for (int RGB = 0; RGB < 3; RGB++)
				{
					Imagedefult[x][y][RGB] = wert_RGB[d];
					d++;
				}
			}
		}
		d = 1;
		for (int x = 0; x < p_w; x++)
		{
			for (int y = 0; y < p_h; y++)
			{
				Imagedefult[x][y][3] = 255;
			}
		}
	}
	else
	{
		std::cout << "nicht ausreichnt Pixel" << "\n";
	}

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(1, &texdefult);
	glBindTexture(GL_TEXTURE_2D, texdefult);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, p_w, p_h, 0, GL_RGBA, GL_UNSIGNED_BYTE,Imagedefult);

	return texdefult;
}
void Image_bild_recht2(char *file_namea,int x,int y)
{
	static GLubyte Imagedefult[16][16][4];
	static GLubyte Imagedefult1[16][16][4];
	static GLubyte Imagedefult2[16][16][4];
	static GLubyte Imagedefult3[16][16][4];
	static GLubyte Imagedefult4[16][16][4];
	static GLubyte Imagedefult5[16][16][4];
	
	
	lode_bild(file_namea);
	
		
		for (int y1 = 0; y1 < p_h; y1++)
		{
			for (int x1 = 0; x1 < p_w; x1++)
			{
				for (int RGB = 0; RGB < 3; RGB++)
				{

					if (y1 <= y)
					{
						if ((x1 >= 0) && (x1 <= x))      Imagedefult[x1][y1][RGB] = wert_RGB[d];
						//if ((x1 >= x) && (x1 <= (x * 2)))Imagedefult1[x1][y1][RGB] = wert_RGB[d];
						//if ((x1 >= (x * 2)) && (x1 <= (x * 3)))Imagedefult2[x1][y1][RGB] = wert_RGB[d];
					}
					else
					{
						//if ((x1 >= 0) && (x1 <= x))      Imagedefult3[x1][y1][RGB] = wert_RGB[d];
						//if ((x1 >= x) && (x1 <= (x * 2)))Imagedefult4[x1][y1][RGB] = wert_RGB[d];
						//if ((x1 >= (x * 2)) && (x1 <= (x * 3)))Imagedefult5[x1][y1][RGB] = wert_RGB[d];
					}
					
					
					
					d++;
				}
			}
		}
		d = 1;
		/////////////////////////////////////////////////////////////////////////
		
		int debag_za[6] = {0,0,0,0,0,0};

		for (int y1 = 0; y1 < p_w; y1++)
		{
			for (int x1 = 0; x1 < p_h; x1++)
			{
				for (int RGB = 0; RGB < 3; RGB++)
				{

					if (y1 <= y)
					{
						if ((x1 >= 0)		&& (x1 <= x))		debag_za[0]++;
						if ((x1 >= x)		&& (x1 <= (x * 2)))	debag_za[1]++;
						if ((x1 >= (x * 2)) && (x1 <= (x * 3)))	debag_za[2]++;
					}
					else
					{
						if ((x1 >= 0)		&& (x1 <= x))		debag_za[3]++;
						if ((x1 >= x)		&& (x1 <= (x * 2))) debag_za[4]++;
						if ((x1 >= (x * 2)) && (x1 <= (x * 3))) debag_za[5]++;
					}

					

					d++;
				}
			}
		}
		std::cout << "1 = " << debag_za[0] << "\n" << "2 = " << debag_za[1] << "\n" << "3 = " << debag_za[2] << "\n" << "4 = " << debag_za[3] << "\n" << "5 = " << debag_za[4] << "\n" << "6 = " << debag_za[5] << "\n" << "insgsamt(g) = " << d << "\n";
		///////////////////////////////////////////////////////////////////////////////////////////////
		
		for (int x = 0; x < p_w; x++)
		{
			for (int y = 0; y < p_h; y++)
			{
				Imagedefult[x][y][3] = 255;
			}
		}
		for (int x = 0; x < p_w; x++)
		{
			for (int y = 0; y < p_h; y++)
			{
				Imagedefult1[x][y][3] = 255;
			}
		}
		for (int x = 0; x < p_w; x++)
		{
			for (int y = 0; y < p_h; y++)
			{
				Imagedefult2[x][y][3] = 255;
			}
		}
		for (int x = 0; x < p_w; x++)
		{
			for (int y = 0; y < p_h; y++)
			{
				Imagedefult3[x][y][3] = 255;
			}
		}
		for (int x = 0; x < p_w; x++)
		{
			for (int y = 0; y < p_h; y++)
			{
				Imagedefult4[x][y][3] = 255;
			}
		}
		for (int x = 0; x < p_w; x++)
		{
			for (int y = 0; y < p_h; y++)
			{
				Imagedefult5[x][y][3] = 255;
			}
		}
		
		
		
		glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	
	glGenTextures(1, &texdefult1);
	glBindTexture(GL_TEXTURE_2D, texdefult1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult);


	glGenTextures(1, &texdefult2);
	glBindTexture(GL_TEXTURE_2D, texdefult2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult1);


	glGenTextures(1, &texdefult3);
	glBindTexture(GL_TEXTURE_2D, texdefult3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult2);


	glGenTextures(1, &texdefult4);
	glBindTexture(GL_TEXTURE_2D, texdefult4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult3);


	glGenTextures(1, &texdefult5);
	glBindTexture(GL_TEXTURE_2D, texdefult5);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult4);


	glGenTextures(1, &texdefult6);
	glBindTexture(GL_TEXTURE_2D, texdefult6);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult5);
}
void Image_bild_recht1(char *file_namea, int x, int y)
{
	static GLubyte Imagedefult[16][16][4];
	static GLubyte Imagedefult1[16][16][4];
	lode_bild(file_namea);
	d = 1;
	for (int y1 = 0; y1 < 16; y1++)
	{
		for (int x1 = 0; x1 < 16; x1++)
		{
			for (int RGB = 0; RGB < 3; RGB++)
			{
				Imagedefult[x1][y1][RGB] = wert_RGB[d];
				d++;
			}
			Imagedefult[x1][y1][3] = 255;
			//std::cout << "d = " << d << "\n";	
		}
		d = (p_w * (y1 + 1)) + (y1 - 1);
	}
	//d = 1;
	for (int y1 = 0; y1 < 16; y1++)
	{
		for (int x1 = 0; x1 < 16; x1++)
		{
			for (int RGB = 0; RGB < 3; RGB++)
			{
				Imagedefult1[x1][y1][RGB] = wert_RGB[d];
				d++;
			}
			Imagedefult1[x1][y1][3] = 255;
			//std::cout << "d = " << d << "\n";	
		}
		d = (p_w * ((y1 + 1) + 15)) + (y1 - 1);
	}
	
	
	/////////////////////////////////////////////////////////////////////////

	
	
	



	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(1, &texdefult1);
	glBindTexture(GL_TEXTURE_2D, texdefult1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult);

	glGenTextures(1, &texdefult2);
	glBindTexture(GL_TEXTURE_2D, texdefult2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult1);

}
void Image_bild_recht3(char *file_namea, int x, int y)
{
	static GLubyte Imagedefult[48][32][4];
	if (lode_bild(file_namea) == ((p_h * p_w) * 3))
	{
		for (int x = 0; x < p_w; x++)
		{
			for (int y = 0; y < p_h; y++)
			{
				for (int RGB = 0; RGB < 3; RGB++)
				{
					Imagedefult[x][y][RGB] = wert_RGB[d];
					d++;
				}
			}
		}
		d = 1;
		for (int x = 0; x < p_w; x++)
		{
			for (int y = 0; y < p_h; y++)
			{
				Imagedefult[x][y][3] = 255;
			}
		}
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glShadeModel(GL_FLAT);
		glEnable(GL_DEPTH_TEST);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &texdefult1);
		glBindTexture(GL_TEXTURE_2D, texdefult1);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, p_h, p_w, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult);
	}
	else
	{
		std::cout << "nicht ausreichnt Pixel" << "\n";
	}
}
int Image_bild1(char *file_name) {
	lode_bild(file_name);
	if (p_w == p_h) { 
		return Image_bild_qad(file_name); 
	}
	else
	{
		
		std::cout << "LODER " << p_w << "::"<< p_h;
		int i = 0;
		int xp = 10000, yp;
		/*for (i; i < 260;i++)
		{
			if ((p_w == 3 * i) && (p_h == 2 * i)) {
				i = 260;
				xp = i,yp= i;
			}
		}*
		
	
		if(((p_w / 3) == (p_h / 2)) || ((p_h / 3) == (p_w / 2)))
		{
			xp = (p_h / 3);
			yp = (p_w / 2);
			
			std::cout << "loder 10";
			Image_bild_recht(file_name,xp,yp);
			;
		}
		else
		{
			std::cout << "EROR 10";
		}
	}
}*/

int Texture::loud(char *file_name)
{
	long int za[10] = { 0,0,0,0,0,0,0,0,0,0 };

	int wert_RGB_r[3];

	using namespace std;
	ifstream Quelldatei;                          // neuen Lese-Stream erzeugen
	Quelldatei.open(file_name, ios_base::in);      // Datei_1.txt öffnen
	long int i = 0;
	char file_data[200000];   // maximale Länge der Datei angeben
	if (!Quelldatei)                              // Fehler beim Öffnen?
		std::cout << "Feler";
	else {                                      // falls es funktioniert hat 
		char c;
		


		while (Quelldatei.get(c))
		{
			file_data[i] = c;
			i++;
		}

		for (int file_zeiger = 0; file_zeiger < i; file_zeiger++)
		{
			if (file_data[file_zeiger] == '\n') {
				file_zeiger++;


				for (file_zeiger; file_zeiger < i; file_zeiger++)
				{
					if (file_data[file_zeiger] == ' ')
					{
						p_h_r[5] = za[1];
						za[2] = 1;
						za[1] = 0;
					}
					else
					{
						if (za[2] == 0)
						{

							p_h_r[za[1]] = (file_data[file_zeiger] - 48);
							za[1]++;
						}
						else
						{

							p_w_r[za[1]] = (file_data[file_zeiger] - 48);
							za[1]++;
						}

						if (file_data[file_zeiger] == '\n') {
							file_zeiger++;
							za[1]--;
							p_w_r[5] = za[1];



							for (file_zeiger; file_zeiger < i; file_zeiger++)
							{
								if (file_data[file_zeiger] == '\n')
								{

									za[8]++;
									switch (za[5])
									{
									case 1:
										wert_RGB[za[7]] = wert_RGB_r[0];
										break;
									case 2:
										wert_RGB[za[7]] = ((wert_RGB_r[0] * 10) + wert_RGB_r[1]);
										break;
									case 3:
										wert_RGB[za[7]] = (((wert_RGB_r[0] * 100) + (wert_RGB_r[1] * 10)) + wert_RGB_r[2]);
										break;
									}
									za[7]++;
									za[5] = 0;
								}


								else
								{
									wert_RGB_r[za[5]] = (file_data[file_zeiger] - 48);
									za[5]++;
								}
							}
						}
					}
				}
			}
		}
	}


	switch (p_w_r[5])
	{
	case 1:
		p_w = p_w_r[0];
		break;
	case 2:
		p_w = ((p_w_r[0] * 10) + p_w_r[1]);
		break;
	case 3:
		p_w = (((p_w_r[0] * 100) + (p_w_r[1] * 10)) + p_w_r[2]);
		break;
	}

	switch (p_h_r[5])
	{
	case 1:
		p_h = p_h_r[0];
		break;
	case 2:
		p_h = ((p_h_r[0] * 10) + p_h_r[1]);
		break;
	case 3:
		p_h = (((p_h_r[0] * 100) + (p_h_r[1] * 10)) + p_h_r[2]);
		break;
	}
	return za[8];
}
int Image_bild_qad(char *file_namea)
{
	static GLubyte Imagedefult[16][16][4];
	static GLuint texdefult;
	Texture Texture;
	if (Texture.loud(file_namea) == ((p_h * p_w) * 3))
	{
		for (int x = 0; x < p_w; x++)
		{
			for (int y = 0; y < p_h; y++)
			{
				for (int RGB = 0; RGB < 3; RGB++)
				{
					Imagedefult[x][y][RGB] = wert_RGB[d];
					d++;
				}
			}
		}
		d = 1;
		for (int x = 0; x < p_w; x++)
		{
			for (int y = 0; y < p_h; y++)
			{
				Imagedefult[x][y][3] = 255;
			}
		}
	}
	else
	{
		std::cout << "nicht ausreichnt Pixel" << "\n";
	}

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(1, &texdefult);
	glBindTexture(GL_TEXTURE_2D, texdefult);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, p_w, p_h, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult);

	return texdefult;
}
void Image_bild_recht(char *file_namea, int x, int y)
{
	static GLubyte Imagedefult[32][48][4];
	static GLubyte Imagedefult_end1[16][16][4];
	static GLubyte Imagedefult_end2[16][16][4];
	static GLubyte Imagedefult_end3[16][16][4];
	static GLubyte Imagedefult_end4[16][16][4];
	static GLubyte Imagedefult_end5[16][16][4];
	static GLubyte Imagedefult_end6[16][16][4];

	//std::cout << "\n" << "x = " << x << " :: y = " << y;

	int Imagedefult_r[32][48][4];
	Texture Texture;
	Texture.loud(file_namea);

	for (int y1 = ((y * 2) - 1); y1 > -1; y1--)
	{
		for (int x1 = 0; x1 < (x * 3); x1++)
		{
			for (int RGB = 0; RGB < 3; RGB++)
			{
				Imagedefult[y1][x1][RGB] = wert_RGB[d];
				Imagedefult_r[y1][x1][RGB] = wert_RGB[d];
				d++;
			}
			//std::cout << "d = " << d << "\n";
			Imagedefult[y1][x1][3] = 255;
		}
		//d = (p_w * (y1 + 1)) + (y1 + 2);
	}
	d = 1;

	for (int y1 = 0; y1 < x; y1++)
	{
		for (int x1 = 0; x1 < y; x1++)
		{
			for (int RGB = 0; RGB < 3; RGB++)
			{

				Imagedefult_end1[y1][x1][RGB] = Imagedefult_r[y1][x1][RGB];

			}
			Imagedefult_end1[y1][x1][3] = 255;
		}
	}
	for (int y1 = 0; y1 < y; y1++)
	{
		for (int x1 = x; x1 < (x * 2); x1++)
		{
			for (int RGB = 0; RGB < 3; RGB++)
			{

				Imagedefult_end2[(y1 + -1)][x1][RGB] = Imagedefult_r[(y1)][x1][RGB];

			}
			Imagedefult_end2[(y1 + -1)][x1][3] = 255;
		}
	}
	for (int y1 = 0; y1 < y; y1++)
	{
		for (int x1 = (x * 2); x1 < (x * 3); x1++)
		{
			for (int RGB = 0; RGB < 3; RGB++)
			{

				Imagedefult_end3[(y1 + -2)][x1][RGB] = Imagedefult_r[(y1)][x1][RGB];

			}
			Imagedefult_end3[(y1 + -2)][x1][3] = 255;
		}
	}
	////////////////////////////////////////////////////////////////////

	for (int y1 = y; y1 < (y * 2); y1++)
	{
		for (int x1 = 0; x1 < x; x1++)
		{
			for (int RGB = 0; RGB < 3; RGB++)
			{
				Imagedefult_end4[(y1 - 16)][x1][RGB] = Imagedefult_r[y1][x1][RGB];
			}
			Imagedefult_end4[(y1 - 16)][x1][3] = 255;
		}
	}

	for (int y1 = y; y1 < (y * 2); y1++)
	{
		for (int x1 = x; x1 < (x * 2); x1++)
		{
			for (int RGB = 0; RGB < 3; RGB++)
			{

				Imagedefult_end5[(y1 - 17)][x1][RGB] = Imagedefult_r[(y1)][x1][RGB];

			}
			Imagedefult_end5[(y1 - 17)][x1][3] = 255;
		}
	}

	for (int y1 = y; y1 < (y * 2); y1++)
	{
		for (int x1 = (x * 2); x1 < (x * 3); x1++)
		{
			for (int RGB = 0; RGB < 3; RGB++)
			{

				Imagedefult_end6[(y1 - 18)][x1][RGB] = Imagedefult_r[(y1)][x1][RGB];

			}
			Imagedefult_end6[(y1 - 18)][x1][3] = 255;
		}
	}




	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(1, &texdefult1);
	glBindTexture(GL_TEXTURE_2D, texdefult1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 16, 16, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult_end1);

	glGenTextures(1, &texdefult2);
	glBindTexture(GL_TEXTURE_2D, texdefult2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 16, 16, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult_end2);

	glGenTextures(1, &texdefult3);
	glBindTexture(GL_TEXTURE_2D, texdefult3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 16, 16, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult_end3);

	glGenTextures(1, &texdefult4);
	glBindTexture(GL_TEXTURE_2D, texdefult4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 16, 16, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult_end4);

	glGenTextures(1, &texdefult5);
	glBindTexture(GL_TEXTURE_2D, texdefult5);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 16, 16, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult_end5);

	glGenTextures(1, &texdefult6);
	glBindTexture(GL_TEXTURE_2D, texdefult6);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 16, 16, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult_end6);

	/*glGenTextures(1, &texdefult7);
	glBindTexture(GL_TEXTURE_2D, texdefult7);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 48, 32, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedefult);*/

}
int Image_bild(char *file_name) {
	Texture Texture;
	Texture.loud(file_name);
	if (p_w == p_h) {
		return Image_bild_qad(file_name);
	}
	else
	{

		std::cout << "\n" << "LODER " << "file name = \"" << file_name << "\" :: " << "Große = "<< p_w << "::" << p_h << "\n";
		int i = 0;
		int xp = 10000, yp;
		
		if (((p_w / 3) == (p_h / 2)) || ((p_h / 3) == (p_w / 2)))
		{
			xp = (p_h / 3);
			yp = (p_w / 2);

			std::cout << "loder 10";
			Image_bild_recht(file_name, xp, yp);
		}
		else
		{
			std::cout << "EROR 10";
		}
	}
}


///////////////////////////////////////////////////
int loud_Gras(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(1, &texGrasf1);
	glBindTexture(GL_TEXTURE_2D, texGrasf1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 5,
		5, 0, GL_RGBA, GL_UNSIGNED_BYTE,
		ImageGras1);
	
	/////////////////////////////////////////////////////////////////
	glGenTextures(1, &texGras2);
	glBindTexture(GL_TEXTURE_2D, texGras2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 5,
		5, 0, GL_RGBA, GL_UNSIGNED_BYTE,
		ImageGras2);
	/////////////////////////////////////////////////////////////////////
	glGenTextures(1, &texGras3);
	glBindTexture(GL_TEXTURE_2D, texGras3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 5,
		5, 0, GL_RGBA, GL_UNSIGNED_BYTE,
		ImageGras3);

	return texGrasf1;
}
void loud_Stone(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(1, &texStone1);
	glBindTexture(GL_TEXTURE_2D, texStone1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 8, 8, 0, GL_RGBA, GL_UNSIGNED_BYTE, ImageStone1);
}
/*void loud_ofen(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(1, &texofen1);
	glBindTexture(GL_TEXTURE_2D, texofen1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 8, 8, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imageofen1);
}
void loud_zenti(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(1, &texzenti1);
	glBindTexture(GL_TEXTURE_2D, texzenti1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 8,
		8, 0, GL_RGBA, GL_UNSIGNED_BYTE,
		Imagezenti1);
	/////////////////////////////////////////////////////////////////
	glGenTextures(1, &texzenti2);
	glBindTexture(GL_TEXTURE_2D, texzenti2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 8,
		8, 0, GL_RGBA, GL_UNSIGNED_BYTE,
		Imagezenti2);
}*/

int *abc(int arry[10]) {
	std::cout << "arry[2] = " << arry[2] << "\n";
	return arry;
}
int aaaaaa[10] = { 1,2,3,4,5,6,7,0,0,0 };
void loud_tex(void)
{
	//texGras1 = Image_bild("D:/bild_lode.ppm");
	int test_var[10];
	std::cout << "a" << "\n";
	
	//defind texGras
	texGras1 = Image_bild("C:/Opengl_3d_game/texture/gras_bo.ppm");
	texGras2 = Image_bild("C:/Opengl_3d_game/texture/gras_uo.ppm");
	texGras3 = Image_bild("C:/Opengl_3d_game/texture/gras_up.ppm");
	//Image_bild("C:/Opengl_3d_game/texture/cube_texcentrifuge.ppm");
	//centrifuge1 = texdefult2;
	//centrifuge2 = texdefult3;
	//centrifuge3 = texdefult5;
	//centrifuge4 = texdefult6;
	//centrifuge5 = texdefult1;
	//centrifuge6 = texdefult4;
	
	Image_bild("C:/Opengl_3d_game/texture/ofen.ppm");
	oven1 = texdefult2;
	oven2 = texdefult3;
	oven3 = texdefult5;
	oven4 = texdefult6;
	oven5 = texdefult1;
	oven6 = texdefult4;

	
	
	aaaaaa[2] = 1;
	test_var[0] = 11;
	//test_var = abc(aaaaaa)++;
	//std::cout << test_var[2];

	loud_Stone();
	//loud_ofen();
	//loud_zenti();
}
///////////////////////////////////////////////////
void cube_texGras()
{

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, texGras2);
	glBegin(GL_QUADS);

	/* front */

	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, 1.0, 1.0);





	/* back */
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 0.0);

	/* left */
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0, 0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, 1.0, 0.0);

	/* right */
	glTexCoord2f(0.0, 1.0);
	glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(1.0, 0, 0.0);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texGras3);
	glBegin(GL_QUADS);
	/*bottom*/
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 0.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 0.0, 1.0);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texGras1);
	glBegin(GL_QUADS);
	/*bottom*/
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 1.0, 1.0);
	glEnd();
}
void cube_texStone()
{

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, texStone1);
	glBegin(GL_QUADS);

	/* front */
	
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, 1.0, 1.0);

	/* back */
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 0.0);

	/* left */
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0, 0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, 1.0, 0.0);

	/* right */
	glTexCoord2f(0.0, 1.0);
	glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(1.0, 0, 0.0);

	/*bottom*/
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 0.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 0.0, 1.0);

	/*bottom*/
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 1.0, 1.0);
	glEnd();
}
void cube_texofen()
{

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, texofen1);
	glBegin(GL_QUADS);

	/* front */

	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, 1.0, 1.0);

	/* back */
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 0.0);

	/* left */
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0, 0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, 1.0, 0.0);

	/* right */
	glTexCoord2f(0.0, 1.0);
	glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(1.0, 0, 0.0);

	/*bottom*/
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 0.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 0.0, 1.0);

	/*bottom*/
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 1.0, 1.0);
	glEnd();
}
void cube_texcentrifuge()
{

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, centrifuge1);
	glBegin(GL_QUADS);

	/* front */

	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, 1.0, 1.0);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, centrifuge2);
	glBegin(GL_QUADS);
	/* back */
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 0.0);
	glBindTexture(GL_TEXTURE_2D, centrifuge3);
	/* left */
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0, 0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, centrifuge4);
	/* right */
	glTexCoord2f(0.0, 1.0);
	glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(1.0, 0, 0.0);
	
	glBindTexture(GL_TEXTURE_2D, centrifuge5);
	/*bottom*/
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 0.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 0.0, 1.0);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, centrifuge6);
	glBegin(GL_QUADS);
	/*bottom*/
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 1.0, 1.0);
	glEnd();
}



void cube_texoven()
{

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, oven1);
	glBegin(GL_QUADS);

	/* front */

	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, 1.0, 1.0);
	glEnd();

	
	glBindTexture(GL_TEXTURE_2D, oven2);
	glBegin(GL_QUADS);
	/* back */
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 0.0);
	glEnd();
	

	glBindTexture(GL_TEXTURE_2D, oven3);
	glBegin(GL_QUADS);
	/* left */
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0, 0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, 1.0, 0.0);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, oven4);
	glBegin(GL_QUADS);
	/* right */
	glTexCoord2f(0.0, 1.0);
	glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(1.0, 0, 0.0);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, oven5);
	glBegin(GL_QUADS);
	/*bottom*/
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 0.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 0.0, 1.0);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, oven6);
	glBegin(GL_QUADS);
	/*bottom*/
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 1.0, 1.0);
	glEnd();
}


void cube_texAlle(int id_b, int x, int y, int z)
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	
	if (World[x][y][(z + 1)] <= 0) {
		switch (id_b)
		{
		case 1:
			glBindTexture(GL_TEXTURE_2D, texStone1);
			break;
		case 2:
			glBindTexture(GL_TEXTURE_2D, texGras1);
			break;
		case 3:
			glBindTexture(GL_TEXTURE_2D, oven1);
			break;
		case 4:
			glBindTexture(GL_TEXTURE_2D, centrifuge1);
			break;
		default:
			//glBindTexture(GL_TEXTURE_2D, texStone1);
			break;
		}
		if (id_b != 0)
		{
			glBegin(GL_QUADS);

			/* front */

			glTexCoord2f(0.0, 0.0);
			glVertex3f(0, 0, 1.0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(1.0, 0, 1.0);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(1.0, 1.0, 1.0);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(0, 1.0, 1.0);
			glEnd();
		}
	}
	if (World[x][y][(z - 1)] <= 0) {
		switch (id_b)
		{
		case 1:
			glBindTexture(GL_TEXTURE_2D, texStone1);
			break;
		case 2:
			glBindTexture(GL_TEXTURE_2D, texGras1);
			break;
		case 3:
			glBindTexture(GL_TEXTURE_2D, oven2);
			break;
		case 4:
			glBindTexture(GL_TEXTURE_2D, centrifuge2);
			break;
		default:
			//glBindTexture(GL_TEXTURE_2D, texStone1);
			break;
		}
		if (id_b != 0)
		{
			glBegin(GL_QUADS);
			/* back */
			glTexCoord2f(0.0, 1.0);
			glVertex3f(0, 1.0, 0.0);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(1.0, 1.0, 0.0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(1.0, 0, 0.0);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0, 0, 0.0);
			glEnd();

		}
	}
	if (World[(x - 1)][y][z] <= 0) {
		switch (id_b)
		{
		case 1:
			glBindTexture(GL_TEXTURE_2D, texStone1);
			break;
		case 2:
			glBindTexture(GL_TEXTURE_2D, texGras1);
			break;
		case 3:
			glBindTexture(GL_TEXTURE_2D, oven3);
			break;
		case 4:
			glBindTexture(GL_TEXTURE_2D, centrifuge3);
			break;
		default:
			//glBindTexture(GL_TEXTURE_2D, texStone1);
			break;
		}
		if (id_b != 0)
		{
			glBegin(GL_QUADS);
			/* left */
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0, 0, 0.0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(0, 0, 1.0);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(0, 1.0, 1.0);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(0, 1.0, 0.0);
			glEnd();

		}
	}
	if (World[(x + 1)][y][z] <= 0) {
		switch (id_b)
		{
		case 1:
			glBindTexture(GL_TEXTURE_2D, texStone1);
			break;
		case 2:
			glBindTexture(GL_TEXTURE_2D, texGras1);
			break;
		case 3:
			glBindTexture(GL_TEXTURE_2D, oven4);
			break;
		case 4:
			glBindTexture(GL_TEXTURE_2D, centrifuge4);
			break;
		default:
			//glBindTexture(GL_TEXTURE_2D, texStone1);
			break;
		}
		if (id_b != 0)
		{
			glBegin(GL_QUADS);
			/* right */
			glTexCoord2f(0.0, 1.0);
			glVertex3f(1.0, 1.0, 0.0);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(1.0, 1.0, 1.0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(1.0, 0, 1.0);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(1.0, 0, 0.0);
			glEnd();
		}
	}
	if (World[x][(y - 1)][z] <= 0) {
		switch (id_b)
		{
		case 1:
			glBindTexture(GL_TEXTURE_2D, texStone1);
			break;
		case 2:
			glBindTexture(GL_TEXTURE_2D, texGras1);
			break;
		case 3:
			glBindTexture(GL_TEXTURE_2D, oven5);
			break;
		case 4:
			glBindTexture(GL_TEXTURE_2D, centrifuge5);
			break;
		default:
			//glBindTexture(GL_TEXTURE_2D, texStone1);
			break;
		}
		if (id_b != 0)
		{
			glBegin(GL_QUADS);
			/*bottom*/
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(1.0, 0.0, 0.0);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(1.0, 0.0, 1.0);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(0.0, 0.0, 1.0);
			glEnd();
		}
	}
	if (World[x][(y + 1)][z] <= 0) {
		switch (id_b)
		{
		case 1:
			glBindTexture(GL_TEXTURE_2D, texStone1);
			break;
		case 2:
			glBindTexture(GL_TEXTURE_2D, texGras1);
			break;
		case 3:
			glBindTexture(GL_TEXTURE_2D, oven6);
			break;
		case 4:
			glBindTexture(GL_TEXTURE_2D, centrifuge6);
			break;
		default:
			//glBindTexture(GL_TEXTURE_2D, texStone1);
			break;
		}
		if (id_b != 0)
		{
			glBegin(GL_QUADS);
			/*bottom*/
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0.0, 1.0, 0.0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(1.0, 1.0, 0.0);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(1.0, 1.0, 1.0);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(0.0, 1.0, 1.0);
			glEnd();
		}
	}
}
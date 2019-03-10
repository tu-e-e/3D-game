#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "C:\Users\Igel\documents\visual studio 2015\Projects\3d-2\3d-2\void.h"

//cube dats 2
static int cube_data_2[6][4] = { { 0,1,2,3 },{ 3,7,6,2 },{ 0,3,7,4 },{ 4,7,6,5 },{ 0,4,5,1 },{ 1,5,6,2 } };

float RGB_PIX[3][100] = { {1,0,0,1,0,0,1,1 ,1,0,0,1,0,0,1,1 ,1,0,0,1,0,0,1,1 },
						  {0,1,0,1,0,1,0,1 ,0,1,0,1,0,1,0,1 ,0,1,0,1,0,1,0,1 },
						  {0,0,1,1,1,0,0,1 ,0,0,1,1,1,0,0,1 ,0,0,1,1,1,0,0,1 } };

float daten_void[30];


void createwindow(char *Windowname, int x_d, int y_d, int x_p, int y_p)
{
	glutInitWindowSize(x_d, y_d);   // Set the window's initial width & height
	glutInitWindowPosition(x_p, y_p); //set pox
	glutCreateWindow(Windowname); // Create a window with the given title
}



void cube_2(float g, float R, float G, float B)
{
	glColor3f(R,G,B);
	for (int j = 0; j < 6; j++)
	{
		glBegin(GL_QUADS);
		for (int i = 0; i < 4; i++)
		{
			switch (cube_data_2[j][i])
			{

			case 0:glVertex3f(g, g, 0); break;
			case 1:glVertex3f(g, 0, 0); break;
			case 2:glVertex3f(0, 0, 0); break;
			case 3:glVertex3f(0, g, 0); break;

			case 4:glVertex3f(g, g, g); break;
			case 5:glVertex3f(g, 0, g); break;
			case 6:glVertex3f(0, 0, g); break;
			case 7:glVertex3f(0, g, g); break;
			}
		}
		glEnd();
	}

}

void cube_texture_1(float g_p ,int h,int w,int z_in)
{
	//float h_p = 1 / h;
	//float w_p = 1 / w;
	int RGB_Z = -1;
	for (int z = 0; z < z_in; z++)
	{
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				RGB_Z++;
				if (RGB_Z == 7)RGB_Z = 0;
				glPushMatrix();
				glTranslatef((x * g_p), (y * g_p), (z * g_p));
				cube_2(g_p, RGB_PIX[0][RGB_Z], RGB_PIX[1][RGB_Z], RGB_PIX[2][RGB_Z]);
				glPopMatrix();
			
			}
		}
	}
}

void drawSnowMan() {

	glColor3f(1.0f, 1.0f, 1.0f);
	//glShadeModel(GL_SMOOTH);
	// Draw Body

	glTranslatef(0.0f, 0.75f, 0.0f);
	glutSolidSphere(0.75f, 20, 20);

	// Draw Head
	glTranslatef(0.0f, 0.95f, 0.0f);
	glutSolidSphere(0.25f, 20, 20);

	// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f, 10, 10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f, 10, 10);
	glPopMatrix();

	// Draw Nose
	glColor3f(1.0f, 0.5f, 0.5f);
	glutSolidCone(0.08f, 0.5f, 10, 2);
}



void command()
{
	char command_z,block;
	int x, y, z;
	float R, G, B ,G_1;
	std::cout << "command <s>,<t>\n";
	std::cin >> command_z;
	switch (command_z) {

		case 's':
			std::cout << "x = ";
			std::cin >> daten_void[5];
			
			std::cout << "y = ";
			std::cin >> daten_void[6];
			
			std::cout << "z = ";
			std::cin >> daten_void[7];
		
			std::cout << "chims:<C>,<R>,<T>\n";
			std::cin >> block;
			switch (block) 
			{

			case 'C':daten_void[2] = 1; break;
			case 'R':
				daten_void[2] = 2;
				std::cout << "Große = ";
				std::cin >> daten_void[11];
				
				std::cout << "R = ";
				std::cin >> daten_void[8];
				
				std::cout << "G = ";
				std::cin >> daten_void[9];
				
				std::cout << "B = ";
				std::cin >> daten_void[10];
				
				
				break;
			
			case 'T':daten_void[2] = 3; break;
			}
			break;
		
		case 't':
			
			break;
	
			daten_void[0] = 1;
	
	}
	
	
	
	
	
	
}
void command_alf(int *daten_void)
{
	char command_z, block;
	int x, y, z;
	float R, G, B, G_1;
	std::cout << "command <s>,<t>\n";
	std::cin >> command_z;
	switch (command_z) {

	case 's':
		std::cout << "x = ";
		std::cin >> daten_void[5];

		std::cout << "y = ";
		std::cin >> daten_void[6];

		std::cout << "z = ";
		std::cin >> daten_void[7];

		std::cout << "chims:<C>,<R>,<T>\n";
		std::cin >> block;
		switch (block)
		{

		case 'C':daten_void[2] = 1; break;
		case 'R':
			daten_void[2] = 2;
			std::cout << "Große = ";
			std::cin >> daten_void[11];

			std::cout << "R = ";
			std::cin >> daten_void[8];

			std::cout << "G = ";
			std::cin >> daten_void[9];

			std::cout << "B = ";
			std::cin >> daten_void[10];


			break;

		case 'T':daten_void[2] = 3; break;
		}
		break;

	case 't':

		break;

		daten_void[0] = 1;

	}
}

void cube_texture_f(float g)
{

	for (int j = 0; j < 6; j++)
	{
		glBegin(GL_QUADS);
		for (int i = 0; i < 4; i++)
		{
			switch (cube_data_2[j][i])
			{

			case 0:glTexCoord2f(0.0,  g); glVertex3f(g, g, 0); break;
			case 1:glTexCoord2f(0.0,0.0); glVertex3f(g, 0, 0); break;
			case 2:glTexCoord2f(g,  0.0); glVertex3f(0, 0, 0); break;
			case 3:glTexCoord2f(g,    g); glVertex3f(0, g, 0); break;

			case 4:glTexCoord2f(0.0,  g); glVertex3f(g, g, g); break;
			case 5:glTexCoord2f(0.0,0.0); glVertex3f(g, 0, g); break;
			case 6:glTexCoord2f(g,  0.0); glVertex3f(0, 0, g); break;
			case 7:glTexCoord2f(g,    g); glVertex3f(0, g, g); break;
			}
		}
		glEnd();
	}

}

void cube_texture1(float g)
{

	glTranslated(0, 0, 0);
	glBegin(GL_QUADS);

	/* front *
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	*/
	
		
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
	glVertex3f(-1.0, 1.0, -1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, -1.0, -1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0, -1.0, -1.0);

	/* left */
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);

	/* right */
	glTexCoord2f(0.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, -1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(1.0, -1.0, -1.0);

	glEnd();


}




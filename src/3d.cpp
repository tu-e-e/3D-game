/*

#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>

#define x_123 1
#define y_123 1
//#include "C:\Game_release\abc.h"


GLuint texture[2];
#pragma warning(disable:4996)

struct Image {

	unsigned long sizeX;

	unsigned long sizeY;

	char *data;

};

typedef struct Image Image;


#define checkImageWidth 64

#define checkImageHeight 64


GLubyte checkImage[checkImageWidth][checkImageHeight][3];

void makeCheckImage(void) {

	int i, j, c;

	for (i = 0; i < checkImageWidth; i++) {

		for (j = 0; j < checkImageHeight; j++) {

			c = ((((i & 0x8) == 0) ^ ((j & 0x8) == 0))) * 255;

			checkImage[i][j][0] = (GLubyte)c;

			checkImage[i][j][1] = (GLubyte)c;

			checkImage[i][j][2] = (GLubyte)c;

		}

	}

}



int ImageLoad(char *filename, Image *image) {

	FILE *file;

	unsigned long size; // size of the image in bytes.

	unsigned long i; // standard counter.

	unsigned short int planes; // number of planes in image (must be 1)

	unsigned short int bpp; // number of bits per pixel (must be 24)

	char temp; // temporary color storage for bgr-rgb conversion.

			   // make sure the file is there.

	if ((file = fopen(filename, "rb")) == NULL) {

		printf("File Not Found : %s\n", filename);
		Sleep(10000);
		return 0;

	}

	// seek through the bmp header, up to the width/height:

	fseek(file, 18, SEEK_CUR);

	// read the width

	if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {

		printf("Error reading width from %s.\n", filename);
		Sleep(10000);
		return 0;

	}

	//printf("Width of %s: %lu\n", filename, image->sizeX);

	// read the height

	if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {

		printf("Error reading height from %s.\n", filename);
		Sleep(10000);
		return 0;

	}

	//printf("Height of %s: %lu\n", filename, image->sizeY);

	// calculate the size (assuming 24 bits or 3 bytes per pixel).

	size = image->sizeX * image->sizeY * 3;

	// read the planes

	if ((fread(&planes, 2, 1, file)) != 1) {

		printf("Error reading planes from %s.\n", filename);
		Sleep(10000);
		return 0;

	}

	if (planes != 1) {

		printf("Planes from %s is not 1: %u\n", filename, planes);
		Sleep(10000);
		return 0;

	}

	// read the bitsperpixel

	if ((i = fread(&bpp, 2, 1, file)) != 1) {

		printf("Error reading bpp from %s.\n", filename);
		Sleep(10000);
		return 0;

	}

	if (bpp != 24) {

		printf("Bpp from %s is not 24: %u\n", filename, bpp);
		Sleep(10000);
		return 0;

	}

	// seek past the rest of the bitmap header.

	fseek(file, 24, SEEK_CUR);

	// read the data.

	image->data = (char *)malloc(size);

	if (image->data == NULL) {

		printf("Error allocating memory for color-corrected image data");
		Sleep(10000);
		return 0;

	}

	if ((i = fread(image->data, size, 1, file)) != 1) {

		printf("Error reading image data from %s.\n", filename);
		Sleep(10000);
		return 0;

	}

	for (i = 0; i<size; i += 3) { // reverse all of the colors. (bgr -> rgb)

		temp = image->data[i];

		image->data[i] = image->data[i + 2];

		image->data[i + 2] = temp;

	}

	// we're done.

	return 1;

}


Image * loadTexture() {

	Image *image1;

	// allocate space for texture

	image1 = (Image *)malloc(sizeof(Image));

	if (image1 == NULL) {

		printf("Error allocating space for image");
		Sleep(10000);
		exit(0);

	}

	if (!ImageLoad("D:/abce_1234.bmp", image1)) {

		exit(1);

	}

	return image1;

}



void myinit(void)

{

	glClearColor(0.5, 0.5, 0.5, 0.0);

	glEnable(GL_DEPTH_TEST);

	glDepthFunc(GL_LESS);

	Image *image1 = loadTexture();

	if (image1 == NULL) {

		printf("Image was not returned from loadTexture\n");

		exit(0);

	}

	makeCheckImage();

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// Create Texture

	glGenTextures(2, texture);
	///////////////////////////////////////////////////////:1:
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //scale linearly when image bigger than texture

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //scale linearly when image smalled than texture

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, /*image1->sizeX, image1->sizeY,64,64, 0,

		GL_RGB, GL_UNSIGNED_BYTE, image1->data);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, -1);
	
	///////////////////////////////////////////////////////////////////:2:

	glBindTexture(GL_TEXTURE_2D, texture[1]);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, checkImageWidth,

		checkImageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, &checkImage[0][0][0]);

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_FLAT);

}



void display_1(float g_xy) {
	/*
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	//glutSolidTeapot(10.0);

	
	
	glBegin(GL_QUADS);

	glTexCoord2f(x_123, 0.0);

	glVertex3f(x_123 , 0.0, -1.0);

	glTexCoord2f(x_123, y_123);

	glVertex3f(x_123, y_123, -1.0);

	glTexCoord2f(0.0, y_123);

	glVertex3f(0.0, y_123, -1.0);

	glTexCoord2f(0.0, 0.0);

	glVertex3f(0.0, 0.0, -1.0);

	glEnd();
	
	glutSwapBuffers();
	
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);

	/* create a square on the XY
	note that OpenGL origin is at the lower left
	but texture origin is at upper left
	=> it has to be mirrored
	(gasman knows why i have to mirror X as well) *
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2d(1, 1); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2d(1, 0); glVertex3f(0.0, g_xy, 0.0);
	glTexCoord2d(0, 0); glVertex3f(g_xy, g_xy, 0.0);
	glTexCoord2d(0, 1); glVertex3f(g_xy, 0.0, 0.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glPopAttrib();

	glFlush();

	glutSwapBuffers();
}

void display(void) 
{
	for (float i = 1; i < 5; i = i + 0.01)
	{
		display_1(i);
		
		Sleep(10);
	}
	printf("abc");
	for (float i = 5; i > 0; i = i - 0.01)
	{
		display_1(i);

		Sleep(10);
	}
}
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
											   // Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset
								  // Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


void keyboard(unsigned char key, int x, int y) {

	switch (key) {

	case 27: // “esc” on keyboard

		exit(0);

		break;

	default: // “a” on keyboard

		break;

	}

}


int main(int argc, char** argv)

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutCreateWindow("Texture Mapping - Programming Techniques");

	myinit();

	glutReshapeFunc(reshape);

	glutDisplayFunc(display);

	glutKeyboardFunc(keyboard);

	glutMainLoop();
	//Sleep(10000);
	do
	{
	
	} while (true);
	
	return 0;

}


/*
GLfloat points_2d_1[(8 + 1)] = {
	 		 0.5,  0.5,
			-0.5,  0.5,
	 		-0.5, -0.5,
			 0.5, -0.5
};
GLfloat points_2d[(18 +1)] = {
	 0.4,  0.0,
	 0.6,  0.2,
	 0.6,  0.4,
	 0.4,  0.6,
	 0.2,  0.6,
	 0.0,  0.4,
	 0.0,  0.2,
	 0.2,  0.0,
	 0.4,  0.0,
};
GLfloat points_3d[12] = {
	1.0 , -1.0 ,  -1.0 ,
	-1.0 , -1.0 , -1.0 ,
	-1.0 , -1.0 , -1.0 ,
	1.0 , -1.0 , -1.0 ,
};
GLfloat points_cube_3d_[72] = {
	0.0, 0.0, 0.0,
	0.5, 0.0, 0.0,
	0.5, 0.5, 0.0,
	0.0, 0.5, 0.0,

	0.0, 0.0, 0.0,
	0.5, 0.0, 0.0,
	0.5, 0.5, 0.0,
	0.0, 0.5, 0.0,

	0.0, 0.0, 0.0,
	0.5, 0.0, 0.0,
	0.5, 0.5, 0.0,
	0.0, 0.5, 0.0,

	0.0, 0.0, 0.0,
	0.5, 0.0, 0.0,
	0.5, 0.5, 0.0,
	0.0, 0.5, 0.0,

	0.0, 0.0, 0.0,
	0.5, 0.0, 0.0,
	0.5, 0.5, 0.0,
	0.0, 0.5, 0.0,

	0.0, 0.0, 0.0,
	0.5, 0.0, 0.0,
	0.5, 0.5, 0.0,
	0.0, 0.5, 0.0,
};



GLfloat points_cube_3d[72] = {
	 1.0 , 1.0 ,-1.0 ,
	-1.0 , 1.0 ,-1.0 ,
	-1.0 , 1.0 , 1.0 ,
	 1.0 , 1.0 , 1.0 ,
	
	 1.0 , -1.0 ,  1.0 ,
	-1.0 , -1.0 ,  1.0 ,
	-1.0 , -1.0 , -1.0 ,
	 1.0 , -1.0 , -1.0 ,

	1.0 , -1.0 ,  1.0 ,
	-1.0 , -1.0 ,  1.0 ,
	-1.0 , -1.0 , -1.0 ,
	1.0 , -1.0 , -1.0 ,

	1.0 , -1.0 , -1.0 ,
	-1.0 , -1.0 , -1.0 ,
	-1.0 ,  1.0 , -1.0 ,
	1.0 ,  1.0 , -1.0 ,

	-1.0 ,  1.0 ,  1.0 ,
	-1.0 ,  1.0 , -1.0 ,
	-1.0 , -1.0 , -1.0 ,
	-1.0 , -1.0 ,  1.0 ,

	1.0 ,  1.0 , -1.0 ,
	1.0 ,  1.0 ,  1.0 ,
	1.0 , -1.0 ,  1.0 ,
	1.0 , -1.0 , -1.0 ,
};


void ceatewindow(char *Windowname, int x_d, int y_d, int x_p, int y_p)
{
	glutInitWindowSize(x_d, y_d);   // Set the window's initial width & height
	glutInitWindowPosition(x_p, y_p); //set pox
	
	glutCreateWindow(Windowname); // Create a window with the given title


}

void draw_2d()
{
	glClearColor(0.0f, 0.8f, 0.5f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f); // Red
		for (int i = 0; i < (sizeof(points_2d) / 4); i++)
		{
			glVertex2f(points_2d[i], points_2d[(i +1)]);
			i++;
		}

	glEnd();
	
	glutSwapBuffers();
}

void draw_3d()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.4f, 0.5f, 1.0f);
	glBegin(GL_QUADS);
	
		for (int i = 0; i < (sizeof(points_3d) / 4); i = i + 3) 
			{ glVertex3f(points_3d[i], points_3d[(i + 1)], points_3d[(i + 2)]); } //glVertex3f(x,y,z)
	
	glEnd();

	glutSwapBuffers();
}

void cube_3d()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.4f, 0.5f, 1.0f);

	glBegin(GL_QUADS);

	glVertex3f(1.0, 1.0, -1.0);

	glVertex3f(-1.0, -1.0, -1.0);

	glVertex3f(0.0, 0.0, -1.0);



	glEnd();

	float x, y, z;
	int i = 0, i_max = 0;
	
	
	//glLoadIdentity();                 // Reset the model-view matrix
	//glTranslatef(0.0f, 0.0f, 0.0f);  // Move right and into the screen
	for (int j = 0; j < 6; j++)
	{
		printf("////////////////////\n");
		glBegin(GL_QUADS);
		i_max = i_max + 12;
		for (i; i < i_max; i++)
			{
				for (int l = 0; l < 3; l++)
				{
					x = points_cube_3d[i];
					i++;
					y = points_cube_3d[i];
					i++;
					z = points_cube_3d[i];


					glVertex3f(x, y, z);
				}
			}
		glEnd();
	}
	
	
	printf("abs");
	

	glutSwapBuffers();
}



void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
											   // Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset
								  // Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


//int main(int argc, char** argv)
//{
	//glutInit(&argc, argv);
	
	//ceatewindow("draw",800,600,50,50);
	//glutDisplayFunc(draw_2d);
	//glutReshapeFunc(reshape);
	//glutMainLoop();
	//Sleep(10000);
	
	//return 0;
//}

*/

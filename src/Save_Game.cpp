/*#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
*/
#include <GL/glut.h>
#include "iostream"
#include "C:\Users\Igel\documents\visual studio 2015\Projects\3d-2\3d-2\void.h"
#include "fstream"
int r, r_1, r_2, r_3, r1, r2;


int mat(int ma)
{
	char out;
	switch (ma)
	{
	case 0:
		out = 'º';
		break;
	case 1:
		out = '#';
		break;
	case 2:
		out = '»';
		break;
	default:
		out = (ma + 48);
		break;
	}

	return out;
}
void int_as(int i)
{
	r = i / 10;
	r_1 = i - (r * 10);

	r1 = r / 10;
	r_2 = r - (r1 * 10);

	r2 = r1 / 10;
	r_3 = r1 - (r2 * 10);

	/*std::cout << r_1;
	std::cout << r_2;
	std::cout << r_3 << "\n";*/
}
int Save_Game(char name_world[5],int x_in,int y_in,int z_in,int arry_ids[30]) {
	using namespace std;
	ifstream Quelldatei;                          // neuen Lese-Stream erzeugen
												  //Quelldatei.open("c:/Users/Igel/Documents/Visual Studio 2015/Projects/game2/Debug/txt.txt", ios_base::in);      // Datei_1.txt öffnen
	char bo[10] = {'[','n', 'a', 'm', 'e', ':'};
												  //if (!Quelldatei)                              // Fehler beim Öffnen?
		//"Eingabe-Datei kann nicht geeoffnet werden"
											//else {                                        // falls es geklappt hat ...
	if (true) {
		ofstream Zieldatei("C:/Game_release/Maps/1.map");              // ja, richtig. Mit Dateinamen im Konstruktor wird die Datei implizit geöffnet
		if (!Zieldatei)                             // Fehler beim Öffnen?
			MessageBox(NULL, "Ausgabe-Datei kann nicht geeoffnet werden", "File Feler", MB_OK | MB_SYSTEMMODAL); //"Ausgabe-Datei kann nicht geeoffnet werden"
		else {                                      // falls es funktioniert hat 

			for (size_t i = 0; i < 6; i++)
			{
				Zieldatei.put(bo[i]);
			}
			for (size_t i = 0; i < 5; i++)
			{
				Zieldatei.put(name_world[i]);
			}
			Zieldatei.put(',');
			
			Zieldatei.put('{');
			for (size_t i = 0; i < 30; i++)
			{
				int_as(arry_ids[i]);
				Zieldatei.put((r_3 + 48));
				Zieldatei.put((r_2 + 48));
				Zieldatei.put((r_1 + 48));
				if (i != 29)Zieldatei.put(',');
			}
			Zieldatei.put('}');

			Zieldatei.put(',');
			Zieldatei.put('[');
			for (size_t x = 0; x < x_in; x++)
			{
				Zieldatei.put('{');
				for (size_t y = 0; y < y_in; y++)
				{
					Zieldatei.put('(');
					for (size_t z = 0; z < z_in; z++)
					{
						Zieldatei.put('<');
						//Zieldatei.put(mat(World[x][y][z]));
						Zieldatei.put((World[x][y][z]+ 48));
						Zieldatei.put('>');
						if(z != (z_in - 1))Zieldatei.put(',');
					}
					Zieldatei.put(')');
					if (y != (y_in - 1))Zieldatei.put(',');
				}
				Zieldatei.put('}');
				if (x != (x_in - 1))Zieldatei.put(',');
			
			}
			Zieldatei.put(']');
			Zieldatei.put(']');
			Zieldatei.put('\n');
			Zieldatei.put('\n');
			
			MessageBox(NULL, "Game Map wurde Gespeichert", "File Save", MB_OK | MB_SYSTEMMODAL);
		}
	}
	return World[0][0][0];
}








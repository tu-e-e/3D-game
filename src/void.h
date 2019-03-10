#pragma once

class Texture
{
public:
	int loud(char *file_name);

private:

};



extern int World[300][100][300];

extern float daten_void[];
extern void cube_2(float, float, float, float);
extern void cube_texture_1(float ,int, int, int);

extern void drawSnowMan();
extern void command_alf(int *daten_void);
//extern void command();
extern void createwindow(char *, int, int, int, int);

extern int Save_Game(char name_world[5], int x_in, int y_in, int z_in, int arry_ids[30]);

extern void generate_land();

extern void loud_tex(void);

extern void cube_texGras(void);
extern void cube_texStone(void);
extern void cube_texoven(void);
extern void cube_texcentrifuge(void);
extern void cube_texAlle(int id_b, int x, int y, int z);





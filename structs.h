#include <math.h>
typedef struct player;
typedef struct location {
	float x, y, z;
}Location;
typedef struct rotation {
	float x, y, z;
}Rotation;
typedef struct size {
	float x, y, z;
}Size;
typedef struct color {
	float r, g, b;
}Color;
typedef struct Cylinder {
	Location location;
	Rotation rotation;
	Color color;
	float Radius, height;

}Cylinder;
typedef struct Part {
	Location location;
	Rotation rotation;
	Color color;
	Size size;
}Part;
typedef struct Pin
{
	Location location;
	Color color;
	float Base;
	float Height;
	Rotation rotation;
}Pin;
typedef struct Ball {
	int lives;
	int Status;
	int coins;
	int ready;
	player *myplayer;
	double ballsSize = 0.3;
	Location location;
	Color color;
	Part HitBox;
	float Radius;
	float speed;
	int jump;
	Rotation rotation;
	double Degree = 90, xt = 5 * cos(90.0 / 180), yt = 5 * sin(90.0 / 180), radius;
}Ball;
typedef struct Shape1
{
	int Flag;
	Location location;
	Part P1, P2, P3, P[25];
	Ball B1, B2, B3, B[12];
	Part HitBoxPinFloor;
	Rotation rotation;
}Shape1;
typedef struct Shet7Circle
{
	float Shet7Size;
	Location location;
	Color color;
	Rotation rotation;
	Part HitBox;
	float Radius;
}Shet7Circle;
typedef struct makok
{
	Rotation rotation;
	Location location;
	Ball B1;
	Shet7Circle s1;
	double Degree = 90, xt = 5 * cos(90.0 / 180), yt = 5 * sin(90.0 / 180), radius;
}Makok;
typedef struct Fly
{
	int Flag;
	Location location;
	Part P1, P2, P3, P4, P5, F1, F2, F3;
	Rotation rotation;


}Fly;

typedef struct Rocket
{
	int Flag;
	Location location;
	Rotation rotation;
	Part HitBoxPinFloor;
	Cylinder C1;
	Ball FrontB;
	Pin pins[19];
	Shet7Circle Sh[4];
	float Degree = 0, xt = 5 * cos(90.0 / 180), yt = 5 * sin(90.0 / 180), radius;
}Rocket;
typedef struct OpenClose
{
	int flag = 0;
	Location location;
	Rotation rotation;
	Cylinder C1, C2, C3, C4;
	Ball B1, B2, B3, B4;
	Part HitBoxCyl[4];

}OpenClose;
typedef struct Tower
{
	Location location;
	Rotation rotation;
	Part HitBoxTower[10];
	Cylinder C[20];

}Tower;
typedef struct Block
{
	int Status;
	int Flag = 0, fl1, fl2, fl3;
	Location location;
	Rotation rotation;
	Cylinder C1, C2, C3, C4, C[9];
	Part P1, P2, P3, HitBoxBlock1[3], HitBoxBlock2[3];
	Ball balls[3];
}Block;

typedef struct Pas
{
	Location location;
	Color color;
	Pin pins[10];
	Part P1, P2, P3, P[9], HitBoxPin[3];
	int flag1, flag2, flag3;
	Rotation rotation;
}Pas;
typedef struct CylinderRor
{
	Pin pins1[64];
	Part HitBoxPinFloor, HitBoxPinCyl[4];
	Cylinder C1, C2, C3;
	Location location;
	Rotation rotation;
	float Degree = 90, xt = 5 * cos(90.0 / 180), yt = 5 * sin(90.0 / 180), radius;
}CylinderRor;
typedef struct Plane
{
	Part HitBox[5];
	int Flag;
	Cylinder C1, C2, C3;
	Part P1, P2, P3, P4, P[3];
	Pin pin, pin1, pin2, pin3, pin4, pin5;
	Ball B1, B2, B[20];
	double Degree = 90, xt = 5 * cos(90.0 / 180), yt = 5 * sin(90.0 / 180), radius;
	Location location;
	Rotation rotation;
}Plane;

typedef struct WAllOfPins
{
	Location location;
	Pin pin[40];
	Part P[4], HitBoxWall[4];
}WAllOfPins;

typedef struct Laser
{
	int Flag;
	int Type;
	Part HitBox[6], HitBox2[30];
	Cylinder Cyl[6], CylFloor[6];
	Part part[6];
	Pin pins[30];
	Location location;
}Laser;

typedef struct Vichle
{
	int type;
	int Flag = 0;
	Rotation rotation;
	Location location;
	Cylinder C[6];
	Part P[19];
	Ball balls[4];
}Vichle;
typedef struct Button
{
	float x, y;
	char *str;
	char txt[80];
	float Size;
	Color color;
}Button;

typedef struct player {
	char name[10];
	char pass[10];
	int score;
	int deaths;
	int wins;
}player;
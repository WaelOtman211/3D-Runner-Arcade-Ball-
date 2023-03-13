#define _CRT_SECURE_NO_WARNINGS 1
#include "structs.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <glut.h>

#define PI 3.1415927

////////פונקציות ראנדום 
float Randfloat(int count) {
	float r;
	srand(time(NULL)*count);
	r = ((float)rand() / (RAND_MAX)) + 1.3;
	return r;
}
int Randint(int count, int x1,int x2) {
	int n;
	srand(time(NULL)*count);
	n = rand() % x1 + x2;
	return n;
}
int Randintz(int count, int z1,int z2) {
	int n;
	srand(time(NULL)*count);
	n = rand() % z1 + z2;
	return n*-1;
}

////////פונקציות אראיות על אתחול כל אוביקטים במשחק
void Set_Location(Location *L,float x,float y,float z)
{
	L->x = x;
	L->y = y;
	L->z = z;
}
void Set_Size(Size *S, float x, float y, float z)
{
	S->x = x;
	S->y = y;
	S->z = z;
}
void Set_Color(Color *C, float r, float g, float b)
{
	C->r = r;
	C->g = g;
	C->b = b;
}
void Set_Rotation(Rotation *R, int x, int y, int z)
{
	R->x = x;
	R->y = y;
	R->z = z;
}
void Location_ON(Location *L)
{
	glTranslatef(L->x,L->y,L->z);
}
void Location_OFF(Location *L)
{
	glTranslatef(-L->x,-L->y,-L->z);

}
void Color_ON(Color *C)
{
	glColor3f(C->r, C->g, C->b);
}
void Rotation_ON(Rotation *R)
{
	glRotatef(R->x, 1, 0, 0);
	glRotatef(R->y, 0, 1, 0);
	glRotatef(R->z, 0, 0, 1);
}
void Rotation_OFF(Rotation *R)
{
	glRotatef(-R->z, 0, 0, 1);
	glRotatef(-R->y, 0, 1, 0);
	glRotatef(-R->x, 1, 0, 0);
}
void Set_Ball(Ball *B, float x, float y, float z, float Radius, float r, float g, float b)
{
	Set_Location(&B->location, x, y, z);
	Set_Color(&B->color, r, g, b);

	B->Radius = Radius;
	Set_Size(&B->HitBox.size,0.6,0.6,0.6);

}
void Set_Part(Part *P,float x,float y,float z,float sx,float sy,float sz,float r,float g,float b)
{
	Set_Location(&P->location, x, y, z);
	Set_Size(&P->size, sx, sy, sz);
	Set_Color(&P->color, r, g, b);
}
void Set_cylinder(Cylinder *C, float radius, float height,float x, float y, float z, float r, float g, float b) {
	Set_Location(&C->location, x, y, z);
	
	C->Radius = radius;
	C->height = height;
	Set_Color(&C->color, r, g, b);

}
void Set_Shet7Circle(Shet7Circle *sh, float x, float y, float z, float raduios, float r, float g, float b) {
	Set_Location(&sh->location, x, y, z);
	sh->Radius = raduios;
	Set_Color(&sh->color, r, g, b);
}
void Set_Pin(Pin *P, float x, float y, float z, float base, float height, float r, float g, float b) {
	Set_Location(&P->location, x, y, z);
	Set_Color(&P->color, r, g, b);
	P->Base = base;
	P->Height = height;
	
}
void Set_Makok(Makok *M, float x, float y, float z)
{
	float a = -4.7, b = -0.25;
	Set_Location(&M->location, x, y, z);
	Set_Ball(&M->B1, 0, 0, 0, 2.5, 3, 1, 1);
	Set_Shet7Circle(&M->s1, 0, 0, 0, 7, 3, 3, 3);
	
}
void Set_UpDwon(Shape1 *S, float x, float y, float z)
{
	Set_Location(&S->location, x, y, z);
	
	float a = 0.4, b = 0.4, c = -2.135, d = -1.708;
	int i;
	for (i = 0; i < 14; i++) {
		if (i % 2 == 0 && i < 7) {
			Set_Part(&S->P[i], -2.6, a, 0, 0.8, 0.8, 0.8, 0, 0, 0.7);
			a += 0.9;
		}
		else if (i % 2 != 0 && i < 7) {
			Set_Part(&S->P[i], -2.6, a - 0.45, 0, 0.8, 0.1, 0.8, 1, 1, 1);
		}
		else if (i % 2 != 0 && i < 14 && i>6) {
			Set_Part(&S->P[i], 2.6, b, 0, 0.8, 0.8, 0.8, 0, 0, 0.7);
			b += 0.9;
		}
		else {
			Set_Part(&S->P[i], 2.6, b - 0.45, 0, 0.8, 0.1, 0.8, 1, 1, 1);
		}
	}
	Set_Part(&S->P[i], 0, 3.25, 0, 4.4, 0.5, 1, 1, 1, 1);
}
void Set_Hammer(Shape1 *S, float x, float y, float z)
{
	Set_Location(&S->location, x, y, z);
	Set_Part(&S->P1, 0, 1, 0, 0.1, 1.5, 0.1, 0.3, 0.3, 0);
	Set_Part(&S->P2, 0, 1.65, 0, 1.3, 0.6, 0.6, 1, 1, 1);
	Set_Ball(&S->B1, 0, 1.65, 0, 0.35, 0, 0, 0);
	Set_Ball(&S->B2, 0, 0.3, 0, 0.2, 0, 0, 0);
	Set_Ball(&S->B3, 0, 0.3, 0.15, 0.1, 1, 0, 0);
	Set_Part(&S->HitBoxPinFloor,0, 1.65,0, 1, 0.6, 0.6,1,15,1);
}
void Set_Bridge(Shape1 *S, float x, float y, float z) {
	Set_Location(&S->location, x, y, z);
	float a = 0.4, b = 0.4, c = -2.135, d = -1.708;
	for (int i = 0; i < 25; i++) {
		if (i % 2 == 0 && i<7) {
			Set_Part(&S->P[i], -2.6, a, 0, 0.8, 0.8, 0.8, 0.7, 0, 0);
			a += 0.9;
		}
		else if (i % 2 != 0 && i<7) {
			Set_Part(&S->P[i], -2.6, a - 0.45, 0, 0.8, 0.1, 0.8, 1, 1, 1);
		}
		else if (i % 2 != 0 && i<14 && i>6) {
			Set_Part(&S->P[i], 2.6, b, 0, 0.8, 0.8, 0.8, 0.7, 0, 0);
			b += 0.9;
		}
		else if (i % 2 == 0 && i<14 && i>6) {
			Set_Part(&S->P[i], 2.6, b - 0.45, 0, 0.8, 0.1, 0.8, 1, 1, 1);

		}

		else if (i % 2 != 0 && i<25 && i>13) {
			Set_Part(&S->P[i], d, 3.1, 0, 0.724, 0.8, 0.8, 0.7, 0, 0);
			d += 0.854;
		}
		else {
			Set_Part(&S->P[i], c, 3.1, 0, 0.13, 0.8, 0.8, 1, 1, 1);
			c += 0.854;
		}
	}
}
void Set_OpenClose(OpenClose *Sh, float x, float y, float z) {
	Set_Location(&Sh->location, x, y, z);
	Set_cylinder(&Sh->C1, 0.3, 2, -2.85, 0, 0, 1, 1,0 );
	Set_cylinder(&Sh->C2, 0.3, 2, 2.85, 0, 0, 1, 1, 0);
	Set_Ball(&Sh->B1, -2.85, 2, 0,0.3,1, 0, 0);
	Set_Ball(&Sh->B2, 2.85, 2, 0, 0.3, 1, 0, 0);
	Set_Rotation(&Sh->C3.rotation, 0, 0, -90);
	Set_cylinder(&Sh->C3, 0.2, 2.3, -2.8, 1, 0, 0, 1, 0);
	Set_Rotation(&Sh->C4.rotation, 0, 0, 90);
	Set_cylinder(&Sh->C4, 0.2, 2.3, 2.8, 1, 0, 0, 1, 0);
	Set_Part(&Sh->HitBoxCyl[1], 2.85, 1, 0, 0.6, 2, 0.6, 1, 1, 1);
	Set_Part(&Sh->HitBoxCyl[0], -2.85, 1, 0, 0.6, 2, 0.6, 1, 1, 1);
	Set_Part(&Sh->HitBoxCyl[3], 1.55, 1, 0, 2.3, 0.4, 0.4, 1, 1,1);
	Set_Part(&Sh->HitBoxCyl[2], -1.55, 1, 0, 2.3, 0.4, 0.4, 1, 1, 1);
	
}
void Set_Rocket(Rocket *R, float x, float y, float z) {
	Set_Location(&R->location, x, y, z);
	Set_cylinder(&R->C1, 1, 4, 0, 0, 0, 1.5, 1.5, 1.5);
	Set_Ball(&R->FrontB, 0, 4, 0,1, 0, 0, 2);
	Set_Rotation(&R->rotation,-80,30,0);
		Set_Shet7Circle(&R->Sh[0], 0, 0, 1, 2, 2, 0, 0);
		
		Set_Shet7Circle(&R->Sh[1],0.7, 0, 0.7, 2, 2, 0, 0);
		Set_Rotation(&R->Sh[1].rotation, 0, 45, 0);
		
		Set_Shet7Circle(&R->Sh[2], 1, 0, 0, 2, 2, 0, 0);
		Set_Rotation(&R->Sh[2].rotation, 0, 90, 0);
		
		Set_Shet7Circle(&R->Sh[3], 0.7, 0, -0.7, 2, 2, 0, 0);
		Set_Rotation(&R->Sh[3].rotation, 0, 135, 0);
		for (int i = 0; i < 19; i++)
		Set_Rotation(&R->pins[i].rotation, 90, 0, 0);
		Set_Pin(&R->pins[0], 0, 1.2, 0, 0.3, 4, 2, 1, 0);
		Set_Pin(&R->pins[1], -0.3, 0, 0, 0.2, 3, 2, 1, 0);
		Set_Pin(&R->pins[2], 0.3, 0, 0, 0.2, 3, 2, 1, 0);
		Set_Pin(&R->pins[3], 0, 0, 0.3, 0.2, 3, 2, 1, 0);
		Set_Pin(&R->pins[4], -0.3, 0, 0.2, 0.2, 3, 2, 1, 0);
		Set_Pin(&R->pins[5], 0.3, 0, 0.2, 0.2, 3, 2, 1, 0);
		Set_Pin(&R->pins[6], 0.15, 0, -0.25, 0.2, 3, 2, 1, 0);
		Set_Pin(&R->pins[7], -0.15, 0, -0.25, 0.2, 3, 2, 1, 0);
		Set_Pin(&R->pins[8], -0.6, 1.2, 0.4, 0.2, 2, 2, 1, 0);
		Set_Pin(&R->pins[9], -0.3, 1.2, 0.6, 0.2, 2, 2, 1, 0);
		Set_Pin(&R->pins[10], -0, 1.2, 0.7, 0.2, 2, 2, 1, 0);
		Set_Pin(&R->pins[11], 0.4, 1.2, 0.6, 0.2, 2, 2, 1, 0);
		Set_Pin(&R->pins[12], 0.65, 1.2, 0.3, 0.2, 2, 2, 1, 0);
		Set_Pin(&R->pins[13], 0.7, 1.2, -0.1, 0.2, 2, 2, 1, 0);
		Set_Pin(&R->pins[14], 0.5, 1.2, -0.45, 0.2, 2, 2, 1, 0);
		Set_Pin(&R->pins[15], 0.15, 1.2, -0.65, 0.2, 2, 2, 1, 0);
		Set_Pin(&R->pins[16], -0.3, 1.2, -0.65, 0.2, 2, 2, 1, 0);
		Set_Pin(&R->pins[17], -0.6, 1.2, -0.35, 0.2, 2, 2, 1, 0);
		Set_Pin(&R->pins[18], -0.65, 1.2, -0, 0.2, 2, 2, 1, 0);
		

}
void Set_Fly(Fly *F, float x, float y, float z) {
	Set_Location(&F->location, x, y, z);
	Set_Part(&F->F1, 0, 5, 0, 0.6, 0.3, 0.6, 0.5, 0.5, 0);
	Set_Part(&F->F2, 0, 5.22, 0, 0.3, 0.15, 0.3, 1, 0.5, 0);
	Set_Part(&F->F3, 0, 5.33, 0, 0.15, 0.1, 0.15, 1, 1, 1);
	Set_Part(&F->P1, 0, 5.48, 0, 0.1, 0.3, 0.1, 0, 1, 0);
	Set_Part(&F->P2, 0, 5.63, 0, 0.6, 0.1, 0.1, 1, 0, 0);
	Set_Part(&F->P3, 0, 5.63, 0, 0.1, 0.1, 0.6, 1, 0, 0);

}
void Set_Tower(Tower *T, float x, float y, float z) {

	Set_Location(&T->location, x, y, z);
	for (int i = 0; i < 20; i += 4) {
		if (i < 4) {
			Set_cylinder(&T->C[i], 0.5, 2, 0, 0, 0, 0, 1, 0.7);
			Set_cylinder(&T->C[i + 1], 0.3, 2, 0, 2, 0, 0, 1, 0.7);
			Set_cylinder(&T->C[i + 2], 0.15, 2, 0, 4, 0, 0, 1, 0.7);
		}
		else if (i > 3 && i < 8) {
			Set_cylinder(&T->C[i], 0.5, 2, -2, 0, -3, 0, 1, 0.7);
			Set_cylinder(&T->C[i + 1], 0.3, 2, -2, 2, -3, 0, 1, 0.7);
			Set_cylinder(&T->C[i + 2], 0.15, 2, -2, 4, -3, 0, 1, 0.7);
		}
		else if (i > 7 && i < 12) {
			Set_cylinder(&T->C[i], 0.5, 2, 2, 0, -3, 0, 1, 0.7);
			Set_cylinder(&T->C[i + 1], 0.3, 2, 2, 2, -3, 0, 1, 0.7);
			Set_cylinder(&T->C[i + 2], 0.15, 2, 2, 4, -3, 0, 1, 0.7);
		}
		else if (i > 11 && i <15) {
			Set_cylinder(&T->C[i], 0.5, 2, -2, 0, 3, 0, 1, 0.7);
			Set_cylinder(&T->C[i + 1], 0.3, 2, -2, 2, 3, 0, 1, 0.7);
			Set_cylinder(&T->C[i + 2], 0.15, 2, -2, 4, 3, 0, 1, 0.7);
		}
		else if (i > 14 && i < 19) {
			Set_cylinder(&T->C[i], 0.5, 2, 2, 0, 3, 0, 1, 0.7);
			Set_cylinder(&T->C[i + 1], 0.3, 2, 2, 2, 3, 0, 1, 0.7);
			Set_cylinder(&T->C[i + 2], 0.15, 2, 2, 4, 3, 0, 1, 0.7);
		}
	}
	Set_Part(&T->HitBoxTower[0], 0, 1, 0, 0.9, 2, 0.9, 1, 1, 1);
	Set_Part(&T->HitBoxTower[1], -2, 1, -3, 0.9, 2, 0.9, 1, 1, 1);
	Set_Part(&T->HitBoxTower[2], 2, 1, -3, 0.9, 2, 0.9, 1, 1, 1);
	Set_Part(&T->HitBoxTower[3], -2, 1, 3, 0.9, 2, 0.9, 1, 1, 1);
	Set_Part(&T->HitBoxTower[4], 2, 1, 3, 0.9, 2, 0.9, 1, 1, 1);
	Set_Part(&T->HitBoxTower[5], 0, 3, 0, 0.5, 2, 0.5, 1, 1, 1);
	Set_Part(&T->HitBoxTower[6], -2, 3, -3, 0.5, 2, 0.5, 1, 1, 1);
	Set_Part(&T->HitBoxTower[7], 2, 3, -3, 0.5, 2, 0.5, 1, 1, 1);
	Set_Part(&T->HitBoxTower[8], -2, 3, 3, 0.5, 2, 0.5, 1, 1, 1);
	Set_Part(&T->HitBoxTower[9], 2, 3, 3, 0.5, 2, 0.5, 1, 1, 1);
}
void Set_Block(Block *B,float x, float y, float z) {
	Set_Location(&B->location, x, y, z);
	Set_Part(&B->P1,-2.8,0.5 ,0 ,0.2, 1, 0.4, 0, 0, 0.7);
	Set_Part(&B->P2, 2.8, 0.5, 0, 0.2, 1, 0.4, 0, 0, 0.7);
	Set_Part(&B->HitBoxBlock1[0], 0, 0.5, 0, 5.6, 0.2, 0.2, 1, 1, 1);
	Set_Rotation(&B->C1.rotation, 0, 0, -90);
	Set_cylinder(&B->C1, 0.1, 5.6, -2.8, 0.5, 0,1,0,0);
}
void Set_BlockUpDown(Block *B, float x, float y, float z) {
	Set_Location(&B->location, x, y, z);
	Set_Part(&B->P1, -2.8, 1.5, 0, 0.2, 3, 18, 0, 0, 0.7);
	Set_Part(&B->P2, 2.8, 1.5, 0, 0.2, 3, 18, 0, 0, 0.7);
	
	Set_Rotation(&B->C1.rotation, 0, 0, -90);
	Set_cylinder(&B->C1, 0.1, 5.6, -2.8, 2.5, 7, 1, 0, 0);
	Set_Part(&B->HitBoxBlock1[0], 0, 2.5, 7, 5.6, 0.2, 0.2, 1, 1, 1);

	Set_Rotation(&B->C2.rotation, 0, 0, -90);
	Set_cylinder(&B->C2, 0.1, 5.6, -2.8, 0.5, -0.5, 1, 0, 0);
	Set_Part(&B->HitBoxBlock1[1], 0, 0.5, -0.5, 5.6, 0.2, 0.2, 1, 1, 1);

	Set_Rotation(&B->C3.rotation, 0, 0, -90);
	Set_cylinder(&B->C3, 0.1, 5.6, -2.8, 2.5, -7, 1, 0, 0);
	Set_Part(&B->HitBoxBlock1[2], 0, 2.5, -7, 5.6, 0.2, 0.2, 1, 1, 1);
}
void Set_Pas(Pas *P, float x, float y, float z) {
	Set_Location(&P->location, x, y, z);
	Set_Part(&P->P1, 0, 0.1, 0, 6, 0.2,0.3, 0, 0, 0.7);
	Set_Part(&P->HitBoxPin[0], 0, 0.3, 0, 6, 0.8, 0.3, 1, 1, 1);
	float a = -2.75;
		for (int i = 0; i < 10; i++) {
			Set_Rotation(&P->pins[i].rotation,-90, 0, 0);
			Set_Pin(&P->pins[i],a , -0.7, 0, 0.15, 0.7, 0.9, 0.3, 0.2);
			a +=0.6;
		}

}
void Set_BallLeftRight(Block *B, float x, float y, float z) {
	Set_Location(&B->location, x, y, z);
	float a = -0.8;
	for (int i = 0; i < 3; i++) {
		Set_Rotation(&B->C[i].rotation, 0, -180, 0);
		Set_cylinder(&B->C[i], 0.07, -5, a, 0, 0, 0.7, 0.3, 0.2);
		Set_Ball(&B->balls[i], a, -5, 0, 0.4,0.1, 0.3, 0.6);
		Set_Part(&B->HitBoxBlock1[i], a, -5, 0, 0.7, 0.7, 0.7, 1, 1, 1);
		Set_Part(&B->HitBoxBlock2[i], a, -2.5, 0, 0.14, 5, 0.14, 1, 1, 1);
		a += 0.8;
	}
	
	
	
}
void Set_LeftRight(Block *B, float x, float y, float z) {
	Set_Location(&B->location, x, y, z);
	Set_cylinder(&B->C1, 0.25, 6, -2.8, 0, 0, 0.4, 0.3, 0.2);
	Set_cylinder(&B->C2, 0.25, 6, 2.8, 0, 0, 0.4, 0.3, 0.2);
	Set_Rotation(&B->C3.rotation, 0, 0, -90);
	Set_cylinder(&B->C3, 0.25, 5.6, -2.8, 5.8, 0, 0.4, 0.3, 0.2);
	Set_Part(&B->HitBoxBlock1[0], -2.8, 3, 0, 0.5, 6, 0.5, 1, 1, 1);
	Set_Part(&B->HitBoxBlock1[1], 2.8, 3, 0, 0.5, 6, 0.5, 1, 1, 1);
	Set_Part(&B->HitBoxBlock1[2], 0, 5.6, 0, 6, 0.5, 0.5, 1, 1, 1);
	
}
void Set_PinsUpDown(Pas *P, float x, float y, float z) {
	Set_Location(&P->location, x, y, z);
	Set_Part(&P->P1, -2.75, 4, 0, 0.5,8, 1.2, 0.9, 0.3, 0.2);
	Set_Part(&P->P2, 2.75, 4, 0, 0.5, 8, 1.2, 0.9, 0.3, 0.2);
	Set_Part(&P->P3, 0, 8, 0, 6, 0.5, 1.2, 0.9, 0.3, 0.2);
	
	float a = -1.6,b=-1.6,c=-1.6,d1=-2,d2=0;
	for (int i = 0; i < 9; i++) {
		if (i < 3) {
			Set_Part(&P->P[i], a, 10.7-(i+2), 0, 1.2, -3, 1.2, 1, 0, 0);
			a += 1.6;
		}
		else if (i > 2 && i < 6) {
			Set_Part(&P->P[i], b, 8.75- (i - 0.95), 0, 0.6, 1, 0.6, 1, 0, 0);
			b += 1.6;
		}
		else {
			Set_Part(&P->P[i], c, 7.5 - (i -3.25), 0, 1.2, 3, 1.2, 1, 0, 0);
			c += 1.6;
		}
	}
	for (int i = 0; i < 9; i++) {
		Set_Rotation(&P->pins[i].rotation, 90, 0, 0);
		Set_Pin(&P->pins[i], d1, 3.3+d2 , 0, 0.2, 1.1, 0.9, 0.3, 0.2);
		if ((i + 1) % 3 == 0) {
			
			d1 += 0.4;
			d2 -= 1;
			
		}
		d1 += 0.4;
	}
	Set_Part(&P->HitBoxPin[0], -1.6, 2.8 , 0, 1.2, 1, 0.4, 1, 1, 1);
	Set_Part(&P->HitBoxPin[1], 0, 1.8, 0, 1.2, 1, 0.4, 1, 1, 1);
	Set_Part(&P->HitBoxPin[2], 1.6,0.8 , 0, 1.2, 1, 0.4, 1, 1, 1);
}
void Set_BigBall(Rocket *B, float x, float y, float z) {
	Set_Location(&B->location, x, y, z);
	Set_cylinder(&B->C1, 0.1, -30, -0, 0, 0, 0.8, 0.8, 0.8);
	Set_Ball(&B->FrontB, 0, -30, 0, 1.5, 1, 0, 0);
	Set_Part(&B->HitBoxPinFloor, 0, -30, 0, 3, 3, 3, 0, 0, 0);
}
void Set_4Balls(OpenClose *B, float x, float y, float z) {
	Set_Location(&B->location, x, y, z);
	Set_Ball(&B->B1, 2, 0.6, 5, 0.6, 1, 0, 0);
	Set_Ball(&B->B2, -1, 0.6, 2, 0.6, 1, 0, 0);
	Set_Ball(&B->B3, 0, 0.6, -3, 0.6, 1, 0, 0);
	Set_Ball(&B->B4, -2, 0.6, -7, 0.6, 1, 0, 0);
	Set_Part(&B->HitBoxCyl[0], 2, 0.6, 5, 1.2, 1.2, 1.2, 0.9, 0.3, 0.2);
	Set_Part(&B->HitBoxCyl[1], -1, 0.6, 2, 1.2, 1.2, 1.2, 0.9, 0.3, 0.2);
	Set_Part(&B->HitBoxCyl[2], 0, 0.6, -3, 1.2, 1.2, 1.2, 0.9, 0.3, 0.2);
	Set_Part(&B->HitBoxCyl[3], -2, 0.6, -7, 1.2, 1.2, 1.2, 0.9, 0.3, 0.2);
}
void Set_CylinderPins(CylinderRor *C, float x, float y, float z)
{
	Set_Location(&C->location, x, y, z);
	Set_Rotation(&C->C1.rotation, 0, 0, -90);
	Set_cylinder(&C->C1,  0.5, 6, -3, 0, 0, 0, 0, 3);
	for (int i = 1; i <= 36; i++) {
		if (i < 10) {
			Set_Rotation(&C->pins1[i - 1].rotation, -90, 0, 0);
			Set_Pin(&C->pins1[i - 1], -3.5 + (i*0.7), 0.5, 0, 0.2, 0.5, 1, 1, 1);
		}
		else if (i > 9 && i < 19) {
			Set_Pin(&C->pins1[i - 1], (-3.5)+ (i*0.7)-6.3, 0, 0.5, 0.2, 0.5, 1, 1, 1);
		}
		else if (i > 18 && i < 28) {
			Set_Rotation(&C->pins1[i - 1].rotation, -180, 0, 0);
			Set_Pin(&C->pins1[i - 1], ((-3.5)+ (i*0.7))-12.6, 0, -0.5, 0.2, 0.5, 1, 1, 1);
		}
		else {
			Set_Rotation(&C->pins1[i - 1].rotation, 90, 0, 0);
			Set_Pin(&C->pins1[i - 1], -3.5 + (i*0.7)-18.9, -0.5, 0, 0.2, 0.5, 1, 1, 1);
		}
	}
	Set_Part(&C->HitBoxPinFloor, 0, 0, 0, 6, 1.4, 1.4, 1, 1, 1);
}
void Set_PinsOnFloor(CylinderRor *C, float x, float y, float z) {
	Set_Location(&C->location, x, y, z);
	Set_Part(&C->HitBoxPinFloor, 0.75, 0.3, -1.9, 1.8, 0.6, 4, 0.9, 0.3, 0.2);
	float a = 0,b=0;
	for (int i = 1; i <= 36; i++) {
		Set_Pin(&C->pins1[i-1], a, 0, b, 0.2, 0.6, 0.5, 0.2, 1);
		Set_Rotation(&C->pins1[i-1].rotation, -90, 0, 0);
		a += 0.5;
		if (i % 4 == 0) {
			a = 0; b -= 0.5;
		}
	}
}
void Set_CylinderPins2(CylinderRor *C, float x, float y, float z) {
	Set_Location(&C->location, x, y, z);
	Set_cylinder(&C->C1, 1.5, 7, 0, 0, 0, 0, 0, 3);
	Set_Part(&C->HitBoxPinFloor, 0, 3.5, 0, 2.8, 7, 2.8, 1, 1, 1);
	Set_Part(&C->HitBoxPinCyl[0], 0, 3.5, 2, 0.6, 7, 0.1, 1, 1, 1);
	Set_Part(&C->HitBoxPinCyl[1], 2, 3.5, 0, 0.1, 7, 0.6, 1, 1, 1);
	Set_Part(&C->HitBoxPinCyl[2], -2, 3.5, 0, 0.1, 7, 0.6, 1, 1, 1);
	Set_Part(&C->HitBoxPinCyl[3], 0, 3.5, -2, 0.6, 7, 0.1, 1, 1, 1);
	for (int i = 0; i < 64; i++) {
		if (i < 8) {
			Set_Pin(&C->pins1[i], -0,  -0.5+((i+1)*0.9), 1.5, 0.3, 0.7, 1, 1, 1);
		}
		else if (i > 7 && i < 16) {
			Set_Rotation(&C->pins1[i].rotation, 0, 90, 0);
			Set_Pin(&C->pins1[i],  1.5, -1.4+((i + 1)*0.9) - 6.3, 0, 0.3, 0.7, 1, 1, 1);

		}
		else if (i > 15 && i < 24) {
			Set_Rotation(&C->pins1[i].rotation, -180, 0, 0);
			Set_Pin(&C->pins1[i],  0, -2.3+((i + 1)*0.9) - 12.6, -1.5, 0.3, 0.7, 1, 1, 1);

		}
		else if (i > 23 && i < 32) {
			Set_Rotation(&C->pins1[i].rotation, 0, -90,0 );
			Set_Pin(&C->pins1[i],  -1.5, -3.2 + ((i + 1)*0.9) - 18.9, 0, 0.3, 0.7, 1, 1, 1);
		}
		else if (i > 31 && i < 40) {
			Set_Rotation(&C->pins1[i].rotation, 0, -45, 0);
			Set_Pin(&C->pins1[i], -1.05, -4.1 + ((i + 1)*0.9) - 25.2, 1, 0.3, 0.7, 1, 1, 1);
		}
		else if (i > 39 && i < 48) {
			Set_Rotation(&C->pins1[i].rotation, 0, 45, 0);
			Set_Pin(&C->pins1[i], 1.1, -5 + ((i + 1)*0.9) - 31.5, 1, 0.3, 0.7, 1, 1, 1);
		}
		else if (i > 47 && i < 56) {
			Set_Rotation(&C->pins1[i].rotation, 0, 135, 0);
			Set_Pin(&C->pins1[i], 1.1, -5.9 + ((i + 1)*0.9) - 37.8, -1, 0.3, 0.7, 1, 1, 1);
		}
		else 
		{
			Set_Rotation(&C->pins1[i].rotation, 0, -135, 0);
			Set_Pin(&C->pins1[i], -1.05, -6.8 + ((i+1)*0.9) - 44.1, -1, 0.3, 0.7, 1, 1, 1);
		}
	}
}
void Set_Boomb(Block *B, float x, float y, float z) {
	Set_Location(&B->location, x, y, z);
	Set_Ball(&B->balls[0], 0, 0.5, 0, 0.3, 0, 0, 0);
	Set_cylinder(&B->C1, 0.1, 0.3, 0, 0.6, 0, 0, 0, 0);
	Set_Rotation(&B->P1.rotation, 0, 0, -35);
	Set_Part(&B->P1, 0.1, 1, 0, 0.05, 0.5, 0.05, 9, 0, 0);
	Set_Part(&B->HitBoxBlock1[0], 0, 0.5, 0, 0.5, 0.5, 0.5, 1, 1, 1);
}
void Set_Life(Block *C, float x, float y, float z)
{
	Set_Location(&C->location, x, y, z);
	Set_cylinder(&C->C1, 0.3, 0.1, 0, 0.5, 0, 9, 0.2, 0);
	Set_Rotation(&C->C2.rotation, -90, 0, 0);
	Set_Rotation(&C->C1.rotation, -90, 0, 0);
	Set_Rotation(&C->C3.rotation, 90, 0, 0);
	Set_cylinder(&C->C2, 0.4, 0.08, 0, 0.5, -0.05, 4, 0.5, 0);
	Set_cylinder(&C->C3, 0.3, 0.1, 0, 0.5, -0.15, 9, 0.2, 0);
	Set_Part(&C->P1, 0, 0.5, -0.085, 0.1, 0.3, 0.2, 9, 9, 0);
	Set_Part(&C->P2, 0, 0.5, -0.085, 0.3, 0.1, 0.2, 9, 9, 0);
	Set_Part(&C->HitBoxBlock1[0], 0, 0.5, -0.05, 0.65, 0.65, 0.1, 1, 1, 1);
}
void Set_Coins(Block *C, float x, float y, float z)
{
	Set_Location(&C->location, x, y, z);
	Set_cylinder(&C->C1, 0.3, 0.1, 0, 0.5, 0, 9, 9, 0);
	Set_Rotation(&C->C2.rotation, -90, 0, 0);
	Set_Rotation(&C->C4.rotation, 90, 0, 0);
	Set_Rotation(&C->C1.rotation, -90, 0, 0);
	Set_Rotation(&C->C3.rotation, 90, 0, 0);
	Set_cylinder(&C->C2, 0.4, 0.08, 0, 0.5, -0.02, 6, 2, 0);
	Set_cylinder(&C->C4, 0.39, 0.08, 0, 0.5, -0.09, 6, 2, 0);
	Set_cylinder(&C->C3, 0.3, 0.1, 0, 0.5, -0.1, 9, 9, 0);
	Set_Part(&C->P1, 0, 0.5, -0.055, 0.1, 0.35, 0.15, 9, 1, 0);
	Set_Part(&C->HitBoxBlock1[0], 0, 0.5, -0.05, 0.65, 0.65, 0.1, 1, 1, 1);
	
}
void Set_CylinderFall(CylinderRor *B, float x, float y, float z) {
	Set_Location(&B->location, x, y, z);
	Set_Rotation(&B->C1.rotation,0 , 0, 90);
	Set_Rotation(&B->C2.rotation, 0, -180,0 );
	Set_Rotation(&B->C3.rotation, 0, -180, 0);
	Set_cylinder(&B->C1, 0.5, 7, 3.5, -17.5, 0, 2, 4, 3);
	Set_cylinder(&B->C2, 0.1, -18, -3.1, 0.5, 0, 3, 1, 1);
	Set_cylinder(&B->C3, 0.1, -18, 3.1, 0.5, 0, 3, 1, 1);
	Set_Part(&B->HitBoxPinFloor, 0, -y, 0, 7, 2, 2, 1, 1, 1);
	for (int i = 1; i <= 19; i++) {
		if (i < 10) {
			Set_Rotation(&B->pins1[i - 1].rotation, -90, 0, 0);
			Set_Pin(&B->pins1[i - 1], -3.5 + (i*0.7), -17, 0, 0.2, 0.5, 1, 1, 1);
		}
		else if (i > 9 && i < 19) {
			Set_Pin(&B->pins1[i - 1], (-3.5) + (i*0.7) - 6.3, -17.5, 0.5, 0.2, 0.5, 1, 1, 1);
		}
	}
	B->rotation.x = 65;
}
void Set_JumpOnCircle(Block *J, float x, float y, float z)
{
	Set_Location(&J->location, x, y, z);
	Set_Rotation(&J->C1.rotation, -90, 0, 0);
	Set_Part(&J->P1, 0,0, 0, 6, 0.2, 3, 0, 0, 0);
	Set_cylinder(&J->C1, 0.8, 0.6, 0, 2.8, 0, 5, 0, 0);
	Set_Part(&J->HitBoxBlock1[0], 0, 2.6, -0.3, 2.6, 0.07, 0.6, 1, 1, 1);
	Set_Part(&J->HitBoxBlock1[1], -0.8, 2.8, 0, 0.07, 1.6, 0.6, 1, 1, 1);
	Set_Part(&J->HitBoxBlock1[2], 0.8, 2.8, 0, 0.07, 1.6, 0.6, 1, 1, 1);
	Set_Part(&J->HitBoxBlock2[0], 0, 1, -0.3, 2.6, 0.07, 0.6, 1, 1, 1);
}
void Set_Plane(Plane *P, float x, float y, float z)
{
	Set_Location(&P->location, x, y, z);
	Set_Rotation(&P->C1.rotation, 90, 0, 0);
	Set_cylinder(&P->C1, 0.75, 5, 0, 5, 0, 9, 9, 9);
	Set_Rotation(&P->pin.rotation, 180, 0, 0);
	Set_Pin(&P->pin, 0,5, -0.75, 0.5, 0.5, 0, 0, 0);
	Set_Ball(&P->B1, 0, 5, -0.2, 0.75, 0, 0, 0);
	Set_Ball(&P->B2, 0, 5, 5, 0.75, 9, 9, 9);
	Set_Rotation(&P->P1.rotation, -90, -5, 25);
	Set_Part(&P->P1, -1.6, 4.7, 2.5, 4.7, 1, 0.1, 1, 1, 1);
	Set_Rotation(&P->P2.rotation, -90, 5, -25);
	Set_Part(&P->P2, 1.6, 4.7, 2.5, 4.7, 1, 0.1, 1, 1, 1);
	//Set_Rotation(&P->P3.rotation, -90, 5, -25);
	Set_Part(&P->P3, 0, 5.8, 4.7, 0.15, 3, 1, 1, 1, 1);
	float a = 0.15;
	for (int i = 0; i < 10; i++) {
		Set_Ball(&P->B[i], 0.65, 5.2, a, 0.15, 0, 0, 0);
		a+=0.5;
	}
	a = 0.15;
	for (int i =10; i < 20; i++) {
		Set_Ball(&P->B[i], -0.65, 5.2, a, 0.15, 0, 0, 0);
		a += 0.5;
	}
	
	Set_Pin(&P->pin1, 1.4, 4.4, 2, 0.3, 1, 1, 0, 0);
	Set_Pin(&P->pin2, 2.6, 4.43, 2.5, 0.15, 0.5, 1, 0, 0);
	Set_Pin(&P->pin3, -1.4, 4.4, 2, 0.3, 1, 1, 0, 0);
	Set_Pin(&P->pin4, -2.6, 4.43, 2.5, 0.15, 0.5, 1, 0, 0);
}
void Set_WallOfPins(WAllOfPins *W, float x, float y, float z) {
	Set_Location(&W->location, x, y, z);
	Set_Part(&W->P[0], 0, 2, 0, 6, 2, 0.5, 3, 1, 7);
	Set_Part(&W->P[1], -2.5, 1.5, 0, 1, 3, 0.5, 3, 1, 7);
	Set_Part(&W->P[2], 2.5, 1.5, 0, 1, 3, 0.5, 3, 1, 7);
	Set_Part(&W->P[3], 0, 1.5, 0, 1, 3, 0.5, 3, 1, 7);
	float a = -2.5;
	for(int i=0;i<6;i+=2){
	Set_Pin(&W->pin[i], a, 0.3, 0, 0.3, 1, 1, 1, 1);
	Set_Pin(&W->pin[i+1], a, 0.9, 0, 0.3, 1, 1, 1, 1);
	a += 2.5;
	}
	 a = -2.5;
	for (int i = 6; i<24; i += 3) {
		Set_Pin(&W->pin[i], a, 1.5, 0, 0.3, 1, 1, 1, 1);
		Set_Pin(&W->pin[i + 1], a, 2.1, 0, 0.3, 1, 1, 1, 1);
		Set_Pin(&W->pin[i + 2], a, 2.7, 0, 0.3, 1, 1, 1, 1);
		a += 1;
	}
	Set_Part(&W->HitBoxWall[0], 0, 2, 0.5, 6, 2, 0.2, 1, 1, 1);
	Set_Part(&W->HitBoxWall[1], -2.5, 0.5, 0.6, 0.5, 1, 0.4, 1, 1, 1);
	Set_Part(&W->HitBoxWall[2], 2.5, 0.5, 0.6, 0.5, 1, 0.4, 1, 1, 1);
	Set_Part(&W->HitBoxWall[3], 0, 0.5, 0.6, 0.5, 1, 0.4, 1, 1, 1);
}
void Set_Laser(Laser *L, float x, float y, float z, int type) {
	Set_Location(&L->location, x, y, z);
	L->Type = type;
	if (L->Type == 1) {
		for (int i = 0; i < 6; i += 2) {
			Set_Part(&L->HitBox[i], -2.5 + (i*1.25), 0.5, 0, 1, 1, 0.7, 1, 1, 1);
			Set_Part(&L->HitBox[i+1], -2.5 + (i*1.25), 0.25, 0, 0.45, 0.45, 0.3, 1, 1, 1);
			Set_Part(&L->part[i], -2.5 + (i*1.25), 0.25, 0, 1, 0.25, 1, 0.1, 0.2, 0.3);
			Set_Part(&L->part[i + 1], -2.5 + (i*1.25), 0.4, 0, 0.75, 0.15, 0.75, 0.3, 0.2, 0.7);
			Set_Rotation(&L->Cyl[i].rotation, -90, 0, 0);
			Set_Rotation(&L->Cyl[i + 1].rotation, -90, 0, 0);
			Set_cylinder(&L->Cyl[i], 0.35, 0.3, -2.5 + (i*1.25), 0.7, 0.2, 0, 0, 9);
			Set_cylinder(&L->Cyl[i + 1], 0.25, 0.3, -2.5 + (i*1.25), 0.7, 0.25, 9, 0, 3);
			if ((i + 1) % 3 == 0) {
				Set_Part(&L->HitBox[i], -2.5 + (i*1.25), 0.5, 2, 1, 1, 0.7, 1, 1, 1);
				Set_Part(&L->HitBox[i + 1], -2.5 + (i*1.25), 0.7, 2.2, 0.45, 0.45, 0.3, 1, 1, 1);
				Set_Part(&L->part[i], -2.5 + (i*1.25), 0.25, 2, 1, 0.25, 1, 0.1, 0.2, 0.3);
				Set_Part(&L->part[i + 1], -2.5 + (i*1.25), 0.4, 2, 0.75, 0.15, 0.75, 0.3, 0.2, 0.7);
				Set_cylinder(&L->Cyl[i], 0.35, 0.3, -2.5 + (i*1.25), 0.7, 2.2, 0, 0, 9);
				Set_cylinder(&L->Cyl[i + 1], 0.25, 0.3, -2.5 + (i*1.25), 0.7, 2.25, 9, 0, 3);
			}
		}
			
	}
	if (L->Type == 2) {
		for (int i = 0; i < 4; i += 2) {
			Set_Part(&L->HitBox[i], -1.5 + (i * 1.5), 0.5, 0, 1, 1, 0.7, 1, 1, 1);
			Set_Part(&L->HitBox[i + 1], -1.5 + (i * 1.5), 0.7, 0.25, 0.45, 0.45, 0.3, 1, 1, 1);
			Set_Part(&L->part[i], -1.5 + (i * 1.5), 0.25, 0, 1, 0.25, 1, 0.1, 0.2, 0.3);
			Set_Part(&L->part[i + 1], -1.5 + (i * 1.5), 0.4, 0, 0.75, 0.15, 0.75, 0.3, 0.2, 0.7);
			Set_Rotation(&L->Cyl[i].rotation, -90, 0, 0);
			Set_Rotation(&L->Cyl[i + 1].rotation, -90, 0, 0);
			Set_cylinder(&L->Cyl[i], 0.35, 0.3, -1.5 + (i * 1.5), 0.7, 0.2, 0, 0, 9);
			Set_cylinder(&L->Cyl[i + 1], 0.25, 0.3, -1.5 + (i * 1.5), 0.7, 0.25, 9, 0, 3);
	
		}
	}
	if (L->Type == 3) {
		Set_Part(&L->HitBox[0], 0, 0.25, 0, 1, 1, 0.7, 1, 1, 1);
		Set_Part(&L->HitBox[1], 0, 0.7, 0.25, 0.45, 0.45, 0.3, 1, 1, 1);
			Set_Part(&L->part[0], 0, 0.25, 0, 1, 0.25, 1, 0.1, 0.2, 0.3);
			Set_Part(&L->part[ 1], 0, 0.4, 0, 0.75, 0.15, 0.75, 0.3, 0.2, 0.7);
			Set_Rotation(&L->Cyl[0].rotation, -90, 0, 0);
			Set_Rotation(&L->Cyl[ 1].rotation, -90, 0, 0);
			Set_cylinder(&L->Cyl[0], 0.35, 0.3, 0, 0.7, 0.2, 0, 0, 9);
			Set_cylinder(&L->Cyl[1], 0.25, 0.3, 0, 0.7, 0.25, 9, 0, 3);

		
	}
	if (L->Type == 4) {
		for (int i = 0; i < 6; i += 2) {
			Set_Part(&L->HitBox[i], -1 + (i*0.5), 0.25, 0, 1, 1, 0.7, 1, 1, 1);
			Set_Part(&L->HitBox[i+1], -1 + (i*0.5), 0.7, 0.25, 0.45, 0.45, 0.3, 1, 1, 1);
			Set_Part(&L->part[i], -1 +(i*0.5), 0.25, 0, 1, 0.25, 1, 0.1, 0.2, 0.3);
			Set_Part(&L->part[i + 1], -1 + (i*0.5), 0.4, 0, 0.75, 0.15, 0.75, 0.3, 0.2, 0.7);
			Set_Rotation(&L->Cyl[i].rotation, -90, 0, 0);
			Set_Rotation(&L->Cyl[i + 1].rotation, -90, 0, 0);
			Set_cylinder(&L->Cyl[i], 0.35, 0.3, -1 + (i*0.5), 0.7, 0.2, 0, 0, 9);
			Set_cylinder(&L->Cyl[i + 1], 0.25, 0.3, -1 + (i*0.5), 0.7, 0.25, 9, 0, 3);		
		}
	}
	if (L->Type == 5) {
		for (int i = 0; i < 4; i += 2) {
			
			Set_Part(&L->HitBox[i + 1], -0.55 + (i*1.11), 0.7, 0, 0.3, 0.3, 0.3, 1, 1, 1);
			Set_Part(&L->part[i], -1 + (i*1.5), 0.25, 0, 1, 0.25, 1, 0.1, 0.2, 0.3);
			Set_Part(&L->part[i + 1], -1 + (i*1.5), 0.6, 0, 0.75, 0.7, 0.75, 0.3, 0.2, 0.7);
			Set_Rotation(&L->Cyl[i].rotation, -90, 0, 90);			
			Set_cylinder(&L->Cyl[i], 0.15, 0.1,-0.55 + (i*1.11), 0.7, 0, 9, 0, 3);			
		}		
	}

}
void Set_PinsRain(Laser *L, float x, float y, float z) {
	Set_Location(&L->location, x, y, z);
	for (int i = 0; i < 6; i ++) {
		if(i<2){
		Set_Part(&L->part[i], -1.8 + (i*1.75), 6, -3+(i*1.25), 0.75, 0.35, 0.75, 1, 0.4, 0.8);
		Set_cylinder(&L->Cyl[i], 0.2, 0.1, -1.8 + (i*1.75), 5.8, -3 + (i*1.25), 0, 0, 9);
		Set_cylinder(&L->CylFloor[i], 0.2, 0.1, -1.8 + (i*1.75), 0.2, -3 + (i*1.25), 0, 0, 0);
		for (int j = 0; j < 10; j++) {
			if (j < 5) {
				Set_Pin(&L->pins[j], -1.8 + (i*1.75), 6.35, -3 + (i*1.25), 0.2, 0.6, 0.5, 0.2, 1);
				Set_Part(&L->HitBox2[j], -1.8 + (i*1.75), 6.15, -3 + (i*1.25), 0.3, 0.6, 0.3, 1, 1, 1);
			}
			if (j > 4 && j < 10) {
				Set_Pin(&L->pins[j], -1.8, 6.35, -3, 0.2, 0.6, 0.5, 0.2, 1);
				Set_Part(&L->HitBox2[j], -1.8, 6.15, -3, 0.3, 0.6, 0.3, 1, 1, 1);
			}
			Set_Rotation(&L->pins[j].rotation, 90, 0, 0);
		}
		}
		if (i > 1 && i < 4) {
			Set_Part(&L->part[i], ((i - 2)*1.85), 6, 1 + ((i - 2)*1.45), 0.75, 0.35, 0.75, 1, 0.4, 0.8);
			Set_cylinder(&L->Cyl[i], 0.2, 0.1, ((i - 2)*1.85), 5.8, 1 + ((i - 2)*1.45), 0, 0, 9);
			Set_cylinder(&L->CylFloor[i], 0.2, 0.1, ((i - 2)*1.85), 0.2, 1 + ((i - 2)*1.45), 0, 0, 0);
			for (int j = 10; j < 20; j++) {
				if (j < 15 && j>9) {
					Set_Pin(&L->pins[j], ((i - 2)*1.85), 6.35, 1 + ((i - 2)*1.45), 0.2, 0.6, 0.5, 0.2, 1);
					Set_Part(&L->HitBox2[j], ((i - 2)*1.85), 6.15, 1 + ((i - 2)*1.45), 0.3, 0.6, 0.3, 1, 1, 1);
				}
				if (j > 14 && j < 20) {
					Set_Pin(&L->pins[j], 0, 6.35, 1, 0.2, 0.6, 0.5, 0.2, 1);
					Set_Part(&L->HitBox2[j], 0, 6.15, 1, 0.3, 0.6, 0.3, 1, 1, 1);
				}
				Set_Rotation(&L->pins[j].rotation, 90, 0, 0);
			}
		}
		if (i > 3&&i<6) {
			Set_Part(&L->part[i], -1.5 + ((i - 4)*1.85), 6, 4 + ((i - 4)*1.25), 0.75, 0.35, 0.75, 1, 0.4, 0.8);
			Set_cylinder(&L->Cyl[i], 0.2, 0.1, -1.5 + ((i - 4)*1.85), 5.8, 4 + ((i - 4)*1.25), 0, 0, 9);
			Set_cylinder(&L->CylFloor[i], 0.2, 0.1, -1.5 + ((i - 4)*1.85), 0.2, 4 + ((i - 4)*1.25), 0, 0, 0);
			for (int j = 20; j < 30; j++) {
				if (j < 25 && j>19) {
					Set_Pin(&L->pins[j], -1.5 + ((i - 4)*1.85), 6.35, 4 + ((i - 4)*1.25), 0.2, 0.6, 0.5, 0.2, 1);
					Set_Part(&L->HitBox2[j], -1.5 + ((i - 4)*1.85), 6.15, 4 + ((i - 4)*1.25), 0.3, 0.6, 0.3, 1, 1, 1);
				}
				if (j > 24 && j < 30) {
					Set_Pin(&L->pins[j], -1.5, 6.35, 4, 0.2, 0.6, 0.5, 0.2, 1);
					Set_Part(&L->HitBox2[j], -1.5, 6.15, 4, 0.3, 0.6, 0.3, 1, 1, 1);
				}
				Set_Rotation(&L->pins[j].rotation, 90, 0, 0);
			}
		}
	}
}
void Set_3Cylinders(Block *C, float x, float y, float z) {
	Set_Location(&C->location, x, y, z);
	for (int i = 0; i < 9; i+=3) {
		Set_Rotation(&C->C[i].rotation, -90, 0, 0);
		Set_Rotation(&C->C[i+1].rotation, -90, 0, 0);
		Set_Rotation(&C->C[i + 2].rotation, -90, 0, 0);
		Set_cylinder(&C->C[i], 0.7, 0.3, -2.5 + (i*0.3), 1, 0.2 - (i*0.3), 3, 1, 0.7);
		Set_cylinder(&C->C[i+1], 0.5, 0.2, -2.5 + (i*0.3), 1, 0.3 - (i*0.3), 3, 1, 9);
		Set_cylinder(&C->C[i + 2], 0.3, 0.2, -2.5 + (i*0.3), 1, 0.35 - (i*0.3), 3, 9, 9);
	}
	Set_Part(&C->HitBoxBlock1[0], -2.5, 1, 0.1, 1.4, 1.4, 0.5, 1, 1, 1);
	Set_Part(&C->HitBoxBlock1[1], -1.6, 1, -0.75, 1.4, 1.4, 0.5, 1, 1, 1);
	Set_Part(&C->HitBoxBlock1[2], -0.7, 1, -1.65, 1.4, 1.4, 0.5, 1, 1, 1);
}
void Set_Shoot(Plane *L, float x, float y, float z) {
	Set_Location(&L->location, x, y, z);
	Set_cylinder(&L->C1, 0.2,0.7,0, -0.5, 0, 0.6, 4, 0.6);
	Set_cylinder(&L->C2, 0.5, 0.4, 0, 0, 0, 9, 0, 0);
	Set_Ball(&L->B[0], 0, 0.4, 0, 0.5, 9, 0, 0);
	Set_Ball(&L->B[1], 0, 0.8, 0, 0.15, 0, 0, 0);
	Set_Ball(&L->B[2], -0.3, 0.2, 0.3, 0.15, 0, 0, 0);
	Set_Ball(&L->B[3], 0, 0.4, 0.4, 0.15, 0, 0, 0);
	Set_Ball(&L->B[4], 0.3, 0.2, 0.3, 0.15, 0, 0, 0);
	Set_Ball(&L->B[5], -0.35, 0.6, 0.1, 0.15, 0, 0, 0);
	Set_Ball(&L->B[6], 0.35, 0.6, 0.1, 0.15, 0, 0, 0);
	Set_Part(&L->HitBox[2], -0.3, 0.2, 0.3, 0.3, 0.3, 0.3, 1, 1, 1);
	Set_Part(&L->HitBox[3], 0.3, 0.2, 0.3, 0.3, 0.3, 0.3, 1, 1, 1);
	Set_Part(&L->HitBox[4], 0, 0.4, 0.4, 0.3, 0.3, 0.3, 1, 1, 1);
	Set_Part(&L->HitBox[0], 0, -0.4, 0, 0.4, 0.7, 0.4, 1, 1, 1);
	Set_Part(&L->HitBox[1], 0, 0.4, 0, 1, 0.9, 1, 1, 1, 1);
}
void Set_Cloud(Plane *P, float x, float y, float z) {
	Set_Location(&P->location, x, y, z);
	for (int i = 0; i < 10; i++) {
		Set_Ball(&P->B[i], -0.5+(i*0.7), 0, 0, 0.7, 2, 2, 2);
		if(i>2&&i<6)
			Set_Ball(&P->B[i], -0.5 + ((i-3)*0.7), -0.4, 0.7, 0.7, 2, 2, 2);
		if (i>5 && i<8)
			Set_Ball(&P->B[i], -0.5 + ((i - 5.5)*0.7), 0, 0.5, 0.7, 2, 2, 2);
	}
	Set_Ball(&P->B[8], -1, -0.3, 0.5, 0.7, 2, 2, 2);
	Set_Ball(&P->B[9], 1.2, -0.3, 0.5, 0.7, 2, 2, 2);
}
void Set_WarPlane(Plane *P, float x, float y, float z) {
	Set_Location(&P->location, x, y, z);

	Set_Rotation(&P->C1.rotation, 90, 0, 0);
	Set_cylinder(&P->C1, 0.5, 3, 0, 5, 0, 0, 0, 0.7);
	Set_Rotation(&P->C2.rotation, -90, 0, 0);
	Set_cylinder(&P->C2, 0.35, 0.6, 0, 5.45, 1.5, 0, 0, 0);
	Set_Ball(&P->B[0], 0, 5.45, 1.5, 0.35, 0, 0, 0);
	Set_Ball(&P->B[1], 0, 5.45, 1, 0.35, 0, 0, 0);
	Set_Ball(&P->B1, 0, 5, 0, 0.5, 0.6, 0.6, 0.6);
	Set_Pin(&P->pin, 0, 5, 3, 0.5, 1, 9, 0, 0);
	Set_Rotation(&P->P2.rotation, -90, 0, -70);
	Set_Part(&P->P2, 1.6, 5, 1, 1, 3, 0.1, 0.6, 0.6, 0.6);
	Set_Rotation(&P->P1.rotation, -90, 0, 70);
	Set_Part(&P->P1, -1.6, 5, 1, 1, 3, 0.1, 0.6, 0.6, 0.6);
	Set_Part(&P->P3, 0, 5, 4, 0.1, 1, 0.1, 0, 0, 0);
	Set_Part(&P->P4, 0, 5, 4, 1, 0.1, 0.1, 0, 0, 0);
	Set_Part(&P->P[0], 0, 5.8, -0.2, 0.1, 1.3, 0.4, 1, 1, 1);
	Set_Rotation(&P->P[1].rotation, 0, 0, 90);
	Set_Rotation(&P->P[2].rotation, 0, 0, -90);
	Set_Part(&P->P[1], -0.75, 5,0, 0.1, 1.3, 0.4, 0, 0, 0);
	Set_Part(&P->P[2], 0.75, 5, 0, 0.1, 1.3, 0.4, 0, 0, 0);
}
void Set_Bird(Plane *P, float x, float y, float z) {
	Set_Location(&P->location, x, y, z);
	Set_Rotation(&P->pin.rotation, -205, 0, 0);
	Set_Pin(&P->pin, 0, 5, 3, 0.3, 1.3, 0.6, 0.3, 0.1);
	Set_cylinder(&P->C1, 0.04, 0.4, 0.09, 4.4,2.8, 0.9, 0.9, 0);
	Set_cylinder(&P->C2, 0.04, 0.4, -0.09, 4.4, 2.8, 0.9, 0.9, 0);
	Set_Ball(&P->B1, 0, 5, 3, 0.3, 0.6, 0.3, 0.1);
	Set_Ball(&P->B[0], 0, 5.4, 3, 0.18, 1, 1, 1);
	Set_Ball(&P->B[1], 0.05, 5.47, 3.15, 0.06, 0, 0, 0);
	Set_Ball(&P->B[2], -0.05, 5.47, 3.15, 0.06, 0, 0, 0);
	Set_Pin(&P->pin1, 0, 5.4, 3, 0.13, 0.4, 0.9, 0.9, 0);
	Set_Rotation(&P->P1.rotation, 90, 30, 45);
	Set_Part(&P->P1, -0.37, 5, 2.7, 1.4, 0.3, 0.05, 0.7, 0, 0);
	Set_Rotation(&P->P2.rotation, 90, -30, -45);
	Set_Part(&P->P2, 0.37, 5, 2.7, 1.4, 0.3, 0.05, 0.7, 0, 0);
	Set_Part(&P->P3, 0.09, 4.4, 2.95, 0.1, 0.05, 0.25, 0.7, 0, 0);
	Set_Part(&P->P4, -0.09, 4.4, 2.95, 0.1, 0.05, 0.25, 0.7, 0, 0);
}
void Set_CircleRocket(Plane *P, float x, float y, float z) {
	Set_Location(&P->location, x, y, z);
	Set_Ball(&P->B1, 0, 3, 3, 1.2, 3, 1, 1);
	Set_Ball(&P->B[0], 0, 3.55, 3, 0.995, 1, 2, 2);
	Set_Rotation(&P->pin.rotation, -90, 0, 0);
	Set_Pin(&P->pin, 0, 3.2, 3, 1.7, 1.2, 3, 1, 1);
	Set_cylinder(&P->C1, 1.7,0.3, 0, 3.2, 3, 3, 1, 1);
	Set_Rotation(&P->C1.rotation, 180, 0, 0);
	Set_Rotation(&P->P1.rotation, -25, 0, 0);
	Set_Rotation(&P->P2.rotation, 25, 0, 0);
	Set_Rotation(&P->P3.rotation, 0, 0, -25);
	Set_Rotation(&P->P4.rotation, 0, 0, 25);
	Set_Part(&P->P1, 0, 2.5, 4.5, 0.15, 2, 0.15, 1, 0.7, 0.5);
	Set_Part(&P->P2, 0, 2.5, 1.5, 0.15, 2, 0.15, 1, 0.7, 0.5);
	Set_Part(&P->P3, -1.5, 2.5, 3, 0.15, 2, 0.15, 1, 0.7, 0.5);
	Set_Part(&P->P4, 1.5, 2.5, 3, 0.15, 2, 0.15, 1, 0.7, 0.5);
	Set_Ball(&P->B[1], 0, 3.4, 4.3, 0.2, 0, 1, 1);
	Set_Ball(&P->B[2], -1.3, 3.4, 3, 0.2, 0, 1, 1);
	Set_Ball(&P->B[3], -0.9, 3.4, 3.85, 0.2,1, 1, 0);
	Set_Ball(&P->B[4], 1.3, 3.4, 3, 0.2, 0, 1, 1);
	Set_Ball(&P->B[5], 0.9, 3.4, 3.85, 0.2, 1, 1, 0);
	Set_Ball(&P->B[6], 0, 3.4, 1.7, 0.2, 0, 1, 1);
	Set_Ball(&P->B[7], 0.9, 3.4, 2, 0.2, 1, 1, 0);
	Set_Ball(&P->B[8], -0.9, 3.4, 2, 0.2, 1, 1, 0);
}
void Set_Volcan(Plane *P, float x, float y, float z) {
	Set_Location(&P->location, x, y, z);
	Set_Rotation(&P->pin.rotation, -90, 0, 0);
	Set_Rotation(&P->pin1.rotation, -90, 0, 0);
	Set_Rotation(&P->pin2.rotation, -90, 0, 0);
	Set_Rotation(&P->pin3.rotation, -90, 0, 0);
	Set_Rotation(&P->pin4.rotation, -90, 0, 0);
	Set_Rotation(&P->pin5.rotation, -90, 0, 0);
	Set_Pin(&P->pin, -5, 0, 0, 10, 15, 0.6, 0.3, 0.1);
	Set_Pin(&P->pin1, 3, 0, 0, 10, 12, 0.6, 0.3, 0.1);
	Set_Pin(&P->pin2, 2.5, 0, 13, 5, 7, 0.6, 0.3, 0.1);
	Set_Pin(&P->pin3, 8.5, 0, 13, 4, 5, 0.6, 0.3, 0.1);
	Set_Pin(&P->pin4, 2.5, 0, 13, 5, 7, 0.6, 0.3, 0.1);
	Set_Pin(&P->pin5, 43, 0, -10, 10, 15, 0.6, 0.3, 0.1);
}
void Set_Vichle(Vichle *V, float x, float y, float z,int num ) {
	Set_Location(&V->location, x, y, z);
	V->type = num;
	if (V->type == 1) {
	float x1= -1.15, z1= 1.3, x2 = -0.75, z2 = 2;
	for (int i = 0; i < 4; i++) {
		Set_Rotation(&V->C[i].rotation, 0, 0, -90);
		if(i>1)Set_Rotation(&V->C[i].rotation, 0, 0,90);
	}
	Set_Part(&V->P[0], 0, 0, 0, 2, 1, 4, 4, 0.2, 0.2);
	Set_Part(&V->P[1], 0, 1, -0.5, 2, 1, 3, 0.2, 0.2, 4);
	for (int i = 2; i < 5; i++)
	Set_Part(&V->P[i], 0, -0.3+(i*0.15), 2, 1, 0.1, 0.2, 0, 0, 0);
	for (int i = 5; i < 9; i++) {
		z2 *= -1;
		Set_Part(&V->P[i], x2, 0.3, z2, 0.3, 0.3, 0.1, 1, 1, 1);
		if (i == 6) x2 *= -1;
	}
	Set_Part(&V->P[9], 0, -0.3, 2, 0.7, 0.3, 0.1, 1, 1, 0);
	Set_Part(&V->P[10], 0, -0.3, -2, 0.7, 0.3, 0.1, 1, 1, 0);
		Set_Part(&V->P[11], -1, 0, -0.3, 0.1, 1, 0.1, 0, 0, 0);
		Set_Part(&V->P[12], 1, 0, -0.3, 0.1, 1, 0.1, 0, 0, 0);
		Set_Part(&V->P[13], -1, 0.2, -0, 0.1, 0.1, 0.3, 0, 0, 0);
		Set_Part(&V->P[14], 1, 0.2, -0, 0.1, 0.1, 0.3, 0, 0, 0);
		Set_Part(&V->P[15], 0.1, 1, -0.5, 1.8, 0.8, 2.8, 0, 9, 9);
		Set_Part(&V->P[16], -0.1, 1, -0.5, 1.8, 0.8, 2.8, 0, 9, 9);
		Set_Part(&V->P[17], 0, 1, -0.4, 1.8, 0.8, 2.8, 0, 9, 9);
		Set_Part(&V->P[18], 0, 1, -0.6, 1.8, 0.8, 2.8, 0, 9, 9);
		
	for (int i = 0; i < 4; i++) {
		 z1 *= -1;
		Set_cylinder(&V->C[i], 0.5, 0.3, x1, -0.5, z1, 0, 0, 0);
		Set_Ball(&V->balls[i], x1, -0.5, z1, 0.15, 9, 9, 9);
		if (i == 1) x1 *= -1;
	}}
	if (V->type == 2) {
		Set_Part(&V->P[0], 0, 0, 0, 3, 3, 5, 9, 9, 0);
		Set_Part(&V->P[1], -1.5, 0.7, -0.5, 0.1, 1, 3, 0, 9, 9);
		Set_Part(&V->P[2], 1.5, 0.7, 0, 0.1, 1, 4, 0, 9, 9);
		Set_Part(&V->P[3], 0, 0.9, 2.5, 1.8, 0.8, 0.1, 0, 9, 9);
		Set_Part(&V->P[4], 0, 0.7, -2.5, 1.8, 0.8, 0.1, 0, 9, 9);
		Set_Part(&V->P[5], -1.5, -0.3, -0.5, 0.1, 0.2, 3, 0, 0, 0);
		Set_Part(&V->P[6], 1.5, -0.3, 0, 0.1, 0.2, 4, 0, 0, 0);
		Set_Part(&V->P[7], -1.5, -0.7, -0.5, 0.1, 0.2, 3, 0, 0, 0);
		Set_Part(&V->P[8], 1.5, -0.7, 0, 0.1, 0.2, 4, 0, 0, 0);
		Set_Part(&V->P[9], 0, -0.75, 3.4, 1.8, 1.5, 2, 9, 9, 0);
		Set_Part(&V->P[10], -1.5, 0, 1.7, 0.1, 2.5, 1, 9, 0, 0);
		Set_Part(&V->P[11], -1.55, 0.5, 1.7, 0.1, 1, 0.7, 0, 9, 9);
		for (int i = 12; i < 15; i++)
			Set_Part(&V->P[i], 0, 1.5-(i*0.2), 4.4, 1, 0.1, 0.2, 0, 0, 0);
		Set_Part(&V->P[15], -1, -0.7, -2.5, 0.3, 0.3, 0.1, 9, 9, 9);
		Set_Part(&V->P[16], -0.6, -0.5, 4.4, 0.3, 0.3, 0.1, 9, 9, 9);
		Set_Part(&V->P[17], 1, -0.7, -2.5, 0.3, 0.3, 0.1, 9, 9, 9);
		Set_Part(&V->P[18], 0.6, -0.5, 4.4, 0.3, 0.3, 0.1, 9, 9, 9);
		for (int i = 0; i < 3; i++)
			Set_Rotation(&V->C[i].rotation, -90, 0, 0);
		Set_cylinder(&V->C[0], 0.8, 2, 0, -0.3, 4.3, 0, 0, 0);
		Set_cylinder(&V->C[1], 1.5, 4.8, 0, 1.2, 2.4, 9, 9, 0);
		for (int i = 2; i < 4; i++)
			Set_Rotation(&V->C[i].rotation, 0, 0, -90);
		for (int i = 4; i < 6; i++)
			Set_Rotation(&V->C[i].rotation, 0, 0, 90);
			Set_cylinder(&V->C[2], 0.7, 0.3, -1.7, -1.5, -1.4, 0, 0, 0);
			Set_cylinder(&V->C[4], 0.7, 0.3, 1.7, -1.5, -1.4, 0, 0, 0);
			Set_cylinder(&V->C[3], 0.7, 0.3, -1, -1.5, 3.5, 0, 0, 0);
			Set_cylinder(&V->C[5], 0.7, 0.3, 1, -1.5, 3.5, 0, 0, 0);
			Set_Ball(&V->balls[0], -1.7, -1.5, -1.4, 0.15, 9, 9, 9);
			Set_Ball(&V->balls[1], 1.7, -1.5, -1.4, 0.15, 9, 9, 9);
			Set_Ball(&V->balls[2], -1, -1.5, 3.5, 0.15, 9, 9, 9);
			Set_Ball(&V->balls[3], 1, -1.5, 3.5, 0.15, 9, 9, 9);
	}
}
void Set_SmallBalls(Plane *P, float x, float y, float z,int num) {
	Set_Location(&P->location, x, y, z);
	P->Flag = num;
	int r, g, b;
	if (P->Flag == 1) {r = 2; b = 0; g = 0;}
	if (P->Flag == 2) { r = 0; b = 1; g = 1; }
	if (P->Flag == 3) { r = 1; b = 4; g = 0; }
		Set_Ball(&P->B[0], 0, 0.3, -0.5, 0.1, r, g, b);
		Set_Ball(&P->B[1], -0.5, 0.3, -0.5, 0.1, r, g, b);
		Set_Ball(&P->B[2], 0.5, 0.3, -0.2, 0.1, r, g, b);
		Set_Ball(&P->B[3], -0.3, 0.5, 0.3, 0.1, r, g, b);
		Set_Ball(&P->B[4], 0, 0.5, 0.5, 0.1, r, g, b);
		Set_Ball(&P->B[5], 0.3, 0.5, 0, 0.1, r, g, b);
		Set_Ball(&P->B[6], -1, 0.3, -0.7, 0.1, r, g, b);
		Set_Ball(&P->B[7], -0.7, 0.5, 0.7, 0.1, r, g, b);
		Set_Ball(&P->B[8], 1, 0.3, 0.7, 0.1, r, g, b);
		Set_Ball(&P->B[9], 0.7, 0.5, -0.7, 0.1, r, g, b);
	

		P->B[3].jump = 9;
		P->B[4].jump = 9;
		P->B[5].jump = 9;
		P->B[8].jump = 9;
		P->B[9].jump = 9;
}

////////פונקציות אראיות על יצירת כל אוביקטים במשחק
void Draw_Shet7_Squar1(Part *P) {
	float x, y, z;
	x = P->size.x / 2;
	y = P->size.y / 2;
	z = P->size.z / 2;
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(x, -y, z);
	glVertex3f(x, -y, -z);
	glVertex3f(-x, -y, -z);
	glVertex3f(-x, -y, z);
	glEnd();
}
void Draw_Shet7_Squar2(Part *P) {
	Location_ON(&P->location);
	Color_ON(&P->color);
	Rotation_ON(&P->rotation);
	Draw_Shet7_Squar1(P);
	Rotation_OFF(&P->rotation);
	Location_OFF(&P->location);
}
void Draw_FlyPart_1(Part *P)
{
	float x, y, z;
	x = P->size.x / 2;
	y = P->size.y / 2;
	z = P->size.z / 2;

	glBegin(GL_QUADS);


	/////Front
	glNormal3f(0, 0, 1);
	glVertex3f(x / 2, y, z / 2);
	glVertex3f(x, -y, z);
	glVertex3f(-x, -y, z);
	glVertex3f(-x / 2, y, z / 2);

	////back
	glNormal3f(0, 0, 1);
	glVertex3f(x / 2, y, -z / 2);
	glVertex3f(x, -y, -z);
	glVertex3f(-x, -y, -z);
	glVertex3f(-x / 2, y, -z / 2);
	/////right
	glNormal3f(1, 0, 0);
	glVertex3f(x / 2, y, z / 2);
	glVertex3f(x / 2, y, -z / 2);
	glVertex3f(x, -y, -z);
	glVertex3f(x, -y, z);
	/////left
	glNormal3f(1, 0, 1);
	glVertex3f(-x / 2, y, z / 2);
	glVertex3f(-x / 2, y, -z / 2);
	glVertex3f(-x, -y, -z);
	glVertex3f(-x, -y, z);
	///////up
	glNormal3f(0, 1, 0);
	glVertex3f(x / 2, y, z / 2);
	glVertex3f(x / 2, y, -z / 2);
	glVertex3f(-x / 2, y, -z / 2);
	glVertex3f(-x / 2, y, z / 2);
	///////down
	glNormal3f(0, 1, 0);
	glVertex3f(x, -y, z);
	glVertex3f(x, -y, -z);
	glVertex3f(-x, -y, -z);
	glVertex3f(-x, -y, z);

	glEnd();

}
void Draw_FlyPart_2(Part *P) {
	Location_ON(&P->location);
	Color_ON(&P->color);
	Rotation_ON(&P->rotation);
	Draw_FlyPart_1(P);
	Rotation_OFF(&P->rotation);
	Location_OFF(&P->location);
}
void Draw_Part_1(Part *P)
{
	float x, y, z;
	x = P->size.x / 2;
	y = P->size.y / 2;
	z = P->size.z / 2;

	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glVertex3f(x, y, z);
	glVertex3f(x, -y, z);
	glVertex3f(-x, -y, z);
	glVertex3f(-x, y, z);

	glNormal3f(0, 0, 1);
	glVertex3f(x, y, -z);
	glVertex3f(x, -y, -z);
	glVertex3f(-x, -y, -z);
	glVertex3f(-x, y, -z);

	glNormal3f(1, 0, 0);
	glVertex3f(x, y, z);
	glVertex3f(x, y, -z);
	glVertex3f(x, -y, -z);
	glVertex3f(x, -y, z);

	glNormal3f(1, 0, 0);
	glVertex3f(-x, y, z);
	glVertex3f(-x, y, -z);
	glVertex3f(-x, -y, -z);
	glVertex3f(-x, -y, z);

	glNormal3f(0, 1, 0);
	glVertex3f(x, y, z);
	glVertex3f(x, y, -z);
	glVertex3f(-x, y, -z);
	glVertex3f(-x, y, z);

	glNormal3f(0, 1, 0);
	glVertex3f(x, -y, z);
	glVertex3f(x, -y, -z);
	glVertex3f(-x, -y, -z);
	glVertex3f(-x, -y, z);

	glEnd();

}
void Draw_Part_2(Part *P)
{
	Location_ON(&P->location);
	Rotation_ON(&P->rotation);
	Color_ON(&P->color);
	Draw_Part_1(P);
	Rotation_OFF(&P->rotation);
	Location_OFF(&P->location);
}
void draw_cylinder1(Cylinder *C)
{
	GLfloat x = 0.0;
	GLfloat z = 0.0;
	GLfloat angle = 0.0;
	GLfloat angle_stepsize = 0.1;

	/** Draw the tube */
	
	glBegin(GL_QUAD_STRIP);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = C->Radius * cos(angle);
		z = C->Radius * sin(angle);
		glVertex3f(x, C->height, z);
		glVertex3f(x, 0.0, z);
		angle = angle + angle_stepsize;
	}
	glVertex3f(C->Radius, C->height, 0.0);
	glVertex3f(C->Radius, 0.0, 0.0);
	glEnd();

	/** Draw the circle on top of cylinder */
	
	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = C->Radius * cos(angle);
		z = C->Radius * sin(angle);
		glVertex3f(x, 0, z);
		angle = angle + angle_stepsize;
	}
	glVertex3f(C->Radius, C->height, 0.0);
	glEnd();
}
void draw_cylinder2(Cylinder *C) {
	Location_ON(&C->location);
	Rotation_ON(&C->rotation);
	Color_ON(&C->color);
	draw_cylinder1(C);
	Rotation_OFF(&C->rotation);
	Location_OFF(&C->location);
}
void Draw_Tube1(Cylinder *C)
{
	GLfloat x = 0.0;
	GLfloat z = 0.0;
	GLfloat angle = 0.0;
	GLfloat angle_stepsize = 0.1;

	/** Draw the tube */

	glBegin(GL_QUAD_STRIP);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = C->Radius * cos(angle);
		z = C->Radius * sin(angle);
		glVertex3f(x, C->height, z);
		glVertex3f(x, 0.0, z);
		angle = angle + angle_stepsize;
	}
	glVertex3f(C->Radius, C->height, 0.0);
	glVertex3f(C->Radius, 0.0, 0.0);
	glEnd();
}
void Draw_Tube2(Cylinder *C)
{
	Location_ON(&C->location);
	Rotation_ON(&C->rotation);
	Color_ON(&C->color);
	Draw_Tube1(C);
	Rotation_OFF(&C->rotation);
	Location_OFF(&C->location);
}
void Draw_Half_Circle1(Shet7Circle *sh) {
	double a, x, y;
	glBegin(GL_POLYGON); /// glBegin(GL_LINE_LOOP);
	
		for (int i = 0; i <= 360; i++) {
			a = 3.14 * i;
			x = cos(a / 360);
			y = sin(a / 360);
			glVertex3d(0, x, y);
		
	}
		glEnd();
}
void Draw_Half_Circle2(Shet7Circle *sh) {
	Location_ON(&sh->location);
	Color_ON(&sh->color);
	Rotation_ON(&sh->rotation);
	Draw_Half_Circle1(sh);
	Rotation_OFF(&sh->rotation);
	Location_OFF(&sh->location);
}
void Draw_Block(Block *B) {
	Location_ON(&B->location);
	Rotation_ON(&B->rotation);
	Draw_Part_2(&B->P1);
	Draw_Part_2(&B->P2);
	draw_cylinder2(&B->C1);
	Rotation_OFF(&B->rotation);
	Location_OFF(&B->location);
}
void Draw_BlockUpDown(Block *B) {
	Location_ON(&B->location);
	Rotation_ON(&B->rotation);
	Draw_Part_2(&B->P1);
	Draw_Part_2(&B->P2);	
	draw_cylinder2(&B->C1);
	draw_cylinder2(&B->C2);
	draw_cylinder2(&B->C3);
	Rotation_OFF(&B->rotation);
	Location_OFF(&B->location);
}
void Draw_Ball(Ball *B)
{
	Location_ON(&B->location);
	Color_ON(&B->color);
	glutSolidSphere(B->Radius, 32, 32);
	Location_OFF(&B->location);

}
void Draw_BallCloud(Ball *B)
{
	Location_ON(&B->location);
	Color_ON(&B->color);
	glutSolidSphere(B->Radius, 5, 5);
	Location_OFF(&B->location);
}
void Draw_Pin(Pin *P) {
	Location_ON(&P->location);
	Rotation_ON(&P->rotation);
	Color_ON(&P->color);
	glutSolidCone(P->Base, P->Height, 10, 10);
	Rotation_OFF(&P->rotation);
	Location_OFF(&P->location);
}
void Draw_Pas(Pas *P){
	Location_ON(&P->location);
	Rotation_ON(&P->rotation);
	Draw_Part_2(&P->P1);
	for (int i = 0; i < 10; i++) {
		Draw_Pin(&P->pins[i]);
	}
	Rotation_OFF(&P->rotation);
	Location_OFF(&P->location);
}
void Draw_Rocket(Rocket *R) {
	Location_ON(&R->location);
	Rotation_ON(&R->rotation);
	for (int i = 0; i < 4; i++) {
		Rotation_ON(&R->Sh[i].rotation);
		Draw_Half_Circle2(&R->Sh[i]);
		Rotation_OFF(&R->Sh[i].rotation);
	}
	draw_cylinder2(&R->C1);
	Draw_Ball(&R->FrontB);
	for (int i = 0; i < 19; i++) 
		Draw_Pin(&R->pins[i]);
	Rotation_OFF(&R->rotation);
	Location_OFF(&R->location);
	
}
void Draw_Hammer(Shape1 *S)
{
	Location_ON(&S->location);
	Rotation_ON(&S->rotation);
	Draw_Part_2(&S->P1);
	Draw_Part_2(&S->P2);
	Draw_Part_2(&S->P3);
	Draw_Ball(&S->B1);
	Draw_Ball(&S->B2);
	Draw_Ball(&S->B3);
	Rotation_OFF(&S->rotation);
	Location_OFF(&S->location);
}
void Draw_UpDwon(Shape1 *S)
{
	Location_ON(&S->location);
	for (int i = 0; i < 15; i++) {
		Draw_Part_2(&S->P[i]);
	}
	Location_OFF(&S->location);
}
void Draw_OpenClose(OpenClose *Sh){
	Location_ON(&Sh->location);
	Rotation_ON(&Sh->rotation);
	draw_cylinder2(&Sh->C1);
	draw_cylinder2(&Sh->C2);
	draw_cylinder2(&Sh->C3);
	draw_cylinder2(&Sh->C4);
	Draw_Ball(&Sh->B1);
	Draw_Ball(&Sh->B2);
	Rotation_OFF(&Sh->rotation);
	Location_OFF(&Sh->location);
}
void Draw_Traps1(Shet7Circle *T) {
	double D, x, y;
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i++) {
		D = 3.14 * i;
		x = T->Radius*cos(D / 180);
		y = T->Radius*sin(D / 180);
		glVertex3d(x, y, 0);
	}
	Set_Part(&T->HitBox, 0, 0.1, 0, 1.3, 1.3, 0.1, 1, 1, 1);
	glEnd();
}
void Draw_Traps2(Shet7Circle *T)
{
	Location_ON(&T->location);
	Rotation_ON(&T->rotation);
	Color_ON(&T->color);
	Set_Rotation(&T->rotation, 90, 0, 0);
	Draw_Traps1(T);
	Rotation_OFF(&T->rotation);
	Location_OFF(&T->location);
}
void Draw_Fly(Fly *F) {
	Location_ON(&F->location);
	
	Draw_FlyPart_2(&F->F1);
	Draw_FlyPart_2(&F->F2);
	Draw_FlyPart_2(&F->F3);
	Draw_Part_2(&F->P1);
	Draw_Part_2(&F->P2);
	Draw_Part_2(&F->P3);
	Draw_Part_2(&F->P4);
	Draw_Part_2(&F->P5);
	Location_OFF(&F->location);
}
void Draw_BallLeftRight(Block *B) {
	Location_ON(&B->location);
	Rotation_ON(&B->rotation);
	for (int i = 0; i < 3; i++) {
		Draw_Ball(&B->balls[i]);
		draw_cylinder2(&B->C[i]);
	}
	Rotation_OFF(&B->rotation);
	Location_OFF(&B->location);
}
void Draw_Bridge(Shape1 *S) {
	Location_ON(&S->location);
	for (int i = 0; i < 25; i++) {
		Draw_Part_2(&S->P[i]);
	}
	Location_OFF(&S->location);
}
void Draw_Shet7Circle1(Shet7Circle *sh) {
	double D, x, z,y;
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i++) {
		D = 3.14 * i;
		x = sh->Radius*cos(D / 180);
		z =  sh->Radius*sin(D / 180);
		y = -2*sin(D / 180);
		glVertex3d(x, y, z);
	}
	glEnd();
	
}
void Draw_Shet7Circle2(Shet7Circle *sh) {
	Location_ON(&sh->location);
	Color_ON(&sh->color);
	Rotation_ON(&sh->rotation);
	Draw_Shet7Circle1(sh);
	Rotation_OFF(&sh->rotation);
	Location_OFF(&sh->location);
}
void Draw_Makok(Makok *M) {
	Location_ON(&M->location);
	Rotation_ON(&M->rotation);
	Set_Rotation(&M->rotation, 10, 0, 0);
	Draw_Ball(&M->B1);
	Draw_Shet7Circle2(&M->s1);
	Rotation_OFF(&M->rotation);
	Location_OFF(&M->location);
}
void Draw_Twoers(Tower *T) {
	Location_ON(&T->location);
	Rotation_ON(&T->rotation);
	for (int i = 0; i < 20; i++) {
		Set_Rotation(&T->C[i].rotation, 0, 180, 0);
		draw_cylinder2(&T->C[i]);
	}
	Rotation_OFF(&T->rotation);
	Location_OFF(&T->location);
	
}
void Draw_LeftRight(Block *B) {

	Location_ON(&B->location);
	Rotation_ON(&B->rotation);
	Set_Rotation(&B->rotation, 0, -180, 0);
	draw_cylinder2(&B->C1);
	draw_cylinder2(&B->C2);
	draw_cylinder2(&B->C3);
	Rotation_OFF(&B->rotation);
	Location_OFF(&B->location);
	
}
void Draw_PinsUpDown(Pas *P) {
	Location_ON(&P->location);
	Rotation_ON(&P->rotation);
	Draw_Part_2(&P->P1);
	Draw_Part_2(&P->P2);
	Draw_Part_2(&P->P3);
	for (int i = 0; i < 9; i++)
	{
		if (i<3)
		Draw_FlyPart_2(&P->P[i]);
		else if (i > 2 && i < 6)
			Draw_Part_2(&P->P[i]);
		else 
			Draw_FlyPart_2(&P->P[i]);

	}
	for (int i = 0; i < 9; i++) {
		Draw_Pin(&P->pins[i]);
	}
	Rotation_OFF(&P->rotation);
	Location_OFF(&P->location);
}
void Draw_BigBall(Rocket *B) {
	Location_ON(&B->location);
	Rotation_ON(&B->rotation);
	Draw_Ball(&B->FrontB);
	draw_cylinder2(&B->C1);
	Rotation_OFF(&B->rotation);
	Location_OFF(&B->location);
}
void Draw_4Balls(OpenClose *B) {
	Location_ON(&B->location);
	Rotation_ON(&B->rotation);
	Draw_Ball(&B->B1);
	Draw_Ball(&B->B2);
	Draw_Ball(&B->B3);
	Draw_Ball(&B->B4);
	Rotation_OFF(&B->rotation);
	Location_OFF(&B->location);
}
void Draw_CylinderPins(CylinderRor *C)
{
	Location_ON(&C->location);
	Rotation_ON(&C->rotation);
	for (int i = 0; i < 36; i++)
		Draw_Pin(&C->pins1[i]);
		draw_cylinder2(&C->C1);
	
	Rotation_OFF(&C->rotation);
	Location_OFF(&C->location);
}
void Draw_PinsOnFloor(CylinderRor *C)
{
	Location_ON(&C->location);
	Rotation_ON(&C->rotation);
	for (int i = 0; i <= 36; i++)
		Draw_Pin(&C->pins1[i]);
	Rotation_OFF(&C->rotation);
	Location_OFF(&C->location);
}
void Draw_CylinderPins2(CylinderRor *C) {
	Location_ON(&C->location);
	Rotation_ON(&C->rotation);
	draw_cylinder2(&C->C1);
	for (int i = 1; i < 64; i++) 
		Draw_Pin(&C->pins1[i]);
	Rotation_OFF(&C->rotation);
	Location_OFF(&C->location);
}
void Draw_Boomb(Block *B)
{
	Location_ON(&B->location);
	Rotation_ON(&B->rotation);
	Draw_Part_2(&B->P1);
	draw_cylinder2(&B->C1);
	Draw_Ball(&B->balls[0]);
	Rotation_OFF(&B->rotation);
	Location_OFF(&B->location);
}
void Draw_Life(Block *C) {
	Location_ON(&C->location);
	Rotation_ON(&C->rotation);
	draw_cylinder2(&C->C1);
	draw_cylinder2(&C->C2);
	draw_cylinder2(&C->C3);
	Draw_Part_2(&C->P1);
	Draw_Part_2(&C->P2);
	Rotation_OFF(&C->rotation);
	Location_OFF(&C->location);
}
void Draw_Coins(Block *C) {
	Location_ON(&C->location);
	Rotation_ON(&C->rotation);
	draw_cylinder2(&C->C1);
	draw_cylinder2(&C->C2);
	draw_cylinder2(&C->C3);
	draw_cylinder2(&C->C4);
	Draw_Part_2(&C->P1);
	Rotation_OFF(&C->rotation);
	Location_OFF(&C->location);
}
void Draw_CylinderFall(CylinderRor *B)
{
	Location_ON(&B->location);
	Rotation_ON(&B->rotation);
	draw_cylinder2(&B->C1);
	draw_cylinder2(&B->C2);
	draw_cylinder2(&B->C3);
	
	for(int i=0;i<19;i++)
	Draw_Pin(&B->pins1[i]);
	Rotation_OFF(&B->rotation);
	Location_OFF(&B->location);
}
void Draw_JumpOnCircle(Block *J)
{
	Location_ON(&J->location);
	Rotation_ON(&J->rotation);
		Draw_Part_2(&J->P1);
		Draw_Tube2(&J->C1);
	Rotation_OFF(&J->rotation);
	Location_OFF(&J->location);
}
void Draw_Plane(Plane *P)
{
	Location_ON(&P->location);
	Rotation_ON(&P->rotation);
	draw_cylinder2(&P->C1);
	Draw_Ball(&P->B1);
	Draw_Ball(&P->B2);
	Draw_Pin(&P->pin);
	Draw_FlyPart_2(&P->P1);
	Draw_FlyPart_2(&P->P2);
	Draw_FlyPart_2(&P->P3);
	for (int i = 0; i < 20; i++)
		Draw_Ball(&P->B[i]);
	Draw_Pin(&P->pin1);
	Draw_Pin(&P->pin2);
	Draw_Pin(&P->pin3);
	Draw_Pin(&P->pin4);
	Rotation_OFF(&P->rotation);
	Location_OFF(&P->location);
}
void Draw_WallOfPins(WAllOfPins *W) {
	Location_ON(&W->location);
	for (int i = 0; i < 4; i++){
		Draw_Part_2(&W->P[i]);
	
	}
	for (int i = 0; i <= 24; i++)
		Draw_Pin(&W->pin[i]);
	Location_OFF(&W->location);
}
void Draw_Laser(Laser *L) {
	Location_ON(&L->location);
	for (int i = 0; i < 6; i++) {
		Draw_Part_2(&L->part[i]);
		draw_cylinder2(&L->Cyl[i]);
	}
	Location_OFF(&L->location);
}
void Draw_PinsRain(Laser *L)
{
	Location_ON(&L->location);
	for (int i = 0; i < 6; i++) {
		Draw_Part_2(&L->part[i]);
		draw_cylinder2(&L->Cyl[i]);
		draw_cylinder2(&L->CylFloor[i]);
	}
	for (int i = 0; i < 30; i++) 
		Draw_Pin(&L->pins[i]);
	Location_OFF(&L->location);

}
void Draw_3Cylinders(Block *C) {
	Location_ON(&C->location);
	for (int i = 0; i < 9; i++) {		
		draw_cylinder2(&C->C[i]);	
	}

	Location_OFF(&C->location);
}
void Draw_Shoot(Plane *L) {
	Location_ON(&L->location);	

	draw_cylinder2(&L->C1);
	draw_cylinder2(&L->C2);
	for(int i=0;i<7;i++)
	Draw_Ball(&L->B[i]);
	Location_OFF(&L->location);
}
void Draw_Cloud(Plane *P){
	Location_ON(&P->location);
	for (int i = 0; i<12; i++)
		Draw_BallCloud(&P->B[i]);
	Location_OFF(&P->location);
}
void Draw_WarPlane(Plane *P) {
	Location_ON(&P->location);
	Rotation_ON(&P->rotation);
	draw_cylinder2(&P->C1);
	draw_cylinder2(&P->C2);
	Draw_Pin(&P->pin);
	Draw_Ball(&P->B1);
	Draw_Ball(&P->B[0]);
	Draw_Ball(&P->B[1]);
	Draw_FlyPart_2(&P->P2);
	Draw_FlyPart_2(&P->P1);
	Draw_Part_2(&P->P3);
	Draw_Part_2(&P->P4);
	for(int i=0;i<3;i++)
		Draw_FlyPart_2(&P->P[i]);
	Rotation_OFF(&P->rotation);
	Location_OFF(&P->location);
}
void Draw_Bird(Plane *P) {
	Location_ON(&P->location);
	Rotation_ON(&P->rotation);
	draw_cylinder2(&P->C1);
	draw_cylinder2(&P->C2);
	draw_cylinder2(&P->C3);
	Draw_Pin(&P->pin);
	Draw_Pin(&P->pin1);
	Draw_Ball(&P->B1);
	Draw_FlyPart_2(&P->P1);
	Draw_FlyPart_2(&P->P2);
	Draw_Part_2(&P->P3);
	Draw_Part_2(&P->P4);
	for(int i=0;i<3;i++)
	Draw_Ball(&P->B[i]);
	Rotation_OFF(&P->rotation);
	Location_OFF(&P->location);
}
void Draw_CircleRocket(Plane *P) {
	Location_ON(&P->location);
	Rotation_ON(&P->rotation);
	Draw_Ball(&P->B1);
	for (int i = 0; i<10; i++)
	Draw_Ball(&P->B[i]);
	Draw_Pin(&P->pin);
	draw_cylinder2(&P->C1);
	Draw_Part_2(&P->P2);
	Draw_Part_2(&P->P1);
	Draw_Part_2(&P->P3);
	Draw_Part_2(&P->P4);
	Rotation_OFF(&P->rotation);
	Location_OFF(&P->location);
}
void Draw_Volcan(Plane *P) {
	Location_ON(&P->location);
	Rotation_ON(&P->rotation);
	Draw_Ball(&P->B1);
	Draw_Pin(&P->pin);
	Draw_Pin(&P->pin1);
	Draw_Pin(&P->pin2);
	Draw_Pin(&P->pin3);
	Draw_Pin(&P->pin4);
	Draw_Pin(&P->pin5);
	Rotation_OFF(&P->rotation);
	Location_OFF(&P->location);
}
void Draw_Vichle(Vichle *V) {
	Location_ON(&V->location);
	Rotation_ON(&V->rotation);
	if(V->type==1){
	for (int i = 0; i < 4; i++) {
		draw_cylinder2(&V->C[i]);
		Draw_Ball(&V->balls[i]);
	}
		Draw_Part_2(&V->P[0]);
		Draw_FlyPart_2(&V->P[1]);
		for (int i = 2; i < 15; i++)
			Draw_Part_2(&V->P[i]);
		for (int i = 15; i < 19; i++)
			Draw_FlyPart_2(&V->P[i]);
	}
	 if (V->type == 2) {
		 for (int i = 0; i < 19; i++)
		Draw_Part_2(&V->P[i]);
		for (int i = 0; i < 6; i++)
		draw_cylinder2(&V->C[i]);
		for (int i = 0; i < 4; i++)
		Draw_Ball(&V->balls[i]);
	}
	Rotation_OFF(&V->rotation);
	Location_OFF(&V->location);

}
void Draw_SmallBalls(Plane *P) {
	Location_ON(&P->location);
	Rotation_ON(&P->rotation);
	for (int i = 0; i < 10; i++)
		Draw_Ball(&P->B[i]);
	Rotation_OFF(&P->rotation);
	Location_OFF(&P->location);
}

////////פונקציות אראיות על תנועות כל אוביקטים במשחק
void Volcano_Control(Plane *P,Ball *B) {
	P->location.z -= B->speed;
}
void UpDwon_Control(Shape1 *S)
{


	if (S->Flag == 0)

		S->P[14].location.y -= 0.03;
	else
		S->P[14].location.y += 0.03;

	if (S->P[14].location.y < 0.25)S->Flag = 1;
	if (S->P[14].location.y > 3.25)S->Flag = 0;

}
void Hammer_Control(Shape1 *S) {

	S->HitBoxPinFloor.location.x = 2 * -sin((PI*S->rotation.z/4) / 180);
	S->HitBoxPinFloor.location.y = 1.5 * cos((PI*S->rotation.z/4) / 180);
	if (S->Flag == 0)
		S->rotation.z+= 2;
	else
		S->rotation.z-= 2;
	if (S->rotation.z>55) {
		S->Flag = 1;
	}
	if (S->rotation.z<-55) {
		S->Flag = 0;
	}
}
void OpenClose_Control(OpenClose *O) {

	if (O->flag == 0) {
		O->C3.location.y-= 0.03;
		O->C4.location.y+= 0.03;
		O->HitBoxCyl[2].location.y -= 0.03;
		O->HitBoxCyl[3].location.y += 0.03;
	}
	else {
		O->C3.location.y+= 0.03;
		O->C4.location.y-= 0.03;
		O->HitBoxCyl[2].location.y += 0.03;
		O->HitBoxCyl[3].location.y -= 0.03;
	}

	if (O->C3.location.y<0.2)O->flag = 1;
	else if (O->C3.location.y  >2)O->flag = 0;

}
void Roket_Control(Rocket *R,Ball *B) {

	R->radius = R->Degree;
	R->xt = -0.1 * cos(R->radius / 180);
	R->yt = -0.07 * sin(R->radius / 180);
	R->Degree = R->Degree + 7;
	R->location.z -= B->speed;
	R->location.y += R->yt;
	R->location.x += R->xt;
	R->rotation.y++;
	if (R->Flag == 1) {
		R->pins[0].location.y+= 0.1;
		for (int i = 1; i < 8; i++)
			R->pins[i].location.y-= 0.1;
		for (int i = 8; i < 19; i++)
			R->pins[i].location.y+= 0.1;
	}
	else {
		R->pins[0].location.y-= 0.1;
		for (int i = 1; i < 8; i++)
			R->pins[i].location.y+= 0.1;
		for (int i = 8; i < 19; i++)
			R->pins[i].location.y-= 0.1;
	}
	if (R->pins[0].location.y >1.2)R->Flag = 0;
	if (R->pins[0].location.y < 0)R->Flag = 1;
}
void BlockUpDown_Control(Block *B) {
	if (B->Flag == 0) {
		B->C1.location.y -= 0.03;
		B->C3.location.y -= 0.03;
		B->C2.location.y += 0.03;
		B->HitBoxBlock1[0].location.y -= 0.03;
		B->HitBoxBlock1[1].location.y += 0.03;
		B->HitBoxBlock1[2].location.y -= 0.03;
	}
	else if (B->Flag == 1) {
		B->C1.location.y += 0.03;
		B->C3.location.y += 0.03;
		B->C2.location.y -= 0.03;
		B->HitBoxBlock1[0].location.y += 0.03;
		B->HitBoxBlock1[1].location.y -= 0.03;
		B->HitBoxBlock1[2].location.y += 0.03;
	}
	if (B->C1.location.y < 0.5)B->Flag = 1;
	if (B->C1.location.y > 2.5)B->Flag = 0;
}
void BallLeftRight_Control(Block *B) {
	if (B->Flag == 0){
		B->location.x -= 0.02;
	}
	else
		B->location.x += 0.02;
	if (B->location.x > 1.5)B->Flag = 0;
	if (B->location.x < -1.5)B->Flag = 1;


}
void PinsUpDown_Control(Pas *P) {
	if (P->flag1 == 0) {
		P->P[0].location.y -= 0.01;
		P->P[3].location.y -= 0.01;
		P->P[6].location.y -= 0.01;
		P->pins[0].location.y -= 0.01;
		P->pins[1].location.y -= 0.01;
		P->pins[2].location.y -= 0.01;
		P->HitBoxPin[0].location.y -= 0.01;
		
	}
	if (P->flag1 == 1) {
		P->P[0].location.y += 0.03;
		P->P[3].location.y += 0.03;
		P->P[6].location.y += 0.03;
		P->pins[0].location.y += 0.03;
		P->pins[1].location.y += 0.03;
		P->pins[2].location.y += 0.03;
		P->HitBoxPin[0].location.y += 0.03;
	
	}
	if (P->flag2 == 0) {
		P->P[1].location.y -= 0.01;
		P->P[4].location.y -= 0.01;
		P->P[7].location.y -= 0.01;
		P->pins[3].location.y -= 0.01;
		P->pins[4].location.y -= 0.01;
		P->pins[5].location.y -= 0.01;
		P->HitBoxPin[1].location.y -= 0.01;
		
	}
	if (P->flag2 == 1) {
		P->P[1].location.y += 0.03;
		P->P[4].location.y += 0.03;
		P->P[7].location.y += 0.03;
		P->pins[3].location.y += 0.03;
		P->pins[4].location.y += 0.03;
		P->pins[5].location.y += 0.03;
		P->HitBoxPin[1].location.y += 0.03;
		
	}
	if (P->flag3 == 0) {
		P->P[2].location.y -= 0.01;
		P->P[5].location.y -= 0.01;
		P->P[8].location.y -= 0.01;
		P->pins[6].location.y -= 0.01;
		P->pins[7].location.y -= 0.01;
		P->pins[8].location.y -= 0.01;
		P->HitBoxPin[2].location.y -= 0.01;
	}
	if (P->flag3 == 1) {
		P->P[2].location.y += 0.03;
		P->P[5].location.y += 0.03;
		P->P[8].location.y += 0.03;
		P->pins[6].location.y += 0.03;
		P->pins[7].location.y += 0.03;
		P->pins[8].location.y += 0.03;
		P->HitBoxPin[2].location.y += 0.03;
	}

	if (P->P[0].location.y > 8.7)P->flag1 = 0;
	if (P->P[6].location.y<2.6)P->flag1 = 1;

	if (P->P[1].location.y > 8.7)P->flag2 = 0;
	if (P->P[7].location.y<2.6)P->flag2 = 1;

	if (P->P[2].location.y > 8.7)P->flag3 = 0;
	if (P->P[8].location.y<2.6)P->flag3 = 1;
}
void BigBall_control(Rocket *B) {

	B->HitBoxPinFloor.location.x = -30 * sin((PI*B->Degree/5) / 180);
	B->HitBoxPinFloor.location.y = -30 * cos((PI*B->Degree/5) / 180);
	if (B->Flag == 0)
	{
		B->Degree += 0.5;
	}
	else
	{
		B->Degree -= 0.5;
	}
	if (B->Degree > 15)B->Flag = 1;
	if (B->Degree < -15)B->Flag = 0;

	
	if(B->Flag==0)
	B->rotation.z-= 0.5;
	else
		B->rotation.z+=0.5;
	if (B->rotation.z > 15)B->Flag = 1;
	if (B->rotation.z < -15)B->Flag = 0;
	
}
void CylinderPins_Control(CylinderRor *C) {
	C->rotation.x+=2;
}
void CylinderPins2_Control(CylinderRor *C) {
		C->rotation.y+=2;
		if(C->rotation.y>=360)C->rotation.y = 0;
}
void Boomb_Control(Block *B) {
	B->rotation.y+=1;
	if(B->rotation.y>360)
	B->rotation.y=0;
}
void JumpOnCircle_Control(Block *B)
{
	if (B->Flag == 0) {
		B->C1.location.x += 0.03;
		B->HitBoxBlock1[0].location.x += 0.03;
		B->HitBoxBlock1[1].location.x += 0.03;
		B->HitBoxBlock1[2].location.x += 0.03;
		B->HitBoxBlock2[0].location.x += 0.03;
	}
	else {
		B->C1.location.x -= 0.03;
		B->HitBoxBlock1[0].location.x -= 0.03;
		B->HitBoxBlock1[1].location.x -= 0.03;
		B->HitBoxBlock1[2].location.x -= 0.03;
		B->HitBoxBlock2[0].location.x -= 0.03;
	}
	if (B->C1.location.x > 3)B->Flag = 1;
	if (B->C1.location.x <-3)B->Flag = 0;
}
void Plane_Control(Plane *P, Ball *B) {
	if (P->Flag == 0)
		P->rotation.z += 0.1;
	else
		P->rotation.z -= 0.1;
	if (P->rotation.z > 7)P->Flag = 1;
	if (P->rotation.z <-7)P->Flag = 0;
	P->radius = P->Degree;
	P->xt = -0.1 * cos(P->radius / 180);
	P->yt = -0.07 * sin(P->radius / 180);
	P->Degree = P->Degree + 1;
	P->location.z -= B->speed;
	P->location.y += P->yt;
	P->location.x += P->xt;

	if (P->location.y >= 0 && P->rotation.x == 100) {
		P->rotation.x += 1;

		Set_Rotation(&P->rotation, P->rotation.x, 30, 0);
	}
	else if (P->location.y <= 0 && P->rotation.x == 70) {
		P->rotation.x -= 1;
		Set_Rotation(&P->rotation, P->rotation.x, 30, 0);
	}

}
void Makok_Control(Makok *M,Ball *B) {
	M->radius = M->Degree;
	M->xt = -0.1 * cos(M->radius / 180);
	M->yt = -0.1 * sin(M->radius / 180);
	M->Degree = M->Degree + 1;
	//M->location.z -= B->speed;
	M->location.z += M->yt;
	M->location.x += M->xt;
	

}
void bloton_Control(Ball *B,Ball *B1) {
	B->radius = B->Degree;
	B->xt = 0.1 * cos(B->radius / 180);
	B->yt = 0.1 * sin(B->radius / 180);
	B->Degree = B->Degree + 1;
	B->location.z += B->yt;
	B->location.x += B->xt;
	B->location.z += -B1->speed;
}
void moon_Control(Ball *M,Ball *B) {
	M->radius = M->Degree;
	M->xt = -0.1 * cos(M->radius / 180);
	M->yt = -0.1 * sin(M->radius / 180);
	M->Degree = M->Degree + 2;
	M->location.z += -B->speed;
	M->location.z += M->yt;
	M->location.x += M->xt;
}
void otared_Control(Ball *B,Ball *B1) {
	B->radius = B->Degree;
	B->xt = 0.15 * cos(B->radius / 180);
	B->yt = 0.25 * sin(B->radius / 180);
	B->Degree = B->Degree + 2;
	B->location.z += B->yt;
	B->location.x += B->xt;
	B->location.z += -B1->speed;
}
void Cylinder3_Control(Block *C) {
	if (C->fl1 == 0) {
		for (int i = 0; i < 3; i++)
			C->C[i].location.x += 0.05;
		C->HitBoxBlock1[0].location.x += 0.05;
	
	}
	if (C->fl1 == 1) {
		for (int i = 0; i < 3; i++) 
			C->C[i].location.x -= 0.05;
			C->HitBoxBlock1[0].location.x -= 0.05;
		
	}
	if (C->fl2 == 0) {
		for (int i = 3; i < 6; i++)
			C->C[i].location.x += 0.05;
		C->HitBoxBlock1[1].location.x += 0.05;
	}
	if (C->fl2 == 1) {
		for (int i = 3; i < 6; i++)
			C->C[i].location.x -= 0.05;
		C->HitBoxBlock1[1].location.x -= 0.05;
	}
	if (C->fl3 == 0) {
		for (int i = 6; i < 9; i++)
			C->C[i].location.x += 0.05;
		C->HitBoxBlock1[2].location.x += 0.05;
	}
	if (C->fl3 == 1) {
		for (int i = 6; i < 9; i++)
			C->C[i].location.x -= 0.05;
		C->HitBoxBlock1[2].location.x -= 0.05;
	}
	
	if (C->C[0].location.x > 2)C->fl1 = 1;	
	if (C->C[3].location.x > 2)C->fl2 = 1;
	if (C->C[6].location.x > 2) C->fl3 = 1;
	if (C->C[0].location.x < -2) C->fl1 = 0;
	if (C->C[3].location.x <-2) C->fl2 = 0;
	if (C->C[6].location.x <- 2) C->fl3 = 0;
}
void CircleRocket_Control(Plane *P,Ball *B) {
	if(P->Flag==0)P->location.y+= 0.04;
	else P->location.y-= 0.04;
	if (P->location.y > 10)P->Flag = 1;
	if (P->location.y <-5)P->Flag = 0;
	P->rotation.y+= 0.4;
	P->location.z -= B->speed;
}
void Bridge_Control(Shape1 *S, Ball *B) {
	int i;
	int a = 0;
	int e = 5;

	i = Randint(e, 9, 14);

	if (i % 2 != 0 && i != a) {
		a = i;
		if (B->location.z < S->location.z + 35 && B->location.z > S->location.z - 5) {
			if (S->P[i].location.y > 0.4)
				S->P[i].location.y -= 0.4;
		}
	}
	else {
		i = Randint(e, 9, 14);
	}

}
void Pas_Control(Pas *P, Ball *B) {
	if (B->location.z < P->location.z + 25) {
		for (int i = 0; i < 12; i++) {
			if (P->pins[i].location.y < 0)
				P->pins[i].location.y += 0.02;
		}
	}
}
void Balls4_Control(OpenClose *B, Ball *B1) {
	if (B1->location.z < B->location.z + 50)
	{
		B->B1.location.z += 0.1;
		B->B2.location.z += 0.1;
		B->B3.location.z += 0.1;
		B->B4.location.z += 0.1;
		for (int i = 0; i<4; i++)
			B->HitBoxCyl[i].location.z += 0.1;
	}

}
void CylinderFall_Control(CylinderRor *C, Ball *B) {
	if (B->location.z < C->location.z + 20 && C->rotation.x >0) {
		C->rotation.x--;
	}
}
void Fly_Control(Fly *F, Ball *B) {
	if (&F->Flag == 0)
	{
		F->P1.rotation.y -= 10;
		F->P2.rotation.y -= 10;
		F->P3.rotation.y -= 10;
		F->P4.rotation.y -= 10;

	}
	else
	{
		F->P1.rotation.y += 10;
		F->P2.rotation.y += 10;
		F->P3.rotation.y += 10;
		F->P4.rotation.y += 10;
	}
	if (B->location.z < F->location.z + 20 && F->F1.location.y >0.21)
	{
		F->F1.location.y -= 0.1;
		F->F2.location.y -= 0.1;
		F->F3.location.y -= 0.1;
	}
}
void WallOfPins_Control(WAllOfPins *W, Ball *B) {
	if (B->location.z < W->location.z + 10) {
		for (int i = 0; i < 2; i++)
			W->pin[i].location.z += 0.1;
		W->HitBoxWall[1].location.z += 0.1;
	}
	if (B->location.z < W->location.z + 20) {
		for (int i = 2; i < 4; i++)
			W->pin[i].location.z += 0.1;
		W->HitBoxWall[3].location.z += 0.1;
	}
	if (B->location.z < W->location.z + 30) {
		for (int i = 4; i < 6; i++)
			W->pin[i].location.z += 0.1;
		W->HitBoxWall[2].location.z += 0.1;
	}
	if (B->location.z < W->location.z + 40) {
		for (int i = 6; i < 24; i++)
			W->pin[i].location.z += 0.1;
		W->HitBoxWall[0].location.z += 0.1;
	}

}
void Laser_Control(Laser *L, Ball *B) {
	if (L->Type == 1) {
		if (B->location.z < L->location.z + 20) {
			for (int i = 0; i < 6; i += 2) {
				Set_cylinder(&L->Cyl[i + 1], 0.25, 25, -2.5 + (i*1.25), 0.7, 25, 9, 9, 0);
				Set_Part(&L->HitBox[i + 1], -2.5 + (i*1.25), 0.7, 12.5, 0.45, 0.45, 25, 1, 1, 1);
				if ((i + 1) % 3 == 0) {
					Set_cylinder(&L->Cyl[i + 1], 0.25, 25, -2.5 + (i*1.25), 0.7, 27, 9, 9, 0);
					Set_Part(&L->HitBox[i + 1], -2.5 + (i*1.25), 0.7, 14.5, 0.45, 0.45, 25, 1, 1, 1);
				}
			}
		}
	}
	if (L->Type == 2) {
		if (B->location.z < L->location.z + 20) {
			for (int i = 0; i < 4; i += 2) {
				Set_cylinder(&L->Cyl[i + 1], 0.25, 25, -1.5 + (i*1.5), 0.7, 25, 9, 9, 0);
				Set_Part(&L->HitBox[i + 1], -1.5 + (i * 1.5), 0.7, 12.5, 0.45, 0.45, 25, 1, 1, 1);
			}
		}
	}
	if (L->Type == 3) {
		if (B->location.z < L->location.z + 20) {
			Set_cylinder(&L->Cyl[1], 0.25, 25, 0, 0.7, 25, 9, 9, 0);
			Set_Part(&L->HitBox[1], 0, 0.7, 12.5, 0.45, 0.45, 25, 1, 1, 1);
		}
		if (L->Flag == 0)L->location.x += 0.01;
		if (L->Flag == 1)L->location.x -= 0.01;
		if (L->location.x > 1.5)L->Flag = 1;
		if (L->location.x < -1.5)L->Flag = 0;
	}
	if (L->Type == 4) {
		if (B->location.z < L->location.z + 20) {
			for (int i = 0; i < 6; i += 2) {
				Set_Part(&L->HitBox[i + 1], -1 + (i*0.5), 0.7, 12.5, 0.45, 0.45, 25, 1, 1, 1);
				Set_cylinder(&L->Cyl[i + 1], 0.25, 25, -1 + (i*0.5), 0.7, 25, 9, 9, 0);
			}
		}
	}
	if (L->Type == 5) {
		if (B->location.z < L->location.z + 20) {
			Set_Part(&L->HitBox[0], 0.45, 0.7, 0, 2.5, 0.3, 0.3, 1, 1, 1);
			Set_cylinder(&L->Cyl[0], 0.15, 2.5, 1.7, 0.7, 0, 9, 0, 0);
		}
	}

}
void PinRain_Control(Laser *L, Ball *B) {
	if (B->location.z < L->location.z + 40) {
		for (int i = 0; i < 30; i += 5) {
			L->pins[i].location.y -= 0.05;
			L->HitBox2[i].location.y -= 0.05;
		}
	}
	if (B->location.z < L->location.z + 30) {
		for (int i = 1; i < 30; i += 5) {
			L->pins[i].location.y -= 0.05;
			L->HitBox2[i].location.y -= 0.05;
		}
	}

	if (B->location.z < L->location.z + 20) {
		for (int i = 2; i < 30; i += 5) {
			L->pins[i].location.y -= 0.05;
			L->HitBox2[i].location.y -= 0.05;
		}
	}
	if (B->location.z < L->location.z + 10) {
		for (int i = 3; i < 30; i += 5) {
			L->pins[i].location.y -= 0.05;
			L->HitBox2[i].location.y -= 0.05;
		}
	}
	if (B->location.z < L->location.z) {
		for (int i = 4; i < 30; i += 5) {
			L->pins[i].location.y -= 0.05;
			L->HitBox2[i].location.y -= 0.05;
		}
	}
}
void Shoot_Control(Plane *L, Ball *B) {
	if (B->location.z < L->location.z + 30) {
		if (L->location.y<0.7)
			L->location.y += 0.01;
	}
	if (B->location.z < L->location.z + 20) {
		for (int i = 2; i < 5; i++) {
			L->B[i].location.z += 0.07;
			L->B[i].location.y -= 0.003;
			L->HitBox[i].location.z += 0.07;
			L->HitBox[i].location.y -= 0.003;
		}
	}


}
void Ball_Control(Ball *B,Part *P) {
	if (B->ready == 0)return;
	B->location.z += -B->speed;
	if(B->Status!=1)
	B->location.x += -(P->rotation.z * (0.007+B->speed*0.01));
	if (B->jump != 0)
	{
		if (B->jump < 20)
			B->location.y += (20 - B->jump)*0.01;
		else
			B->location.y += (B->jump - 20)*-0.01;
		B->jump++;
		B->jump %= 40;
	}
	if (B->Status == 1) {
		B->location.y -= B->speed;
		B->location.z += B->speed;

	}
	if (B->Status == 2 || B->Status == 4) {
		B->location.z += B->speed+0.015;
	}
	if (B->Status == 3) {
		B->location.z += B->speed;
	}
	if (B->Status == 5) {
		B->ballsSize -= 0.01;
		B->location.z += B->speed;
	}
	if (B->Status == 6)
		B->speed = 0;
}
void BallTrap_control(Shet7Circle *S,Ball *B) {
	if (B->Status == 5 && S->Shet7Size < 0.9) 
		S->Shet7Size += 0.02;	
}
void SmallBalls_control(Plane *P,Ball *B) {
	if (B->Status == 2) {
		P->location.z += 0.03;
		P->location.x += (B->location.x)*0.01;
		for (int i = 0; i < 10; i++)
			P->B[i].jump++;
		for (int i = 0; i < 10; i++) {
			if (P->B[i].jump != 0) {
				if (P->B[i].jump < 10)
					P->B[i].location.y += (10 - P->B[i].jump)*0.01;
				else
					P->B[i].location.y += (P->B[i].jump - 10)*-0.01;
				P->B[i].jump %= 19;
			}
		}
	}
	if (B->Status == 4) {
		
		for (int i = 0; i < 3; i++) {
			P->B[i].location.z += 0.2;
			P->B[i].location.y+= 0.2;
			P->B[i].location.x -= 0.2;
		}
		for (int i = 3; i < 6; i++) {
			P->B[i].location.z += 0.2;
			P->B[i].location.y += 0.2;
			P->B[i].location.x += 0.2;
		}
		for (int i = 6; i < 8; i++) {
			P->B[i].location.z -= 0.2;
			P->B[i].location.y += 0.2;
		
		}
		for (int i = 8; i < 10; i++) {
			P->B[i].location.y += 0.2;
			P->B[i].location.x -= 0.2;
		}
	}
}
void WarPlane_Control(Plane *P, int side,Ball *B) {
	if (side == 1) {
		if (B->location.z < P->location.z - 5) {
			int e = 1000;
			int f = 2000;
			Set_WarPlane(P, 5, Randint(f, 12, -7), -200 + B->location.z);
			f++;
		}
		if (P->Flag == 0)
			P->rotation.z += 0.1;
		else
			P->rotation.z -= 0.1;
		if (P->rotation.z > 7)P->Flag = 1;
		if (P->rotation.z <-7)P->Flag = 0;
		P->radius = P->Degree;
		P->xt = -0.001 * cos(P->radius / 180);
		P->yt = -0.007 * sin(P->radius / 180);
		P->Degree = P->Degree + 1;
		P->location.z += 0.3;
		P->location.y += P->yt;
		P->location.z += P->xt;
		P->P3.rotation.z += 5;
		P->P4.rotation.z += 5;
	}
	if (side == 2) {
		int e = 1000;
		int j = 2000;
		int f = 2000;
		if (B->location.z < P->location.z - 5) {

			Set_Plane(P, -15, Randint(f, -8, 2), -300 + B->location.z);
			Set_cylinder(&P->C1, 0.75, 5, 0, 5, 0, Randfloat(e) + 0.4, Randfloat(j) + 0.2, Randfloat(f) + 0.1);
			Set_Ball(&P->B2, 0, 5, 5, 0.75, Randfloat(e) + 0.4, Randfloat(j) + 0.2, Randfloat(f) + 0.1);
			f++;
			j--;
			e++;
		}
		if (P->Flag == 0)
			P->rotation.z += 0.1;
		else
			P->rotation.z -= 0.1;
		if (P->rotation.z > 7)P->Flag = 1;
		if (P->rotation.z <-7)P->Flag = 0;
		P->radius = P->Degree;
		P->xt = -0.001 * cos(P->radius / 180);
		P->yt = -0.007 * sin(P->radius / 180);
		P->Degree = P->Degree + 1;
		P->location.z += 0.3;
		P->location.y += P->yt;
		P->location.z += P->xt;
		Set_Rotation(&P->rotation, 0, 180, 0);
	}

}



////////פונקציות אראיות על התנגשות כל אוביקטים בכדור
int Hit(Part P1,Location L1,Part P2,Location L2)
{
	P1.location.x += L1.x;
	P1.location.y += L1.y;
	P1.location.z += L1.z;
	P2.location.x += L2.x;
	P2.location.y += L2.y;
	P2.location.z += L2.z;
	if (P1.location.x>(P2.location.x-P2.size.x/2-P1.size.x/2)&& P1.location.x<(P2.location.x + P2.size.x / 2 + P1.size.x / 2))
		if (P1.location.y>(P2.location.y - P2.size.y / 2 - P1.size.y / 2) && P1.location.y<(P2.location.y + P2.size.y / 2 + P1.size.y / 2))
			if (P1.location.z>(P2.location.z - P2.size.z / 2 - P1.size.z / 2) && P1.location.z<(P2.location.z + P2.size.z / 2 + P1.size.z / 2))
				return 1;
	return 0;
}
int HammerHit(Ball B, Shape1 S) {
	if (Hit(B.HitBox, B.location, S.HitBoxPinFloor, S.location))return 1;
	return 0;
}
int PinRainHit(Ball B, Laser L) {
	for (int i = 0; i<30; i++)
		if (Hit(B.HitBox, B.location, L.HitBox2[i], L.location))return 1;
	return 0;
}
int Cylinder3Hit(Ball B, Block P) {
	for (int i = 0; i<3; i++)
		if (Hit(B.HitBox, B.location, P.HitBoxBlock1[i], P.location))return 1;
	return 0;
}
int ShootHit(Ball B, Plane P) {
		for (int i = 0; i<5; i++)
			if (Hit(B.HitBox, B.location, P.HitBox[i], P.location))return 1;
		return 0;
}
int UpDownHit(Ball B,Shape1 S)
{
	for(int i=0;i<15;i++)
	if (Hit(B.HitBox, B.location, S.P[i], S.location))return 1;
	return 0;
}
int OpenCloseHit(Ball B, OpenClose sh)
{
	for (int i = 0; i<4; i++)
	if (Hit(B.HitBox, B.location, sh.HitBoxCyl[i], sh.location))return 1;
	
	return 0;
}
int PasHit(Ball B, Pas P)
{
		if (Hit(B.HitBox, B.location, P.HitBoxPin[0], P.location))return 1;

	return 0;
}
int BlockHit(Ball B, Block Bl) {
	if (Hit(B.HitBox, B.location, Bl.HitBoxBlock1[0], Bl.location))return 1;
	if (Hit(B.HitBox, B.location, Bl.P1,Bl.location))return 1;
	if (Hit(B.HitBox, B.location, Bl.P2, Bl.location))return 1;
	return 0;
}
int FlyHit(Ball B, Fly F) {
	if (Hit(B.HitBox, B.location, F.F1, F.location))return 1;
	if (Hit(B.HitBox, B.location, F.F2, F.location))return 1;
	if (Hit(B.HitBox, B.location, F.F3, F.location))return 1;
	return 0;
}
int BridgeHit(Ball B, Shape1 S) {
	for(int i=0;i<25;i++)
		if (Hit(B.HitBox, B.location, S.P[i], S.location))return 1;
	return 0;
}
int PinsOnFloorHit(Ball B, CylinderRor C) {
	if (Hit(B.HitBox, B.location, C.HitBoxPinFloor, C.location))return 1;
	return 0;
}
int HitBoxs(Ball B, Part P) {
	if (B.location.x>(P.location.x - P.size.x / 2 - B.HitBox.size.x / 2) && B.location.x<(P.location.x + P.size.x / 2 + B.HitBox.size.x / 2))
		if (B.location.y>(P.location.y - P.size.y / 2 - B.HitBox.size.y/ 2) && B.location.y<(P.location.y + P.size.y / 2 + B.HitBox.size.y / 2))
			if (B.location.z>(P.location.z - P.size.z / 2 - B.HitBox.size.z / 2) && B.location.z<(P.location.z + P.size.z / 2 + B.HitBox.size.z / 2))
				return 1;
	return 0;
}
int HitTowers(Ball B, Tower T) {
	for (int i = 0; i<10; i++)
		if (Hit(B.HitBox, B.location, T.HitBoxTower[i],T.location))return 1;
	return 0;
}
int BlockUpDownHit(Ball B, Block Bl) {
	for (int i = 0; i<3; i++)
	if (Hit(B.HitBox, B.location, Bl.HitBoxBlock1[i], Bl.location))return 1;
	if (Hit(B.HitBox, B.location, Bl.P1, Bl.location))return 1;
	if (Hit(B.HitBox, B.location, Bl.P2, Bl.location))return 1;
	return 0;
}
int PinsUpDownHit(Ball B, Pas P) {
	for (int i = 0; i<9; i++)
		if (Hit(B.HitBox, B.location, P.P[i], P.location))return 1;
	for (int i = 0; i<3; i++)
	if (Hit(B.HitBox, B.location, P.HitBoxPin[i], P.location))return 1;
	if (Hit(B.HitBox, B.location, P.P1, P.location))return 1;
	if (Hit(B.HitBox, B.location, P.P2, P.location))return 1;
	return 0;
}
int TowerFallHit(Ball B, Tower T) {
	for (int i = 0; i<3; i++)
		if (Hit(B.HitBox, B.location, T.HitBoxTower[i], T.location))return 1;
	return 0;
}
int FourBallHit(Ball B, OpenClose O){
	for (int i = 0; i<4; i++)
		if (Hit(B.HitBox, B.location, O.HitBoxCyl[i], O.location))return 1;
	return 0;
}
int CylinderPinsHit(Ball B, CylinderRor C) {
	if (Hit(B.HitBox, B.location, C.HitBoxPinFloor, C.location))return 1;
	return 0;
}
int CylinderPins2Hit(Ball B, CylinderRor C) {
	if (Hit(B.HitBox, B.location, C.HitBoxPinFloor, C.location))return 1;
	for (int i = 0; i<4; i++)
	if (Hit(B.HitBox, B.location, C.HitBoxPinCyl[i], C.location))return 1;
	return 0;
}
int BallLeftRightHit(Ball B, Block Bl) {
	for (int i = 0; i < 6; i++) {
		if (Hit(B.HitBox, B.location, Bl.HitBoxBlock1[i], Bl.location))return 1;
		if (Hit(B.HitBox, B.location, Bl.HitBoxBlock2[i], Bl.location))return 1;
	}
	return 0;
}
int LeftRightHit(Ball B, Block Bl) {
	for(int i=0;i<3;i++)
		if (Hit(B.HitBox, B.location, Bl.HitBoxBlock1[i], Bl.location))return 1;
	return 0;
}
int JumpOnCircleHit(Ball B, Block Bl) {
	for (int i = 0; i<3; i++)
		if (Hit(B.HitBox, B.location, Bl.HitBoxBlock1[i], Bl.location))return 1;
	if (Hit(B.HitBox, B.location, Bl.HitBoxBlock2[0], Bl.location))return 1;
	if (Hit(B.HitBox, B.location, Bl.P1, Bl.location))return 1;
	return 0;
}
int WallOfPinsHit(Ball B, WAllOfPins W) {
	for (int i = 0; i < 4; i++) {
		if (Hit(B.HitBox, B.location, W.HitBoxWall[i], W.location))return 1;
		if (Hit(B.HitBox, B.location, W.P[i], W.location))return 1;
		
	}
	return 0;
}
int CylinderFallHit(Ball B, CylinderRor C)
{
	if(Hit(B.HitBox, B.location, C.HitBoxPinFloor, C.location))return 1;
		return 0;
}
int BigBallHit(Ball B, Rocket R)
{
	if (Hit(B.HitBox, B.location, R.HitBoxPinFloor, R.location))return 1;
	return 0;
}
int CoinsHit(Ball B, Block B1)
{
	if (B1.Status == 1)return 0;
	if (Hit(B.HitBox, B.location,B1.HitBoxBlock1[0], B1.location))return 1;
	return 0;
}
int TrapHit(Ball B, Shet7Circle S) {
	if (Hit(B.HitBox, B.location, S.HitBox, S.location))return 1;
	return 0;
}
int LaserHit(Ball B, Laser L) {
	for (int i = 0; i < 6; i++) {
		if (Hit(B.HitBox, B.location, L.HitBox[i], L.location))return 1;
		if (Hit(B.HitBox, B.location, L.part[i], L.location))return 1;
	}
	return 0;
}

////////פונקציות אראיות על מיקום ויתירת ואתחול הכפתורם במשחק
void Set_Button(Button *btn, float x, float y, float size, float r, float g, float b,char *txt)
{
	int i = 0;
	while (*(txt + i) != 0)
		btn->txt[i] = *(txt + (i++));
	Set_Color(&btn->color, r, g, b);
	btn->x = x;
	btn->y = y;
	btn->Size = size;
}
void Draw_Button(Button *btn)
{
	Color_ON(&btn->color);
	glBegin(GL_LINE_LOOP);
	glVertex3f(btn->x + btn->Size, btn->y + btn->Size / 2, -5);
	glVertex3f(btn->x - btn->Size, btn->y + btn->Size / 2, -5);
	glVertex3f(btn->x - btn->Size, btn->y - btn->Size / 2, -5);
	glVertex3f(btn->x + btn->Size, btn->y - btn->Size / 2, -5);
	glEnd();

	btn->str = btn->txt;
	glColor3f(0, 0, 0);
	glRasterPos3f(btn->x - 0.3, btn->y, -5);
	do glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *btn->str);
	while (*(++btn->str));
}
int clickonbutton(Button *btn,int x,int y)
{
	if (x > 767.5 + (btn->x * 265) - 132.5&&x < 767.5 + (btn->x * 265) + 132.5)
		if (y > 430 + (btn->y *-150) - 75/2 &&y < 430 + (btn->y *-150) + 75/2)
			return 1;
	return 0;
}
////////פונקציות אראיות על יצירת ואתחול מחרוזות
void Typeing_String_IntoButton(char *name,char  ch)
{
	if (strlen(name) > 10)return;
	int i = 0;
	while (*(name + i) != 0)i++;
	*(name + (i++)) = ch;
	*(name + i) = 0;
}
void delete_char(char *name)
{
	strcpy(name, " ");
	name[0] = 0;
}
void Print_String(float x, float y, float z, float r, float g, float b, char *str)
{
	char *strP;
	strP = str;
	glColor3f(r, g, b);
	glRasterPos3f(x, y, z);
	do glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *strP);
	while (*(++strP));
}
void Print_String_int(float x, float y, float z, float r, float g, float b, char *str, int h)
{
	char *strP;
	char buffer[40];
	sprintf(buffer, str, h);
	strP = buffer;
	glColor3f(r, g, b);
	glRasterPos3f(x, y, z);
	do glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *strP);
	while (*(++strP));
}
////////פונקציות אראיות בדיקות הכנסה והרשמה של השחקן 
int Check_Player(char *name)
{
	FILE *file;
	char path[80]="";
	strcat(path, "players/");
	strcat(path, name);
	strcat(path, ".txt");
	file = fopen(path, "r");
	if (file != nullptr)
	{
		fclose(file);
		return 1;
	}
	return 0;
}
void In_Player(player *p)
{
	FILE *file;
	char path[80]="";
	strcat(path, "players/");
	strcat(path, p->name);
	strcat(path, ".txt");
	file = fopen(path, "w");
	fprintf(file, "%s\n", p->name);
	fprintf(file, "%s\n", p->pass);
	fprintf(file, "%d\n", p->score);
	fprintf(file, "%d\n", p->wins);
	fprintf(file, "%d\n", p->deaths);
	fclose(file);
}
int Create_New_Player(char *name,char *pass)
{
	if (Check_Player(name) == 1)return 0;
	player p;
	strcpy(p.name, name);
	strcpy(p.pass, pass);
	p.deaths = p.score = p.wins = 0;
	In_Player(&p);
	return 1;
}
player *Get_Player(char *name)
{
	FILE *file;
	player *p;
	char path[80]="";
	if (Check_Player(name) == 0)return nullptr;
	p = (player*)malloc(sizeof(player));
	strcat(path, "players/");
	strcat(path, name);
	strcat(path, ".txt");
	file = fopen(path, "r");
	fscanf(file, "%s", &p->name);
	fscanf(file, "%s", &p->pass);
	fscanf(file, "%d", &p->score);
	fscanf(file, "%d", &p->wins);
	fscanf(file, "%d", &p->deaths);
	fclose(file);
	return p;
}
int Login_Player(char *name, char *pass)
{
	if (Check_Player(name) == 0)return 0;
	player *p;
	p = Get_Player(name);
	puts(name);
	puts(pass);
	if (strcmp(pass, p->pass) != 0)
	{
		free(p);
		return 1;
	}
	free(p);
	return 2;
}

#include "Header.h"
//מספר מכשולים #define
#define Num_2_Of_Obstacle 2
#define Num_3_Of_Obstacle 3
#define Num_6_Of_Obstacle 6
#define Num_10_Of_Obstacle 10
#define Num_Of_stars 200
////
float Xstring = -2;//x ל הזזת המחרוזת בציר  
int rot;/// משתנה ל רוטציה של העולם
int fa, fd;// משתנים לתנועת המרחב (FLAGS)
int Level;// משתנה ל שלבי המשחק
int *arr;//מערך משתמשים בו לחילוק המכשולים על המרחב
int size = 0;//משתנה ששומר מספר מכשולים בכל שלב
char pass[20];//loginמחרוזת לדף     
char pass1[20];//registerמחרוזת לדף   
GLsizei WIDTH = 1500, HEIGHT = 1000;//משתנים לשמירת ערכי המסך  
Part Floor, shet7_floor1[5], shet7_floor2[500], Floor2, Street1, Street2;//לעיצוב המשחק ו של המרחב PART אוביקטים מסוג 
Part Boxs[Num_10_Of_Obstacle];// PART מכשול מסןג  
Ball ball;// הכדור של המשחק
Ball sun, moon, bloton, otared, sun2;//לעיצוב המשחק בשלב 1 
Location stars[Num_Of_stars];//לעיצוב המשחק בשלב 1
Shape1 UpDwon, hammer[5], bridge[Num_2_Of_Obstacle];// Shape1 כל המכשולים שמסוג   
Makok M1;//אובייקט לעיצוב המשחק בשלב 1
Fly Fly1[11], JumpFlor;// Fly כל המכשולים שמסוג  
Rocket R1;//לעיצוב המשחק בשלב 1 
Rocket BigBall[Num_6_Of_Obstacle];// Rocket כל המכשולים שמסוג  
Tower Towers[Num_2_Of_Obstacle];// Tower כל המכשולים שמסוג
OpenClose OpenCylinders[Num_2_Of_Obstacle], four_Balls[Num_2_Of_Obstacle];// OpenClose כל המכשולים שמסוג
Block block[Num_3_Of_Obstacle], Block_Up_Down[Num_2_Of_Obstacle];// Block  מכשולים שמסוג
Block  left_right[Num_2_Of_Obstacle], Ball_left_right[Num_2_Of_Obstacle] ;// Block  מכשולים שמסוג
Block Boom1[5], Life1[Num_2_Of_Obstacle], coins1[20];// Block  מכשולים שמסוג
Block JumpToCylinder[Num_2_Of_Obstacle], Jump3Cylinder, threeCyl[Num_2_Of_Obstacle];// Block  מכשולים שמסוג
Block  Boom2[Num_6_Of_Obstacle], Life2[Num_3_Of_Obstacle], coins2[30];//לשלב 2 ו 1 Block  מכשולים שמסוג
Block Coin, Boom, Life;//משתמשים בהם בדף ה מדע Block  מכשולים שמסוג
Pas Pas1[Num_2_Of_Obstacle], pinUpDown[Num_2_Of_Obstacle];// Pas כל המכשולים שמסוג
CylinderRor cylinderRor[Num_2_Of_Obstacle], PinsOnFloor1[8]; // CylinderRor כל המכשולים שמסוג
CylinderRor cylinderRor2[Num_3_Of_Obstacle], cylinderRor1[Num_3_Of_Obstacle]; // CylinderRor כל המכשולים שמסוג
CylinderRor cylinderFall[Num_2_Of_Obstacle];// CylinderRor כל המכשולים שמסוג
Plane plane, cloud[Num_10_Of_Obstacle], warPlane, bird1[Num_6_Of_Obstacle];
Plane shoot1[Num_2_Of_Obstacle], shoot2[Num_2_Of_Obstacle];//  לשלב 3 Block  מכשולים שמסוג
Plane shoot3[Num_2_Of_Obstacle], shoot4[Num_2_Of_Obstacle];//לשלב 3 Block  מכשולים שמסוג
Plane  plane2, vlocano;//עיצובים לשלב 3
Plane CircleRocket;//עיצובים לשלב 1
Plane smallBalls;// משתמשים בו לשנות צורת הכדור לצורת האוביקת הזה
Shet7Circle Traps[Num_10_Of_Obstacle], ballTrap; //לכל השלבים Shet7Circle  מכשולים שמסוג
WAllOfPins PinsWall[Num_3_Of_Obstacle];//WAllOfPins מכשול לשלב 3 מסוג 
Laser laser1[Num_6_Of_Obstacle], laser2[Num_6_Of_Obstacle], pinsRain[Num_2_Of_Obstacle];// Laser  מכשולים שמסוג
Vichle car[Num_3_Of_Obstacle], bus[Num_2_Of_Obstacle];// Vichle  אוביקטים לעיצוב בשלב 3
/////////////
Button start, Easy, Medium, Hard;// כפתורם בדף בחירת שלב והתחלת המשחק
Button Exit_Btn, Login_Name, Login_Pass, Login_Pagebtn, Reigster_Pagebtn, Information_Pagebtn;//mainpage
Button NewName, NamePass, Reigster_btn, Reigster_BackMain;//לחזרה לדף קודם וכפתורם לרישום שם וססמה וכפתור לשמירה אחרי רישום reigster pageכפתורם ב 
Button Information_BackMain;//Information_page בBackכפתור   
Button Login_BackMain;//login_page בBackכפתור  
char login_str[80] = "";//מחרוזת לשמירת פרטים login_page ב 
char register_str[80] = "";//מחרוזת לשמירת פרטים reigster page ב 
int type = 0;//משתנה מצב שעוזר במחיקת וקיתבת מחרוזות ומתי למחוק ולכתוב
int registerflag = 0;//משתנה עוזר ל לחיצת העכבר
int witchpage =0;//משתנה שומר באיזה דף נמצאים
int MaxScore = 0;//משתנה שומר ניקוד הכי גבוהה


void init_game();
//פונקציה ששומרת הניקוד אחרי סיום המשחק  
void Finsh_Game() {
	witchpage = 5;
	ball.Status = 0;
	if (ball.myplayer->score < (ball.coins + MaxScore)) {
		ball.myplayer->score = ball.coins + MaxScore;
		In_Player(ball.myplayer);
	}
}
//פונקציה למחיקת כל מה שרכתבנו בכל דף 
void Clear_str_Fucntion()
{
	strcpy(NewName.txt, " ");
	strcpy(NamePass.txt, " ");
	strcpy(login_str, " ");
	strcpy(register_str, " ");
	strcpy(Login_Name.txt, " ");
	strcpy(Login_Pass.txt, " ");
	Login_Pass.txt[0] = 0;
	NewName.txt[0] = 0;
	NamePass.txt[0] = 0;
	Login_Name.txt[0] = 0;
	login_str[0] = 0;
	register_str[0] = 0;
}
//פונקציה תיקוני המסך 
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLsizei)w / (GLsizei)h, 1, 100);
	glMatrixMode(GL_MODELVIEW);
	WIDTH = w;
	HEIGHT = h;
}
//פונקציה העכבר 
void ClickMouse(int btn, int state, int x, int y)
{

	if (clickonbutton(&start, x, y) && witchpage == 1)
	{
		MaxScore = 0;
		init_game();
		ball.lives = 3;
		ball.Status = 0;
		ball.coins = 0;
		Floor.location.x = 0;
		Floor.rotation.z = 0;
		ball.ballsSize = 0.3;
		ballTrap.Shet7Size = 0;
		for (int i = 0; i < 30; i++)
			coins2[i].Status = 0;
		for (int i = 0; i < 3; i++)
			Life2[i].Status = 0;
		for (int i = 0; i < 6; i++)
			Boom2[i].Status = 0;
		for (int i = 0; i < 5; i++)
			Boom1[i].Status = 0;
		Life1[0].Status = 0;
		Life1[1].Status = 0;
		for (int i = 0; i < 20; i++)
			coins1[i].Status = 0;
		witchpage = 2;
	}
	else if (clickonbutton(&Easy, x, y) && witchpage == 1) {

		Level = 1;
		Set_Color(&Easy.color, 1, 0, 0);
		Set_Color(&Hard.color, 1, 1, 1);
		Set_Color(&Medium.color, 1, 1, 1);
		ball.ready = 0;
	}
	else if (clickonbutton(&Medium, x, y) && witchpage == 1) {
		Level = 2;
		Set_Color(&Medium.color, 1, 0, 0);
		Set_Color(&Hard.color, 1, 1, 1);
		Set_Color(&Easy.color, 1, 1, 1);
		ball.ready = 0;
	}
	else if (clickonbutton(&Hard, x, y) && witchpage == 1) {
		Level = 3;

		Set_Color(&Hard.color, 1, 0, 0);
		Set_Color(&Easy.color, 1, 1, 1);
		Set_Color(&Medium.color, 1, 1, 1);
		ball.ready = 0;
	}
	else if (clickonbutton(&Login_BackMain, x, y) && witchpage == 1)
	{
		Clear_str_Fucntion();
		witchpage = 0;
	}
	else if (clickonbutton(&Reigster_Pagebtn, x, y) && witchpage == 0)
		witchpage = 3;
	else if (clickonbutton(&Login_Pagebtn, x, y) && witchpage == 0)
	{
		if (Login_Player(Login_Name.txt, pass1) == 0)
			strcpy(login_str, "Player Not FOund");
		if (Login_Player(Login_Name.txt, pass1) == 1)
			strcpy(login_str, "Password Is Wrong");
		if (Login_Player(Login_Name.txt, pass1) == 2)
		{
			witchpage = 1;
			ball.myplayer = Get_Player(Login_Name.txt);
			strcpy(login_str, "");
		}
	}
	else if (clickonbutton(&Information_Pagebtn, x, y) && witchpage == 0)
		witchpage = 4;
	else if (clickonbutton(&Login_Name, x, y) && witchpage == 0)
		type = 3;
	else if (clickonbutton(&Login_Pass, x, y) && witchpage == 0)
		type = 4;
	else if (clickonbutton(&Exit_Btn, x, y) && witchpage == 0)
		exit(1);
	else if (clickonbutton(&Reigster_BackMain, x, y) && witchpage == 3) {
		Clear_str_Fucntion();
		witchpage = 0;
	}
	else if (clickonbutton(&NewName, x, y) && witchpage == 3)
		type = 1;
	else if (clickonbutton(&NamePass, x, y) && witchpage == 3)
		type = 2;
	else if (clickonbutton(&Reigster_btn, x, y) && witchpage == 3)
	{
		if (registerflag != 0)return;
		if (strcmp(NewName.txt, "") == 0 || strcmp(NamePass.txt, "") == 0)
			strcpy(register_str, "Enter Name And Pass");
		else if (Create_New_Player(NewName.txt, pass) == 1)
			strcpy(register_str, "Registerd Successfuly");
		else
			strcpy(register_str, "Player Already Registerd");
		registerflag = 150;
		return;
	}
	else if (clickonbutton(&Information_BackMain, x, y) && witchpage == 4)
	{
		Clear_str_Fucntion();
		witchpage = 0;
	}
	else
		type = 0;

}
//פונקציה מיצרת כפתורם בדף בחירת שלב 
void tafret()
{
	Draw_Button(&start);
	Draw_Button(&Easy);
	Draw_Button(&Medium);
	Draw_Button(&Hard);
	Draw_Button(&Login_BackMain);
}
//פונקציה מחזירה מיקום המכשול 
int GiveEmptyIndex()
{
	int get = -1;
	while (get == -1)
	{
		int index;
		index = rand() % size;
		get = arr[index];
		arr[index] = -1;
	}
	return get;
}
//פונקציה לאיתחול הכוכבים 
void init_Stars() {
	int j = 1000;
	int e = 1000;
	int f = 2000;
	for (int i = 0; i<200; i++)
	{
		stars[i].x = Randint(e, 60, -30);
		stars[i].y = Randint(f, 40, -20);
		stars[i].z = Randintz(j, 500, 20);
		for (int k = 0; k < 200; k++) {
			if ((stars[i].x >= stars[k].x - 5 && stars[i].x <= stars[k].x + 5 && stars[i].z >= stars[k].z - 5 && stars[i].z <= stars[k].z + 5 && stars[i].y >= stars[k].y - 5 && stars[i].y <= stars[k].y + 5) && k != i) {
				e--;
				j++;
				f++;
				stars[i].x = Randint(e, 60, -30);
				stars[i].z = Randintz(j, 500, 20);
				stars[i].y = Randint(f, 40, -20);
				k = 0;
			}
		}

		j++;
		e--;
		f++;
	}
}
//פונקציה לאיתחול העננים 
void init_Cloud() {
	int j = 1000;
	int e = 1000;
	int f = 2000;
	for (int i = 0; i<Num_10_Of_Obstacle; i++)
	{
		Set_Cloud(&cloud[i], Randint(e, 60, -30), Randint(f, 15, 15), Randintz(j, 40, 20));
		cloud[i].location.y = 10;
		cloud[i].location.z = Randintz(j, 40, 20);
		for (int k = 0; k < 10; k++) {
			if ((cloud[i].location.x >= cloud[k].location.x - 5 && cloud[i].location.x <= cloud[k].location.x + 5 &&
				cloud[i].location.z >= cloud[k].location.z - 5 && cloud[i].location.z <= cloud[k].location.z + 5 &&
				cloud[i].location.y >= cloud[k].location.y - 5 && cloud[i].location.y <= cloud[k].location.y + 5) && k != i) {
				e--;
				j++;
				f++;
				Set_Cloud(&cloud[i], Randint(e, 60, -30), Randint(f, 15, 15), Randintz(j, 40, 20));
				k = 0;
			}
		}

		j++;
		e--;
		f++;
	}
}
//פונקציה לאיתחול הציפורים 
void init_Bird() {
	int j = 1000;
	int e = 1000;
	int f = 2000;
	for (int i = 0; i<6; i++)
	{
		Set_Bird(&bird1[i], Randint(e, 60, -30), Randint(f, 5, 7), Randintz(j, 40, 20));
		for (int k = 0; k < 6; k++) {
			if ((bird1[i].location.x >= bird1[k].location.x - 5 && bird1[i].location.x <= bird1[k].location.x + 5 &&
				bird1[i].location.z >= bird1[k].location.z - 5 && bird1[i].location.z <= bird1[k].location.z + 5 &&
				bird1[i].location.y >= bird1[k].location.y - 5 && bird1[i].location.y <= bird1[k].location.y + 5) && k != i) {
				e--;
				j++;
				f++;
				Set_Bird(&bird1[i], Randint(e, 60, -30), Randint(f, 5, 7), Randintz(j, 40, 20));
				k = 0;
			}
		}

		j++;
		e--;
		f++;
	}
}
//פונקציה לאיתחול כל האוביקטים במשחק בכל השלבים 
void init_game()
{

	int j = 1;
	int e = 50;
	int f = 2000;
	if (Level == 1) {
		init_Stars();
		ball.speed = 0.1;
		Set_CircleRocket(&CircleRocket, 15, 0, -30);
		for (int i = 0; i < 5; i++) {
			if (i < 3)
				Set_Fly(&Fly1[i], -2 + (i * 2), 0, -20);
			else if (i > 2 && i < 5)
				Set_Fly(&Fly1[i], -2 + ((i - 2.5) * 2), 0, -25);
		}
		Set_Fly(&Fly1[5], 2, 0, -205);
		Set_Fly(&Fly1[6], -1, 0, -205);
		Set_Fly(&Fly1[7], -0, 0, -210);
		Set_Fly(&Fly1[8], -2, 0, -210);
		Set_Fly(&Fly1[9], -1, 0, -215);
		Set_Fly(&Fly1[10], 2, 0, -215);

		Set_Life(&Life1[0], 1, 0, -315);
		Set_Life(&Life1[1], 2, 0, -120);

		Set_Block(&block[0], 0, 0, -45);
		Set_Block(&block[1], 0, 0, -225);
		Set_Block(&block[2], 0, 0, -390);

		Set_Shet7Circle(&Traps[0], 1.8, 0.1, -55, 0.9, 0, 0, 0);
		Set_Shet7Circle(&Traps[1], -1.8, 0.1, -60, 0.9, 0, 0, 0);
		Set_Shet7Circle(&Traps[2], 0, 0.1, -63, 0.9, 0, 0, 0);
		Set_Shet7Circle(&Traps[3], 1, 0.1, -90, 0.9, 0, 0, 0);
		Set_Shet7Circle(&Traps[4], 2.1, 0.1, -245, 0.9, 0, 0, 0);
		Set_Shet7Circle(&Traps[5], -2.1, 0.1, -245, 0.9, 0, 0, 0);
		Set_Shet7Circle(&Traps[6], 0, 0.1, -250, 0.9, 0, 0, 0);
		Set_Shet7Circle(&Traps[7], 2, 0.1, -390, 0.9, 0, 0, 0);
		Set_Shet7Circle(&Traps[8], -2, 0.1, -390, 0.9, 0, 0, 0);
		Set_Shet7Circle(&Traps[9], 0, 0.1, -410, 0.9, 0, 0, 0);

		Set_OpenClose(&OpenCylinders[0], 0, 0, -80);
		Set_OpenClose(&OpenCylinders[1], 0, 0, -290);

		Set_PinsOnFloor(&PinsOnFloor1[0], -2.3, 0, -95);
		Set_PinsOnFloor(&PinsOnFloor1[1], 1.5, 0, -105);
		Set_PinsOnFloor(&PinsOnFloor1[2], -1.5, 0, -110);
		Set_PinsOnFloor(&PinsOnFloor1[3], 0, 0, -195);
		Set_PinsOnFloor(&PinsOnFloor1[4], -2, 0, -300);
		Set_PinsOnFloor(&PinsOnFloor1[5], -2, 0, -303.6);
		Set_PinsOnFloor(&PinsOnFloor1[6], 1, 0, -300);
		Set_PinsOnFloor(&PinsOnFloor1[7], 1, 0, -303.6);


		Set_Hammer(&hammer[0], -1.8, 0, -255);
		Set_Hammer(&hammer[1], 1.5, 0, -265);
		Set_Hammer(&hammer[2], 0, 0, -275);
		Set_Hammer(&hammer[3], 1.5, 0, -375);
		Set_Hammer(&hammer[4], -1.5, 0, -375);


		Set_BigBall(&BigBall[0], 0, 31.8, -390);
		Set_BigBall(&BigBall[1], 0, 31.8, -370);
		BigBall[1].Flag = 1;
		Set_BigBall(&BigBall[2], 0, 31.8, -340);
		Set_UpDwon(&UpDwon, 0, 0, -320);

		Set_Boomb(&Boom1[0], 0, 0, -35);
		Set_Boomb(&Boom1[1], 1.8, 0, -70);
		Set_Boomb(&Boom1[2], -1.8, 0, -180);
		Set_Boomb(&Boom1[3], -2.1, 0, -250);
		Set_Boomb(&Boom1[4], -2, 0, -395);



		Set_Coins(&coins1[0], 1, 0, -20);
		Set_Coins(&coins1[1], 0, 0, -25);
		Set_Coins(&coins1[2], -1.8, 0, -66);
		Set_Coins(&coins1[3], -2.2, 0, -110);
		Set_Coins(&coins1[4], -1.8, 0, -140);
		Set_Coins(&coins1[5], -1.8, 0, -145);
		Set_Coins(&coins1[6], 0, 0, -150);
		Set_Coins(&coins1[7], 0, 0, -155);
		Set_Coins(&coins1[8], 1.5, 0, -165);
		Set_Coins(&coins1[9], 0, 0, -185);
		Set_Coins(&coins1[10], 1.8, 0, -200);
		Set_Coins(&coins1[11], 0, 0, -95);
		Set_Coins(&coins1[12], 0.5, 0, -205);
		Set_Coins(&coins1[13], -1, 0, -210);
		Set_Coins(&coins1[14], 0.5, 0, -215);
		Set_Coins(&coins1[15], 0, 0, -260);
		Set_Coins(&coins1[16], 1, 0, -280);
		Set_Coins(&coins1[17], 0.2, 0, -301);
		Set_Coins(&coins1[18], 0.2, 0, -303);
		Set_Coins(&coins1[19], 0.2, 0, -306);

		Set_Rocket(&R1, -15, 0, -30);
		Set_Ball(&moon, -20, 40, -60, 1, 1, 1, 1);
		Set_Makok(&M1, -20, 30, -50);
		Set_Ball(&bloton, 0, 40, -90, 3, 0.2, 0.9, 1);
		Set_Ball(&otared, -10, 25, -85, 2, 1, 0.6, 1);
		Set_Part(&Boxs[0], -1, 0.5, -140, 1, 1, 1, 1, 0, 0);
		Set_Part(&Boxs[1], 0, 0.5, -145, 1, 1, 1, 1, 1, 0);
		Set_Part(&Boxs[2], -2, 0.5, -150, 1, 1, 1, 1, 0, 1);
		Set_Part(&Boxs[3], -1.5, 0.5, -155, 1, 1, 1, 1, 0, 0);
		Set_Part(&Boxs[4], 1.5, 0.5, -160, 1, 1, 1, 1, 0, 1);
		Set_Part(&Boxs[5], 0, 0.5, -165, 1, 1, 1, 1, 0, 0);
		Set_Part(&Boxs[6], -2, 0.5, -170, 1, 1, 1, 1, 1, 0);
		Set_Part(&Boxs[7], 1.5, 0.5, -175, 1, 1, 1, 1, 0, 0);
		Set_Part(&Boxs[8], 0, 0.5, -180, 1, 1, 1, 1, 1, 0);
		Set_Part(&Boxs[9], -1.5, 0.5, -185, 1, 1, 1, 1, 0, 1);
		Set_Ball(&sun, -15, 30, -70, 7, 1, 0.8, 0);
		Set_Part(&Floor, 0, 0, -1250, 6, 0.1, 2500, 1, 0.7, 2);
		Set_Ball(&ball, 0, 0.3, 0, 0.3, 1, 0, 0);
	}
	if (Level == 2) {
		ball.speed = 0.15;
		size = 26;
		arr = (int*)malloc(sizeof(int)*size);
		int get;
		for (int i = 0; i < size; i++)
			arr[i] = ((i + 1)*-30);

		init_Cloud();
		init_Bird();
		for (int i = 0; i < 30; i++)
			Set_Coins(&coins2[i], Randint(e++, 2, -1), 0.1, Randintz(j++, 750, 20));
		for (int i = 0; i < Num_10_Of_Obstacle; i++)
			Set_Shet7Circle(&Traps[i], Randint(e++, 2, -1), 0.15, Randintz(j++, 750, 20), 0.9, 0, 0.7, 1);
		for (int i = 0; i < Num_6_Of_Obstacle; i++)
			Set_Boomb(&Boom2[i], Randint(e++, 2, -1), 0.1, Randintz(j++, 750, 20));
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Set_Laser(&laser1[i], Randint(e++, 2, -1), 0, GiveEmptyIndex(), 5);
		for (int i = Num_2_Of_Obstacle; i < Num_2_Of_Obstacle + 2; i++)
			Set_Laser(&laser1[i], Randint(e++, 2, -1), 0, GiveEmptyIndex(), 4);
		for (int i = Num_2_Of_Obstacle + 2; i < Num_6_Of_Obstacle; i++)
			Set_Laser(&laser1[i], 0, 0, GiveEmptyIndex(), 2);
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Set_BlockUpDown(&Block_Up_Down[i], 0, 0, GiveEmptyIndex());
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Set_Tower(&Towers[i], 0, 0, GiveEmptyIndex());
		for (int i = 0; i < Num_2_Of_Obstacle; i++) {
			int z = GiveEmptyIndex();
			Set_LeftRight(&left_right[i], 0, 0, z);
			Set_BallLeftRight(&Ball_left_right[i], 0, 5.8, z);
		}
		for (int i = 0; i < Num_3_Of_Obstacle; i++)
			Set_Life(&Life2[i], Randint(e++, 2, -1), 0.1, Randintz(j++, 740, 20));
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Set_Bridge(&bridge[i], 0, 0, GiveEmptyIndex());
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Set_4Balls(&four_Balls[i], 0, 0, GiveEmptyIndex());
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Set_CylinderFall(&cylinderFall[i], 0, 18, GiveEmptyIndex());
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Set_CylinderPins(&cylinderRor[i], 0, 0.5, GiveEmptyIndex());
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Set_Pas(&Pas1[i], 0, 0, GiveEmptyIndex());
		Set_Plane(&plane, -15, 0, -30);
		Set_Plane(&plane2, -10, 7, -65);
		Set_Ball(&sun2, 20, 30, -70, 5, 5, 5, 0);
		Set_Part(&Floor, 0, 0, -1250, 6, 0.1, 2500, 1, 4, 0);
		Set_Ball(&ball, 0, 0.3, 0, 0.3, 0, 1, 1);
		Set_WarPlane(&warPlane, 7, -4, -65);
	}

	if (Level == 3) {
		ball.speed = 0.2;
		size = 34;
		arr = (int*)malloc(sizeof(int)*size);
		for (int i = 0; i < size; i++)
			arr[i] = ((i + 1)*-35);
		for (int i = 0; i < 30; i++)
			Set_Coins(&coins2[i], Randint(e++, 2, -1), 0.1, Randintz(j++, 750, 20));
		for (int i = 0; i < Num_10_Of_Obstacle; i++)
			Set_Shet7Circle(&Traps[i], Randint(e++, 2, -1), 0.15, Randintz(j++, 750, 20), 0.9, 0, 0, 0);
		for (int i = 0; i < Num_6_Of_Obstacle; i++)
			Set_Boomb(&Boom2[i], Randint(e++, 2, -1), 0.1, Randintz(j++, 750, 20));
		for (int i = 0; i < Num_3_Of_Obstacle; i++)
			Set_Life(&Life2[i], Randint(e++, 2, -1), 0.1, Randintz(j++, 740, 20));
		Set_Part(&Floor2, 0, -7, -750, 100, 0.1, 1500, 0.2f, 1, 0.0f);
		Set_Ball(&sun2, 20, 30, -70, 5, 5, 5, 0);
		Set_Part(&Floor, 0, 0, -1250, 6, 0.1, 2500, 1, 4, 0);
		Set_Ball(&ball, 0, 0.3, 0, 0.3, 1, 0, 4);
		Set_Part(&Street2, 15, -7, -750, 0.7, 0.2, 1500, 9, 9, 9);
		Set_Part(&Street1, 15, -7, -750, 10, 0.2, 1500, 0, 0, 0);
		Set_Volcan(&vlocano, -15, -7, -70);
		Set_Vichle(&bus[1], 18, -5.1, -70, 2);
		Set_Vichle(&bus[0], 12, -5.1, -70, 2);
		Set_Vichle(&car[0], 12, -6.3, -50, 1);
		Set_Vichle(&car[1], 12, -6.3, -10, 1);
		Set_Vichle(&car[2], 18, -6.3, -10, 1);
		init_Cloud();
		init_Bird();
		for (int i = 0; i < Num_2_Of_Obstacle; i++) {
			int z = GiveEmptyIndex();
			Set_Shoot(&shoot1[i], 0, 0, z + 5);
			Set_Shoot(&shoot2[i], 2, 0, z + 5);
			Set_Shoot(&shoot3[i], -2, 0, z + 10);
			Set_Shoot(&shoot4[i], 0, 0, z + 15);
		}
		for (int i = 0; i < Num_3_Of_Obstacle; i++) {
			int z = GiveEmptyIndex();
			Set_CylinderPins2(&cylinderRor2[i], -1.5, 0, z - 15);
			Set_CylinderPins2(&cylinderRor1[i], 1.5, 0, z);
		}
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Set_CylinderPins(&cylinderRor[i], 0, 0.5, GiveEmptyIndex());
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Set_CylinderFall(&cylinderFall[i], 0, 18, GiveEmptyIndex());
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Set_4Balls(&four_Balls[i], 0, 0, GiveEmptyIndex());
		for (int i = 0; i < Num_3_Of_Obstacle; i++) {
			int z = GiveEmptyIndex();
			Set_BigBall(&BigBall[i], 0, 0, z + 15);
		}
		for (int i = Num_2_Of_Obstacle + 1; i < Num_6_Of_Obstacle; i++) {
			int z = GiveEmptyIndex();
			Set_BigBall(&BigBall[i], 0, 0, z + 15);
		}
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Set_Laser(&laser2[i], 0, 0, GiveEmptyIndex(), 1);
		for (int i = Num_2_Of_Obstacle; i < Num_2_Of_Obstacle + 2; i++)
			Set_Laser(&laser2[i], Randint(e++, 2, -1), 0, GiveEmptyIndex(), 3);
		for (int i = Num_2_Of_Obstacle + 2; i < Num_6_Of_Obstacle; i++)
			Set_Laser(&laser2[i], Randint(e++, 2, -1), 0, GiveEmptyIndex(), 4);
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Set_JumpOnCircle(&JumpToCylinder[i], 0, 0, GiveEmptyIndex());
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Set_PinsRain(&pinsRain[i], 0, 0, GiveEmptyIndex());
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Set_3Cylinders(&threeCyl[i], 0, 0, GiveEmptyIndex());
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Set_PinsUpDown(&pinUpDown[i], 0, 0, GiveEmptyIndex());
		for (int i = 0; i < Num_3_Of_Obstacle; i++)
			Set_WallOfPins(&PinsWall[i], 0, 0, GiveEmptyIndex());

	}
	for (int i = 0; i < 5; i++) {
		Set_Part(&shet7_floor1[i], -2 + i, 0.15, -1250, 0.1, 0.1, 2500, 0, 0, 0);
	}
	for (int i = 0; i < 500; i++) {
		Set_Part(&shet7_floor2[i], 0, 0.15, -0.05 - (i * 4), 6, 0.1, 0.1, 0, 0, 0);
	}

}
void keyboard(unsigned char key, int x, int y)
{
	if (key == 't')
		printf("%f", ball.location.z);
	if (witchpage == 5)
	{
		witchpage = 1;
		return;
	}
	if (type == 1)
	{
		if (key == 8)
			delete_char(NewName.txt);
		else
			Typeing_String_IntoButton(NewName.txt, key);
		return;
	}
	if (type == 2)
	{
		if (key == 8)
		{
			delete_char(NamePass.txt);
			delete_char(pass);
		}
		else
		{
			Typeing_String_IntoButton(pass, key);
			Typeing_String_IntoButton(NamePass.txt, '*');
		}
		return;
	}
	if (type == 3)
	{
		if (key == 8)
			delete_char(Login_Name.txt);
		else
			Typeing_String_IntoButton(Login_Name.txt, key);
		return;
	}
	if (type == 4)
	{
		if (key == 8)
		{
			delete_char(pass1);
			delete_char(Login_Pass.txt);
		}
		else
		{
			Typeing_String_IntoButton(pass1, key);
			Typeing_String_IntoButton(Login_Pass.txt, '*');
		}
		return;
	}
	if (key == 27)
	{
		if (witchpage == 2) {
			witchpage = 1;
			fa = fd = 0; ball.ready = 0;
		}
		else
			exit(1);
	}
	if (key == 'r'&&ball.ready == 0) {
		ball.ready = 1;
		ball.ballsSize = 0.3;
		ballTrap.Shet7Size = 0;
		return;
	}
	if (key == 'r'&&ball.Status != 0) {
		if (MaxScore < ball.location.z*-1)
			MaxScore = ball.location.z*-1;
		ball.location.z = 0;
		ball.location.x = 0;
		Xstring = -2;
		fa = fd = 0;

		Floor.rotation.z = 0;
		ball.location.y = 0.3;
		ball.lives--;
		if (ball.lives == 0 || (Level == 2 && ball.Status == 6) || (Level == 1 && ball.Status == 6) || (Level == 3 && ball.Status == 6))
		{
			Finsh_Game();
		}

		ball.Status = ball.ready = 0;
		init_game();
		return;
	}
	if (key == ' ')
	{
		if (ball.jump != 0)return;
		ball.jump = 1;
	}
	if (key == 'w')
	{
		if (ball.speed < 0.3)
			ball.speed += 0.01;
	}
	if (key == 's')
	{
		if (ball.speed > 0.1)
			ball.speed -= 0.01;
	}

	if (key == 'a') {
		fa = 1; fd = 0;
	}
	if (key == 'd')
	{
		fa = 0; fd = 1;
	}

}
//פונקציה ליצירת אוביקט הכוכבים 
void drawStars() {
	for (int i = 0; i<200; i++)
	{

		glTranslatef(stars[i].x, stars[i].y, stars[i].z);
		glColor3f(1, 1, 1);
		glutSolidSphere(0.09, 5, 5);
		glTranslatef(-stars[i].x, -stars[i].y, -stars[i].z);
	}
}
// פונקציה ליצירת כל האוביקטים בכל השלבים
void gamegame()
{
	Print_String_int(-2.5, 2.2, -5, 9, 0, 0, "Lives : %d", ball.lives);
	Print_String_int(-2.5, 2, -5, 9, 0, 0, "Max : %d", MaxScore);
	Print_String_int(-2.5, 1.8, -5, 9, 0, 0, "Score : %d", -ball.location.z);
	Print_String_int(-2.5, 1.6, -5, 9, 0, 0, "Bonus : %d", ball.coins);
	if (ball.Status != 0 && ball.Status != 6 && ball.location.z != 0) {
		Print_String(Xstring += 0.01, 0, -5, 9, 0, 0, "You Lose!...Press 'r'");
	}
	if (Level == 2) {
		if (ball.location.z < -800)
			Print_String(Xstring += 0.01, 0, -5, 2, 0, 0, "you win...Press r to Exist");
	}
	if (Level == 1) {
		if (ball.location.z < -425)
			Print_String(Xstring += 0.01, 0, -5, 2, 0, 0, "you win...Press r to Exist");
	}
	if (Level == 3) {
		if (ball.location.z < -1225)
			Print_String(Xstring += 0.01, 0, -5, 2, 0, 0, "you win...Press r to Exist");
	}
	glTranslatef(0, -4, -(ball.location.z + 10));
	glRotatef(rot, 1, 0, 0);
	if (Level == 1) {
		Draw_Makok(&M1);
		Draw_Ball(&moon);
		Draw_Rocket(&R1);
		Draw_Ball(&sun);
		Draw_Ball(&bloton);
		Draw_Ball(&otared);
	}
	if (Level == 2) {

		Draw_Plane(&plane);
		Draw_Plane(&plane2);
		for (int i = 0; i<Num_6_Of_Obstacle; i++)
			Draw_Bird(&bird1[i]);
		Draw_WarPlane(&warPlane);
		for (int i = 0; i<Num_10_Of_Obstacle; i++)
			Draw_Cloud(&cloud[i]);
		Draw_Ball(&sun2);
	}
	if (Level == 3) {
		for (int i = 0; i < Num_3_Of_Obstacle; i++)
			Draw_Vichle(&car[i]);
		Draw_Vichle(&bus[0]);
		Draw_Vichle(&bus[1]);
		Draw_Plane(&plane2);
		Draw_Part_2(&Street2);
		Draw_Part_2(&Street1);
		for (int i = 0; i<Num_6_Of_Obstacle; i++)
			Draw_Bird(&bird1[i]);
		for (int i = 0; i<Num_10_Of_Obstacle; i++)
			Draw_Cloud(&cloud[i]);
		Draw_Part_2(&Floor2);
		Draw_Volcan(&vlocano);
		Draw_Ball(&sun2);
		glClearColor(0, 0.7, 1, 0.0f);
	}
	Draw_Part_2(&Floor);
	///////////////////////////////////////////
	Rotation_ON(&Floor.rotation);
	if (Level == 1) {
		drawStars();
		Draw_CircleRocket(&CircleRocket);
		for (int i = 0; i < Num_10_Of_Obstacle; i++) {
			Draw_Part_2(&Boxs[i]);
			Draw_Traps2(&Traps[i]);
		}
		for (int i = 0; i < Num_10_Of_Obstacle + 1; i++)
			Draw_Fly(&Fly1[i]);
		for (int i = 0; i < Num_3_Of_Obstacle; i++)
			Draw_Block(&block[i]);
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			Draw_OpenClose(&OpenCylinders[i]);
		for (int i = 0; i < 8; i++)
			Draw_PinsOnFloor(&PinsOnFloor1[i]);
		for (int i = 0; i < 5; i++)
			Draw_Hammer(&hammer[i]);
		for (int i = 0; i < Num_3_Of_Obstacle; i++)
			Draw_BigBall(&BigBall[i]);
		for (int i = 0; i < 20; i++) {
			if (coins1[i].Status == 0)
				Draw_Coins(&coins1[i]);
			if (i < 5 && Boom1[i].Status == 0)
				Draw_Boomb(&Boom1[i]);
		}
		if (Life1[0].Status == 0)
			Draw_Life(&Life1[0]);
		if (Life1[1].Status == 0)
			Draw_Life(&Life1[1]);
		Draw_UpDwon(&UpDwon);
		glClearColor(0, 0, 0.2, 0.0f);

	}
	if (Level == 2) {
		for (int i = 0; i < 30; i++)
			if (coins2[i].Status == 0)
				Draw_Coins(&coins2[i]);
		for (int i = 0; i < Num_10_Of_Obstacle; i++)
			Draw_Traps2(&Traps[i]);
		for (int i = 0; i < Num_6_Of_Obstacle; i++) {
			Draw_Laser(&laser1[i]);
			if (Boom2[i].Status == 0)
				Draw_Boomb(&Boom2[i]);
		}
		for (int i = 0; i < Num_3_Of_Obstacle; i++)
			if (Life2[i].Status == 0)
				Draw_Life(&Life2[i]);

		for (int i = 0; i < Num_2_Of_Obstacle; i++) {
			Draw_Twoers(&Towers[i]);
			Draw_BlockUpDown(&Block_Up_Down[i]);
			Draw_Pas(&Pas1[i]);
			Draw_4Balls(&four_Balls[i]);
			Draw_LeftRight(&left_right[i]);
			Draw_BallLeftRight(&Ball_left_right[i]);
			Draw_CylinderPins(&cylinderRor[i]);
			Draw_Bridge(&bridge[i]);
			Draw_CylinderFall(&cylinderFall[i]);
		}
		glClearColor(0.0f, 0.7f, 1.0f, 0.0f);
	}
	if (Level == 3) {
		for (int i = 0; i < Num_6_Of_Obstacle; i++)
			Draw_BigBall(&BigBall[i]);
		for (int i = 0; i < Num_3_Of_Obstacle; i++)
			Draw_CylinderPins2(&cylinderRor1[i]);
		for (int i = 0; i < 30; i++)
			if (coins2[i].Status == 0)
				Draw_Coins(&coins2[i]);
		for (int i = 0; i < Num_10_Of_Obstacle; i++)
			Draw_Traps2(&Traps[i]);
		for (int i = 0; i < Num_6_Of_Obstacle; i++) {
			Draw_Laser(&laser2[i]);
			if (Boom2[i].Status == 0)
				Draw_Boomb(&Boom2[i]);
		}
		for (int i = 0; i < Num_2_Of_Obstacle; i++) {
			Draw_Shoot(&shoot1[i]);
			Draw_Shoot(&shoot2[i]);
			Draw_Shoot(&shoot3[i]);
			Draw_Shoot(&shoot4[i]);
			Draw_PinsRain(&pinsRain[i]);
			Draw_3Cylinders(&threeCyl[i]);
			Draw_JumpOnCircle(&JumpToCylinder[i]);
			Draw_PinsUpDown(&pinUpDown[i]);
			Draw_4Balls(&four_Balls[i]);
			Draw_CylinderFall(&cylinderFall[i]);
			Draw_CylinderPins(&cylinderRor[i]);
		}
		for (int i = 0; i < Num_3_Of_Obstacle; i++) {
			Draw_WallOfPins(&PinsWall[i]);
			Draw_CylinderPins2(&cylinderRor2[i]);
			if (Life2[i].Status == 0)
				Draw_Life(&Life2[i]);
		}
	}

	if (ball.Status == 0 || ball.Status == 5 || ball.Status == 1)
		Draw_Ball(&ball);
	if (ball.Status == 2 || ball.Status == 4)
		Draw_SmallBalls(&smallBalls);
	if (ball.Status == 3 || ball.Status == 5)
		Draw_Traps2(&ballTrap);
	for (int i = 0; i < 5; i++)
		Draw_Shet7_Squar2(&shet7_floor1[i]);
	for (int i = 0; i < 500; i++)
		Draw_Shet7_Squar2(&shet7_floor2[i]);
}
// פונקציה ליצירת המחרוזות על המסך אחרי סיום המשחק
void Final()
{
	if (ball.lives != 0) {
		Print_String(0, 1, -5, 9, 0, 0, "Nice Work");
		Print_String(0.5, 1, -5, 9, 0, 0, ball.myplayer->name);
		Print_String(0, 0, -5, 9, 0, 0, "you win");
	}
	else {
		Print_String(-0, 1, -5, 9, 0, 0, "Game Over");
		Print_String(-0, 0, -5, 9, 0, 0, "you didnt get to the end");
	}
	Print_String(0, 2, -5, 9, 0, 0, "Name:");
	Print_String(0.25, 2, -5, 9, 0, 0, ball.myplayer->name);
	Print_String_int(0, 1.8, -5, 9, 0, 0, "Score : %d", ball.coins + MaxScore);
}
//פונקציה ליצירת המחרוזות והכפתורם על המסך בדף המדע
void Information_page()
{
	Set_Coins(&Coin, 7, 5, -15);
	Set_Boomb(&Boom, 7, 3, -15);
	Set_Life(&Life, 7, 2, -15);
	Draw_Button(&Information_BackMain);
	Print_String(-2.5, 2, -5, 0, 0, 0, "Move tips:");
	Print_String(-2.5, 1.5, -5, 0, 0, 0, "Press 'a' to rotate the floor left");
	Print_String(-2.5, 1, -5, 0, 0, 0, "Press 'd' to rotate the floor right");
	Print_String(-2.5, 0.5, -5, 0, 0, 0, "press 'w' to increase the ball speed");
	Print_String(-2.5, 0, -5, 0, 0, 0, "press 's' to decrease the ball speed");
	Print_String(-2.5, -0.5, -5, 0, 0, 0, "press space to jump");
	Print_String(0.5, 1.8, -5, 0, 0, 0, "coins: will give you a bunos");
	Print_String(0.5, 1.2, -5, 0, 0, 0, "Boom: will destroy you");
	Print_String(0.5, 0.7, -5, 0, 0, 0, "Life: will give you more chance to play");
	Print_String(0, 0, -5, 0, 0, 0, "try to cross all the obstacles until you get to the end ");
	Draw_Coins(&Coin);
	Draw_Boomb(&Boom);
	Draw_Life(&Life);
}
//פונקציה ליצירת המחרוזות והכפתורם על המסך בדף הרשמה
void Register_Page()
{
	Draw_Button(&NewName);
	Draw_Button(&NamePass);
	Draw_Button(&Reigster_btn);
	Draw_Button(&Reigster_BackMain);
	Print_String(0, 0, -5, 0, 0, 0, register_str);
	Print_String(-0.5, 1, -5, 0, 0, 0, "Player Pass : ");
	Print_String(-0.5, 2, -5, 0, 0, 0, "Player Name : ");

}
//פונקציה ליצירת המחרוזות והכפתורם על המסך בדף הראשי
void Main_Page()
{
	glClearColor(0, 0.7, 0.2, 0);
	Draw_Button(&Login_Pagebtn);
	Draw_Button(&Information_Pagebtn);
	Draw_Button(&Reigster_Pagebtn);
	Draw_Button(&Login_Name);
	Draw_Button(&Login_Pass);
	Draw_Button(&Exit_Btn);
	Print_String(1, -1, -5, 0, 0, 0, login_str);
	Print_String(0, 2, -5, 0, 0, 0, "Player Name: ");
	Print_String(0, 1, -5, 0, 0, 0, "Player Pass: ");

}
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT |
		GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glClearColor(0, 0.7, 0.2, 0);
	if (witchpage == 0)
		Main_Page();
	else if (witchpage == 1)
		tafret();
	else if (witchpage == 2)
		gamegame();
	else if (witchpage == 3)
		Register_Page();
	else if (witchpage == 4)
		Information_page();
	else if (witchpage == 5)
		Final();

	glutSwapBuffers();
}
////////פונקציות אראית על תנועות אוביקטים העיצוב
void Cloude_Control() {
	for (int i = 0; i < 10; i++) {
		if (ball.location.z < cloud[i].location.z + 5) {
			int j = 1000;
			int e = 1000;
			int f = 2000;
			Set_Cloud(&cloud[i], Randint(e, 60, -30), Randint(f, 10, 10), Randintz(j, ball.location.z - 50, 40));
			for (int k = 0; k < 10; k++) {
				if ((cloud[i].location.x >= cloud[k].location.x - 5 && cloud[i].location.x <= cloud[k].location.x + 5 &&
					cloud[i].location.z >= cloud[k].location.z - 5 && cloud[i].location.z <= cloud[k].location.z + 5 &&
					cloud[i].location.y >= cloud[k].location.y - 5 && cloud[i].location.y <= cloud[k].location.y + 5) && k != i) {
					e--;
					j++;
					f++;
					Set_Cloud(&cloud[i], Randint(e, 60, -30), Randint(f, 10, 10), Randintz(j, ball.location.z - 50, 40));
					k = 0;
				}
			}
			j++;
			e--;
			f++;
		}
	}

}
void Bird_Control(Plane *P) {
	for (int i = 0; i < Num_6_Of_Obstacle; i++) {
		if (ball.location.z < bird1[i].location.z + 5) {
			int j = 1000;
			int e = 1000;
			int f = 2000;
			Set_Bird(&bird1[i], Randint(e, 60, -30), Randint(f, 3, 2), Randintz(j, ball.location.z - 90, 20));
			for (int k = 0; k < Num_6_Of_Obstacle; k++) {
				if ((bird1[i].location.x >= bird1[k].location.x - 5 && bird1[i].location.x <= bird1[k].location.x + 5 &&
					bird1[i].location.z >= bird1[k].location.z - 5 && bird1[i].location.z <= bird1[k].location.z + 5 &&
					bird1[i].location.y >= bird1[k].location.y - 5 && bird1[i].location.y <= bird1[k].location.y + 5) && k != i) {
					e--;
					j++;
					f++;
					Set_Bird(&bird1[i], Randint(e, 60, -30), Randint(f, 3, 2), Randintz(j, ball.location.z - 90, 20));
					k = 0;
				}
			}

			j++;
			e--;
			f++;
		}
	}

	if (P->Flag == 0) {
		P->P1.rotation.y += 7;
		P->P2.rotation.y -= 7;
	}
	else {
		P->P1.rotation.y -= 7;
		P->P2.rotation.y += 7;
	}
	if (P->P1.rotation.y > 20)P->Flag = 1;
	if (P->P1.rotation.y <-30)P->Flag = 0;
	P->location.z += 0.1;
}
void Vichle_control(Vichle *V) {

	for (int i = 0; i < Num_2_Of_Obstacle; i++) {
		if (ball.location.z < car[i].location.z + 5)
			Set_Vichle(&car[i], 12, -6.3, -150 + ball.location.z, 1);
	}
	Set_Rotation(&car[2].rotation, 0, 180, 0);
	if (ball.location.z > car[2].location.z + 80)
		Set_Vichle(&car[2], 18, -6.3, 50 + ball.location.z, 1);
	car[2].location.z -= 0.1;
	for (int i = 0; i < Num_2_Of_Obstacle; i++)
		car[i].location.z += 0.1;

	if (ball.location.z < bus[0].location.z + 5)
		Set_Vichle(&bus[0], 12, -5.1, -150 + ball.location.z, 2);
	Set_Rotation(&bus[1].rotation, 0, 180, 0);
	if (ball.location.z > bus[1].location.z + 80)
		Set_Vichle(&bus[1], 18, -5.1, 50 + ball.location.z, 2);
	bus[1].location.z -= 0.1;
	bus[0].location.z += 0.1;
}

void idle()
{
	//if (ball.location.x > 3.3 || ball.location.x < -3.3)
	//	ball.Status = 1;
	if (registerflag > 0)registerflag--;
	if (Level == 1) {
		if (ball.location.z < -425)
			ball.Status = 6;
		for (int i = 0; i < 5; i++) {
			if (HammerHit(ball, hammer[i])) {
				ball.Status = 4;
				Set_SmallBalls(&smallBalls, ball.location.x, 0, ball.location.z, 1);
			}
		}
		for (int i = 0; i < Num_3_Of_Obstacle; i++)
			if (BigBallHit(ball, BigBall[i])) {
				ball.Status = 2;
				Set_SmallBalls(&smallBalls, ball.location.x, 0, ball.location.z + 0.7, 1);
			}
		for (int i = 0; i < Num_10_Of_Obstacle + 1; i++)
			if (FlyHit(ball, Fly1[i])) {
				ball.Status = 3;
				Set_Shet7Circle(&ballTrap, ball.location.x, 0.2, ball.location.z, 0.9, 1, 0, 0);
			}
		if (UpDownHit(ball, UpDwon)) {
			ball.Status = 2;
			Set_SmallBalls(&smallBalls, ball.location.x, 0, ball.location.z + 0.7, 1);
		}
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			if (OpenCloseHit(ball, OpenCylinders[i])) {
				ball.Status = 2;
				Set_SmallBalls(&smallBalls, ball.location.x, 0, ball.location.z + 0.7, 1);
			}

		for (int i = 0; i < 8; i++) {
			if (PinsOnFloorHit(ball, PinsOnFloor1[i])) {
				ball.Status = 5;
				Set_Shet7Circle(&ballTrap, ball.location.x, 0.3, ball.location.z, ballTrap.Shet7Size, 1, 0, 0);
				Set_Ball(&ball, ball.location.x, 0.3, ball.location.z, ball.ballsSize, 1, 0, 0);
			}
		}
		for (int i = 0; i < Num_3_Of_Obstacle; i++) {
			if (BlockHit(ball, block[i])) {
				ball.Status = 5;
				Set_Shet7Circle(&ballTrap, ball.location.x, 0.3, ball.location.z, ballTrap.Shet7Size, 1, 0, 0);
				Set_Ball(&ball, ball.location.x, 0.3, ball.location.z, ball.ballsSize, 1, 0, 0);
			}
		}

		for (int i = 0; i < 20; i++) {
			if (CoinsHit(ball, coins1[i])) {
				coins1[i].Status = 1;
				ball.coins += 10;
			}
		}
		for (int i = 0; i < Num_2_Of_Obstacle; i++) {
			if (CoinsHit(ball, Life1[i])) {
				Life1[i].Status = 1;
				ball.lives++;
			}
		}
		for (int i = 0; i < Num_10_Of_Obstacle; i++) {
			if (HitBoxs(ball, Boxs[i])) {
				ball.speed = 0.05;
				ball.location.z += ball.speed;
			}
			if (TrapHit(ball, Traps[i]))
				ball.Status = 1;
		}
		for (int i = 0; i < Num_6_Of_Obstacle - 1; i++) {
			if (CoinsHit(ball, Boom1[i])) {
				Boom1[i].Status = 1;
				ball.Status = 4;
				Set_SmallBalls(&smallBalls, ball.location.x, 0, ball.location.z, 1);
			}
		}
		SmallBalls_control(&smallBalls, &ball);
		BallTrap_control(&ballTrap, &ball);
	}
	if (Level == 2) {
		if (ball.location.z < -800)
			ball.Status = 6;
		for (int i = 0; i < Num_10_Of_Obstacle; i++) {
			if (TrapHit(ball, Traps[i]))
				ball.Status = 1;
		}
		for (int i = 0; i < Num_2_Of_Obstacle; i++) {
			if (PasHit(ball, Pas1[i])) {
				ball.Status = 5;
				Set_Shet7Circle(&ballTrap, ball.location.x, 0.3, ball.location.z, ballTrap.Shet7Size, 0, 1, 1);
				Set_Ball(&ball, ball.location.x, 0.3, ball.location.z, ball.ballsSize, 0, 1, 1);
			}
		}
		for (int i = 0; i < Num_2_Of_Obstacle; i++) {
			if (CylinderFallHit(ball, cylinderFall[i]) || CylinderPinsHit(ball, cylinderRor[i])
				|| BallLeftRightHit(ball, Ball_left_right[i]) || BlockUpDownHit(ball, Block_Up_Down[i])) {
				ball.Status = 2;
				Set_SmallBalls(&smallBalls, ball.location.x, 0, ball.location.z + 0.7, 2);
			}
		}
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			if (HitTowers(ball, Towers[i]))
				ball.Status = 1;

		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			if (FourBallHit(ball, four_Balls[i]) || LeftRightHit(ball, left_right[i]) || BridgeHit(ball, bridge[i])) {
				ball.Status = 3;
				Set_Shet7Circle(&ballTrap, ball.location.x, 0.2, ball.location.z, 0.5, 0, 1, 1);
			}
		for (int i = 0; i < Num_3_Of_Obstacle; i++) {
			if (CoinsHit(ball, Life2[i])) {
				Life2[i].Status = 1;
				ball.lives++;
			}
		}
		for (int i = 0; i < Num_3_Of_Obstacle * 10; i++) {
			if (CoinsHit(ball, coins2[i])) {
				ball.coins += 10;
				coins2[i].Status = 1;
			}
		}
		for (int i = 0; i < Num_6_Of_Obstacle; i++) {
			if (LaserHit(ball, laser1[i]))
			{
				ball.Status = 5;
				Set_Shet7Circle(&ballTrap, ball.location.x, 0.3, ball.location.z, ballTrap.Shet7Size, 0, 1, 1);
				Set_Ball(&ball, ball.location.x, 0.3, ball.location.z, ball.ballsSize, 0, 1, 1);
			}
		}
		for (int i = 0; i < Num_6_Of_Obstacle; i++) {
			if (CoinsHit(ball, Boom2[i])) {
				Boom2[i].Status = 1;
				ball.Status = 4;
				Set_SmallBalls(&smallBalls, ball.location.x, 0, ball.location.z, 2);
			}
		}
		SmallBalls_control(&smallBalls, &ball);
		BallTrap_control(&ballTrap, &ball);
	}
	if (Level == 3) {
		if (ball.location.z < -1225)
			ball.Status = 6;
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			if (ShootHit(ball, shoot1[i]) || ShootHit(ball, shoot2[i]) || ShootHit(ball, shoot3[i]) || ShootHit(ball, shoot4[i])
				|| PinsUpDownHit(ball, pinUpDown[i]) || Cylinder3Hit(ball, threeCyl[i]) || CylinderFallHit(ball, cylinderFall[i]))
			{
				ball.Status = 2;
				Set_SmallBalls(&smallBalls, ball.location.x, 0, ball.location.z + 0.7, 3);
				ball.speed = 0;
			}
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			if (FourBallHit(ball, four_Balls[i]) || PinRainHit(ball, pinsRain[i])) {
				ball.Status = 3;
				Set_Shet7Circle(&ballTrap, ball.location.x, 0.2, ball.location.z, 0.5, 1, 0, 4);
				ball.speed = 0;
			}
		for (int i = 0; i < Num_3_Of_Obstacle; i++) {
			if (CoinsHit(ball, Life2[i])) {
				Life2[i].Status = 1;
				ball.lives++;
			}
		}
		for (int i = 0; i < Num_3_Of_Obstacle; i++)
			if (WallOfPinsHit(ball, PinsWall[i])) {
				ball.Status = 5;
				Set_Shet7Circle(&ballTrap, ball.location.x, 0.3, ball.location.z, ballTrap.Shet7Size, 1, 0, 4);
				Set_Ball(&ball, ball.location.x, 0.3, ball.location.z, ball.ballsSize, 1, 0, 4);
				ball.speed = 0;
			}
		for (int i = 0; i < 30; i++) {
			if (CoinsHit(ball, coins2[i])) {
				ball.coins += 10;
				coins2[i].Status = 1;
			}
		}
		for (int i = 0; i < Num_6_Of_Obstacle; i++) {
			if (LaserHit(ball, laser2[i]))
			{
				ball.Status = 5;
				Set_Shet7Circle(&ballTrap, ball.location.x, 0.3, ball.location.z, ballTrap.Shet7Size, 1, 0, 4);
				Set_Ball(&ball, ball.location.x, 0.3, ball.location.z, ball.ballsSize, 1, 0, 4);
				ball.speed = 0;
			}
		}
		for (int i = 0; i < Num_3_Of_Obstacle; i++) {
			if (CylinderPins2Hit(ball, cylinderRor1[i]) || CylinderPins2Hit(ball, cylinderRor2[i]) || CylinderPins2Hit(ball, cylinderRor[i])) {
				ball.Status = 2;
				Set_SmallBalls(&smallBalls, ball.location.x, 0, ball.location.z + 0.7, 3);
				Floor.rotation.z = 0;
				ball.speed = 0;
			}
		}
		for (int i = 0; i < Num_2_Of_Obstacle; i++)
			if (JumpOnCircleHit(ball, JumpToCylinder[i])) {
				ball.Status = 1;
				ball.speed = 0;
			}
		for (int i = 0; i < Num_10_Of_Obstacle; i++) {
			if (TrapHit(ball, Traps[i])) {
				ball.Status = 1;
			}
		}
		for (int i = 0; i < Num_6_Of_Obstacle; i++) {
			if (CoinsHit(ball, Boom2[i])) {
				Boom2[i].Status = 1;
				ball.Status = 4;
				Set_SmallBalls(&smallBalls, ball.location.x, 0, ball.location.z, 3);
				ball.speed = 0;
			}
		}
		SmallBalls_control(&smallBalls, &ball);
		BallTrap_control(&ballTrap, &ball);
	}
	for (int i = 0; i < Num_3_Of_Obstacle; i++) {
		Vichle_control(&car[i]);
		Boomb_Control(&Life2[i]);
		BigBall_control(&BigBall[i]);
		Balls4_Control(&four_Balls[i], &ball);
		BallLeftRight_Control(&Ball_left_right[i]);
		CylinderPins2_Control(&cylinderRor1[i]);
		CylinderPins2_Control(&cylinderRor2[i]);
		Pas_Control(&Pas1[i], &ball);
		WallOfPins_Control(&PinsWall[i], &ball);
		Bridge_Control(&bridge[i], &ball);
		CylinderPins_Control(&cylinderRor[i]);

	}
	for (int i = 0; i < 40; i++)
		Boomb_Control(&coins2[i]);
	for (int i = 0; i < Num_6_Of_Obstacle; i++) {
		Bird_Control(&bird1[i]);
		Boomb_Control(&Boom1[i]);
	}
	for (int i = 0; i < Num_6_Of_Obstacle - 1; i++)
		Hammer_Control(&hammer[i]);
	for (int i = 0; i<Num_6_Of_Obstacle; i++)
		Laser_Control(&laser1[i], &ball);
	for (int i = 0; i<Num_6_Of_Obstacle; i++)
		Laser_Control(&laser2[i], &ball);
	for (int i = 0; i < Num_2_Of_Obstacle; i++) {
		CylinderFall_Control(&cylinderFall[i], &ball);
		Shoot_Control(&shoot1[i], &ball);
		Shoot_Control(&shoot2[i], &ball);
		Shoot_Control(&shoot3[i], &ball);
		Shoot_Control(&shoot4[i], &ball);
		Cylinder3_Control(&threeCyl[i]);
		PinRain_Control(&pinsRain[i], &ball);
		PinsUpDown_Control(&pinUpDown[i]);
		BlockUpDown_Control(&Block_Up_Down[i]);
		OpenClose_Control(&OpenCylinders[i]);
		Boomb_Control(&Life1[i]);
		JumpOnCircle_Control(&JumpToCylinder[i]);
	}
	if (ball.ready == 1) {
		WarPlane_Control(&plane2, 2, &ball);
		WarPlane_Control(&warPlane, 1, &ball);
		UpDwon_Control(&UpDwon);
		Makok_Control(&M1, &ball);
		bloton_Control(&bloton, &ball);
		moon_Control(&moon, &ball);
		otared_Control(&otared, &ball);
		Volcano_Control(&vlocano, &ball);
		Plane_Control(&plane, &ball);
		Roket_Control(&R1, &ball);
		sun.location.z += -ball.speed;
		sun2.location.z += -ball.speed;
		M1.location.z += -ball.speed;
		CircleRocket_Control(&CircleRocket, &ball);
	}
	Boomb_Control(&Coin);
	Boomb_Control(&Life);
	Boomb_Control(&Boom);
	for (int i = 0; i < Num_6_Of_Obstacle; i++)
		Boomb_Control(&Boom2[i]);
	for (int i = 0; i < Num_10_Of_Obstacle + 1; i++)
		Fly_Control(&Fly1[i], &ball);

	for (int i = 0; i < 20; i++)
		Boomb_Control(&coins1[i]);
	if (fa == 1 && Floor.rotation.z < 25)Floor.rotation.z += 0.2;
	if (fd == 1 && Floor.rotation.z > -25)Floor.rotation.z -= 0.2;
	Ball_Control(&ball, &Floor);
	Cloude_Control();
	draw();
}

// Set OpenGL parameters
void init()
{
	Set_Button(&start, -1, 0, 0.5, 1, 1, 1, "Start");
	Set_Button(&Easy, 1, 1, 0.5, 1, 1, 1, "Easy");
	Set_Button(&Medium, 1, 0, 0.5, 1, 1, 1, "Medium");
	Set_Button(&Hard, 1, -1, 0.5, 1, 1, 1, "Hard");
	Set_Button(&Login_BackMain, 2, -2, 0.5, 1, 1, 1, "Log-Out");

	Set_Button(&NewName, 1, 2, 0.5, 1, 1, 1, "");
	Set_Button(&NamePass, 1, 1, 0.5, 1, 1, 1, "");
	Set_Button(&Login_Pagebtn, 1, 0, 0.5, 1, 1, 1, "Login");
	Set_Button(&Reigster_Pagebtn, -1, 0, 0.5, 1, 1, 1, "Register");
	Set_Button(&Information_Pagebtn, 0, -1, 0.5, 1, 1, 1, "Information");
	Set_Button(&Exit_Btn, 0, -2, 0.5, 1, 1, 1, "Exit Game");

	Set_Button(&Login_Name, 1, 2, 0.5, 1, 1, 1, "");
	Set_Button(&Login_Pass, 1, 1, 0.5, 1, 1, 1, "");
	Set_Button(&Reigster_btn, 0, -2, 0.5, 1, 1, 1, "Register");
	Set_Button(&Reigster_BackMain, 2, -2, 0.5, 1, 1, 1, "Back");

	Set_Button(&Information_BackMain, 2, -2, 0.5, 1, 1, 1, "Back");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);

	// Lighting parameters

	GLfloat mat_ambdif[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_specular[] = { 0.0, 1.0, 0.0, 0.0 };
	GLfloat mat_shininess[] = { 80.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	glClearColor(0.0f, 0.0f, 0.20f, 0.0f);


	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_ambdif);	// set both amb and diff components
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);		// set specular
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);		// set shininess
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);		// set light "position", in this case direction
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);		// active material changes by glColor3f(..)

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char *argv[])

{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);	// RGB display, double-buffered, with Z-Buffer
	glutInitWindowSize(WIDTH, HEIGHT);					// 500 x 500 pixels
	glutCreateWindow("3D");
	glutReshapeFunc(reshape);
	glutDisplayFunc(draw);						// Set the display function
	glutKeyboardFunc(keyboard);					// Set the keyboard function
	glutIdleFunc(idle);
	glutMouseFunc(ClickMouse);
	glutFullScreen();
	init();
	glutMainLoop();							// Start the main event loop
}


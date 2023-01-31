//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include <fstream>
#include<string>
#include <sstream>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

void obstScoreL();
void obstScoreR();
void obstScoreU();
void obstScoreD();
void psgScoreL();
void psgScoreR();
void psgScoreU();
void psgScoreD();
void carsScoreL();
void carsScoreR();
void carsScoreU();
void carsScoreD();
void mainMenu();
void carSel();
void learderboard();
void Name();
string nameInput();
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


long long int xI = 200, yI = 780,cx[10],cy[10],px[3],py[3],cpx,cpy,bx[2500000],by[2500000],bh=0,bv=0,pn,space=1,speed=2, score=0,add=0,nocars=0,rang=25;
string pname[100000],pscore[100000];
int t1=0,t2=0,ox[10]={400,600,280,680,680,560,280,880,840,480}, oy[10]={280,460,540,280,740,60,240,540,380,580},cartype=1,carcol=15,v=10;
fstream file,file2; 


void drawCar() {
	
	DrawRectangle(xI, yI+20, 40,20, colors[carcol]);
	DrawRoundRect(xI, yI, 20, 20 ,colors[BLACK], 10.0);
	DrawRoundRect(xI+20, yI, 20, 20 ,colors[BLACK], 10.0);

	// DrawSquare(xI, yI, 40, colors[DARK_GOLDEN_ROD]);
	
	glutPostRedisplay();
}


bool flag =true, flag1 =true, flag2 =true, flag3 =true, flag4 =true, flag5 =true, flag6=true, flag7=true,menu=true,lb=false,carsel=false,name=false;
string Namein;
void moveCar() {
	

	// Horizontal;
	if (cx[0] > 200 && flag) {
		cx[0] -= speed;
		// cout << "going left";
		if(cx[0] < 600)
			
			flag = false;
						//AUto Car Moment
	}
	else if (cx[0] < 1010 && !flag) {
		// cout << "go right";
		cx[0] += speed;
		if (cx[0] > 960)
			flag = true;
	}


	if (cx[1] > 200 && flag1) {
		cx[1] -= speed;
		// cout << "going left";
		if(cx[1] < 360)
			
			flag1 = false;
						//AUto Car Moment
	}
	else if (cx[1] < 1010 && !flag1) {
		// cout << "go right";
		cx[1] += speed;
		if (cx[1] > 960)
			flag1 = true;
	}


	if (cx[6] > 200 && flag2) {
		cx[6] -= speed;
		// cout << "going left";
		if(cx[6] < 360)
			
			flag2 = false;
						//AUto Car Moment
	}
	else if (cx[6] < 1010 && !flag2) {
		// cout << "go right";
		cx[6] += speed;
		if (cx[6] > 480)
			flag2 = true;
	}

	if (cx[3] > 200 && flag3) {
		cx[3] -= speed;
		// cout << "going left";
		if(cx[3] < 640)
			
			flag3 = false;
						//AUto Car Moment
	}
	else if (cx[3] < 1010 && !flag3) {
		// cout << "go right";
		cx[3] += speed;
		if (cx[3] > 960)
			flag3 = true;
	}

	
	
	if (cx[4] > 200 && flag4) {
		cx[4] -= speed;
		// cout << "going left";
		if(cx[4] < 560)
			
			flag4 = false;
						//AUto Car Moment
	}
	else if (cx[4] < 1010 && !flag4) {
		// cout << "go right";
		cx[4] += speed;
		if (cx[4] > 960)
			flag4 = true;
	}

	if (cx[7] > 200 && flag7) {
		cx[7] -= speed;
		// cout << "going left";
		if(cx[7] < 560)
			
			flag7 = false;
						//AUto Car Moment
	}
	else if (cx[7] < 1010 && !flag7) {
		// cout << "go right";
		cx[7] += speed;
		if (cx[7] > 960)
			flag7 = true;
	}

	// VERTICAL
	if (cy[5] >= 20 && flag5) {
		cy[5] -= speed;
		// cout << "going left";
		if(cy[5] < 320)
			
			flag5 = false;
						//AUto Car Moment
	}
	else if (cy[5] < 760 && !flag5) {
		// cout << "go right";
		cy[5] += speed;
		if (cy[5] > 660)
			flag5 = true;	
	
	}

	if (cy[2] >= 20 && flag6) {
		cy[2] -= speed;
		// cout << "going left";
		if(cy[2] < 20)
			
			flag6 = false;
						//AUto Car Moment
	}
	else if (cy[2] < 780 && !flag6) {
		// cout << "go right";
		cy[2] += speed;
		if (cy[2] > 760)
			flag6 = true;	
	
	}



}

/*
 * Main Canvas drawing function.
 * */
void mainMenu(){

		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/);
		glClear (GL_COLOR_BUFFER_BIT);

		DrawString( 420, 750, "______________", colors[WHITE]);
		DrawString( 440, 700, "RUSH HOUR", colors[WHITE]);
		DrawString( 420, 675, "______________", colors[WHITE]);

		DrawString( 400, 250, "LEADERBOARDS  (L)", colors[WHITE]);

		DrawString( 290, 400, "PRESS 'ENTER' TO START THE GAME", colors[WHITE]);

		t2=0;

		glutPostRedisplay();


	}
void carSel(){

		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/);
		glClear (GL_COLOR_BUFFER_BIT);

		DrawString( 400, 750, "________________", colors[WHITE]);
		DrawString( 410, 700, "CAR SELECTION", colors[WHITE]);
		DrawString( 400, 675, "________________", colors[WHITE]);

		DrawString( 300, 490, "Yellow CAR 	(Y)", colors[WHITE]);
			DrawRectangle(600, 480+20, 40,20, colors[15]);
			DrawRoundRect(600-2, 480, 20, 20 ,colors[WHITE], 10.0);
			DrawRoundRect(600+22, 480, 20, 20 ,colors[WHITE], 10.0);

		DrawString( 300, 410, "Red CAR			(R)", colors[WHITE]);
			DrawRectangle(600, 400+20, 40,20, colors[5]);
			DrawRoundRect(600-2, 400, 20, 20 ,colors[WHITE], 10.0);
			DrawRoundRect(600+22, 400, 20, 20 ,colors[WHITE], 10.0);

		DrawString( 300, 310, "Auto Selection	(A)", colors[WHITE]);
			DrawRectangle(600, 300+20, 20,20, colors[5]);
			DrawRectangle(600+19, 300+20, 20,20, colors[15]);
			DrawRoundRect(600-2, 300, 20, 20 ,colors[WHITE], 10.0);
			DrawRoundRect(600+22, 300, 20, 20 ,colors[WHITE], 10.0);	

		//DrawString( 290, 500, "PRESS 'ENTER' TO START THE GAME", colors[WHITE]);

		t2=0;

		glutPostRedisplay();


	}
void Name(){

		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/);
		glClear (GL_COLOR_BUFFER_BIT);

		DrawString( 400, 750, "________________", colors[WHITE]);
		DrawString( 460, 700, "NAME", colors[WHITE]);
		DrawString( 400, 675, "________________", colors[WHITE]);

		DrawString( 150, 500, "PRESS 'Enter' AND TYPE YOUR 'NAME' TO START THE GAME   ", colors[WHITE]);


		t2=0;

		glutPostRedisplay();


	}
void leaderBoard(){
	
	int i,j,n,x=260,y=580;
	string dec,swap,no,sc;

	file.open("data.csv",ios::in);

		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/);
		glClear (GL_COLOR_BUFFER_BIT);

		
		
		
		for(int i=0,n=0;1;i++,n++){

			getline(file,no,',');
			getline(file,sc,'\n');
			
			pname[i]=no;
			pscore[i]=sc;

			

			if(file.eof())
				break;
		
		}
	file.close();

	for(i=0;i<n;i++){

    for(j=i+1;j<n;j++){

      if(pscore[i]<pscore[j]){

        dec=pscore[i];
        swap=pname[i];
        pscore[i]=pscore[j];
        pname[i]=pname[j];
        pscore[j]=dec;
        pname[j]=swap;


      }
    }
  }


		DrawString( 400, 750, "________________", colors[WHITE]);
		DrawString( 410, 700, "LEADERBOARDS", colors[WHITE]);
		DrawString( 400, 675, "________________", colors[WHITE]);

		DrawString( 0, 630, "____________________________________________________________________________________________", colors[WHITE]);

	for(i=0;i<10;y-=50,i++){
		string num=Num2Str(i+1);
		DrawString( x-100, y, num, colors[WHITE]);
		DrawString( x, y, pname[i], colors[WHITE]);
		DrawString( x+500, y, pscore[i], colors[WHITE]);
		DrawString( x-230, y-10, "__________________________________________________________________________", colors[WHITE]);
	}
		DrawString( 0, 80, "____________________________________________________________________________________________", colors[WHITE]);
		DrawString( 270, 40, "PRESS 'M' TO GO BACK TO 'MAIN MENU'", colors[WHITE]);
		glutPostRedisplay();

}

string nameInput(){
		string n;
		cin>>n;
		return n;
	}



void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	

	
	
	//Display Score
	DrawString( 10, 815, "Score=", colors[BLACK]);
	string scoredisplay = Num2Str(score);
	DrawString( 85, 813, scoredisplay, colors[BLACK]);
	
	
	// CANVAS DRAW CODE
	
	for(int xl=200,i=0;i<=20;i++,xl+=40){
		DrawLine( xl , 19 ,  xl , 820 , 1 , colors[BLACK] );	
	}	
	DrawRectangle( 200,  819, 800,  2, colors[BLACK] );
	DrawRectangle( 200,  19, 800,  2, colors[BLACK] );
	
	
	// BUILDINGS AKA BLACK BOXES
	
	DrawRectangle( 600,  700, 400,  40, colors[BLACK] );
	DrawRectangle( 280,  700, 160,  40, colors[BLACK] );
	
	
	DrawRectangle( 320,  540, 80,  40, colors[BLACK] );
	DrawRectangle( 440,  540, 120,  40, colors[BLACK] );
		DrawRectangle( 520,  540, 40,  160, colors[BLACK] );
	DrawRectangle( 720,  540, 160,  40, colors[BLACK] );
	DrawRectangle( 600,  500, 40,  40, colors[BLACK] );
	
	DrawRectangle( 640,  420, 120,  40, colors[BLACK] );
	
	DrawRectangle( 760,  340, 240,  40, colors[BLACK] );
	
	DrawRectangle( 400,  240, 80,  40, colors[BLACK] );
	DrawRectangle( 640,  240, 120,  40, colors[BLACK] );
		DrawRectangle( 640,  240, 40,  120, colors[BLACK] );
		DrawRectangle( 440,  240, 40,  240, colors[BLACK] );
		DrawRectangle( 280,  80, 80,  160, colors[BLACK] );	
		
	DrawRectangle( 880,  80, 120,  40, colors[BLACK] );
	
	DrawRectangle( 520,  100, 160,  40, colors[BLACK] );
		DrawRectangle( 520,  20, 40,  120, colors[BLACK] );
	
	
	//OBSTACLES AKA TREES AND CARDBOARD BOXES
	
	int ind=0;
	
	for(int o=0; o<=3;o++){
		DrawRoundRect( ox[ind]+5, oy[ind], 30, 30 ,colors[SADDLE_BROWN-1], 5.0);	
		ind++;
	}
	for(int o=4;o<=9;o++){
		DrawRectangle(ox[ind]+15, oy[ind]-1, 10, 20 ,colors[BROWN]);
		DrawRoundRect( ox[ind]+5, oy[ind]+3, 30, 30 ,colors[DARK_GREEN], 15.0);
			
		ind++;
	}

	// PASSENGERS
		
		DrawRoundRect( px[0], py[0], 10, 30 ,colors[RED], 5.0);
		DrawRoundRect( px[1], py[1], 10, 30 ,colors[RED], 5.0);
		DrawRoundRect( px[2], py[2], 10, 30 ,colors[RED], 5.0);
	
	// CHECKPOINTS	
		if(space==0)
			DrawRoundRect( cpx, cpy, 40, 40 ,colors[DARK_GREEN], 20.0);

	// OTHER CARS
	int k=0,cn=0;
	
	for(cn=0,k=0;k<=nocars;k++,cn++){
		
		DrawRectangle(cx[cn], cy[cn]+20, 40,20, colors[rang]);
		DrawRoundRect(cx[cn], cy[cn], 20, 20 ,colors[BLACK], 10.0);
		DrawRoundRect(cx[cn]+20, cy[cn], 20, 20 ,colors[BLACK], 10.0);
	
	}
	drawCar();

	if(menu){

		mainMenu();
		

	}
	if(lb){
		leaderBoard();
	}
	if(carsel){

		carSel();
		

	}
	if(name){
		Name();
		
	}
	
	
	
	glutSwapBuffers(); // do not modify this line..
	
		

}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
		
	int u=1,d=1,l=1,r=1;
	
	if(yI==660 && xI>240 && xI<440 || yI==660 && xI>560 && xI<970 ||
	yI==500 && xI>280 && xI<400 || yI==500 && xI>400 && xI<560 || yI==500 && xI>680 && xI<880 ||
	yI==460 && xI>560 && xI<640 ||
	yI==380 && xI>600 && xI<760 ||
	yI==300 && xI>720 && xI<970 ||
	yI==200 && xI>360 && xI<480 || yI==200 && xI>600 && xI<760 ||
	yI==60 && xI>550 && xI<680 ||
	yI==40 && xI>840 && xI<970 || yI==40 && xI>240 && xI<360 
	){
	u=0;
	}
	if( yI==740 && xI>240 && xI<440 || yI==740 && xI>560 && xI<970 ||
	yI==700 && xI>480 && xI<560 ||
	yI==580 && xI>280 && xI<400 || yI==580 && xI>400 && xI<490 || yI==580 && xI>680 && xI<880 ||
	yI==540 && xI>560 && xI<640 ||
	yI==480 && xI>400 && xI<480 ||
	yI==460 && xI>600 && xI<760 ||
	yI==380 && xI>720 && xI<970 ||
	yI==360 && xI>600 && xI<680 ||
	yI==280 && xI>360 && xI<410 ||yI==280 && xI>670 && xI<760 ||
	yI==240 && xI>240 && xI<360 ||
	yI==140 && xI>480 && xI<680 ||
	yI==120 && xI>840 && xI<970 
	
	 ){
	d=0;
	}
	if(xI==440 && yI>660 && yI<740 ||
	xI==560 && yI>500 && yI<700 ||
	xI==400 && yI>500 && yI<580 || xI==880 && yI>500 && yI<580 ||
	xI==640 && yI>460 && yI<540 ||
	xI==480 && yI>200 && yI<480 ||
	xI==400 && yI>500 && yI<580 ||
	xI==760 && yI>380 && yI<460 ||
	xI==400 && yI>500 && yI<580 ||
	xI==680 && yI>270 && yI<360 ||
	xI==760 && yI>200 && yI<280 || 
	xI==360 && yI>40 && yI<240 ||
	xI==680 && yI>60 && yI<140 ||
	xI==560 && yI>10 && yI<70 
	){
	
	l=0;
	}
	if(xI==240 && yI>660 && yI<740 || xI==560 && yI>660 && yI<740 ||
	 xI==480 && yI>570 && yI<700 || 
	 xI==280 && yI>500 && yI<580 || xI==400 && yI>500 && yI<580 || xI==680 && yI>500 && yI<580 ||
	 xI==560 && yI>460 && yI<540 || 
	 xI==600 && yI>380 && yI<460 || 
	 xI==400 && yI>270 && yI<480 ||
	 xI==720 && yI>300 && yI<380 || 
	 xI==600 && yI>200 && yI<360 ||
	 xI==360 && yI>200 && yI<280 ||
	 xI==240 && yI>40 && yI<240 ||
	 xI==480 && yI>10 && yI<140 ||
	 xI==840 && yI>40 && yI<120 
	  ){
	 
	r=0;
	}



	if( 1 ){
		if ( xI>200 &&	l==1 &&
		key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left 			arrow key*/) 	{
		// what to do when left key is pressed...
			xI -= v;
			//OBSTACLES SCORE
			obstScoreL();
			//PASSENGER SCORE
			psgScoreL();
			// MOVING CARS SCORE
			carsScoreL();
		}				

		 else if (xI<960 && r==1 &&
		key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for 		right arrow key*/) {
			xI += v;
			//OBSTACLES SCORE
			obstScoreR();
			//PASSENGER SCORE
			psgScoreR();
			// MOVING CARS SCORE
			carsScoreR();
		}	
	}	
	
	if(1 ){			 
		if ( yI<780 && u==1 &&
		key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow 			key*/) {
			yI += v;
			//OBSTACLES SCORE
			obstScoreU();		
			
			//PASSENGER SCORE
			psgScoreU();
			// MOVING CARS SCORE
			carsScoreU();
			

		}

		else if (  yI>20 && d==1 &&
		key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down 			arrow key*/) {
			yI -= v;
			//OBSTACLES SCORE
			obstScoreD();
			//PASSENGER SCORE
			psgScoreD();						
			// MOVING CARS SCORE
			carsScoreD();

		}
	}
	cout<<xI<<"____"<<yI<<endl;

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
int car=0;
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == ' ' || key == ' ') //Key for placing the bomb
	{	
				
		int xmin=200,xmax=960 ,ymin=20, ymax=770,randx,randy,flagp=1, flagcp=1,i=0,rcpx,rcpy;

		if(xI>=(px[0]-40) && xI<=(px[0]+30) && yI>=(py[0]-30) && yI<=(py[0]+30)){

			pn=0;	//Passenger 1
			
		}
		else if(xI>=(px[1]-40) && xI<=(px[1]+30) && yI>=(py[1]-30) && yI<=(py[1]+30)){

			pn=1;	//Passenger 2
			
		}
		else if(xI>=(px[2]-40) && xI<=(px[2]+30) && yI>=(py[2]-30) && yI<=(py[2]+30)){

			pn=2;	//Passenger 3
			
		}
		
			
		if(xI>=(px[pn]-40) && xI<=(px[pn]+30) && yI>=(py[pn]-30) && yI<=(py[pn]+30)){	
			if(space==1){	
				fail:			
					randx=GetRandInRange(xmin, xmax);
					randy=GetRandInRange(ymin, ymax);
				for(i=0;i<bh;i++){

					if(bx[i] == randx && by[i] == randy || cpx==randx && cpy == randy   ){
						flagp =0; 
						break;
					}
					else{
						flagp =1;	
					}	
				}
				if(flagp ==1){

					px[pn]=randx;
					cout<<"\npXXXXXXXXX ["<<pn<<"]"<<px[pn];
					py[pn]=randy;
					cout<<"\npYYYYYYYYY ["<<pn<<"]"<<py[pn];
					;
				}
				else{
					cout<<"\nBUILDING CORRECTION";
					goto fail;
				}
				space=0;	
			}	
		}
		else if(xI>=(cpx-40) && xI<=(cpx+30) && yI>=(cpy-30) && yI<=(cpy+30) ){

			if(space==0){
			cpfail:			
					rcpx=GetRandInRange(xmin, xmax);
					rcpy=GetRandInRange(ymin, ymax);
				for(i=0;i<bh;i++){

					if((bx[i]-20)== rcpx && (by[i]-20) == rcpy || (bx[i]) == rcpx && (by[i]-20) == rcpy || (bx[i]+20) == rcpx && (by[i]) == rcpy || (bx[i]) == rcpx && (by[i]+20) == rcpy || px[0] == rcpx && py[0] == rcpy || px[1] == rcpx && py[1] == rcpy || px[2] == rcpx && py[2] == rcpy ){
						flagcp =0; 
						break;
					}
					else
						flagcp =1;	
				}
				if(flagcp == 1){

					cpx=rcpx;
					//cout<<"\npXXXXXXXXX"<<cpx;
					cpy=rcpy;
					//cout<<"\npYYYYYYYYY "<<cpy;
					
				}
				else{
					cout<<"\nBUILDING CORRECTION CHECKPOINT";
					cout<<"ELSE PART EXECUTES"<<space<<endl;
					goto  cpfail;
				}

			space=1;
			score+=10;
			add++;

				if(add%2==0){
					if(nocars<7)
						nocars++;
					speed+=1;
				if(rang<=75)	
					rang+=10;
					
				}

			
			}		

		}

			//do something if space is pressed
			//cout << "\nspace   pressed" << endl;

		}
	
	if (key == 'A' && carsel|| key == 'a' && carsel){
		

			car=GetRandInRange(0, 5);
			cout<<car;
			
		
	}

	if (key == 'R' || key == 'r' || car>=0 && car<3 && carsel) 
	{
		cartype=2;		//Red
		carcol=5;
		v=5;
		carsel=false;
		name=true;
		
	}
	if (key == 'Y'  || key == 'y' || (car>=3 && car<5 && carsel)) 
	{
		cartype=1;		//YELLOW
		carcol=15;
		v=10;
		carsel=false;
		name=true;
		
	}

	if (key == 13 || key == 13){

		menu=false;
		carsel=true;
		if(name){
		Namein=nameInput();
		name=false;
		carsel=false;
		}
		

	}
	
	if(key == 'l'  || key == 'L' ){

		lb=true;
		

	}
	if(key == 'm'  || key == 'M' ){

		menu=true;	
		lb=false;	

	}
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	int i,j,isc,n;
	string swap,no,sc,stsc,dec;
	// implement your functionality here
	t1++;
	if(t1%10==0)
	{	t2=t2+1;
		//cout<<"TIMER=="<<t2<<endl;}
	
		if(t2>=180){

		stsc=Num2Str(score)  ;
	
	file.open("data.csv",ios::in|ios::out|ios::app);	
		
		file<<Namein<<','<<stsc<<endl;
		
		

	file.close();

	file.open("data.csv",ios::in);

		for(i=0,n=0; 1 ;i++,n++){

			getline(file,no,',');
			getline(file,sc,'\n');
			
			pname[i]=no;
			pscore[i]=sc;
			

			if(file.eof())
				break;
		
		}
	file.close();	

	for(i=0;i<n;i++){

		for(j=i+1;j<n;j++){

			if(pscore[i]<pscore[j]){

				dec=pscore[i];
				swap=pname[i];
				pscore[i]=pscore[j];
				pname[i]=pname[j];
				pscore[j]=dec;
				pname[j]=swap;


			}
    	}
  	}




	file2.open("leaderboard.csv",ios::in|ios::out);

		for(i=0;i<10;i++){

			file2<<pname[i]<<','<<pscore[i]<<endl;

		}

	file2.close();

		exit(1);
		}	
	}
	moveCar();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
	
}


	//////////////////////////////////
	//		MY CUSTOM FUNCTIONS		//
	//////////////////////////////////
	
void psgScoreL(){

	for(int o=0;o<=2;o++){
				if(xI>(px[o]-5) && yI>=(py[o]-30)  && yI<=(py[o]+20) && xI<=(px[o]) && yI>=(py[o]-30)  && yI<=(py[o]+20)){
				score-=5;
				break;
				}	
			}	
}
void psgScoreR(){
	for(int o=0;o<=2;o++){
				if(xI>(px[o]-35) && yI>=(py[o]-30)  && yI<=(py[o]+20) && xI<=(px[o]-30) && yI>=(py[o]-30)  && yI<=(py[o]+20)){
				score-=5;
				break;
				}	

			}
}
void psgScoreU(){
	for(int o=0;o<=2;o++){
				if(xI>=(px[o]-30) && xI<=(px[o]+30) && yI==(py[o]-30) ){
				score-=4;
				break;
				}			
			}
			

}
void psgScoreD(){
	for(int o=0;o<=2;o++){
				if(xI>=(px[o]-30) && xI<=(px[o]+30) && yI==(py[o]+20) ){
				score-=4;
				break;
				}			
			}

}

void obstScoreL(){

for(int o=0;o<=9;o++){
				if(xI==(ox[o]+30) && yI>=(oy[o]-30)  && yI<=(oy[o]+20)){
					if(cartype==1)
						score-=4;
					else if(cartype==2)
						score-=2;	
				break;
				}
			}

}
void obstScoreR(){
	for(int o=0;o<=9;o++){
				if(xI==(ox[o]-30) && yI>=(oy[o]-30)  && yI<=(oy[o]+20)){
					if(cartype==1)
						score-=4;
					else if(cartype==2)
						score-=2;	
				break;
				}
			}
}
void obstScoreU(){
	for(int o=0;o<=9;o++){
				if(xI>=(ox[o]-30) && xI<=(ox[o]+30) && yI==(oy[o]-30) ){
					if(cartype==1)
						score-=4;
					else if(cartype==2)
						score-=2;	
				break;
				}	
	}
}
void obstScoreD(){

for(int o=0;o<=9;o++){
				if(xI>=(ox[o]-30) && xI<=(ox[o]+30) && yI==(oy[o]+20) ){
					if(cartype==1)
						score-=4;
					else if(cartype==2)
						score-=2;	
				break;
				}			
			}

}

void carsScoreL(){
			for(int o=0;o<=7;o++){
				if(xI<=(cx[o]+30) && xI>=(cx[o]+20) && yI>=(cy[o]-30)  && yI<=(cy[o]+30)){
					if(cartype==1)
						score-=2;
					else if(cartype==2)
						score-=3;	
				break;
				}
			}
			
}
void carsScoreR(){
	for(int o=0;o<=nocars;o++){
				if(xI>=(cx[o]-30) && xI<=(cx[o]-20) && yI>=(cy[o]-30)  && yI<=(cy[o]+30)){
					if(cartype==1)
						score-=2;
					else if(cartype==2)
						score-=3;	
				break;
				}
			}
}
void carsScoreU(){

	for(int o=0;o<=nocars;o++){
				if(xI>=(cx[o]-30) && xI<=(cx[o]+30) && yI>=(cy[o]-30)  && yI<=(cy[o]-20)){
					if(cartype==1)
						score-=2;
					else if(cartype==2)
						score-=3;	
				break;
				}
			}

}
void carsScoreD(){
	for(int o=0;o<=nocars;o++){
				if(xI>=(cx[o]-30) && xI<=(cx[o]+30) && yI<=(cy[o]+30)  && yI>=(cy[o]+20)){
					if(cartype==1)
						score-=2;
					else if(cartype==2)
						score-=3;	
				break;
				}
			}

}

// void mainMenu(){

// 	DrawRectangle(500,500,1500,1500,colors[BLACK]);
// 	glutPostRedisplay();
// 	system pause;

// }


/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */

int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	
	long long int bxmin=270,bxmax=440,bymin=670,bymax=740;		
	
	for(bymin=670; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for( bxmin=270;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
			// cout<<"BYMIN====="<<bymin<<endl;
		}	
	
	}

     bxmin=590 , bxmax=1000 ,bymin=670,bymax=740 ;
    
    for(bymin=670; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=590;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
			// cout<<"BYMIN====="<<bymin<<endl;
		}	
	
	}
    ///////////////////////////////////
    bxmin=510 , bxmax=560 ,bymin=510,bymax=700 ;
    
    for(bymin=510; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=510;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
			// cout<<"BYMIN====="<<bymin<<endl;
		}	
	
	}
	///////////////////////////////////
    bxmin=270 , bxmax=400 ,bymin=510,bymax=580 ;
    
    for(bymin=510; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=270 ;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
		}	
	
	}
	bxmin= 430, bxmax=560 ,bymin=510,bymax=580 ;
    
    for(bymin= 510; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin= 430;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
		}	
	
	}bxmin= 710, bxmax= 920 ,bymin=510,bymax=580 ;
    
    for(bymin= 510; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin= 710 ;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
		}	
	
	}
	///////////////////////////////////
    bxmin=590 , bxmax=640 ,bymin=430,bymax=540 ;
    
    for(bymin=430; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=590 ;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
		}	
	
	}
	///////////////////////////////////
    bxmin=430 , bxmax=480 ,bymin=310,bymax=480 ;
    
    for(bymin=310; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=430 ;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
		}	
	
	}
	///////////////////////////////////
    bxmin=630 , bxmax=760 ,bymin=390,bymax=460;
    
    for(bymin=390; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=630 ;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
		}	
	
	}
	///////////////////////////////////
    bxmin=750 , bxmax=1000  ,bymin=310,bymax=380 ;
    
    for(bymin=310; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=750 ;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;

	
		}	
	
	}
	///////////////////////////////////
    bxmin=630 , bxmax=680 ,bymin=310,bymax=360 ;
    
    for(bymin=310; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=630 ;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
		}	
	
	}
	///////////////////////////////////
    bxmin=390 , bxmax=480 ,bymin=210,bymax=310 ;
    
    for(bymin=210; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=390 ;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
		}	
	
	}
	///////////////////////////////////
    bxmin=630 , bxmax=720 ,bymin=210,bymax=310 ;
    
    for(bymin=210; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=630 ;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
		}	
	
	}
	///////////////////////////////////
    bxmin=630 , bxmax=760 ,bymin=210,bymax=280 ;
    
    for(bymin=210; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=630 ;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
		}	
	
	}
	///////////////////////////////////
    bxmin=260 , bxmax=360 ,bymin=50,bymax=270 ;
    
    for(bymin=50; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=260 ;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
		}	
	
	}
	///////////////////////////////////
    bxmin=260 , bxmax=360 ,bymin=50,bymax=240 ;
    
    for(bymin=50; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=260 ;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
		}	
	
	}
	///////////////////////////////////
    bxmin=510 , bxmax=560 ,bymin=20,bymax=140 ;
    
    for(bymin=20; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=510 ;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
		}	
	
	}
	///////////////////////////////////
    bxmin=510 , bxmax=680 ,bymin=70,bymax=140 ;
    
    for(bymin=70; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=510 ;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
		}	
	
	}
	///////////////////////////////////
    bxmin=510 , bxmax=590 ,bymin=30,bymax=140 ;
    
    for(bymin=30; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=510 ;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
		}	
	
	}
	///////////////////////////////////
    bxmin=860 , bxmax=1000  ,bymin=40,bymax=130 ;
    
    for(bymin=50; bymin!=bymax+1  ;bymin++,bv++ ){
	
		
		for(bxmin=870 ;bxmin!=bxmax+1 ; bxmin++, bh++){
			
            bx[bh]= bxmin;
            by[bh]= bymin;
		}	
	
	}

    		//BUILDING COORDINATES EXTRACTION

    // long long int i ;
    // for(i=0; i<bh; i++){

    //     cout<<bx[i]<<" ########### ";
    //     cout<<by[i]<<endl;
        
    // }
	// i=i-1;
    // cout<<"\n\n bx="<< bh << " by="<<bv<<endl;
    // cout<<"Z==========="<<i<<endl;
       

	px[0]=py[0]=500;
	px[1]=py[1]=780;
	px[2]=py[2]=300;

	cpx=cpy=200;

	//AUTO CARS
	//HORIZONTAL
	cx[0]=680;
	cy[0]=780;
	cx[1]=920;
	cy[1]=160;
	cx[6]=260;
	cy[6]=40;
	cx[3]=720;
	cy[3]=500;
	cx[4]=600;
	cy[4]=660;
	cx[7]=560;
	cy[7]=20;
	//VERTICAL
	cx[5]=400;
	cy[5]=440;
	cx[2]=240;
	cy[2]=700;


	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Mahad Saleem"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */





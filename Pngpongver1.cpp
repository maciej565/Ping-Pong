//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Pngpongver1.h"
#include <iostream>
#include <string.h>
#include <sstream>
#include <dstring.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TForm1 *Form1;

        int x=0,y=0,tempX=-5,tempY=-5,paddleSpeed=10, score1, score2;  //predkosc pilki, wyniki

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ballTimerTimer(TObject *Sender)
{

ball->Left+=x;
ball->Top +=y;
if (tenisball -> Visible == true)ball=tenisball;


// odbij od górnej sciany
if(ball-> Top-5 <= background -> Top) y= -y;

//odbij od dolnej sciany
if(ball -> Top+ball -> Height+5 >= background -> Height) y=-y;

//Skucha

if(ball -> Left <= paddle1 -> Left -15 )
{
        tempX=x, tempY=y;
        score2++;
        ballTimer -> Enabled = false;
        ball -> Visible = false;
        start -> Visible =true;
        pause -> Visible =false;
        ball -> Left = 484;
        ball -> Top = 264;
        ball -> Visible = true;

}
else if (ball -> Left >= paddle2 -> Left + paddle2 -> Width +15)
{
        tempX=x, tempY=y;
        score1++;
        ballTimer -> Enabled = false;
        ball -> Visible = false;
        start -> Visible =true;
        pause -> Visible =false;
        ball -> Left = 484;
        ball -> Top = 264;
        ball -> Visible = true;
}

score->Caption="Score: "+IntToStr(score1)+" : "+IntToStr(score2);
if (score1>=5)
{
        winner -> Visible = true;
        winner -> Caption ="The Winner is Player 1!!!";
        start -> Visible = false;
        pause -> Visible = false;
        newGame -> Visible = true;
        level -> Visible = true; 
}
else if (score2>=5)
{
        winner -> Visible = true;
        winner -> Caption ="The Winner is Player 2!!!";
        start -> Visible = false;
        pause -> Visible = false;
        newGame -> Visible = true;
        level -> Visible = true;
}

if (ball -> Top > (paddle1 -> Top - ball -> Height/2) && ball -> Top < (paddle1 -> Top + paddle1 -> Height + ball -> Height/2) && ball -> Left < paddle1 -> Left+15)

{
    if (x<0) x = -x;
}


else if (ball -> Top > (paddle2 -> Top - ball -> Height/2) && ball -> Top < (paddle2 -> Top + paddle2 -> Height + ball -> Height/2) && ball -> Left > paddle2 -> Left-15)

{
    if (x>0) x = -x;
}

}

//---------------------------------------------------------------------------

void __fastcall TForm1::upTimer(TObject *Sender)
{
        if(paddle1 -> Top > 10) paddle1 -> Top -= 10;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::downTimer(TObject *Sender)
{
        if(paddle1 -> Top + paddle1 -> Height < background -> Height-20) paddle1 -> Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::up2Timer(TObject *Sender)
{
        if(paddle2 -> Top > 10) paddle2 -> Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::down2Timer(TObject *Sender)
{
        if(paddle2 -> Top + paddle2 -> Height < background -> Height-20) paddle2 -> Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(x!=0 && start -> Visible==false)
{
        if(Key == VK_UP) up->Enabled = true;
        if(Key == VK_DOWN) down->Enabled = true;
        if(Key == 0x57) up2->Enabled = true;
        if(Key == 0x53)down2->Enabled = true;
}

if(Key == VK_SPACE && start->Visible==true)
{
        ballTimer -> Enabled = true;
        start -> Visible =false;
        pause -> Visible =true;
        x=tempX,y=tempY;
}

else if (Key == VK_SPACE && pause->Visible==true)
{
        start -> Visible =true;
        pause -> Visible =false;
        tempX=x, tempY=y;
        x=0,y=0;

}


else if (Key == VK_SPACE && newGame->Visible==true)
{
        winner -> Visible = false;
        score1=0,score2=0;
        x=tempX, y=tempY;
        ballTimer -> Enabled = true;
        start -> Visible =false;
        pause -> Visible =true;
        menuDescription -> Visible = false;
        newGame -> Visible = false;
        level -> Visible = false;
        beginner -> Visible = false;
        medium -> Visible = false;
        hard -> Visible = false;
        expert -> Visible = false;
        custom -> Visible = false;
        levelMenu -> Visible = false;

        
}

}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_UP) up->Enabled = false;
        if(Key == VK_DOWN) down->Enabled = false;
        if(Key == 0x57) up2->Enabled = false;
        if(Key == 0x53)down2->Enabled = false;

}
//--------------------------------------------------------------------------

void __fastcall TForm1::startClick(TObject *Sender)
{
        ballTimer -> Enabled = true;
        start -> Visible =false;
        pause -> Visible =true;
        x=tempX,y=tempY;   

}
//---------------------------------------------------------------------------

void __fastcall TForm1::pauseClick(TObject *Sender)
{
start -> Visible =true;
pause -> Visible =false;
tempX=x, tempY=y;
x=0,y=0;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::newGameClick(TObject *Sender)
{

winner -> Visible = false;
score1=0,score2=0;
x=tempX, y=tempY;
ballTimer -> Enabled = true;
start -> Visible =false;
pause -> Visible =true;
newGame -> Visible = false;
menuDescription -> Visible = false;
level -> Visible = false;
beginner -> Visible = false;
medium -> Visible = false;
hard -> Visible = false;
expert -> Visible = false;
custom -> Visible = false;
levelMenu -> Visible = false;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::beginnerClick(TObject *Sender)
{
tempX=-3,tempY=-3;
menuDescription -> Visible = false;
beginner -> Visible = false;
medium -> Visible = false;
hard -> Visible = false;
expert -> Visible = false;
custom -> Visible = false;
levelMenu -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::levelClick(TObject *Sender)
{
beginner -> Visible = true;
medium -> Visible = true;
hard -> Visible = true;
expert -> Visible = true;
custom -> Visible = true;
levelMenu -> Visible = true;
menuDescription -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::mediumClick(TObject *Sender)
{
tempX=-5,tempY=-5;
menuDescription -> Visible = false;
beginner -> Visible = false;
medium -> Visible = false;
hard -> Visible = false;
expert -> Visible = false;
custom -> Visible = false;
levelMenu -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::hardClick(TObject *Sender)
{
tempX=-8,tempY=-8;
up -> Interval == 8;
menuDescription -> Visible = false;
beginner -> Visible = false;
medium -> Visible = false;
hard -> Visible = false;
expert -> Visible = false;
custom -> Visible = false;
levelMenu -> Visible = false;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::expertClick(TObject *Sender)
{
tempX=-10,tempY=-10;
up -> Interval == 6;
menuDescription -> Visible = false;
beginner -> Visible = false;
medium -> Visible = false;
hard -> Visible = false;
expert -> Visible = false;
custom -> Visible = false;
levelMenu -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::customClick(TObject *Sender)
{
ball1Button -> Visible = true;
ball2Button -> Visible = true;
ball1 -> Visible = true;
ball2 -> Visible = true;
chooseBall -> Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ball1ButtonClick(TObject *Sender)
{

ball ->Visible = true;
tenisball ->Visible = false;
ball1Button -> Visible = false;
ball2Button -> Visible = false;
ball1 -> Visible = false;
ball2 -> Visible = false;
chooseBall -> Visible = false;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ball2ButtonClick(TObject *Sender)
{

ball -> Visible = false;
tenisball -> Visible = true;
ball1Button -> Visible = false;
ball2Button -> Visible = false;
ball1 -> Visible = false;
ball2 -> Visible = false;
chooseBall -> Visible = false;
}
//---------------------------------------------------------------------------






void __fastcall TForm1::FormCreate(TObject *Sender)
{
        AnsiString strHello = "Welcome to The Ping-Pong Game :)";
	AnsiString strFirstPlayer = "1st player controls: 'UP ARROW key':up. 'DOWN ARROW key':down";
	AnsiString strSecondPlayer = "2nd player controls: 'W':up. 'S':down";
        AnsiString strPause = "Press Space to start game or pause";
	AnsiString strLast = "Lets The Ping-Pong Games Begin!! !";
       	ShowMessage(strHello + sLineBreak + strFirstPlayer + sLineBreak +
	 		strSecondPlayer + sLineBreak + strPause + sLineBreak + strLast);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::TrayIcon1Create(TObject *Sender)
{
;        
}
//---------------------------------------------------------------------------


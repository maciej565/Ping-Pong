//---------------------------------------------------------------------------

#ifndef Pingpongver1H
#define Pingpongver1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
#include "trayicon.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *ball;
        TTimer *ballTimer;
        TImage *paddle1;
        TTimer *up;
        TTimer *down;
        TImage *paddle2;
        TTimer *up2;
        TTimer *down2;
        TButton *start;
        TButton *pause;
        TLabel *player1;
        TLabel *player2;
        TLabel *score;
        TLabel *winner;
        TButton *newGame;
        TButton *level;
        TShape *Shape1;
        TShape *levelMenu;
        TButton *beginner;
        TButton *medium;
        TButton *hard;
        TButton *expert;
        TLabel *menuDescription;
        TButton *custom;
        TImage *tenisball;
        TShape *chooseBall;
        TImage *ball1;
        TImage *ball2;
        TButton *ball1Button;
        TButton *ball2Button;
        TTrayIcon *TrayIcon1;
        void __fastcall ballTimerTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall upTimer(TObject *Sender);
        void __fastcall downTimer(TObject *Sender);
        void __fastcall up2Timer(TObject *Sender);
        void __fastcall down2Timer(TObject *Sender);
        void __fastcall startClick(TObject *Sender);
        void __fastcall pauseClick(TObject *Sender);
        void __fastcall newGameClick(TObject *Sender);
        void __fastcall beginnerClick(TObject *Sender);
        void __fastcall levelClick(TObject *Sender);
        void __fastcall mediumClick(TObject *Sender);
        void __fastcall hardClick(TObject *Sender);
        void __fastcall expertClick(TObject *Sender);
        void __fastcall customClick(TObject *Sender);
        void __fastcall ball1ButtonClick(TObject *Sender);
        void __fastcall ball2ButtonClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall TrayIcon1Create(TObject *Sender);
        
        
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

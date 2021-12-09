//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TImage *background;
    TImage *table;
    TImage *paddleLeft;
    TImage *paddleRight;
    TImage *ball;
    TTimer *TimerLeftUp;
    TTimer *TimerRightUp;
    TTimer *TimerBall;
    TTimer *TimerLeftDown;
    TTimer *TimerRightDown;
    TLabel *mainTable;
    TButton *nextRoundButton;
    TButton *newGameButton;
    TLabel *resultTable;
    TMediaPlayer *ballSounds;
    TMediaPlayer *paddleSounds;
    TButton *mainButton;
    TLabel *infoTable;
    void __fastcall TimerBallTimer(TObject *Sender);
    void __fastcall TimerLeftUpTimer(TObject *Sender);
    void __fastcall TimerLeftDownTimer(TObject *Sender);
    void __fastcall TimerRightUpTimer(TObject *Sender);
    void __fastcall TimerRightDownTimer(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall mainButtonClick(TObject *Sender);
    void __fastcall newGameButtonClick(TObject *Sender);
    void __fastcall nextRoundButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

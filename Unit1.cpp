//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

float axisX = 10;
float axisY = 10;
int leftPlayerPoints = 0;
int rightPlayerPoints = 0;
int bounceCount = 0;
int roundCount = 0;
AnsiString player = "";

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
    const int TOP_BORDER_USED_PICTURE = 0;
    const int BORDER_HALF_USED_PICTURE = 50;
    const int BOTTOM_BORDER_USED_PICTURE = 98;

    ball->Left += axisX;
    ball->Top += axisY;

    if ((ball->Top - 5 <= table->Top) || (ball->Top + ball->Height + 5 >= table->Height))
        {
        ballSounds->Play();
        axisY = -axisY;
        }

    if (ball->Left <= table->Left - 10)
        {
            ball->Left += ball->Width;
            ball->Top += ball->Height;

            rightPlayerPoints++;
            roundCount++;
            TimerBall->Enabled = false;
            ball->Visible = false;
            sndPlaySound("snd/applause.wav", SND_ASYNC);

            if (rightPlayerPoints >= 11 && (rightPlayerPoints - leftPlayerPoints >= 2))
                {
                    resultTable->Caption = IntToStr(leftPlayerPoints) + "  :  " + IntToStr(rightPlayerPoints);
                    infoTable->Caption = " RIGHT  PLAYER  WIN!  >>";
                    bouncesTable->Caption = " Bounces:  " + IntToStr(bounceCount);
                    roundTable->Caption = " ROUND:  " + IntToStr(roundCount);

                    newGameButton->Visible = true;
                    roundTable->Visible = true;
                    infoTable->Visible = true;
                    resultTable->Visible = true;
                    bouncesTable->Visible = true;
                }
            else
                {
                resultTable->Caption = IntToStr(leftPlayerPoints) + "  :  " + IntToStr(rightPlayerPoints);
                player = "RIGHT";
                infoTable->Caption = " Point for:  " + player + " PLAYER  >>";
                bouncesTable->Caption = " Bounces:  " + IntToStr(bounceCount);
                roundTable->Caption = " ROUND:  " + IntToStr(roundCount);

                nextRoundButton->Visible = true;
                newGameButton->Visible = true;
                roundTable->Visible = true;
                infoTable->Visible = true;
                resultTable->Visible = true;
                bouncesTable->Visible = true;
                }
        }
    else if (ball->Left >= table->Left + table->Width - ball->Width + 10)
        {
            ball->Left += ball->Width;
            ball->Top += ball->Height;

            leftPlayerPoints++;
            roundCount++;
            TimerBall->Enabled = false;
            ball->Visible = false;
            sndPlaySound("snd/applause.wav", SND_ASYNC);

            if (leftPlayerPoints >= 11 && (leftPlayerPoints - rightPlayerPoints >= 2))
                {
                    resultTable->Caption = IntToStr(leftPlayerPoints) + "  :  " + IntToStr(rightPlayerPoints);
                    infoTable->Caption = " <<  LEFT  PLAYER  WIN!";
                    bouncesTable->Caption = " Bounces:  " + IntToStr(bounceCount);
                    roundTable->Caption = " ROUND:  " + IntToStr(roundCount);

                    newGameButton->Visible = true;
                    roundTable->Visible = true;
                    infoTable->Visible = true;
                    resultTable->Visible = true;
                    bouncesTable->Visible = true;
                }
            else
                {
                    resultTable->Caption = IntToStr(leftPlayerPoints) + "  :  " + IntToStr(rightPlayerPoints);
                    player = "LEFT";
                    infoTable->Caption = "Point for:   <<  " + player + " PLAYER";
                    bouncesTable->Caption = " Bounces:  " + IntToStr(bounceCount);
                    roundTable->Caption = " ROUND:  " + IntToStr(roundCount);

                    nextRoundButton->Visible = true;
                    newGameButton->Visible = true;
                    roundTable->Visible = true;
                    infoTable->Visible = true;
                    resultTable->Visible = true;
                    bouncesTable->Visible = true;
                }
            
        }
    else if (ball->Left + ball->Width / 2 <= paddleLeft->Left + paddleLeft->Width &&
            ball->Top + ball->Height / 2 >= paddleLeft->Top + TOP_BORDER_USED_PICTURE &&
            ball->Top + ball->Height / 2 <= paddleLeft->Top + BOTTOM_BORDER_USED_PICTURE)
        {
            axisX = -axisX / 0.9;
            paddleSounds->Play();
            bounceCount++;

            if (axisX < 0)
            {
                if (ball->Left + ball->Width / 2 <= paddleLeft->Left + paddleLeft->Width &&
                    ball->Top + ball->Height / 2 >= paddleLeft->Top + TOP_BORDER_USED_PICTURE &&
                    ball->Top + ball->Height / 2 <= paddleLeft->Top + BORDER_HALF_USED_PICTURE)
                    {
                        axisX = -axisX * 0.8;
                        axisY = axisY * 0.8;
                    }
                else if (ball->Left + ball->Width / 2 <= paddleLeft->Left + paddleLeft->Width &&
                        ball->Top + ball->Height / 2 > paddleLeft->Top + BORDER_HALF_USED_PICTURE &&
                        ball->Top + ball->Height / 2 <= paddleLeft->Top + BOTTOM_BORDER_USED_PICTURE)
                    {
                        axisX = -axisX * 1.1;
                        axisY = axisY * 1.1;
                    }
            }
        }

    else if (ball->Left + ball->Width / 2 >= paddleRight->Left &&
            ball->Top + ball->Height / 2 >= paddleRight->Top + TOP_BORDER_USED_PICTURE &&
            ball->Top + ball->Height / 2 <= paddleRight->Top + BOTTOM_BORDER_USED_PICTURE)
        {
            axisX = -axisX / 0.9;
            paddleSounds->Play();
            bounceCount++;

            if (axisX > 0)
            {
                if (ball->Left + ball->Width / 2 >= paddleRight->Left &&
                    ball->Top + ball->Height / 2 >= paddleRight->Top + TOP_BORDER_USED_PICTURE &&
                    ball->Top + ball->Height / 2 <= paddleRight->Top + BORDER_HALF_USED_PICTURE)
                    {
                        axisX = -axisX * 0.8;
                        axisY = axisY * 0.8;
                    }
                else if (ball->Left + ball->Width / 2 >= paddleRight->Left &&
                    ball->Top + ball->Height / 2 > paddleRight->Top + BORDER_HALF_USED_PICTURE &&
                    ball->Top + ball->Height / 2 <= paddleRight->Top + BOTTOM_BORDER_USED_PICTURE)
                    {
                        axisX = -axisX * 1.1;
                        axisY = axisY * 1.1;
                    }
            }
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerLeftUpTimer(TObject *Sender)
{
    if (paddleLeft->Top > 5)
        paddleLeft->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerLeftDownTimer(TObject *Sender)
{
    if (paddleLeft->Top + paddleLeft->Height < table->Height + paddleRight->Height / 2)
        paddleLeft->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerRightUpTimer(TObject *Sender)
{
    if (paddleRight->Top > 5)
        paddleRight->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerRightDownTimer(TObject *Sender)
{
    if (paddleRight->Top + paddleRight->Height < table->Height + paddleRight->Height / 2)
        paddleRight->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == 0x57)
        TimerLeftUp->Enabled = true;
    if (Key == 0x53)
        TimerLeftDown->Enabled = true;
    if (Key == VK_UP)
        TimerRightUp->Enabled = true;
    if (Key == VK_DOWN)
        TimerRightDown->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == 0x57)
        TimerLeftUp->Enabled = false;
    if (Key == 0x53)
        TimerLeftDown->Enabled = false;
    if (Key == VK_UP)
        TimerRightUp->Enabled = false;
    if (Key == VK_DOWN)
        TimerRightDown->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
    ShowMessage("Welcome to TENNIS GAME 1.0!\n\n"
    "RACKET CONTROL:\n"
    "LEFT PLAYER control: press A and Z keys.\n"
    "RIGHT PLAYER control: press UP and DOWN keys.\n\n"
    "WIN:\n"
    "Player who scores 11 points and has a 2-point lead over his opponent.\n\n"
    "CURIOSITY:\n"
    "Rackets are divided into zones.\n"
    "Ball bounces at different speeds depending on the position on the racket.\n"
    "The longer you bounce, the faster the ball moves.\n"
    "The player who won the previous round serves.\n\n"
    "Have fun!");

    ballSounds->FileName = "snd/dzwiekSciana.wav";
    ballSounds->Open();
    paddleSounds->FileName = "snd/dzwiekPaletka.wav";
    paddleSounds->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    TimerBall->Enabled = false;

    if (Application->MessageBoxA("Do you want to exit program?", "Confirm",
    MB_YESNO | MB_ICONQUESTION) == IDNO)
    {
        TimerBall->Enabled = true;
        ball->Visible = true;
        Action = caNone;
    }
    else
    {
        ballSounds->Close();
        paddleSounds->Close();
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::mainButtonClick(TObject *Sender)
{
    axisX = 10;
    axisY = 10;
    leftPlayerPoints = 0;
    rightPlayerPoints = 0;
    bounceCount = 0;
    roundCount = 0;
    player = "";

    TimerBall->Enabled = true;
    ball->Visible = true;
    mainButton->Visible = false;
    nextRoundButton->Visible = false;
    newGameButton->Visible = false;
    roundTable->Visible = false;
    mainTable->Visible = false;
    infoTable->Visible = false;
    resultTable->Visible = false;
    bouncesTable->Visible = false;

    randomize();
    ball->Left = 476;
    ball->Top = random(table->Height - 156) + 100;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::newGameButtonClick(TObject *Sender)
{
    mainButton->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::nextRoundButtonClick(TObject *Sender)
{
    bounceCount = 0;

    TimerBall->Enabled = true;
    ball->Visible = true;
    mainButton->Visible = false;
    nextRoundButton->Visible = false;
    newGameButton->Visible = false;
    roundTable->Visible = false;
    mainTable->Visible = false;
    infoTable->Visible = false;
    resultTable->Visible = false;
    bouncesTable->Visible = false;

    if (player == "LEFT")
        {
            ball->Left = table->Left + paddleLeft->Width;
            axisX = 10;
            axisY = 10;
        }
    else if (player == "RIGHT")
        {
            ball->Left = table->Left + table->Width - paddleRight->Width;
            axisX = -10;
            axisY = -10;
        }

    randomize();
    ball->Top = random(table->Height - paddleLeft->Height) + paddleLeft->Height / 2;
}
//---------------------------------------------------------------------------



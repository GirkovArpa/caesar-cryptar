{ KOL MCK } // Do not remove this line!
{$DEFINE KOL_MCK}
{$ifdef FPC} {$mode delphi} {$endif}
program project1;

uses
  KOL,
   Unit1;

//{$R *.res}

//{$R *.res}

//{$R *.res}

{$R *.res}

begin // PROGRAM START HERE -- Please do not remove this comment

{$IFNDEF LAZIDE_MCK} {$I project1_0.inc} {$ELSE}

  Application.Title:='CaesarCryptar';
  Application.Scaled:=True;
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;

{$ENDIF}

end.


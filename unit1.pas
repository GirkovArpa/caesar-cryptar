{ KOL MCK } // Do not remove this line!
{$DEFINE KOL_MCK}
{$ifdef FPC} {$mode delphi} {$codepage utf8} {$endif}
unit Unit1;

interface

uses Windows, Messages, KOL {place your units here->}
{$IFDEF LAZIDE_MCK}, Forms, mirror, Classes, Controls, mckCtrls, mckObjs, Graphics;
{$ELSE} ; {$ENDIF}

type

  { TForm1 }

  {$I MCKfakeClasses.inc}
  {$IFDEF KOLCLASSES} TForm1 = class; PForm1 = TForm1; {$ELSE OBJECTS} PForm1 = ^TForm1; {$ENDIF CLASSES/OBJECTS}
  TForm1 = {$IFDEF LAZIDE_MCK}class(TForm{$ELSE}{$IFDEF KOLCLASSES}class{$ELSE}object{$ENDIF}(TObj{$ENDIF})
    ButtonDecrypt: TKOLButton;
    MyDropDown: TKOLComboBox;
    Form: PControl;
    ButtonEncrypt: TKOLButton;
    KOLForm1: TKOLForm;
    KOLProject: TKOLProject;
    MyMemo: TKOLMemo;
    procedure ButtonDecryptClick(Sender: PObj);
    procedure ButtonEncryptClick(Sender: PObj);
    procedure FormCreate(Sender: TObject);
    procedure KOLForm1FormCreate(Sender: PObj);
    procedure MyDropDownClick(Sender: PObj);
  private
    { private declarations }
  public
    { public declarations }
  end;

var
  Form1 {$IFDEF KOL_MCK} : PForm1 {$ELSE} : TForm1 {$ENDIF} ;

{$IFDEF KOL_MCK}
procedure NewForm1( var Result: PForm1; AParent: PControl );
{$ENDIF}

implementation

{$IFNDEF KOL_MCK} {$R *.lfm} {$ENDIF}

{ TForm1 }

{$IFNDEF LAZIDE_MCK}
{$IFDEF KOL_MCK}
{$I unit1_1.inc}
{$ENDIF}
{$ENDIF}

function StrToInt(src: String): Integer;
var
  int: Integer;
  code: Integer;
begin
  Val(src, int, code);
  Result := int;
end;

function indexOf(src: String; dst: String): Integer;
var
  idx: Integer;
  l: String;
begin
  idx := 0;
  for l in src do
  begin
  idx := idx + 1;
  if (l = dst) then
     begin
       Result := idx;
     end;
  end;
end;

function crypt(plaintext: String; shift: Integer): String;
var
  ciphertext: String;
  alphabet: String;
  pt: String;
  ct: String;
  idx: Integer;
begin
  alphabet := 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
  ciphertext := '';
  idx := 0;
  for pt in plaintext do
  begin
    if (pt = ' ') then
       ciphertext := ciphertext + ' '
    else begin
      idx := (indexOf(alphabet, pt) + shift) mod 26;
      while (idx <= 0) do idx := idx + 26;
      if (idx > 0) then
      begin
        ct := alphabet[idx];
        ciphertext := ciphertext + ct;
      end;
    end
  end;
  Result := ciphertext;
end;

procedure TForm1.ButtonEncryptClick(Sender: PObj);
begin
  MyMemo.Text := crypt(MyMemo.Text, StrToInt(MyDropdown.Caption));
end;

procedure TForm1.ButtonDecryptClick(Sender: PObj);
begin
  MyMemo.Text := crypt(MyMemo.Text, -StrToInt(MyDropdown.Caption));
end;

procedure TForm1.FormCreate(Sender: TObject);
begin

end;

procedure TForm1.KOLForm1FormCreate(Sender: PObj);
begin

end;

procedure TForm1.MyDropDownClick(Sender: PObj);
begin

end;

end.


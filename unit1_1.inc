{ KOL MCK } // Do not remove this line!

procedure NewForm1( var Result: PForm1; AParent: PControl );
begin

  {$ifndef wince}InitCommonControls;{$endif}
  {$IFDEF KOLCLASSES}
  Result := PForm1.Create;
  {$ELSE OBJECTS}
  New( Result, Create );
  {$ENDIF KOL CLASSES/OBJECTS}
  Result.Form := NewForm( AParent, 'CaesarCryptar' ){$ifndef wince}.SetPosition( 502, 200 ){$endif};
  Applet :=  Result.Form;
  Result.Form.Add2AutoFree( Result );
{$IFDEF UNICODE_CTRLS}{$IFNDEF wince}
     Result.Form.SetUnicode(TRUE);
{$ENDIF wince}{$ENDIF UNICODE_CTRLS}
   {$IFDEF USE_NAMES}
    Result.Form.SetName( Applet, 'Form1' );
   {$ENDIF}
    Result.Form.Style := Result.Form.Style and not (WS_MINIMIZEBOX or WS_MAXIMIZEBOX);
    {$ifndef wince}Result.Form.SetClientSize( 336, 258 );{$endif}
    Result.Form.Font.FontName := 'Arial';
    // Result.MyMemo.TabOrder = 0
    Result.MyMemo := NewEditBox( Result.Form, [ eoMultiline, eoNoHScroll, eoUpperCase ] ).SetPosition( 8, 8 ).SetSize( 320, 145 );
   {$IFDEF USE_NAMES}
    Result.MyMemo.SetName( Result.Form, 'MyMemo' ); 
   {$ENDIF}
    {$IFNDEF UNICODE_CTRLS}Result.MyMemo.SetUnicode( TRUE );{$ENDIF}
    Result.MyMemo.IgnoreDefault := FALSE;
    // Result.MyDropDown.TabOrder = 1
    Result.MyDropDown := NewComboBox( Result.Form, [ coReadOnly, coNoIntegralHeight ] ).SetPosition( 8, 160 ).SetSize( 320, 0 );
   {$IFDEF USE_NAMES}
    Result.MyDropDown.SetName( Result.Form, 'MyDropDown' ); 
   {$ENDIF}
   {$IFDEF UNICODE_CTRLS}{$IFNDEF wince}
   Result.MyDropDown.SetUnicode(TRUE);
   {$ENDIF wince}{$ENDIF UNICODE_CTRLS}
    Result.MyDropDown.Color := TColor(clWindow);
    Result.MyDropDown.Items[ 0 ] := '1';
    Result.MyDropDown.Items[ 1 ] := '2';
    Result.MyDropDown.Items[ 2 ] := '3';
    Result.MyDropDown.Items[ 3 ] := '4';
    Result.MyDropDown.Items[ 4 ] := '5';
    Result.MyDropDown.Items[ 5 ] := '6';
    Result.MyDropDown.Items[ 6 ] := '7';
    Result.MyDropDown.Items[ 7 ] := '8';
    Result.MyDropDown.Items[ 8 ] := '9';
    Result.MyDropDown.Items[ 9 ] := '10';
    Result.MyDropDown.Items[ 10 ] := '11';
    Result.MyDropDown.Items[ 11 ] := '12';
    Result.MyDropDown.Items[ 12 ] := '13';
    Result.MyDropDown.Items[ 13 ] := '14';
    Result.MyDropDown.Items[ 14 ] := '15';
    Result.MyDropDown.Items[ 15 ] := '16';
    Result.MyDropDown.Items[ 16 ] := '17';
    Result.MyDropDown.Items[ 17 ] := '18';
    Result.MyDropDown.Items[ 18 ] := '19';
    Result.MyDropDown.Items[ 19 ] := '20';
    Result.MyDropDown.Items[ 20 ] := '21';
    Result.MyDropDown.Items[ 21 ] := '22';
    Result.MyDropDown.Items[ 22 ] := '23';
    Result.MyDropDown.Items[ 23 ] := '24';
    Result.MyDropDown.Items[ 24 ] := '25';
    Result.MyDropDown.Items[ 25 ] := '26';
    Result.MyDropDown.CurIndex := 0;
    // Result.ButtonEncrypt.TabOrder = 2
    Result.ButtonEncrypt := NewButton( Result.Form, 'Encrypt' ).SetPosition( 7, 192 ).SetSize( 321, 25 );
   {$IFDEF USE_NAMES}
    Result.ButtonEncrypt.SetName( Result.Form, 'ButtonEncrypt' ); 
   {$ENDIF}
   {$IFDEF UNICODE_CTRLS}{$IFNDEF wince}
   Result.ButtonEncrypt.SetUnicode(TRUE);
   {$ENDIF wince}{$ENDIF UNICODE_CTRLS}
    // Result.ButtonDecrypt.TabOrder = 3
    Result.ButtonDecrypt := NewButton( Result.Form, 'Decrypt' ).SetPosition( 7, 224 ).SetSize( 321, 25 );
   {$IFDEF USE_NAMES}
    Result.ButtonDecrypt.SetName( Result.Form, 'ButtonDecrypt' ); 
   {$ENDIF}
   {$IFDEF UNICODE_CTRLS}{$IFNDEF wince}
   Result.ButtonDecrypt.SetUnicode(TRUE);
   {$ENDIF wince}{$ENDIF UNICODE_CTRLS}
    Result.MyMemo.Color := TColor(clWindow);
    {$IFDEF OVERRIDE_SCROLLBARS}
    OverrideScrollbars( Result.MyMemo);
    {$ENDIF OVERRIDE_SCROLLBARS}
      Result.MyDropDown.OnClick := Result.MyDropDownClick;
      Result.ButtonEncrypt.OnClick := Result.ButtonEncryptClick;
      Result.ButtonDecrypt.OnClick := Result.ButtonDecryptClick;
    Result.Form.CenterOnParent.CanResize := False;
    Result.Form.Perform( WM_INITMENU, 0, 0 );

end;


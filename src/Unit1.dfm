object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1089#1080#1085#1090#1077#1079#1072#1090#1086#1088#1086#1084' '#1095#1072#1089#1090#1086#1090
  ClientHeight = 711
  ClientWidth = 877
  Color = clSkyBlue
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -20
  Font.Name = 'Arial Unicode MS'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 26
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 513
    Height = 153
    Caption = #1057#1074#1103#1079#1100' '#1089' NPORT-5110'
    Color = clMoneyGreen
    ParentBackground = False
    ParentColor = False
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 40
      Width = 45
      Height = 26
      Caption = #1055#1086#1088#1090
    end
    object Label2: TLabel
      Left = 88
      Top = 119
      Width = 255
      Height = 26
      Caption = 'RealCOM 57600 1-8-1-None'
    end
    object ComboBox1: TComboBox
      Left = 88
      Top = 37
      Width = 145
      Height = 34
      ItemIndex = 1
      TabOrder = 0
      Text = '\\.\COM2'
      Items.Strings = (
        '\\.\COM1'
        '\\.\COM2'
        '\\.\COM3'
        '\\.\COM4'
        '\\.\COM5'
        '\\.\COM6'
        '\\.\COM7'
        '\\.\COM8'
        '\\.\COM9'
        '\\.\COM10'
        '\\.\COM11'
        '\\.\COM12'
        '\\.\COM13'
        '\\.\COM14'
        '\\.\COM15'
        '\\.\COM16'
        '\\.\COM17'
        '\\.\COM18'
        '\\.\COM19'
        '\\.\COM20'
        '\\.\COM21'
        '\\.\COM22'
        '\\.\COM23'
        '\\.\COM24'
        '\\.\COM25'
        '\\.\COM26'
        '\\.\COM27'
        '\\.\COM28'
        '\\.\COM29'
        '\\.\COM30')
    end
    object Button1: TButton
      Left = 264
      Top = 34
      Width = 113
      Height = 40
      Caption = #1054#1090#1082#1088#1099#1090#1100
      TabOrder = 1
      OnClick = Button1Click
    end
    object ProgressBar1: TProgressBar
      Left = 88
      Top = 88
      Width = 289
      Height = 25
      TabOrder = 2
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 176
    Width = 513
    Height = 521
    Caption = #1063#1072#1089#1090#1086#1090#1099
    Color = clMoneyGreen
    ParentBackground = False
    ParentColor = False
    ParentShowHint = False
    ShowHint = False
    TabOrder = 1
    object Label3: TLabel
      Left = 16
      Top = 48
      Width = 52
      Height = 26
      Caption = 'DDS1'
    end
    object Label4: TLabel
      Left = 16
      Top = 88
      Width = 52
      Height = 26
      Caption = 'DDS2'
    end
    object Label5: TLabel
      Left = 16
      Top = 128
      Width = 52
      Height = 26
      Caption = 'DDS3'
    end
    object Label6: TLabel
      Left = 16
      Top = 176
      Width = 52
      Height = 26
      Caption = 'DDS4'
    end
    object Label7: TLabel
      Left = 16
      Top = 224
      Width = 52
      Height = 26
      Caption = 'DDS5'
    end
    object Label8: TLabel
      Left = 16
      Top = 272
      Width = 52
      Height = 26
      Caption = 'DDS6'
    end
    object Label9: TLabel
      Left = 16
      Top = 320
      Width = 52
      Height = 26
      Caption = 'DDS7'
    end
    object Label10: TLabel
      Left = 16
      Top = 368
      Width = 52
      Height = 26
      Caption = 'DDS8'
    end
    object Label11: TLabel
      Left = 215
      Top = 48
      Width = 42
      Height = 26
      Caption = 'F,Hz'
    end
    object Label12: TLabel
      Left = 215
      Top = 88
      Width = 42
      Height = 26
      Caption = 'F,Hz'
    end
    object Label13: TLabel
      Left = 215
      Top = 131
      Width = 42
      Height = 26
      Caption = 'F,Hz'
    end
    object Label14: TLabel
      Left = 215
      Top = 176
      Width = 42
      Height = 26
      Caption = 'F,Hz'
    end
    object Label15: TLabel
      Left = 215
      Top = 224
      Width = 42
      Height = 26
      Caption = 'F,Hz'
    end
    object Label16: TLabel
      Left = 215
      Top = 272
      Width = 42
      Height = 26
      Caption = 'F,Hz'
    end
    object Label17: TLabel
      Left = 215
      Top = 320
      Width = 42
      Height = 26
      Caption = 'F,Hz'
    end
    object Label18: TLabel
      Left = 215
      Top = 368
      Width = 42
      Height = 26
      Caption = 'F,Hz'
    end
    object Label19: TLabel
      Left = 415
      Top = 48
      Width = 48
      Height = 26
      Caption = #1075#1088#1072#1076'.'
    end
    object Label20: TLabel
      Left = 415
      Top = 88
      Width = 48
      Height = 26
      Caption = #1075#1088#1072#1076'.'
    end
    object Label21: TLabel
      Left = 415
      Top = 128
      Width = 48
      Height = 26
      Caption = #1075#1088#1072#1076'.'
    end
    object Label22: TLabel
      Left = 415
      Top = 176
      Width = 48
      Height = 26
      Caption = #1075#1088#1072#1076'.'
    end
    object Label23: TLabel
      Left = 415
      Top = 224
      Width = 48
      Height = 26
      Caption = #1075#1088#1072#1076'.'
    end
    object Label24: TLabel
      Left = 415
      Top = 272
      Width = 48
      Height = 26
      Caption = #1075#1088#1072#1076'.'
    end
    object Label25: TLabel
      Left = 415
      Top = 320
      Width = 48
      Height = 26
      Caption = #1075#1088#1072#1076'.'
    end
    object Label26: TLabel
      Left = 415
      Top = 368
      Width = 48
      Height = 26
      Caption = #1075#1088#1072#1076'.'
    end
    object Edit1: TEdit
      Left = 88
      Top = 45
      Width = 121
      Height = 34
      Hint = 'Frot1'
      MaxLength = 7
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      Text = '0'
      TextHint = 'Frot1'
      OnKeyPress = Edit17KeyPress
    end
    object Edit2: TEdit
      Left = 88
      Top = 85
      Width = 121
      Height = 34
      Hint = 'Frot2'
      MaxLength = 7
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      Text = '0'
      OnKeyPress = Edit17KeyPress
    end
    object Edit3: TEdit
      Left = 88
      Top = 128
      Width = 121
      Height = 34
      Hint = 'F1*Z1'
      MaxLength = 7
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      Text = '0'
      TextHint = 'F1*Z1'
      OnKeyPress = Edit17KeyPress
    end
    object Edit4: TEdit
      Left = 88
      Top = 173
      Width = 121
      Height = 34
      Hint = 'F1*Z2'
      MaxLength = 7
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      Text = '0'
      TextHint = 'F1*Z2'
      OnKeyPress = Edit17KeyPress
    end
    object Edit5: TEdit
      Left = 88
      Top = 221
      Width = 121
      Height = 34
      Hint = 'F2*Z1'
      MaxLength = 7
      ParentShowHint = False
      ShowHint = True
      TabOrder = 4
      Text = '0'
      TextHint = 'F2*Z1'
      OnKeyPress = Edit17KeyPress
    end
    object Edit6: TEdit
      Left = 88
      Top = 269
      Width = 121
      Height = 34
      Hint = 'F2*Z2'
      MaxLength = 7
      ParentShowHint = False
      ShowHint = True
      TabOrder = 5
      Text = '0'
      TextHint = 'F2*Z2'
      OnKeyPress = Edit17KeyPress
    end
    object Edit7: TEdit
      Left = 88
      Top = 320
      Width = 121
      Height = 34
      Hint = 'Fx1 '#1087#1088#1086#1080#1079#1074#1086#1083#1100#1085#1072#1103
      MaxLength = 7
      ParentShowHint = False
      ShowHint = True
      TabOrder = 6
      Text = '0'
      TextHint = #1055#1088#1086#1080#1079#1074#1086#1083#1100#1085#1072#1103' '#1095#1072#1089#1090#1086#1090#1072
      OnKeyPress = Edit17KeyPress
    end
    object Edit8: TEdit
      Left = 88
      Top = 368
      Width = 121
      Height = 34
      Hint = 'Fx2 '#1087#1088#1086#1080#1079#1074#1086#1083#1100#1085#1072#1103
      MaxLength = 7
      ParentShowHint = False
      ShowHint = True
      TabOrder = 7
      Text = '0'
      TextHint = #1055#1088#1086#1080#1079#1074#1086#1083#1100#1085#1072#1103' '#1095#1072#1089#1090#1086#1090#1072
      OnKeyPress = Edit17KeyPress
    end
    object Edit9: TEdit
      Left = 280
      Top = 45
      Width = 121
      Height = 34
      MaxLength = 7
      ParentShowHint = False
      ShowHint = False
      TabOrder = 8
      Text = '0'
      TextHint = '22222'
      OnKeyPress = Edit17KeyPress
    end
    object Edit10: TEdit
      Left = 280
      Top = 85
      Width = 121
      Height = 34
      MaxLength = 7
      TabOrder = 9
      Text = '0'
      OnKeyPress = Edit17KeyPress
    end
    object Edit11: TEdit
      Left = 280
      Top = 125
      Width = 121
      Height = 34
      MaxLength = 7
      TabOrder = 10
      Text = '0'
      OnKeyPress = Edit17KeyPress
    end
    object Edit12: TEdit
      Left = 280
      Top = 173
      Width = 121
      Height = 34
      MaxLength = 7
      TabOrder = 11
      Text = '0'
      OnKeyPress = Edit17KeyPress
    end
    object Edit13: TEdit
      Left = 280
      Top = 221
      Width = 121
      Height = 34
      MaxLength = 7
      TabOrder = 12
      Text = '0'
      OnKeyPress = Edit17KeyPress
    end
    object Edit14: TEdit
      Left = 280
      Top = 269
      Width = 121
      Height = 34
      MaxLength = 7
      TabOrder = 13
      Text = '0'
      OnKeyPress = Edit17KeyPress
    end
    object Edit15: TEdit
      Left = 280
      Top = 320
      Width = 121
      Height = 34
      MaxLength = 7
      TabOrder = 14
      Text = '0'
      OnKeyPress = Edit17KeyPress
    end
    object Edit16: TEdit
      Left = 280
      Top = 368
      Width = 121
      Height = 34
      MaxLength = 7
      TabOrder = 15
      Text = '0'
      OnKeyPress = Edit17KeyPress
    end
    object Button2: TButton
      Left = 16
      Top = 416
      Width = 193
      Height = 65
      Caption = #1047#1072#1087#1080#1089#1100' '#1095#1072#1089#1090#1086#1090
      Enabled = False
      TabOrder = 16
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 279
      Top = 416
      Width = 184
      Height = 30
      Caption = #1047#1072#1087#1080#1089#1100' '#1092#1072#1079
      Enabled = False
      TabOrder = 17
      OnClick = Button3Click
    end
    object ProgressBar2: TProgressBar
      Left = 16
      Top = 487
      Width = 447
      Height = 17
      TabOrder = 18
    end
    object Button4: TButton
      Left = 280
      Top = 451
      Width = 183
      Height = 30
      Caption = 'Read state'
      Enabled = False
      TabOrder = 19
      OnClick = Button4Click
    end
  end
  object Memo1: TMemo
    Left = 536
    Top = 224
    Width = 333
    Height = 250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial Unicode MS'
    Font.Style = []
    Lines.Strings = (
      'S1 '#215' T1 = S2 '#215' T2, '#1043#1076#1077':'
      ' S1 '#8211' '#1095#1072#1089#1090#1086#1090#1072' '#1074#1088#1072#1097#1077#1085#1080#1103' '
      '('#1074#1077#1076#1091#1097#1077#1081') '#1096#1077#1089#1090#1077#1088#1085#1080','
      #1058'1 '#8211' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1079#1091#1073#1100#1077#1074
      '('#1074#1077#1076#1091#1097#1077#1081') '#1096#1077#1089#1090#1077#1088#1085#1080';'
      'S2- '#1095#1072#1089#1090#1086#1090#1072' '#1074#1088#1072#1097#1077#1085#1080#1103' '
      #1096#1077#1089#1090#1077#1088#1085#1080','
      #1058'2 '#8211' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1079#1091#1073#1100#1077#1074'  '
      #1096#1077#1089#1090#1077#1088#1085#1080'.'
      #1050#1053#1044' 40,'#1042#1077#1076#1091#1097#1080#1081' 69,'#1055#1088#1086#1084#1074#1072#1083' 50,'#1050#1042#1044' 29')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object GroupBox3: TGroupBox
    Left = 536
    Top = 8
    Width = 333
    Height = 201
    Caption = #1048#1089#1093#1086#1076#1085#1099#1077' '#1076#1072#1085#1085#1099#1077
    Color = clMoneyGreen
    ParentBackground = False
    ParentColor = False
    TabOrder = 3
    OnClick = GroupBox3Click
    object Label27: TLabel
      Left = 16
      Top = 34
      Width = 53
      Height = 26
      Caption = 'Frot.1'
    end
    object Label28: TLabel
      Left = 16
      Top = 82
      Width = 53
      Height = 26
      Caption = 'Frot.2'
    end
    object Label29: TLabel
      Left = 24
      Top = 114
      Width = 23
      Height = 26
      Caption = 'Z1'
    end
    object Label30: TLabel
      Left = 24
      Top = 154
      Width = 23
      Height = 26
      Caption = 'Z2'
    end
    object Label31: TLabel
      Left = 232
      Top = 34
      Width = 64
      Height = 26
      Caption = #1086#1073'/'#1084#1080#1085
    end
    object Label32: TLabel
      Left = 232
      Top = 66
      Width = 64
      Height = 26
      Caption = #1086#1073'/'#1084#1080#1085
    end
    object Edit17: TEdit
      Left = 91
      Top = 31
      Width = 121
      Height = 34
      MaxLength = 7
      TabOrder = 0
      Text = '6000'
      OnKeyPress = Edit17KeyPress
    end
    object Edit18: TEdit
      Left = 91
      Top = 71
      Width = 121
      Height = 34
      MaxLength = 7
      TabOrder = 1
      Text = '0'
      OnKeyPress = Edit17KeyPress
    end
    object Edit19: TEdit
      Left = 91
      Top = 111
      Width = 121
      Height = 34
      MaxLength = 7
      TabOrder = 2
      Text = '22'
      OnKeyPress = Edit17KeyPress
    end
    object Edit20: TEdit
      Left = 91
      Top = 151
      Width = 121
      Height = 34
      MaxLength = 7
      TabOrder = 3
      Text = '33'
      OnKeyPress = Edit17KeyPress
    end
  end
  object Memo2: TMemo
    Left = 536
    Top = 480
    Width = 333
    Height = 217
    ScrollBars = ssVertical
    TabOrder = 4
    OnDblClick = Memo2DblClick
  end
  object Button5: TButton
    Left = 424
    Top = 184
    Width = 75
    Height = 25
    Caption = 'Button5'
    TabOrder = 5
    OnClick = Button5Click
  end
end

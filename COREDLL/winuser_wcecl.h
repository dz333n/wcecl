#pragma once

// Window Style
#define WINCE_WS_OVERLAPPED       WINCE_WS_BORDER | WINCE_WS_CAPTION
#define WINCE_WS_CLIPSIBLINGS     0x04000000L
#define WINCE_WS_CLIPCHILDREN     0x02000000L
#define WINCE_WS_CAPTION          0x00C00000L     /* WINCE_WS_BORDER | WINCE_WS_DLGFRAME  */
#define WINCE_WS_BORDER           0x00800000L
#define WINCE_WS_DLGFRAME         0x00400000L
#define WINCE_WS_VSCROLL          0x00200000L
#define WINCE_WS_HSCROLL          0x00100000L
#define WINCE_WS_SYSMENU          0x00080000L
#define WINCE_WS_THICKFRAME       0x00040000L
#define WINCE_WS_MAXIMIZEBOX      0x00020000L
#define WINCE_WS_MINIMIZEBOX      0x00010000L
#define WINCE_WS_SIZEBOX          WINCE_WS_THICKFRAME
#define WINCE_WS_POPUP            0x80000000L

// Window Style Extended
#define WINCE_WS_EX_DLGMODALFRAME     0x00000001L
#define WINCE_WS_EX_TOPMOST           0x00000008L
#define WINCE_WS_EX_TOOLWINDOW        0x00000080L
#define WINCE_WS_EX_WINDOWEDGE        0x00000100L
#define WINCE_WS_EX_CLIENTEDGE        0x00000200L
#define WINCE_WS_EX_CONTEXTHELP	      0x00000400L
#define WINCE_WS_EX_RIGHT             0x00001000L
#define WINCE_WS_EX_RTLREADING        0x00002000L
#define WINCE_WS_EX_LEFTSCROLLBAR     0x00004000L
#define WINCE_WS_EX_STATICEDGE        0x00020000L
#define WINCE_WS_EX_NOINHERITLAYOUT   0x00100000L // Disable inheritence of mirroring by children
#define WINCE_WS_EX_LAYOUTRTL         0x00400000L // Right to left mirroring
#define WINCE_WS_EX_OVERLAPPEDWINDOW  (WINCE_WS_EX_WINDOWEDGE | WINCE_WS_EX_CLIENTEDGE)
#define WINCE_WS_EX_CAPTIONOKBTN      0x80000000L
#define WINCE_WS_EX_NODRAG            0x40000000L
#define WINCE_WS_EX_ABOVESTARTUP      0x20000000L
#define WINCE_WS_EX_INK				  0x10000000L
#define WINCE_WS_EX_NOANIMATION		  0x04000000L

// Show Window
#define WINCE_SW_HIDE               0
#define WINCE_SW_SHOWNORMAL         1
#define WINCE_SW_SHOWNOACTIVATE     4
#define WINCE_SW_SHOW               5
#define WINCE_SW_MINIMIZE           6
#define WINCE_SW_SHOWNA             8
#define WINCE_SW_SHOWMAXIMIZED	    11
#define WINCE_SW_MAXIMIZE			12
#define WINCE_SW_RESTORE			13

// Class Style
#define WINCE_CS_VREDRAW          0x0001
#define WINCE_CS_HREDRAW          0x0002
#define WINCE_CS_DBLCLKS          0x0008
#define WINCE_CS_PARENTDC         0x0080
#define WINCE_CS_NOCLOSE          0x0200
#define WINCE_CS_SAVEBITS         0x0800
#define WINCE_CS_GLOBALCLASS      0x4000
#define WINCE_CS_IME              0x00010000

// Dialog Style
#define WINCE_DS_LOCALEDIT        0x20L   /* Edit items get Local storage. */
#define WINCE_DS_SETFONT          0x40L   /* User specified font for Dlg controls */
#define WINCE_DS_MODALFRAME       0x80L   /* Can be combined with WS_CAPTION  */
#define WINCE_DS_SETFOREGROUND    0x200L  /* not in Windows 3.1 */
#define WINCE_DS_3DLOOK           0x0004L
#define WINCE_DS_CONTROL          0x0400L
#define WINCE_DS_CENTER           0x0800L
#define WINCE_DS_NOCLOSEBTN		0x4000L

#include <Scratch.h>


int main() {
	ExMessage m;
	groundsize(GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
	groundcolor(0xFFFFFF);
	setbkmode(TRANSPARENT);
	cleardevice();
	HWND hWnd = GetHWnd();
	SetWindowPos(hWnd, HWND_TOPMOST, 0,0, 100,100, SWP_SHOWWINDOW);
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_CAPTION);
	SetLayeredWindowAttributes(hWnd, 0, 1, LWA_ALPHA);
	MoveWindow(hWnd,0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN),TRUE);
	m = getmessage(EM_MOUSE);
	Sleep(100);

	hWnd = GetHWnd();
	HRGN rgn = CreateRoundRectRgn(0, 0, 100, 100,15,15);
	SetWindowRgn(hWnd, rgn, true);
	SetLayeredWindowAttributes(hWnd, 0, 255, LWA_ALPHA);
	SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	MoveWindow(hWnd,m.x,m.y,100,100,TRUE);
	settextstyle(30,0,"Microsoft Yahei");
	settextcolor(0);
	outtextxy(30,10,"退出");
	outtextxy(8,62,"报告BUG");
	while(true){
		m = getmessage(EM_MOUSE);
		if(m.x>10 && m.x<90 && m.y>10 && m.y<40){
			setlinecolor(RGB(189,184,184));
			setfillcolor(RGB(189,184,184));
			fcubes(10,90,10,45);
			outtextxy(30,5,"退出");
			outtextxy(8,62,"报告BUG");
			if(m.message==WM_LBUTTONDOWN){
				system("taskkill /f /im MacDock.exe");
				return 0;
			}
		}
		else if(m.x>10 && m.x<90 && m.y>50 && m.y<90){
			setlinecolor(RGB(189,184,184));
			setfillcolor(RGB(189,184,184));
			fcubes(10,90,45,90);
			outtextxy(30,5,"退出");
			outtextxy(8,62,"报告BUG");
			if(m.message==WM_LBUTTONDOWN){
				system("start https://github.com/SoftOSDev/MacDock");
				return 0;
			}
		}
		else if(m.message==WM_LBUTTONDOWN){
			return 0;
		}
		else{
			//groundcolor(0xFFFFFF);
			cleardevice();
			outtextxy(30,5,"退出");
			outtextxy(8,62,"报告BUG");
		}
	}
	over();
}
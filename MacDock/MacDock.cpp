#include <Scratch.h>


int main() {
	initgraph(600,100,WS_EX_TOOLWINDOW);
	groundcolor(0/*xFFFFFF*/);
	cleardevice();
	HWND hWnd = GetHWnd();
	ShowWindow(hWnd, SW_HIDE );
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_CAPTION);
	hWnd = GetHWnd();
	HRGN rgn = CreateRoundRectRgn(0, 0, 600, 100,40,40);
	SetWindowRgn(hWnd, rgn, true);
	SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hWnd, 0, 200, LWA_ALPHA);
	SetWindowPos(hWnd, HWND_TOPMOST, 0,0, 600,100, SWP_SHOWWINDOW);
	MoveWindow(hWnd,GetSystemMetrics(SM_CYSCREEN)/2+80,GetSystemMetrics(SM_CXSCREEN)/2-40,600,100,TRUE);
	IMAGE finder,setting,note,calc,cmd,mstore,rc;
	loadimage(&finder,"finder.png",60,60);
	loadimage(&setting,"setup.png",60,60);
	loadimage(&note,"notes.png",60,60);
	loadimage(&calc,"calc.png",60,60);
	loadimage(&cmd,"cmd.png",60,60);
	loadimage(&mstore,"store.png",60,60);
	loadimage(&rc,"rc.png",60,60);
	putimage(20,20,&finder);
	putimage(100,20,&setting);
	putimage(180,20,&note);
	putimage(260,20,&calc);
	putimage(340,20,&cmd);
	putimage(420,20,&mstore);
	putimage(520,20,&rc);
	ExMessage m;
	while(true){
		m = getmessage(EM_MOUSE);
		if(m.x>20 && m.x<80 && m.y>20 && m.y<80){
			setlinecolor(BLUE);
			cubes(18,82,18,82);
			if(m.message==WM_LBUTTONDOWN){
				system("explorer=");
			}
		}
		if(m.x>100 && m.x<160 && m.y>20 && m.y<80){
			setlinecolor(BLUE);
			cubes(98,162,18,82);
			if(m.message==WM_LBUTTONDOWN){
				system("start ms-settings:");
			}
		}
		if(m.x>180 && m.x<240 && m.y>20 && m.y<80){
			setlinecolor(BLUE);
			cubes(178,242,18,82);
			if(m.message==WM_LBUTTONDOWN){
				system("notepad");
			}
		}
		if(m.x>260 && m.x<320 && m.y>20 && m.y<80){
			setlinecolor(BLUE);
			cubes(258,322,18,82);
			if(m.message==WM_LBUTTONDOWN){
				system("calc");
			}
		}
		if(m.x>340 && m.x<400 && m.y>20 && m.y<80){
			setlinecolor(BLUE);
			cubes(338,402,18,82);
			if(m.message==WM_LBUTTONDOWN){
				system("start cmd");
			}
		}
		if(m.x>420 && m.x<480 && m.y>20 && m.y<80){
			setlinecolor(BLUE);
			cubes(418,482,18,82);
			if(m.message==WM_LBUTTONDOWN){
				system("start zune:");
			}
		}
		if(m.x>520 && m.x<560 && m.y>20 && m.y<80){
			setlinecolor(BLUE);
			cubes(528,572,18,82);
			if(m.message==WM_LBUTTONDOWN){
				system("explorer ::{645FF040-5081-101B-9F08-00AA002F954E}");
			}
		} 
		if(m.message==WM_LBUTTONDOWN){
			PostMessage(hWnd, WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(m.x, m.y));
		}
		if(m.message==WM_RBUTTONDOWN){
	        system("start RightBottonPress.exe");
		}
		else{
			cleardevice();
			putimage(20,20,&finder);
			putimage(100,20,&setting);
			putimage(180,20,&note);
			putimage(260,20,&calc);
			putimage(340,20,&cmd);
			putimage(420,20,&mstore);
			putimage(520,20,&rc);
		}
	}
	over();
}												   
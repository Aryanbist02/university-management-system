void main(void)
{

	main_menu ob_menu ;
	int gdriver = DETECT, gmode, errorcode ;
	char pass[10], ch ;

	initgraph(&gdriver, &gmode, "c:\\tc\\bgi") ;

	ob_menu.welcome_screen() ;

	closegraph() ;
	ob_menu.control_menu() ;

	getch() ;
	closegraph() ;
}
#include <ncurses.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
enum menu_principale{
	MENU,
	CHECK,
	RETURN,
	PARCOURIR,
	OPTION,
	QUITTER
};
enum check_and_return{
	tmp,
	by_num,
	by_name,
	go_back
};
enum options{
	temporary,
	langue,
	theme,
	zetinareo,
	back
};
enum langue{
	temp,
	francais,
	anglais,
	malagasy,
	goback
};
typedef struct modify_langue{
	char** menu;
	char** checker;
	char** retourner;
	char** parcourir;
	char** option;
	char** quitter;
	char** langueP;
	char** others;
}modify_langue;

int menu(WINDOW* win,int count, ...); 
modify_langue modify_francais ( modify_langue change);
modify_langue modify_anglais ( modify_langue change);
modify_langue modify_malagasy ( modify_langue change);
int main(int argc,char** argv)
{
	initscr();
	curs_set(0);
	cbreak();
	noecho();
	modify_langue change;
	change = modify_francais(change);	//initialisation 
	menu:
	switch(menu(stdscr,6,change.menu[0],change.menu[1],change.menu[2],change.menu[3],change.menu[4],change.menu[5]))			//ngeza ndrindra
	{
		case CHECK:																						//si check
		clear();
		check:
		switch(menu(stdscr,4,change.checker[0],change.checker[1], change.checker[2],change.checker[3]))									//faire switch
		{
			case by_num:
			clear();
			printw("petafana eto le algo an le by numero");
			refresh();
			napms(2000);
			clear();
			goto check;
			break;
			case by_name:
			clear();
			printw("petafana eto le algo an le by name");
			refresh();
			napms(2000);
			clear();
			goto check;
			break;
			case go_back:
			clear();
			refresh();
			goto menu;
			break;
		}
		break;
		case RETURN:																//si return
		clear();
		retourner:
		switch(menu(stdscr,4,change.retourner[0],change.retourner[1], change.retourner[2],change.retourner[3]))			//choisir entre ...
		{
			case by_num:
			clear();
			printw("petafana eto le algo an le by numero");
			refresh();
			napms(2000);
			clear();
			goto retourner;
			break;
			case by_name:
			clear();
			printw("petafana eto le algo an le by name");
			refresh();
			napms(2000);
			clear();
			goto retourner;
			break;
			case go_back:
			clear();
			refresh();
			goto menu;
			break;
		}break;
		case PARCOURIR:														//si parcourir
		clear();
		parcourir:
		switch(menu(stdscr,4,change.parcourir[0],change.parcourir[1], change.parcourir[2],change.parcourir[3]))		//choisir entre
		{
			case by_num:
			clear();
			printw("petafana eto le algo an le by numero");
			refresh();
			napms(2000);
			clear();
			goto parcourir;
			break;
			case by_name:
			clear();
			printw("petafana eto le algo an le by name");
			refresh();
			napms(2000);
			clear();
			goto parcourir;
			break;
			case go_back:
			clear();
			refresh();
			goto menu;
			break;
		}
		break;
		case OPTION:																		//si option
		clear();
		option:
		switch (menu(stdscr,4,change.option[0] , change.option[1],change.option[2],change.option[3])){		//choisir entre : 
			case langue:																		// langue
			switch(menu(stdscr,5,change.langueP[0],change.langueP[1] , change.langueP[2], change.langueP[3],change.langueP[4]))
			{
				case francais:
				clear();
				printw("vous avez choisis le francaise");
				change = modify_francais (change);
				refresh();
				napms(2000);
				clear();
				goto menu;
				break;
				case anglais:
				clear();
				printw("you choose english ");
				change = modify_anglais (change);
				refresh();
				napms(2000);
				clear();
				goto menu;
				break;
				case malagasy:
				clear();
				printw("teny malagasy no nosafidinao");
				change = modify_malagasy (change);
				napms(2000);
				clear();
				goto menu;
				break;
				case goback:
				clear();
				refresh();
				goto menu;
				break;
			}
			case theme:
			clear();
			printw("theme milay be");
			refresh();
			napms(2000);
			clear();
			goto option;
			break;
			case zetinareo:
			clear();
			printw("tena ze tinareo");
			refresh();
			napms(2000);
			clear();
			goto option;
			break;
			case back:
			clear();
			refresh();
			goto menu;
			break;
		}
		break;
		case QUITTER:
		clear();
		printw("%s.",change.quitter);
		clear();
		printw("%s..",change.quitter);
		clear();
		printw("%s...",change.quitter);
		clear();
		printw("%s....",change.quitter);
		refresh();
		napms(2000);
		break;
	}
	for (int i = 0; i < 6; i++) {
        free(change.menu[i]);
    }
    for (int i = 0; i < 4; i++) {
        free(change.checker[i]);
        free(change.retourner[i]);
        free(change.parcourir[i]);
        free(change.option[i]);
        free(change.langueP[i]);
		free(change.langueP[i]);
    }
    free(change.quitter[0]);
    free(change.quitter);
	endwin();
	return 0;
}

int menu(WINDOW* win,int count, ...)
{
	keypad(win,true);
	va_list arg;
	va_start(arg,count);
	start_color();
	init_pair (1,COLOR_BLACK,COLOR_YELLOW);
	init_pair (2,COLOR_YELLOW,COLOR_BLACK);
	
	char **argument=(char**)malloc(count*sizeof(char*));;
	int i,c,heighlight=1,y,x;
	getmaxyx(stdscr,y,x);
	for(i=0; i<count ; i++)
	{
		argument[i]=(char*)malloc(200*sizeof(char));
		sprintf(argument[i],"%s" , va_arg(arg, char*));
	}
	wattron(win, COLOR_PAIR(1));
	mvwprintw(win,0,x/2-22,"﴾﴾﴾﴾﴾﴾﴾﴾ %s ﴿﴿﴿﴿﴿﴿﴿﴿\n\n\n", argument[0]);		//titre
		for (i = 1; i < count; i++) {
        if (i == heighlight)
            wattron(win, COLOR_PAIR(1) | A_BOLD | A_DIM);  
		else
			wbkgd(stdscr, COLOR_PAIR(2));		//arrrière plan
            wattron(win, COLOR_PAIR(2));
			WINDOW *window = subwin(win, 4, x - 25, i * 4, 10);  
			box(window, 0, 0);
			mvwprintw(win, i * 4 + 1, x / 2 - 10, "༺   %s ༻", argument[i]);
			wrefresh(window);
			delwin(window);
        wattroff(win, A_BOLD | A_DIM);
        wrefresh(win);
		}
	
	 while((c=getch())!='\n')
	{
		switch (c)
	{
		case KEY_UP:
			heighlight-=(heighlight==1)? 0:1;
			break;
		
		case KEY_DOWN:
			heighlight+=(heighlight==count-1)? 0:1;
			break;
	}for (i = 1; i < count; i++) {
        if (i == heighlight)
            wattron(win, COLOR_PAIR(1) | A_BOLD | A_DIM | A_BLINK);  
		else
			wbkgd(stdscr, COLOR_PAIR(2));				//arrrière plan
            wattron(win, COLOR_PAIR(2));
			WINDOW *window = subwin(win, 4, x - 25, i * 4, 10);  
			box(window, 0, 0);
			mvwprintw(win, i * 4 + 1, x / 2 - 10, "༺   %s ༻", argument[i]);
			wrefresh(window);
			delwin(window);
        wattroff(win, A_BOLD | A_DIM | A_BLINK);
        wrefresh(win);
		}
	}
	va_end(arg);
	return heighlight;
}	
modify_langue modify_malagasy ( modify_langue change){
	change.menu = (char**)malloc(6 * sizeof(char*));
	for (int i=0; i<6; i++){
		change.menu[i] = (char*)malloc(6 * sizeof(char)); 
	}
	if (change.menu == NULL){
		printf("erreur d'allocation ! '");
		exit(1);
	}
	strcpy(change.menu[0], " MENIO LEHIBE ");
    strcpy(change.menu[1], "tsikiro");
    strcpy(change.menu[2], "hamerina");
    strcpy(change.menu[3], "mitady");
    strcpy(change.menu[4], "safidy");
    strcpy(change.menu[5], "hiverina");
    
	change.checker = (char**)malloc(4 * sizeof(char*));
    for (int i=0; i<4; i++){
		change.checker[i] = (char*)malloc(4 * sizeof(char)); 
	}
	if (change.checker == NULL){
		printf("erreur d'allocation ! '");
		exit(1);
	}
	strcpy(change.checker[0], " tsikiro ");			
    strcpy(change.checker[1], " amin'ny laharana ");			
    strcpy(change.checker[2], " amin'ny anarana");
    strcpy(change.checker[3], "hiverina");

	change.retourner = (char**)malloc(4 * sizeof(char*));
    for (int i=0; i<4; i++){
		change.retourner[i] = (char*)malloc(4 * sizeof(char)); 
	}
	if (change.retourner == NULL){
		printf("erreur d'allocation ! '");
		exit(1);
	}
	strcpy(change.retourner[0], " hamerina ");
    strcpy(change.retourner[1], " amin'ny laharana ");
    strcpy(change.retourner[2], "amin'ny anarana");
    strcpy(change.retourner[3], "hiverina");
    
	change.parcourir = (char**)malloc(4 * sizeof(char*));
    for (int i=0; i<4; i++){
		change.parcourir[i] = (char*)malloc(4 * sizeof(char)); 
	}
	if (change.parcourir == NULL){
		printf("erreur d'allocation ! '");
		exit(1);
	}
	strcpy(change.parcourir[0], " mitady ");
    strcpy(change.parcourir[1], " amin'ny laharana ");
    strcpy(change.parcourir[2], " amin'ny anarana ");
    strcpy(change.parcourir[3], "hiverina");
    
    change.option = (char**)malloc(4 * sizeof(char*));
    for (int i=0; i<4; i++){
		change.option[i] = (char*)malloc(4 * sizeof(char)); 
	}
	if (change.option == NULL){
			printf("erreur d'allocation ! '");
			exit(1);
		}
	strcpy(change.option[0], " safidy  ");
    strcpy(change.option[1], " fiteny  ");
    strcpy(change.option[2], " endrika ");
    strcpy(change.option[3], "hiverina");
    
    change.quitter = (char**)malloc(sizeof(char*));
	change.quitter[0] = (char*)malloc(50 * sizeof(char));
	if (change.quitter == NULL || change.quitter[0] == NULL) {
		printf("Erreur d'allocation pour change.quitter");
		exit(1);
	}
	strcpy(change.quitter[0], "quitter le programme");

    
     change.langueP = (char**)malloc(5 * sizeof(char*));
    for (int i=0; i<5; i++){
		change.langueP[i] = (char*)malloc(5 * sizeof(char)); 
	}
	if (change.langueP == NULL){
		printf("erreur d'allocation ! '");
		exit(1);
	}
	strcpy(change.langueP[0], " fiteny ");
    strcpy(change.langueP[1], " frantsay ");
    strcpy(change.langueP[2], " anglisy ");
    strcpy(change.langueP[3], " malagasy ");
    strcpy(change.langueP[4], "hiverina");
    
	change.others = (char**)malloc(5 * sizeof(char*));
    for (int i=0; i<5; i++){
		change.others[i] = (char*)malloc(5 * sizeof(char)); 
	}
	if (change.others == NULL){
		printf("erreur d'allocation ! '");
		exit(1);
	}
	strcpy(change.others[0], " laharana ");
    strcpy(change.others[1], " anarana ");
    strcpy(change.others[2], " Eny ");
    strcpy(change.others[3], " Tsia ");
	strcpy(change.others[4], " tena manokana ");

    return change;
}
modify_langue modify_anglais ( modify_langue change){
	change.menu= (char**)malloc(6 * sizeof(char*));
	for (int i=0; i<6; i++){
		change.menu[i] = (char*)malloc(6 * sizeof(char)); 
	}
		if (change.menu== NULL){
			printf("erreur d'allocation ! '");
			exit(1);
		}
	strcpy(change.menu[0], " MAIN");
    strcpy(change.menu[1], "check");
    strcpy(change.menu[2], "return");
    strcpy(change.menu[3], "browse");
    strcpy(change.menu[4], "option");
    strcpy(change.menu[5], "leave");
    
    change.checker = (char**)malloc(4 * sizeof(char*));
    for (int i=0; i<4; i++){
		change.checker[i] = (char*)malloc(4 * sizeof(char)); 
	}
	if (change.checker == NULL){
		printf("erreur d'allocation ! ");
		exit(1);
	}
	strcpy(change.checker[0], " check ");
    strcpy(change.checker[1], " by number");			
    strcpy(change.checker[2], "by name");
    strcpy(change.checker[3], "go back");

    change.retourner = (char**)malloc(4 * sizeof(char*));
    for (int i=0; i<4; i++){
		change.retourner[i] = (char*)malloc(4 * sizeof(char)); 
	}
	if (change.retourner == NULL){
		printf("erreur d'allocation !");
		exit(1);
	}
	strcpy(change.retourner[0], " return  ");
    strcpy(change.retourner[1], " by number  ");
    strcpy(change.retourner[2], " by name ");
    strcpy(change.retourner[3], "go back");
    
    change.parcourir = (char**)malloc(4 * sizeof(char*));
    for (int i=0; i<4; i++){
		change.parcourir[i] = (char*)malloc(4 * sizeof(char)); 
	}
	if (change.parcourir == NULL){
		printf("erreur d'allocation ! '");
		exit(1);
	}
	strcpy(change.parcourir[0], " browse  ");
    strcpy(change.parcourir[1], " by number  ");
    strcpy(change.parcourir[2], " by name ");
    strcpy(change.parcourir[3], "go back");
    
    change.option = (char**)malloc(4 * sizeof(char*));
    for (int i=0; i<4; i++){
		change.option[i] = (char*)malloc(4 * sizeof(char)); 
	}
	if (change.option == NULL){
			printf("erreur d'allocation ! '");
			exit(1);
		}
	strcpy(change.option[0], " option  ");
    strcpy(change.option[1], " language ");
    strcpy(change.option[2], " theme ");
    strcpy(change.option[3], "go back");
    
    change.quitter = (char**)malloc(sizeof(char*));
	change.quitter[0] = (char*)malloc(50 * sizeof(char));
	if (change.quitter == NULL || change.quitter[0] == NULL) {
		printf("Erreur d'allocation pour change.quitter");
		exit(1);
	}
	strcpy(change.quitter[0], "leaving program");
    
    change.langueP = (char**)malloc(5 * sizeof(char*));
    for (int i=0; i<5; i++){
		change.langueP[i] = (char*)malloc(5 * sizeof(char)); 
	}
		if (change.langueP == NULL){
			printf("erreur d'allocation ! '");
			exit(1);
		}
	strcpy(change.langueP[0], " language ");
    strcpy(change.langueP[1], " french ");
    strcpy(change.langueP[2], " english ");
    strcpy(change.langueP[3], " malagasy ");
    strcpy(change.langueP[4], " go back ");

	change.others = (char**)malloc(5 * sizeof(char*));
    for (int i=0; i<5; i++){
		change.others[i] = (char*)malloc(5 * sizeof(char)); 
	}
	if (change.others == NULL){
		printf("erreur d'allocation ! '");
		exit(1);
	}
	strcpy(change.others[0], " number ");
    strcpy(change.others[1], " name ");
    strcpy(change.others[2], " Yes ");
    strcpy(change.others[3], " No ");
	strcpy(change.others[4], " personal ");    
    return change;
}
modify_langue modify_francais ( modify_langue change){
	change.menu = (char**)malloc(6 * sizeof(char*));
	for (int i=0; i<6; i++){
		change.menu[i] = (char*)malloc(6 * sizeof(char)); 
	}
		if (change.menu == NULL){
			printf("erreur d'allocation ! '");
			exit(1);
	}
	strcpy(change.menu[0], " MENU PRINCIPALE ");
    strcpy(change.menu[1], "checker");
    strcpy(change.menu[2], "retourner");
    strcpy(change.menu[3], "parcourir");
    strcpy(change.menu[4], "option");
    strcpy(change.menu[5], "quitter");
    
    change.checker = (char**)malloc(4 * sizeof(char*));
    for (int i=0; i<4; i++){
		change.checker[i] = (char*)malloc(4 * sizeof(char)); 
	}
	if (change.checker == NULL){
		printf("erreur d'allocation ! '");
		exit(1);
	}
	strcpy(change.checker[0], " checker ");
    strcpy(change.checker[1], " par numero ");			
    strcpy(change.checker[2], "par nom");
    strcpy(change.checker[3], "retour");

	change.retourner = (char**)malloc(4 * sizeof(char*));
    for (int i=0; i<4; i++){
		change.retourner[i] = (char*)malloc(4 * sizeof(char)); 
	}
		if (change.retourner == NULL){
			printf("erreur d'allocation ! '");
			exit(1);
		}
	strcpy(change.retourner[0], " retourner ");
    strcpy(change.retourner[1], " par numero ");
    strcpy(change.retourner[2], "par nom");
    strcpy(change.retourner[3], "retour");
    
    change.parcourir = (char**)malloc(4 * sizeof(char*));
    for (int i=0; i<4; i++){
		change.parcourir[i] = (char*)malloc(4 * sizeof(char)); 
	}
		if (change.parcourir == NULL){
			printf("erreur d'allocation ! '");
			exit(1);
		}
	strcpy(change.parcourir[0], " parcourir  ");
    strcpy(change.parcourir[1], "  par numero ");
    strcpy(change.parcourir[2], " par nom ");
    strcpy(change.parcourir[3], "retour");
    
    change.option = (char**)malloc(4 * sizeof(char*));
    for (int i=0; i<4; i++){
		change.option[i] = (char*)malloc(4 * sizeof(char)); 
	}
	if (change.option == NULL){
			printf("erreur d'allocation ! '");
			exit(1);
		}
	strcpy(change.option[0], " option  ");
    strcpy(change.option[1], " langue  ");
    strcpy(change.option[2], " thème ");
    
    
    change.quitter = (char**)malloc(sizeof(char*));
	change.quitter[0] = (char*)malloc(50 * sizeof(char));
	if (change.quitter == NULL || change.quitter[0] == NULL) {
		printf("Erreur d'allocation pour change.quitter");
		exit(1);
	}
	strcpy(change.quitter[0], "quitter le programme");
	
    
    change.langueP = (char**)malloc(5 * sizeof(char*));
    for (int i=0; i<5; i++)
		change.langueP[i] = (char*)malloc(5 * sizeof(char)); 
		if (change.langueP == NULL){
			printf("erreur d'allocation ! '");
			exit(1);
		}
    strcpy(change.langueP[0], " langue ");
    strcpy(change.langueP[1], " français ");
    strcpy(change.langueP[2], " anglais ");
    strcpy(change.langueP[3], " malagasy ");
    strcpy(change.langueP[4], " retour ");

	change.others = (char**)malloc(5 * sizeof(char*));
    for (int i=0; i<5; i++){
		change.others[i] = (char*)malloc(5 * sizeof(char)); 
	}
	if (change.others == NULL){
		printf("erreur d'allocation ! '");
		exit(1);
	}
	strcpy(change.others[0], " numero ");
    strcpy(change.others[1], " nom ");
    strcpy(change.others[2], " Oui ");
    strcpy(change.others[3], " Non ");
	strcpy(change.others[4], " personel ");

    return change;
}

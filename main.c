
#include "initsys.h"

#include "Isd4004Spi.h"

void Init_Device(void);

void MenuScreen();


void main(void)
{
	S16 x=0, y=0,  ButtonNum;
	Init_Device();
	initSYS();

	MenuScreen();

	while(1) {
		if(!T_IRQ) {
			delay_ms(10);
			x = ReadTouchX();
			y = ReadTouchY();
			ButtonNum= ButtonTouch(x, y);
			if(ButtonNum==1){ 
				LCD_print2C(20,100,"Record1 ",3,WHITE,BLACK);				
				Record(0);
				PlayI(0);
			}
			else if(ButtonNum==2){ 
				LCD_print2C(20,100,"Record2 ",3,WHITE,BLACK);	
				Record(100);
				PlayI(100);
			}
			else if(ButtonNum==3){
				LCD_print2C(20,100,"Record3 ",3,WHITE,BLACK);	
				Record(200);
				PlayI(200);			
			}
			else if(ButtonNum==4) {
				LCD_print2C(20,100,"Record4 ",3,WHITE,BLACK);	
				Record(300);
				PlayI(300);
			}
		}	
	}
}

void MenuScreen() {
	LCD_fillScreen(BLACK);
	LCD_print2C(20,30,"Test Voicer",3,WHITE,BLACK);
	LCD_clearButton();	
	LCD_drawButton(1,10,  150,60,60, 10, RED,WHITE,"Rec1",2);
	LCD_drawButton(2,80, 150,60,60, 10, BLUE,YELLOW,"Rec2",2);
	LCD_drawButton(3,150, 150,60,60, 10, GREEN,BLACK,"Rec3",2);
	LCD_drawButton(4,220, 150,60,60, 10, YELLOW,BLACK,"Rec4",2);
	LCD_setText2Color(WHITE,BLACK);
}





#include <reg51.h>

sbit R0=P1^0;
sbit R1=P1^1;
sbit R2=P1^2;
sbit R3=P1^3;
sbit C0=P1^4;
sbit C1=P1^5;
sbit C2=P1^6;
sbit C3=P1^7;

void keypad_init()
{
	P1=0xf0;
}
char Read_switch()
{ 
	   int i;
	   R0=0; R1=1; R2=1; R3=1;
	   if(C0==0){for(i=0;i<30000;i++); while(C0==0); return '7';}
     if(C1==0){for(i=0;i<30000;i++); while(C1==0); return '8';}
     if(C2==0){for(i=0;i<30000;i++); while(C2==0); return '9';}
     if(C3==0){for(i=0;i<30000;i++); while(C3==0); return '/';}

     R0=1; R1=0; R2=1; R3=1;
	   if(C0==0){for(i=0;i<30000;i++); while(C0==0); return '4';}
     if(C1==0){for(i=0;i<30000;i++); while(C1==0); return '5';}
     if(C2==0){for(i=0;i<30000;i++); while(C2==0); return '6';}
     if(C3==0){for(i=0;i<30000;i++); while(C3==0); return '*';}

     R0=1; R1=1; R2=0; R3=1;
	   if(C0==0){for(i=0;i<30000;i++); while(C0==0); return '1';}
     if(C1==0){for(i=0;i<30000;i++); while(C1==0); return '2';}
     if(C2==0){for(i=0;i<30000;i++); while(C2==0); return '3';}
     if(C3==0){for(i=0;i<30000;i++); while(C3==0); return '-';}

     R0=1; R1=1; R2=1; R3=0;
	   if(C0==0){for(i=0;i<30000;i++); while(C0==0); return 'N';}
     if(C1==0){for(i=0;i<30000;i++); while(C1==0); return '0';}
     if(C2==0){for(i=0;i<30000;i++); while(C2==0); return '=';}
     if(C3==0){for(i=0;i<30000;i++); while(C3==0); return '+';}

     return 'n';
}
char getkey()
{
	char key='n',i=0;
	while(key=='n')
	{
		key=Read_switch();
	}
	return key;
}


int main()
{
	char a[5];
	lcd_init();
	keypad_init();
while(1)	
{
   a[0]=getkey();
			 lcd_data(a[0]);
}
}
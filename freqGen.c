#include <reg51.h>
/******************************keypad 4x4**************************/
//ports used for the keypad
sbit R1=P1^0;
sbit R2=P1^1;
sbit R3=P1^2;
sbit R4=P1^3;
sbit C1=P1^4;
sbit C2=P1^5;
sbit C3=P1^6;
sbit C4=P1^7;
sbit mybit=P2^4;

void keypad_init()
{
	P1=0xFF; //set the port to be able to use it as an input

}

	void Delay(int a)
{
	//delay of 1ms , a is the number of seconds
    int j;
    int i;
    for(i=0;i<a;i++)
    {
        for(j=0;j<100;j++)
        {
        }
    }
}


char Read_Keypad()
{
 C1=1;C2=1;C3=1;C4=1;R1=0;R2=1;R3=1;R4=1;
 if(C1==0){Delay(100);while(C1==0);return '1';}
 if(C2==0){Delay(100);while(C2==0);return '2';}
 if(C3==0){Delay(100);while(C3==0);return '3';}
 //if(C4==0){Delay(100);while(C4==0);return '/';}
 R1=1;R2=0;R3=1;R4=1;
 if(C1==0){Delay(100);while(C1==0);return '4';}
 if(C2==0){Delay(100);while(C2==0);return '5';}
 if(C3==0){Delay(100);while(C3==0);return '6';}
 //if(C4==0){Delay(100);while(C4==0);return 'X';}
 R1=1;R2=1;R3=0;R4=1;
 if(C1==0){Delay(100);while(C1==0);return '7';}
 if(C2==0){Delay(100);while(C2==0);return '8';}
 if(C3==0){Delay(100);while(C3==0);return '9';}
 //if(C4==0){Delay(100);while(C4==0);return '-';}
 R1=1;R2=1;R3=1;R4=0;
 //if(C1==0){Delay(100);while(C1==0);return 'C';}
 if(C2==0){Delay(100);while(C2==0);return '0';}
 //if(C3==0){Delay(100);while(C3==0);return '=';}
 //if(C4==0){Delay(100);while(C4==0);return '+';}
 return 'x' ;
}
/******************************keypad 4x4**************************/


/*****************************7 segment****************************/

#define led P2	//port used for seven segment

//selectors used to display numbers on diffrent digits
sbit sw1=P0^0;
sbit sw2=P0^2;
sbit sw3=P0^4;
sbit sw4=P0^6;

sbit INT0_Pin = P3^2; // Define INT0 pin as P3.2 (to set the frequncey and restart the program)
unsigned char ch[]={0x0C0,0x0F9,0x0A4,0x0B0,0x099,0x092,0x082,0x0F8,0x080,0x090};//list of numbers (active low) from 0 to 9



//functions :
void sdelay(unsigned int ms_Count) 
{
    unsigned int i, j;
    for (i = 0; i < ms_Count; i++) 
    {
        for (j = 0; j < 100; j++);
    }
}


void display (int n)
{
	//to display a number on the seven segment-quad
	int number = n;
	int temp;
	
	
	temp=number/1000;
	number=number%1000;
	led=ch[temp];
	sw1=0;
	sdelay(1);
	sw1=1;
	
	
	temp = number / 100;
	number = number % 100;
	led=ch[temp];
	
	sw2=0;
	sdelay(1);
	sw2=1;
	
	temp = number / 10;
	led=ch[temp];
	sw3=0;
	sdelay(1);
	sw3=1;
	
	temp = number % 10;
	led=ch[temp];
	sw4=0;
	sdelay(1);
	sw4=1;
	
}

/*****************************7 segment****************************/

void main()
{
	int h=0;	
	int test;
	int flag=1;
	keypad_init();
while(1)
{
	h=0;
	flag=1;
	while(flag)
	{
		test=Read_Keypad()-48;
		while(test==72 && flag==1)
		{
			display(h);
			test=Read_Keypad()-48;
			if(INT0_Pin == 0)
			{
				sdelay(300);
				flag=0;
			}
		}
		if(h<1000 && test != 72)
			h=h*10+test;
	}
		while(1)
	{
		  display(h);
			if(INT0_Pin == 0)
			{
				sdelay(300);
				break;
			}
	}
	
}
	
}


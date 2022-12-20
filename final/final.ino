#include <avr/io.h>
#include <util/delay.h>


void init(){
  
  Adc_Init();
  LCD_Init();
  showtemp();
  



}

int main(){

 init();
 DDRD=0b11111111;
 DDRB=0b11100111;
 float incs=40;
 float temp_val;
 
  char *dataa[0];
 
  while(1)
  {
  temp_val = showtemp();
  
  _delay_ms(300);
  
  if((temp_val/20)>incs){
     
  PORTB |=(1<<2);
  }
  else{
     
  PORTB &=~(1<<2);
  }
  
if(Adc_ReadChannel(0)>600){
  _delay_ms(50);
  if(PORTB&(1<<3)!=1){
    
    LCD_Clear();
    incs++;
  }
    LCD_String_xy(0,0,"40 C changed to ");
    itoa(incs,*dataa,10);
    LCD_String_xy(1,0,*dataa);
    LCD_String_xy(1,6,"C");
   
    
    _delay_ms(3000);
    LCD_Clear();
    


  
  }

  
if(Adc_ReadChannel(1)>600){
  _delay_ms(50);
  if(PORTB&(1<<3)!=1){
    
    LCD_Clear();
    incs--;
  }
    LCD_String_xy(0,0,"40 C changed to ");
    itoa(incs,*dataa,10);
    LCD_String_xy(1,0,*dataa);
    LCD_String_xy(1,6,"C");
   
    
    _delay_ms(3000);
    LCD_Clear();
    


  
  }
  
  if(Adc_ReadChannel(2)>600){
  _delay_ms(50);
  if(PORTB&(1<<3)!=1){
    
    LCD_Clear();
    
    PORTD &=~(1<<0);
    PORTD &=~(1<<1);
    _delay_ms(500);
  }
    LCD_String_xy(0,0,"motor rotate right");
    
    
    
    _delay_ms(800);
    

    
    PORTD=0b11110101;

   
    
    _delay_ms(300);
    LCD_Clear();
    


  
  }

  if(Adc_ReadChannel(3)>600){
  _delay_ms(50);
  if(PORTB&(1<<3)!=1){
    
  
    LCD_Clear();
    
    PORTD &=~(1<<0);
    PORTD &=~(1<<1);
    _delay_ms(500);
  }
    LCD_String_xy(0,0,"motor rotate left");
    
    
    
    _delay_ms(800);
    

    
    PORTD=0b11110110;

   
    
    _delay_ms(300);
    LCD_Clear();
    


  
  }
  
}

}


#include <avr/io.h>
#include <util/delay.h>

float showtemp(){
  Adc_Init();

  float temp_val;
  char *data[0];
  
  DDRC=0b00000000;
  PORTC=0b00000000;
  temp_val=Adc_ReadChannel(5);
  itoa(temp_val/20,*data,10);
  _delay_ms(300);
  LCD_String_xy(0,0,"current temp is ");
  LCD_String_xy(1,0,*data);
  LCD_String_xy(1,6,"C");
  _delay_ms(300);
  return temp_val;
}
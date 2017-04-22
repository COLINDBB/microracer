#include <avr/io.h>
#include <avr/interrupt.h>


#define BIT(a) (1 << (a))  // this creates a byte with all bits zero except a'th bit . eg (BIT(2)) is 0000 0100

char set_pin_io(int pin, int set){
 
  // set=1 is output. set=0 is input. 
  // be careful with pins o and 1. if these are changed return 'w' for warning
  // if successful, return 's' 
  // if bad pin input (outside 0-13) , return 'f' 
  
  if((pin>1)&&(pin<8)){
    //port D
    if(set == 1){
      DDRD |= BIT(pin)  ;  
    }
    if(set == 0){
      //turn off
      DDRD &= ~BIT(pin); 
    } 
    else return 's';
  }

  if((pin>=8)&&(pin<=13)){
    //PORTB
    if(set == 1){
      DDRB |= BIT(pin-8);
    }
    if(set == 0){
      DDRB &= ~BIT(pin-8);
    }
    return 's';
  }
  
  if((pin>=14)&&(pin<=21)){
    //PORTB
    if(set == 1){
      DDRB |= BIT(pin-14);
    }
    if(set == 0){
      DDRB &= ~BIT(pin-14);
    }
    return 's';
  }
  if((pin==0) | (pin==1)) return 'w';
  return 'f';
}

char digital_write(int pin, int state){
 
  // set=1 is high. set=0 is low. 
  // 0-7 is D
  // 8-13 is B
  // 14-21 is C (20,21 are unavailable);
  
  
  if((pin == 0) || (pin == 1)) return 'w';
  
  if((pin>1)&&(pin<8)){ // PORT D!
    if(state == 1){ //  set to 1;
      PORTD |= BIT(pin);
      return 's';
    }
    if(state == 0){ // set to 0
      PORTD &= ~BIT(pin);
      return 's'; 
    }
  }

  if((pin>=8)&&(pin<14)){// PORT B!
    if(state == 1){ //set to 1
      PORTB |= BIT(pin);
      return 's';
    }
    if(state == 0){ // set to 0
      PORTB &= ~BIT(pin);
      return 's'; 
    }
  }
  return 'f';
}

int digital_read(int pin){
  // example
  // PINB: 0000 0010 
  // to find out if bit 1 is on, & it with BIT(1) and see if its equal to BIT(1);
  // here the pin corresponding to bit 1 is HIGH. 
  //
  //      check bit1.             check bit 4
  //      0000 0010               0000 0010 
  //    & 0000 0010             & 0001 0000
  //    = 0000 0010             = 0000 0000 
  
  if((pin>=0) && (pin<8)){ //PIND
    if(PIND&BIT(pin)==BIT(pin)) return 1;
    else return 0;
  }
  
  if((pin>=8) && (pin<14)){ //PINB
    if(PINB&BIT(pin)==BIT(pin)) return 1;
    else return 0;
  }
}  

void delay_ms(int ms){}

void delay_us(int us){}

void pwm_p5_p6(int dc5, int dc6, int period){
	
	// Timer0
	
	
}

void pwm_p9_p10(int dc9, int dc10, int period){
	
	// Timer1
}

void pwm_p11_p3(int dc11, int dc3, int period){
	
	// Timer 2
	
}

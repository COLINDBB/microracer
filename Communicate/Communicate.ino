int max_buffer = 64;
char buff_in[64];
char buff_out[64];
int *joystick_int = (int*)buff_in;
char *joystick_char =buff_in;
bool proceed = false;
bool changed = true;

//LED 
int L1 = 12;
int L2 = 11;
int L3 = 10;
int L4 = 9;


char get_char();
void start_comm();
void all_off();
void on_off(int);
void on(int);
void off(int);

void setup() {
  
  Serial.begin(9600);
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(L3,OUTPUT);
  pinMode(L4,OUTPUT);
  int throttle;


  start_comm(); //starts communication with computer. If successful, proceed is set to True; 

  //if(!proceed) alarm());
  
  while(proceed){
    throttle = (int) get_char();
    if(throttle == 0){
      on_off(L1); 
    }
    if(throttle == 127);
       
  }   
}

void loop() {}

char get_char(){ 
  
    if(Serial.available()){
       Serial.readBytes(buff_in,1);
       return buff_in[0];
    }else return 'f';
}




void on_off(int pin){
  
  digitalWrite(pin,HIGH);
  delay(500);
  digitalWrite(pin,LOW);
}




void all_on_off(){
  
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,HIGH);
  digitalWrite(L4,HIGH);
  delay(500);
  digitalWrite(L1,LOW);
  digitalWrite(L2,LOW);
  digitalWrite(L3,LOW);
  digitalWrite(L4,LOW);
}



void start_comm(){
  
  while(!Serial.available()){}
  Serial.readBytes(buff_in,1);
  if(buff_in[0] == 'y'){
    Serial.println('y');
    proceed = true;
  }
}



void on(int pin){
  
  digitalWrite(pin,HIGH);
}



void off(int pin){
  
  digitalWrite(pin,LOW);
}



void all_off(){
  
  digitalWrite(L1,LOW);
  digitalWrite(L2,LOW);
  digitalWrite(L3,LOW);
  digitalWrite(L4,LOW);
}
  



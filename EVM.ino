
#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2, 3, 4,5}; 
byte colPins[COLS] = {6,7,8,9}; 
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
byte a=0;
byte b=0;
byte c=0;
//byte d=0;

int sw=12;
int buz=10;



void setup(){
  Serial.begin(9600);
  pinMode(sw,INPUT);
  digitalWrite(sw,HIGH);
  pinMode(buz,OUTPUT);
  digitalWrite(buz,LOW);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  

  if (customKey=='*')
  {
   Serial.print("CASTE YOUR VOTE");
Serial.print("\nBJP  AAP  CONGRESS");

Serial.print("\nA     B       C");
//Serial.print("\nPRESS 'D' FOR RESULTS"); 
  }
  else if (customKey=='A')
  {
    a=a+1;
    Serial.println("\nA");
    Serial.println("\nTHANKS FOR VOTING TO B.J.P." );    
    digitalWrite(buz,HIGH);
     delay(50);
    digitalWrite(buz,LOW);
    while(digitalRead(sw)==HIGH);
    

  }
  else if(customKey=='B')
  {
    b=b+1;
    Serial.println("\nB");
    Serial.println("\nTHANKS FOR VOTING TO AAP");
    
    digitalWrite(buz,HIGH);
    delay(50);
    digitalWrite(buz,LOW);
    while(digitalRead(sw)==HIGH);
   
  }
  else if(customKey=='C')
  {
     c=c+1;
    Serial.println("\nC");
    Serial.println("\nTHANKS FOR VOTING TO CONGRESS");
   
    digitalWrite(buz,HIGH);
     delay(50);
    digitalWrite(buz,LOW);
    while(digitalRead(sw)==HIGH);
    
  }

  
  
  
}


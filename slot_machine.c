const int tiltPin = 2;  // the number of the tiltPin
const int seven_1_A = 3;
const int seven_1_B = 4;
const int seven_1_C = 5;
const int seven_1_D = 6;
const int seven_1_E = 7;
const int seven_1_F = 8;
const int seven_1_G = 9;

const int seven_2_A = 11;
const int seven_2_B = 12;
const int seven_2_C = 13;
const int seven_2_D = 14;
const int seven_2_E = 15;
const int seven_2_F = 17;
const int seven_2_G = 18;

const int seven_3_A = 31;
const int seven_3_B = 32;
const int seven_3_C = 33;
const int seven_3_D = 34;
const int seven_3_E = 35;
const int seven_3_F = 36;
const int seven_3_G = 37;

const int green_led = 40;
const int red_led = 19;

int enterFlag = 0;
int num1;
int num2;
int num3;
int loops1;
int loops2;
int loops3;
int a_pin;





byte seven_segment_digits[10][7] = { { 1,1,1,1,1,1,0 }, // display '0'
                                     { 0,1,1,0,0,0,0 }, // display '1'
                                     { 1,1,0,1,1,0,1 }, // display '2'
                                     { 1,1,1,1,0,0,1 }, // display '3'
                                     { 0,1,1,0,0,1,1 }, // display '4'
                                     { 1,0,1,1,0,1,1 }, // display '5'
                                     { 1,0,1,1,1,1,1 }, // display '6'
                                     { 1,1,1,0,0,0,0 }, // display '7'
                                     { 1,1,1,1,1,1,1 }, // display '8'
                                     { 1,1,1,0,0,1,1 }  // display '9'
                                   };

void display_num(int num, int a_pin){

  for (int segCount = 0; segCount < 7; ++segCount) {
      digitalWrite(a_pin, seven_segment_digits[num][segCount]);
      ++a_pin;
      if(a_pin == 16){
        ++a_pin;
      }
    }
}

void all_off()
{
  digitalWrite(seven_1_A, LOW);
  digitalWrite(seven_1_B, LOW);
  digitalWrite(seven_1_C, LOW);
  digitalWrite(seven_1_D, LOW);
  digitalWrite(seven_1_E, LOW);
  digitalWrite(seven_1_F, LOW);
  digitalWrite(seven_1_G, LOW);

  
  digitalWrite(seven_2_A, LOW);
  digitalWrite(seven_2_B, LOW);
  digitalWrite(seven_2_C, LOW);
  digitalWrite(seven_2_D, LOW);
  digitalWrite(seven_2_E, LOW);
  digitalWrite(seven_2_F, LOW);
  digitalWrite(seven_2_G, LOW);

  digitalWrite(seven_3_A, LOW);
  digitalWrite(seven_3_B, LOW);
  digitalWrite(seven_3_C, LOW);
  digitalWrite(seven_3_D, LOW);
  digitalWrite(seven_3_E, LOW);
  digitalWrite(seven_3_F, LOW);
  digitalWrite(seven_3_G, LOW);
}



//int buttonState = 0;         // variable for reading the pushbutton status
int tiltState = 0;      // variable for reading the tiltPin status

void setup() {
  Serial.begin(9600);      // open the serial port at 9600 bps:
  // initialize the LED pin as an output:
  pinMode(seven_1_A, OUTPUT);
  pinMode(seven_1_B, OUTPUT);
  pinMode(seven_1_C, OUTPUT);
  pinMode(seven_1_D, OUTPUT);
  pinMode(seven_1_E, OUTPUT);
  pinMode(seven_1_F, OUTPUT);
  pinMode(seven_1_G, OUTPUT);
 
  pinMode(seven_2_A, OUTPUT);
  pinMode(seven_2_B, OUTPUT);
  pinMode(seven_2_C, OUTPUT);
  pinMode(seven_2_D, OUTPUT);
  pinMode(seven_2_E, OUTPUT);
  pinMode(seven_2_F, OUTPUT);
  pinMode(seven_2_G, OUTPUT);

  pinMode(seven_3_A, OUTPUT);
  pinMode(seven_3_B, OUTPUT);
  pinMode(seven_3_C, OUTPUT);
  pinMode(seven_3_D, OUTPUT);
  pinMode(seven_3_E, OUTPUT);
  pinMode(seven_3_F, OUTPUT);
  pinMode(seven_3_G, OUTPUT);
  
  pinMode(green_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  // initialize the pushbutton pin as an input:
  //pinMode(buttonPin, INPUT_PULLUP);
  // initialize the tiltPin as an input:
  pinMode(tiltPin, INPUT_PULLUP);
}

                            

void loop() {
    tiltState = analogRead(tiltPin);
    // check if the pushbutton is pressed.
    // if it is, the button State is HIGH:
    if (tiltState > 4000) 
    {
     
      enterFlag = 0;
    }
    if (tiltState < 200 && enterFlag == 0)
    {
      // turn LED on:
      int bound = 3;
      num1 = (int)random(1, bound + 1);
      num2 = (int)random(1, bound + 1);
      num3 = (int)random(1, bound + 1);
      display_num(num1, 3);
      display_num(num2, 11);
      display_num(num3, 31);
     
      
      
      if (num1 == num2 && num1 == num3)
      {
        digitalWrite(red_led, LOW);
        digitalWrite(green_led, HIGH);
        int i;
        for (i = 0; i < 3; i++)
        {
          display_num(num1, 3);
          display_num(num2, 11);
          display_num(num3, 31);
          delay(500);
          all_off();
          delay(500);
        }
        display_num(num1, 3);
        display_num(num2, 11);
        display_num(num3, 31);
        delay(500);
      }
      else 
      {
        digitalWrite(green_led, LOW);
        digitalWrite(red_led, HIGH);
      }
      enterFlag = 1;
      delay(2000);
    }
    else
    {
      all_off();
      digitalWrite(red_led, LOW);
      digitalWrite(green_led, LOW);
    }
}
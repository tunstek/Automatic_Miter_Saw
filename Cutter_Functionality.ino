/*
  Cutter (Basic Functionality)

  The basic functionality required for an automatic briquette cutting system.
  For use with L293D chip.

  Includes:
  - Reversing motor (with delays)
  - PWM on motor speed
  - Potometer control


  modified 13TH JUNE 2016
  by Keith Tunstead
 */


/*        
 *  D9 - Motor 1 enable
 *  D11 - Motor 2 enable          
 *  D10 - Motor 3 enable (24v)
 *  
 *  D12  - Motor 1 input A (No need for B as no dynamic reversing is necessary - we can simply reverse polarity on outputs)
 *  D8  - Motor 2 input A (Same as above)
 *  D7  - Motor 3 input A
 *  D6  - Motor 3 input B
 *  
 *  
 *  D2 - Relay 1 output
 *  D3 - Relay 2 output
 *  
 *  
 *  A0 - Potentiometer 1
 *  A1 - Potentiometer 2
 *  A2 - Potentiometer 3
 */
 

 #include <Motor.h>
 #define pot0 A0
 #define pot1 A1
 #define pot2 A2
 #define relay1 2
 #define relay2 3
 #define enableSwitch A3


  //Motor limeMotor(9, 12); //Motor1
  //Motor mixingMotor(11, 8); //Motor2
  Motor sawMotor(10, 7, 6); //Motor3

  int pot0Val = 0;
  int pot1Val = 0;
  int pot2Val = 0;

  int toggle1 = 1;

  int switchstate = 0;



void setup() {

/*
  //Timer Setup
  cli();//stop interrupts

  //set timer0 interrupt at 2kHz
    TCCR0A = 0;// set entire TCCR2A register to 0
    TCCR0B = 0;// same for TCCR2B
    TCNT0  = 0;//initialize counter value to 0
    // set compare match register for 2khz increments
    OCR0A = 124;// = (16*10^6) / (2000*64) - 1 (must be <256)
    // turn on CTC mode
    TCCR0A |= (1 << WGM01);
    // Set CS01 and CS00 bits for 64 prescaler
    TCCR0B |= (1 << CS01) | (1 << CS00);   
    // enable timer compare interrupt
    TIMSK0 |= (1 << OCIE0A);

  //set timer1 interrupt at 1Hz
    TCCR1A = 0;// set entire TCCR1A register to 0
    TCCR1B = 0;// same for TCCR1B
    TCNT1  = 0;//initialize counter value to 0
    // set compare match register for 1hz increments
    OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS12 and CS10 bits for 1024 prescaler
    TCCR1B |= (1 << CS12) | (1 << CS10);  
    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);

  //set timer2 interrupt at 8kHz
    TCCR2A = 0;// set entire TCCR2A register to 0
    TCCR2B = 0;// same for TCCR2B
    TCNT2  = 0;//initialize counter value to 0
    // set compare match register for 8khz increments
    OCR2A = 249;// = (16*10^6) / (8000*8) - 1 (must be <256)
    // turn on CTC mode
    TCCR2A |= (1 << WGM21);
    // Set CS21 bit for 8 prescaler
    TCCR2B |= (1 << CS21);   
    // enable timer compare interrupt
    TIMSK2 |= (1 << OCIE2A);

  sei();//allow interrupts
*/



  // setup the serial monitor
    Serial.begin(9600);
    Serial.println("Begin");
  
  //Setup pins  
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(enableSwitch, INPUT);

    // *** Debug ***
    pinMode(13, OUTPUT);  

}


// the loop function runs over and over again forever
void loop() {
  
/*
  switchstate = digitalRead(enableSwitch);
  if(switchstate == HIGH) {
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);
  }
*/

  sawMotor.rotateClockwise(255);
  digitalWrite(13,HIGH);

  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(13, HIGH);
  delay(2000);

  sawMotor.rotateCounterClockwise(255);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(13,LOW);
  delay(2000);








/*

  // *** Print Pot Values ***
    pot0Val = analogRead(pot0);
    Serial.print("PotVal0 = ");
    Serial.print(pot0Val);
    Serial.print("\n");
    delay(500);
    pot1Val = analogRead(pot1);
    Serial.print("PotVal1 = ");
    Serial.print(pot1Val);
    Serial.print("\n");
    delay(500);
    pot2Val = analogRead(pot2);
    Serial.print("PotVal2 = ");
    Serial.print(pot2Val);
    Serial.print("\n");
    delay(500);
    */

} //End of loop

/*
ISR(TIMER1_COMPA_vect){//timer1 interrupt 1Hz toggles pin 13 (LED)
//generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)
  if (toggle1){
    digitalWrite(13,HIGH);
    toggle1 = 0;
  }
  else{
    digitalWrite(13,LOW);
    toggle1 = 1;
  }
}
*/

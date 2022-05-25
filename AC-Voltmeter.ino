#include <LiquidCrystal.h>                              // include Arduino LCD library
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);                   // LCD module connections (RS, E, D4, D5, D6, D7) 
void setup(void) {
  lcd.begin(20, 4);                                  
  lcd.setCursor(0, 0);
  lcd.print("*INPUT*     *OUTPUT*"); 
  lcd.setCursor(0, 3);
  lcd.print("**Welcome**"); 
  analogReference(INTERNAL);}                        // set ADC positive reference voltage to 1.1V (internal)
  uint16_t get_max() {
  uint16_t max_v = 0;
  for(uint8_t i = 0; i < 100; i++) {
  uint16_t r = analogRead(A3);  // read from analog channel 3 (A3)
  if(max_v < r) max_v = r;
  delayMicroseconds(200);}
  return max_v;}
  uint16_t get_max1() {
  uint16_t max1_v = 0;
  for(uint8_t j = 0; j < 100; j++) {
  uint16_t t = analogRead(A1);  // read from analog channel 3 (A3)
  if(max1_v < t) max1_v = t;
  delayMicroseconds(200);}
  return max1_v;}
void loop() {
       {char buf[10];                          // get amplitude (maximum - or peak value)
        uint32_t v = get_max();               // get actual voltage (ADC voltage reference = 1.1V)
        v = v * 1100/1023;                   // calculate the RMS value ( = peak/√2 )
        v /= sqrt(2); 
        sprintf(buf, " %03u ", v);
        lcd.setCursor(0,1);
        lcd.print(buf); 
        lcd.setCursor(0,2);
        lcd.print("VOLTS"); 
        delay(100);}
      {char buf1[10];
       uint32_t v = get_max1();           // get amplitude (maximum - or peak value)
       v = v * 1100/1023;                // get actual voltage (ADC voltage reference = 1.1V)
       v /= sqrt(2);                    // calculate the RMS value ( = peak/√2 )
       sprintf(buf1, " %03u ", v);
       lcd.setCursor(14, 1);
       lcd.print(buf1); 
       lcd.setCursor(14, 2);
       lcd.print("VOLTS"); 
       delay(100);}
       }

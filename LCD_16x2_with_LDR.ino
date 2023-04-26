#include <LiquidCrystal.h>

#define LDR_Pin A5
#define ValLen 4

float LDRValue = 0.0;
String LDR_String_Value;

LiquidCrystal Screen16x2(7, 8, 9, 10, 11 , 12);

void setup() {
    Screen16x2.begin(16, 2);
    Serial.begin(9600);
}

void loop() {

    Screen16x2.clear();

    Screen16x2.setCursor(0,0);
    Screen16x2.write("Testing...");
    
    LDRValue= analogRead(LDR_Pin)*0.004887585532746823069403714565;
    int PercLigth=float_map(LDRValue,5.0,0.0,0,100);  
    Screen16x2.setCursor(0,1);
    Screen16x2.write("Lux=");    
    Screen16x2.setCursor(4,1);
    LDR_String_Value=String(PercLigth);
    Screen16x2.write(LDR_String_Value.c_str());    
    Screen16x2.setCursor(7,1);
    Screen16x2.write("%");
    Serial.println(String(LDRValue));
    delay(1000);  

}


float float_map(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

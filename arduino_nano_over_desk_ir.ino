#include <FastLED.h>
#include <IRremote.h>
#include <stdio.h>
#include <string.h>


char string[100] = "";
const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

int function_number = 0;


#define LED_PIN       3
#define NUM_LEDS       24
int BRIGHTNESS =  90;

CRGB leds[NUM_LEDS];

int  white_fade_down (int BRIGHTNESS)  {
    
  int FastLED_fade_counter = 51;
  for (int outer_counter = 0; outer_counter < 50; outer_counter++){
    check_ir();
    if (function_number != 0){
              return 0;
            }
    
    for ( int i = 0; i < NUM_LEDS; i++){
              leds[i] = CRGB::White;  // Can be any colour.
              leds[i].maximizeBrightness(FastLED_fade_counter);  // 'FastLED_fade_counter' How low we want to fade down to 0 = maximum.
    }
  
    FastLED.show();
    FastLED_fade_counter -- ;  // Decrement
          
    check_ir();
    if (function_number != 1){
        return 0;
    }
    FastLED.delay(50);
  }
  
  for (int outer_counter = 0; outer_counter < 50; outer_counter++){
    check_ir();
    if (function_number != 0){
              return 0;
            }
    
        for ( int i = 0; i < NUM_LEDS; i++){
              leds[i] = CRGB::White;  // Can be any colour.
              leds[i].maximizeBrightness(FastLED_fade_counter);  // 'FastLED_fade_counter' How low we want to fade down to 0 = maximum.
            }
            
  
        FastLED.show();
        FastLED_fade_counter ++ ;  // Decrement
  
        if (FastLED_fade_counter == 45){
            for ( int i = 0; i < 10000; i++){
            check_ir();
            if (function_number != 0){
              return 0;
            }
            FastLED.delay(10);
            }
        }
        
        check_ir();
        if (function_number != 1){
            return 0;
        }      
        FastLED.delay(50);
        }
      
}


int rainbow (int rainbow_increment,int BRIGHTNESS){

    int rainbow_hue = 0;
    int saturation = 255;
    int brightness = BRIGHTNESS;
  
    for (int outer_counter = 0; outer_counter <= 255; outer_counter += rainbow_increment){
        
        for (int i = 0; i < NUM_LEDS; i++){
            leds[i] = CHSV(rainbow_hue, saturation, brightness);
            
            }
            rainbow_hue += rainbow_increment;
        FastLED.show();
        check_ir();
            if (function_number != 1){
              return 0;
            }
        FastLED.delay(80);
        

        
        
        //delay(500);
  }
      for (int outer_counter = 0; outer_counter <= 255; outer_counter += rainbow_increment){
        
        for (int i = 0; i < NUM_LEDS; i++){
            leds[i] = CHSV(rainbow_hue, saturation, brightness);
            
            
            }
            rainbow_hue -= rainbow_increment;
        FastLED.show();
        check_ir();
            if (function_number != 1){
              return 0;
            }
        FastLED.delay(80);

        
        
        
  }
  return 1;
}


int fire (int fire_number, int BRIGHTNESS){
    int hue = 0;
    int saturation = 255;
    int brightness = BRIGHTNESS;
    

    for (int outer_counter = 0; outer_counter <= 1000; outer_counter += 1){
        
    
        for (int i = 0; i < NUM_LEDS; i++){
            hue = random(0, 32);
            leds[i] = CHSV(hue, saturation, brightness);
            
            
            }
        FastLED.show();
        FastLED.delay(20);
        check_ir();
            if (function_number != 1){
              return 0;
            }
        

    
  
    }
}


int red (int fire_number, int BRIGHTNESS){
    int hue = 0;
    int saturation = 255;
    int brightness = BRIGHTNESS;
    int random_number; 

    for (int outer_counter = 0; outer_counter <= 1000; outer_counter += 1){
 
            for (int i = 0; i < NUM_LEDS; i++){
                hue = 0;
                leds[i] = CHSV(hue, saturation, brightness);
                
            
        }
        
        FastLED.show();
        check_ir();
            if (function_number != 1){
              return 0;
            }
        FastLED.delay(80);

    
  
    }
}

// wavy blue green and purple : 160, 96, 192

int spencer_wavy_function (int BRIGHTNESS,int color1, int color2, int color3){
    int hue = 0;
    int saturation = 255;
    int brightness = BRIGHTNESS;
    // yellow 64

    for (int outer_counter = 0; outer_counter <= 1000; outer_counter += 1){
      
    
            
            
            for (int i = 0; i < NUM_LEDS; i++){
                leds[i-1] = CHSV(64, saturation, brightness);
                leds[i] = CHSV(color1, saturation, brightness);
                leds[i+1] = CHSV(color2, saturation, brightness);
                leds[i+2] = CHSV(color3, saturation, brightness);
                leds[i+3] = CHSV(0, saturation, brightness);
                leds[i+4] = CHSV(32, saturation, brightness);
                leds[i+5] = CHSV(224, saturation, brightness);
                
                 FastLED.show();
        check_ir();
            if (function_number != 4){
              return 0;
            }
        FastLED.delay(50);
                
            
        }
         for (int i = NUM_LEDS; i > 0; i--){
                leds[i-1] = CHSV(64, saturation, brightness);
                leds[i] = CHSV(color1, saturation, brightness);
                leds[i+1] = CHSV(color2, saturation, brightness);
                leds[i+2] = CHSV(color3, saturation, brightness);
                leds[i+3] = CHSV(0, saturation, brightness);
                leds[i+4] = CHSV(32, saturation, brightness);
                leds[i+5] = CHSV(224, saturation, brightness);
                
                 FastLED.show();
        check_ir();
            if (function_number != 4){
              return 0;
            }
        FastLED.delay(50);
                
            
        }
        /*
        FastLED.show();
        check_ir();
            if (function_number != 4){
              return 0;
            }
        FastLED.delay(80);

*/
  

    }

}

int random_waves (int BRIGHTNESS){
    int hue = 0;
    int saturation = 255;
    int brightness = BRIGHTNESS;
    // yellow 64

    for (int outer_counter = 0; outer_counter <= 1000; outer_counter += 1){
            hue = random(0,255);
            
            for (int i = 0; i < NUM_LEDS; i++){
               
                leds[i] = CHSV(hue, saturation, brightness);
                
                 FastLED.show();
        check_ir();
            if (function_number != 5){
              return 0;
            }
        FastLED.delay(50);
                
            
        }
        hue = random(0,255);
    for (int i = NUM_LEDS; i > 0; i--){
      
               
                leds[i] = CHSV(hue, saturation, brightness);
                
                 FastLED.show();
        check_ir();
            if (function_number != 5){
              return 0;
            }
        FastLED.delay(50);
                
            
        }
    }
}
        




void check_ir(){
    //Serial.print("endering check_ir");
    unsigned long key_value = 0;
    long int the_results;
    if (irrecv.decode(&results)){
      //Serial.print("hit this \n" );
      the_results = results.value;
      Serial.print(the_results, HEX);
      Serial.print("\n");
      if (function_number == 0){
                function_number = 1;
            }
            else if (function_number == 1){
              function_number = 2;
            }
            else if (function_number == 2){
              function_number = 3;
            }
            else if (function_number == 3){
              function_number = 4;
            }
             else if (function_number == 4){
              function_number = 5;
            }
            else{
              function_number = 0;
            }
 
        key_value = results.value;
        irrecv.resume();
    }

}
  





void setup() {
  //digitalWrite(LED_BUILTIN, LOW); // turn off led??
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
  irrecv.enableIRIn(); 
  //irrecv.blink13(true);
}

void loop() {
    check_ir();

    if (function_number == 0){
    white_fade_down(BRIGHTNESS);
    }
    else if (function_number == 1){
    
    rainbow(1, BRIGHTNESS);
    }
    else if (function_number == 2){
    fire(1, BRIGHTNESS);
    }
    else if (function_number == 3){
    red(1, BRIGHTNESS);
    }
    else if (function_number == 4){
    spencer_wavy_function(BRIGHTNESS,160,96,192);
    }
    else if (function_number == 5){
    random_waves(BRIGHTNESS);
    }
    
  
 
  
/*
  for (int i = 0; i<= 14; i++) {
    leds[i] = CRGB (2, 1, 1);
    if ((i+1) <= 14){
      leds[i+1] = CRGB (10, 50, 10);
    }
    FastLED.show();
    delay(200);
  }

  for (int i = 14; i>= 0; i--) {
    leds[i] = CRGB (1, 2, 1);
    FastLED.show();
    delay(200);
  }  



//FaprintstLED.clear ();
*/

}

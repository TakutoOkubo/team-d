//for WS2812B
//sannkou
//http://cammy.co.jp/technical/2016/01/23/arduino-007/

#include "FastLED.h"
 
//LEDバッファーを必要個数分用意する
CRGB leds[1];
 
void setup() { 
  FastLED.addLeds<NEOPIXEL, 6>(leds, 1); 
  //　　　　　　　　　　　| 　 　|　  | 　 |
  //             　　　|     |   　|   +--LEDの数量 上記配列数と同じ
  //             　　　|     |   　+--宣言したCRGBバッファ配列
  //             　　　|     +--接続ポート番号 PWMを選択
  //             　　　+--使用するLEDDriver WS2811はこのままでもよい
}
void loop() { 
  leds[0] = CRGB::White; //1個目色の指定
  FastLED.show();       //表示
  delay(1000);
  leds[0] = CRGB::Black; //黒にする→消す
  FastLED.show();        
  delay(1000);
  leds[0] = CRGB::Green; //1個目色の指定
  FastLED.show();       //表示
  delay(1000);
  leds[0] = CRGB::Black; //黒にする→消す
  FastLED.show();
}

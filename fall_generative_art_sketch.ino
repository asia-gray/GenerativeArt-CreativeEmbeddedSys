#include <TFT_eSPI.h>  

TFT_eSPI tft = TFT_eSPI(); 
int16_t colors[12];


void setup() {
  tft.init();
  tft.setRotation(1);  
  tft.fillScreen(TFT_BLACK);  

}

void loop() {
    tft.fillScreen(TFT_BLUE);  
    delay(3000);   
    drawSadPumpkin();
    delay(3000);        
    tft.fillScreen(TFT_YELLOW);  
    delay(3000);      
    drawHappyPumpkin(); 
    delay(3000);      
    tft.fillScreen(TFT_WHITE);  
    rainbow();
    delay(3000);
    drawSurprisedPumpkin();   
    delay(3000);         
}

void rainbow(){
  for (uint8_t c = 0; c < 2; c++) {
    colors[c + 10] = tft.alphaBlend(128 + c * 127, TFT_RED,     TFT_MAGENTA);
    colors[c +  8] = tft.alphaBlend(128 + c * 127, TFT_MAGENTA, TFT_BLUE);
    colors[c +  6] = tft.alphaBlend(128 + c * 127, TFT_BLUE,    TFT_GREEN);
    colors[c +  4] = tft.alphaBlend(128 + c * 127, TFT_GREEN,   TFT_YELLOW);
    colors[c +  2] = tft.alphaBlend(128 + c * 127, TFT_YELLOW,  TFT_ORANGE);
    colors[c +  0] = tft.alphaBlend(128 + c * 127, TFT_ORANGE,  TFT_RED);
  }
  uint16_t rDelta = (tft.width() - 1) / 10;
  uint16_t x = tft.width() / 2;
  uint16_t y = tft.height() / 2;
  bool smooth = true;

  for (uint16_t i = 5; i > 0; i--) {
    for (uint16_t angle = 0; angle <= 330; angle += 30) {
      uint16_t radius = i * rDelta;
      uint16_t wheelColor = tft.alphaBlend((i * 255.0)/5.0, colors[angle / 30], TFT_WHITE);
      tft.drawArc(x, y, radius, radius - rDelta, angle, angle + 30, wheelColor, TFT_BLACK, smooth);
    }
    smooth = false;  // Only outer ring is smooth
  }

  //while (1) delay(100);
}


void drawPumpkinBody() {
  tft.fillEllipse(110, 80, 52, 43, TFT_ORANGE); 
  tft.drawEllipse(120, 79, 51, 42, TFT_DARKGREY); 
  tft.drawEllipse(100, 80, 31, 40, TFT_DARKGREY); 
  tft.drawEllipse(140, 79, 29, 40, TFT_DARKGREY); 
  tft.fillRect(111, 40, 22, 11, TFT_GREEN);  
}

void drawHappyPumpkin() {
  drawPumpkinBody();

  tft.fillTriangle(105, 60, 115, 63, 111, 71, TFT_BLACK); 
  tft.fillTriangle(125, 60, 138, 60, 132, 72, TFT_BLACK); 

  tft.drawLine(105, 90, 115, 95, TFT_BLACK); 
  tft.drawLine(116, 95, 128, 95, TFT_BLACK); 
  tft.drawLine(125, 95, 135, 90, TFT_BLACK); 
}

void drawSurprisedPumpkin() {
  drawPumpkinBody();

  tft.fillCircle(111, 65, 7, TFT_BLACK); 
  tft.fillCircle(130, 65, 7, TFT_BLACK);  

  tft.fillCircle(120, 90, 10, TFT_BLACK); 
}
void drawSadPumpkin() {
  tft.fillEllipse(120, 80, 52, 41, TFT_ORANGE); 

  tft.drawEllipse(120, 83, 50, 40, TFT_DARKGREY); 
  tft.drawEllipse(100, 83, 30, 40, TFT_DARKGREY); 

  tft.fillRect(110, 42, 20, 11, TFT_GREEN);  

  tft.fillTriangle(107, 60, 115, 68, 110, 70, TFT_BLACK); 
  tft.fillTriangle(125, 60, 135, 62, 130, 70, TFT_BLACK); 

  tft.fillRect(110, 90, 23, 10, TFT_BLACK);  
  tft.fillRect(115, 98, 12, 5, TFT_ORANGE);  
}

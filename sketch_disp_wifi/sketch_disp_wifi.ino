#include <Adafruit_SSD1306.h>
#include <gfxfont.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>

#include <Wire.h>
#include <WiFi.h>
#include <WiFiClient.h>

const char* ssid = "dingo-zte";
const char* password = "dKj2cL0A";

Adafruit_SSD1306 display(-1);

void setup(void)
{  
    Serial.begin(115200);
    Serial.println("Start...");
    Wire.begin();

    // Connect to WiFi network
    WiFi.begin(ssid, password);
    Serial.println("");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("");

    // Сканируем I2C шину
    for(int i = 1; i < 127; i++ )  {
       Wire.beginTransmission(i);
       if(  Wire.endTransmission() == 0 ){
           Serial.printf("Found I2C device 0x%x\n",i);
       }
    }

    // Инициализация дисплея  
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("ESP32");
    display.setTextSize(1);
    display.setCursor(0,22);
    display.println("AndrDI 2018");
    display.display();     
    delay(2000);

    //Вывод данных о подключении
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0,0);
    display.println("Connected to ");
    display.println(ssid);
    display.println("IP address: ");
    display.println(WiFi.localIP());
    display.display();
   
}

void loop()
{
}

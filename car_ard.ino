#define ENA 16      // Enable/speed motors Right        GPIO14(D5)
#define ENB 14      // Enable/speed motors Left         GPIO12(D6)
#define IN_1 5      // L298N in1 motors Rightx          GPIO15(D8)
#define IN_2 4      // L298N in2 motors Right           GPIO13(D7)
#define IN_3 0      // L298N in3 motors Left            GPIO2(D4)
#define IN_4 2      // L298N in4 motors Left            GPIO0(D3)
int speedCar = 800; // 400 - 1023.
int speed_Coeff = 3;
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
AsyncWebServer server(80);
const char *ssid = "Dhruvesh";
const char *password = "1234567890";

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <div class="-controls">
        
        <button id="b1" onclick="up()"  >UP</button>
        <button id="b2" onclikc="down()"  >BACK</button>
        <button id="b3" onclick="left()" >LEFT</button>
        <button id="b4" onclick="r()"  >RIGHT</button>
        <button id="b5" onclick="x()"  >STOP</button>
        
    </div>
    <iframe src="x.html" name="rame"frameborder="1"></iframe>
    <p><a href  ="http://192.168.152.103" target="rame">abc</a></p>
  <script>
  function up(){
    window.location.href="/up"
    
    }
    function down(){
    window.location.href="/back"
    
    }
 function left(){
    window.location.href="/left"
    
    }
     function r(){
    window.location.href="/right"
    
    }
    function x(){
    window.location.href="/null"
    
    }
  </script>
</body>
</html>)rawliteral";

void goAhead()
{
  Serial.println("goAhead Called");
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENB, speedCar);
}
void goBack()
{
  Serial.println("goBack Called");

  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCar);
}
void goRight()
{
  Serial.println("goRight Called");

  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENB, speedCar);
}
void goLeft()
{
  Serial.println("goLeft Called");

  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCar);
}

void stopRobot()
{

  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCar);
}

void setup()
{
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial.println("WiFi Failed!");
    return;
  }
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/html", index_html); });
  server.on("/up", HTTP_GET, [](AsyncWebServerRequest *request)
            {
      goAhead();
    request->send_P(200, "text/html", index_html); });
  server.on("/back", HTTP_GET, [](AsyncWebServerRequest *request)
            {
      goBack();
    request->send_P(200, "text/html", index_html); });
  server.on("/right", HTTP_GET, [](AsyncWebServerRequest *request)
            {
      goRight();
    request->send_P(200, "text/html", index_html); });
  server.on("/left", HTTP_GET, [](AsyncWebServerRequest *request)
            {
      goLeft();
    request->send_P(200, "text/html", index_html); });
  server.on("/null", HTTP_GET, [](AsyncWebServerRequest *request)
            {
      stopRobot();
    request->send_P(200, "text/html", index_html); });
  server.begin();
}

void loop()
{
}
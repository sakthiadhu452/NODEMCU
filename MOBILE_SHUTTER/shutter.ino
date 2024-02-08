#include <ESP8266WiFi.h>

const char* ssid = "POCO X2";
const char* password = "12345678";

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  server.begin();
  delay(3000);
}

void loop() {
  WiFiClient client;
  client = server.available();

 if (client == 1) {
    String request = client.readStringUntil('\n');
    client.flush();
    //Serial.println(request);
    if (request.indexOf("ledon") != -1)
    { 
      Serial.println(1);
    }
 
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println(""); 
  
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
    client.println("<title> Controlling Camra </title>");
    client.println("</head>");
    client.println("<body align= \"center\" >");
    client.println("<h1> <font size = \"95\" face = \"Cooper\" >  PRESS TO CLICK PHOTO  </font> </h1> ");
    client.println("<p> <a href=\"/ledon\">  <button style=\"height:500px; background-color: red; width:1000px; cursor: pointer\"> CLICK HERE  </button> <a> </font></p> ");
    client.println("</body>");
    client.println("</html>");
       
  }
}
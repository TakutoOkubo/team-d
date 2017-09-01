/*
 *  This sketch sends a message to a TCP server
 *
 */

#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

WiFiMulti WiFiMulti;

void setup()
{
    Serial.begin(115200);
    Serial.println("5");
    delay(10);

    // We start by connecting to a WiFi network
    WiFiMulti.addAP("team_d", "intern2017");

    Serial.println("5");
    Serial.println("");
    Serial.println("10");
    Serial.print("Wait for WiFi... ");

    while(WiFiMulti.run() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    delay(500);
}


void loop()
{
  int temp =0;
  int hot =0;
  int user =0;
    const uint16_t port = 5000;
    const char * host = "111.171.215.117"; // ip or dns
    String PostData = "{\"user_id\": \"0\", \"temp\": \"0\", \"hot_cold\": \"0\"}";

    Serial.print("connecting to ");
    Serial.println(host);

    // Use WiFiClient class to create TCP connections
    WiFiClient client;

    if (!client.connect(host, port)) {
        Serial.println("connection failed");
        Serial.println("wait 5 sec...");
        delay(5000);
        return;
    }
    
  if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status

      //if(hot==1){
        client.println("POST /send HTTP/1.1");
        client.print("Host: ");
        client.println(host);
        client.println("Content-Type: application/json");
        client.println("User-Agent: Arduino Post Client");

        client.print("Content-Length: ");
        client.println(PostData.length());

        client.println("Connection: close");
        client.println();
        client.print(PostData);
   /*HTTPClient http;   
 
   http.begin("http://111.171.215.117/send");  //Specify destination for HTTP request
   http.addHeader("Content-Type", "application/json");             //Specify content-type header

   client.println("POST /posts HTTP/1.1");
   
   http.POST("POSTING from ESP32");   //Send the actual POST request

   http.end();  //Free resources */

    // This will send the request to the server

    //read back one line from server
    String line = client.readStringUntil('\r');
    client.println(line);

    Serial.println("closing connection");
    client.stop();

    Serial.println("wait 5 sec...");
    delay(5000);
  }
}


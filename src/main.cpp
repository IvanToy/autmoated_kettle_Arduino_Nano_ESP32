#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include "web_page.h"
#include "temp_readings.h"
#include "leds_control.h"

const char *ssid = "WI-FI NAME";
const char *password = "WI-FI PASSWORD";

WebServer server(80);

IPAddress local_IP(192, 168, 1 ,251);
IPAddress gateway(192, 168, 1,1);
IPAddress subnet(255, 255, 0, 0);


int selected_temp = 100;
int kettle_state = false;
int temp_in_kettle;


const int relay_pin = D10;
const int thermistor_pin = A0;
const int red_led = D4;
const int green_led = D5;
const int blue_led = D6;

void handle_root();
void handle_set_temperature();
void handle_toggle_kettle();
void handle_get_temperature();

void setup()
{
  Serial.begin(9500);

  WiFi.begin(ssid, password);
  WiFi.config(local_IP, gateway, subnet);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, handle_root);
  server.on("/set_temperature", HTTP_POST, handle_set_temperature);
  server.on("/toggle_kettle", HTTP_POST, handle_toggle_kettle);
  server.on("/get_temperature", HTTP_GET, handle_get_temperature);

  server.begin();
  Serial.println("HTTP server started");

  server.begin();

  pinMode(relay_pin, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(green_led, OUTPUT);
}

void loop()
{
  server.handleClient();

  temp_in_kettle = temp_readings(thermistor_pin);
  Serial.println(temp_in_kettle);
  leds_control(red_led, green_led, blue_led, temp_in_kettle);

  if (temp_in_kettle >= selected_temp)
  {
    kettle_state = false;
    selected_temp = 100;

  }

  if (kettle_state)
  {
    digitalWrite(relay_pin, LOW);
  }
  else
  {
    digitalWrite(relay_pin, HIGH);
  }
  delay(500);
}

void handle_root()
{
  server.send(200, "text/html", web_page());
}

void handle_set_temperature()
{
  String temp = server.arg("temp");
  selected_temp = temp.toInt();
  server.send(200, "text/plain", "OK");
}

void handle_toggle_kettle()
{
  kettle_state = !kettle_state;
  server.send(200, "text/plain", "OK");
}

void handle_get_temperature()
{
  server.send(200, "application/json", "{\"temperature\":" + String(temp_in_kettle) + "}");
}
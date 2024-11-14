#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "";   // Replace with your Wi-Fi SSID
const char* password = ""; // Replace with your Wi-Fi password

WebServer server(80);

// Simulate a temperature sensor (random value between 20 and 30)
float simulateTemperature() {
  return random(200, 300) / 10.0; // Random float between 20.0 and 30.0
}

// Handle the root URL to serve the simulated temperature data
void handleRoot() {
  float temperature = simulateTemperature();
  String html = "<html><body>";
  html += "<h1>Simulated Temperature Sensor</h1>";
  html += "<p>Current Temperature: " + String(temperature) + " °C</p>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  // Initialize serial and WiFi
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  // Wait for the connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");

  // Print the IP address
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Define HTTP routes
  server.on("/", HTTP_GET, handleRoot);

  // Start the server
  server.begin();
}

void loop() {
  // Handle client requests
  server.handleClient();
}

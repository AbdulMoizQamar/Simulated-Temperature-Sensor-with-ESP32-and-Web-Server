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
  
  // Create a modern, responsive HTML design with CSS
  String html = "<!DOCTYPE html><html lang='en'>";
  html += "<head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<title>Simulated Temperature Sensor</title>";
  html += "<style>";
  html += "body { font-family: 'Arial', sans-serif; background-color: #f4f4f9; margin: 0; padding: 0; color: #333; }";
  html += "header { background-color: #4CAF50; color: white; text-align: center; padding: 20px; }";
  html += "h1 { margin: 0; font-size: 36px; }";
  html += "main { display: flex; justify-content: center; align-items: center; height: 80vh; }";
  html += ".container { text-align: center; padding: 20px; background-color: #fff; border-radius: 8px; box-shadow: 0 4px 8px rgba(0,0,0,0.1); }";
  html += "p { font-size: 24px; font-weight: bold; color: #4CAF50; }";
  html += "@media (max-width: 600px) { h1 { font-size: 28px; } p { font-size: 20px; } }";  // Responsive text size
  html += "</style>";
  html += "</head><body>";
  
  html += "<header><h1>Simulated Temperature Sensor</h1></header>";
  html += "<main><div class='container'>";
  html += "<p>Current Temperature: " + String(temperature) + " °C</p>";
  html += "</div></main>";
  
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

const char* apiKey = "AIzaSyDnWqFh0sKEb3a8KKkpD6iLoiXNIvXRhSE";

void askGemini(String question) {
  if (question.length() == 0) {
    noResponseEmo();
    return;
}
  apiEmo();
  HTTPClient http;
  String url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-2.0-flash:generateContent?key=" + String(apiKey);

  StaticJsonDocument<512> doc;
  JsonArray contents = doc.createNestedArray("contents");
  JsonObject content = contents.createNestedObject();
  JsonArray parts = content.createNestedArray("parts");

  // Instruct Gemini to keep it short
  parts.createNestedObject()["text"] = question;

  String payload;
  serializeJson(doc, payload);

  http.begin(url);
  http.addHeader("Content-Type", "application/json");

  int httpCode = http.POST(payload);
  String response = http.getString();
  http.end();

  if (httpCode != 200) {
    Serial.printf("HTTP error %d: %s\n", httpCode, response.c_str());
    errorEmo();
  }

  DynamicJsonDocument respDoc(4096);
  DeserializationError error = deserializeJson(respDoc, response);
  if (error) {
    Serial.print("JSON parse error: ");
    Serial.println(error.c_str());
    errorEmo();
  }

  const char* reply = respDoc["candidates"][0]["content"]["parts"][0]["text"];
  Serial.println(String(reply));
  Serial1.println(cleanForTTS(String(reply)));
  audioEmo();
}

String cleanForTTS(String response) {
  response.replace("*", "");                // Remove all asterisks
  response.replace("\r", "");               // Remove carriage returns
  response.replace("\n", ",");          // Replace newlines with pause marker
  response.replace("  ", " ");              // Remove double spaces
  response.trim();                          // Clean up leading/trailing spaces
  return response;
}

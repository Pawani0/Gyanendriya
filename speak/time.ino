void initTime() {
  // Set up NTP
  configTime(19800, 0, "pool.ntp.org","time.nist.gov");

  // Wait for time sync
  struct tm timeinfo;
  while (!getLocalTime(&timeinfo)) {
    Serial.println("Waiting for NTP time...");
    delay(1000);
    Serial.println("time failed");
  }
  Serial.println("Time initialized.");
}

String numberToWords(int num) {
  const char* words[] = {
    "twelve", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine", "ten", "eleven"
  };
  return String(words[num % 12]);
}

String getCurrentTimeInWords() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    return "Failed to get time";
  }

  int h = timeinfo.tm_hour;
  int m = timeinfo.tm_min;

  String result = "It’s ";

  if (m == 0) {
    result += numberToWords(h) + " o'clock";
  } else if (m == 15) {
    result += "quarter past " + numberToWords(h);
  } else if (m == 30) {
    result += "half past " + numberToWords(h);
  } else if (m == 45) {
    result += "quarter to " + numberToWords(h + 1);
  } else if (m < 30) {
    result += String(m) + " past " + numberToWords(h);
  } else {
    result += String(60 - m) + " to " + numberToWords(h + 1);
  }

  return result;
}
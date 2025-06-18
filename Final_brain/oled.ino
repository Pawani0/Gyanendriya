void errorEmo() {
  Serial.print("error occured");
  delay(1500);
  unsigned long time = millis();
  while (millis() - time < 5000) {
    display.clearDisplay();
    display.drawBitmap(32, 0, error_emo[frame], FRAME_WIDTH, FRAME_HEIGHT, 1);
    display.display();
    frame = (frame + 1) % FRAME_COUNT;
    delay(FRAME_DELAY);
  }
}

void coolEmo() {
  Serial.print("swag");
  delay(1500);
  unsigned long time = millis();
  while (millis() - time < 5000) {
    display.clearDisplay();
    display.drawBitmap(32, 0, cool_emo[frame], FRAME_WIDTH, FRAME_HEIGHT, 1);
    display.display();
    frame = (frame + 1) % FRAME_COUNT;
    delay(FRAME_DELAY);
  }
}

void handEmo() {
  Serial.print("handshake");
  delay(1500);
  unsigned long time = millis();
  while (millis() - time < 5000) {
    display.clearDisplay();
    display.drawBitmap(32, 0, hand_emo[frame], FRAME_WIDTH, FRAME_HEIGHT, 1);
    display.display();
    frame = (frame + 1) % FRAME_COUNT;
    delay(FRAME_DELAY);
  }
}

void audioEmo() {
  Serial.print("playing audio");
  delay(1500);
  unsigned long time = millis();
  while (millis() - time < 5000) {
    display.clearDisplay();
    display.drawBitmap(32, 0, audio_emo[frame], FRAME_WIDTH, FRAME_HEIGHT, 1);
    display.display();
    frame = (frame + 1) % FRAME_COUNT;
    delay(FRAME_DELAY);
  }
}

void noResponseEmo() {
  Serial.print("no response");
  delay(1500);
  unsigned long time = millis();
  while (millis() - time < 5000) {
    display.clearDisplay();
    display.drawBitmap(32, 0, confuse_emo[frame], FRAME_WIDTH, FRAME_HEIGHT, 1);
    display.display();
    frame = (frame + 1) % FRAME_COUNT;
    delay(FRAME_DELAY);
  }
}

void apiEmo() {
  Serial.print("api request");
  delay(1500);
  unsigned long time = millis();
  while (millis() - time < 5000) {
    display.clearDisplay();
    display.drawBitmap(32, 0, cloud_emo[frame], FRAME_WIDTH, FRAME_HEIGHT, 1);
    display.display();
    frame = (frame + 1) % FRAME_COUNT;
    delay(FRAME_DELAY);
  }
}
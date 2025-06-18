void match(String Question) {
  if (strcmp(Question.c_str(), "Introduce yourself.") == 0 || strcmp(Question.c_str(), "Tell me about yourself.") == 0 || strcmp(Question.c_str(), "Who are you?") == 0 || strcmp(Question.c_str(), "Hello.") == 0 || strcmp(Question.c_str(), "Hello?") == 0 || strcmp(Question.c_str(), "What is your name?") == 0 || strcmp(Question.c_str(), "What is your name.") == 0) {
    Serial1.println("Hello, My name is Gyanendriya and I am a humanoid robot with AI capabilities. Tell me how can i assist you");
    audioEmo();
  } else if (strcmp(Question.c_str(), "What are your capabilities.") == 0 || strcmp(Question.c_str(), "Tell me about your capabilities.") == 0) {
    Serial1.println("As an AI integrated robot i can answer your questions, perform action according to your voice command");
    audioEmo();
  } else if (strcmp(Question.c_str(), "What are your main components?") == 0 || strcmp(Question.c_str(), "Tell me about your main components.") == 0 || strcmp(Question.c_str(), "Main components.") == 0) {
    Serial1.println("My main components are E S P 32, AI assistance, servo motors, servo motor driver, temperature sensors, amplifier for speaker");
    audioEmo();
  } else if (strcmp(Question.c_str(), "What is sistec?") == 0 || strcmp(Question.c_str(), "What is sagar institute of science of technology?") == 0 || strcmp(Question.c_str(), "Tell me about sistec.") == 0 || strcmp(Question.c_str(), "Systec.") == 0 || strcmp(Question.c_str(), "Tell me about systec.") == 0 || strcmp(Question.c_str(), "Sagar institute of science of technology.") == 0 || strcmp(Question.c_str(), "Systech.") == 0 || strcmp(Question.c_str(), "Tell me about systech.") == 0) {
    Serial1.println("sagar institute of science of technology is private engineering college. Located in bhopal, madhya pradesh. It is A I C T E approved.");
    audioEmo();
  } else if (strcmp(Question.c_str(), "Time.") == 0 || strcmp(Question.c_str(), "What is the time now?") == 0 || strcmp(Question.c_str(), "What,s the time now?") == 0) {
    Serial1.print("time");
    audioEmo();
  } else if (strcmp(Question.c_str(), "News.") == 0 || strcmp(Question.c_str(), "Play news.") == 0 || strcmp(Question.c_str(), "Play News.") == 0) {
    Serial1.print("news");
    Serial.print("news");
    audioEmo();
  } else if (strcmp(Question.c_str(), "Radio.") == 0 || strcmp(Question.c_str(), "Play radio.") == 0 || strcmp(Question.c_str(), "Play Radio.") == 0) {
    Serial1.print("radio");
    Serial.print("radio");
    audioEmo();
  } else if (strcmp(Question.c_str(), "Stop.") == 0 || strcmp(Question.c_str(), "Stop playing.") == 0 || strcmp(Question.c_str(), "Stop radio.") == 0 || strcmp(Question.c_str(), "Stop news.") == 0 || strcmp(Question.c_str(), "Stop Radio.") == 0 || strcmp(Question.c_str(), "Stop News.") == 0) {
    Serial1.print("stop");
    Serial.print("stoping");
  } else if (strcmp(Question.c_str(), "Dance.") == 0 || strcmp(Question.c_str(), "Start dancing.") == 0 || strcmp(Question.c_str(), "Gyanendriya dance.") == 0) {
    Serial2.print("dance");
    Serial.print("dance");
  } else if (strcmp(Question.c_str(), "Swag.") == 0) {
    Serial2.print("swag");
    Serial.print("swag");
    coolEmo();
  } else if (strcmp(Question.c_str(), "Hug.") == 0 || strcmp(Question.c_str(), "Hug me.") == 0 || strcmp(Question.c_str(), "Gyanendriya hug me.") == 0) {
    Serial2.print("hug");
    Serial.print("hug");
  } else if (strcmp(Question.c_str(), "Handshake.") == 0 || strcmp(Question.c_str(), "Hand shake.") == 0 || strcmp(Question.c_str(), "Gyanendriya handshake.") == 0) {
    Serial2.print("handshake");
    Serial.print("handshake");
    handEmo();
  } else if (strcmp(Question.c_str(), "Tarzan.") == 0 || strcmp(Question.c_str(), "Taarzan.") == 0) {
    Serial2.print("tarzan");
    Serial.print("tarzan");
  } else if (strcmp(Question.c_str(), "Stand.") == 0 || strcmp(Question.c_str(), "Stand straight.") == 0) {
    Serial2.print("stand");
    Serial.print("stand");
  } else if (strcmp(Question.c_str(), "Salute.") == 0 || strcmp(Question.c_str(), "Gyanendriya salute,") == 0) {
    Serial2.print("salute");
    Serial.print("salute");
  } else if (strcmp(Question.c_str(), "One leg.") == 0) {
    Serial2.print("one leg");
    Serial.print("one leg");
  } else if (strcmp(Question.c_str(), "Pick.") == 0 || strcmp(Question.c_str(), "Pick up.") == 0) {
    Serial2.print("pick");
    Serial.print("pick");
  } else if (strcmp(Question.c_str(), "Drop.") == 0 || strcmp(Question.c_str(), "Drop this.") == 0) {
    Serial2.print("drop");
    Serial.print("drop");
  } else {
    askGemini(Question);
  }
}
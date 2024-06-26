#define LED_1 13
#define LED_2  8
#define LED_3  2

void setup() {
  Serial.begin(115200);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

void loop() {
  while(!Serial.available());
  char recieve[256];
  int i = 0;
  while(Serial.available() > 0) {
    char c = Serial.read();
    if(((0x20 <= c) && (c <= 0x7E) || (c == 0x0A) || (c == 0x0D))) {
      recieve[i++] = c;
    }
  }
  recieve[i] = 0;
  Serial.print("[INFO] Recieved data : ");
  Serial.println(recieve);

  char cmd[4], led[2], status[5];
  sscanf(recieve, "%s %s %s", cmd, led, status);

  char buffer[64];
  sprintf(buffer, "     command : %s\nselected LED : %s\n      status : %s\n\n", cmd, led, status);
  Serial.print(buffer);

  /* LED コマンドここから */
  if(strncmp(cmd, "led", 3) == 0) {
    Serial.println("\"led\" command start");
    if((strncmp(led, "1", 1) == 0) || (strncmp(led, "a", 1) == 0) || (strncmp(led, "A", 1) == 0)) {
      Serial.println("LED_1 selected");
      if((strncmp(status, "on", 2) == 0) || (strncmp(status, "high", 4) == 0) || (strncmp(status, "1", 1) == 0)) {
        Serial.println("LED_1 turn on");
        digitalWrite(LED_1, HIGH);
      }else if((strncmp(status, "off", 3) == 0) || (strncmp(status, "low", 3) == 0) || (strncmp(status, "0", 1) == 0)) {
        Serial.println("LED_1 turn off");
        digitalWrite(LED_1,  LOW);
      }else {
        Serial.print("invalid argument : ");
        Serial.println(status);
      }
    }else if((strncmp(led, "2", 1) == 0) || (strncmp(led, "b", 1) == 0) || (strncmp(led, "B", 1) == 0)) {
      Serial.println("LED_2 selected");
      if((strncmp(status, "on", 2) == 0) || (strncmp(status, "high", 4) == 0) || (strncmp(status, "1", 1) == 0)) {
        Serial.println("LED_2 turn on");
        digitalWrite(LED_2, HIGH);
      }else if((strncmp(status, "off", 3) == 0) || (strncmp(status, "low", 3) == 0) || (strncmp(status, "0", 1) == 0)) {
        Serial.println("LED_2 turn off");
        digitalWrite(LED_2,  LOW);
      }else {
        Serial.print("invalid argument : ");
        Serial.println(status);
      }
    }else if((strncmp(led, "3", 1) == 0) || (strncmp(led, "c", 1) == 0) || (strncmp(led, "C", 1) == 0)) {
      Serial.println("LED_3 selected");
      if((strncmp(status, "on", 2) == 0) || (strncmp(status, "high", 4) == 0) || (strncmp(status, "1", 1) == 0)) {
        Serial.println("LED_3 turn on");
        digitalWrite(LED_3, HIGH);
      }else if((strncmp(status, "off", 3) == 0) || (strncmp(status, "low", 3) == 0) || (strncmp(status, "0", 1) == 0)) {
        Serial.println("LED_3 turn off");
        digitalWrite(LED_3,  LOW);
      }else {
        Serial.print("invalid argument : ");
        Serial.println(status);
      }
    }else {
      Serial.print("invalid argument : ");
      Serial.println(led);
    }
    Serial.println("\"led\" command end");
    Serial.println();
  }
  /* LED コマンドここまで */
}

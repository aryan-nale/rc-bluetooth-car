char command;

#define ENA 5
#define ENB 6
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

void setup() {
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);

  // Motor speed
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void loop() {

  if (Serial.available()) {
    command = Serial.read();

    // Forward
    if (command == 'F') {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);

      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    // Backward
    else if (command == 'B') {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);

      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }

    // Left
    else if (command == 'L') {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);

      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    // Right
    else if (command == 'R') {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);

      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }

    // Stop
    else if (command == 'S') {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);

      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
  }
}

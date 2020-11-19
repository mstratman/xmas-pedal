#define SOMETIMES_MULTIPLES

#define SOMETIMES_ALL
#define CHANCE_FOR_ALL 14

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

int pin  = 0;
void loop() {
  pin = random(0, 5);
  digitalWrite(pin, HIGH);

#ifdef SOMETIMES_MULTIPLES
  pin = random(0, 5);
  digitalWrite(pin, HIGH);
#endif

#ifdef SOMETIMES_ALL
  if (random(0, CHANCE_FOR_ALL) == 0) {
    for (pin = 0; pin < 5; pin++) {
      digitalWrite(pin, HIGH);
    }
  }
#endif

  delay(400);

  for (pin = 0; pin < 5; pin++) {
    digitalWrite(pin, LOW);
  }
}

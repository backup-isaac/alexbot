void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}

double old_random_1, old_random_2;

void loop() {
  // put your main code here, to run repeatedly:
  double new_random_1 = random_squared_256();
  double new_random_2 = random_squared_256();
  for (int i = 0; i <= 25; i++) {
    analogWrite(6, old_random_1 + i * (new_random_1 - old_random_1) / 25.0);
    analogWrite(9, old_random_2 + i * (new_random_2 - old_random_2) / 25.0);
    delay(80);
  };
  old_random_1 = new_random_1;
  old_random_2 = new_random_2;
}

double random_squared_256() {
  double val = random(490) / 490.0 * 16;
  return val * val;
}

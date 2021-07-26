void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
}
int steer, speed;

void loop() {
  steer = 0;
  speed = constrain(analogRead(A0), 0, 1000);

  Serial.write(0xff);
  Serial.write(0xfe);
  Serial.write((uint16_t)steer >> 8);
  Serial.write(steer);
  Serial.write((uint16_t)speed >> 8);
  Serial.write(speed);
  uint16_t sumcheck = 0xff + 0xfe + (uint8_t)(steer >> 8) + (uint8_t)(steer) + (uint8_t)(speed >> 8) + (uint8_t)(speed);

  Serial.write((uint16_t)sumcheck >> 8);
  Serial.write(sumcheck);
  delay(50);  // motor enable timeout 200 ms
}
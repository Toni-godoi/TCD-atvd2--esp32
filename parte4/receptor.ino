// receptor.ino
#define BAUD_RATE 9600
#define PINO_TX 17
#define PINO_RX 16
#define PINO_LED 25

#define CANAL_PWM 0
#define FREQ_PWM 1000
#define RESOLUCAO 8

String recebido = "";

void setup() {
 Serial.begin(115200);
 Serial2.begin(BAUD_RATE, SERIAL_8N1, PINO_RX, PINO_TX);

 ledcAttachChannel(PINO_LED, FREQ_PWM, RESOLUCAO, CANAL_PWM);

 Serial.println("Receptor pronto.");
}

void loop() {
 while (Serial2.available()) {
  char c = Serial2.read();

  if (c == '\n') {
   int valor = recebido.toInt(); // 0–4095
   int pwm = map(valor, 0, 4095, 0, 255);

   ledcWrite(PINO_LED, pwm);

   Serial.print("ADC: ");
   Serial.print(valor);
   Serial.print(" | PWM: ");
   Serial.println(pwm);

   recebido = "";
  } else {
   recebido += c;
  }
 }
}

// transmissor.ino
#define BAUD_RATE 9600
#define PINO_TX 17
#define PINO_RX 16
#define PINO_POT 34

void setup() {
 Serial.begin(115200);
 Serial2.begin(BAUD_RATE, SERIAL_8N1, PINO_RX, PINO_TX);
 Serial.println("Transmissor pronto.");
}

void loop() {
 int leitura = analogRead(PINO_POT); // 0–4095

 Serial2.println(leitura);           // envia valor
 Serial.print("Enviado: ");
 Serial.println(leitura);

 delay(100);
}

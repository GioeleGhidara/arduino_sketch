long int data = 0;
long unsigned t0, t1;
int i;

void setup() {
  // open serial communication and wait for port to open
  Serial.begin(9600);                // Velocità porta seriale
  Serial.println("Ci siamo!");       // Messaggio iniziale
  Serial.println(" ");               // Scrive una linea vuota
}

void loop() {
  if (Serial.available() > 0) {      // Controlla se c'è qualcosa in input
    data = Serial.parseInt();        // legge l’input come intero
    t0 = micros();                   // Salva il tempo iniziale

    Serial.print("Hai scritto il numero: ");
    Serial.println(data);            // Stampa il numero inserito

    Serial.print("E questo moltiplicato per 10 fa: ");
    Serial.println(data * 10);       // Stampa il numero moltiplicato per 10

    t1 = micros();                   // Salva il tempo finale

    Serial.print("durata t0= ");
    Serial.println(t0);              // Stampa t0

    Serial.print("t1= ");
    Serial.println(t1);              // Stampa t1

    Serial.print("t1-t0: ");
    Serial.println(t1 - t0);         // Calcola e stampa la differenza

    Serial.println("microsecondi");  // Scrive “microsecondi”
    delay(100);                      // Aspetta 100 millisecondi
  }
}

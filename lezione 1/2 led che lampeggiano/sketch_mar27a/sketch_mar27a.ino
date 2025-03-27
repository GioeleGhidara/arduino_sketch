// 2 led lampeggiano alternativamente
const int LED1 = 13; // assegno il pin 13
const int LED2 = 8; // assegno il pin 8

void setup() {
  pinMode(LED1, OUTPUT); // il pin è definito come output
  pinMode(LED2, OUTPUT); // il pin è definito come output
}

void loop() {
  digitalWrite(LED1, HIGH); // mette il pin LED1 a 5V
  digitalWrite(LED2, LOW); // mette il pin LED1 a 0V
  delay(500); // aspetta 500ns, la funzione delay() è settata in millisecondi
  digitalWrite(LED1, LOW); // mette il pin LED1 a 0V
  digitalWrite(LED2, HIGH); // mette il pin LED1 a 5V
  delay(500); // aspetta 500ns
}

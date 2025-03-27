// 2 led lampeggiano alternativamente
const int VERDE = 13; // assegno il pin 13 verde
const int GIALLO = 8; // assegno il pin 8 giallo
const int ROSSO = 4; // assegno il pin 4 rosso

void setup() {
  pinMode(VERDE, OUTPUT); // il pin è definito come output
  pinMode(GIALLO, OUTPUT); // il pin è definito come output
  pinMode(ROSSO, OUTPUT); // il pin è definito come output

}

void loop() {
  for ( int i=0;i<3;i++ ) {
    digitalWrite(VERDE, HIGH);
    digitalWrite(GIALLO, LOW);
    digitalWrite(ROSSO, LOW); 
    delay(500); // aspetta 5s, la funzione delay() è settata in millisecondi
    digitalWrite(VERDE, LOW);
    digitalWrite(GIALLO, LOW);
    digitalWrite(ROSSO, LOW); 
    delay(500); // aspetta 5s, la funzione delay() è settata in millisecondi
  }
  
  digitalWrite(VERDE, HIGH);
  digitalWrite(GIALLO, LOW);
  digitalWrite(ROSSO, LOW); 
  delay(5000); // aspetta 5s, la funzione delay() è settata in millisecondi
  digitalWrite(VERDE, LOW); 
  digitalWrite(GIALLO, HIGH);
  digitalWrite(ROSSO, LOW); 
  delay(2000); // aspetta 2s, la funzione delay() è settata in millisecondi
  digitalWrite(VERDE, LOW); 
  digitalWrite(GIALLO, LOW); 
  digitalWrite(ROSSO, HIGH); 
  delay(5000); // aspetta 5s, la funzione delay() è settata in millisecondi
}

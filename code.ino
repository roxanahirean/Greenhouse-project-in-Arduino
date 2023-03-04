int releu = 12; //pompa conectata la pinul 12
int senzor = A1; //sezsor analog pin conectat la pinul A1
//int val; //in val pastrez valoarea pe care o primesc de la senzorul de umiditate din sol

void setup() {
  pinMode(8, INPUT);
  pinMode(12, OUTPUT); //setez pinul 12 ca output 
  digitalWrite(12, HIGH);
  pinMode(A1, INPUT); //pinul A1 va fi input pt ca in el primesc info de la senzorul de umiditate din sol

  // serial begin si setam la 9600
  Serial.begin(9600); 
  Serial.println("Am inceput programul:");

}

void loop() {

  int temp = digitalRead(8); 
  int  val = analogRead(A1);

  Serial.print("umiditate: ");
   Serial.println(val);
  //citeste date de la senzorul de umiditate
  if (temp == LOW) {  //analog read
    Serial.println("Este zi/lumina!");
    if (val >= 600) {
      Serial.println("Sol uscat. Udam 3 secunde");
      digitalWrite(12, LOW); 
      delay(3000);
      digitalWrite(12, HIGH);
    }
    else {
      Serial.println("Sol umed. Nu udam");
      //digitalWrite(12, HIGH); 
      }
    }
  else {
    Serial.println("Este noapte/intuneric!");
  }

  Serial.println("Final colectare date. Le re-verificam peste 10 secunde.");

  delay(7000); //asteptam cateva sec si dupa se continua loop ul
}
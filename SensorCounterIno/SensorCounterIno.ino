int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
}

void loop() {
  val = analogRead(16);
  Serial.println(val);  

  delay(100);
  
  //if(val > 100) Serial.println(1);  
  //else Serial.println(0);  
}


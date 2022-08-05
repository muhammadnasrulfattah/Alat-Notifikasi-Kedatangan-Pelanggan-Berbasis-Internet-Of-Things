int sensor_pir1 = 5;
int sensor_pir2 = 2;
int buzzer_1 = 12;
int buzzer_2 = 13;
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char token[] = "uxkMX26AsM_6w56ilDZ5HKPq-MtL80xm";
char user[] = "Indihome";
char pass[] = "ruangdapur";

void setup() {
  Serial.begin(115200);
  Blynk.begin(token, user, pass);
  pinMode(sensor_pir1, INPUT);
  pinMode(sensor_pir2, INPUT);
  pinMode(buzzer_1,OUTPUT);
  pinMode(buzzer_2,OUTPUT);
  digitalWrite(buzzer_1,LOW);
  digitalWrite(buzzer_2, LOW);
}

void loop() {
  long pintu_1 = digitalRead(sensor_pir1);
  long pintu_2 = digitalRead(sensor_pir2);
  
  if (pintu_1 == HIGH && pintu_2 == LOW) {
    Serial.println("ada gerakan di pintu 1");
    Blynk.notify("ada gerakan di pintu 1");
    digitalWrite(buzzer_1, HIGH);
    delay(1000);
  }

   if (pintu_1 == LOW && pintu_2 == HIGH) {
    Serial.println("ada gerakan di pintu 2");
    Blynk.notify("ada gerakan di pintu 2");
    digitalWrite(buzzer_2, HIGH);
    delay(1000);
  }

   if (pintu_1 == HIGH && pintu_2 == HIGH) {
    Serial.println("ada gerakan di pintu 1 dan pintu 2");
    Blynk.notify("ada gerakan di pintu 1 dan pintu 2");
    digitalWrite(buzzer_1, HIGH);
    digitalWrite(buzzer_2, HIGH);
    delay(1000);
  }
 
  else {
    Serial.println("tidak ada gerakan");
    digitalWrite(buzzer_1, LOW);
    digitalWrite(buzzer_2, LOW);
    delay(1000);
  }
  
  Blynk.run();
}

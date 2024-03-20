//#define IN1D 2 // deklarasi pin IN1
//#define IN2D 3  // deklarasi pin IN2
//#define IN3D 4  // deklarasi pin IN3
//#define IN4D 7  // deklarasi pin IN4
//#define ENAD 5 // deklarasi pin ENA
//#define ENBD 6  // deklarasi pin ENB

//
#define IN1U 8 // deklarasi pin IN1
#define IN2U 11  // deklarasi pin IN2
#define IN3U 12  // deklarasi pin IN3
#define IN4U 13  // deklarasi pin IN4
#define ENAU 9 // deklarasi pin ENA
#define ENBU 10  // deklarasi pin ENB

#define pwm  80
void setup() {
  // Konfigurasi pin-pin sebagai Output
//  pinMode(IN1D, OUTPUT);
//  pinMode(IN2D, OUTPUT);
//  pinMode(IN3D, OUTPUT);
//  pinMode(IN4D, OUTPUT);
//  pinMode(ENAD, OUTPUT);
//  pinMode(ENBD, OUTPUT);

  pinMode(IN1U, OUTPUT);
  pinMode(IN2U, OUTPUT);
  pinMode(IN3U, OUTPUT);
  pinMode(IN4U, OUTPUT);
  pinMode(ENAU, OUTPUT);
  pinMode(ENBU, OUTPUT);
}

void loop() {
  // Motor A dan B berputar ke kanan 2000 ms (2 detik) dengan kecepatan penuh
  digitalWrite(IN1D, HIGH);
  digitalWrite(IN2D, LOW);
  digitalWrite(ENAD, pwm); // Mengatur kecepatan motor A (0-255)
  digitalWrite(IN3D, HIGH);
  digitalWrite(IN4D, LOW);
  digitalWrite(ENBD, pwm); // Mengatur kecepatan motor B (0-255)
  delay(2000); // Jeda 2 detik
  
//  // Motor A dan B berputar ke kiri 2000 ms (2 detik) dengan kecepatan penuh
  digitalWrite(IN1U, LOW);
  digitalWrite(IN2U, HIGH);
  digitalWrite(ENAU, pwm); // Mengatur kecepatan motor A (255 = 100%)
  digitalWrite(IN3U, LOW);
  digitalWrite(IN4U, HIGH);
  digitalWrite(ENBU, pwm); // Mengatur kecepatan motor B (255 = 100%)
  delay(2000); // Jeda 2 detik;

  // Motor A dan motor B berhenti selama 2000 ms (2 detik)
  digitalWrite(IN1U, LOW);
  digitalWrite(IN2U, LOW);
  digitalWrite(ENAU, LOW);
  digitalWrite(IN3U, LOW);
  digitalWrite(IN4U, LOW);
  digitalWrite(ENBU, LOW);
  // Motor A dan motor B berhenti selama 2000 ms (2 detik)
  digitalWrite(IN1D, LOW);
  digitalWrite(IN2D, LOW);
  digitalWrite(ENAD, LOW);
  digitalWrite(IN3D, LOW);
  digitalWrite(IN4D, LOW);
  digitalWrite(ENBD, LOW);

  digitalWrite(IN1D, LOW);
  digitalWrite(IN2D, HIGH);
  digitalWrite(ENAD, pwm); // Mengatur kecepatan motor A (0-255)
  digitalWrite(IN3D, LOW);
  digitalWrite(IN4D, HIGH);
  digitalWrite(ENBD, pwm); // Mengatur kecepatan motor B (0-255)
  delay(2000); // Jeda 2 detik

  digitalWrite(IN1D, LOW);
  digitalWrite(IN2D, LOW);
  digitalWrite(ENAD, LOW);
  digitalWrite(IN3D, LOW);
  digitalWrite(IN4D, LOW);
  digitalWrite(ENBD, LOW);
  
  delay(800);
}

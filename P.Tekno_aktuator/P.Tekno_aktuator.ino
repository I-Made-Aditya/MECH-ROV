const int Fasa1_In1 = 8;
const int Fasa1_In2 = 7;
const int Fasa1_PWM = 10;
const int Fasa2_In1 = 6;
const int Fasa2_In2 = 5;
const int Fasa2_PWM = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(Fasa1_In1, OUTPUT);
  pinMode(Fasa1_In2, OUTPUT);
  pinMode(Fasa1_PWM, OUTPUT);
  pinMode(Fasa2_In1, OUTPUT);
  pinMode(Fasa2_In2, OUTPUT);
  pinMode(Fasa2_PWM, OUTPUT);

  analogWrite(Fasa1_PWM, 0); //nilai awal = 0
  analogWrite(Fasa2_PWM, 0); //nilai awal = 0
}

int Step = 0;
int PWMstepAntara = 105;

void Rectangular_16Step()
{
  switch (Step)
  { case 0:
      analogWrite(Fasa1_PWM, 255);
      analogWrite(Fasa2_PWM, 0);
      digitalWrite(Fasa1_In1, 1);
      digitalWrite(Fasa1_In2, 0);
      digitalWrite(Fasa2_In1, 0);
      digitalWrite(Fasa2_In2, 0);
      break;
    case 1:
      analogWrite(Fasa1_PWM, 255);
      analogWrite(Fasa2_PWM, PWMstepAntara);
      digitalWrite(Fasa1_In1, 1);
      digitalWrite(Fasa1_In2, 0);
      digitalWrite(Fasa2_In1, 1);
      digitalWrite(Fasa2_In2, 0);
      break;
    case 2:
      analogWrite(Fasa1_PWM, 255);
      analogWrite(Fasa2_PWM, 255);
      digitalWrite(Fasa1_In1, 1);
      digitalWrite(Fasa1_In2, 0);
      digitalWrite(Fasa2_In1, 1);
      digitalWrite(Fasa2_In2, 0);
      break;
    case 3:
      analogWrite(Fasa1_PWM, PWMstepAntara);
      analogWrite(Fasa2_PWM, 255);
      digitalWrite(Fasa1_In1, 1);
      digitalWrite(Fasa1_In2, 0);
      digitalWrite(Fasa2_In1, 1);
      digitalWrite(Fasa2_In2, 0);
      break;
    case 4:
      analogWrite(Fasa1_PWM, 0);
      analogWrite(Fasa2_PWM, 255);
      digitalWrite(Fasa1_In1, 0);
      digitalWrite(Fasa1_In2, 0);
      digitalWrite(Fasa2_In1, 1);
      digitalWrite(Fasa2_In2, 0);
      break;
    case 5:
      analogWrite(Fasa1_PWM, PWMstepAntara);
      analogWrite(Fasa2_PWM, 255);
      digitalWrite(Fasa1_In1, 0);
      digitalWrite(Fasa1_In2, 1);
      digitalWrite(Fasa2_In1, 1);
      digitalWrite(Fasa2_In2, 0);
      break;
    case 6:
      analogWrite(Fasa1_PWM, 255);
      analogWrite(Fasa2_PWM, 255);
      digitalWrite(Fasa1_In1, 0);
      digitalWrite(Fasa1_In2, 1);
      digitalWrite(Fasa2_In1, 1);
      digitalWrite(Fasa2_In2, 0);
      break;
    case 7:
      analogWrite(Fasa1_PWM, 255);
      analogWrite(Fasa2_PWM, PWMstepAntara);
      digitalWrite(Fasa1_In1, 0);
      digitalWrite(Fasa1_In2, 1);
      digitalWrite(Fasa2_In1, 1);
      digitalWrite(Fasa2_In2, 0);
      break;
    case 8:
      analogWrite(Fasa1_PWM, 255);
      analogWrite(Fasa2_PWM, 0);
      digitalWrite(Fasa1_In1, 0);
      digitalWrite(Fasa1_In2, 1);
      digitalWrite(Fasa2_In1, 0);
      digitalWrite(Fasa2_In2, 0);
      break;
    case 9:
      analogWrite(Fasa1_PWM, 255);
      analogWrite(Fasa2_PWM, PWMstepAntara);
      digitalWrite(Fasa1_In1, 0);
      digitalWrite(Fasa1_In2, 1);
      digitalWrite(Fasa2_In1, 0);
      digitalWrite(Fasa2_In2, 1);
      break;
    case 10:
      analogWrite(Fasa1_PWM, 255);
      analogWrite(Fasa2_PWM, 255);
      digitalWrite(Fasa1_In1, 0);
      digitalWrite(Fasa1_In2, 1);
      digitalWrite(Fasa2_In1, 0);
      digitalWrite(Fasa2_In2, 1);
      break;
    case 11:
      analogWrite(Fasa1_PWM, PWMstepAntara);
      analogWrite(Fasa2_PWM, 255);
      digitalWrite(Fasa1_In1, 0);
      digitalWrite(Fasa1_In2, 1);
      digitalWrite(Fasa2_In1, 0);
      digitalWrite(Fasa2_In2, 1);
      break;
    case 12:
      analogWrite(Fasa1_PWM, 0);
      analogWrite(Fasa2_PWM, 255);
      digitalWrite(Fasa1_In1, 0);
      digitalWrite(Fasa1_In2, 0);
      digitalWrite(Fasa2_In1, 0);
      digitalWrite(Fasa2_In2, 1);
      break;
    case 13:
      analogWrite(Fasa1_PWM, PWMstepAntara);
      analogWrite(Fasa2_PWM, 255);
      digitalWrite(Fasa1_In1, 1);
      digitalWrite(Fasa1_In2, 0);
      digitalWrite(Fasa2_In1, 0);
      digitalWrite(Fasa2_In2, 1);
      break;
    case 14:
      analogWrite(Fasa1_PWM, 255);
      analogWrite(Fasa2_PWM, 255);
      digitalWrite(Fasa1_In1, 1);
      digitalWrite(Fasa1_In2, 0);
      digitalWrite(Fasa2_In1, 0);
      digitalWrite(Fasa2_In2, 1);
      break;
    case 15:
      analogWrite(Fasa1_PWM, 255);
      analogWrite(Fasa2_PWM, PWMstepAntara);
      digitalWrite(Fasa1_In1, 1);
      digitalWrite(Fasa1_In2, 0);
      digitalWrite(Fasa2_In1, 0);
      digitalWrite(Fasa2_In2, 1);
      break;
  }

}

void MicroStepping_R16_CW() {
  if (++Step > 15) Step = 0; // naikkan hitungan step
  Rectangular_16Step();
}

void MicroStepping_R16_CCW() {
  if (--Step < 0) Step = 15; // turunkan hitungan step
  Rectangular_16Step();
}

void loop() {
  MicroStepping_R16_CW();
  delay(500);
}

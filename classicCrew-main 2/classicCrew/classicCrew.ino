#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <MPU6050.h>
#include <I2Cdev.h>

#define nbPCAServo 1
Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver(0x40);
MPU6050 mpu;

const float ACC_THRESHOLD = 2.5;
//const float GYRO_THRESHOLD = 200; // 200°/s 이상

const int ir[5] = { 9, 10, 11, 12, 13 };
int val[5];


int16_t ax, ay, az;
int16_t gx, gy, gz;



void setup() {
  Serial.begin(115200);

  Wire.begin();

  Serial.println("Initializing MPU6050...");
  mpu.initialize();

  if (mpu.testConnection()) {
    Serial.println("MPU6050 connection successful!");
  } else {
    Serial.println("MPU6050 connection failed!");
  }

  for (int i = 0; i < 5; i++) {
    pinMode(ir[i], INPUT);
  }

  pca.begin();
  pca.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

bool isPeopleDetected = false;
bool isCarDetected = false;
unsigned long barrierDownTime = 0;
const unsigned long BARRIER_DELAY = 1000;
bool isBarrierMoving = false;

int guard = 0;

void loop() {

  // check Sensors' Activation
  for (int i = 0; i < 5; i++) {
    val[i] = digitalRead(ir[i]);
  }

  check_mpu();

  if (guard == 1) {
    guardDown(1);
    delay(50);
  } else if (guard == 2) {
    guardDown(2);
    delay(50);
  } else {
  }

  // detect Cars
  // 사람이 대기하고, 차가 멈춰서면 올림
  if ((val[3] == LOW || val[4] == LOW) && val[2] == LOW) {
    Serial.println("Waiting\n");
    guard = 2;
  } else if ((val[0] == LOW || val[1] == LOW || val[2] == LOW) && (val[3] == LOW || val[4] == LOW)) {  // 차를 먼저 확인하고 사람이 있으면 내림
    Serial.println("Car is detected");
    guard = 1;

  } else {  // 사람이 없거나 셋 다 차가 없으면 올림
    Serial.println("No car");
    guard = 2;
  }
}

// Guard Control
void guardDown(int act) {

  switch (act) {
    case 1:
      pca.writeMicroseconds(0, jointToImp(90));
      //          Serial.println("Up!");

      break;
    case 2:
      pca.writeMicroseconds(0, jointToImp(0));
      //          Serial.println("Down!");

      break;
    default:
      // 잘못된 caseNum 입력 처리
      Serial.println("Invalid case number!");
      break;
  }
}


// Servo Angle
int jointToImp(double angle) {
  const int minImpulse = 500;   // 서보 최소 펄스
  const int maxImpulse = 2500;  // 서보 최대 펄스
  const int minAngle = 0;       // 최소 각도
  const int maxAngle = 180;     // 최대 각도

  int imp = (angle - minAngle) * (maxImpulse - minImpulse) / (maxAngle - minAngle) + minImpulse;
  imp = max(imp, minImpulse);
  imp = min(imp, maxImpulse);
  return imp;
}


// 자이로센서
void check_mpu() {

  // 가속도계 및 자이로 데이터 읽기
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  int16_t start_ax = ax;
  int16_t start_ay = ay;
  int16_t start_az = az;

  float ax_g = ax / 16384.0;  // MPU6050은 ±2g 설정에서 1g = 16384
  float ay_g = ay / 16384.0;
  float az_g = az / 16384.0;

  if (abs(ax_g) > ACC_THRESHOLD || abs(ay_g) > ACC_THRESHOLD || abs(az_g) > ACC_THRESHOLD) {

    Serial.println("Collision Detected!\n");
  }
}

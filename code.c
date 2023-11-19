#include <Mouse.h>
#include <MPU6050.h>
MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy, vx_prec, vy_prec;
int count=0;
void setup()
{
Serial.begin(9600);
Mouse.begin();
}
void loop()
{
mpu.imu(&ax, &ay, &az, &gx, &gy, &gz);
Mouse.move(ax, ay);
if ( (pax-5)<=ax && ax<=pax+5 && (pay-5)<=ay && ay<=pay+5)
{
count++;
if(count == 100)
{
Mouse.press(MOUSE_LEFT);
count = 0;
delay(70);
Mouse.release(MOUSE_LEFT);
}
}
else {
pax = vx; // updating values to check the position of the pointer and allow the click
pay = vy;
count = 0;
}
delay(20);
}

int Filter_Value;
int Value;

void setup() {
  Serial.begin(9600);// 初始化串口通信
  randomSeed(analogRead(0)); // 产生随机种子
  Value = 300;
}

void loop() {
  Filter_Value = Filter();// 获得滤波器输出值
  Serial.println(Filter_Value); // 串口输出
  delay(50);
}

// 用于随机产生一个300左右的当前值
int Get_AD() {
  return random(295, 305);
}

// 消抖滤波法
#define FILTER_N 12
int i = 0;
int Filter() {
  int new_value;
  new_value = Get_AD();
  if (Value != new_value) {
    i++;
    if (i > FILTER_N) {
      i = 0;
      Value = new_value;
    }
  }
  else
    i = 0;
  return Value;
}

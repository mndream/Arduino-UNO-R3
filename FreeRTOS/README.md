# FreeRTOS 的使用

使用FreeRTOS和UNO R3盒子中的器件，构建一个小综合实验，至少包含三个实时任务。

### 构想

现在能用的器件有：蜂鸣器、LED灯、HC-SR04超声波传感器、温湿度传感器。

车库报警装置：

1. 防止车辆碰撞（优先级高）：超声波传感器固定到车库大门正对的墙壁上，当且仅当光线传感器接收到光线（开车时，汽车启动时有尾灯；不开车时，人经过时不警报。）而且超声波传感器测距小于一定值（比如0.5米）时，促使蜂鸣器发声，产生警报。

2. 防止温度过低结冰，或者温度过高产生火灾（优先级高）：温度传感器置放于车库内，当温度低于一定温度（比如零摄氏度）或者高于一定温度（比如50摄氏度）时，促使蜂鸣器发声，产生警报。

3. 工作指示灯（优先级低）：LED灯呈现呼吸状态，第一周期从暗到亮，第二周期从亮到暗，第三周期一直暗。工作指示灯不亮可能表示装置出现故障。

### 接法

- HC-SR04超声波传感器：

    Grid -> G

    Echo -> D5

    Trig -> D4

    Vcc  -> 5V

- 蜂鸣器：12
- 指示灯：9
- 光感器：A0
- 温度传感器：A5

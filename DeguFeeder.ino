
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
#include <Servo.h>
 
Servo feeder1;
Servo feeder2;
 
unsigned long time;
 
//Duration to wait until the first feeding
unsigned long feed_time = 1000uL*60uL*60uL*10uL; //10 hours
 
//Interval between subsequent feeding times
unsigned long feed_interval = 1000uL*60uL*60uL*12uL; //12 hours
 
unsigned int feeder_pause = 1500;
unsigned int feeder_shake = 150;
unsigned int feeder_speed_delay = 0;
unsigned int feed_num = 0;
 
int ii;
 
//Calibrate the rest position and maximum extents of the servo
unsigned int feeder1_zero = 93;
unsigned int feeder1_max = 170;
unsigned int feeder1_min = 10;
unsigned int feeder2_zero = 100;
unsigned int feeder2_max = 170;
unsigned int feeder2_min = 10;
 
void setup()
{
  feeder1.attach(10);
  feeder2.attach(11);
 
  feeder1.write(feeder1_zero);
  feeder2.write(feeder2_zero);
  delay(1000);
}
 
void loop()
{
  time = millis();
  if (time > feed_time){
    if (feed_num == 0){
      feeder1.write(feeder1_min);
      delay(feeder_pause);
      feeder1.write(feeder1_min+30);
      delay(feeder_shake);
      feeder1.write(feeder1_min);
      delay(feeder_shake);
      feeder1.write(feeder1_min+30);
      delay(feeder_shake);
      feeder1.write(feeder1_min);
      delay(feeder_pause);
      feeder1.write(feeder1_zero);
    }
    else if (feed_num == 1){
      feeder1.write(feeder1_max);
      delay(feeder_pause);
      feeder1.write(feeder1_max-30);
      delay(feeder_shake);
      feeder1.write(feeder1_max);
      delay(feeder_shake);
      feeder1.write(feeder1_max-30);
      delay(feeder_shake);
      feeder1.write(feeder1_max);
      delay(feeder_pause);
      feeder1.write(feeder1_zero);
    }
    else if (feed_num == 2){
      feeder2.write(feeder2_min);
      delay(feeder_pause);
      feeder2.write(feeder2_min+30);
      delay(feeder_shake);
      feeder2.write(feeder2_min);
      delay(feeder_shake);
      feeder2.write(feeder2_min+30);
      delay(feeder_shake);
      feeder2.write(feeder2_min);
      delay(feeder_pause);
      feeder2.write(feeder2_zero);
    }
    else if (feed_num == 3){
      feeder2.write(feeder2_max);
      delay(feeder_pause);
      feeder2.write(feeder2_max-30);
      delay(feeder_shake);
      feeder2.write(feeder2_max);
      delay(feeder_shake);
      feeder2.write(feeder2_max-30);
      delay(feeder_shake);
      feeder2.write(feeder2_max);
      delay(feeder_pause);
      feeder2.write(feeder2_zero);
    }
    feed_num++;
    feed_time += feed_interval;
  }
}

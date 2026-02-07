
```md
# Dead Reckoning – Manual Tests

این تست‌ها برای برنامه‌ی C++ محاسبه‌ی یک قدم dead-reckoning نوشته شده‌اند.

فرض‌ها:
- yaw بر حسب درجه است
- yaw خروجی در بازه‌ی [-180 , 180] نرمال می‌شود
- dt باید مثبت باشد
- فرمول حرکت:
  x2 = x + v*dt*cos(yaw)
  y2 = y + v*dt*sin(yaw)
  yaw2 = yaw + w*dt
---
```

## Test 1: حرکت ساده رو به جلو + چرخش مثبت
**Input**
x = 0  
y = 0  
yaw_deg = 30

v = 2  
w_deg = 10  
dt = 5

```text
Result after one dead-reckoning step:
x2 = 8.66025
y2 = 5
yaw2_deg = 80
```

**Expected Output**
x2 ≈ 8.66025  
y2 = 5  
yaw2_deg = 80

```
توضیح:
- yaw2 = 30 + 10×5 = 80 (در بازه مجاز)
- cos(30°)=0.866 ، sin(30°)=0.5
---
## 

```

## Test 2: بدون حرکت خطی، فقط چرخش (نرمال‌سازی yaw)
**Input**
x = 1  
y = 2  
yaw_deg = 170

v = 0  
w_deg = 30  
dt = 1

```
Result after one dead-reckoning step:
x2 = 1
y2 = 2
yaw2_deg = -160
```
**Expected Output**
x2 = 1  
y2 = 2  
yaw2_deg = -160

```
توضیح:
- yaw2_raw = 170 + 30 = 200
- نرمال‌سازی: 200 − 360 = -160
---
```

## Test 3: ورودی نامعتبر (dt منفی)
**Input**
x = 0  
y = 0  
yaw_deg = 0

v = 1  
w_deg = 0  
dt = -2

```
Error: dt must be positive.
### Expected Output
```

Error: dt must be positive.  
(program exits)

```
توضیح:
- چون dt ≤ 0 است، برنامه باید پیام خطا بدهد و terminate شود.
---
```

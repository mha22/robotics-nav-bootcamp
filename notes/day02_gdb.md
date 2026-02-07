## خلاصه‌ی دیباگ با gdb در C/C++

### 1) اگر از CMake استفاده میکنی کد پایین به **CMake** می‌گه پروژه رو در حالت **دیباگ (Debug)** پیکربندی کنه.
```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . -j
```

### 2) اجرای gdb

```bash
gdb ./test_pose2d
```

یا با آرگومان‌ها:

```bash
gdb --args ./app arg1 arg2
```

---

### 3) اجرای برنامه

```gdb
run
```

---

### 4) گذاشتن breakpoint

توقف روی تابع به نام foo:

```gdb
break foo
```

توقف در خط خاص:

```gdb
break 8
```

توقف روی فایل و خط:

```gdb
break main.cpp:25
```



---

### 5)برای اینکه بفهمیم الان کدوم خط از کد هستیم و دیدن مسیر فراخوانی توابع (دیدن call stack)

```gdb
where
```

یا:

```gdb
bt
```

-----
### 6) حرکت مرحله‌به‌مرحله

اجرای خط بعدی (بدون ورود به تابع):

```gdb
next
```

اجرای خط بعدی (با ورود به داخل تابع):

```gdb
step
```

ادامه‌ی اجرا تا breakpoint بعدی:

```gdb
continue
```

خروج از تابع فعلی و مشاهده مقدار بازگشتی تابع (پرکاربرد):

```gdb
finish
```

---

### 7) دیدن مقدار متغیرها

```gdb
print x
print result
```


---

### 8) خروج از gdb

```gdb
quit
```

---

### نکته‌ی مهم

اگر برنامه کرش کرد:

```gdb
run
where or bt
```

این سریع‌ترین راه پیدا کردن محل خطاست.

---

مثلا در کد اصلی تابع normalize_angle_rad عمدا خطای assert قرار دادم. بعد اومدم با gdb یک braekpoint روی normalize_angle_rad گذاشتم.
```bash
gdb ./test_pose2d
break normalize_angle_rad
run
```


هر مرحله میتونیم نگاه کنیم الان دقیقا کجا هستیم
```bash
bt
#0  normalize_angle_rad (yaw_raw=3.2415926535897932)
    at /home/mha/github/robotics-nav-bootcamp/cpp/nav_core/src/pose2d.cpp:26
#1  0x0000555555555271 in main ()
    at /home/mha/github/robotics-nav-bootcamp/cpp/nav_core/tests/test_pose2d.cpp:11
```

بهمون میگه به ترتیب خط ۲۶ فایل pose2d.cpp قرار داریم و این فایل در خط ۱۱ فایل test_pose2d.cpp کال شده بوده. 

حالا با زدن finish میتونیم مقدار بازگشتی رو ببینیم و متوجه بشیم کجا اشتباه کرده بودیم.
```bash
finish
Run till exit from #0  normalize_angle_rad (yaw_raw=-3.041592653589793)
    at /home/mha/github/robotics-nav-bootcamp/cpp/nav_core/src/pose2d.cpp:26
0x0000555555555271 in main ()
    at /home/mha/github/robotics-nav-bootcamp/cpp/nav_core/tests/test_pose2d.cpp:11
11          assert(normalize_angle_rad(M_PI + 0.1) == - M_PI + 0.2);
Value returned is $1 = -3.041592653589793
```
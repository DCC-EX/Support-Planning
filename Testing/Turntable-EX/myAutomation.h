// myAutomation.h file for regression testing of Turntable-EX.

// Initial DONE to ensure turntable stays at "home" on startup.
DONE

#define TURNTABLE_EX(route_id, reserve_id, vpin, steps, activity, desc) \
  ROUTE(route_id, desc) \
    RESERVE(reserve_id) \
    MOVETT(vpin, 0, LED_Slow) \
    DELAY(3000) \
    MOVETT(vpin, 0, Acc_On) \
    MOVETT(vpin, steps, activity) \
    WAITFOR(vpin) \
    MOVETT(vpin, 0, Acc_Off) \
    DELAY(3000) \
    MOVETT(vpin, 0, LED_Off) \
    FREE(reserve_id) \
    DONE
  
  TURNTABLE_EX(TTRoute1, Turntable, 600, 56, Turn, "Position 1")
  TURNTABLE_EX(TTRoute2, Turntable, 600, 111, Turn, "Position 2")
  TURNTABLE_EX(TTRoute3, Turntable, 600, 167, Turn, "Position 3")
  TURNTABLE_EX(TTRoute4, Turntable, 600, 1056, Turn_PInvert, "Position 4")
  TURNTABLE_EX(TTRoute5, Turntable, 600, 1111, Turn_PInvert, "Position 5")
  TURNTABLE_EX(TTRoute6, Turntable, 600, 1167, Turn_PInvert, "Position 6")
  TURNTABLE_EX(TTRoute7, Turntable, 600, 0, Home, "Home turntable")
  TURNTABLE_EX(TTRoute8, Turntable, 600, 0, Calibrate, "Calibrate turntable")

ALIAS(Turntable, 255)
ALIAS(TTRoute1, 5179)
ALIAS(TTRoute2, 5180)
ALIAS(TTRoute3, 5181)
ALIAS(TTRoute4, 5182)
ALIAS(TTRoute5, 5183)
ALIAS(TTRoute6, 5184)
ALIAS(TTRoute7, 5185)
ALIAS(TTRoute8, 5186)

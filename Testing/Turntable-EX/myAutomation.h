// myAutomation.h file for regression testing of Turntable-EX.

// Initial DONE to ensure turntable stays at "home" on startup.
DONE

#define TURNTABLE_EX(route_id, reserve_id, vpin, steps, activity, desc) \
  ROUTE(route_id, desc) \
    RESERVE(reserve_id) \
    MOVETT(vpin, steps, activity) \
    FREE(reserve_id) \
    DONE
  
  TURNTABLE_EX(TTRoute1, Turntable, 600, 56, Turn, "TTEX-RT1 - Position 1")
  TURNTABLE_EX(TTRoute2, Turntable, 600, 111, Turn, "TTEX-RT2 - Position 2")
  TURNTABLE_EX(TTRoute3, Turntable, 600, 167, Turn, "TTEX-RT3 - Position 3")
  TURNTABLE_EX(TTRoute4, Turntable, 600, 1056, Turn_PInvert, "TTEX-RT4 - Position 4")
  TURNTABLE_EX(TTRoute5, Turntable, 600, 1111, Turn_PInvert, "TTEX-RT5 - Position 5")
  TURNTABLE_EX(TTRoute6, Turntable, 600, 1167, Turn_PInvert, "TTEX-RT6 - Position 6")
  TURNTABLE_EX(TTRoute7, Turntable, 600, 1167, Turn_PInvert, "TTEX-RT7 - Position 4")
  TURNTABLE_EX(TTRoute8, Turntable, 600, 1167, Turn_PInvert, "TTEX-RT8 - Position 2")
  TURNTABLE_EX(TTRoute9, Turntable, 600, 0, Home, "TTEX-RT9 - Home turntable")
  TURNTABLE_EX(TTRoute10, Turntable, 600, 0, Calibrate, "TTEX-RT10 - Calibrate turntable")

ALIAS(Turntable, 255)
ALIAS(TTRoute1)
ALIAS(TTRoute2)
ALIAS(TTRoute3)
ALIAS(TTRoute4)
ALIAS(TTRoute5)
ALIAS(TTRoute6)
ALIAS(TTRoute7)
ALIAS(TTRoute8)
ALIAS(TTRoute9)
ALIAS(TTRoute10)

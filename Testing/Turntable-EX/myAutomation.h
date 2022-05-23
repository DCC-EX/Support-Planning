// myAutomation.h file for regression testing of Turntable-EX.

// Initial DONE to ensure turntable stays at "home" on startup.
DONE

#define TURNTABLE_EX(route_id, reserve_id, vpin, steps, activity, desc) \
  ROUTE(route_id, desc) \
    RESERVE(reserve_id) \
    MOVETT(vpin, steps, activity) \
    FREE(reserve_id) \
    DONE
  
TURNTABLE_EX(TTRoute1, Turntable, 600, 114, Turn, "TTEX-RT1 - Position 1")
TURNTABLE_EX(TTRoute2, Turntable, 600, 227, Turn, "TTEX-RT2 - Position 2")
TURNTABLE_EX(TTRoute3, Turntable, 600, 341, Turn, "TTEX-RT3 - Position 3")
TURNTABLE_EX(TTRoute4, Turntable, 600, 2159, Turn, "TTEX-RT4 - Position 4")
TURNTABLE_EX(TTRoute5, Turntable, 600, 2273, Turn, "TTEX-RT5 - Position 5")
TURNTABLE_EX(TTRoute6, Turntable, 600, 2386, Turn, "TTEX-RT6 - Position 6")
TURNTABLE_EX(TTRoute7, Turntable, 600, 2159, Turn, "TTEX-RT7 - Position 4")
TURNTABLE_EX(TTRoute8, Turntable, 600, 227, Turn, "TTEX-RT8 - Position 2")
TURNTABLE_EX(TTRoute9, Turntable, 600, 0, Home, "TTEX-RT9 - Home turntable")
TURNTABLE_EX(TTRoute10, Turntable, 600, 0, Calibrate, "TTEX-RT10 - Calibrate turntable")
TURNTABLE_EX(TTRoute11, Turntable, 600, 0, LED_On, "TTEX-RT11 - LED On")
TURNTABLE_EX(TTRoute12, Turntable, 600, 0, LED_Slow, "TTEX-RT12 - LED Slow Blink")
TURNTABLE_EX(TTRoute13, Turntable, 600, 0, LED_Fast, "TTEX-RT13 - LED Fast Blink")
TURNTABLE_EX(TTRoute14, Turntable, 600, 0, LED_Off, "TTEX-RT14 - LED Off")
TURNTABLE_EX(TTRoute15, Turntable, 600, 0, Acc_On, "TTEX-RT15 - Accessory On")
TURNTABLE_EX(TTRoute16, Turntable, 600, 0, Acc_Off, "TTEX-RT16 - Accessory Off")
TURNTABLE_EX(TTRoute17, Turntable, 600, 2159, Turn, "TTEX-RT17 - Position 4")
TURNTABLE_EX(TTRoute18, Turntable, 600, 341, Turn_PInvert, "TTEX-RT18 - Position 2")

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
ALIAS(TTRoute11)
ALIAS(TTRoute12)
ALIAS(TTRoute13)
ALIAS(TTRoute14)
ALIAS(TTRoute15)
ALIAS(TTRoute16)
ALIAS(TTRoute17)
ALIAS(TTRoute18)

from serialCOM import *
from data import *
from const import *
import time

serialData = SerialConnection()

data = CellTesterRecvPkt()

mode = CHARGE_MODE

while True:
    serialData.read_data(data)
    if data.mode == CHARGE_MODE:
        mode = CHARGE_MODE
        #STOP DISCHARGE
        #START CHARGE
    elif data.mode == DISCHARGE_MODE:
        mode = DISCHARGE_MODE
        #STOP CHARGE
        #START DISCHARGE

    time.sleep()



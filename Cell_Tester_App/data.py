from dataclasses import *
from dataclasses import dataclass

def dataClassSize(c: type) -> int:
    size = 0
    for f in fields(c):
        if f.type is int or f.type is float:
            size += 4
        elif f.type is bool:
            size += 1
        else:
            print(f.type, "is not supported")
        
def getFields(c: type) -> str:
    s = ""
    for f in fields(c):
        if f.type is int:
            s += "I"
        elif f.type is float:
            s += "f"
        elif f.type is bool:
            s += "?"
        else:
            print(f.type, "is not supported")

@dataclasses
class CellTesterRecvPkt():
    voltage: int = 0
    current: int = 0
    temp1: int = 0
    temp2: int = 0
    temp3: int = 0
    mode: int = 0
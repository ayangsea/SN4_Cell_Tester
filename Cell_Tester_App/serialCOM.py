from data import *
import serial, serial.tools.list_ports
import sys
import struct

class SerialConnection:
    BAUD_RATE = 115200
    BYTE_SIZE = serial.EIGHTBITS
    PARITY = serial.PARITY_NONE
    STOP_BITS = serial.STOPBITS_ONE

    def __init__(self):
        port = self.__get_port()
        self.__connection = self.__connect(port)

    def __get_port(self) -> str:
        while True:
            ports = serial.tools.list_ports.comports()
            if len(ports) == 0:
                print("Error: no active ports")
            else:
                ports_str = [p[0] for p in ports]
                print(f"\nPorts: {ports_str}")
                try:
                    port_index = int(input(f"Choose port [1, {len(ports)}]: ")) - 1
                    if 0 <= port_index < len(ports):
                        break
                    else:
                        print("Error: invalid port index")
                except KeyboardInterrupt:
                    sys.exit(1)
                except:
                    print("Error: invalid port index")
        return ports[port_index][0]

    def __connect(self, port: str) -> serial.Serial:
        try:
            serial_connection = serial.Serial(port, SerialConnection.BAUD_RATE, SerialConnection.BYTE_SIZE,
                                              SerialConnection.PARITY, SerialConnection.STOP_BITS)
            return serial_connection
        except:
            print("Error: invalid serial connection")
            sys.exit(1)
    
    def ReceiveDataPacket(self, data: type) -> type:
        inNumBytes = dataClassSize(data)
        bytesWaiting, rawData = self.read_data(inNumBytes)

        if bytesWaiting >= inNumBytes:
            unpackStr = getFields(data)
            unPackedData = list(struct.unpack(unpackStr, rawData))
            fieldCount = 0
            for f in fields(data):
                setattr(f.type, f.name, unPackedData[fieldCount])
                fieldCount += 1

    def read_data(self, size):
        data = None
        if size < 1:
            print("invalid Argument size")
            return
        dataCount = self.__connection.in_waiting
        if dataCount >= size:
            data = self.__connection.read(size)
            print("Read:" + str(data))
        return (dataCount, data)
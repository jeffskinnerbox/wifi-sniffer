# Made by @xdavidhu (github.com/xdavidhu, https://xdavidhu.me/)

import serial
import io
import os
import subprocess
import signal
import time


serialport = "/dev/ttyUSB0"
boardRate = 115200
#ser = serial.Serial(serialport, boardRate)
#line=ser.readline()
#print line
filename = "capture.pcap"

canBreak = False
while not canBreak:
    try:
        ser = serial.Serial(serialport, boardRate)
        canBreak = True
    except KeyboardInterrupt:
        print("\n[+] Exiting...")
        exit()
    except:
        print("[!] Serial connection failed... Retrying...")
        time.sleep(2)
        continue

print("[+] Serial connected. Name: " + ser.name)
counter = 0
f = open(filename,'wb')

check = 0
while check == 0:
    line = ser.readline()
    if b"<<START>>" in line:
        check = 1
        print("[+] Stream started...")
    else:
        print(line.strip())

print("[+] Starting up wireshark...")
cmd = "tail -f -c +0 " + filename + " | wireshark -k -i -"
p = subprocess.Popen(cmd, stdout=subprocess.PIPE,
                       shell=True, preexec_fn=os.setsid)

try:
    while True:
        ch = ser.read()
        f.write(ch)
        f.flush()
except KeyboardInterrupt:
    print("[+] Stopping...")
    os.killpg(os.getpgid(p.pid), signal.SIGTERM)

f.close()
ser.close()
print("[+] Done.")

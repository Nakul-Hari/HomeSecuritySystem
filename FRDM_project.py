import serial
import cv2
def take_picture(i):
    cap = cv2.VideoCapture(0)

    if not cap.isOpened():
        print("Could not open webcam")
        return

    ret, frame = cap.read()


    if ret:
        cv2.imwrite("picture" + str(i) + ".jpg", frame)
        print("Picture saved as picture" + str(i) + ".jpg")

   
    cap.release()
    cv2.destroyAllWindows()



serial_port = "COM10"
baud_rate = 57600
timeout = 1 

i=0
ser = serial.Serial(serial_port, baud_rate, timeout=timeout)
while True:
    
    bytesToRead = ser.inWaiting()
    received_data = ser.read(bytesToRead)
    if received_data:

        if (received_data.decode()=='Y'):
            take_picture(i)
            i+=1

ser.close()


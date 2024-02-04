import cv2 
from cvzone.FaceDetectionModule import FaceDetector 
from cvzone.SerialModule import SerialObject 
cap = cv2.VideoCapture(0) 
detector = FaceDetector() 
ardunio = SerialObject('COM3') 
 
while True: 
    success, img = cap.read() 
    img, bBoxes = detector.findFaces(img) 
 
    if bBoxes: 
        ardunio.sendData([1, 0]) 
    else: 
        ardunio.sendData([0, 1]) 
    cv2.imshow("Video", img) 
    cv2.waitKey(1)
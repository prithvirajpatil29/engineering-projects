from importlib import import_module
import os
from flask import Flask, render_template, Response
from picamera.array import PiRGBArray
from picamera import PiCamera
import time
import cv2
import numpy as np
import math
import argparse
from imutils.video import VideoStream
import imutils

CLASSES = ["background", "aeroplane", "bicycle", "bird", "boat",
	"bottle", "bus", "car", "cat", "chair", "cow", "diningtable",
	"dog", "horse", "motorbike", "person", "pottedplant", "sheep",
	"sofa", "train", "tvmonitor"]

app = Flask(__name__)


@app.route('/')
def index():
    """Video streaming home page."""
    return render_template('index.html')


def gen(camera):
    theta=0
    minLineLength = 5
    maxLineGap = 10
    camera.resolution = (640, 480)
    camera.framerate = 30
    rawCapture = PiRGBArray(camera, size=(640, 480))
    time.sleep(0.1)
    
    detected_objects = []

    """Video streaming generator function."""
    for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
        image = frame.array
                
        frame = imutils.resize(image, width=800)
	
	for i in np.arange(0, detections.shape[2]):
		confidence = detections[0, 0, i, 2]
		if confidence > args["confidence"]:
			idx = int(detections[0, 0, i, 1])
			box = detections[0, 0, i, 3:7] * np.array([w, h, w, h])
			(startX, startY, endX, endY) = box.astype("int")

			label = "{}: {:.2f}%".format(CLASSES[idx],
				confidence * 100)
			detected_objects.append(label)
			cv2.rectangle(frame, (startX, startY), (endX, endY),
				COLORS[idx], 2)
			y = startY - 15 if startY - 15 > 15 else startY + 15
			cv2.putText(frame, label, (startX, y),
				cv2.FONT_HERSHEY_SIMPLEX, 0.5, COLORS[idx], 2)
			
        cv2.imwrite('hvs.jpg', frame)
        img = open('hvs.jpg', 'rb').read()
        yield (b'--frame\r\n'
                b'Content-Type: image/jpeg\r\n\r\n' + img + b'\r\n')
        rawCapture.truncate(0)
        

if __name__ == '__main__':
    
    app.run(host='0.0.0.0', threaded=True)

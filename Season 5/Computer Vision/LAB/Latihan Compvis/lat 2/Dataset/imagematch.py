import cv2
import numpy as np
import matplotlib.pyplot as plt

#import gambar
cadbury = cv2.imread('lat 2\Dataset\cadbury.jpeg')
scene = cv2.imread('lat 2\Dataset\chocolate_scene.jpeg')

#convert rgb to gray
cadbury_gray = cv2.cvtColor(cadbury, cv2.COLOR_BGR2GRAY)
scene_gray = cv2.cvtColor(scene, cv2.COLOR_BGR2GRAY)

#SIFT


import cv2
import numpy as np
import matplotlib.pyplot as plt
import os

image = cv2.imread('')

#blur
blur_image = cv2.blur(image, (15,15))
# median
median_image = cv2.medianBlur(image,15)
# gaussian
gaussian_image = cv2.GaussianBlur(image,(15,15),2.0)
# bilateral
bilateral_image = cv2.bilateralFilter(image, 1, 150, 150)


import cv2
import matplotlib.pyplot as plt
import numpy as np

def showResult(image, cmap=None):
    plt.imshow(image, cmap=cmap)
    plt.show()

image = cv2.imread('chessboard.jpg')
image_gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

image_gray = np.float32(image_gray)

# HARRIS
harris = cv2.cornerHarris(image_gray, 2 , 5, 0.04)

without_subpix = image.copy()
without_subpix[harris > 0.01 * harris.max()] = [0,255,0]
# showResult(without_subpix,'gray')

_, thresh = cv2.threshold(harris, 0.001*harris.max(), 255, 0) # 0 -> cv2.THRESHOLD_BINARY
thresh = np.uint8(thresh)

im, lb, st, centroids = cv2.connectedComponentsWithStats(thresh)
centroids = np.float32(centroids)
criteria = (cv2.TERM_CRITERIA_MAX_ITER + cv2.TERM_CRITERIA_EPS, 100, 0.01)
enhanced_criteria = cv2.cornerSubPix(image_gray,centroids, (2,2), (-1,-1), criteria)
enhanced_criteria = np.uint16(enhanced_criteria)

with_subpix = image.copy()
for i in enhanced_criteria:
    x,y = i[:2]
    with_subpix[y,x] = [0,255,0]

# showResult(with_subpix, 'gray')


# FAST
image = cv2.imread('chessboard.jpg', cv2.IMREAD_GRAYSCALE)

fast = cv2.FastFeatureDetector_create()
kp = fast.detect(image, None)
image_2 = cv2.drawKeypoints(image, kp, None, color=[0,255,0])
# cv2.imwrite('fast.png',image_2)
# showResult(image_2)

# ORB

orb = cv2.ORB_create()
kp = orb.detect(image, None)
kp, des = orb.compute(image,kp)
image_3 = cv2.drawKeypoints(image, kp, None, color=[0,255,0])
showResult(image_3)

